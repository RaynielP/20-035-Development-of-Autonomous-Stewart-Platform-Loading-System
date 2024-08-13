#include <Arduino.h> // Include Arduino Library for Serial and other functions

// Define pins for each actuator
const int extendPins[] = {38, 44, 22, 34, 30, 26};
const int retractPins[] = {40, 42, 24, 36, 32, 28};
const int enaPins[] = {2, 4, 6};
const int enbPins[] = {3, 5, 7};
const int numActuators = 6;

// Define array to hold speeds for each actuator
int speeds[numActuators] = {255, 255, 255, 255, 255, 255}; // Default to full speed
float Kp = 9.5; // 1.0 , 1.5 , 2.2 // 10, 5.5, 20.2 // 9.5, 6.5, 9.9
float Ki = 6.5;
float Kd = 9.9;
float targetX = 300; // 300
float targetY = 150; // 150

float errorX, errorY;
float integralX = 0, integralY = 0;
float derivativeX, derivativeY;
float previousErrorX = 0, previousErrorY = 0;

unsigned long previousTime = 0;
unsigned long lastTouchTime = 0;
const unsigned long timeoutDuration = 1000; // Timeout duration in milliseconds (1 seconds)

bool startPID = false;

void setup() {
  Serial.begin(9600);
  previousTime = millis();

  // Initialize pins
  for (int i = 0; i < numActuators; i++) {
    pinMode(extendPins[i], OUTPUT);
    pinMode(retractPins[i], OUTPUT);
  }
  for (int i = 0; i < numActuators / 2; i++) {
    pinMode(enaPins[i], OUTPUT);
    pinMode(enbPins[i], OUTPUT);
  }

  // Retract all actuators until touch values are in the desired range
  while (true) {
    int currentX = readTouchX();
    int currentY = readTouchY();

    if (currentX > 10 && currentY > 10) {
      // Stop retracting if values are within range
      break;
    }

    for (int i = 0; i < numActuators; i++) {
      digitalWrite(extendPins[i], LOW);
      digitalWrite(retractPins[i], HIGH);
    }

    for (int i = 0; i < numActuators / 2; i++) {
      analogWrite(enaPins[i], 255);
      analogWrite(enbPins[i], 255);
    }

    delay(100); // Adjust as necessary
  }

  // Stop actuators
  for (int i = 0; i < numActuators / 2; i++) {
    analogWrite(enaPins[i], 0);
    analogWrite(enbPins[i], 0);
  }

  // Extend all actuators for 1 second
  extendAllActuators();
}

int readTouchX() {
  // Set Y+ to HIGH
  pinMode(A3, OUTPUT);
  digitalWrite(A3, HIGH);

  // Set Y- to LOW
  pinMode(A2, OUTPUT);
  digitalWrite(A2, LOW);

  // Set X+ and X- to input
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);

  // Read the X value from A0
  int xValue = analogRead(A0);

  return xValue;
}

int readTouchY() {
  // Set X+ to HIGH
  pinMode(A0, OUTPUT);
  digitalWrite(A0, HIGH);

  // Set X- to LOW
  pinMode(A1, OUTPUT);
  digitalWrite(A1, LOW);

  // Set Y+ and Y- to input
  pinMode(A3, INPUT);
  pinMode(A2, INPUT);

  // Read the Y value from A3
  int yValue = analogRead(A3);

  return yValue;
}

void extendAllActuators() {
  for (int i = 0; i < numActuators; i++) {
    digitalWrite(extendPins[i], HIGH);
    digitalWrite(retractPins[i], LOW);
  }

  for (int i = 0; i < numActuators / 2; i++) {
    analogWrite(enaPins[i], 255);
    analogWrite(enbPins[i], 255);
  }

  delay(3000); // Extend for 2 second

  // Stop actuators
  for (int i = 0; i < numActuators / 2; i++) {
    analogWrite(enaPins[i], 0);
    analogWrite(enbPins[i], 0);
  }
}

void stopAllActuators() {
  for (int i = 0; i < numActuators; i++) {
    digitalWrite(extendPins[i], LOW);
    digitalWrite(retractPins[i], LOW);
  }

  for (int i = 0; i < numActuators / 2; i++) {
    analogWrite(enaPins[i], 0);
    analogWrite(enbPins[i], 0);
  }
}

void setActuatorSpeed(int actuator, float speed) {
  if (speed > 0) {
    digitalWrite(extendPins[actuator], HIGH);
    digitalWrite(retractPins[actuator], LOW);
  } else {
    digitalWrite(extendPins[actuator], LOW);
    digitalWrite(retractPins[actuator], HIGH);
    speed = -speed;  // Make speed positive for PWM
  }
  if (actuator < 3) {
    analogWrite(enaPins[actuator], speed);
  } else {
    analogWrite(enbPins[actuator - 3], speed);
  }
}

void computePID() {
  unsigned long currentTime = millis();
  float timeStep = (currentTime - previousTime) / 1000.0;  // Convert to seconds

  // Read current position
  int currentX = readTouchX();
  int currentY = readTouchY();

  // Check initial conditions
  if (!startPID) {
    if (currentX > 10 && currentY > 10) {
      startPID = true;
      previousTime = currentTime;  // Initialize previousTime to avoid large initial timestep
      Serial.println("Starting PID control.");
    } else {
      Serial.print("Waiting for initial condition. CurrentX: ");
      Serial.print(currentX);
      Serial.print(" CurrentY: ");
      Serial.println(currentY);
      delay(100);
      return;  // Skip the rest of the loop if conditions are not met
    }
  }

  // If initial conditions are lost, reset PID
  if (currentX <= 10 || currentY <= 10) {
    startPID = false;
    integralX = 0;
    integralY = 0;
    previousErrorX = 0;
    previousErrorY = 0;
    Serial.println("Resetting PID control due to out of range values.");
    return;
  }

  // Calculate errors
  errorX = targetX - currentX;
  errorY = targetY - currentY;

  // Calculate integrals
  integralX += errorX * timeStep;
  integralY += errorY * timeStep;

  // Calculate derivatives
  derivativeX = (errorX - previousErrorX) / timeStep;
  derivativeY = (errorY - previousErrorY) / timeStep;

  // Compute PID outputs
  float outputX = Kp * errorX + Ki * integralX + Kd * derivativeX;
  float outputY = Kp * errorY + Ki * integralY + Kd * derivativeY;

  // Update previous errors
  previousErrorX = errorX;
  previousErrorY = errorY;

  // Update previous time
  previousTime = currentTime;

  // Print PID results for debugging and plotting
  Serial.print("errorX: ");
  Serial.print(errorX);
  Serial.print("\terrorY: ");
  Serial.print(errorY);
  Serial.print("\tintegralX: ");
  Serial.print(integralX);
  Serial.print("\tintegralY: ");
  Serial.print(integralY);
  Serial.print("\tderivativeX: ");
  Serial.print(derivativeX);
  Serial.print("\tderivativeY: ");
  Serial.print(derivativeY);
  Serial.print("\toutputX: ");
  Serial.print(outputX);
  Serial.print("\toutputY: ");
  Serial.println(outputY);

  // Control actuators based on PID outputs
  speeds[0] = constrain(abs(outputY), 0, 255);
  speeds[1] = constrain(abs(outputX), 0, 255);
  speeds[2] = constrain(abs(outputY), 0, 255);
  speeds[3] = constrain(abs(outputX), 0, 255);
  speeds[4] = constrain(abs(outputY), 0, 255);
  speeds[5] = constrain(abs(outputY), 0, 255);

  setActuatorSpeed(0, outputY);  // Actuator 1 depends on (x, y)
  setActuatorSpeed(1, outputX);  // Actuator 2 depends on (x, y)
  setActuatorSpeed(2, outputX); // Actuator 3 depends on (x, y) -outputY
  setActuatorSpeed(3, -outputX); // Actuator 4 depends on (x, -y) outputX
  setActuatorSpeed(4, -outputX); // Actuator 5 depends on (-x, y)
  setActuatorSpeed(5, outputY);  // Actuator 6 depends on (-x, y)
}

void loop() {
  computePID();
  
  // Timeout feature
  unsigned long currentTime = millis();
  int currentX = readTouchX();
  int currentY = readTouchY();

  if (currentX > 10 && currentY > 10) {
    lastTouchTime = currentTime; // Reset last touch time
  }

  if (currentTime - lastTouchTime > timeoutDuration) {
    Serial.println("Timeout: No touch detected, stopping actuators.");
    stopAllActuators();
    startPID = false; // Reset PID control
  }

  delay(100);  // Adjust delay as needed for control speed
}

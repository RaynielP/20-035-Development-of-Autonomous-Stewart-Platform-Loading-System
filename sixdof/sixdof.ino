// All actuator time stop is adjusted since the actuators used has unforeseen delay/defects. Some does not follow the coded speed.
// Initialize motor object
const int extend1 = 38; //orig 38
const int retract1 = 40; //orig 40
const int ena_1 = 2;

const int extend2 = 44; //orig 42
const int retract2 = 42; //orig 44
const int enb_1 = 3;

const int extend3 = 22;
const int retract3 = 24;
const int ena_2 = 4;

const int extend4 = 34;
const int retract4 = 36;
const int enb_2 = 5;

const int extend5 = 30;
const int retract5 = 32;
const int ena_3 = 6;

const int extend6 = 26;
const int retract6 = 28;
const int enb_3 = 7;

unsigned long startTime1, startTime2, startTime3, startTime4, startTime5, startTime6; // Variables to store the start time for each actuator
bool positivesurgeExecuted = false; // Flag variable to track whether positivesurge() has been executed
bool negativesurgeExecuted = false; // Flag variable to track whether negativesurge() has been executed
bool positiveswayExecuted = false; // Flag variable to track whether positivesway() has been executed
bool negativeswayExecuted = false; // Flag variable to track whether negativesway() has been executed
bool positiveheaveExecuted = false; // Flag variable to track whether positiveheave() has been executed
bool negativeheaveExecuted = false; // Flag variable to track whether negativeheave() has been executed
bool positiverollExecuted = false; // Flag variable to track whether positiveroll() has been executed
bool negativerollExecuted = false; // Flag variable to track whether negativeroll() has been executed
bool positivepitchExecuted = false; // Flag variable to track whether positivepitch() has been executed
bool negativepitchExecuted = false; // Flag variable to track whether negativepitch() has been executed
bool positiveyawExecuted = false; // Flag variable to track whether positiveyaw() has been executed
bool negativeyawExecuted = false; // Flag variable to track whether negativeyaw() has been executed

void setup() {

  pinMode(extend1, OUTPUT);
  pinMode(retract1, OUTPUT);
  pinMode(ena_1, OUTPUT);

  pinMode(extend2, OUTPUT);
  pinMode(retract2, OUTPUT);
  pinMode(enb_1, OUTPUT);

  pinMode(extend3, OUTPUT);
  pinMode(retract3, OUTPUT);
  pinMode(ena_2, OUTPUT);

  pinMode(extend4, OUTPUT);
  pinMode(retract4, OUTPUT);
  pinMode(enb_2, OUTPUT);

  pinMode(extend5, OUTPUT);
  pinMode(retract5, OUTPUT);
  pinMode(ena_3, OUTPUT);

  pinMode(extend6, OUTPUT);
  pinMode(retract6, OUTPUT);
  pinMode(enb_3, OUTPUT);

}



void returnActuator(int index) {
  switch (index) {
    case 1:
      retractActuator1();
      break;
    case 2:
      retractActuator2();
      break;
    case 3:
      retractActuator3();
      break;
    case 4:
      retractActuator4();
      break;
    case 5:
      retractActuator5();
      break;
    case 6:
      retractActuator6();
      break;
  }
}

void stopActuator(int index) {
  switch (index) {
    case 1:
      stopactuator1();
      break;
    case 2:
      stopactuator2();
      break;
    case 3:
      stopactuator3();
      break;
    case 4:
      stopactuator4();
      break;
    case 5:
      stopactuator5();
      break;
    case 6:
      stopactuator6();
      break;
  }
}








void stopactuator1() {
  digitalWrite(extend1, LOW); 
  digitalWrite(retract1, LOW); 
}

void stopactuator2() {
  digitalWrite(extend2, LOW);
  digitalWrite(retract2, LOW);
}

void stopactuator3() {
  digitalWrite(extend3, LOW);
  digitalWrite(retract3, LOW);
}

void stopactuator4() {
  digitalWrite(extend4, LOW);
  digitalWrite(retract4, LOW);
}

void stopactuator5() {
  digitalWrite(extend5, LOW);
  digitalWrite(retract5, LOW);
}

void stopactuator6() {
  digitalWrite(extend6, LOW);
  digitalWrite(retract6, LOW);
}









void extendActuator1() {
  digitalWrite(extend1, HIGH);
  digitalWrite(retract1, LOW);
  analogWrite(ena_1, 255);
}

void retractActuator1() {
  digitalWrite(extend1, LOW);
  digitalWrite(retract1, HIGH);
  analogWrite(ena_1, 255);
}

void extendActuator2() {
  digitalWrite(extend2, HIGH);
  digitalWrite(retract2, LOW);
  analogWrite(enb_1, 135);
}

void retractActuator2() {
  digitalWrite(extend2, LOW);
  digitalWrite(retract2, HIGH);
  analogWrite(enb_1, 187);
}

void extendActuator3() {
  digitalWrite(extend3, HIGH);
  digitalWrite(retract3, LOW);
  analogWrite(ena_2, 252);
}

void retractActuator3() {
  digitalWrite(extend3, LOW);
  digitalWrite(retract3, HIGH);
  analogWrite(ena_2, 252);
}

void extendActuator4() {
  digitalWrite(extend4, HIGH);
  digitalWrite(retract4, LOW);
  analogWrite(enb_2, 80);
}

void retractActuator4() {
  digitalWrite(extend4, LOW);
  digitalWrite(retract4, HIGH);
  analogWrite(enb_2, 87);
}

void extendActuator5() {
  digitalWrite(extend5, HIGH);
  digitalWrite(retract5, LOW);
  analogWrite(ena_3, 162);
}

void retractActuator5() {
  digitalWrite(extend5, LOW);
  digitalWrite(retract5, HIGH);
  analogWrite(ena_3, 193);
}

void extendActuator6() {
  digitalWrite(extend6, HIGH);
  digitalWrite(retract6, LOW);
   analogWrite(enb_3, 143);
}

void retractActuator6() {
  digitalWrite(extend6, LOW);
  digitalWrite(retract6, HIGH);
  analogWrite(enb_3, 180);
}






void positivesurge () {
  startTime1 = millis(); // Record the start time for actuator 1
  startTime2 = millis(); // Record the start time for actuator 2
  startTime3 = millis(); // Record the start time for actuator 3
  startTime4 = millis(); // Record the start time for actuator 4
  startTime5 = millis(); // Record the start time for actuator 5
  startTime6 = millis(); // Record the start time for actuator 6
  
  while (true) { 
    unsigned long currentTime = millis(); // Get the current time
    
    // Extend all actuators
    extendActuator1();
    extendActuator2();
    extendActuator3();
    extendActuator4();
    extendActuator5();
    extendActuator6();
    
    // Check if it's time to stop actuator 1
    if (currentTime - startTime1 >= 7500) { //SHOULD BE 10400 BUT ACTUATOR WON'T FOLLOW
      stopActuator(1); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 2
    if (currentTime - startTime2 >= 1000) { //SHOULD BE 5800 BUT ACTUATOR WON'T FOLLOW
      stopActuator(2); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 3
    if (currentTime - startTime3 >= 13700) {
      stopActuator(3); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 4
    if (currentTime - startTime4 >= 13700) {
      stopActuator(4); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    } 
    
    // Check if it's time to stop actuator 5
    if (currentTime - startTime5 >= 7800) { //SHOULD BE 5800 BUT ACTUATOR WON'T FOLLOW
      stopActuator(5); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 6
    if (currentTime - startTime6 >= 10400) {
      stopActuator(6); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Exit the loop if all actuators have stopped
    if (currentTime - startTime1 >= 8500 && 
        currentTime - startTime2 >= 2800 && 
        currentTime - startTime3 >= 13700 &&
        currentTime - startTime4 >= 13700 &&
        currentTime - startTime5 >= 6200 &&
        currentTime - startTime6 >= 10400) {
      break;
    }
  }
}

/* TO EXECUTE POSITIVE SURGE ONCE 
  if (!positivesurgeExecuted) {
    positivesurge(); // Execute positivesurge() only once
    positivesurgeExecuted = true; // Set the flag to true to indicate that positivesurge() has been executed
  }
*/

void negativesurge () {
  startTime1 = millis(); // Record the start time for actuator 1
  startTime2 = millis(); // Record the start time for actuator 2
  startTime3 = millis(); // Record the start time for actuator 3
  startTime4 = millis(); // Record the start time for actuator 4
  startTime5 = millis(); // Record the start time for actuator 5
  startTime6 = millis(); // Record the start time for actuator 6
  
  while (true) { 
    unsigned long currentTime = millis(); // Get the current time
    
    // Extend all actuators
    extendActuator1();
    extendActuator2();
    extendActuator3();
    extendActuator4();
    extendActuator5();
    extendActuator6();
    
    // Check if it's time to stop actuator 1
    if (currentTime - startTime1 >= 9700) {
      stopActuator(1); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 2
    if (currentTime - startTime2 >= 14000) {
      stopActuator(2); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 3
    if (currentTime - startTime3 >= 5500) { //should be 6300, but actuator won't follow
      stopActuator(3); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 4
    if (currentTime - startTime4 >= 6300) {
      stopActuator(4); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    } 
    
    // Check if it's time to stop actuator 5
    if (currentTime - startTime5 >= 14000) {
      stopActuator(5); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 6
    if (currentTime - startTime6 >= 10300) { //should be 9700, but actuator won't follow
      stopActuator(6); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Exit the loop if all actuators have stopped
    if (currentTime - startTime1 >= 9700 && 
        currentTime - startTime2 >= 14000 && 
        currentTime - startTime3 >= 6300 &&
        currentTime - startTime4 >= 6300 &&
        currentTime - startTime5 >= 14000 &&
        currentTime - startTime6 >= 9700) {
      break;
    }
  }
}

/* TO EXECUTE NEGATIVE SURGE ONCE 
  if (!negativesurgeExecuted) {
    negativesurge(); // Execute negativesurge() only once
    negativesurgeExecuted = true; // Set the flag to true to indicate that negativesurge() has been executed
  }
*/


void positivesway () {
  startTime1 = millis(); // Record the start time for actuator 1
  startTime2 = millis(); // Record the start time for actuator 2
  startTime3 = millis(); // Record the start time for actuator 3
  startTime4 = millis(); // Record the start time for actuator 4
  startTime5 = millis(); // Record the start time for actuator 5
  startTime6 = millis(); // Record the start time for actuator 6
  
  while (true) { 
    unsigned long currentTime = millis(); // Get the current time
    
    // Extend all actuators
    extendActuator1();
    extendActuator2();
    extendActuator3();
    extendActuator4();
    extendActuator5();
    extendActuator6();
    
    // Check if it's time to stop actuator 1
    if (currentTime - startTime1 >= 4500) {
      stopActuator(1); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 2
    if (currentTime - startTime2 >= 7900) {
      stopActuator(2); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 3
    if (currentTime - startTime3 >= 13500) {
      stopActuator(3); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 4
    if (currentTime - startTime4 >= 7100) {
      stopActuator(4); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    } 
    
    // Check if it's time to stop actuator 5
    if (currentTime - startTime5 >= 12700) {
      stopActuator(5); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 6
    if (currentTime - startTime6 >= 15800) {
      stopActuator(6); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Exit the loop if all actuators have stopped
    if (currentTime - startTime1 >= 4500 && 
        currentTime - startTime2 >= 7900 && 
        currentTime - startTime3 >= 13500 &&
        currentTime - startTime4 >= 7100 &&
        currentTime - startTime5 >= 12700 &&
        currentTime - startTime6 >= 15800) {
      break;
    }
  }
}
/* TO EXECUTE POSITIVE SWAY ONCE 
  if (!positiveswayExecuted) {
    positivesway(); // Execute positivesway() only once
    positiveswayExecuted = true; // Set the flag to true to indicate that positivesway() has been executed
  }
*/

void negativesway () {
  startTime1 = millis(); // Record the start time for actuator 1
  startTime2 = millis(); // Record the start time for actuator 2
  startTime3 = millis(); // Record the start time for actuator 3
  startTime4 = millis(); // Record the start time for actuator 4
  startTime5 = millis(); // Record the start time for actuator 5
  startTime6 = millis(); // Record the start time for actuator 6
  
  while (true) { 
    unsigned long currentTime = millis(); // Get the current time
    
    // Extend all actuators
    extendActuator1();
    extendActuator2();
    extendActuator3();
    extendActuator4();
    extendActuator5();
    extendActuator6();
    
    // Check if it's time to stop actuator 1
    if (currentTime - startTime1 >= 15100) { //should be 15800
      stopActuator(1); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 2
    if (currentTime - startTime2 >= 12700) {
      stopActuator(2); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 3
    if (currentTime - startTime3 >= 7100) {
      stopActuator(3); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 4
    if (currentTime - startTime4 >= 13500) {
      stopActuator(4); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    } 
    
    // Check if it's time to stop actuator 5
    if (currentTime - startTime5 >= 7900) {
      stopActuator(5); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 6
    if (currentTime - startTime6 >= 5500) { //should be 4500
      stopActuator(6); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Exit the loop if all actuators have stopped
    if (currentTime - startTime1 >= 15800 && 
        currentTime - startTime2 >= 12700 && 
        currentTime - startTime3 >= 7100 &&
        currentTime - startTime4 >= 13500 &&
        currentTime - startTime5 >= 7900 &&
        currentTime - startTime6 >= 4500) {
      break;
    }
  }
}
/* TO EXECUTE NEGATIVE SWAY ONCE 
  if (!negativeswayExecuted) {
    negativesway(); // Execute negativesway() only once
    negativeswayExecuted = true; // Set the flag to true to indicate that negativesway() has been executed
  }
*/

void positiveheave() { //Z translation (upwards)
  startTime1 = millis(); // Record the start time for actuator 1
  startTime2 = millis(); // Record the start time for actuator 2
  startTime3 = millis(); // Record the start time for actuator 3
  startTime4 = millis(); // Record the start time for actuator 4
  startTime5 = millis(); // Record the start time for actuator 5
  startTime6 = millis(); // Record the start time for actuator 6
  
  while (true) { 
    unsigned long currentTime = millis(); // Get the current time
    
    // Extend all actuators
    extendActuator1();
    extendActuator2();
    extendActuator3();
    extendActuator4();
    extendActuator5();
    extendActuator6();
    
    // Check if it's time to stop actuator 1
    if (currentTime - startTime1 >= 19500) { 
      stopActuator(1); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 2
    if (currentTime - startTime2 >= 19500) {
      stopActuator(2); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 3
    if (currentTime - startTime3 >= 19500) {
      stopActuator(3); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 4
    if (currentTime - startTime4 >= 19500) {
      stopActuator(4); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    } 
    
    // Check if it's time to stop actuator 5
    if (currentTime - startTime5 >= 19500) {
      stopActuator(5); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 6
    if (currentTime - startTime6 >= 19500) { //should be 4500
      stopActuator(6); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Exit the loop if all actuators have stopped
    if (currentTime - startTime1 >= 19500 && 
        currentTime - startTime2 >= 19500 && 
        currentTime - startTime3 >= 19500 &&
        currentTime - startTime4 >= 19500 &&
        currentTime - startTime5 >= 19500 &&
        currentTime - startTime6 >= 19500) {
      break;
    }
  }
}
/* TO EXECUTE POSITIVE HEAVE ONCE 
  if (!positiveheaveExecuted) {
    positiveheave(); // Execute positiveheave() only once
    positiveheaveExecuted = true; // Set the flag to true to indicate that positiveheave() has been executed
  }
*/

void negativeheave() { //Z translation (downwards)
  startTime1 = millis(); // Record the start time for actuator 1
  startTime2 = millis(); // Record the start time for actuator 2
  startTime3 = millis(); // Record the start time for actuator 3
  startTime4 = millis(); // Record the start time for actuator 4
  startTime5 = millis(); // Record the start time for actuator 5
  startTime6 = millis(); // Record the start time for actuator 6
  
  while (true) { 
    unsigned long currentTime = millis(); // Get the current time
    
    // Extend all actuators
    retractActuator1();
    retractActuator2();
    retractActuator3();
    retractActuator4();
    retractActuator5();
    retractActuator6();
    
    // Check if it's time to stop actuator 1
    if (currentTime - startTime1 >= 25000) { //should be 15800
      stopActuator(1); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 2
    if (currentTime - startTime2 >= 25000) {
      stopActuator(2); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 3
    if (currentTime - startTime3 >= 25000) {
      stopActuator(3); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 4
    if (currentTime - startTime4 >= 25000) {
      stopActuator(4); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    } 
    
    // Check if it's time to stop actuator 5
    if (currentTime - startTime5 >= 25000) {
      stopActuator(5); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 6
    if (currentTime - startTime6 >= 25000) { //should be 4500
      stopActuator(6); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Exit the loop if all actuators have stopped
    if (currentTime - startTime1 >= 25000 && 
        currentTime - startTime2 >= 25000 && 
        currentTime - startTime3 >= 25000 &&
        currentTime - startTime4 >= 25000 &&
        currentTime - startTime5 >= 25000 &&
        currentTime - startTime6 >= 25000) {
      break;
    }
  }
}
/* TO EXECUTE NEGATIVE HEAVE ONCE 
  if (!negativeheaveExecuted) {
    negativeheave(); // Execute negativeheave() only once
    negativeheaveExecuted = true; // Set the flag to true to indicate that negativeheave() has been executed
  }
*/

void positiveroll () {
  startTime1 = millis(); // Record the start time for actuator 1
  startTime2 = millis(); // Record the start time for actuator 2
  startTime3 = millis(); // Record the start time for actuator 3
  startTime4 = millis(); // Record the start time for actuator 4
  startTime5 = millis(); // Record the start time for actuator 5
  startTime6 = millis(); // Record the start time for actuator 6
  
  while (true) { 
    unsigned long currentTime = millis(); // Get the current time
    
    // Extend all actuators
    extendActuator1();
    extendActuator2();
    extendActuator3();
    extendActuator4();
    extendActuator5();
    extendActuator6();
    
    // Check if it's time to stop actuator 1
    if (currentTime - startTime1 >= 9000) {
      stopActuator(1); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 2
    if (currentTime - startTime2 >= 16000) {
      stopActuator(2); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 3
    if (currentTime - startTime3 >= 14400) {
      stopActuator(3); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 4
    if (currentTime - startTime4 >= 900) {
      stopActuator(4); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    } 
    
    // Check if it's time to stop actuator 5
    if (currentTime - startTime5 >= 400) {
      stopActuator(5); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 6
    if (currentTime - startTime6 >= 6800) {
      stopActuator(6); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Exit the loop if all actuators have stopped
    if (currentTime - startTime1 >= 9000 && 
        currentTime - startTime2 >= 16000 && 
        currentTime - startTime3 >= 14400 &&
        currentTime - startTime4 >= 900 &&
        currentTime - startTime5 >= 400 &&
        currentTime - startTime6 >= 6800) {
      break;
    }
  }
}
/* TO EXECUTE POSITIVE ROLL ONCE 
  if (!positiverollExecuted) {
    positiveroll(); // Execute positiveroll() only once
    positiverollExecuted = true; // Set the flag to true to indicate that positiveroll() has been executed
  }
*/

void negativeroll () {
  startTime1 = millis(); // Record the start time for actuator 1
  startTime2 = millis(); // Record the start time for actuator 2
  startTime3 = millis(); // Record the start time for actuator 3
  startTime4 = millis(); // Record the start time for actuator 4
  startTime5 = millis(); // Record the start time for actuator 5
  startTime6 = millis(); // Record the start time for actuator 6
  
  while (true) { 
    unsigned long currentTime = millis(); // Get the current time
    
    // Extend all actuators
    extendActuator1();
    extendActuator2();
    extendActuator3();
    extendActuator4();
    extendActuator5();
    extendActuator6();
    
    // Check if it's time to stop actuator 1
    if (currentTime - startTime1 >= 6800) {
      stopActuator(1); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 2
    if (currentTime - startTime2 >= 100) { 
      stopActuator(2); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 3
    if (currentTime - startTime3 >= 100) { 
      stopActuator(3); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 4
    if (currentTime - startTime4 >= 14400) {
      stopActuator(4); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    } 
    
    // Check if it's time to stop actuator 5
    if (currentTime - startTime5 >= 16000) {
      stopActuator(5); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 6
    if (currentTime - startTime6 >= 9000) {
      stopActuator(6); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Exit the loop if all actuators have stopped
    if (currentTime - startTime1 >= 6800 && 
        currentTime - startTime2 >= 100 && 
        currentTime - startTime3 >= 100 &&
        currentTime - startTime4 >= 14400 &&
        currentTime - startTime5 >= 16000 &&
        currentTime - startTime6 >= 9000) {
      break;
    }
  }
}
/* TO EXECUTE NEGATIVE ROLL ONCE 
  if (!negativerollExecuted) {
    negativeroll(); // Execute negativerollroll() only once
    negativerollExecuted = true; // Set the flag to true to indicate that negativeroll() has been executed
  }
*/

void positivepitch () {
  startTime1 = millis(); // Record the start time for actuator 1
  startTime2 = millis(); // Record the start time for actuator 2
  startTime3 = millis(); // Record the start time for actuator 3
  startTime4 = millis(); // Record the start time for actuator 4
  startTime5 = millis(); // Record the start time for actuator 5
  startTime6 = millis(); // Record the start time for actuator 6
  
  while (true) { 
    unsigned long currentTime = millis(); // Get the current time
    
    // Extend all actuators
    extendActuator1();
    extendActuator2();
    extendActuator3();
    extendActuator4();
    extendActuator5();
    extendActuator6();
    
    // Check if it's time to stop actuator 1
    if (currentTime - startTime1 >= 1300) { //EXTEND PAST 1.3s ???????? changing the value doesn't change anything. It stops at fixed length whatever the inputted value is.
      stopActuator(1); //to loop and return to original position, change "stopActuator" to "returnActuator" :) 
    }
    
    // Check if it's time to stop actuator 2
    if (currentTime - startTime2 >= 12800) {
      stopActuator(2); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 3
    if (currentTime - startTime3 >= 15400) {
      stopActuator(3); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 4
    if (currentTime - startTime4 >= 15400) {
      stopActuator(4); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    } 
    
    // Check if it's time to stop actuator 5
    if (currentTime - startTime5 >= 12800) {
      stopActuator(5); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 6
    if (currentTime - startTime6 >= 1300) {
      stopActuator(6); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Exit the loop if all actuators have stopped
    if (currentTime - startTime1 >= 1300 && 
        currentTime - startTime2 >= 12800 && 
        currentTime - startTime3 >= 15400 &&
        currentTime - startTime4 >= 15400 &&
        currentTime - startTime5 >= 12800 &&
        currentTime - startTime6 >= 1300) {
      break;
    }
  }
}
/* TO EXECUTE POSITIVE PITCH ONCE 
  if (!positivepitchExecuted) {
    positivepitch(); // Execute positivepitch() only once
    positivepitchExecuted = true; // Set the flag to true to indicate that positivepitch() has been executed
  }
*/

void negativepitch () {
  startTime1 = millis(); // Record the start time for actuator 1
  startTime2 = millis(); // Record the start time for actuator 2
  startTime3 = millis(); // Record the start time for actuator 3
  startTime4 = millis(); // Record the start time for actuator 4
  startTime5 = millis(); // Record the start time for actuator 5
  startTime6 = millis(); // Record the start time for actuator 6
  
  while (true) { 
    unsigned long currentTime = millis(); // Get the current time
    
    // Extend all actuators
    extendActuator1();
    extendActuator2();
    extendActuator3();
    extendActuator4();
    extendActuator5();
    extendActuator6();
    
    // Check if it's time to stop actuator 1
    if (currentTime - startTime1 >= 15000) { 
      stopActuator(1); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 2
    if (currentTime - startTime2 >= 2500) { //should be 6300, but actuator won't follow
      stopActuator(2); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 3
    if (currentTime - startTime3 >= 500) { //should be 4900, but actuator won't follow
      stopActuator(3); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 4
    if (currentTime - startTime4 >= 500) { //should be 4900, but actuator won't follow
      stopActuator(4); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    } 
    
    // Check if it's time to stop actuator 5
    if (currentTime - startTime5 >= 6600) { //should be 6300
      stopActuator(5); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 6
    if (currentTime - startTime6 >= 15000) {
      stopActuator(6); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Exit the loop if all actuators have stopped
    if (currentTime - startTime1 >= 18300 && 
        currentTime - startTime2 >= 6300 && 
        currentTime - startTime3 >= 4900 &&
        currentTime - startTime4 >= 4900 &&
        currentTime - startTime5 >= 6300 &&
        currentTime - startTime6 >= 18300) {
      break;
    }
  }
}
/* TO EXECUTE NEGATIVE PITCH ONCE 
  if (!negativepitchExecuted) {
    negativepitch(); // Execute negativepitch() only once
    negativepitchExecuted = true; // Set the flag to true to indicate that negativepitch() has been executed
  }
*/

void positiveyaw () {
  startTime1 = millis(); // Record the start time for actuator 1
  startTime2 = millis(); // Record the start time for actuator 2
  startTime3 = millis(); // Record the start time for actuator 3
  startTime4 = millis(); // Record the start time for actuator 4
  startTime5 = millis(); // Record the start time for actuator 5
  startTime6 = millis(); // Record the start time for actuator 6
  
  while (true) { 
    unsigned long currentTime = millis(); // Get the current time
    
    // Extend all actuators
    extendActuator1();
    extendActuator2();
    extendActuator3();
    extendActuator4();
    extendActuator5();
    extendActuator6();
    
    // Check if it's time to stop actuator 1 
    if (currentTime - startTime1 >= 2000) { //actuators 1,3,5 should be 5000, while actuators 2,4,6 should be 15000
      stopActuator(1); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 2
    if (currentTime - startTime2 >= 15000) {
      stopActuator(2); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 3
    if (currentTime - startTime3 >= 2000) {
      stopActuator(3); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 4
    if (currentTime - startTime4 >= 15000) {
      stopActuator(4); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    } 
    
    // Check if it's time to stop actuator 5
    if (currentTime - startTime5 >= 5000) {
      stopActuator(5); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 6
    if (currentTime - startTime6 >= 15000) {
      stopActuator(6); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Exit the loop if all actuators have stopped
    if (currentTime - startTime1 >= 2000 && 
        currentTime - startTime2 >= 15000 && 
        currentTime - startTime3 >= 2000 &&
        currentTime - startTime4 >= 15000 &&
        currentTime - startTime5 >= 5000 &&
        currentTime - startTime6 >= 15000) {
      break;
    }
  }
}
/* TO EXECUTE POSITIVE YAW ONCE 
  if (!positiveyawExecuted) {
    positiveyaw(); // Execute positiveyaw() only once
    positiveyawExecuted = true; // Set the flag to true to indicate that positiveyaw() has been executed
  }
*/

void negativeyaw () {
  startTime1 = millis(); // Record the start time for actuator 1
  startTime2 = millis(); // Record the start time for actuator 2
  startTime3 = millis(); // Record the start time for actuator 3
  startTime4 = millis(); // Record the start time for actuator 4
  startTime5 = millis(); // Record the start time for actuator 5
  startTime6 = millis(); // Record the start time for actuator 6
  
  while (true) { 
    unsigned long currentTime = millis(); // Get the current time
    
    // Extend all actuators
    extendActuator1();
    extendActuator2();
    extendActuator3();
    extendActuator4();
    extendActuator5();
    extendActuator6();
    
    // Check if it's time to stop actuator 1
    if (currentTime - startTime1 >= 15000) {
      stopActuator(1); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 2
    if (currentTime - startTime2 >= 5000) {
      stopActuator(2); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 3
    if (currentTime - startTime3 >= 15000) {
      stopActuator(3); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 4
    if (currentTime - startTime4 >= 5000) {
      stopActuator(4); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    } 
    
    // Check if it's time to stop actuator 5
    if (currentTime - startTime5 >= 15000) {
      stopActuator(5); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Check if it's time to stop actuator 6
    if (currentTime - startTime6 >= 5000) {
      stopActuator(6); //to loop and return to original position, change "stopActuator" to "returnActuator" :)
    }
    
    // Exit the loop if all actuators have stopped
    if (currentTime - startTime1 >= 15000 && 
        currentTime - startTime2 >= 5000 && 
        currentTime - startTime3 >= 15000 &&
        currentTime - startTime4 >= 5000 &&
        currentTime - startTime5 >= 15000 &&
        currentTime - startTime6 >= 5000) {
      break;
    }
  }
}
/* TO EXECUTE POSITIVE YAW ONCE 
  if (!negativeyawExecuted) {
    negativeyaw(); // Execute negativeyaw() only once
    negativeyawExecuted = true; // Set the flag to true to indicate that negativeyaw() has been executed
  }
*/


void loop() {
  
  /*if (!positivesurgeExecuted) {
    positivesurge(); // Execute positivesurge() only once
    Serial.println("Lengths (l): [337.9230689543023, 317.6571912341147, 352.16102343768387, 352.1610234376839, 317.65719123411463, 337.9230689543023]");
    positivesurgeExecuted = true; // Set the flag to true to indicate that positivesurge() has been executed
  }
  */
  /*if (!negativesurgeExecuted) {
    negativesurge(); // Execute positivesurge() only once
    Serial.println("Lengths (l): [334.49212975861064, 353.794989024998, 319.4676806396359, 319.4676806396359, 353.7949890249979, 334.49212975861064]");
    negativesurgeExecuted = true; // Set the flag to true to indicate that negativesurge() has been executed
  }
  */
  /*if (!positiveswayExecuted) {
    positivesway(); // Execute positivesway() only once
    Serial.println("Lengths (l): [311.864316662963, 326.8755592120412, 351.463756173379, 323.0328365637848, 347.8927337438376, 361.41061605089646]");
    positiveswayExecuted = true; // Set the flag to true to indicate that positivesway() has been executed
  }
  */
  /*if (!negativeswayExecuted) {
    negativesway(); // Execute negativesway() only once
    Serial.println("Lengths (l): [361.41061605089646, 347.8927337438377, 323.0328365637848, 351.463756173379, 326.8755592120411, 311.86431666296306]");
    negativeswayExecuted = true; // Set the flag to true to indicate that negativesway() has been executed
  }
  */
  /*if (!positiveheaveExecuted) {
    positiveheave(); // Execute positiveheave() only once
    Serial.println("Lengths (l): [377.91466325213247, 377.9146632521325, 377.9146632521324, 377.9146632521324, 377.9146632521324, 377.9146632521325]");
    positiveheaveExecuted = true; // Set the flag to true to indicate that positiveheave() has been executed
  }
  */
  /*if (!negativeheaveExecuted) {
    negativeheave(); // Execute negativeheave() only once
    Serial.println("Lengths (l): [291.6461772438869, 291.6461772438869, 291.6461772438868, 291.6461772438868, 291.64617724388677, 291.6461772438869]");
    negativeheaveExecuted = true; // Set the flag to true to indicate that negativeheave() has been executed
  }
  */
  /*if (!positiverollExecuted) {
    positiveroll(); // Execute positiveroll() only once
    Serial.println("Lengths (l): [331.676705557388, 362.38805315914243, 355.22481042248114, 295.6416482725346, 293.45220299099987, 321.8372463273735]");
    positiverollExecuted = true; // Set the flag to true to indicate that positiveroll() has been executed
  }
  */
  /*if (!negativerollExecuted) {
    negativeroll(); // Execute negativerollroll() only once
    Serial.println("Lengths (l): [321.83724632737346, 293.452202991, 295.64164827253455, 355.22481042248114, 362.3880531591423, 331.676705557388]");
    negativerollExecuted = true; // Set the flag to true to indicate that negativeroll() has been executed
  }
  */
  /*if (!positivepitchExecuted) {
    positivepitch(); // Execute positivepitch() only once
    Serial.println("Lengths (l): [331.676705557388, 362.38805315914243, 355.22481042248114, 295.6416482725346, 293.45220299099987, 321.8372463273735]");
    positivepitchExecuted = true; // Set the flag to true to indicate that positivepitch() has been executed
  }
  */
  /*if (!negativepitchExecuted) {
    negativepitch(); // Execute negativepitch() only once
    Serial.println("Lengths (l): [372.66187132953405, 319.8068926713708, 313.4231183709267, 313.42311837092666, 319.80689267137075, 372.66187132953405]");
    negativepitchExecuted = true; // Set the flag to true to indicate that negativepitch() has been executed
  }
  */
  /*if (!positiveyawExecuted) {
    positiveyaw(); // Execute positiveyaw() only once
    Serial.println("Lengths (l): [314.6277714774449, 358.2355290376627, 314.6277714774449, 358.2355290376626, 314.6277714774449, 358.23552903766273]");
    positiveyawExecuted = true; // Set the flag to true to indicate that positiveyaw() has been executed
  }
  */
  /*if (!negativeyawExecuted) {
    negativeyaw(); // Execute negativeyaw() only once
    Serial.println("Lengths (l): [358.2355290376627, 314.6277714774449, 358.2355290376626, 314.6277714774449, 358.2355290376626, 314.6277714774449]");
    negativeyawExecuted = true; // Set the flag to true to indicate that negativeyaw() has been executed
  }
  */
  /*retractActuator2();
  delay(1000);
  */
  

  /*extendActuator1();
  delay(1000);
  */
}






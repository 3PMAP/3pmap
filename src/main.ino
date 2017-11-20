/////////////
// CONTENT //
/////////////
// 1. libraries
// 2. variables
// 3. initializes
// 4. setup function
// 5. loop function
// 6. callable functions

///////////////
// LIBRARIES //
///////////////
#include <Stepper.h>

/////////////
// DEFINES //
/////////////
#define motorSteps 200  // not sure what the exact number is, but this works
#define motor1Pin0 8    // define pins for steppermotor 1
#define motor1Pin1 9
#define motor1Pin2 10
#define motor1Pin3 11
#define ledPin 13       // define test LED


////////////////////////
// STEPPER INITIALIZE //
////////////////////////
Stepper Stepper1(motorSteps, motor1Pin0, motor1Pin1, motor1Pin2, motor1Pin3);


///////////
// SETUP //
///////////
void setup() {
  // serial port for bug fixing
  Serial.begin(9600);

  // LED pin and blink 3 times
  pinMode(ledPin, OUTPUT);
  blink(3);

  // max speed is around 120
  Stepper1.setSpeed(100);
}


///////////////////
// LOOP FUNCTION //
///////////////////
void loop() {
  // Step forward 100 steps:
  Stepper1.step(500);
}


//////////////
// CALLABLE //
//////////////
void blink(int howManyTimes) {
  int i;
  for (i = 0; i < howManyTimes; i++) {
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
  }
}

void fullBendFinger(int finger) {
  switch (finger) {
    case 1:
      Stepper1.step(500);
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
  }
}

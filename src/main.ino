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
int step_mode = 8;
#define motorSteps 2048 * (step_mode/4)   // not sure what the exact number is, but this works

#define ledPin 13       // define test LED

////////////////////////
// STEPPER INITIALIZE //
////////////////////////
Stepper Stepper1(motorSteps, 2, 3, 4, 5, step_mode);


///////////
// SETUP //
///////////
void setup() {
  // serial port
  Serial.begin(9600);

  // LED pin and blink 3 times
  pinMode(ledPin, OUTPUT);
  blink(3);

  // max: 160
  Stepper1.setSpeed(100);
}

///////////////////
// LOOP FUNCTION //
///////////////////
void loop() {
  // Step forward 100 steps:
  Serial.println("Forward");
  Stepper1.step(motorSteps);
  delay(100);
  Serial.println("Backward");
  Stepper1.step(-motorSteps);
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

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
// step_mode let us use halfsteps (but we prolly don't need that)
int step_mode = 8; // 4 = full, 8 = half

#define fullRev 2048 * (step_mode/4)

#define ledPin 13       // define test LED

////////////////////////
// STEPPER INITIALIZE //
////////////////////////
// the four integers are the pins the motor is connected to.
Stepper Stepper1(fullRev, 2, 3, 4, 5, step_mode);


///////////
// SETUP //
///////////
void setup() {
  // serial port
  Serial.begin(9600);

  // LED pin and blink 3 times
  pinMode(ledPin, OUTPUT);
  blink(3);

  // max is around 160
  Stepper1.setSpeed(100);
}

///////////////////
// LOOP FUNCTION //
///////////////////
void loop() {
  // Step forward 100 steps:
  Serial.println("Forward");
  Stepper1.step(fullRev);
  delay(100);
  Serial.println("Backward");
  Stepper1.step(-fullRev);
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

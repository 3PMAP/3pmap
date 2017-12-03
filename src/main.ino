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

// number of steps it takes to turn 360º
#define fullRev 2048 * (step_mode/4)

// setup LED at pin 13
#define ledPin 13

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

  partRev(1, 1.0);
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

void partRev(int finger, float frac) {
  if (frac > 0) {
    switch (finger) {
      case 1:
        Stepper1.step(fullRev);
        break;
      case 2:
        Stepper1.step(fullRev);
        break;
      case 3:
        Stepper1.step(fullRev);
        break;
      case 4:
        Stepper1.step(fullRev);
        break;
      case 5:
        Stepper1.step(fullRev);
        break;
    }
  }
  else {
    Serial.println("Fraction of rotation can't be negative or 0.");
    float frac = 1.0;
    partRev(finger, frac);
  }
}

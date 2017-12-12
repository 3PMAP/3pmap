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
// step_mode let us use halfsteps (but we probably don't need that)
int step_mode = 8; // 4 = full, 8 = half

// number of steps it takes to turn motor 360º
#define fullRev 2048 * (step_mode/4)

////////////////////////
// STEPPER INITIALIZE //
////////////////////////
// the four integers are the pins the motor is connected to.
Stepper Digit1(fullRev, 2, 3, 4, 5, step_mode);
Stepper Digit2(fullRev, 6, 7, 8, 9, step_mode);
Stepper Digit3(fullRev, 10, 11, 12, 13, step_mode);


///////////
// SETUP //
///////////
void setup() {
  // serial port
  Serial.begin(9600);

  // Built in led blinks 3 times
  pinMode(LED_BUILTIN, OUTPUT);
  blink(3);

  // max is around 160 RPM
  Digit1.setSpeed(100);
  Digit2.setSpeed(100);
  Digit3.setSpeed(100);
}

///////////////////
// LOOP FUNCTION //
///////////////////
void loop() {
  Digit1.step(fullRev);
  delay(100);
  Digit2.step(fullRev);
  delay(100);
  Digit3.step(fullRev);
  delay(100);

  turnDigit(1, 0.25);
  turnDigit(2, 0.5);
  turnDigit(3, 0.75);
}


//////////////
// CALLABLE //
//////////////
void blink(int howManyTimes) {
  int i;
  for (i = 0; i < howManyTimes; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(200);
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
  }
}

void turnDigit(int digNum, float frac) {
  if (frac > 0) {
    int steps = fullRev * frac;

    switch (digNum) {
      case 1:
        Digit1.step(steps);
        break;
      case 2:
        Digit2.step(steps);
      case 3:
        Digit3.step(steps);
    }
  }
  else {
    Serial.println("Fraction of rotation can't be negative or 0.");
    float frac = 1.0;
    turnDigit(digNum, frac);
  }
}

void thumbsUp() {
  turnDigit(1, 5);
  turnDigit(2, -5);
  turnDigit(3, -5);
}

void pinch() {
  turnDigit(1, 5);
  turnDigit(2, 5);
}

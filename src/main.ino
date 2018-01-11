// LIBRARIES //
#include <Servo.h>

Servo m1;
Servo m2;
Servo m3;
Servo m4;
Servo m5;


// SETUP //
void setup() {
  // Attach motor variables to digital pin
  m1.attach(2);
  m2.attach(3);
  m3.attach(4);
  m4.attach(5);
  m5.attach(6);

  // Set EMG pin to input
  pinMode(A0, INPUT);

  // Button for Rock, Paper and Scissors
  pinMode(7, INPUT);
}


// LOOP //
void loop() {
  int emg = analogRead(A0);

  switch (emg) {
    case 70:
      pinch();
      break;
    case 81:
      thumbsUp();
      break;
    case 60:
      middleFinger();
      break;
    default:
      allFingers(0);
      break;
  }

  int buttonState = 0;
  if (buttonState == HIGH) {
    int gstr = random(3);

    if (gstr = 0) {
      rock();
    } else if (gstr = 1) {
      paper();
    } else {
      scissors();
    }

    // reset buttonState
    buttonState = 0;
  }
}


// FUNCTIONS //
void allFingers(int pos) {
  // get all fingers in same position.
  // 0 for open hand, 180 for fully closed hand
  m1.write(pos);
  m2.write(pos);
  m3.write(pos);
  m4.write(pos);
  m5.write(pos);
  delay(100);
}

void pinch() {
  m1.write(90);
  m2.write(90);
  m3.write(180);
  m4.write(180);
  m5.write(180);
  delay(100);
}

void thumbsUp() {
  m1.write(0);
  m2.write(180);
  m3.write(180);
  m4.write(180);
  m5.write(180);
  delay(100);
}

void middleFinger() {
  m1.write(180);
  m2.write(180);
  m3.write(0);
  m4.write(180);
  m5.write(180);
  delay(100);
}

void rock() {
  allFingers(180);
}

void paper() {
  allFingers(0);
}

void scissors() {
  m1.write(0);
  m2.write(180);
  m3.write(180);
  m4.write(0);
  m5.write(0);
}

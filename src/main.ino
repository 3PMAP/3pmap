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
}


// LOOP //
void loop() {
  int emg = analogRead(A0);

  switch (emg) {
    case 70:
      pinch();
    case 81:
      thumbsUp();
    case 60:
      middleFinger();
  }
}


// FUNCTIONS //
void pinch() {
  m1.write(90);
  m2.write(90);
  m3.write(180);
  m4.write(180);
  m5.write(180);
}

void thumbsUp() {
  m1.write(0);
  m2.write(180);
  m3.write(180);
  m4.write(180);
  m5.write(180);
}

void middleFinger() {
  m1.write(180);
  m2.write(180);
  m3.write(0);
  m4.write(180);
  m5.write(180);
}

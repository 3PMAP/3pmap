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

  Serial.begin(9600);
}


// LOOP //
void loop() {
  int emg = analogRead(A4);

  if (emg < 50) {
    allFingers(700);
  } else if (emg > 50 && emg < 200) {
    pinch();
  } else if (emg > 700) {
    allFingers(2300);
  }
  
  delay(1000);
}

// FUNCTIONS //
void allFingers(int pos) {
  // get all fingers in same position.
  // 0 for open hand, 180 for fully closed hand
  m1.writeMicroseconds(pos);
  m2.writeMicroseconds(pos);
  m3.writeMicroseconds(pos);
  m4.writeMicroseconds(pos);
  m5.writeMicroseconds(pos);
  delay(1000);
}

void pinch() {
  m1.writeMicroseconds(2300);
  m2.writeMicroseconds(2300);
  m3.writeMicroseconds(700);
  m4.writeMicroseconds(700);
  m5.writeMicroseconds(700);
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

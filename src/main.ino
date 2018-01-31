// LIBRARIES //
#include <Servo.h>

Servo m1;
Servo m2;
Servo m3;
Servo m4;
Servo m5;

//Setup for lock position
const unsigned long lLockOut = 2000L;
unsigned long lStartTime = 0L;
bool bStartLockTimer = false;
bool bActiveLock = false;

// SETUP //
void setup() {
  // Attach motor variables to digital pin
  m1.attach(2);
  m2.attach(3);
  m3.attach(4);
  m4.attach(5);
  m5.attach(6);
  delay(5000)

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

  if (emg > 700) {
    if(!bStartLockTimer)
    {
      lStartTime = millis();
      bStartLockTimer = true;
    }
  } else {
    lStartTime = 0L;
    bStartLockTimer = false;
  }

  if(bStartLockTimer && millis()-lStartTime >= lLockOut) {
    bActiveLock = !bActiveLock;
    lStartTime = 0L;
    bStartLockTimer = false;

    if(bActiveLock) {
      allFingers(2300);
    } else {
      allFingers(700);
    }

  delay(1000);
  }

  if(bActiveLock)
    allFingers(2300);
  else
    allFingers(700);

  delay(100);
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
  delay(1000);
}

void thumbsUp() {
  m1.writeMicroseconds(700);
  m2.writeMicroseconds(2300);
  m3.writeMicroseconds(2300);
  m4.writeMicroseconds(2300);
  m5.writeMicroseconds(2300);
  delay(1000);
}

void middleFinger() {
  m1.writeMicroseconds(2300);
  m2.writeMicroseconds(2300);
  m3.writeMicroseconds(700);
  m4.writeMicroseconds(2300);
  m5.writeMicroseconds(2300);
  delay(1000);
}

void rock() {
  m1.writeMicroseconds(700)
  m2.writeMicroseconds(700)
  m3.writeMicroseconds(2300)
  m4.writeMicroseconds(2300)
  m5.writeMicroseconds(700)
}

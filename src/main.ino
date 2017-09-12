const int switchPin = 2;

// Setup for motorpins
const int motor1 = 9;
const int motor2 = 10;
const int motor3 = 11;
const int motor4 = 12;
const int motor5 = 13;

int switchState = 0;

int motors[] = {
  9, 10, 11, 12, 13
};


// setup code
void setup() {
  for (int m = 0; m < 5; m++) {
    pinMode(motors[m], OUTPUT);
  }

  pinMode(switchPin, INPUT);
}




// re-usable functions
stopAllMotors() {
  digitalWrite(motorPin, LOW);
}
// or
stopAllMotos() {
  for (int m = 0; m < 5; m++) {
    pinMode(motors[m], LOW);
  }
}






// main code
void loop() {
  switchState = digitalRead(switchPin);

  digitalWrite(motorPin, switchState);
  delay(1000)
}

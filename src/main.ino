
int switchPin = 2;

// Setup for motorpins
const int motor1 = 9;
const int motor2 = 10;
const int motor3 = 11;
const int motor4 = 12;
const int motor5 = 13;

int switchState = 0;

// setup code
void setup() {
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
  pinMode(motor5, OUTPUT);

  pinMode(switchPin, INPUT);
}




// call functions
void stopAllMotors() {
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, LOW);
  digitalWrite(motor5, LOW);
}

void startAllMotors() {
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, HIGH);
  digitalWrite(motor3, HIGH);
  digitalWrite(motor4, HIGH);
  digitalWrite(motor5, HIGH);
}

// main code
void loop() {
  switchState = digitalRead(switchPin);

  digitalWrite(motor1, switchState);
  delay(1000);
}

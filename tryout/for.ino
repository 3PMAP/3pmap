const int switchPin = 2;

// Setup for motorpins
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




// call functions
void stopAllMotors() {
  for (int m = 0; m < 5; m++) {
    digitalWrite(motors[m], LOW);
  }
}

void startAllMotors() {
  for (int m = 0; m < 5; m++) {
    digitalWrite(motors[m], LOW)
  }
}





// main code
void loop() {
  switchState = digitalRead(switchPin);

  digitalWrite(motors[], switchState);
  delay(1000);
}

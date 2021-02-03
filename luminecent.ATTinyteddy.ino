
//variables for vibration
int RedPin = 3; //digital pin 2
int GreenPin = 0; //digital pin 0

//varibales for potentiometer
int potPin = 1; //analog pin 1 
int potVal;

int switchVal = 0;

int threshold1 = 100;
int threshold2 = 400;
int threshold3 = 800;

void setup() {
  
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  //variable that reads the potentiometer and stores it
  potVal = analogRead(potPin);

  //uses the function 
  checkState(potVal);

  switch (switchVal) {

    case 0: // no color
      digitalWrite(RedPin, LOW);
      digitalWrite(GreenPin, LOW);
      break;

    case 1:// red
      digitalWrite(RedPin, HIGH);
      digitalWrite(GreenPin, LOW);
      break;

    case 2:// green
      digitalWrite(GreenPin, HIGH);
      digitalWrite(RedPin, LOW);
      break;

  }
}

//function that switches between states based off of potentiometer
//readings 
void checkState( int aPotVal) {

  if (aPotVal <= threshold1) {
    switchVal = 0;
  }
  if (aPotVal > threshold1 && aPotVal <= threshold2) {
    switchVal = 1;
  }
  if (aPotVal > threshold2 && aPotVal <= threshold3) {
    switchVal = 2;
  }
}

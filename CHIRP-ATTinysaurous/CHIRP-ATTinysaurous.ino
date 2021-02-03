//This program uses a button to change states which controls a piezo buzzer 
//The name comes from it sounding like a bird when you boop them on the nose (button)

//variables for the piezo sound/buzzer/output
const int piezoPinSound = 2;
int piezoValues;

//variables for the button/input
int buttonPin = 1;
boolean buttonState = false;
boolean prevButtonState = false;


int switchVal = 1;


void setup() {
  pinMode(buttonPin, INPUT);

}

void loop() {

  //uses the debounce function to set the buttonState variable
  buttonState = Debounce(buttonPin, prevButtonState);

  // changes the states when the button is pressed
  if (buttonState == HIGH && prevButtonState == LOW) {
    switchVal = switchVal + 1;
    if (switchVal == 3) {
      switchVal = 0;
    }
  }

  switch (switchVal) {

    case 0: // high pitch sound
      //digitalWrite(2, HIGH);
      tone (2, 10);
      delay(500);
      noTone(2);
      //delay(1000);
      break;

    case 1: //low pitch sound
      //digitalWrite(2, LOW);
      tone(2, 300);
      delay(500);
      noTone(2);
      //delay(1000);
      break;

      case 2:// no sound 
      tone(2,0);
      delay(500);
      noTone(2);
      break;
  }
  prevButtonState = buttonState;
}

// function that allows the button to act when pressed once and again when pressed again
boolean Debounce (int aRandomButtonPin, boolean aPrevButtonState) {
  boolean aButtonState = digitalRead(aRandomButtonPin);
  if (aButtonState != aPrevButtonState) {
    delay(5);
    aButtonState = digitalRead(aRandomButtonPin);
  }
  return aButtonState;
}

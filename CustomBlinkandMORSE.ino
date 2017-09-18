/**
   Name: Joshua Dusome
   Date: 9/18/2017
   Purpose: This program is designed to display some functionality of the arduino LED lights. By default it will display both lights as a siren.
   If the user presses the first button it will flash blue, the second will flash red. Adjusting the rotation dial will change the frequency
   of the lights. If you press both buttons, it will display a message in MORSE code. The message that is displayed, is defined in the first
   constant called "CustomMessage". currently only supports uppercase EN-CA Strings, but will not crash if unsupported characters are used.
*/

//custom Morse code message
const String CustomMessage = "This code is brought to you, by Joshua Dusome";

//local variables
int code[4];
int frequency = 0;
int blueButton = 2;
int redButton = 3;

/** 
 *  the setup function runs once when you press reset or power the board. Initializes pins.
 */
void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(0, INPUT);
  pinMode(blueButton, INPUT);
  pinMode(redButton, INPUT);
}

/**
 * the loop function runs over and over again forever. Will display a siren, or MORSE code message
 * depending on which buttons have been pressed.
 */
void loop() {
  // read the value from the sensor, adjust frequency accordingly:
  frequency = analogRead(0);

  //flash both lights
  if (digitalRead(blueButton) == HIGH && digitalRead(redButton) == HIGH) {
    digitalWrite(13, HIGH);
    delay(frequency);
    digitalWrite(13, LOW);
    delay(frequency);
    digitalWrite(12, HIGH);
    delay(frequency);
    digitalWrite(12, LOW);
    delay(frequency);
  }

  //flash just blue light
  else if (digitalRead(blueButton) == HIGH) {
    digitalWrite(12, HIGH);
    delay(frequency);
    digitalWrite(12, LOW);
    delay(frequency);
  }

  //flash just red light
  else if (digitalRead(redButton) == HIGH) {
    digitalWrite(13, HIGH);
    delay(frequency);
    digitalWrite(13, LOW);
    delay(frequency);
  }

  //both buttons are pressed, display custom MORSE code message
  else {
    for (int i = 0; i < CustomMessage.length(); i++){
      String currentChar = CustomMessage.substring(i,i+1);
      currentChar.toUpperCase();
      displayMORSE(currentChar);
    }
  }
}

/**
 * method used to calculate the MORSE pattern, and control the lights for an individual character
 */
void displayMORSE(String character) {
  //this modifies the code array
  calculateCode(character);

  //change lights based off current array
  controlLight();
}

/**
 * This method is used to generate a code based on the character passed in, currently only supports uppercase EN-CA Strings
 */
void calculateCode(String character) {

  if (character == "A") {
    code[0] = 1;
    code[1] = 3;
    code[2] = 0;
    code[3] = 0;
  }
  else if (character == "B") {
    code[0] = 3;
    code[1] = 1;
    code[2] = 1;
    code[3] = 1;
  }
  else if (character == "C") {
    code[0] = 3;
    code[1] = 1;
    code[2] = 3;
    code[3] = 1;
  }
  else if (character == "D") {
    code[0] = 3;
    code[1] = 1;
    code[2] = 1;
    code[3] = 0;
  }
  else if (character == "E") {
    code[0] = 1;
    code[1] = 0;
    code[2] = 0;
    code[3] = 0;
  }
  else if (character == "F") {
    code[0] = 1;
    code[1] = 1;
    code[2] = 3;
    code[3] = 1;
  }
  else if (character == "G") {
    code[0] = 3;
    code[1] = 3;
    code[2] = 1;
    code[3] = 0;
  }
  else if (character == "H") {
    code[0] = 1;
    code[1] = 1;
    code[2] = 1;
    code[3] = 1;
  }
  else if (character == "I") {
    code[0] = 1;
    code[1] = 1;
    code[2] = 0;
    code[3] = 0;
  }
  else if (character == "J") {
    code[0] = 1;
    code[1] = 3;
    code[2] = 3;
    code[3] = 3;
  }
  else if (character == "K") {
    code[0] = 3;
    code[1] = 1;
    code[2] = 3;
    code[3] = 0;
  }
  else if (character == "L") {
    code[0] = 1;
    code[1] = 3;
    code[2] = 1;
    code[3] = 1;
  }
  else if (character == "M") {
    code[0] = 3;
    code[1] = 3;
    code[2] = 0;
    code[3] = 0;
  }
  else if (character == "N") {
    code[0] = 3;
    code[1] = 1;
    code[2] = 0;
    code[3] = 0;
  }
  else if (character == "O") {
    code[0] = 3;
    code[1] = 3;
    code[2] = 3;
    code[3] = 0;
  }
  else if (character == "P") {
    code[0] = 1;
    code[1] = 3;
    code[2] = 3;
    code[3] = 1;
  }
  else if (character == "Q") {
    code[0] = 3;
    code[1] = 3;
    code[2] = 1;
    code[3] = 3;
  }
  else if (character == "R") {
    code[0] = 1;
    code[1] = 3;
    code[2] = 1;
    code[3] = 0;
  }
  else if (character == "S") {
    code[0] = 1;
    code[1] = 1;
    code[2] = 1;
    code[3] = 0;
  }
  else if (character == "T") {
    code[0] = 3;
    code[1] = 0;
    code[2] = 0;
    code[3] = 0;
  }
  else if (character == "U") {
    code[0] = 1;
    code[1] = 1;
    code[2] = 3;
    code[3] = 0;
  }
  else if (character == "V") {
    code[0] = 1;
    code[1] = 1;
    code[2] = 1;
    code[3] = 3;
  }
  else if (character == "W") {
    code[0] = 1;
    code[1] = 3;
    code[2] = 3;
    code[3] = 0;
  }
  else if (character == "X") {
    code[0] = 3;
    code[1] = 1;
    code[2] = 1;
    code[3] = 3;
  }
  else if (character == "Y") {
    code[0] = 3;
    code[1] = 1;
    code[2] = 3;
    code[3] = 3;
  }
  else if (character == "Z") {
    code[0] = 3;
    code[1] = 3;
    code[2] = 1;
    code[3] = 1;
  }
  //unrecognized character
  else {
    code[0] = 0;
    code[1] = 0;
    code[2] = 0;
    code[3] = 0;
  }
}
/**
 * method used to flash the lights, based on the MORSE code pattern
 */
void controlLight() {
  for (int i = 0; i <= 3; i++) {
    if(code[i] != 0){
      digitalWrite(10, HIGH);
      delay(frequency * code[i]);
      digitalWrite(10, LOW);
      delay(frequency);
    }
  }
}




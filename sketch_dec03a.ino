// Funken library
// Download the Funken library here: https://github.com/astefas/Funken/tree/master/bin
// Install with Sketch > Include Library > Add .ZIP Library
#include <Funken.h>

#include <Wire.h>
#include "rgb_lcd.h"

Funken fnk;
rgb_lcd lcd;

const int colorR = 255;
const int colorG = 0;
const int colorB = 0;

bool alarm=false;

const int ledPin = 2; // the pin that the LED is attached to

void setup() {
  /*
  // initialize serial communication:
  Serial.begin(57600);
  */
  fnk.begin(57600, 0, 0); // higher baudrate for better performance
  fnk.listenTo("TEST", test); // however you want to name your callback
  
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  lcd.begin(16, 2);
}

void loop() {
  // needed to make FUNKEN work
  fnk.hark();

  
  if (alarm) {
    digitalWrite(ledPin, HIGH);   // set the LED on
    delay(500);               // for 500ms
    digitalWrite(ledPin, LOW);   // set the LED off
    delay(500);
  }
  
  /*
  // see if there's incoming serial data:
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    s = Serial.read();
    // if it's a capital H (ASCII 72), turn on the LED:
    if (incomingByte == 'H') {
      h = true;
      digitalWrite(ledPin, HIGH);
    }
    // if it's an L (ASCII 76) turn off the LED:
    if (incomingByte == 'L') {
      digitalWrite(ledPin, LOW);
    }
  }
  */
}

void test(char *c) {

  // get first argument
  char *token = fnk.getToken(c); // is needed for library to work properly, but can be ignored

  String s = "" + atoi(fnk.getArgument(c));

  lcd.print(s);

  if(s=="h")
  {
    alarm=true;
  }

}
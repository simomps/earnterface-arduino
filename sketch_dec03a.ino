/*
  Physical Pixel

  An example of using the Arduino board to receive data from the computer. In
  this case, the Arduino boards turns on an LED when it receives the character
  'H', and turns off the LED when it receives the character 'L'.
  The data can be sent from the Arduino Serial Monitor, or another program like
  Processing (see code below), Flash (via a serial-net proxy), PD, or Max/MSP.
  The circuit:
  - LED connected from digital pin 13 to ground

  created 2006
  by David A. Mellis
  modified 30 Aug 2011
  by Tom Igoe and Scott Fitzgerald
  This example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/PhysicalPixel
*/
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;
const int colorR = 255;
const int colorG = 0;
const int colorB = 0;

const int ledPin = 2; // the pin that the LED is attached to
int incomingByte;      // a variable to read incoming serial data into
bool h = false;
String s = "";

void setup() {
  // initialize serial communication:
  Serial.begin(57600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  lcd.setRGB(colorR, colorG, colorB);
  lcd.begin(16, 2);
}

void loop() {
  Serial.println(colorR);
  lcd.print(s);
  if (h) {
    digitalWrite(ledPin, HIGH);   // set the LED on
    delay(500);               // for 500ms
    digitalWrite(ledPin, LOW);   // set the LED off
    delay(500);
  }
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
}

#include <Wire.h>
#include "rgb_lcd.h"
#include <Servo.h>

/*
rgb_lcd lcd;
const int colorR = 255;
const int colorG = 0;
const int colorB = 0;

const int ledPin = 2; // the pin that the LED is attached to
String incomingByte;      // a variable to read incoming serial data into
int trigger = 0;
String s = "";
*/
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int pos = 0;    // variable to store the servo position
int incomingByte = 0;   // for incoming serial data

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  
  myservo.attach(6);  // attaches the servo on pin 9 to the servo object
  /*
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  lcd.begin(16, 2);
  */
}

void loop() {
  
  // send data only when you receive data:
  if (Serial.available() > 0) {
          // read the incoming byte:
          incomingByte = Serial.read();

          // say what you got:
          Serial.print("received: ");
          Serial.print (incomingByte);
          if(incomingByte == 108){
           Serial.println(" sent 0 Rotaing CW "); 
           myservo.write(0); 
          }else if(incomingByte == 114){
            Serial.println(" sent 180 Rotaing CCW "); 
            myservo.write(180); 
          }else if(incomingByte == 115){
            Serial.println(" sent Stopped "); 
            myservo.write(60); 
          }else if(incomingByte == 10){
          }else{
            Serial.println(" moving Random"); 
            myservo.write(incomingByte); 
          }
            
           
  }
  /*
  // see if there's incoming serial data:
  if (Serial.available() > 0) {
    lcd.print(incomingByte);

    incomingByte = Serial.readStringUntil('\n');

    if (incomingByte == "ACTION_1") {
      // DO SOME ACTION HERE
      trigger = 1;
    }
    if (incomingByte == "ACTION_2") {
      // DO SOME ACTION HERE
    }
    if (trigger == 1) {
      digitalWrite(ledPin, HIGH);   // set the LED on
      delay(500);               // for 500ms
      digitalWrite(ledPin, LOW);   // set the LED off
      delay(500);
      Serial.write("test");
    }
  }
  */
}

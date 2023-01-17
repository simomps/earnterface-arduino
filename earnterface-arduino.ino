#include <Wire.h>
#include "rgb_lcd.h"
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
Servo myservo1;
// twelve servo objects can be created on most boards
int pos = 0;    // variable to store the servo position
int incomingByte = 0;   // for incoming serial data

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  
  myservo.attach(6);  // attaches the servo on pin 9 to the servo object
  myservo1.attach(9);
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
            myservo1.write(180); 
          }else if(incomingByte == 115){
            Serial.println(" sent Stopped "); 
            myservo.write(60);
            myservo1.write(60); 
          }else if(incomingByte == 10){
          }else{
            Serial.println(" moving Random"); 
            myservo.write(incomingByte);
            myservo1.write(incomingByte);
          }
            
  }}

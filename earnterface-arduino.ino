#include <Wire.h>
#include "rgb_lcd.h"
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
Servo myservo1;

String incomingByte;   // for incoming serial data

int myState = 0;
long myStartTime = 0;

const long time1 = 2000; // 20 sec
const long time2 = 4000; // 40 sec

void setup() {
  // initialize serial communication:
  Serial.begin(57600);
  
  myservo.attach(6);  // attaches the servo on pin 9 to the servo object
  myservo1.attach(9);
}

void loop() {
  // see if there's incoming serial data:
  if (Serial.available() > 0) {

    incomingByte = Serial.readStringUntil('\n');
    // read the incoming byte:

    if (incomingByte == "ACTION_1") {
      // DO SOME ACTION HERE
      myState = 1;
      //START TIMER
      myStartTime = millis();
      Serial.println("HEY");
    }
    if (incomingByte == "ACTION_2") {
      // DO SOME ACTION HERE
    }
    if (myState == 1) {
      Serial.println("last: ");
      long m = millis() - myStartTime;
      Serial.write(" " + m);
      //change cycle based on timer
      if(millis() - myStartTime < time1){ //for left turn
       myservo.write(0);
       myservo1.write(0);
       Serial.write(" :1");
      }
      if(millis() - myStartTime >= time1 && millis() - myStartTime < time2){ //for right turn
        myservo.write(180);
        myservo1.write(180); 
        Serial.write(" :2");
      }
      if(millis() - myStartTime >= time2){ //after 1 min stop
        myservo.write(90);
        myservo1.write(90);
        Serial.write(" :3");
      }
      //delay(1000);               // for 1000ms
      Serial.write("test");
    }
  }
} 

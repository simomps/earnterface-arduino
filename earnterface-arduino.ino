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
  Serial.begin(57600);
  
  myservo.attach(6);  // attaches the servo on pin 9 to the servo object
  myservo1.attach(9);
}

void loop() {
  // see if there's incoming serial data:
  if (Serial.available() > 0) {
    lcd.print(incomingByte);

    incomingByte = Serial.readStringUntil('\n');
    // read the incoming byte:
    incomingByte = Serial.read();


    if (incomingByte == "ACTION_1") {
      // DO SOME ACTION HERE
      trigger = 1;
      //START TIMER
      lastMillis = millis();
    }
    if (incomingByte == "ACTION_2") {
      // DO SOME ACTION HERE
    }
    if (trigger == 1) {
      //change cycle based on timer
      if(lastMillis >= 30L * 1000 && lastMillis < 60L * 1000){ //half a minute for left turn
       myservo.write(0);
       myservo1.write(0);
      }else if(lastMillis >= 60L * 1000 && lastMillis < 90L * 1000){//half a minute for right turn
        myservo.write(180);
        myservo1.write(180); 
      }else if(lastMillis >= 90L * 1000){ //after 1 min stop
        myservo.write(90);
        myservo1.write(90);
      }
      delay(1000);               // for 1000ms
      Serial.write("test");
    }
  }
} 

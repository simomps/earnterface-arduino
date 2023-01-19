#include <Wire.h>
#include "rgb_lcd.h"
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
Servo myservo1;

String incomingByte;   // for incoming serial data

int myState = 0;

const long time1 = 2000; // 20 sec
const long time2 = 2000; // 40 sec
const long time3 = 2000; // 40 sec

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
    }
    if (incomingByte == "ACTION_2") {
      // DO SOME ACTION HERE
    }
    if (myState == 1) {
      Serial.write("test");
      //change cycle based on timer
      myservo.write(0);
      myservo1.write(0);
      delay(time1);

      myservo.write(90);
      myservo1.write(90);
      delay(time2);

      myservo.write(180);
      myservo1.write(180);
      delay(time3);

      myservo.write(90);
      myservo1.write(90);

    }
  }
}

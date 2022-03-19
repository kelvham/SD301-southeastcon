/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.
 
 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/
 
#include <Servo.h>
 
Servo hand;  // create servo object to control a servo
Servo elbow;  // create servo object to control a servo
Servo shoulder;  // create servo object to control a servo
// twelve servo objects can be created on most boards
 
int HAND_CLOSE = 70;
int HAND_OPEN = 180;

int ELBOW_CLOSE = 180;
int ELBOW_OPEN = 30;

int SHOULDER_CLOSE = 180;
int SHOULDER_OPEN = 90;

int HAND_HALFOPEN = (HAND_CLOSE+HAND_OPEN)/2;

int ELBOW_HALFOPEN = (ELBOW_CLOSE+ELBOW_OPEN)/2;

int SHOULDER_HALFOPEN = (SHOULDER_CLOSE+SHOULDER_OPEN)/2;
 
void setup() {
  hand.attach(9);  // attaches the servo on pin 9 to the servo object
  elbow.attach(10);  // attaches the servo on pin 9 to the servo object
  shoulder.attach(11);  // attaches the servo on pin 9 to the servo object
}
 
void loop() {
  hand.write(HAND_CLOSE);
  elbow.write(ELBOW_CLOSE);
  shoulder.write(SHOULDER_CLOSE);

  delay(10000);

  shoulder.write(130);

  delay(1000);

  elbow.write(ELBOW_OPEN);

  delay(1000);
  
  shoulder.write(SHOULDER_OPEN);

  delay(1000);

  elbow.write(ELBOW_OPEN);

  delay(1000);

  hand.write(HAND_OPEN);

  delay(500);

  hand.write(HAND_CLOSE);

  delay(1000);
}

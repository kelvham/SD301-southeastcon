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
Servo rotator;
// twelve servo objects can be created on most boards
 
int HAND_CLOSE = 70;
int HAND_OPEN = 180;

int ELBOW_CLOSE = 165;
int ELBOW_OPEN = 0;

int SHOULDER_CLOSE = 180;
int SHOULDER_OPEN = 130;

int HAND_HALFOPEN = (HAND_CLOSE+HAND_OPEN)/2;

int ELBOW_HALFOPEN = (ELBOW_CLOSE+ELBOW_OPEN)/2;

int SHOULDER_HALFOPEN = (SHOULDER_CLOSE+SHOULDER_OPEN)/2;
 
void setup() {
  rotator.attach(8);
  hand.attach(9);  // attaches the servo on pin 9 to the servo object
  elbow.attach(10);  // attaches the servo on pin 9 to the servo object
  shoulder.attach(11);  // attaches the servo on pin 9 to the servo object
}
 
void loop() {
  rotator.write(90);
  hand.write(HAND_CLOSE);
  elbow.write(ELBOW_CLOSE);
  shoulder.write(SHOULDER_CLOSE);
  

  delay(10000);

  elbow.write(ELBOW_OPEN);
  shoulder.write(SHOULDER_OPEN);
  hand.write(HAND_OPEN);

  delay(5000);

  hand.write(HAND_CLOSE);

  delay(5000);

  elbow.write(100); //ELBOW_CLOSE

  delay(500);

  hand.write(HAND_CLOSE);
  shoulder.write(SHOULDER_CLOSE);

  delay(1000);

  rotator.write(145);

  delay(1000);

  shoulder.write(75); //165

  delay(1000);

  hand.write(HAND_HALFOPEN);

  delay(100);
  rotator.write(155);
  delay(100);
  rotator.write(135);
  delay(100);
  rotator.write(155);
  delay(100);
  rotator.write(135);
  delay(100);
  rotator.write(155);
  delay(100);
  rotator.write(135);
  delay(100);
  rotator.write(155);
  delay(100);
  rotator.write(135);
  delay(100);
  rotator.write(155);
  delay(100);
  rotator.write(135);
  delay(100);
  rotator.write(155);
  delay(100);
  rotator.write(135);
  delay(100);
  rotator.write(155);
  delay(100);
  rotator.write(135);
  delay(100);
  rotator.write(155);
  delay(100);
  rotator.write(135);
  delay(100);
  rotator.write(155);
  delay(100);
  rotator.write(135);



  hand.write(HAND_CLOSE);

  
}

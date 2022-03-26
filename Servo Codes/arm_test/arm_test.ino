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
Servo catapult;
// twelve servo objects can be created on most boards

int CATAPULT_DOWN = 170;
int CATAPULT_UP = 40;

int ROTATOR_CLOSE = 180;
int ROTATOR_CATAPULT = 120;
 
int HAND_CLOSE = 0;
int HAND_OPEN = 90;

int ELBOW_CLOSE = 180;
int ELBOW_OPEN = 0;
int ELBOW_CATAPULT = 135;
int ELBOW_TENSION = 150;

int SHOULDER_CLOSE = 180;
int SHOULDER_OPEN = 115;
int SHOULDER_CATAPULT = 115;

int HAND_HALFOPEN = (HAND_CLOSE+HAND_OPEN)/2;

int ELBOW_HALFOPEN = (ELBOW_CLOSE+ELBOW_OPEN)/2;

int SHOULDER_HALFOPEN = (SHOULDER_CLOSE+SHOULDER_OPEN)/2;
 
void setup() {
  rotator.attach(23);
  hand.attach(25);  // attaches the servo on pin 9 to the servo object
  elbow.attach(27);  // attaches the servo on pin 9 to the servo object
  shoulder.attach(29);  // attaches the servo on pin 9 to the servo object
  catapult.attach(31);
}
 
void loop() {
  rotator.write(ROTATOR_CLOSE);
  hand.write(HAND_CLOSE);
  elbow.write(ELBOW_CLOSE);
  shoulder.write(SHOULDER_CLOSE);
  catapult.write(CATAPULT_DOWN);
  

  delay(1000);

  elbow.write(ELBOW_OPEN);
  shoulder.write(SHOULDER_OPEN);
  hand.write(HAND_OPEN);

  delay(5000);

  hand.write(HAND_CLOSE);

  delay(5000);

  elbow.write(ELBOW_CATAPULT); //ELBOW_CLOSE

  delay(500);

  hand.write(HAND_CLOSE);

  delay(500);

  shoulder.write(SHOULDER_CLOSE);

  delay(1000);

  rotator.write(ROTATOR_CATAPULT);

  delay(1000);

  shoulder.write(SHOULDER_CATAPULT); //165

  delay(1000);

  hand.write(HAND_OPEN);

  delay(100);
  rotator.write(ROTATOR_CATAPULT + 10);
  delay(100);
  rotator.write(ROTATOR_CATAPULT - 10);
  delay(100);
  rotator.write(ROTATOR_CATAPULT + 10);
  delay(100);
  rotator.write(ROTATOR_CATAPULT - 10);
  delay(100);
  rotator.write(ROTATOR_CATAPULT + 10);
  delay(100);
  rotator.write(ROTATOR_CATAPULT - 10);
  delay(100);
  rotator.write(ROTATOR_CATAPULT + 10);
  delay(100);
  rotator.write(ROTATOR_CATAPULT - 10);
  delay(100);
  rotator.write(ROTATOR_CATAPULT + 10);
  delay(100);
  rotator.write(ROTATOR_CATAPULT - 10);
  delay(100);
  rotator.write(ROTATOR_CATAPULT + 10);
  delay(100);
  rotator.write(ROTATOR_CATAPULT - 10);
  delay(100);
  rotator.write(ROTATOR_CATAPULT + 10);
  delay(100);
  rotator.write(ROTATOR_CATAPULT - 10);
  delay(100);
  rotator.write(ROTATOR_CATAPULT + 10);
  delay(100);
  rotator.write(ROTATOR_CATAPULT - 10);
  delay(100);
  rotator.write(ROTATOR_CATAPULT + 10);
  delay(100);
  rotator.write(ROTATOR_CATAPULT - 10);


  //elbow.write(ELBOW_CLOSE-30);
  shoulder.write(SHOULDER_CLOSE-30);
  delay(500);
  rotator.write(ROTATOR_CLOSE+30);

  rotator.write(ROTATOR_CLOSE);
  hand.write(HAND_CLOSE);
  elbow.write(ELBOW_CLOSE);
  shoulder.write(SHOULDER_CLOSE);


  delay(5000);
  //****************************************
  //Start launch procedure
  //****************************************
    shoulder.write(SHOULDER_CATAPULT);
    elbow.write(ELBOW_TENSION);
    rotator.write(ROTATOR_CATAPULT);
    hand.write(HAND_CLOSE);
    
    delay(1000);
  
    catapult.write(CATAPULT_UP);
  
    delay(3000);
  
    rotator.write(ROTATOR_CLOSE);
    hand.write(HAND_CLOSE);
    elbow.write(ELBOW_CLOSE);
    shoulder.write(SHOULDER_CLOSE);
  
    delay(5000);
  
    catapult.write(CATAPULT_DOWN);
  while(1);

  
}

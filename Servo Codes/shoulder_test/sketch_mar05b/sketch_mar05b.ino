#include <Servo.h>
 
Servo shoulder;  // create servo object to control a servo
Servo elbow;
Servo rotator;
Servo hand;
Servo catapult;

void setup() {
  rotator.attach(8);
//  hand.attach(9);  // attaches the servo on pin 9 to the servo object
  elbow.attach(10);  // attaches the servo on pin 9 to the servo object
  shoulder.attach(11);  // attaches the servo on pin 9 to the servo object
//  catapult.attach(12);
}

void loop() {
  // put your main code here, to run repeatedly:
//  rotator.write(120);
//  hand.write(90);
  shoulder.write(115);
//  elbow.write(135);
  rotator.write(120);
  elbow.write(150);

}

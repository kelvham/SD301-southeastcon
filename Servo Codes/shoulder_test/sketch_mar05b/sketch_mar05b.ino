#include <Servo.h>
 
Servo shoulder;  // create servo object to control a servo
Servo elbow;
Servo rotator;

void setup() {
  // put your setup code here, to run once:
  //shoulder.attach(11);  // attaches the servo on pin 9 to theservo object 
  // elbow.attach(10);
  //rotator.attach(8);
}

void loop() {
  // put your main code here, to run repeatedly:
  shoulder.write(165);

}

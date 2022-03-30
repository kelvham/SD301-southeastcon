//top board code

/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.
 
 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/
 
#include <Servo.h>
#include <Pixy2.h>

Pixy2 pixy; 
Servo hand;  // create servo object to control a servo
Servo elbow;  // create servo object to control a servo
Servo shoulder;  // create servo object to control a servo
Servo rotator;
Servo catapult;
// twelve servo objects can be created on most boards

int CATAPULT_DOWN = 170;
int CATAPULT_UP = 40;

int ROTATOR_CLOSE = 180;
int ROTATOR_CATAPULT = 100;
 
int HAND_CLOSE = 0;
int HAND_OPEN = 90;

int ELBOW_CLOSE = 180;
int ELBOW_OPEN = 0;
int ELBOW_CATAPULT = 150;
int ELBOW_TENSION = 150;

int SHOULDER_CLOSE = 180;
int SHOULDER_OPEN = 110;
int SHOULDER_CATAPULT = 125;

int HAND_HALFOPEN = (HAND_CLOSE+HAND_OPEN)/2;

int ELBOW_HALFOPEN = (ELBOW_CLOSE+ELBOW_OPEN)/2;

int SHOULDER_HALFOPEN = (SHOULDER_CLOSE+SHOULDER_OPEN)/2;
 
void setup() {
//  rotator.attach(23);
//  hand.attach(25);  // attaches the servo on pin 9 to the servo object
//  elbow.attach(27);  // attaches the servo on pin 9 to the servo object
//  shoulder.attach(29);  // attaches the servo on pin 9 to the servo object
//  catapult.attach(31);
  rotator.write(ROTATOR_CLOSE);
  hand.write(HAND_CLOSE);
  elbow.write(ELBOW_CLOSE);
  shoulder.write(SHOULDER_CLOSE);
  catapult.write(CATAPULT_DOWN);
  Serial.begin(9600);
  pixy.init();
  pinMode(33, OUTPUT); //output to bottom board
  //pinMode(35, INPUT); //input from bottom board
  pinMode(37, INPUT); //input from bottom board
  pinMode(39, INPUT); //input from bottom board
}
 
void loop() 
{
  rotator.detach();
  hand.detach();  // attaches the servo on pin 9 to the servo object
  elbow.detach();  // attaches the servo on pin 9 to the servo object
  shoulder.detach();  // attaches the servo on pin 9 to the servo object
  //catapult.detach();
  if (digitalRead(37) == 1) //launch input
  {
    pixy.ccc.getBlocks();
    if (pixy.ccc.numBlocks)
    {
        rotator.attach(23);
  hand.attach(25);  // attaches the servo on pin 9 to the servo object
  elbow.attach(27);  // attaches the servo on pin 9 to the servo object
  shoulder.attach(29);  // attaches the servo on pin 9 to the servo object
  catapult.attach(31);
      digitalWrite(33, HIGH);
      launch();
      digitalWrite(33, LOW);
    }
  }
  else if (digitalRead(39) == 0) //collect input
  {
      rotator.attach(23);
  hand.attach(25);  // attaches the servo on pin 9 to the servo object
  elbow.attach(27);  // attaches the servo on pin 9 to the servo object
  shoulder.attach(29);  // attaches the servo on pin 9 to the servo object
  catapult.attach(31);
    digitalWrite(33, HIGH);
    collect();
    digitalWrite(33, LOW);
  }
//  else
//  {
//    rotator.write(ROTATOR_CLOSE);
//    hand.write(HAND_CLOSE);
//    elbow.write(ELBOW_CLOSE);
//    shoulder.write(SHOULDER_CLOSE);
//    catapult.write(CATAPULT_DOWN);
//  }
}

void collect(void)
{
  //**************************
  //Start Bead Grab Procedure
  //**************************

  delay(1000);

  elbow.write(ELBOW_OPEN);
  shoulder.write(SHOULDER_OPEN);
  hand.write(HAND_OPEN);

  delay(2000);

  rotator.write(ROTATOR_CLOSE);
  
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

  delay(3000);
//  rotator.write(ROTATOR_CATAPULT + 10);
//  delay(100);
//  rotator.write(ROTATOR_CATAPULT - 10);
//  delay(100);
//  rotator.write(ROTATOR_CATAPULT + 10);
//  delay(100);
//  rotator.write(ROTATOR_CATAPULT - 10);
//  delay(100);
//  rotator.write(ROTATOR_CATAPULT + 10);
//  delay(100);
//  rotator.write(ROTATOR_CATAPULT - 10);
//  delay(100);
//  rotator.write(ROTATOR_CATAPULT + 10);
//  delay(100);
//  rotator.write(ROTATOR_CATAPULT - 10);
//  delay(100);
//  rotator.write(ROTATOR_CATAPULT + 10);
//  delay(100);
//  rotator.write(ROTATOR_CATAPULT - 10);
//  delay(100);
//  rotator.write(ROTATOR_CATAPULT + 10);
//  delay(100);
//  rotator.write(ROTATOR_CATAPULT - 10);
//  delay(100);
//  rotator.write(ROTATOR_CATAPULT + 10);
//  delay(100);
//  rotator.write(ROTATOR_CATAPULT - 10);
//  delay(100);
//  rotator.write(ROTATOR_CATAPULT + 10);
//  delay(100);
//  rotator.write(ROTATOR_CATAPULT - 10);
//  delay(100);
//  rotator.write(ROTATOR_CATAPULT + 10);
//  delay(100);
//  rotator.write(ROTATOR_CATAPULT - 10);


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
  //End Bead Grab Procedure
  //****************************************
}

void launch(void)
{
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

  //****************************************
  //End launch procedure
  //****************************************
}

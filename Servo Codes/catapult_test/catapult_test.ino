//FAMU-FSU College of Engineering
//ECE
//Senior Design 301
//IEEE Southeast Con Hardware Competition
//Code Author:
//Kelvin Hamilton

//top board code
 
#include <Servo.h>
#include <Pixy2.h>

Pixy2 pixy; 
Servo hand;
Servo elbow;
Servo shoulder;
Servo rotator;
Servo catapult;

int CATAPULT_DOWN = 170; //catapult rest position
int CATAPULT_UP = 40; ///catapult launch position

int ROTATOR_CLOSE = 180; //arm rotator rest position
int ROTATOR_CATAPULT = 135; //arm rotator catapult position (dump beads and tension catapult)
 
int HAND_CLOSE = 0; //hand close position
int HAND_OPEN = 90; //hand open position

int ELBOW_CLOSE = 180; //elbow rest position
int ELBOW_OPEN = 0; //elbow open (all the way to 0 to not strain motors)
int ELBOW_CATAPULT = 150; //elbow catapult position
int ELBOW_TENSION = 130; //elbow tensioner position

int SHOULDER_CLOSE = 180; //shoulder rest position
int SHOULDER_OPEN = 110; //shoulder open position (to grab beads)
int SHOULDER_CATAPULT = 125; //sboulder catapult position (to dump beads and tension catapult)

int HAND_HALFOPEN = (HAND_CLOSE+HAND_OPEN)/2; //hand half open (used to not send so much current at once)
int ELBOW_HALFOPEN = (ELBOW_CLOSE+ELBOW_OPEN)/2; //elbow half open (used to not send so much current at once)
int SHOULDER_HALFOPEN = (SHOULDER_CLOSE+SHOULDER_OPEN)/2; //shoulder half open (used to not send so much current at once)
 
void setup() {
  //set all servos to close position
  rotator.write(ROTATOR_CLOSE);
  hand.write(HAND_CLOSE);
  elbow.write(ELBOW_CLOSE);
  shoulder.write(SHOULDER_CLOSE);
  catapult.write(CATAPULT_DOWN);
  
  //use baud rate of 9600
  Serial.begin(9600);

  //initialize pixycam
  pixy.init();

  //initialize I/O pins to other board for communication
  pinMode(33, OUTPUT); //output to bottom board
  pinMode(37, INPUT); //input from bottom board
  pinMode(39, INPUT); //input from bottom board
}
 
void loop() 
{
  //detach all servos to conserve power
  //catapult.detach(); //this was breaking the program
  //attach all servos
  rotator.attach(23);
  catapult.attach(31);
  launch(); //collect beads from trees
  while(1);
}

void launch(void)
{
  //****************************************
  //Start launch procedure
  //****************************************
  rotator.write(ROTATOR_CATAPULT);
     
  delay(1000);

  rotator.detach();

  delay(500);
  
  catapult.write(CATAPULT_UP);
  
  delay(3000);

  rotator.attach(23);

  delay(500);

  //return arm to closed position
  rotator.write(ROTATOR_CLOSE);
  hand.write(HAND_CLOSE);
  elbow.write(ELBOW_CLOSE);
  shoulder.write(SHOULDER_CLOSE);
  
  delay(5000);

  //return catapult to closed position
  catapult.write(CATAPULT_DOWN);

  //****************************************
  //End launch procedure
  //****************************************
}

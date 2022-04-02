//FAMU-FSU College of Engineering
//ECE
//Senior Design 301
//IEEE Southeast Con Hardware Competition
//Code Authors:
//Kelvin Hamilton
//Raymond Martinez

//bottom board code

#include "Drivetrain.h"
#include "LineTrack.h"

void setup()
{
  set_up_timer();
  track_setup();
  motor_init();
  encoder_init();
  pinMode(33, INPUT); //input from top board
  pinMode(37, OUTPUT); //output to top board
  pinMode(39, OUTPUT); //output to top board
  digitalWrite(37, LOW);
  digitalWrite(39, LOW);
  Serial.begin(9600);
}

void loop(void) 
{
  interrupts();
  digitalWrite(37, LOW);
  digitalWrite(39, LOW);
  while(digitalRead(33) == 1) //stop condition from top
  {
    noInterrupts();
    get_current_status();
    des_pos[0] = cur_pos[0];//leftmotor position
    des_pos[1] = cur_pos[1];//rightmotor position
    des_vel[0] = 0;
    des_vel[1] = 0;
    low_level_control();//pid controller
  }
  interrupts();
  track();//line follower sensors
  get_current_status();

  if (current_position > 24)
  {
      des_vel[0] = 0;//leftmotor speed
      des_vel[1] = 0;//rightmotor speed
      low_level_control();//pid controller
      return;
  }
  else
  {
    des_vel[0] = command1/14;//leftmotor speed
    des_vel[1] = command2/14;//rightmotor speed
    low_level_control();//pid controller 
  }
  Serial.println(current_position);
}

ISR(TIMER1_COMPA_vect)//interrupt timer that is activated ever 10ms //should be timer 1
{
  loop();
}

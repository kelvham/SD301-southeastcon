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
  Serial.begin(9600);
}

void loop(void) 
{
  while(1);
  interrupts();
  while(digitalRead(33) == 1)
  {
    noInterrupts();
    des_vel[0] = 0;//leftmotor speed
    des_vel[1] = 0;//rightmotor speed
    low_level_control();//pid controller
  }
  track();//line follower sensors
  get_current_status();

  if (current_position > 15.5)
  {
      des_vel[0] = 0;//leftmotor speed
      des_vel[1] = 0;//rightmotor speed
      low_level_control();//pid controller
      return;
  }

  des_vel[0] = command1/14;//leftmotor speed
  des_vel[1] = command2/14;//rightmotor speed
  low_level_control();//pid controller 
}

ISR(TIMER1_COMPA_vect)//interrupt timer that is activated ever 10ms //should be timer 1
{
  loop();
}

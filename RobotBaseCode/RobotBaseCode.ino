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
  while(digitalRead(33) == 0) //stop condition from top
  {
    noInterrupts();
    get_current_status();
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
  else
  {
    des_vel[0] = command1/14;//leftmotor speed
    des_vel[1] = command2/14;//rightmotor speed
    low_level_control();//pid controller 
  }
}

ISR(TIMER1_COMPA_vect)//interrupt timer that is activated ever 10ms //should be timer 1
{
  loop();
}

#include "Drivetrain.h"
//#include "RaspCommands.h"
#include "LineTrack.h"

void setup()
{
  set_up_timer();
  //read_setup();
  track_setup();
  motor_init();
  encoder_init();
  Serial.begin(9600);
}

void loop(void) 
{
  //sense();//ir senseor for object detectiom
  track();//line follower sensors
  get_current_status();
  
  des_vel[0] = command1/14;//leftmotor speed
  des_vel[1] = command2/14;//rightmotor speed

  low_level_control();//pid controller

  if (cur_pos[1] == 11.26)
  {
    des_vel[0] = 1/14;//leftmotor speed
    des_vel[1] = -1/14;//rightmotor speed
    delay(500);
    des_vel[0] = 0;//leftmotor speed
    des_vel[1] = 0;//rightmotor speed
  }
  
  //Serial.print(encoder0_val);
  //Serial.print(" ");
  //Serial.println(encoder1_val);
}

ISR(TIMER1_COMPA_vect)//interrupt timer that is activated ever 10ms
{
  loop();
}

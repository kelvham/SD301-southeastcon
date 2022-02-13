#include "RobotBaseCode.h"
#include "IRSense.h"
#include "LineTrack.h"

void setup()
{
  set_up_timer();
  sense_setup();
  track_setup();
  motor_init();
  encoder_init();
  Serial.begin(9600);
}

void loop(void) 
{
  sense();//ir senseor for object detectiom
  track();//line follower sensors
  get_current_status();
  
  des_vel[0] = command1/14;//leftmotr speed
  des_vel[1] = command2/14;//rightmotr speed

  low_level_control();//pid controller
}

ISR(TIMER1_COMPA_vect)//interrupt timer that is activated ever 10ms
{
  loop();
}

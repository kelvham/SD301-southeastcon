#include "Drivetrain.h"
#include "LineTrack.h"
#include "BeadCollectLaunch.h"

void setup()
{
  set_up_timer();
  //read_setup();
  track_setup();
  motor_init();
  encoder_init();
  armcat_init();
  Serial.begin(9600);
}

void loop(void) 
{
  //sense();//ir senseor for object detectiom
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
  
  //Serial.print(encoder0_val);
  //Serial.print(" ");
  //Serial.println(encoder1_val);
}

ISR(TIMER1_COMPA_vect)//interrupt timer that is activated ever 10ms
{
  loop();
}

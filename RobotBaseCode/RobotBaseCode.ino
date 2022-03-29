#include "Drivetrain.h"
//#include "PixyCam.h"
#include "LineTrack.h"
#include <Pixy2.h>

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
  
  //Serial.print(encoder0_val);
  //Serial.print(" ");
  //Serial.println(encoder1_val);
}

ISR(TIMER1_COMPA_vect)//interrupt timer that is activated ever 10ms
{
  loop();
}

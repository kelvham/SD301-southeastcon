#include "RobotBaseCode.h"
#include "LineTrack.h"

void setup()
{
  //set_up_timer();
  track_set();
  motor_init();
  encoder_init();
  Serial.begin(9600);
}

void loop(void) 
{
  //motor_speed(0, 155);
  //motor_speed(1, 155);

  track();
  get_current_status();
  
  des_vel[0] = command * 1.1;
  des_vel[1] = command * 1.0;

  low_level_control();

  Serial.println(des_vel[1]);
}

ISR(TIMER1_COMPA_vect)
{
  loop();
}

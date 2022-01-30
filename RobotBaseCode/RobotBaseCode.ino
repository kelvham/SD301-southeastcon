#include "RobotBaseCode.h"
#include "IRSense.h"
//#include "LineTrack.h"

void setup()
{
  //set_up_timer();
  sense_setup();
  //track_setup();
  motor_init();
  encoder_init();
  Serial.begin(9600);
}

void loop(void) 
{
  //motor_speed(0, 155);
  //motor_speed(1, 155);

  sense();
  get_current_status();
  
  des_vel[0] = command;
  des_vel[1] = command2;

  low_level_control();

  Serial.println(digitalRead(22));
}

ISR(TIMER1_COMPA_vect)
{
  loop();
}

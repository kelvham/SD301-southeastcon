void sense(void); //Speed control
void sense_setup(void); //pin set up

Pixy2 pixy;

void read_setup(void)
{
  pixy.init();
}

void sense(void)
{
  while(Seria.available() > 0)
  {
   
  }
}

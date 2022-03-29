void sense(void); //Speed control
void sense_setup(void); //pin set up

Pixy2 pixy;

void read_setup(void)
{
  const int Command_Length = 12;
  static char RasComm[Command_Length];
  static unsigned int Command_Pos = 0;
}

void sense(void)
{
  while(Seria.available() > 0)
  {
   
  }
}

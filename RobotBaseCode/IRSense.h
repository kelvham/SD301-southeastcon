void sense(void); //Speed control
void sense_setup(void); //pin set up

void sense_setup(void)
{
pinMode(22, INPUT);
}

void sense(void)
{
  if(digitalRead(22) == 0)
  {
   // command1 = 7;
    //command2 = 7;
  }
    else if (digitalRead(22) == 1)
    {
    //  command1 = 0;
    //  command2 = 0;
    }
}

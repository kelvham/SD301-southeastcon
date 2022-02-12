void sense(void); //Speed control
void sense_setup(void); //pin set up

void sense_setup(void)
{
pinMode(22, INPUT);
}

int obs=0;//flag for obstacle detection

void sense(void)
{
  if(digitalRead(22) == 1)//if obstacle detected
  {
   obs = 1;
  }
  else
  {
    obs = 0;
  }
   /* else if (digitalRead(22) == 1)
    {
    //  command1 = 0;
    //  command2 = 0;
    }*/
}

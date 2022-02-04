void sense(void); //Speed control
void sense_setup(void); //pin set up

float command = 0;
float command2 = 0;

void sense_setup(void)
{
pinMode(22, INPUT);
}

void sense(void)
{
  if(digitalRead(22) == 0)
  {
    command = 15*(1.2);
    command2 = 15;
  }
    else if (digitalRead(22) == 1)
    {
      command = 0;
      command2 = 0;
    }
}

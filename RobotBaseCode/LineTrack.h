void track(void); //Speed control
void track_setup(void); //pin set up

float command = 0;

void track_setup(void)
{
pinMode(25, INPUT);
pinMode(26, INPUT);
pinMode(27, INPUT);
pinMode(28, INPUT);
pinMode(29, INPUT);
}

void track(void)
{
  if((digitalRead(26) == 1) && (digitalRead(27) == 1) && (digitalRead(28) == 1))
  {
    command1 = 3.5;
    command2 = 3.5;
  }
    else if((digitalRead(25) == 1) && (digitalRead(26) == 1) && (digitalRead(27) == 1))
    {
      command1 = 3.5;
      command2 = 3.0;
    }
      else if (digitalRead(22) == 1)
      {
        command = 0;
      }
}

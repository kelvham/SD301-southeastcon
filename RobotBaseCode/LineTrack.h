void track(void); //Speed control
void track_set(void); //pin set up

float command = 0;

void track_set(void)
{
pinMode(22, INPUT);
}

void track(void)
{
  if(digitalRead(22) == 0)
    command = 2.0;
    else if (digitalRead(22) == 1)
      command = 0;
}

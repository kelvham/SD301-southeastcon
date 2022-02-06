void track(void); //Speed control
void track_setup(void); //pin set up

float command1 = 0;
float command2 = 0;

void track_setup(void)
{
pinMode(A1, INPUT);
pinMode(A2, INPUT);
pinMode(A3, INPUT);
pinMode(A4, INPUT);
pinMode(A5, INPUT);
}

void track(void)
{
  //Serial.print(A1);
  //Serial.print(A2);
  //Serial.print(A3);
  //Serial.print(A4);
  Serial.println(analogRead(A3));
  
  if((analogRead(A2) > 100) && (analogRead(A3) > 100) && (analogRead(A4) > 100))
  {
    command1 = 7;
    command2 = 7;
  }
    else if((analogRead(A1) > 100) && (analogRead(A2) > 100) && (analogRead(A3) > 100))
    {
      command1 = 0;
      command2 = 7;
    }
      else if((analogRead(A3) > 100) && (analogRead(A4) > 100) && (analogRead(A5) > 100))
      {
        command1 = 7;
        command2 = 0;
      }
        else
        {
          command1 = 0;
          command2 = 0;
        }
}

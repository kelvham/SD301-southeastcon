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
  Serial.println(analogRead(A5));
  int x = 300;
  int prevCom = 0;
  
  if(analogRead(A3) < x)
  {
    command1 = 8;
    command2 = 8;
  }
    else if((analogRead(A1)< x) || (analogRead(A2) < x))//left
    {
      if((analogRead(A1)< x))
      {
        command1 = 7;//lefmotr
        command2 = 9;//righmotr
      }
      else
      {
        command1 = 6;
        command2 = 8;
      }
      prevCom = 1;
    }
      else if((analogRead(A4) < x) || (analogRead(A5) < x))//right
      {
        if((analogRead(A5)< x))
        {
        command1 = 9;
        command2 = 7;
        }
        else
        {
          command1 = 8;
          command2 = 6;
        }
        prevCom = 5;
      }
        else
        {
          if(prevCom == 5)
          {
          command1 = 16;
          command2 = 8;
          }
          else if (prevCom == 1)
          {
            command1 = 8;
            command2 = 16;
          }
        }
}

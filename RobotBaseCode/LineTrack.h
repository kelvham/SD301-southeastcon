void track(void); //Speed control
void track_setup(void); //pin set up

float command1 = 0;//lefmotr speed
float command2 = 0;//rightmotr speed

void track_setup(void) //enabling line tracker sensors
{
pinMode(A1, INPUT);
pinMode(A2, INPUT);
pinMode(A3, INPUT);
pinMode(A4, INPUT);
pinMode(A5, INPUT);
}

void track(void)
{
  //Serial.println(analogRead(A1));
  //Serial.println(analogRead(A2));
  //Serial.println(analogRead(A3));
  //Serial.println(analogRead(A4));
  //Serial.println(analogRead(A3));
  int x = 0;

  if(analogRead(A3) > x)
  {
    command1 = 5;//lefmotr speed
    command2 = 5;//righmotr speed
  }
    else if((analogRead(A1)< x) || (analogRead(A2) < x))//left
    {
      command1 = -1;//lefmotr speed
      command2 = 1;//righmotr speed
    }
      else if((analogRead(A4) < x) || (analogRead(A5) < x))//right
      {
        command1 = 1;//lefmotr speed
        command2 = -1;//righmotr speed
      }
        else
        {
          command1 = 0;//lefmotr speed
          command2 = 0;//righmotr speed      
        }
}

void track(void); //Speed control
void track_setup(void); //pin set up

float command1 = 0;//lefmotr speed rev/s
float command2 = 0;//rightmotr speed rev/s

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
  Serial.print(analogRead(A1));
  Serial.print(" ");
  Serial.print(analogRead(A2));
  Serial.print(" ");
  Serial.print(analogRead(A3));
  Serial.print(" ");
  Serial.print(analogRead(A4));
  Serial.print(" ");
  Serial.println(analogRead(A5));
  int x = 600;

  if(analogRead(A1) > x && analogRead(A2) > x && analogRead(A3) > x && analogRead(A4) > x && analogRead(A5) > x)
  {
      command1 = 0;//lefmotr speed
      command2 = 0;//righmotr speed
  }  

  if(analogRead(A3) < x)
  {
      command1 = 1;//lefmotr speed
      command2 = 1;//righmotr speed
  }
    else if((analogRead(A1)< x) || (analogRead(A2) < x))//left
    {
      command1 = 1;//lefmotr speed
      command2 = -1;//righmotr speed
    }
      else if((analogRead(A4) < x) || (analogRead(A5) < x))//right
      {
        command1 = -1;//lefmotr speed
        command2 = 1;//righmotr speed
      }
        else
        {
          command1 = 0;//lefmotr speed
          command2 = 0;//righmotr speed      
        }
}

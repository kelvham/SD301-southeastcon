void track(void); //Speed control
void track_setup(void); //pin set up
void active_braking(void);

float command1 = 0;//rightmotr speed rev/s
float command2 = 0;//leftmotr speed rev/s
int Brake = 0;

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
  Serial.print(analogRead(A1)); //rightmost
  Serial.print(" ");
  Serial.print(analogRead(A2));
  Serial.print(" ");
  Serial.print(analogRead(A3));
  Serial.print(" ");
  Serial.print(analogRead(A4));
  Serial.print(" ");
  Serial.println(analogRead(A5)); //leftmost
  int x = 850;

  /*if(analogRead(A1) > x && analogRead(A2) > x && analogRead(A3) > x && analogRead(A4) > x && analogRead(A5) > x)
  {
      command1 = 0;//rightmotr speed
      command2 = 0;//righttmotr speed
  }  */

  if(analogRead(A3) < x)
  {
      command1 = 1;//rightmotr speed
      command2 = 1;//lefthmotr speed
  }
    else if((analogRead(A1)< x) || (analogRead(A2) < x))//left
    {
      command1 = -1;//rightmotr speed
      command2 = 1;//leftmotr speed
    }
      else if((analogRead(A4) < x) || (analogRead(A5) < x))//right
      {
          command1 = 1;//rightmotr speed
          command2 = -1;//leftmotr speed
      }                                                                                        
        else
        {
          command1 = -1;//rightmotr speed
          command2 = -1;//leftmotr speed      
        }
}

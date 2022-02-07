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
  int x = 600;
  //int prevCom = 0;

 /* if((obs == 1) && ((analogRead(A1) > x ) || (analogRead(A2) > x ) || (analogRead(A3) > x )  || (analogRead(A4) > x ) || (analogRead(A5) > x )))
  {
    command1 = 17;
    command2 = -10;
  }
  else*/ if(analogRead(A3) < x)
  {
    command1 = 7;
    command2 = 7;
  }
   /* else if((analogRead(A1)< x) && (analogRead(A2) < x))//left
    {
      command1 = -7;//lefmotr
      command2 = 7;//righmotr
      //prevCom = 1;
    }
      else if((analogRead(A4) < x) && (analogRead(A5) < x))//right
      {
        command1 = 7;//lefmotr
        command2 = -7;//righmotr
        //prevCom = 5;
      }*/
        else if((analogRead(A1)< x) || (analogRead(A2) < x))//left
        {
          command1 = -9;//lefmotr
          command2 = 8.5;//righmotr
          //prevCom = 1;
        }
          else if((analogRead(A4) < x) || (analogRead(A5) < x))//right
          {
            command1 = 8.5;//lefmotr
            command2 = -9;//righmotr
            //prevCom = 5;
          }
            else
            {
              command1 = 0;
              command2 = 0;          
              /*if(prevCom == 5)
              {
              command1 = 16;
              command2 = 8;
              }
              else if (prevCom == 1)
              {
                command1 = 8;
                command2 = 16;
              }*/
            }
}

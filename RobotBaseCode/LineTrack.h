void track(void); //Speed control
void track_setup(void); //pin set up
void active_braking(void);

float command1 = 0;//leftmotr speed rev/s
float command2 = 0;//rightmotr speed rev/s
int Brake = 0;
int Out_R;
int R;
int Mid_R;
int Mid;
int Mid_L;
int L;
int Out_L;
float wr;
float LookAhead_Dis[3] = {0.1513, 0.1552, 0.1616}; //[outside L/R sens, L/R sens] in meters
float LookAhead_Ycomp = 0.15; //[outside L/R sens, L/R sens] in meters
float WheelDis = 0.215; //in meters
float wheelRad = 0.0575; //in meters
int x = 200;
int n = 0;
int v = 1.5;

void track_setup(void) //enabling line tracker sensors
{
pinMode(A2, INPUT); //out right
pinMode(A3, INPUT); //right
pinMode(A1, INPUT); //right middle
pinMode(A4, INPUT); //middle
pinMode(A7, INPUT); //left middle
pinMode(A5, INPUT); //left
pinMode(A6, INPUT); //out left
}

void track(void)
{
  Out_L = analogRead(A7);
  L = analogRead(A6);
  Mid_L = analogRead(A5);
  Mid = analogRead(A4);
  Mid_R = analogRead(A3);
  R = analogRead(A2);
  Out_R = analogRead(A1);
  /*
  Serial.print(Out_L);
  Serial.print(" ");
  Serial.print(L);
  Serial.print(" ");
  Serial.print(Mid_L);
  Serial.print(" ");
  Serial.print(Mid);
  Serial.print(" ");
  Serial.print(Mid_R);
  Serial.print(" ");
  Serial.print(R);
  Serial.print(" ");
  Serial.println(Out_R);*/

  if((Out_R > x) || (Out_L > x))
    {
      if(Out_L > x)
      { 
        wr = (2*(2*PI*v*wheelRad)*LookAhead_Ycomp)/pow(LookAhead_Dis[2],2);
        command1 = -1*((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = ((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        n = 6;
      }
      else
      {
        wr = -1*(2*(2*PI*v*wheelRad)*LookAhead_Ycomp)/pow(LookAhead_Dis[2],2);
        command1 = ((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = -1*((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        n = 5;
      }
    }
  else if ((L > x) || (R > x))
    {
      if(L > x)
      { 
        wr = (2*(2*PI*v*wheelRad)*LookAhead_Ycomp)/pow(LookAhead_Dis[1],2);
        command1 = -1*((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = ((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        n = 4;
      }
      else
      {
        wr = -1*(2*(2*PI*v*wheelRad)*LookAhead_Ycomp)/pow(LookAhead_Dis[1],2);
        command1 = ((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = -1*((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        n = 3;
      }
    }
    else if ((Mid_L > x) || (Mid_R > x))
    {
      if(Mid_L > x)
      { 
        //wr = (2*(2*PI*v*wheelRad)*LookAhead_Ycomp)/pow(LookAhead_Dis[0],2);
        command1 = v;//-1*((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = v*1.1;//((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        n = 2;
      }
      else
      {
        //wr = -1*(2*(2*PI*v*wheelRad)*LookAhead_Ycomp)/pow(LookAhead_Dis[0],2);
        command1 = v*1.1;//((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = v;//-1*((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        n = 1;
      }
    }                                                                                   
  else if(Mid > x)
  {
    if(n == 2)
    {
      command1 = v*1.2;
      command2 = v;
    }
    else if (n == 1)
    {
      command1 = v;
      command2 = v*1.2;
    }
    else
    {
    command1 = v;
    command2 = v;
    }
    n = 0;
  }
    else
    {
      switch (n)
      {
      case 0: 
        command1 = v;
        command2 = v;
        break;
      case 1: 
        //wr = -1*(2*(2*PI*v*wheelRad)*LookAhead_Ycomp)/pow(LookAhead_Dis[0],2);
        command1 = v*1.1;//((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = v;//-1*((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        break;
      case 2:
        //wr = (2*(2*PI*v*wheelRad)*LookAhead_Ycomp)/pow(LookAhead_Dis[0],2);
        command1 = v;//-1*((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = v*1.1;//((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        break;
      case 3:
        wr = -1*(2*(2*PI*v*wheelRad)*LookAhead_Ycomp)/pow(LookAhead_Dis[1],2);
        command1 = ((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = -1*((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        break;
      case 4:
        wr = (2*(2*PI*v*wheelRad)*LookAhead_Ycomp)/pow(LookAhead_Dis[1],2);
        command1 = -1*((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = ((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        break;
      case 5:
        wr = -1*(2*(2*PI*v*wheelRad)*LookAhead_Ycomp)/pow(LookAhead_Dis[2],2);
        command1 = ((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = -1*((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        break;
      case 6:
        wr = (2*(2*PI*v*wheelRad)*LookAhead_Ycomp)/pow(LookAhead_Dis[2],2);
        command1 = -1*((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = ((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        break;
      default:
        command1 = -0.75;//rightmotr speed
        command2 = -0.75;//lefthmotr speed
      }
    }
/*
  if(Mid > x)
  {
    command1 = v*1.1;
    command2 = v;
    n = 0;
  }
  else if ((L > x) || (R > x))
    {
      if(L > x)
      { 
        wr = (2*(2*PI*v*wheelRad)*LookAhead_Ycomp[1])/pow(LookAhead_Dis[1],2);
        command1 = -1*((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = ((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        n = 1;
      }
      else
      {
        wr = -1*(2*(2*PI*v*wheelRad)*LookAhead_Ycomp[1])/pow(LookAhead_Dis[1],2);
        command1 = ((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = -1*((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        n = 2;
      }
    }                                                                                   
    else if((Out_R > x) || (Out_L > x))
    {
      if(Out_L > x)
      { 
        wr = (2*(2*PI*v*wheelRad)*LookAhead_Ycomp[0])/pow(LookAhead_Dis[0],2);
        command1 = -1*((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = ((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        n = 3;
      }
      else
      {
        wr = -1*(2*(2*PI*v*wheelRad)*LookAhead_Ycomp[0])/pow(LookAhead_Dis[0],2);
        command1 = ((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = -1*((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        n = 4;
      }
    }
   else
    {
      switch (n)
      {
      case 1: 
        wr = (2*(2*PI*v*wheelRad)*LookAhead_Ycomp[1])/pow(LookAhead_Dis[1],2);
        command1 = -1*((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = ((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        break;
      case 2:
        wr = -1*(2*(2*PI*v*wheelRad)*LookAhead_Ycomp[1])/pow(LookAhead_Dis[1],2);
        command1 = ((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = -1*((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        break;
      case 3:
        wr = (2*(2*PI*v*wheelRad)*LookAhead_Ycomp[0])/pow(LookAhead_Dis[0],2);
        command1 = -1*((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = ((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        break;
      case 4:
        wr = -1*(2*(2*PI*v*wheelRad)*LookAhead_Ycomp[0])/pow(LookAhead_Dis[0],2);
        command1 = ((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = -1*((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        break;
      default:
        command1 = -0.75;//rightmotr speed
        command2 = -0.75;//lefthmotr speed
      }
    }*/
  Serial.print(command1);
  Serial.print(" ");
  Serial.println(command2);
}

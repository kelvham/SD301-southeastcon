void track(void); //Speed control
void track_setup(void); //pin set up
void active_braking(void);

float command1 = 0;//rightmotr speed rev/s
float command2 = 0;//leftmotr speed rev/s
int Brake = 0;
<<<<<<< HEAD
int Out_R;
int R;
int Mid_R;
int Mid;
int Mid_L;
int L;
int Out_L;
float wr = 0;
float prev_wr = 0;
float LookAhead_Dis[3] = {0.1513, 0.1552, 0.1616}; //[outside L/R sens, L/R sens] in meters
float LookAhead_Ycomp = 0.15; //[outside L/R sens, L/R sens] in meters
float WheelDis = 0.215; //in meters
float wheelRad = 0.0575; //in meters
int x = 42;
int n = 0;
int v = 1.5;
int index = 0;
int sums[7];
int readings[30][7];
int flag = 1;
=======
>>>>>>> parent of 2199e96 (Line Tacking Update)

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
<<<<<<< HEAD
  //Low Pass Filter for the sensor readings
  int data[] = {analogRead(A7), analogRead(A6), analogRead(A5), analogRead(A4), analogRead(A3), analogRead(A2), analogRead(A1)};

  for(int d = 0; d < 6; d++)
  {
    sums[d] = sums[d] - readings[index][d];
    readings[index][d] = data[d];
    sums[d] = sums[d] + readings[index][d];
    data[d] = sums[d]/30; 
  } 
  index = (index + 1)%30;

  //sensor values
  Out_L = data[0];
  L = data[1];
  Mid_L = data[2];
  Mid = data[3];
  Mid_R = data[4];
  R = data[5];
  Out_R = data[6];
  
  Serial.print(Out_L);
=======
  Serial.print(analogRead(A1)); //rightmost
>>>>>>> parent of 2199e96 (Line Tacking Update)
  Serial.print(" ");
  Serial.print(analogRead(A2));
  Serial.print(" ");
  Serial.print(analogRead(A3));
  Serial.print(" ");
  Serial.print(analogRead(A4));
  Serial.print(" ");
<<<<<<< HEAD
  Serial.print(Mid_R);
  Serial.print(" ");
  Serial.print(R);
  Serial.print(" ");
  Serial.println(Out_R);
  Serial.print(" ");
  Serial.println(cur_pos[1]);

  float current_position = (cur_pos[0] + cur_pos[1])/2;
  if (current_position > 8)
  {
    if (flag == 1)
    {
      command1 = -20;//leftmotor speed
      command2 = 20;//rightmotor speed
      flag++;
    }
    if (flag == 2)
    {
      get_current_status();
      des_vel[0] = (command1*1.10)/14;//leftmotor speed
      des_vel[1] = command2/14;//rightmotor speed
      low_level_control();//pid controller
      flag++;
    }
    if (flag > 2)
    {
      for (flag = 1; flag < 2000; flag++);
      flag = 0;
    }
  }
  else if (current_position > 17)
  {
      des_vel[0] = 0;//leftmotor speed
      des_vel[1] = 0;//rightmotor speed
      low_level_control();//pid controller
      return;
  }
    else if ((Out_L > x) && (L > x) && (Mid_L > x) && (Mid > x) && (Mid_R > x) && (R > x) && (Out_R > x))
    {
      command1 = -1;
      command2 = -1;
      switch (n)
      {
      case 0: 
        break;
        command1 = v;
        command2 = v;
        break;
      case 1: 
        break;
        //wr = -1*(2*(2*PI*v*wheelRad)*LookAhead_Ycomp)/pow(LookAhead_Dis[0],2);
        command1 = v;//*1.1;//((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = v;//-1*((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        break;
      case 2:
        break;
        //wr = (2*(2*PI*v*wheelRad)*LookAhead_Ycomp)/pow(LookAhead_Dis[0],2);
        command1 = v;//-1*((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = v;//*1.1;//((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        break;
      case 3:
        break;
        wr = -1*(2*(2*PI*v*wheelRad)*LookAhead_Ycomp)/pow(LookAhead_Dis[1],2);
        command1 = 2*((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = -.75*((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        break;
      case 4:
        break;
        wr = (2*(2*PI*v*wheelRad)*LookAhead_Ycomp)/pow(LookAhead_Dis[1],2);
        command1 = -.75*((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = 1.25*((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        break;
      case 5:
        break;
        wr = -1*(2*(2*PI*v*wheelRad)*LookAhead_Ycomp)/pow(LookAhead_Dis[2],2);
        command1 = 2*((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = -1*((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        break;
      case 6:
        break;
        wr = (2*(2*PI*v*wheelRad)*LookAhead_Ycomp)/pow(LookAhead_Dis[2],2);
        command1 = -1*((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = 2*((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        break;
      }
    }
  else if(current_position < .25)
  {
     command1 = 5;//*1.10;
     command2 = 5;
  }
  else if(((Out_R < Out_L) && (Out_R < L) && (Out_R < Mid_L) && (Out_R < Mid) && (Out_R < Mid_R) && (Out_R < R))  || 
          ((Out_L < Out_R) && (Out_L < L) && (Out_L < Mid_L) && (Out_L < Mid) && (Out_L < Mid_R) && (Out_L < R)))
    {
      if((Out_L < Out_R) && (Out_L < L) && (Out_L < Mid_L) && (Out_L < Mid) && (Out_L < Mid_R) && (Out_L < R))
      { 
        wr = (2*(2*PI*v*wheelRad)*LookAhead_Ycomp)/pow(LookAhead_Dis[2],2);
        command1 = -1*((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = 2*((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        n = 6;
      }
      else
      {
        wr = -1*(2*(2*PI*v*wheelRad)*LookAhead_Ycomp)/pow(LookAhead_Dis[2],2);
        command1 = 2*((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = -1*((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        n = 5;
      }
    }
  else if (((L < Out_R) && (L < Out_L) && (L < Mid_L) && (L < Mid) && (L < Mid_R) && (L < R)) || 
          ((R < Out_R) && (R < L) && (R < Mid_L) && (R < Mid) && (R < Mid_R) && (R < Out_L)))
    {
      if((L < Out_R) && (L < Out_L) && (L < Mid_L) && (L < Mid) && (L < Mid_R) && (L < R))
      { 
        wr = (2*(2*PI*v*wheelRad)*LookAhead_Ycomp)/pow(LookAhead_Dis[1],2);
        command1 = -.75*((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = 1.5*((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        n = 4;
      }
      else
      {
        wr = -1*(2*(2*PI*v*wheelRad)*LookAhead_Ycomp)/pow(LookAhead_Dis[1],2);
        command1 = 1.5*((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = -.75*((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        n = 3;
      }
    }
    else if (((Mid_L < Out_R) && (Mid_L < Out_L) && (Mid_L < L) && (Mid_L < Mid) && (Mid_L < Mid_R) && (Mid_L < R)) || 
            ((Mid_R < Out_R) && (Mid_R < Out_L) && (Mid_R < Mid_L) && (Mid_R < Mid) && (Mid_R < L) && (Mid_R < R)))
    {
      if((Mid_L < Out_R) && (Mid_L < Out_L) && (Mid_L < L) && (Mid_L < Mid) && (Mid_L < Mid_R) && (Mid_L < R))
      { 
        //wr = (2*(2*PI*v*wheelRad)*LookAhead_Ycomp)/pow(LookAhead_Dis[0],2);
        command1 = v;//-1*((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = v;//*1.2;//((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        n = 2;
      }
      else
      {
        //wr = -1*(2*(2*PI*v*wheelRad)*LookAhead_Ycomp)/pow(LookAhead_Dis[0],2);
        command1 = v;//*1.2;//((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = v;//-1*((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        n = 1;
      }
    }                                                                                   
  else if((Mid < Out_R) && (Mid < Out_L) && (Mid < L) && (Mid < Mid_L) && (Mid < Mid_R) && (Mid < R))
  {
    if(n == 2)
    {
      command1 = v;//*1.2;
      command2 = v;
    }
    else if (n == 1)
    {
      command1 = v;
      command2 = v;//*1.2;
    }
    else
    {
      command1 = v;
      command2 = v;
    }
    n = 0;
  }

=======
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
>>>>>>> parent of 2199e96 (Line Tacking Update)
}

void track(void); //Speed control
void track_setup(void); //pin set up

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
float wr = 0;
float prev_wr = 0;
float LookAhead_Dis[3] = {0.1513, 0.1552, 0.1616}; //[outside L/R sens, L/R sens] in meters
float LookAhead_Ycomp = 0.15; //[outside L/R sens, L/R sens] in meters
float WheelDis = 0.215; //in meters
float wheelRad = 0.0575; //in meters
int x = 45;
int n = 0;
int v = 1; //1
int index = 0;
int sums[7];
int readings[30][7];
bool flag = 0, flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0, flag6 = 0, flag7 = 0, tree1 = 0, tree2 = 0;
float current_position = (cur_pos[0] + cur_pos[1])/2;

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
  current_position = (cur_pos[0] + cur_pos[1])/2;
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
  
//  Serial.print(Out_L);
//  Serial.print(" ");
//  Serial.print(L);
//  Serial.print(" ");
//  Serial.print(Mid_L);
//  Serial.print(" ");
//  Serial.print(Mid);
//  Serial.print(" ");
//  Serial.print(Mid_R);
//  Serial.print(" ");
//  Serial.print(R);
//  Serial.print(" ");
//  Serial.print(Out_R);
//  Serial.print(" ");
//  Serial.print(flag);
//  Serial.print(" ");
  Serial.println(current_position);
  if(current_position < .15) //initial launch out of start square
  {
     command1 = 1;//2
     command2 = 1;//2
  }
  else if (current_position > 2.48 && tree1 == 0)
  {
    noInterrupts();
    tree1 = 1;
    digitalWrite(37, LOW);
    digitalWrite(39, HIGH);
    get_current_status();
    des_pos[0] = cur_pos[0];//leftmotor position
    des_pos[1] = cur_pos[1];//rightmotor position
    low_level_control();//pid controller
    interrupts();
  }
  else if (current_position > 2.75 && flag1 == 0)
  {
    noInterrupts();
    flag1 = 1;
    digitalWrite(37, HIGH);
    digitalWrite(39, LOW);
    get_current_status();
    des_pos[0] = cur_pos[0];//leftmotor position
    des_pos[1] = cur_pos[1];//rightmotor position
    low_level_control();//pid controller
    interrupts();
  }
  else if (current_position > 100 && flag2 == 0)
  {
    noInterrupts();
    flag2 = 1;
    digitalWrite(37, HIGH);
    digitalWrite(39, LOW);
    get_current_status();
    des_pos[0] = cur_pos[0];//leftmotor position
    des_pos[1] = cur_pos[1];//rightmotor position
    low_level_control();//pid controller
    interrupts();
  }
  else if (current_position > 5.75 && flag3 == 0)
  {
    noInterrupts();
    flag3 = 1;
    digitalWrite(37, HIGH);
    digitalWrite(39, LOW);
    get_current_status();
    des_pos[0] = cur_pos[0];//leftmotor position
    des_pos[1] = cur_pos[1];//rightmotor position
    low_level_control();//pid controller
    interrupts();
  }
  else if (current_position > 10.17 && tree2 == 0)
  {
    noInterrupts();
    tree2 = 1;
    digitalWrite(37, LOW);
    digitalWrite(39, HIGH);
    get_current_status();
    des_pos[0] = cur_pos[0];//leftmotor position
    des_pos[1] = cur_pos[1];//rightmotor position
    low_level_control();//pid controller
    interrupts();
  }
  else if (current_position > 11.89 && flag == 0) //turn around
  {
    flag = 1;
    command1 = -100;//leftmotor speed
    command2 = 100;//rightmotor speed
    get_current_status();
    des_vel[0] = (command1*1.2/2)/14;//leftmotor speed
    des_vel[1] = (command2/2)/14;//rightmotor speed
    low_level_control();//pid controller
    for (int z = 1; z < 4000; z++);
  }
  else if (current_position > 12.28 && flag4 == 0)
  {
    noInterrupts();
    flag4 = 1;
    digitalWrite(37, HIGH);
    digitalWrite(39, LOW);
    get_current_status();
    des_pos[0] = cur_pos[0];//leftmotor position
    des_pos[1] = cur_pos[1];//rightmotor position
    low_level_control();//pid controller
    interrupts();
  }
  else if (current_position > 17.88 && flag5 == 0)
  {
    noInterrupts();
    flag5 = 1;
    digitalWrite(37, HIGH);
    digitalWrite(39, LOW);
    get_current_status();
    des_pos[0] = cur_pos[0];//leftmotor position
    des_pos[1] = cur_pos[1];//rightmotor position
    low_level_control();//pid controller
    interrupts();
  }
  else if (current_position > 20 && flag6 == 0)
  {
    noInterrupts();
    flag6 = 1;
    digitalWrite(37, HIGH);
    digitalWrite(39, LOW);
    get_current_status();
    des_pos[0] = cur_pos[0];//leftmotor position
    des_pos[1] = cur_pos[1];//rightmotor position
    low_level_control();//pid controller
    interrupts();
  }
    else if ((Out_L > x) && (L > x) && (Mid_L > x) && (Mid > x) && (Mid_R > x) && (R > x) && (Out_R > x))
    {
      command1 = -.5;
      command2 = -.5;
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
        command2 = -1*((2*PI*v*wheelRad) + (WheelDis/2)*wr);//.75
        break;
      case 4:
        break;
        wr = (2*(2*PI*v*wheelRad)*LookAhead_Ycomp)/pow(LookAhead_Dis[1],2);
        command1 = -1*((2*PI*v*wheelRad) - (WheelDis/2)*wr);//.75
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
        command1 = -1*((2*PI*v*wheelRad) - (WheelDis/2)*wr);//.75
        command2 = 1.5*((2*PI*v*wheelRad) + (WheelDis/2)*wr);
        n = 4;
      }
      else
      {
        wr = -1*(2*(2*PI*v*wheelRad)*LookAhead_Ycomp)/pow(LookAhead_Dis[1],2);
        command1 = 1.5*((2*PI*v*wheelRad) - (WheelDis/2)*wr);
        command2 = -1*((2*PI*v*wheelRad) + (WheelDis/2)*wr);//.75
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

}

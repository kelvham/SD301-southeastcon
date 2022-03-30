//motor stuff
void pwm_init(void); //timer function
void motor_init(void); //Motor pin initialization
void motor_speed(int motor, int duty); //Motor speed control

void pwm_init(void)
{
  pinMode(45, OUTPUT); //PWM(EA) on motor driver for motor 0
  pinMode(46, OUTPUT); //PWM(EB) on motor driver for motor 1
  TCCR5A = _BV(COM5A1) | _BV(COM5B1) | _BV(WGM52) | _BV(WGM50);
  TCCR5B = _BV(CS51) | _BV(CS50); //Sets prescaler to 64
  OCR5A = 0;
  OCR5B = 0;
}

void motor_init(void)
{
  pwm_init();
  pinMode(50, OUTPUT); //Direction(I1) for motor 0/left motor//50
  pinMode(51, OUTPUT); //Direction(I2) for motor 0//51
  pinMode(52, OUTPUT); //Direction(I3) for motor 1/right motor//52
  pinMode(53, OUTPUT); //Direction(I4) for motor 1//53
}

void motor_speed(int motor, int duty)
{
  /*direction specification*/
  int dir;
  
  if(duty < 0) //reverse
  {
    if(duty < -255)
    {
     duty = 255; 
    }
    dir = 1;
  }
  else if(duty > 0) //forward
  {
    if(duty > 255)
    {
      duty = 255;
    }
    dir = 0;
  }

  /*Setting Duty Cycle*/
  if(motor == 0 && dir == 0)
  {
    OCR5B = duty;
  }
  else if(motor == 0 && dir == 1)
  {
    OCR5B = duty;
  }
  else if(motor == 1 && dir == 0)
  {
    OCR5A = duty;
  }
  else if(motor == 1 && dir == 1)
  {
    OCR5A = duty;
  }

  /*Speed specification*/
  switch(dir)
  {
    case 0: //forward direction
    if(motor == 0)
    {
      digitalWrite(50, LOW); // I1
      digitalWrite(51, HIGH); // I2
    }
    else if(motor == 1)
    {
      digitalWrite(52, LOW); // I3
      digitalWrite(53, HIGH); // I4
    }
    break;
    
    case 1: //reverse direction
        if(motor == 0)
    {
      digitalWrite(50, HIGH);
      digitalWrite(51, LOW);
    }
    else if(motor == 1)
    {
      digitalWrite(52, HIGH);
      digitalWrite(53, LOW);
    }
    break;
   
    default:
    break;
  }
}


//encoder stuff----------------------------------------------------------------------------------------
long int encoder0_val = 0;
long int encoder1_val = 0;
void encoder_init(void);
void Enc0();
void Enc1();

void encoder_init(void)
{
  pinMode(2, INPUT_PULLUP); //Encoder 0 CHA Left MOTOR
  pinMode(3, INPUT_PULLUP); //Encoder 0 CHB
  pinMode(18, INPUT_PULLUP); //Encoder 1 CHA Right MOTOR
  pinMode(19, INPUT_PULLUP); //Encoder 1 CHB
  attachInterrupt(digitalPinToInterrupt(2), Enc0, RISING);
  attachInterrupt(digitalPinToInterrupt(18), Enc1, RISING);
}

void Enc0()
{
  if(digitalRead(3) > 0)
  {
    encoder0_val++;
  }
  else
  {
    encoder0_val--;
  }
  
}

void Enc1()
{
  if(digitalRead(19) > 0)
  {
    encoder1_val++;
  }
  else
  {
    encoder1_val--;
  }
  
}

//PD control stuff----------------------------------------------------------------------------------------
#define END_CPR     100
#define Gear_Ratio  50
#define T           0.1 //.1  // 100 msec

float des_vel[2] = {0,0};
float cur_vel[2] = {0,0};
float prev_des_pos[2] = {0,0};
float des_pos[2] = {0,0};
float cur_pos[2] = {0,0};
float prev_pos[2] = {0,0};

void set_up_timer(void);
void get_current_status(void);
void low_level_control(void);

void set_up_timer(void)
{
  noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  OCR1A = 6250; //Used to compare the match registry
  TCCR1B |= (1 << WGM12); //CTC mode
  TCCR1B |= (1 << CS12); //256 prescaler
  TIMSK1 |= (1 << OCIE1A); //Enable timer compare interrupt
  interrupts();
}

void get_current_status(void)
{
  //motor 0
  cur_pos[0] = ((encoder0_val*2*PI) / (4*END_CPR*Gear_Ratio))*1.57; //(Encoderval*NumOfWheels*PI)/(QuadratureDecoding*CountPerRev*GearRatio)
  cur_vel[0] = (cur_pos[0] - prev_pos[0]) / T;
  prev_pos[0] = cur_pos[0];
  des_pos[0] = prev_des_pos[0] + des_vel[0]*T;
  prev_des_pos[0] = des_pos[0];
  //Serial.println(cur_vel[0]);
    
  //motor 1
  cur_pos[1] = ((encoder1_val*2*PI) / (4*END_CPR*Gear_Ratio))*1.57; //(Encoderval*NumOfWheels*PI)/(QuadratureDecoding*CountPerRev*GearRatio)
  cur_vel[1] = (cur_pos[1] - prev_pos[1]) / T;
  prev_pos[1] = cur_pos[1];
  des_pos[1] = prev_des_pos[1] + des_vel[1]*T;
  prev_des_pos[1] = des_pos[1];

//  Serial.println(encoder0_val);
//  Serial.println(" ");
//  Serial.println(encoder1_val);
}

void low_level_control(void)
{
  static float batt_volt = 7.2;
  float Kp = 5; //5;
  float Ki = 0;
  float Kd = 0.5; //0.5;
  float volt[2] = {0,0};
  int duty = 0;
/*
  Serial.print(cur_pos[0]);
  Serial.print(" ");
  Serial.println(cur_pos[1]);*/
  
  volt[0] = Kp*(des_pos[0]-cur_pos[0]) + Ki*((des_pos[0] - cur_pos[0])*T) + Kd*(des_vel[0]-cur_vel[0]);
  volt[1] = Kp*(des_pos[1]-cur_pos[1]) + Ki*((des_pos[1] - cur_pos[1])*T) + Kd*(des_vel[1]-cur_vel[1]);
  
  duty = (volt[0]/batt_volt)*255;
  motor_speed(0, duty);
  
  duty = (volt[1]/batt_volt)*255;
  motor_speed(1, duty);
}

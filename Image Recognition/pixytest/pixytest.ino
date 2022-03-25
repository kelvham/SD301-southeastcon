//pixy cam base code
  
#include <Pixy2.h>

// This is the main Pixy object 
Pixy2 pixy;
int light = 7; //test LED
void setup()
{
  pinMode(light,OUTPUT);
  Serial.begin(9600);
  Serial.print("Starting...\n");
  pixy.init();
}

void loop()
{ 
  int i; 
  // grab blocks!
  pixy.ccc.getBlocks();
  
  // If there are detect blocks, print them!
  if (pixy.ccc.numBlocks)
  {
    digitalWrite(light,HIGH);
    Serial.print("Detected Cup");
    Serial.println(pixy.ccc.numBlocks);
  } 
  else 
  {
     digitalWrite(light,LOW);
    } 
}

#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup(void) {
    // set the speed at 60 rpm:
myStepper.setSpeed(60);
  // initialize the serial port:
Serial.begin(9600);

      // step one revolution in the other direction:
Serial.println("counterclockwise");
myStepper.step(stepsPerRevolution/4);

digitalWrite (8,LOW);
digitalWrite (9,LOW);
digitalWrite (10,LOW);
digitalWrite (11,LOW);

delay(2000); // Pause 2 seconds before moving on to loop()
       // step one revolution in the other direction:

digitalWrite (8,HIGH);
digitalWrite (9,HIGH);
digitalWrite (10,HIGH);
digitalWrite (11,HIGH);
Serial.println("clockwise");
myStepper.step(-stepsPerRevolution/4);

digitalWrite (8,LOW);
digitalWrite (9,LOW);
digitalWrite (10,LOW);
digitalWrite (11,LOW);
}

void loop() {
 //exit(1);
}
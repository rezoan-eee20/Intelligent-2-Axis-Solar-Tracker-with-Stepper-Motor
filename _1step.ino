#include <Stepper.h>
const int stepsPerRevolution = 50;  // change this to fit the number of steps per revolution
// initialize the stepper library on pins 8 through 11:
Stepper myStepper1(stepsPerRevolution, 8, 10, 9, 11);
Stepper myStepper2(stepsPerRevolution, 4, 6, 5, 7); 
float a=0.00,b=0.00;


//CLOCKWISE ROTATION FUNCTION
void clockwise()
  {
   myStepper2.step(25);
   myStepper1.step(0);
  }
  
//ANTICLOCKWISE ROTATION FUNCTION 
  void anticlockwise()
  {
  myStepper2.step(-25);
  myStepper1.step(0);
  }
  
void setup() 
{
  myStepper1.setSpeed(60 );
  myStepper2.setSpeed(50);
  Serial.begin(9600);
}

float val1=0.00,val2=0.00,val3=0.00;

void loop() 
{
//STORE CONVERTED VOLTAGE VALUE IN VAL1
a=analogRead(A1);
b=(5.00*a)/1023.00;
   val1=b;

//ROTATE CLOCKWISE AND STORE CONVERTED VOLTAGE VALUE IN VAL2
clockwise();
a=analogRead(A1);
b=(5.00*a)/1023.00;
val2=b;

//ROTATE ANTICLOCKWISE AND STORE CONVERTED VOLTAGE VALUE IN VAL3
anticlockwise();
a=analogRead(A1);
b=(5.00*a)/1023.00;
val3=b;
  
Serial.println("val1:");
Serial.println(val1);
//delay(1000);
Serial.println("val2:");
Serial.println(val2);
//delay(1000);
Serial.println("val3:");
Serial.println(val3);
//delay(1000);

//COMPARE AND STOP ROTATION SINCE THE PRESENT INTENSITY IS GREATER THAN THE REST
  if((val1>val2)&&(val1>val3))
  {
  myStepper2.step(0);
  //delay(100);
  }

//COMPARE AND ROTATE CLOCKWISE
if((val2>val1)&&(val2>val3))
  {
  clockwise();
  }
  
  //COMPARE AND ROTATE ANTICLOCKWISE
  if((val3>val2)&&(val3>val1))
  {
  anticlockwise();
  }
 
}



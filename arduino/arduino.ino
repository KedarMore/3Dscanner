/*
45 degree lead srew....
start scanning (line)
rotate platform by 4 degrees
complete 360 degrees
.....send each value of distance seperately to C++
.....DONT calculate in arduino
.....send 0 as a data at start and end of each column
*/

#include <Stepper.h>//..........................................................................STEPPER
const int stepsPerRevolution = 360;  // change this to fit the number of steps per revolution
                                     // for your motor
// initialize the stepper library on pins 8 through 11:
Stepper objectStepper(stepsPerRevolution, 8,9,10,11);
Stepper leadStepper(stepsPerRevolution, 8,9,10,11);

#include <Servo.h>

Servo myservo;  // create servo object to control a servo.....................................SERVO
                // a maximum of eight servo objects can be created
int pos = 0;    // variable to store the servo position

void setup()
{
  pinMode(buttonPin, INPUT);//................................................................start button

  while(distValue<=50)//........height is not needed, just keep it
  {
    servoPos(lead,0);
    lead++;
  }
  height=lead/1.41;
}

void loop()
{
    for(i=0;i<=90;i++)//.....................................................theta scan
    {
      if(phi%8==0)
      {
        servoPos(lead,i);//calculate the relation b/w lead and theta
        lead=lead+
      }
      else
      {
        servoPos(lead,90-i);
        lead=lead-
      }
    }
    objectStepper.steps(4);
    phi=phi+4;//..........................................................phi increases
  }
}

void servoPos(lead,theta)//........lead is the dist from the base of lead screw
{
  myservo.write(theta);
  diff=currentLead-lead;
  leadStepper.steps(leadTOsteps(diff));
}

int leadTOsteps(lead)
{
  steps=(lead/pitch)*360;
  return steps;
}

#include <Stepper.h>
const int stepsPerRevolution = 3200;
Stepper objectStepper(stepsPerRevolution, 37,42);
Stepper leadStepper(stepsPerRevolution, 38,40);

#include <Servo.h>
Servo myServo;

//CONSTANTS
int pitch=14;//tpi
int currentLead=0;

void setup() {
  myServo.attach(44);
  Serial.begin(9600);
}

void loop() {
  for(i=0;i<=90;i++)//.....................................................theta scan
    {
      if(phi%8==0)
      {
        lead=(tan(i)*l*sqrt(2)/(1+tan(i)));
        servoPos(lead,i);//calculate the relation b/w lead and theta
        Serial.println(value());
        currentLead=lead;
      }
      else
      {
        lead=(tan(90-i)*l*sqrt(2)/(1+tan(90-i)));
        servoPos(lead,90-i);
        Serial.println(value());
        currentLead=lead
      }
    }
    objectStepper.steps(degreeTOsteps(4));

    phi=phi+4;//..........................................................phi increases
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

int degreeTOsteps(degree)
{
  steps=degree*stepsPerRevolution/360;
  return steps;
}

int value()
{
  val=analogRead(A0);
  val=(6768/(val-3))-4;
  return val;
}

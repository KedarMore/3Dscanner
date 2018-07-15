/*
Start button (physical)....debounce
height estimation
45 degree lead srew....idea....
start scanning (line)
rotate platform by 4 degrees
complete 360 degrees
.....send each value of distance seperately to C++
.....DONT calculate in arduino
.....send 0 as a data at start and end of each column
*/

// constants won't change. They're used here to..................................................DEBOUNCE
// set pin numbers:
const int buttonPin = 2;    // the number of the pushbutton pin
// Variables will change:
int start = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
// the following variables are long's because the time, measured in miliseconds
// will quickly become a bigger number than can be stored in an int
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

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

  int reading = digitalRead(buttonPin);//.....................................................button
  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH),  and you've waited
  // long enough since the last press to ignore any noise:
  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:
    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;
      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        start = !start
      }
    }
  }
  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = reading;

  if(start==1 && phi<=360)
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

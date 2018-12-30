#include <Arduino.h>

int count=1,flag=0,value;
float avg,sum=0,val;

void setup()
{
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop()
{
  // put your main code here, to run repeatedly:
  val=analogRead(A0);
  val=(6768/(val-3))-4;
  Serial.println(val);
  delay(100);
  /*
  flag=1;
  if(count<=100)
  {
    flag=0;
    sum=sum+val;
    count++;
  }
  if(flag==1)
  {
    avg=sum/100;
    Serial.println(avg);
    sum=0;
    count=1;
  }*/
}

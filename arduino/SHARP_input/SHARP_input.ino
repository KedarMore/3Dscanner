int count=1,flag=0;
float val,avg,sum=0;

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
 // Serial.println(val);
  delay(10);
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
  }
}

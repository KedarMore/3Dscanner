void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  pinMode(A1,OUTPUT);
}
int diff, output, p;
void loop() {
  // put your main code here, to run repeatedly:
  int input=(analogRead(A0);
  diff=p*input;
  output=-diff;
  analogWrite(A1);
}

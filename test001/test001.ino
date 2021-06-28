int LEDpin=A5;
int SWpin=A2;

void setup()
{
  pinMode(LEDpin, OUTPUT);
  pinMode(SWpin,INPUT);
}

void loop()
{
  int SWITCH=digitalRead(SWpin);
  if(SWITCH==HIGH)
  {
    digitalWrite(LEDpin,HIGH);
  }else
  {
    digitalWrite(LEDpin,LOW);
  }
}

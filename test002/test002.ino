int LEDpin=A1;
int LEDpin2=A2;
int SWpin=A4;
int SWpin2=A5;

void setup()
{
  pinMode(LEDpin, OUTPUT);
  pinMode(SWpin,INPUT);
  pinMode(LEDpin2, OUTPUT);
  pinMode(SWpin2,INPUT);
}

void loop()
{
  int SW=digitalRead(SWpin);
  int SW2=digitalRead(SWpin2);

  if(SW==HIGH && SW2==HIGH)
  {
    digitalWrite(LEDpin,HIGH);
    digitalWrite(LEDpin2,HIGH);
  }
  else if(SW==HIGH && SW2==LOW)
  {
    digitalWrite(LEDpin,HIGH);
  }
  else if(SW==LOW && SW2==HIGH)
  {
    digitalWrite(LEDpin2,HIGH);
  }
  else if(SW==LOW && SW2==LOW)
  {
    digitalWrite(LEDpin,LOW);
    digitalWrite(LEDpin2,LOW);
  }
}

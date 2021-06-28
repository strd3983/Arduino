int LEDpin = A5;
int SWpin = A2;
int SW_new;
int n = 0;

void setup()
{
  pinMode(LEDpin, OUTPUT);
  pinMode(SWpin, INPUT);
}

void loop()
{
  int SW_old = digitalRead(SWpin);

  if (SW_old == HIGH && SW_new == LOW)
  {
    n += 1;
  }

  if (n % 2 == 0)
  {
    digitalWrite(LEDpin, LOW);
  }
  else
  {
    digitalWrite(LEDpin, HIGH);
  }

  SW_new = SW_old;
}

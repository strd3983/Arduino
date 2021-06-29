#define LEDpin 9
#define PSWpin 2
int n = 0, PSW_old = HIGH;

void setup()
{
  pinMode(LEDpin, OUTPUT);
  pinMode(PSWpin, INPUT);
}

void loop()
{
  int PSW = digitalRead(PSWpin);
  if (PSW_old == HIGH && PSW == LOW)
    n += 1;
  if (n == 0)
    digitalWrite(LEDpin, LOW);
  else
    digitalWrite(LEDpin, HIGH);
  PSW_old = PSW;
  n %= 2;
}

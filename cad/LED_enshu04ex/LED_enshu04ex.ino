#define LEDpin 9
#define varRpin A0
#define CdSpin A1
#define offset 120

void setup()
{
  pinMode(LEDpin, OUTPUT);
  pinMode(CdSpin, INPUT);
}

void loop()
{
  int CdS = analogRead(CdSpin) - 120;
  if (255 < CdS)
    CdS = 255;
  analogWrite(LEDpin, CdS);
  delay(100);
}

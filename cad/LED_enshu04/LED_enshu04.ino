#define LEDpin 9
#define SSWpin 4
#define PSWpin 2
#define varRpin A0
#define CdSpin A1

void setup()
{
  pinMode(LEDpin, OUTPUT);
  pinMode(SSWpin, INPUT);
  pinMode(PSWpin, INPUT);
  pinMode(varRpin, INPUT);
  pinMode(CdSpin, INPUT);
}

void loop()
{
  int CdS = analogRead(CdSpin);
  analogWrite(LEDpin, CdS);
  delay(2);
}

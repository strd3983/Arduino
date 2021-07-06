#define LEDpin 9
#define SSWpin 4
#define PSWpin 2
#define varR A0

void setup()
{
  pinMode(LEDpin, OUTPUT);
  pinMode(SSWpin, INPUT);
  pinMode(PSWpin, INPUT);
  pinMode(varR, INPUT);
}

void loop()
{
  int var = analogRead(varR);
  analogWrite(LEDpin, var);
  delay(2);
}

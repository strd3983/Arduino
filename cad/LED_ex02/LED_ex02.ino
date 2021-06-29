#define LEDpin 9
#define SSWpin 4
#define PSWpin 2
#define varR A0

void setup()
{
  pinMode(LEDpin, OUTPUT);
  pinMode(SSWpin, INPUT);
  pinMode(PSWpin, INPUT);
  pinMode(varR, OUTPUT);
}

void loop()
{
  long long val = pulseIn(PSWpin, LOW, 60000000);
  analogWrite(LEDpin, val * 255 / 10000000);
}

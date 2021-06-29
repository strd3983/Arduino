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
  int SSW = digitalRead(SSWpin);
  int PSW = digitalRead(PSWpin);

  if (SSW == HIGH && PSW == LOW)
    analogWrite(LEDpin, 255 * 3 / 3);
  if (SSW == HIGH && PSW == HIGH)
    analogWrite(LEDpin, 255 * 2 / 3);
  if (SSW == LOW && PSW == LOW)
    analogWrite(LEDpin, 255 * 1 / 3);
  if (SSW == LOW && PSW == HIGH)
    analogWrite(LEDpin, 255 * 0 / 3);

  delay(2);
}

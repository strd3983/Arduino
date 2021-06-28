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

//LED点滅関数
void flash(int time)
{
  digitalWrite(LEDpin,HIGH);
  delay(time);
  digitalWrite(LEDpin,LOW);
  delay(time);
}

void loop()
{
  int PSW1 = digitalRead(PSWpin);

  if(SSW==HIGH)
    flash(2000);
  else
    digitalWrite(LEDpin,LOW);
  PSW2=PSW1;
}

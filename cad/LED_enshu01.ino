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
  int SSW=digitalRead(SSWpin);
  //int PSW=digitalRead(PSWpin);

  if(SSW==HIGH)
    digitalWrite(LEDpin,HIGH);
  else
    digitalWrite(LEDpin,LOW);

}

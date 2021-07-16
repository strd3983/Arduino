#define SSWpin 4
#define PSWpin 2
#define varRpin A0

void setup()
{
  pinMode(SSWpin, INPUT);
  pinMode(PSWpin, INPUT);
  pinMode(varRpin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int SSW = digitalRead(SSWpin);
  int PSW = digitalRead(PSWpin);
  int varR = analogRead(varRpin);
  Serial.print(SSW);
  Serial.print("\t");
  Serial.print(PSW);
  Serial.print("\t");
  Serial.println(varR);
  delay(1000);
}

#define LEDPIN 13
#define PERIOD 1000
void setup()
{
  pinMode(LEDPIN, OUTPUT);
}
void loop()
{
  digitalWrite(LEDPIN, HIGH);
  delay(PERIOD / 2);
  digitalWrite(LEDPIN, LOW);
  delay(PERIOD / 2);
  digitalWrite(LEDPIN, HIGH);
  delay(PERIOD / 4);
  digitalWrite(LEDPIN, LOW);
  delay(PERIOD / 2);
}

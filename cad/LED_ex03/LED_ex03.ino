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

volatile int n = 0; //割り込み回数

void ledISR()
{
  n++;
  if (n % 2 == 0)
    digitalWrite(LEDpin, LOW);
  else
    digitalWrite(LEDpin, HIGH);
}

void loop()
{
  //プッシュスイッチが押されたとき割り込み
  attachInterrupt(0, ledISR, FALLING);
  delay(10000);
}

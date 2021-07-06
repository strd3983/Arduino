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

volatile int flag;

void ledISR()
{
  flag = 0;
}

void loop()
{
  //flagのデフォルト値は1
  flag = 1;
  //プッシュスイッチが押されたとき割り込み
  attachInterrupt(0, ledISR, FALLING);
  while (flag)
    digitalWrite(LEDpin, LOW);
  digitalWrite(LEDpin, HIGH);
  delay(1000);
}

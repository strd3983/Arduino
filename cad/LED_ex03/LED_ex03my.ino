#define LEDpin 9
#define PSWpin 2
#define varRpin A0
volatile int n = 0; //割り込み回数
volatile int PSW_old = HIGH;

void setup()
{
  pinMode(LEDpin, OUTPUT);
  pinMode(PSWpin, INPUT);
  pinMode(varRpin, OUTPUT);
  Serial.begin(9600);
}

void ledISR()
{
  int PSW = digitalRead(PSWpin);
  if (n % 2 == 0)
    digitalWrite(LEDpin, LOW);
  else
    digitalWrite(LEDpin, HIGH);
  PSW_old = PSW;
}

void loop()
{
  int PSW = digitalRead(PSWpin);

    attachInterrupt(0, ledISR, HIGH);
  //プッシュスイッチが押されたとき割り込み
  double varR = analogRead(varRpin);
  Serial.print(varR);
  Serial.print("\t");
  Serial.println(n);
  delay(2500);
}

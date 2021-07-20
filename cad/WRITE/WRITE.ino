#define LEDpin 9
#define PSWpin 2
#define varRpin A0
volatile int n = 0; //割り込み回数

void setup()
{
  pinMode(LEDpin, OUTPUT);
  pinMode(PSWpin, INPUT);
  pinMode(varRpin, OUTPUT);
  //プッシュスイッチが押されたとき割り込み
  attachInterrupt(0, ledISR, CHANGE);
  Serial.begin(9600);
}

void ledISR()
{
  //変化したときに押しているときは反応しない
  if (digitalRead(PSWpin) == LOW)
    return;
  n++;
  if (n % 2 == 0)
    digitalWrite(LEDpin, LOW);
  else
    digitalWrite(LEDpin, HIGH);
}

void loop()
{
  Serial.print(analogRead(varRpin));
  Serial.print("\t");
  Serial.println(n);
  delay(10000);
}

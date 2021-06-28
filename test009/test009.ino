int SER = A5, LCK = A4, SRCK = A3;
int time = 50;
//SER:シリアル, LCK:ラッチクロック, SRCK:シフトレジスタクロック

void setup()
{
  pinMode(SER, OUTPUT);
  pinMode(LCK, OUTPUT);
  pinMode(SRCK, OUTPUT);
}

void loop()
{
  digitalWrite(SER, HIGH);
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(SRCK, HIGH);
    digitalWrite(SRCK, LOW);
    digitalWrite(LCK, HIGH);
    digitalWrite(LCK, LOW);
    digitalWrite(SER, LOW);
    delay(time);
  }

  for (int i = 8; 0 < i; i--)
  {
    digitalWrite(SER, HIGH);
    for (int j = 0; j < i; j++)
    {
      digitalWrite(SRCK, HIGH);
      digitalWrite(SRCK, LOW);
      digitalWrite(SER, LOW);
    }
    digitalWrite(LCK, HIGH);
    digitalWrite(LCK, LOW);
    delay(time);
    for (int j = 0; j <= 8 - i; j++)
    {
      digitalWrite(SRCK, HIGH);
      digitalWrite(SRCK, LOW);
    }
  }
}

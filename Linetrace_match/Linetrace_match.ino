//setup

//フォトトランジスタ
int a = A0;
int b = A1;
int c = A2;
int d = A3;
int e = A4;
int f = A5;
int sg = A6;

//モーター
int L_f = 9;
int L_b = 10;
int R_f = 6;
int R_b = 5;

int count = 0;
int out = 0;
int kp = 50;
int sp_set = 55;

bool wb1 = false;
bool wb2 = false;

int LMP = 50;
int RMP = 50;

void setup()
{
  pinMode(L_f, OUTPUT);
  pinMode(L_b, OUTPUT);
  pinMode(R_f, OUTPUT);
  pinMode(R_b, OUTPUT);

  pinMode(a, INPUT);
  pinMode(b, INPUT);
  pinMode(c, INPUT);
  pinMode(d, INPUT);
  pinMode(e, INPUT);
  pinMode(f, INPUT);
  pinMode(sg, INPUT);
  //Serial.begin(9600);
}

void loop()
{
  int n = 1;
  double ls = 0;
  int sp = sp_set;
  int sel = 0;

  if (analogRead(a) < 100)
  {
    ls -= 2.0;
    n += 1;
    out = -2;
    sp /= 2;
  }
  if (analogRead(b) < 100)
  {
    ls -= 1.0;
    n += 1;
    out = -1;
    sp -= 20;
  }
  if (analogRead(c) < 100)
  {
    ls -= 0.5;
    n += 1;
    out = 0;
    sp += 15;
  }
  if (analogRead(d) < 100)
  {
    ls += 0.5;
    n += 1;
    out = 0;
    sp += 15;
  }
  if (analogRead(e) < 100)
  {
    ls += 1.0;
    n += 1;
    out = 1;
    sp -= 20;
  }
  if (analogRead(f) < 100)
  {
    ls += 2.0;
    n += 1;
    out = 2;
    sp /= 2;
  }

  //ゴールテープ読み
  if (analogRead(sg) < 950 && wb1 == false)
  {
    wb1 = true;
    ++count;
  }
  if (analogRead(sg) > 1000 && wb1 == true)
  {
    wb1 = false;
  }

  //十字読み
  if (n > 5 && wb2 == false)
  {
    wb2 = true;
    --count;
    ls = 0;
    out = 0;
  }
  if (n < 5 && wb2 == true)
  {
    wb2 = false;
    ls = 0;
    out = 0;
  }

  //コースアウト処理
  if (out == -2 && n == 1)
  {
    ls -= 1.5;
    sp /= 3;
    sel = 1;
  }
  if (out == 2 && n == 1)
  {
    ls += 1.5;
    sp /= 3;
    sel = -1;
  }

  //比例制御
  int MD = kp * (ls / n);

  LMP = sp - MD;
  RMP = sp + 10 + MD;

  //ゴールストップ
  if (count > 1)
  {
    delay(sp / 3 * 10);
    RMP = 0;
    LMP = 0;
  }

  driveMotor(LMP, RMP);

  Serial.println(count);
}

//モーターを動かす関数
void driveMotor(int left, int right)
{
  //255は超えないようにする
  if (left > 255)
  {
    left = 255;
  }
  else if (left < -255)
  {
    left = -255;
  }
  if (right > 255)
  {
    right = 255;
  }
  else if (right < -255)
  {
    right = -255;
  }

  if (left > 0)
  {
    analogWrite(L_f, left);
    analogWrite(L_b, 0);
  }
  else
  {
    left = abs(left);
    analogWrite(L_f, 0);
    analogWrite(L_b, left);
  }
  if (right > 0)
  {
    analogWrite(R_f, right);
    analogWrite(R_b, 0);
  }
  else
  {
    right = abs(right);
    analogWrite(R_f, 0);
    analogWrite(R_b, right);
  }
}

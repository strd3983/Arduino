//setup
int sp_set = 60;
int dt = 1;
double kp = 60;
double ki = 0.1;
double kd = 100;

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

int LMP = 50;
int RMP = 50;

//変数
double diff[2];
int integ;
int out = 0;
int count = 0;
bool wb1 = false;
bool wb2 = false;

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
  Serial.begin(9600);
}

void loop()
{
  int p, i, d1, r;
  int sp = sp_set;
  int n = 1;

  diff[0] = diff[1];
  diff[1] = 0;

  if (analogRead(c) < 100)
  {
    diff[1] += -0.5;
    n++;
    out = 0;
    sp += 10;
  }
  if (analogRead(d) < 100)
  {
    diff[1] += 0.5;
    n++;
    out = 0;
    sp += 10;
  }
  if (analogRead(b) < 100)
  {
    diff[1] += -1.0;
    n++;
    out = -1;
    sp -= 10;
  }
  if (analogRead(e) < 100)
  {
    diff[1] += 1.0;
    n++;
    out = 1;
    sp -= 10;
  }
  if (analogRead(a) < 100)
  {
    diff[1] += -2.0;
    n++;
    sp /= 2;
    out = -2;
  }
  if (analogRead(f) < 100)
  {
    diff[1] = 2.0;
    n++;
    sp /= 2;
    out = -2;
  }

  //コースアウト処理
  if (out == -2 && n == 1)
  {
    r = -2;
    sp /= 3;
  }
  if (out == 2 && n == 1)
  {
    r = 2;
    sp /= 3;
  }

  integ += (diff[1] + diff[0]) / 2 * dt;

  p = kp * (diff[1] / n);
  i = ki * integ;
  d1 = kd * (diff[1] - diff[0]) / dt;
  r = p - i + d1;
  sp -= abs(r) / 2;

  //十字読み
  if (n > 5 && wb2 == false)
  {
    wb2 = true;
    --count;
    out = 0;
  }
  if (n < 5 && wb2 == true)
  {
    wb2 = false;
    out = 0;
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

  LMP = sp - r;
  RMP = sp + 10 + r;

  //ゴールストップ
  if (count > 1)
  {
    delay(sp / 3 * 10);
    RMP = 0;
    LMP = 0;
  }

  driveMotor(LMP, RMP);

  if (d1 > 0)
  {
    Serial.println(1);
  }
  if (d1 < 0)
  {
    Serial.println(-1);
  }

  delay(1);
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

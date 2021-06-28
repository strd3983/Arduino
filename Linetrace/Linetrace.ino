//フォトトランジスタ
int a = A0;
int b = A1;
int c = A2;
int d = A3;
int e = A4;
int f = A5;

//モーター
int L_f = 9;
int L_b = 10;
int R_f = 6;
int R_b = 5;

int out = 0;
int kp = 50;


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
  //Serial.begin(9600); 
}

void loop()
{

  int n = 1;
  double ls = 0;
  int sp = 50;

  //どのフォトで白線を読んでいるか
  if (analogRead(a) < 100)
  {
    ls -= 2;
    n += 1;
    out = -2;
    kp = 50;
  }
  if (analogRead(b) < 100)
  {
    ls -= 1;
    n += 1;
    out = -1;
    kp = 50;
  }
  if (analogRead(c) < 100)
  {
    ls -= 0.5;
    n += 1;
    out = 0;
    kp = 50;
  }
  if (analogRead(d) < 100)
  {
    ls += 0.5;
    n += 1;
    out = 0;
    kp = 50;
  }
  if (analogRead(e) < 100)
  {
    ls += 1;
    n += 1;
    out = 1;
    kp = 50;
  }
  if (analogRead(f) < 100)
  {
    ls += 2;
    n += 1;
    out = 2;
    kp = 50;
  }
  if (analogRead(f)>100 && analogRead(a)>100 && out == 2)
  {
    kp = sp / 2;
    n = 1;
    ls = 1;
  }
  if (analogRead(f)>100 && analogRead(a)>100 && out == -2)
  {
    kp = -sp / 2;
    n = 1;
    ls = 1;
  }

  //比例制御
  int MD = kp * (ls / n);
  
  LMP = sp - MD;
  RMP = sp+10 + MD;

  //モーターを動かす関数
  driveMotor(LMP, RMP);
  //Serial.println(out);
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

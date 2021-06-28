int Forward=3;
int Back=5;
void driveMotor(int);

void setup()
{
  pinMode(Forward,OUTPUT);
  pinMode(Back,OUTPUT);
}

void loop()
{
  driveMotor(100);
  delay(2000);
  driveMotor(-100);
  delay(2000);
  driveMotor(500);
  delay(2000);
}

void driveMotor(int mt)
{
  if (mt > 255)
    mt = 255;
  else if (mt < -255)
  {
    mt = -255;
  }

  if (mt > 0)
  {
    analogWrite(Forward, mt);
    analogWrite(Back, mt);
  }
  else
  {
    mt = abs(mt);
    analogWrite(Forward, 0);
    analogWrite(Back, mt);
  }
}

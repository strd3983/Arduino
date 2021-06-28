int sensor_01 = A0, sensor_02 = A1, sensor_03 = A2;
int LED_01 = A5, LED_02 = A4, LED_03 = 7;
int val_01, val_02, val_03;
int n = 980;

void setup()
{
  pinMode(sensor_01, INPUT);
  pinMode(sensor_02, INPUT);
  pinMode(sensor_03, INPUT);
  pinMode(LED_01, OUTPUT);
  pinMode(LED_02, OUTPUT);
  pinMode(LED_03, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  val_01 = analogRead(sensor_01);
  val_02 = analogRead(sensor_02);
  val_03 = analogRead(sensor_03);
  Serial.println(val_03);
  delay(500);

  if (val_01 < n)
  {
    if (val_02 < n)
    {
      if (val_03 < n)
      {
        digitalWrite(LED_01, HIGH);
        digitalWrite(LED_02, HIGH);
        digitalWrite(LED_03, HIGH);
      }
      else
      {
        digitalWrite(LED_01, HIGH);
        digitalWrite(LED_02, HIGH);
        digitalWrite(LED_03, LOW);
      }
    }
    else if (val_03 < n)
    {
      digitalWrite(LED_01, HIGH);
      digitalWrite(LED_02, LOW);
      digitalWrite(LED_03, HIGH);
    }
    else
    {
      digitalWrite(LED_01, HIGH);
      digitalWrite(LED_02, LOW);
      digitalWrite(LED_03, LOW);
    }
  }
  else if (val_02 < n)
  {
    if (val_03 < n)
    {
      digitalWrite(LED_01, LOW);
      digitalWrite(LED_02, HIGH);
      digitalWrite(LED_03, HIGH);
    }
    else
    {
      digitalWrite(LED_01, LOW);
      digitalWrite(LED_02, HIGH);
      digitalWrite(LED_03, LOW);
    }
  }
  else if (val_03 < n)
  {
    digitalWrite(LED_01, LOW);
    digitalWrite(LED_02, LOW);
    digitalWrite(LED_03, HIGH);
  }
  else
  {
    digitalWrite(LED_01, LOW);
    digitalWrite(LED_02, LOW);
    digitalWrite(LED_03, LOW);
  }
}

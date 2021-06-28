//フォトトランジスタ
int a = A1;
int b = A2;
int c = A3;
int d = A4;
int e = A5;


//モーター
int L_f = 9;
int L_b = 10;
int R_f = 6;
int R_b = 5;

int LMP = 50;
int RMP = 50;

void setup(){
  pinMode(L_f,OUTPUT);
  pinMode(L_b,OUTPUT);
  pinMode(R_f,OUTPUT);
  pinMode(R_b,OUTPUT);
  
  pinMode(a,INPUT); 
  pinMode(b,INPUT); 
  pinMode(c,INPUT); 
  pinMode(d,INPUT); 
  pinMode(e,INPUT);
}

void loop(){
  
  int n = 0;
  double ls = 0;

  //どのフォトで白線を読んでいるか
  if(analogRead(a) < 100){  
    ls-=2;
    n+=1;
  }
  if(analogRead(b) < 100){
    ls-=1;
    n+=1;
  }
  if(analogRead(c) < 100){
    ls=0;
    n+=1;
  }
  if(analogRead(d) < 100){
    ls+=1;
    n+=1;
  }
  if(analogRead(e) < 100){
    ls+=2;
    n+=1;
  }


  //比例制御
  int kp=20;
  int MD = kp * (ls / n);   
  
   LMP =50+MD;
   RMP =50-MD;

  //モーターを動かす関数
  driveMotor(LMP,RMP);   
  
}


//モーターを動かす関数
void driveMotor(int left,int right){

  //255は超えないようにする
  if(left>255){
    left = 255;
  }else if(left<-255){
    left = -255;
  }
  if(right>255){
    right = 255;
  }else if(right < -255){
    right = -255;
  }
  
  if(left>0){
    analogWrite(L_f,left);
    analogWrite(L_b,0);
  }else{
    left = abs(left);
    analogWrite(L_f,0);
    analogWrite(L_b,left);
  }
  if(right>0){
    analogWrite(R_f,right);
    analogWrite(R_b,0);
  }else{
    right = abs(right);
    analogWrite(R_f,0);
    analogWrite(R_b,right);
  }
}

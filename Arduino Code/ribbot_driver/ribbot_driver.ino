char data;
int datatemp;


const int servo = 6;
const int motors = 5;


const int pinCW_Left = 7;
const int pinCC_Left = 8;
const int pinSpeed_Left = 9;


const int pinSpeed_Right = 10;
const int pinCW_Right = 11;
const int pinCC_Right = 12;


void setup() {
  pinMode(servo, OUTPUT);
  pinMode(motors, OUTPUT);
  pinMode(pinCW_Left,OUTPUT);
  pinMode(pinCC_Left,OUTPUT);
  pinMode(pinSpeed_Left,OUTPUT);
  pinMode(pinCW_Right,OUTPUT);
  pinMode(pinCC_Right,OUTPUT);
  pinMode(pinSpeed_Right,OUTPUT);


  digitalWrite(pinCW_Left,LOW);
  digitalWrite(pinCC_Left,LOW);
  digitalWrite(pinCW_Right,LOW);
  digitalWrite(pinCC_Right,LOW);
  digitalWrite(motors,HIGH);


  analogWrite(pinSpeed_Right, 160);
  analogWrite(pinSpeed_Left, 160);
  analogWrite(servo, 100);
  
  Serial.begin(115200);
}


void loop() {
  if(Serial.available()) {
    data = Serial.read();
    datatemp = (int)(data - 48);
    if(datatemp == 1) {Forward();}
    if(datatemp == 2) {Reverse();}
    if(datatemp == 3) {Left();}
    if(datatemp == 4) {Right();}
    if(datatemp == 5) {Stop();}
    if(datatemp == 6) {Launch();}
    Serial.print(data, DEC);
  }
  
}


void Launch(){
  Stop();
  delay(100);
  MotorControl_ON();
  delay(500);
  BallDrop();
  delay(1000);
  MotorControl_OFF();
}


void MotorControl_ON(){
  digitalWrite(motors, LOW);
}


void MotorControl_OFF(){
  digitalWrite(motors, HIGH);
}


void BallDrop(){
  digitalWrite(servo, HIGH);
  delay(27);
  digitalWrite(servo, LOW);
}


void Forward(){
  RightCC_ON();
  RightCW_OFF();
  LeftCC_ON();
  LeftCW_OFF();
}


void Reverse(){
  RightCC_OFF();
  RightCW_ON();
  LeftCC_OFF();
  LeftCW_ON();
}


void Left(){
  RightCC_ON();
  RightCW_OFF();
  LeftCC_OFF();
  LeftCW_ON();
}


void Right(){
  RightCC_OFF();
  RightCW_ON();
  LeftCC_ON();
  LeftCW_OFF();
}


void Stop(){
  RightCC_OFF();
  RightCW_OFF();
  LeftCC_OFF();
  LeftCW_OFF();
}


void RightCC_ON(){
  digitalWrite(pinCC_Right,HIGH);
}



void RightCC_OFF(){
  digitalWrite(pinCC_Right,LOW);
}



void RightCW_ON(){
  digitalWrite(pinCW_Right,HIGH);
}



void RightCW_OFF(){
  digitalWrite(pinCW_Right,LOW);
}



void LeftCC_ON(){
  digitalWrite(pinCC_Left,HIGH);
}



void LeftCC_OFF(){
  digitalWrite(pinCC_Left,LOW);
}



void LeftCW_ON(){
  digitalWrite(pinCW_Left,HIGH);
}



void LeftCW_OFF(){
  digitalWrite(pinCW_Left,LOW);
}


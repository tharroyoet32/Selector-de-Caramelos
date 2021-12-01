#include <Servo.h>

#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6
Servo topServo;
Servo bottomServo;
int frequency = 0;
int color=0;
void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, HIGH);
  topServo.attach(10);
  bottomServo.attach(11);
  Serial.begin(9600);
}
void loop() {
  topServo.write(90);
  delay(700);
  topServo.write(10);
  color = readColor();
  delay(50);

  if(color==1){
    Serial.println("Color: Rojo");
    bottomServo.write(160);
    delay(1000);  
  }
  if(color==2){
    Serial.println("Color: Azúl");
    bottomServo.write(150);
  }
  if(color==3){
    Serial.println("Color: Verde");  
    bottomServo.write(100);
  }
  
  delay(1000);
  bottomServo.write(10);
  color = 0;
}

// Custom Function - readColor()
int readColor() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(50);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(50);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.println("  ");
  delay(50);

  if( (R>=16 && R<=21) && (G>=30 && G<=35) && (B>=19 && B<=23)){
    color = 1; // Rojo
    return color;
  } 
  if( (R>=23 && R<=27) && (G>=20 && G<=29) && (B>=10 && B<=18)){
    color = 2; // Azul
    return color;
  }
  if( (R>=16 && R<=23) && (G>=19 && G<=24) && (B>=14 && B<=19)){
    color = 3; // Verde
    return color;
  }
     
 return 0; 
}

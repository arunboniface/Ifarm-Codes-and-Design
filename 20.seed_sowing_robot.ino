
#include <Servo.h>
#include <AFMotor.h>

Servo myservo;  // create servo object to control a servo


int pos = 0;    // variable to store the servo position

int m1=29;
int m2=31;
int m3=33;
int m4=35;
int automode=23;
int seed=25;
int water=27;

#define echoPin 24 
#define trigPin 22

long duration; 
int distance;

AF_DCMotor motor(1);
AF_DCMotor motor1(2);
AF_DCMotor pump(4);



void setup() {
myservo.attach(10);  // attaches the servo on pin 9 to the servo object
myservo.write(90);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT

Serial.begin(9600);
pinMode(m1,INPUT);
pinMode(m2,INPUT);
pinMode(m3,INPUT);
pinMode(m4,INPUT);
pinMode(automode,INPUT);
pinMode(seed,INPUT);
pinMode(water,INPUT);



digitalWrite(m1,LOW);
digitalWrite(m2,LOW);
digitalWrite(m3,LOW);
digitalWrite(m4,LOW);

      
delay(3000);
motor.setSpeed(100);
motor1.setSpeed(100);
pump.setSpeed(255);

motor.run(RELEASE);
motor1.run(RELEASE);
pump.run(RELEASE);

}
void dist() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance1: ");
  Serial.print(distance);
  Serial.println(" cm");
}

void seed1(){
  myservo.write(160);  // set servo to mid-point  
  delay(2000);
  
myservo.write(20);  // set servo to mid-point  
 delay(2000);
  myservo.write(90);  // set servo to mid-point  
  delay(10);
}



void loop() {
int mode1 = digitalRead(automode);
             Serial.print("mode =");
        Serial.println(mode1);
if(mode1==1){
 
  dist();
  if(distance>5 && distance<30){
      motor.run(FORWARD);
      motor1.run(BACKWARD);       
delay(2000);
      }else{
      
      motor.run(FORWARD);
      motor1.run(FORWARD);
      delay(3000);
      motor.run(RELEASE);
      motor1.run(RELEASE);
      delay(1000);
      seed1();
      delay(2000);
      pump.run(BACKWARD);
      delay(2000);
     pump.run(RELEASE);
      }        
 
}else{
  int m11 = digitalRead(m1);
    int m12 = digitalRead(m2);
      int m13 = digitalRead(m3);
        int m14 = digitalRead(m4);
        Serial.print("m1 =");
        Serial.println(m11);
             Serial.print("m2 =");
        Serial.println(m12);
             Serial.print("m3 =");
        Serial.println(m13);
             Serial.print("m4 =");
        Serial.println(m14);
  if(m11==1 && m12==1){
    Serial.println("frwd");
    motor.run(FORWARD);
      motor1.run(FORWARD);
  }else if(m13==1 && m14==1){
     Serial.println("backwrd");
    motor.run(BACKWARD);
      motor1.run(BACKWARD);
  }
  else if(m11==1 && m13==1){
    motor.run(FORWARD);
      motor1.run(BACKWARD);
     Serial.println("left");
  }
  else if(m12==1 && m14==1){
    motor.run(BACKWARD);
      motor1.run(FORWARD);
     Serial.println("right");
  }
  else{
    Serial.println("stop");
    motor.run(RELEASE);
      motor1.run(RELEASE); 
  }

int seed2 = digitalRead(seed);
             Serial.print("seed =");
        Serial.println(seed2);
  if(seed2==1){
   // delay(1000);
    seed1();
  }
int water1 = digitalRead(water);
             Serial.print("water =");
        Serial.println(water1);
        
  if(water1==1){
    pump.run(BACKWARD);
    delay(3000);
    pump.run(RELEASE);
  }
  
}
 
}

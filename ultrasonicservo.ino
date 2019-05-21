#include <Servo.h>
Servo myservo;
int pos=0;
const int trigPin=4;
const int echoPin=5;
long duration;
long distance;

void setup() {
   pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);

 myservo.attach(13);
}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  if(distance>0&&distance<10){
    for(pos=0;pos<=180;pos++){
    myservo.write(pos);
    if(pos==90)
    delay(200);
    delay(15);
    }
    delay(2000);
    for(pos=180;pos>=0;pos--){
         myservo.write(pos);
         if(pos==90)
          delay(200);
         delay(15);  
 
       
    }
  }
  
}

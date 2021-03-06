const int trigPin=4;
const int echoPin=5;
long duration;
long distance;
void setup() {
  Serial.begin(115200);
  pinMode(2,OUTPUT);
  pinMode(16,OUTPUT);
  pinMode(18,OUTPUT);
  pinMode(19,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);

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
    digitalWrite(2,HIGH);
  }else{
    digitalWrite(2,LOW);
  }
  if(distance>10&&distance<40){
    digitalWrite(16,HIGH);
  }else{
    digitalWrite(16,LOW);
  }
  if(distance>40&&distance<60){
    digitalWrite(18,HIGH);
  }else{
    digitalWrite(18,LOW);
  }
  if(distance>60){
    digitalWrite(19,HIGH);
  }else{
    digitalWrite(19,LOW);
  }

}

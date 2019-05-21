const int trigPin=4;
const int echoPin=5;
long duration;
long distance;
void setup() {
  Serial.begin(115200);
  pinMode(2,OUTPUT);
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
  

}

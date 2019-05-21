void setup() {
  Serial.begin(115200);
  pinMode(2,OUTPUT);
  pinMode(4,INPUT);
}

void loop(){
  if(digitalRead(4)==HIGH){
    digitalWrite(2,HIGH);
    Serial.println("Person detected");
  }
  if(digitalRead(4)==LOW){
    digitalWrite(2,LOW);
    Serial.println("Person not detected");
  }

}

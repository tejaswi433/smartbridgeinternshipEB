void setup() {
  Serial.begin(115200);
  pinMode(2,OUTPUT);
  pinMode(4,INPUT);
  
}

void loop() {
  if(digitalRead(4)==LOW){
    Serial.print("switch value:");
    Serial.println(digitalRead(4));
    digitalWrite(2,HIGH);
    Serial.println("LED=HIGH");
    delay(500);
 }
  if(digitalRead(4)==HIGH){
    Serial.print("switch value:");
    Serial.println(digitalRead(4));
    Serial.println("LED=LOW");
    digitalWrite(2,LOW);
    delay(500);
 }


}

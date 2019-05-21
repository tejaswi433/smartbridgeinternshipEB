void setup() {
  pinMode(2,OUTPUT);
  pinMode(4,INPUT);
   pinMode(0,INPUT);

}

void loop() {
  
 if(digitalRead(4)==LOW){
  digitalWrite(2,HIGH);
  
 }
  if(digitalRead(0)==LOW){
  digitalWrite(2,LOW);
 }
}

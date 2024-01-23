void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(115200);
  pinMode(7, INPUT);
  pinMode(6, INPUT);
  pinMode(4, INPUT);

}
bool isPacket7Sent = false; 
bool isPacket6Sent = false; 
bool isPacket4Sent = false; 
void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == '1') {
      digitalWrite(13, HIGH);
      delay(50);
      digitalWrite(13, LOW);
      
    } else if (command == '2') {
      digitalWrite(12, HIGH);
      delay(50);
      digitalWrite(12, LOW);
    } else if (command == '3') {
      digitalWrite(11, HIGH);
      delay(50);

      digitalWrite(11, LOW);
    } 
  }
    int touchValue7 = digitalRead(7);
    int touchValue6 = digitalRead(6);
    int touchValue4 = digitalRead(4);


    if (touchValue7 == HIGH && !isPacket7Sent){
      Serial.write('1');
      isPacket7Sent = true;
    }    
    if (touchValue6 == HIGH && !isPacket6Sent){
      Serial.write('2');
      isPacket6Sent = true;

    }    
    if (touchValue4 == HIGH && !isPacket4Sent){
      Serial.write('3');
      isPacket4Sent = true;
    }
    isPacket7Sent = false;
    isPacket6Sent = false;
    isPacket4Sent = false;

}
const char* SSID = "Motorola";
const char* pass =  "sweetchilisourcream";

#include <WiFi.h>
#include <WebSocketsClient.h>
#include <M5StickC.h>

WebSocketsClient webSocket;
int vib;
int past_vib;
void setup() {
  webSocket.begin("192.168.172.162", 5001, "/");
  webSocket.onEvent(webSocketEvent);
  WiFi.begin(SSID, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi!");

  webSocket.onEvent(webSocketEvent);
  M5.begin();

  // Display setting
  M5.Lcd.setRotation(1);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextSize(5);

  // IMU & LED
  M5.IMU.Init();
  pinMode(26, OUTPUT);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.printf("output\n");
}

void loop() {
  
  if (vib > 100){
    if (vib == past_vib){
    digitalWrite(26, LOW); // led off
    }else{
    digitalWrite(26, HIGH); // led off
    delay(vib/2);
    digitalWrite(26, LOW); // led off
    delay(vib/2);
    past_vib = vib;
    }
  }

  webSocket.loop(); // Handle WebSocket events

}
void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
  switch (type) {
    case WStype_DISCONNECTED:
      Serial.println("Disconnected from WebSocket server");
      break;
    case WStype_CONNECTED:
      Serial.println("Connected to WebSocket server");
      webSocket.sendTXT("connect");
      break;
    case WStype_TEXT:
      Serial.printf("Received message: %s\n", payload);
      const char* paceString = reinterpret_cast<const char*>(payload); // cast to const char*
      int pace = atoi(paceString); // convert string to integer
      if (pace < 1000){
        vib = pace;
      }
        
      break;
  }
}

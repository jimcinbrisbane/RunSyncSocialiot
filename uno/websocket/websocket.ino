const char* SSID = "Motorola";
const char* pass =  "sweetchilisourcream";

#include <ESP8266WiFi.h>
#include <WebSocketsClient.h>

WebSocketsClient webSocket;

void setup() {
  Serial.begin(115200); // Set the baud rate for the serial monitor

  // Connect to Wi-Fi
  WiFi.begin(SSID, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to Wi-Fi...");
  }
  Serial.println("Connected to Wi-Fi.");

  // Connect to the WebSocket server
	webSocket.begin("192.168.172.162", 5000, "/");
  webSocket.onEvent(webSocketEvent);
}

void loop() {
    
    // if (command == '1') {
    //     webSocket.sendTXT("1");

      
    // } else if (command == '0') {
    //     webSocket.sendTXT("0");

    // }
  webSocket.loop(); // Handle WebSocket events
   if (Serial.available() > 0){
        char command = Serial.read();
        char message[2]; 
        message[0] = command; 
        message[1] = '\0';
        webSocket.sendTXT(message);

    }

}

void webSocketEvent(WStype_t type, uint8_t *payload, size_t length) {
  switch (type) {
    case WStype_CONNECTED:
      Serial.println("WebSocket connected.");
      webSocket.sendTXT("connected");
      break;
    case WStype_TEXT:
      Serial.print("Received message: ");
      Serial.println((char *)payload);
      if (payload[0] == '1') {
        Serial.write('1'); 
      } else if (payload[0] == '2') {
        Serial.write('2');
      } else if (payload[0] == '3') {
        Serial.write('3');
      } else if (payload[0] == '4') {
        Serial.write('4');
      } else if (payload[0] == '5') {
        Serial.write('5');
      }
      
      break;
    case WStype_DISCONNECTED:
      Serial.println("WebSocket disconnected.");
      break;
  }
}
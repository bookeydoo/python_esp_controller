#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>

#define Serv_port 4080
const char* ssid = "WALEED ESP";
const char* password = "12345678";

WiFiServer TCPserver(Serv_port);

void setup() {
    Serial.begin(9600);
    Serial.println("TCP server");

    // Connecting to the hotspot/router
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Connecting ...");
    }
    Serial.println("Connected");

    // Printing this ESP's IP address
    Serial.print("TCP server IP address: ");
    Serial.println(WiFi.localIP());

    TCPserver.begin();
}

void listAvailableNetworks() {
    int numNetworks = WiFi.scanNetworks();
    Serial.println("Available networks:");
    for (int i = 0; i < numNetworks; ++i) {
        Serial.print(WiFi.SSID(i));
        Serial.print(" (");
        Serial.print(WiFi.RSSI(i));
        Serial.println(" dBm)");
    }
}

void loop() {
  
    WiFiClient client = TCPserver.available();
    if(client) {
    
        byte command = client.read();
        Serial.print("Received a command: ");
        Serial.print(command);
        if (command == 1) {
          Serial.print("1");
          Serial.print("first command has been put to work");// for debugging

        }
        // Add more commands and code here as needed

      else if(command ==2){
        Serial.print("2");
        Serial.print("client ending");
        client.stop();
        } Serial.print("error has occured failed to connect");
    }
    }
  
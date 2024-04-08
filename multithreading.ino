//this file is a test to check if its possible to multithread on esp32 devkit wroom

#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>

#define Serv_port 4080
const char* ssid = "WE_F15C0E";
const char* password = "m4n11115";

WiFiServer TCPserver(Serv_port);

TaskHandle_t Task1;
TaskHandle_t Task2;

const int led1=5;// this one is gonna work all the time
const int led2=18;  // this one is supposed to light on if we are connected 



void setup() {
    Serial.begin(9600);
    Serial.println("TCP server");

    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    
    //first thread or task
     xTaskCreatePinnedToCore(
      Task1code,     //name of the function to do
      "task1",
      10000, //stack size
      NULL,//parameter of the task
      1,//priority of the task
      &Task1,
      0); //pinning task to first core
      
      delay(500);

      //second thread or task
      xTaskCreatePinnedToCore(
      Task2code,     //name of the function to do
      "task2",
      10000, //stack size
      NULL,//parameter of the task
      1,//priority of the task
      &Task2,
      1); //pinning task to first core
delay(500);
    
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

void Task1code( void * pvParameters ){
  Serial.print("Task1 running on core ");
  Serial.println(xPortGetCoreID());

  for(;;){
    digitalWrite(led1, HIGH);
    delay(1000);
    digitalWrite(led1, LOW);
    delay(1000);
  } 
}
void Task2code(void *pvParameters){
  Serial.print("Task 2 running on core");
  Serial.println(xPortGetCoreID());

  for(;;){
    
     // Connecting to the hotspot/router
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Connecting ...");
    }
    Serial.println("Connected");
    digitalWrite(led2,HIGH);
    delay(5000);
    digitalWrite(led2,LOW);
    delay(200);

    // Printing this ESP's IP address
    Serial.print("TCP server IP address: ");
    Serial.println(WiFi.localIP());

    TCPserver.begin();

    
    }
  }



  void loop(){}
#include "Arduino.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* host = "Esp_Bot";
const char* ssid = "freebox_LFVSZS";
const char* password = "WiFiBarcel0na2019";

uint8_t statuslediteration = 0;
//uint8_t statusledstate = ;
uint8_t statuslediterationdone = 0;
uint32_t laststatusledblink=millis();
uint32_t lastsandbyblink=millis();

IPAddress localIP(192,168,0,17);
IPAddress gateway(192,168,2,199);
IPAddress subnet(255,255,255,0);
IPAddress dns(172,100,1,1);

ESP8266WebServer server(80);
const char* serverIndex = "<a href='/left'>LEFT</a><br><a href='/right'>RIGHT</a><br><a href='/forward'>FORWARD</a><br><a href='/reward'>REWARD</a>";

unsigned char PIN_HBRIDGE_1A = 1; //9
unsigned char PIN_HBRIDGE_2A = 2; //6
unsigned char PIN_HBRIDGE_3A = 3; //5
unsigned char PIN_HBRIDGE_4A = 4; //3

void MotorLeftStop()
{
  digitalWrite(PIN_HBRIDGE_1A, LOW);
  digitalWrite(PIN_HBRIDGE_2A, LOW);
}
 
void MotorPIN_HBRIDGE_1Aard()
{
  digitalWrite(PIN_HBRIDGE_1A, HIGH);
  digitalWrite(PIN_HBRIDGE_2A, LOW);
}
 
void MotorLeftReverse()
{
  digitalWrite(PIN_HBRIDGE_1A, LOW);
  digitalWrite(PIN_HBRIDGE_2A, HIGH);
}
 
void MotorRightStop()
{
  digitalWrite(PIN_HBRIDGE_3A, LOW);
  digitalWrite(PIN_HBRIDGE_4A, LOW);
}
 
void MotorPIN_HBRIDGE_3Aard()
{
  digitalWrite(PIN_HBRIDGE_3A, LOW);
  digitalWrite(PIN_HBRIDGE_4A, HIGH);
}
 
void MotorRightReverse()
{
  digitalWrite(PIN_HBRIDGE_3A, HIGH);
  digitalWrite(PIN_HBRIDGE_4A, LOW);
}

void init_WiFi(){
  WiFi.config(localIP, gateway, subnet, dns);
  delay(100);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
}

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Booting Sketch...");
  init_WiFi();
  if(WiFi.waitForConnectResult() == WL_CONNECTED){
    digitalWrite(LED_BUILTIN, HIGH);
    MDNS.begin(host);
    server.on("/", HTTP_GET, [](){
      server.sendHeader("Connection", "close");
      server.sendHeader("Access-Control-Allow-Origin", "*");
      server.send(200, "text/html", serverIndex);
    });
    server.on("/left", HTTP_GET, [](){
      digitalWrite(PIN_HBRIDGE_1A,LOW);
      digitalWrite(PIN_HBRIDGE_4A,LOW);
      delay(500);
      digitalWrite(PIN_HBRIDGE_1A,HIGH);
      digitalWrite(PIN_HBRIDGE_4A,HIGH);
      server.sendHeader("Connection", "close");
      server.sendHeader("Access-Control-Allow-Origin", "*");
      server.send(200, "text/html", serverIndex);
    });
    server.on("/right", HTTP_GET, [](){
      digitalWrite(PIN_HBRIDGE_2A,LOW);
      digitalWrite(PIN_HBRIDGE_3A,LOW);
      delay(500);
      digitalWrite(PIN_HBRIDGE_2A,HIGH);
      digitalWrite(PIN_HBRIDGE_3A,HIGH);
      server.sendHeader("Connection", "close");
      server.sendHeader("Access-Control-Allow-Origin", "*");
      server.send(200, "text/html", serverIndex);
    });
    server.on("/forward", HTTP_GET, [](){
      digitalWrite(PIN_HBRIDGE_1A,LOW);
      digitalWrite(PIN_HBRIDGE_3A,LOW);
      delay(2000);
      digitalWrite(PIN_HBRIDGE_1A,HIGH);
      digitalWrite(PIN_HBRIDGE_3A,HIGH);
      server.sendHeader("Connection", "close");
      server.sendHeader("Access-Control-Allow-Origin", "*");
      server.send(200, "text/html", serverIndex);
    });
    server.on("/reward", HTTP_GET, [](){
      digitalWrite(PIN_HBRIDGE_2A,LOW);
      digitalWrite(PIN_HBRIDGE_4A,LOW);
      delay(2000);
      digitalWrite(PIN_HBRIDGE_2A,HIGH);
      digitalWrite(PIN_HBRIDGE_4A,HIGH);
      server.sendHeader("Connection", "close");
      server.sendHeader("Access-Control-Allow-Origin", "*");
      server.send(200, "text/html", serverIndex);
    });
    server.begin();
    MDNS.addService("http", "tcp", 80);
    Serial.print("Ready on ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("WiFi Failed");
  }
}


void loop() {
    server.handleClient();
    delay(1);
  }
  

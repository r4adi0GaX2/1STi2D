#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#include <SparkFun_RHT03.h>

const char* ssid = "Bbox-ACAA01";
const char* password = "5567C13A7A";

const int RHT03_DATA_PIN = D4;

ESP8266WebServer server(80);

const int led = 13;

RHT03 rht;

void sensor();

float latestHumidity = rht.humidity();
float latestTempC = rht.tempC();
float latestTempF = rht.tempF();

void setup(void) {
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);

  server.on("/inline", []() {
    server.send(200, "text/plain", "this works as well");
  });

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");

  rht.begin(RHT03_DATA_PIN);
}

void loop(void) {
  server.handleClient();

  sensor() ;
}

void sensor() {
  int updateRet = rht.update();

  if (updateRet == 1)
  {
   
    float latestHumidity = rht.humidity();
    float latestTempC = rht.tempC();
    float latestTempF = rht.tempF();

    //Serial.println("Humidity: " + String(latestHumidity, 1) + " %");
    //Serial.println("Temp (F): " + String(latestTempF, 1) + " deg F");
    //Serial.println("Temp (C): " + String(latestTempC, 1) + " deg C");
    server.send(200, "text/plain","Temp: " + String(latestTempC, 1) + " ºC" + "   " + "Humidity: " + String(latestHumidity, 1) + " %");
    
  }
  else
  {
    
    delay(RHT_READ_INTERVAL_MS);
  }

  delay(1000);

}

void handleRoot() {
  digitalWrite(led, 1);
  //server.send(200, "text/plain", "Temp (C): " + String(latestTempC, 1) + " deg C");
  digitalWrite(led, 0);
}

void handleNotFound() {
  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  digitalWrite(led, 0);
}

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <IPAddress.h>
#include <EEPROM.h>
 
//WIFI CONFIG
const char* ssid = "Cisco68896";
const char* password = "elperrococoliso";

MDNSResponder mdns;

//GPIO
const int gpio0 = 0;
const int gpio2 = 2;

//set static local ip /port
IPAddress ip = IPAddress(192,168,2,115);
IPAddress gateway = IPAddress(192,168,2,2);
IPAddress subnet = IPAddress(255,255,255,0);
int port = 1000;


//control de apagado
int segundosON;
unsigned long lastON = 0;

//START WEB SERVER
ESP8266WebServer server(port);
 
void setup(void){
  pinMode(gpio0, OUTPUT);
  digitalWrite(gpio0, 0);
  pinMode(gpio2, OUTPUT);
  digitalWrite(gpio2, 0);
  Serial.begin(115200);
  delay(10);
  EEPROM.begin(512);
  delay(10);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
    Serial.print("Seteando IP estatica: ");
  //set static ip part
  WiFi.config(ip,gateway,subnet);
   Serial.println(WiFi.localIP());
  
  if (mdns.begin("esp8266", WiFi.localIP())) {
    Serial.println("MDNS responder started");
  }
  
  processURLs();
  
  server.on("/", handleRoot);
  
  server.onNotFound(handleNotFound);
  
  server.begin();
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();
  checkeaApagado();
  getSegundosON();
} 

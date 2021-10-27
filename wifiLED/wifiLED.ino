#include <ESP8266WiFi.h> 
#include "DHT.h"
#define DHTPIN D1
#define LEDPIN D2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "201312405"; 
const char* password = "like1111";
WiFiServer server(80);

void setup() {
  Serial.begin(115200); delay(100); 
  Serial.println();
  Serial.print("CONNECTING TO ");
  Serial.println(ssid); 
  WiFi.begin(ssid, password);
  dht.begin();
  
  while(WiFi.status() != WL_CONNECTED){
  delay(500); Serial.print(".");
  } 
  Serial.println(); 
  Serial.println("Wifi connected!");

  server.begin();
  Serial.println("HTTP server started");
  Serial.print("Use this URL : ");
  Serial.print(WiFi.localIP());
  Serial.print("/");
  Serial.println("");
  pinMode(LEDPIN, OUTPUT);
  } 

  
void LedOnOff(String req, WiFiClient client){
  if(req.indexOf("/ledOn") != -1){
    digitalWrite(LEDPIN, HIGH);
    Serial.println("LED ON");
    Serial.println("#######");
    client.flush();
  } else if(req.indexOf("/ledOff") != -1){
    digitalWrite(LEDPIN, LOW);
    Serial.println("LED OFF");
    Serial.println("#######");
    client.flush();
  }else{
    Serial.println(req);
  }
}


void loop() {
  WiFiClient client = server.available();

  if(!client){
    return;
  }
  
  Serial.println("new client");
  
  while(!client.available()){
    delay(1);
  }

  String request = client.readStringUntil('\r');
  LedOnOff(request, client);
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connection: clolse");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<meta http-equiv=\"refresh\"content=\"5\">");
  client.println("<body>");
  client.println("Hello NodeMCU World <br>");
  client.println("Temperature : ");
  client.println(t);
  client.println("<br>");
  client.println("Humidity (%): ");
  client.println(h);
  client.println("<br>");
  client.println("<a href=/ledOn><button>LED ON</button></a>");
  client.println("<a href=/ledOff><button>LED OFF</button></a>");
  client.println("</body>");
  client.println("</html>");
}

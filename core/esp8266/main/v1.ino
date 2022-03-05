//
//// Import required libraries
//#include <ESP8266WiFi.h>
//#include <ESPAsyncTCP.h>
//#include <ESPAsyncWebServer.h>
//#include <FS.h>
//#include <Wire.h>
//
//// Replace with your network credentials
//const char* ssid = "RRE network";
//const char* password = "R5+8*YLZf-";
//
//// Set LED GPIO
//const int ledPin = 2;
//// Stores LED state
//String ledState;
//
//// Create AsyncWebServer object on port 80
//AsyncWebServer server(80);
//
//String getTemperature() {
//  float temperature = 12;
//  // Read temperature as Fahrenheit (isFahrenheit = true)
//  //float temperature = 1.8 * bme.readTemperature() + 32;
//  Serial.println(temperature);
//  return String(temperature);
//}
//  
//String getHumidity() {
//  float humidity = 13;
//  Serial.println(humidity);
//  return String(humidity);
//}
//
//String getPressure() {
//  float pressure = 400 / 100.0F;
//  Serial.println(pressure);
//  return String(pressure);
//}
//
//// Replaces placeholder with LED state value
//String processor(const String& var){
//  Serial.println(var);
//  if(var == "STATE"){
//    if(digitalRead(ledPin)){
//      ledState = "ON";
//    }
//    else{
//      ledState = "OFF";
//    }
//    Serial.print(ledState);
//    return ledState;
//  }
//  else if (var == "TEMPERATURE"){
//    return getTemperature();
//  }
//  else if (var == "HUMIDITY"){
//    return getHumidity();
//  }
//  else if (var == "PRESSURE"){
//    return getPressure();
//  }  
//}
// 
//void setup(){
//  // Serial port for debugging purposes
//  Serial.begin(115200);
//  // pinMode(ledPin, OUTPUT);
//  Serial.println("WORKING :)");
//  // Initialize SPIFFS
//  if(!SPIFFS.begin()){
//    Serial.println("An Error has occurred while mounting SPIFFS");
//    return;
//  }
//
//  // Connect to Wi-Fi
//  WiFi.begin(ssid, password);
//  while (WiFi.status() != WL_CONNECTED) {
//    delay(1000);
//    Serial.println("Connecting to WiFi..");
//  }
//
//  // Print ESP32 Local IP Address
//  Serial.println(WiFi.localIP());
//
//  // Route for root / web page
//  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
//    request->send(SPIFFS, "/index.html", String(), false, processor);
//  });
//  
//  // Route to load style.css file
//  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
//    request->send(SPIFFS, "/style.css", "text/css");
//  });
//
//  // Route to set GPIO to HIGH
//  server.on("/on", HTTP_GET, [](AsyncWebServerRequest *request){
//    // digitalWrite(ledPin, HIGH);    
//    request->send(SPIFFS, "/index.html", String(), false, processor);
//  });
//  
//  // Route to set GPIO to LOW
//  server.on("/off", HTTP_GET, [](AsyncWebServerRequest *request){
//    // digitalWrite(ledPin, LOW);    
//    request->send(SPIFFS, "/index.html", String(), false, processor);
//  });
//
//  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
//    request->send_P(200, "text/plain", getTemperature().c_str());
//  });
//  
//  server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest *request){
//    request->send_P(200, "text/plain", getHumidity().c_str());
//  });
//  
//  server.on("/pressure", HTTP_GET, [](AsyncWebServerRequest *request){
//    request->send_P(200, "text/plain", getPressure().c_str());
//  });
//
//  // Start server
//  server.begin();
//}
// 
//void loop(){
//  
//}

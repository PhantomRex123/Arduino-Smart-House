///**
//* @file main.ino
//* @author Ryan Samaeian (ry.samaeian@gmail.com)
//* @brief Main file for maneging esp8266
//* @version 0.1
//* @date 2022-02-28
//*
//* @copyright Copyright (c) 2022
//*
//*/
//#include "credits.h"
//#include <ESP8266WiFi.h>
//#include <WiFiClient.h>
//#include <ESP8266WebServer.h>
//#include <ESP8266mDNS.h>
//#include <ArduinoJson.h>
//#include <strTools.h> //from LC_basetools library
//#include <stdio.h>
//#include <stdlib.h>
//#include <NTPClient.h>
//#include <ESP8266WiFi.h>
//#include <WiFiUdp.h>
//#include "LittleFS.h"
//
//const char *ssid = STASSID;
//const char *pass = STAPSK;
//String uname = STUNAME;
//String upass = STUOASS;
//
//String stat[2][6][2] = {
//   {
//       {"RELAY1", "on"},
//       {"RELAY2", "on"},
//   },
//   {
//       {"PLANTMOIST", "on"},
//       {"MOISTION", "on"},
//       {"CLAP=1", "on"},
//       {"ESPCAM=1", "on"},
//   }};
//IPAddress local_IP(192, 168, 4, 22);
//IPAddress gateway(192, 168, 4, 9);
//IPAddress subnet(255, 255, 255, 0);
//
//ESP8266WebServer server(80);
//
//void serverRouting();
//
//void setup()
//{
// delay(5000); // Not required just some delay time
// Serial.begin(115200);
// WiFi.mode(WIFI_AP_STA); // https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/readme.html#station
// WiFi.begin(ssid, pass);
//
// while (WiFi.status() != WL_CONNECTED)
// {
//   delay(500);
//   Serial.println("=");
// }
//
// Serial.println("");
// Serial.print("Connected to ");
// Serial.println(ssid);
// Serial.print("With IP: ");
// Serial.println(WiFi.localIP());
//
// Serial.println("Setting soft-ap configs... ");
// WiFi.softAPConfing(local_IP, gateway, subnet);
// Serial.println(WiFi.softAP("RRE home", STUOASS) ? "Ready" : "Fail");
// Serial.println(WiFi.softAPIP());
// serverRouting();
////  server.collectHeaders("User-Agent", "Cookie");
// server.begin();
// timeClient.begin();
// Serial.println("HTTP server started");
//}
//
///**
//* @brief Set the Cross Origin object
//*
//* @version 0.1
//* @author Ryan Samaeian (ry.samaeian@gmail.com)
//* @date 2022-03-01
//* @copyright Copyright (c) 2022
//*/
//void setCrossOrigin()
//{
// server.sendHeader(F("Access-Control-Allow-Origin"), F("*"));
// server.sendHeader(F("Access-Control-Max-Age"), F("600"));
// server.sendHeader(F("Access-Control-Allow-Methods"), F("PUT,POST,GET,OPTIONS"));
// server.sendHeader(F("Access-Control-Allow-Headers"), F("*"));
//};
//
///**
//* @brief Server routing
//*
//* @version 0.1
//* @author Ryan Samaeian (ry.samaeian@gmail.com)
//* @date 2022-03-01
//* @copyright Copyright (c) 2022
//*/
//void serverRouting() {
//     server.onNotFound(handleNotFound);
//     // All web page locations
//     server.on("/", handleRoot);
//    server.on("/api", handleApi)
//}
//
///**
//* @brief Load data from EEProm
//*
//* @param path
//* @param dataType
//* @return true
//* @return false
//* @version 0.1
//* @author Ryan Samaeian (ry.samaeian@gmail.com)
//* @date 2022-03-01
//* @copyright Copyright (c) 2022
//*/
//bool loadFromLittleFS(String path, String dataType)
//{
// Serial.print("Requested page -> ");
// Serial.println(path);
// if (LittleFS.exists(path))
// {
//   File dataFile = LittleFS.open(path, "r");
//   if (!dataFile)
//   {
//     handleNotFound();
//     return false;
//   }
//
//   if (server.streamFile(dataFile, dataType) != dataFile.size())
//   {
//     Serial.println("Sent less data than expected!");
//   }
//   else
//   {
//     Serial.println("Page served!");
//   }
//
//   dataFile.close();
// }
// else
// {
//   handleNotFound();
//   return false;
// }
// return true;
//}
//
///**
//* @brief Get the Content Type object
//*
//* @param filename
//* @return String
//* @version 0.1
//* @author Ryan Samaeian (ry.samaeian@gmail.com)
//* @date 2022-03-01
//* @copyright Copyright (c) 2022
//*/
//String getContentType(String filename)
//{
// if (filename.endsWith(F(".htm")))
//   return F("text/html");
// else if (filename.endsWith(F(".html")))
//   return F("text/html");
// else if (filename.endsWith(F(".css")))
//   return F("text/css");
// else if (filename.endsWith(F(".js")))
//   return F("application/javascript");
// else if (filename.endsWith(F(".json")))
//   return F("application/json");
// else if (filename.endsWith(F(".png")))
//   return F("image/png");
// else if (filename.endsWith(F(".gif")))
//   return F("image/gif");
// else if (filename.endsWith(F(".jpg")))
//   return F("image/jpeg");
// else if (filename.endsWith(F(".jpeg")))
//   return F("image/jpeg");
// else if (filename.endsWith(F(".ico")))
//   return F("image/x-icon");
// else if (filename.endsWith(F(".xml")))
//   return F("text/xml");
// else if (filename.endsWith(F(".pdf")))
//   return F("application/x-pdf");
// else if (filename.endsWith(F(".zip")))
//   return F("application/x-zip");
// else if (filename.endsWith(F(".gz")))
//   return F("application/x-gzip");
// return F("text/plain");
//}
//
///**
//* @brief Read files
//*
//* @param path
//* @return true
//* @return false
//* @version 0.1
//* @author Ryan Samaeian (ry.samaeian@gmail.com)
//* @date 2022-03-01
//* @copyright Copyright (c) 2022
//*/
//bool handleFileRead(String path)
//{
// Serial.print(F("handleFileRead: "));
// Serial.println(path);
//
// if (!request->authenticate(www_username, www_password))
// {
//   Serial.print(F("NOT AUTHENTICATE!"));
//   request->requestAuthentication();
// }
//
// if (path.endsWith("/"))
//   path += F("index.html");                 // If a folder is requested, send the index file
// String contentType = getContentType(path); // Get the MIME type
// String pathWithGz = path + F(".gz");
// if (LittleFS.exists(pathWithGz) || LittleFS.exists(path))
// { // If the file exists, either as a compressed archive, or normal
//   bool gzipped = false;
//
//   if (LittleFS.exists(pathWithGz))
//   {                   // If there's a compressed version available
//     path += F(".gz"); // Use the compressed version
//     gzipped = true;
//   }
//   AsyncWebServerResponse *response = request->beginResponse(LittleFS, path, contentType);
//   if (gzipped)
//   {
//     response->addHeader("Content-Encoding", "gzip");
//   }
//   Serial.print("Real file path: ");
//   Serial.println(path);
//
//   request->send(response);
//
//   return true;
// }
// Serial.println(String(F("\tFile Not Found: ")) + path);
// return false; // If the file doesn't exist, return false
//}
///**
//* @brief Allows option to toggle on and off enable/disable sensors
//*
//* @version 2.0.1
//* @author Ryan Samaeian (ry.samaeian@gmail.com)
//* @date 2022-02-28
//* @copyright Copyright (c) 2022
//*/
//void handleOption()
//{
// String postBody = server.arg("plain");
// Serial.println(postBody);
// setCrossOrigin();
//
// DynamicJsonDocument doc(1024);
// DeserializationError error = deserializeJson(doc, postBody);
//
// if (error)
// {
//   // if the file didn't open, print an error:
//   Serial.print(F("Error parsing JSON "));
//   Serial.println(error.c_str());
//
//   String msg = error.c_str();
//
//   server.send(400, F("text/html"),
//               "Error in parsin json body! <br>" + msg);
// }
// else
// {
//   JsonObject postObj = doc.as<JsonObject>();
//
//   Serial.print(F("HTTP Method: "));
//   Serial.println(server.method());
//
//   if (server.method() == HTTP_POST)
//   {
//     if (postObj.containsKey("name") && postObj.containsKey("value"))
//     {
//       char *Vname = NULL;
//       char *value = NULL;
//       Serial.println(F("done."));
//       heapStr(&Vname, doc["name"]);
//       heapStr(&value, doc["value"]);
//       Serial.println(String(Vname) + " " + String(value));
//       //        if (moist == "plantMoist")
//       //        {
//       //          stat[1][0][1] = doc["value"];
//       //        }
//
//       //        if (motion == "motionOption")
//       //        {
//       //          stat[1][1][1] = doc["value"];
//       //        }
//       //
//       //        if (clap == "clap")
//       //        {
//       //          stat[1][2][1] = doc["value"];
//       //        }
//       //
//       //        if (espcam == "espcam")
//       //        {
//       //          stat[1][3][1] = doc["value"];
//       //        }
//
//       doc["status"] = "OK";
//
//       Serial.print(F("Stream..."));
//       String buf;
//       serializeJson(doc, buf);
//
//       server.send(201, F("application/json"), buf);
//       Serial.print(F("done."));
//     }
//     else
//     {
//       DynamicJsonDocument doc(512);
//       doc["status"] = "KO";
//       doc["message"] = F("No data found, or incorrect!");
//
//       Serial.print(F("Stream..."));
//       String buf;
//       serializeJson(doc, buf);
//
//       server.send(400, F("application/json"), buf);
//       Serial.print(F("done."));
//     }
//   }
// }
//}
//
///**
//* @brief If its the first time a user has joined the site it will create a set of cookies to validate sensor activity
//* @todo make this sync with relay values
//* @deprecated No reason to use cookies in the first place
//* @version 0.1
//* @author Ryan Samaeian (ry.samaeian@gmail.com)
//* @date 2022-02-28
//* @copyright Copyright (c) 2022
//*/
//// void defaultCheck()
//// {
////   String cookie = server.header("Cookie");
////   if (!cookie.indexOf("RELAY1") != -1)
////   {
////     server.sendHeader("Set-Cookie", "PLANTMOIST=1");
////     server.sendHeader("Set-Cookie", "MOISTION=1");
////     server.sendHeader("Set-Cookie", "CLAP=1");
////     server.sendHeader("Set-Cookie", "ESPCAM=1");
////   }
//// }
////
//
///**
//* @brief Return's a HTTP response of sensor values, activity, timers etc.
//* @todo start timer
//* @version 0.1
//* @author Ryan Samaeian (ry.samaeian@gmail.com)
//* @date 2022-02-28
//* @copyright Copyright (c) 2022
//*/
//void handleStat()
//{
// DynamicJsonDocument doc(512);
// setCrossOrigin();
//
// doc["ip"] = WiFi.localIP().toString();
// doc["gw"] = WiFi.gatewayIP().toString();
// doc["nm"] = WiFi.subnetMask().toString();
// doc["stat"]["relay1"] = stat[0][0][1];
// doc["stat"]["relay2"] = stat[0][1][1];
// doc["options"]["plantmoistOption"] = stat[1][0][1];
// doc["options"]["motionOption"] = stat[1][1][1];
// doc["options"]["clap"] = stat[1][2][1];
// doc["options"]["espcam"] = stat[1][3][1];
//
// Serial.print(F("Stream..."));
// String buf;
// serializeJson(doc, buf);
// server.send(200, F("application/json"), buf);
// Serial.print(F("done."));
//}
//
///**
//* @brief Allows users to disable / enable sensors
//* @todo allow disability at a certain time: 5:04PM
//* @version 0.1
//* @author Ryan Samaeian (ry.samaeian@gmail.com)
//* @date 2022-02-28
//* @copyright Copyright (c) 2022
//*/
//void handleSettings()
//{
// if (checkAuth())
// {
//   String content;
//   if (server.hasArg("moist") && server.hasArg("motion") && server.hasArg("clap") && server.hasArg("espcam"))
//   {
//     Serial.println(server.args());
//     content = "<html><span>server.args()</span><br>";
//     content = "Woops ! Didn't catch that. Try again</html>";
//     server.send(200, "text/html", content);
//     return;
//   }
//   content += "<input type='checkbox' id='moist' name='moist' value='Moisture'>";
//   content += "<label for='moist'>Plant Moisture</label><br>";
//   content += "<input type='checkbox' id='motion' name='motion' value='MotionSensor'>";
//   content += "<label for='motion'>Motion sensor</label><br>";
//   content += "<input type='checkbox' id='clap' name='clap' value='clapping'>";
//   content += "<label for='clap'>Microphone - Clapping functionality</label><br><br>";
//   content += "<input type='checkbox' id='espcam' name='espcam' value='clapping'>";
//   content += "<label for='espcam'>Esp32 Web cam</label><br><br>";
//   content += "<input type='submit' name='submit' value='Submit'>";
//   server.send(200, "text/html", content);
//   return;
// }
// server.sendHeader("Location", "/login");
// server.sendHeader("Cache-Control", "no-cache");
// server.send(301);
//}
//
///**
//* @brief Checks if user is logged in
//* @todo more security
//* @return true
//* @return false
//* @version 0.1
//* @author Ryan Samaeian (ry.samaeian@gmail.com)
//* @date 2022-02-28
//* @copyright Copyright (c) 2022
//*/
//bool checkAuth()
//{
// if (server.hasHeader("Cookie"))
// {
//   Serial.print("Found cookie: ");
//   String cookie = server.header("Cookie");
//   Serial.println(cookie);
//   if (cookie.indexOf("ESPSESSIONID=1") != -1)
//   {
//     Serial.println("Authentication Successful");
//     return true;
//   }
// }
// Serial.println("Authentication Failed");
// return false;
//}
//
///**
//* @brief Let user login
//* @todo add this to the api . login via paplication. 2. Dynamic username password 3. Session control
//* @version 0.1
//* @author Ryan Samaeian (ry.samaeian@gmail.com)
//* @date 2022-02-28
//* @copyright Copyright (c) 2022
//*/
//void handleLogin()
//{
// String msg;
// if (server.hasHeader("Cookie"))
// {
//   Serial.print("Found cookie: ");
//   String cookie = server.header("Cookie");
//   Serial.println(cookie);
// }
// if (server.hasArg("DISCONNECT"))
// {
//   server.sendHeader("Location", "/login");
//   server.sendHeader("Cache-control", "no-cache");
//   server.sendHeader("Set-cookie", "ESPSESSIONID=0");
//   server.send(301);
//   return;
// }
//
// if (server.hasArg("USERNAME") && server.hasArg("PASSWORD"))
// {
//   if (server.arg("USERNAME") == uname && server.arg("PASSWORD") == upass)
//   {
//     server.sendHeader("Location", "/");
//     server.sendHeader("Cache-Control", "no-cache");
//     server.sendHeader("Set-Cookie", "ESPSESSIONID=1"); // set the ESP cookie
//     server.send(301);
//     Serial.println("Log in Successful");
//     return;
//   }
//   msg = "Wrong username/password! try again.";
//   Serial.println("Log in Failed");
// }
//
// String content = "<html><body><form action='/login' method='POST'>To log in, please use : admin/admin<br>";
// content += "User:<input type='text' name='USERNAME' placeholder='user name'><br>";
// content += "Password:<input type='password' name='PASSWORD' placeholder='password'><br>";
// content += "<input type='submit' name='SUBMIT' value='Submit'></form>" + msg + "<br>";
// content += "You also can go <a href='/inline'>here</a></body></html>";
// server.send(200, "text/html", content);
//}
//
///**
//* @brief For logged in users
//* @todo work on!
//* @version 0.1
//* @author Ryan Samaeian (ry.samaeian@gmail.com)
//* @date 2022-02-28
//* @copyright Copyright (c) 2022
//*/
//void handleRoot()
//{
// //  defaultCheck();
// if (checkAuth())
// {
//   String content = "<html><body><H2>hello, you successfully connected to esp8266!</H2><br>";
//   if (server.hasHeader("User-Agent"))
//   {
//     content += "the user agent used is : " + server.header("User-Agent") + "<br><br>";
//   }
//   content += "You can access this page until you <a href=\"/login?DISCONNECT=YES\">disconnect</a></body></html>";
//   server.send(200, "text/html", content);
//   return;
// }
// server.sendHeader("Location", "/login");
// server.sendHeader("Cache-Control", "no-cache");
// server.send(301);
//}
//
///**
//* @brief similar to a 404 page.
//* @todo make it more dynamic
//* @version 0.1
//* @author Ryan Samaeian (ry.samaeian@gmail.com)
//* @date 2022-02-28
//* @copyright Copyright (c) 2022
//*/
//void handleNotFound()
//{
// String message = "File Not Found\n\n";
// message += "URI: ";
// message += server.uri();
// message += "\nMethod: ";
// message += (server.method() == HTTP_GET) ? "GET" : "POST";
// message += "\nArguments: ";
// message += server.args();
// message += "\n";
// for (uint8_t i = 0; i < server.args(); i++)
// {
//   message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
// }
// server.send(404, "text/plain", message);
//}
//
//void loop(void)
//{
// timeClient.update();
// server.handleClient();
//
// if (minutes - timeClient.getMinutes() == 50000)
// {
//   Serial.println("5 minutes");
// }
//}
//
//
//


// #include "Arduino.h"
// #include "credits.h"
// #include <ESP8266WiFi.h>
// #include <WiFiClient.h>
// #include <ESP8266WebServer.h>
// #include <ESP8266mDNS.h>
// #include <ArduinoJson.h>
// #include <strTools.h> //from LC_basetools library
// #include <stdio.h>
// #include <stdlib.h>
// //#include <SoftwareSerial.h>
// #include "LittleFS.h"
// #define EspSerial Serial1

// String stat[2][6][2] = {
//     {
//         {"OPTIONPLANTMOIST", "on"},
//         {"OPTIONMOISTION", "on"},
//         {"OPTIONCLAP", "on"},
//         {"OPTIONESPCAM", "on"},
//     },
//     {
//         {"RELAY1", "off"},
//         {"RELAY2", "off"},
//         {"PLANTMOIST", "1230"},
//     }};

// IPAddress local_IP(192, 168, 4, 22);
// IPAddress gateway(192, 168, 4, 9);
// IPAddress subnet(255, 255, 255, 0);
// const char *ssid = STASSID;
// const char *password = STAPSK;
// const byte numChars = 32;
// char relay1[numChars] = {0};
// char relay2[numChars] = {0};
// char plantMoist[numChars] = {0};
// char receivedChars[numChars];
// char receivedCharsRelay[numChars];
// char tempChars[numChars];
// char tempCharsRelay[numChars];
// boolean newData, newDataRelay;
// boolean relay1Status = false;
// boolean relay2Status = false;
// ESP8266WebServer server(80);
// //SoftwareSerial EspSerial(2, 3);

// // =====================================================================

// //
// //
// // SERIAL COMMUNICATION CENTER
// // THIS IS USED TO COMMUNICATE WITH THIS DUE AND GET THE REQUIRED VALUE
// //
// //

// /**
//  * @brief Get the end of the serial object <content>
//  *
//  * @version 0.1
//  * @author Ryan Samaeian (ry.samaeian@gmail.com)
//  * @date 2022-03-03
//  * @copyright Copyright (c) 2022
//  */
// void recvWithStartEndMarkers()
// {
//   static boolean recvInProgress = false;
//   static byte ndx = 0;
//   char startMarker = '<';
//   char endMarker = '>';
//   char rc;

//   while (Serial.available() > 0 && newData == false)
//   {
//     rc = Serial.read();

//     if (recvInProgress == true)
//     {
//       if (rc != endMarker)
//       {
//         receivedChars[ndx] = rc;
//         ndx++;
//         if (ndx >= numChars)
//         {
//           ndx = numChars - 1;
//         }
//       }
//       else
//       {
//         receivedChars[ndx] = '\0'; // terminate the string
//         recvInProgress = false;
//         ndx = 0;
//         newData = true;
//       }
//     }

//     else if (rc == startMarker)
//     {
//       recvInProgress = true;
//     }
//   }
// }

// /**
//  * @brief Get the values recvWithStartEndMarker()
//  *
//  * @version 0.1
//  * @author Ryan Samaeian (ry.samaeian@gmail.com)
//  * @date 2022-03-03
//  * @copyright Copyright (c) 2022
//  */
// void parseData()
// {                   // split the data into its parts
//   char *strtokIndx; // this is used by strtok() as an index

//   strtokIndx = strtok(tempChars, ","); // get the first part - the string
//   strcpy(relay1, strtokIndx);          // convert this part to an integer

//   strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
//   strcpy(relay2, strtokIndx);     // convert this part to an integer

//   strtokIndx = strtok(NULL, ",");
//   strcpy(plantMoist, strtokIndx); // convert this part to a float
// }

// /**
//  * @brief Set parsed information
//  *
//  * @version 0.1
//  * @author Ryan Samaeian (ry.samaeian@gmail.com)
//  * @date 2022-03-03
//  * @copyright Copyright (c) 2022
//  */
// void showParsedData()
// {
//   stat[1][0][1] = String(relay1);
//   stat[1][1][1] = String(relay2);
//   stat[1][2][1] = String(plantMoist);
// }
// // =====================================================================

// //
// //
// // API SECETION
// // EVERYTHING RELATED TO THE ARDUINOS API WILL BE IN THIS SECTION
// //
// //

// /**
//  * @brief Set the Cross Origin object
//  *
//  * @version 0.1
//  * @author Ryan Samaeian (ry.samaeian@gmail.com)
//  * @date 2022-03-03
//  * @copyright Copyright (c) 2022
//  */
// void setCrossOrigin()
// {
//   server.sendHeader(F("Access-Control-Allow-Origin"), F("*"));
//   server.sendHeader(F("Access-Control-Max-Age"), F("600"));
//   server.sendHeader(F("Access-Control-Allow-Methods"), F("PUT,POST,GET,OPTIONS"));
//   server.sendHeader(F("Access-Control-Allow-Headers"), F("*"));
// };

// /**
//  * @brief Set the Json Value object
//  *
//  * @param err
//  * @return DynamicJsonDocument
//  * @version 0.1
//  * @author Ryan Samaeian (ry.samaeian@gmail.com)
//  * @date 2022-03-03
//  * @copyright Copyright (c) 2022
//  */
// DynamicJsonDocument setJsonValue(String err)
// {
//   DynamicJsonDocument doc(512);
//   doc["status"] = "ERROR";
//   doc["message"] = err;

//   Serial.print(F("Stream..."));
//   String buf;
//   return doc;
// }

// /**
//  * @brief Set the Api object
//  *
//  * @version 0.1
//  * @author Ryan Samaeian (ry.samaeian@gmail.com)
//  * @date 2022-03-03
//  * @copyright Copyright (c) 2022
//  */
// void getApi()
// {
//   setCrossOrigin();
//   DynamicJsonDocument doc(512);
//   setCrossOrigin();

//   doc["ip"] = WiFi.localIP().toString();
//   doc["gw"] = WiFi.gatewayIP().toString();
//   doc["nm"] = WiFi.subnetMask().toString();
//   doc["options"]["plantmoistOption"] = stat[0][0][1];
//   doc["options"]["motionOption"] = stat[0][1][1];
//   doc["options"]["clap"] = stat[0][2][1];
//   doc["options"]["espcam"] = stat[0][3][1];
//   doc["stat"]["relay1"] = stat[1][0][1];
//   doc["stat"]["relay2"] = stat[1][1][1];
//   doc["stat"]["plantMoist"] = stat[1][2][1];

//   Serial.print(F("Stream..."));
//   String buf;
//   serializeJson(doc, buf);
//   server.send(200, F("application/json"), buf);
//   Serial.print(F("done."));
// }

// /**
//  * @brief Set the Api object
//  *
//  * @version 0.1
//  * @author Ryan Samaeian (ry.samaeian@gmail.com)
//  * @date 2022-03-03
//  * @copyright Copyright (c) 2022
//  */
// void setApi()
// {
//   String postBody = server.arg("plain");
//   Serial.println(postBody);
//   setCrossOrigin();

//   DynamicJsonDocument doc(1024);
//   DeserializationError error = deserializeJson(doc, postBody);

//   if (error)
//   {
//     // if the file didn't open, print an error:
//     Serial.print(F("Error parsing JSON "));
//     Serial.println(error.c_str());

//     String msg = error.c_str();

//     server.send(400, F("text/html"),
//                 "Error in parsin json body! <br>" + msg);
//   }
//   else
//   {
//     JsonObject postObj = doc.as<JsonObject>();

//     Serial.print(F("HTTP Method: "));
//     Serial.println(server.method());

//     if (server.method() == HTTP_POST)
//     {
//       if (postObj.containsKey("name") && postObj.containsKey("value") && postObj.containsKey("username") && postObj.containsKey("password"))
//       {
//         char *Vname = NULL;
//         char *value = NULL;
//         char *username = NULL;
//         char *password = NULL;
//         Serial.println(F("done."));
//         heapStr(&value, doc["value"]);
//         heapStr(&Vname, doc["name"]);
//         heapStr(&username, doc["username"]);
//         heapStr(&password, doc["password"]);

//         if (String(username) != "admin" || String(password) != "admin")
//         {
//           String buf;
//           doc = setJsonValue("Credits are invalid");
//           serializeJson(doc, buf);
//           server.send(400, F("application/json"), buf);
//           Serial.print(F("done."));
//         }

//         if (String(value) != "on" && String(value) != "off" && String(value) != "ide")
//         {
//           String buf;
//           doc = setJsonValue("Status is invalid");
//           serializeJson(doc, buf);
//           server.send(400, F("application/json"), buf);
//           Serial.print(F("done."));
//         }

//         if (String(Vname) == "plantMoist")
//         {
//           stat[0][0][1] = value;
//         }
//         else if (String(Vname) == "motionOption")
//         {
//           stat[0][1][1] = value;
//         }
//         else if (String(Vname) == "clap")
//         {
//           stat[0][2][1] = value;
//         }
//         else if (String(Vname) == "espcam")
//         {
//           stat[0][3][1] = value;
//         }
//         else if (String(Vname) == "relay1")
//         {
//           stat[1][0][1] = value;
//           Serial.println("(" + String(stat[1][0][1]) + "," + String(stat[1][1][1]) + ")");
//           EspSerial.println("(" + String(stat[1][0][1]) + "," + String(stat[1][1][1]) + ")");
//         }
//         else if (String(Vname) == "relay2")
//         {
//           stat[1][1][1] = value;
//           Serial.println("(" + String(stat[1][0][1]) + "," + String(stat[1][1][1]) + ")");
//           EspSerial.println("(" + String(stat[1][0][1]) + "," + String(stat[1][1][1]) + ")");
//         }
//         else
//         {
//           String buf;
//           doc = setJsonValue("Invalid HTTP headers.");
//           server.send(400, F("application/json"), buf);
//           Serial.print(F("done."));
//         }
//         Serial.print(F("done."));

//         doc["status"] = "OK";

//         Serial.print(F("Stream..."));
//         String buf;
//         serializeJson(doc, buf);

//         server.send(201, F("application/json"), buf);
//         Serial.print(F("done."));
//       }
//       else
//       {
//         String buf;
//         doc = setJsonValue("Invalid HTTP headers.");
//         serializeJson(doc, buf);
//         server.send(400, F("application/json"), buf);
//         Serial.print(F("done."));
//       }
//     }
//   }
// }

// void sendCrossOriginHeader()
// {
//   Serial.println(F("sendCORSHeader"));

//   server.sendHeader(F("access-control-allow-credentials"), F("false"));

//   setCrossOrigin();

//   server.send(204);
// }

// // =====================================================================

// //
// //
// // LITTLEFS
// // USED FOR ROUTING
// //
// //

// /**
//  * @brief Load data from EEProm
//  *
//  * @param path
//  * @param dataType
//  * @return true
//  * @return false
//  * @version 0.1
//  * @author Ryan Samaeian (ry.samaeian@gmail.com)
//  * @date 2022-03-01
//  * @copyright Copyright (c) 2022
//  */
// bool loadFromLittleFS(String path, String dataType)
// {
//   Serial.print("Requested page -> ");
//   Serial.println(path);
//   if (LittleFS.exists(path))
//   {
//     File dataFile = LittleFS.open(path, "r");
//     if (!dataFile)
//     {
//       handleNotFound();
//       return false;
//     }

//     if (server.streamFile(dataFile, dataType) != dataFile.size())
//     {
//       Serial.println("Sent less data than expected!");
//     }
//     else
//     {
//       Serial.println("Page served!");
//     }

//     dataFile.close();
//   }
//   else
//   {
//     handleNotFound();
//     return false;
//   }
//   return true;
// }

// /**
//  * @brief Get the Content Type object
//  *
//  * @param filename
//  * @return String
//  * @version 0.1
//  * @author Ryan Samaeian (ry.samaeian@gmail.com)
//  * @date 2022-03-01
//  * @copyright Copyright (c) 2022
//  */
// String getContentType(String filename)
// {
//   if (filename.endsWith(F(".htm")))
//     return F("text/html");
//   else if (filename.endsWith(F(".html")))
//     return F("text/html");
//   else if (filename.endsWith(F(".css")))
//     return F("text/css");
//   else if (filename.endsWith(F(".js")))
//     return F("application/javascript");
//   else if (filename.endsWith(F(".json")))
//     return F("application/json");
//   else if (filename.endsWith(F(".png")))
//     return F("image/png");
//   else if (filename.endsWith(F(".gif")))
//     return F("image/gif");
//   else if (filename.endsWith(F(".jpg")))
//     return F("image/jpeg");
//   else if (filename.endsWith(F(".jpeg")))
//     return F("image/jpeg");
//   else if (filename.endsWith(F(".ico")))
//     return F("image/x-icon");
//   else if (filename.endsWith(F(".xml")))
//     return F("text/xml");
//   else if (filename.endsWith(F(".pdf")))
//     return F("application/x-pdf");
//   else if (filename.endsWith(F(".zip")))
//     return F("application/x-zip");
//   else if (filename.endsWith(F(".gz")))
//     return F("application/x-gzip");
//   return F("text/plain");
// }

// /**
//  * @brief Read files
//  *
//  * @param path
//  * @return true
//  * @return false
//  * @version 0.1
//  * @author Ryan Samaeian (ry.samaeian@gmail.com)
//  * @date 2022-03-01
//  * @copyright Copyright (c) 2022
//  */
// bool handleFileRead(String path)
// {
//   Serial.print(F("handleFileRead: "));
//   Serial.println(path);

//   if (path.endsWith("/"))
//     path += F("index.html");                 // If a folder is requested, send the index file
//   String contentType = getContentType(path); // Get the MIME type
//   String pathWithGz = path + F(".gz");
//   if (LittleFS.exists(pathWithGz) || LittleFS.exists(path))
//   { // If the file exists, either as a compressed archive, or normal
//     if (LittleFS.exists(pathWithGz))
//     {                   // If there's a compressed version available
//       path += F(".gz"); // Use the compressed version
//     }
//     File file = LittleFS.open(path, "r");
//     size_t sent = server.streamFile(file, contentType);
//     file.close();
//     Serial.print("Real file path: ");
//     Serial.println(path);
//     return true;
//   }
//   Serial.println(String(F("\tFile Not Found: ")) + path);
//   return false; // If the file doesn't exist, return false
// }

// // =====================================================================

// //
// //
// // RELAY STATUS
// //
// //

// void updateRelayValue()
// {
//   Serial.println("[" + String(stat[1][0][1]) + "," + String(stat[1][1][1]) + "]");
//   EspSerial.println("[" + String(stat[1][0][1]) + "," + String(stat[1][1][1]) + "]");
// }

// void relay1Stat()
// {
//   relay1Status = !relay1Status;
//   stat[1][0][1] = relay1Status;
//   updateRelayValue();
//   server.sendHeader("Location", "/");
//   server.sendHeader("Cache-Control", "no-cache");
//   server.send(200);
// }

// void relay2Stat()
// {
//   relay1Status = !relay1Status;
//   stat[1][0][1] = relay1Status;
//   updateRelayValue();
//   server.sendHeader("Location", "/");
//   server.sendHeader("Cache-Control", "no-cache");
//   server.send(200);
// }

// // =====================================================================

// //
// //
// // HTML WEB PAGE SECTION
// // ROUTERS ALL URLS
// //
// //

// /**
//  * @brief Route all URI's
//  *
//  * @version 0.1
//  * @author Ryan Samaeian (ry.samaeian@gmail.com)
//  * @date 2022-03-03
//  * @copyright Copyright (c) 2022
//  */
// void restServerRouting()
// {
//   server.onNotFound([]() { // If the client requests any URI
//     Serial.println(F("On not found"));
//     if (!handleFileRead(server.uri()))
//     {                   // send it if it exists
//       handleNotFound(); // otherwise, respond with a 404 (Not Found) error
//     }
//   });
//   server.on(F("/relay1"), HTTP_GET, relay1Stat);
//   server.on(F("/relay2"), HTTP_GET, relay2Stat);
//   server.on(F("/api"), HTTP_OPTIONS, sendCrossOriginHeader);
//   server.on(F("/api"), HTTP_GET, getApi);
//   server.on(F("/api"), HTTP_POST, setApi);
//   Serial.println(F("Set cache!"));
//   // Serve a file with no cache so every tile It's downloaded
//   server.serveStatic("/configuration.json", LittleFS, "/configuration.json", "no-cache, no-store, must-revalidate");
//   // Server all other page with long cache so browser chaching they
//   server.serveStatic("/", LittleFS, "/", "max-age=31536000");
// }

// /**
//  * @brief Handle error page
//  *
//  * @version 0.1
//  * @author Ryan Samaeian (ry.samaeian@gmail.com)
//  * @date 2022-03-03
//  * @copyright Copyright (c) 2022
//  */
// void handleNotFound()
// {
//   String message = "File Not Found\n\n";
//   message += "URI: ";
//   message += server.uri();
//   message += "\nMethod: ";
//   message += (server.method() == HTTP_GET) ? "GET" : "POST";
//   message += "\nArguments: ";
//   message += server.args();
//   message += "\n";
//   for (uint8_t i = 0; i < server.args(); i++)
//   {
//     message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
//   }
//   server.send(404, "text/plain", message);
// }

// void setup(void)
// {
//   delay(5000); // Not required just some delay time
//   Serial.begin(115200);
//   EspSerial.begin(115200);
//   WiFi.mode(WIFI_AP_STA); // https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/readme.html#station
//   WiFi.begin(ssid, password);

//   while (WiFi.status() != WL_CONNECTED)
//   {
//     delay(500);
//     Serial.println("=");
//   }

//   Serial.println("");
//   Serial.print("Connected to ");
//   Serial.println(ssid);
//   Serial.print("With IP: ");
//   Serial.println(WiFi.localIP());
//   if (MDNS.begin("esp8266"))
//   {
//     Serial.println("MDNS responder started");
//   }
//   Serial.println("Setting soft-ap configs... ");
//   WiFi.softAPConfig(local_IP, gateway, subnet);
//   Serial.println(WiFi.softAP("RRE home", STUOASS) ? "Ready" : "Fail");
//   Serial.println(WiFi.softAPIP());
//   Serial.print(F("Inizializing LittleFS..."));
//   if (LittleFS.begin())
//   {
//     Serial.println(F("done."));
//   }
//   else
//   {
//     Serial.println(F("fail."));
//   }
//   restServerRouting();
//   server.begin();
//   Serial.println("HTTP server started");
// }

// void loop(void)
// {
//   server.handleClient();

//   recvWithStartEndMarkers();
//   if (newData == true)
//   {
//     strcpy(tempChars, receivedChars);
//     // this temporary copy is necessary to protect the original data
//     //   because strtok() used in parseData() replaces the commas with \0
//     parseData();
//     showParsedData();
//     newData = false;
//   }

// //    startWithEndMarker();
// //  if (newDataRelay == true)
// //  {
// //    strcpy(tempCharsRelay, receivedCharsRelay);
// //    // this temporary copy is necessary to protect the original data
// //    //   because strtok() used in parseData() replaces the commas with \0
// //    parseDataRelay();
// //    newDataRelay = false;
// //  }
// }

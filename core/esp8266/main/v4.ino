
#include "Arduino.h"
#include "credits.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ArduinoJson.h>
#include <strTools.h>
#include <stdio.h>
#include <stdlib.h>
#include "LittleFS.h"
#define ESP Serial1

/*
 * Functions
 * This is a lint of useful functions mainly important from the libs folder and modified
 * The code mainly runs on this base
 */

/**
 * @brief Returns the current HTTP status of the webpage, used to return
 * proper types - very useful when using an external application.
 *
 * @param TYPE
 * @return int
 * @version 0.1
 * @author Ryan Samaeian (ry.samaeian@gmail.com)
 * @date 2022-03-05
 * @copyright Copyright (c) 2022
 */
int httpStatus(string TYPE)
{
  int status;
  if (TYPE == "redirect")
    status = 100;
  else if (TYPE == "processing")
    status = 102;
  else if (TYPE == "ok")
    status = 200;
  else if (TYPE == "created")
    status = 201;
  else if (TYPE == "accepted")
    status = 202;
  else if (TYPE == "invalid")
    status = 400;
  else if (TYPE == "unauthorized")
    status = 401;
  else if (TYPE == "implement")
    status 501;
  else
    status = 404;
  return status;
}

// JSON response
String httpBuildStatus(String object[])
{
  // { {"x", "y"} {"x", "y"} }
  DynamicJsonDocument doc(1024);
  String value;
  for (int i = 0; i < sizeof(object) / sizeof(object[0]); i++)
  {
    for (int j = 0; j < sizeof(object[i]) / sizeof(object[i][0]); j++)
    {
      doc[object[i][j]] = object[i][++j];
    }
  }
  serializeJson(doc, value);
  return value;
}

// Return a Response
void serveWebsite(
    String object[],
    String redirect,
    String serveHtml,
    String type,
    String status,
    boolean onlyRedirect = false,
    boolean setCache = false)
{
  if (redirect != Null)
  {
    if (onlyRedirect)
    {
      server.sendHeader("Location", redirect);
      server.send(httpStatus("redirect"));
    }
    else
    {
      server.sendHeader("Location", redirect);
    }
    if (setCache)
      server.sendHeader("Cache-Control", "cache");
    else
      server.sendHeader("Cache-Control", "no-cache");
    return;
  }
  server.send(httpStatus(status), F(type), httpBuildStatus(object));
}

/**
 * @brief Set the Cookie object
 *
 * @param cookies
 * @version 0.1
 * @author Ryan Samaeian (ry.samaeian@gmail.com)
 * @date 2022-03-06
 * @copyright Copyright (c) 2022
 */
void setCookie(object cookies[])
{
  for (int i = 0; i < sizeof(object) / sizeof(object[0]); i++)
  {
    for (int i = 0; i < sizeof(object[i]) / sizeof(object[i][0]); i++)
    {
      server.sendHeader("Set-cookie", String(object[i] + "=" + object[i][++j]));
    }
  }
}

/**
 * @brief Get the Cookie object
 * 
 * @return String 
 * @version 0.1
 * @author Ryan Samaeian (ry.samaeian@gmail.com)
 * @date 2022-03-06
 * @copyright Copyright (c) 2022
 */
String getCookie(name)
{
  if (server.hasHeader("Cookie"))
  {
    char *cookie;
    char *remaining[] = server.header("Cookie");

    while (cookie = strtok_r(remaining, ";", &remaining))
    {
      if (cookie.indexOf(name) != -1)
      {
        return cookie;
      }
    }
  }
}

void sha256()
{
  // Will do later
}

void startTimer()
{
  // help needed !
}

/*
 * Serial Communication
 * Used to communicate between the ESP32-Cam and Arduino Due
 */

// BEING HEAVILY WORKED ON!
void serialListen()
{
  static boolean recvInProgress = false;
  static byte ndx = 0;
  char startMarker = '<';
  char endMarker = '>';
  char rc;

  while (Serial.available() > 0 && newData == false)
  {
    rc = Serial.read();

    if (recvInProgress == true)
    {
      if (rc != endMarker)
      {
        receivedChars[ndx] = rc;
        ndx++;
        if (ndx >= numChars)
        {
          ndx = numChars - 1;
        }
      }
      else
      {
        receivedChars[ndx] = '\0'; // terminate the string
        recvInProgress = false;
        ndx = 0;
        newData = true;
      }
    }

    else if (rc == startMarker)
    {
      recvInProgress = true;
    }
  }
}

void serialPrint(value)
{
  ESP.println(value);
}
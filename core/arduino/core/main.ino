#define RELAY1 53
#define RELAY2 52
#define CAMDG 8
//#define MICDG
#define SOILDG 4
#define SOILAO A0
#define DEBUG true
#define ESP8266 Serial3
#include <AsyncTimer.h>

AsyncTimer t;

boolean led1Stat = 1;
boolean led2Stat = 1;
boolean timerSet;
int plantMoist, motionStat;
long runningTime;
String action;
String plantMoistStat = "No information";
unsigned long previousMillis = 0;
long interval = 10000;
long relay1Running, relay2Running;
const byte numChars = 32;
//char relay1[numChars] = {0};
//char relay2[numChars] = {0};
//char plantMoist[numChars] = {0};
// char receivedChars[numChars];
char relayStatus[numChars];
char relayStatusTemp[numChars];
// char tempChars[numChars];
boolean newData = false;
bool timeoutId;
long prevTime;

void setup()
{
  // Begin Serial ports
  Serial.begin(115200);
  ESP8266.begin(115200);
  // Functions

  // Relay off by default
  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);

  // Init I/O
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(8, INPUT);
  pinMode(SOILDG, INPUT);
  pinMode(SOILAO, INPUT);
  delay(5000);
  String msg = "<" + String(led1Stat)+ ", " + String(led2Stat) + ", " + String(analogRead(SOILAO)) + ">";
  Serial.println(msg.c_str()); 
  ESP8266.println(msg.c_str());
}

void loop()
{
  runningTime++;
  int plantMoist = analogRead(SOILAO);
  checkMovement();
  recvWithStartEndMarkers('(', ')', relayStatus);
  if (newData == true)
  {
    strcpy(relayStatusTemp, relayStatus);
    // this temporary copy is necessary to protect the original data
    //   because strtok() used in parseData() replaces the commas with \0
    parseData(relayStatusTemp);
    newData = false;
  }
}

/**
 * @brief Get the end of the serial object <content>
 *
 * @version 0.1
 * @author Ryan Samaeian (ry.samaeian@gmail.com)
 * @date 2022-03-03
 * @copyright Copyright (c) 2022
 */
void recvWithStartEndMarkers(char startMarker, char endMarker, char variable[])
{
  static boolean recvInProgress = false;
  static byte ndx = 0;
  // char startMarker = '(';
  // char endMarker = ')';
  char rc;

  while (ESP8266.available() > 0 && newData == false)
  {
    rc = ESP8266.read();

    if (recvInProgress == true)
    {
      if (rc != endMarker)
      {
        variable[ndx] = rc;
        ndx++;
        if (ndx >= numChars)
        {
          ndx = numChars - 1;
        }
      }
      else
      {
        variable[ndx] = '\0'; // terminate the string
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

/**
 * @brief Get the values recvWithStartEndMarker()
 *
 * @version 0.1
 * @author Ryan Samaeian (ry.samaeian@gmail.com)
 * @date 2022-03-03
 * @copyright Copyright (c) 2022
 */
void parseData(const variable[])
{                   // split the data into its parts
  char *strtokIndx; // this is used by strtok() as an index
  strtokIndx = strtok(variable, ","); // get the first part - the string
    Serial.println(strtokIndx);

  if (String(strtokIndx) == "on")
  {
        digitalWrite(RELAY1, LOW);
  } else {
        digitalWrite(RELAY1, HIGH);

  }
  strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    Serial.println(strtokIndx);

  if (String(strtokIndx) == "on")
  {
    digitalWrite(RELAY2, LOW);
  } else {
    digitalWrite(RELAY2, HIGH);
  }
//  strcpy(led2Stat, strtokIndx);     // convert this part to an integer
}

void counter()
{
}

boolean setTimer(int time, bool returnOrNot)
{
  // START AT X AMOUNT AND END AT Y AMOUNT
}

void clap()
{
  //
}
void checkMovement(void)
{
  unsigned long millisSec = millis();
  delay(2000);
  int cameraDG = digitalRead(8);
   if (led1Stat == 0 || led2Stat == 0) {
     if (cameraDG == 0)
     {
       if (millisSec - prevTime > 10000)
       {
         Serial.println("no movemento!");
         prevTime = millisSec;
         Serial.println(millisSec);
   digitalWrite(RELAY1, HIGH);
   digitalWrite(RELAY2, HIGH);
   led1Stat = 1;
   led2Stat = 1;
         millisSec = 0;
       }
     }
   }
   if (cameraDG == 1)
   {
     Serial.println(cameraDG);
     prevTime = millisSec;
   digitalWrite(RELAY1, LOW);
   digitalWrite(RELAY2, LOW);
   led1Stat = 0;
   led2Stat = 0;
     delay(60000);
   }
//  if (cameraDG == HIGH)
//  {
//    if (timeoutId != 0)
//    {
//      digitalWrite(RELAY1, LOW);
//      digitalWrite(RELAY2, LOW);
//      led1Stat = 0;
//      led2Stat = 0;
//      t.reset(timeoutId);
//    }
//    else
//      timeoutId = t.setTimeout(
//          []()
//          {
//            digitalWrite(RELAY1, HIGH);
//            digitalWrite(RELAY2, HIGH);
//            led1Stat = 1;
//            led2Stat = 1;
//            timeoutId = 0;
//          },
//          60000);
//  }
}
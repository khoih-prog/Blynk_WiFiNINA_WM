/****************************************************************************************************************************
   SAM_DUE_ESP8266Shield.ino
   For SAM DUE using ESP8266 WiFi Shield

   Blynk_Esp8266AT_WM is a library for the Mega, Teensy, SAM DUE and SAMD boards (https://github.com/khoih-prog/Blynk_Esp8266AT_WM)
   to enable easy configuration/reconfiguration and autoconnect/autoreconnect of WiFi/Blynk

   Forked from Blynk library v0.6.1 https://github.com/blynkkk/blynk-library/releases
   Built by Khoi Hoang https://github.com/khoih-prog/Blynk_WM
   Licensed under MIT license
   Version: 1.0.4

   Original Blynk Library author:
   @file       BlynkSimpleShieldEsp8266.h
   @author     Volodymyr Shymanskyy
   @license    This project is released under the MIT License (MIT)
   @copyright  Copyright (c) 2015 Volodymyr Shymanskyy
   @date       Jun 2015
   @brief

   Version Modified By   Date        Comments
   ------- -----------  ----------   -----------
    1.0.0   K Hoang      16/02/2020  Initial coding
    1.0.1   K Hoang      17/02/2019  Add checksum, fix bug
    1.0.2   K Hoang      22/02/2019  Add support to SAMD boards
    1.0.3   K Hoang      03/03/2019  Add support to STM32 boards, except STM32F0
    1.0.4   K Hoang      13/03/2019  Add SAM DUE support. Enhance GUI. 
 *****************************************************************************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#if ( defined(ARDUINO_SAM_DUE) || defined(__SAM3X8E__) )
  #if defined(ESP8266_AT_USE_SAM_DUE)
  #undef ESP8266_AT_USE_SAM_DUE
  #endif
  #define ESP8266_AT_USE_SAM_DUE      true
  #warning Use SAM_DUE architecture
#endif

#if ( defined(ESP8266) || defined(ESP32) || defined(ARDUINO_AVR_MEGA2560) || defined(ARDUINO_AVR_MEGA) || \
      defined(CORE_TEENSY) || defined(CORE_TEENSY) || !(ESP8266_AT_USE_SAM_DUE) )
#error This code is intended to run on the SAM DUE platform! Please check your Tools->Board setting.
#endif

#if defined(ESP8266_AT_USE_SAM_DUE) 
   // For SAM DUE
  #define EspSerial Serial1
  
  #if defined(ARDUINO_SAM_DUE)
    #define BOARD_TYPE      "SAM DUE"
  #elif defined(__SAM3X8E__)
    #define BOARD_TYPE      "SAM SAM3X8E"    
  #else
    #define BOARD_TYPE      "SAM Unknown"
  #endif
#endif

#include <ESP8266_Lib.h>

// Start location in EEPROM to store config data. Default 0
// Config data Size currently is 128 bytes)
#define EEPROM_START     256

#define USE_BLYNK_WM      true
//#define USE_BLYNK_WM      false

#if USE_BLYNK_WM
#include <BlynkSimpleShieldEsp8266_DUE_WM.h>
#else
#include <BlynkSimpleShieldEsp8266_DUE.h>

#define USE_LOCAL_SERVER      true

#if USE_LOCAL_SERVER
char auth[] = "****";
String BlynkServer = "account.duckdns.org";
//String BlynkServer = "192.168.2.112";
#else
char auth[] = "****";
String BlynkServer = "blynk-cloud.com";
#endif

#define BLYNK_SERVER_HARDWARE_PORT    8080

// Your WiFi credentials.
char ssid[] = "****";
char pass[] = "****";

#endif

// Your Megay <-> ESP8266 baud rate:
#define ESP8266_BAUD 115200

ESP8266 wifi(&EspSerial);

void heartBeatPrint(void)
{
  static int num = 1;

  if (Blynk.connected())
  {
    Serial.print("B");
  }
  else
  {
    Serial.print("F");
  }

  if (num == 80)
  {
    Serial.println();
    num = 1;
  }
  else if (num++ % 10 == 0)
  {
    Serial.print(" ");
  }
}

void check_status()
{
  static unsigned long checkstatus_timeout = 0;

#define STATUS_CHECK_INTERVAL     15000L

  // Send status report every STATUS_REPORT_INTERVAL (60) seconds: we don't need to send updates frequently if there is no status change.
  if ((millis() > checkstatus_timeout) || (checkstatus_timeout == 0))
  {
    // report status to Blynk
    heartBeatPrint();

    checkstatus_timeout = millis() + STATUS_CHECK_INTERVAL;
  }
}

void setup()
{
  // Debug console
  Serial.begin(115200);
  delay(1000);

  // initialize serial for ESP module
  EspSerial.begin(ESP8266_BAUD);
  Serial.println("\nStart Blynk WiFiManager using ESP8266_AT_Shield on " + String(BOARD_TYPE));

#if USE_BLYNK_WM
  Serial.println(F("Start Blynk_WM"));
  Blynk.setConfigPortalIP(IPAddress(192, 168, 120, 1));
  //Blynk.setConfigPortal("Mega", "MyMega");
  Blynk.begin(wifi);
#else
  Serial.println(F("Start Blynk"));
  Blynk.begin(auth, wifi, ssid, pass, BlynkServer.c_str(), BLYNK_SERVER_HARDWARE_PORT);
#endif
}

void loop()
{
  Blynk.run();
  check_status();
}

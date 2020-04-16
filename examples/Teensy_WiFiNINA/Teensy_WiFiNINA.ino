/****************************************************************************************************************************
   Teensy_WiFiNINA.ino
   For Teensy (4.0, 3.x, LC) using WiFiNINA Shield/Module

   Blynk_WiFiNINA_WM is a library for the Mega, Teensy, SAM DUE and SAMD boards (https://github.com/khoih-prog/Blynk_WiFiNINA_WM)
   to enable easy configuration/reconfiguration and autoconnect/autoreconnect of WiFiNINA/Blynk

   Modified from Blynk library v0.6.1 https://github.com/blynkkk/blynk-library/releases
   Built by Khoi Hoang https://github.com/khoih-prog/Blynk_WiFiNINA_WM
   Licensed under MIT license
   Version: 1.0.2

   Original Blynk Library author:
   @file       BlynkSimpleWiFiNINA.h
   @author     Volodymyr Shymanskyy
   @license    This project is released under the MIT License (MIT)
   @copyright  Copyright (c) 2018 Volodymyr Shymanskyy
   @date       Sep 2018
   @brief

   Version Modified By   Date        Comments
   ------- -----------  ----------   -----------
    1.0.0   K Hoang      07/04/2020  Initial coding
    1.0.1   K Hoang      09/04/2020  Add support to SAM DUE, Teensy, STM32
    1.0.2   K Hoang      15/04/2020  Fix bug. Add SAMD51 support.
 *****************************************************************************************************************************/

/* Comment this out to disable prints and save space */
#define DEBUG_WIFI_WEBSERVER_PORT Serial
#define WIFININA_DEBUG_OUTPUT     Serial
#define BLYNK_PRINT Serial

#if ( defined(ESP8266) || defined(ESP32) || defined(ARDUINO_AVR_MEGA) || defined(ARDUINO_AVR_MEGA2560) || !defined(CORE_TEENSY) )
#error This code is intended to run on Teensy platform! Please check your Tools->Board setting.
#endif

#ifdef CORE_TEENSY  
  #if defined(WIFININA_USE_TEENSY)
    #undef WIFININA_USE_TEENSY
    #undef WIFI_USE_TEENSY
  #endif
  #define WIFININA_USE_TEENSY      true
  #define WIFI_USE_TEENSY          true
  #warning Use Teensy architecture
  
  #if defined(__IMXRT1062__)
    #define BOARD_TYPE      "TEENSY 4.0"
  #elif defined(__MK66FX1M0__)
    #define BOARD_TYPE "Teensy 3.6"
  #elif defined(__MK64FX512__)
    #define BOARD_TYPE "Teensy 3.5"
  #elif defined(__MKL26Z64__)       
    #define BOARD_TYPE "Teensy LC"
  #elif defined(__MK20DX256__)       
    #define BOARD_TYPE "Teensy 3.2-3.1"
  #elif defined(__MK20DX128__)       
    #define BOARD_TYPE "Teensy 3.0"  
  #elif ( defined(__AVR_AT90USB1286__) || defined(__AVR_ATmega32U4__) )   
    #error "Teensy 2.0 and 2.0++ not supported"
  #endif
#endif

// Start location in EEPROM to store config data. Default 0
// Config data Size currently is 128 bytes)
#define EEPROM_START     0

#define USE_BLYNK_WM      true
//#define USE_BLYNK_WM      false

#if USE_BLYNK_WM
#include <BlynkSimpleWiFiNINA_Teensy_WM.h>

#define USE_DYNAMIC_PARAMETERS      true

/////////////// Start dynamic Credentials ///////////////

//Defined in <BlynkSimpleWiFiNINA_Teensy_WM.h>
/**************************************
  #define MAX_ID_LEN                5
  #define MAX_DISPLAY_NAME_LEN      16

  typedef struct
  {
  char id             [MAX_ID_LEN + 1];
  char displayName    [MAX_DISPLAY_NAME_LEN + 1];
  char *pdata;
  uint8_t maxlen;
  } MenuItem;
**************************************/

#if USE_DYNAMIC_PARAMETERS

#define MAX_MQTT_SERVER_LEN      34
char MQTT_Server  [MAX_MQTT_SERVER_LEN + 1]   = "";

#define MAX_MQTT_PORT_LEN        6
char MQTT_Port   [MAX_MQTT_PORT_LEN+ 1]  = "";

#define MAX_MQTT_USERNAME_LEN      34
char MQTT_UserName  [MAX_MQTT_USERNAME_LEN + 1]   = "";

#define MAX_MQTT_PW_LEN        34
char MQTT_PW   [MAX_MQTT_PW_LEN + 1]  = "";

#define MAX_MQTT_SUBS_TOPIC_LEN      34
char MQTT_SubsTopic  [MAX_MQTT_SUBS_TOPIC_LEN + 1]   = "";

#define MAX_MQTT_PUB_TOPIC_LEN       34
char MQTT_PubTopic   [MAX_MQTT_PUB_TOPIC_LEN + 1]  = "";

MenuItem myMenuItems [] =
{
  { "mqtt", "MQTT Server",      MQTT_Server,      MAX_MQTT_SERVER_LEN },
  { "mqpt", "Port",             MQTT_Port,        MAX_MQTT_PORT_LEN   },
  { "user", "MQTT UserName",    MQTT_UserName,    MAX_MQTT_USERNAME_LEN },
  { "mqpw", "MQTT PWD",         MQTT_PW,          MAX_MQTT_PW_LEN },
  { "subs", "Subs Topics",      MQTT_SubsTopic,   MAX_MQTT_SUBS_TOPIC_LEN },
  { "pubs", "Pubs Topics",      MQTT_PubTopic,    MAX_MQTT_PUB_TOPIC_LEN },
};

uint16_t NUM_MENU_ITEMS = sizeof(myMenuItems) / sizeof(MenuItem);  //MenuItemSize;

#else

MenuItem myMenuItems [] = {};

uint16_t NUM_MENU_ITEMS = 0;

#endif    //USE_DYNAMIC_PARAMETERS

/////// // End dynamic Credentials ///////////

#else
#include <BlynkSimpleWiFiNINA_Teensy.h>

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
  while (!Serial);
  //delay(1000);

  Serial.println("\nStart Blynk_WiFiNINA_WM using WiFiNINA_Shield on " + String(BOARD_TYPE));

#if USE_BLYNK_WM
  Serial.println("Start Blynk_WM");
  Blynk.setConfigPortalIP(IPAddress(192, 168, 120, 1));
  //Blynk.setConfigPortal("Teensy4", "MyTeensy4");
  Blynk.begin("Teensy40-WiFiNINA");
#else
  Serial.println("Start Blynk");
  Blynk.begin(auth, ssid, pass, BlynkServer.c_str(), BLYNK_SERVER_HARDWARE_PORT);
#endif
}

#if (USE_BLYNK_WM && USE_DYNAMIC_PARAMETERS)
void displayCredentials(void)
{
  Serial.println("Your stored Credentials :");

  for (int i = 0; i < NUM_MENU_ITEMS; i++)
  {
    Serial.println(String(myMenuItems[i].displayName) + " = " + myMenuItems[i].pdata);
  }
}
#endif

void loop()
{
  Blynk.run();
  check_status();

#if (USE_BLYNK_WM && USE_DYNAMIC_PARAMETERS)
  static bool displayedCredentials = false;

  if (!displayedCredentials)
  {
    for (int i = 0; i < NUM_MENU_ITEMS; i++)
    {
      if (!strlen(myMenuItems[i].pdata))
      {
        break;
      }

      if ( i == (NUM_MENU_ITEMS - 1) )
      {
        displayedCredentials = true;
        displayCredentials();
      }
    }
  }
#endif
}

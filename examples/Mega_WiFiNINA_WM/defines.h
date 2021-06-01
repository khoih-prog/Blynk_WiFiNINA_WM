/****************************************************************************************************************************
  defines.h
  For AVR Mega boards using WiFiNINA Shields

  Blynk_WiFiNINA_WM is a library for the Mega, Teensy, SAM DUE, nRF52, STM32, SAMD and RP2040 boards 
  (https://github.com/khoih-prog/Blynk_WiFiNINA_WM) to enable easy configuration/reconfiguration and
  autoconnect/autoreconnect of WiFiNINA/Blynk

  Modified from Blynk library v0.6.1 https://github.com/blynkkk/blynk-library/releases
  Built by Khoi Hoang https://github.com/khoih-prog/Blynk_WiFiNINA_WM
  Licensed under MIT license
 *****************************************************************************************************************************/

#ifndef defines_h
#define defines_h

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#define DEBUG_WIFI_WEBSERVER_PORT Serial
#define WIFININA_DEBUG_OUTPUT     Serial

#define DRD_GENERIC_DEBUG         true
#define WIFININA_DEBUG            true
#define BLYNK_WM_DEBUG            3

#if !( defined(ARDUINO_AVR_MEGA) || defined(ARDUINO_AVR_MEGA2560) || defined(ARDUINO_AVR_ADK) )
  #error This code is intended to run only on the Arduino Mega 1280/2560/ADK boards ! Please check your Tools->Board setting.
#endif

#if defined(ARDUINO_AVR_MEGA2560)
  #define BOARD_TYPE      "AVR Mega2560"
#elif defined(ARDUINO_AVR_ADK)
  #define BOARD_TYPE      "AVR Mega ADK"
#else
  #define BOARD_TYPE      "AVR Mega"
#endif

#if !defined(BOARD_NAME)
  #define BOARD_NAME    BOARD_TYPE
#endif

// Start location in EEPROM to store config data. Default 0
// Config data Size currently is 128 bytes)
#define EEPROM_START     0

#define USE_BLYNK_WM      true
//#define USE_BLYNK_WM      false

#define USE_SSL             false

#if USE_BLYNK_WM

//#if USE_DYNAMIC_PARAMETERS
#include <BlynkSimpleWiFiNINA_AVR_WM.h>
#include "dynamicParams.h"

#else
#include <BlynkSimpleWiFiNINA_AVR.h>

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

#endif      //USE_BLYNK_WM

#define HOST_NAME   "Mega-WiFiNINA"

#endif      //defines_h

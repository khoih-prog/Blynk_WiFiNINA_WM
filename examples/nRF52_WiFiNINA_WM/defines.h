/****************************************************************************************************************************
   defines.h for SAMD_WiFiNINA_WM.ino
   For SAMD using WiFiNINA Shield/Module

   Blynk_WiFiNINA_WM is a library for the Mega, Teensy, SAM DUE and SAMD boards (https://github.com/khoih-prog/Blynk_WiFiNINA_WM)
   to enable easy configuration/reconfiguration and autoconnect/autoreconnect of WiFiNINA/Blynk

   Modified from Blynk library v0.6.1 https://github.com/blynkkk/blynk-library/releases
   Built by Khoi Hoang https://github.com/khoih-prog/Blynk_WiFiNINA_WM
   Licensed under MIT license
   Version: 1.0.4

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
    1.0.3   K Hoang      05/05/2020  Add nRF52 support, MultiWiFi/Blynk, Configurable Config Portal Title, 
                                     Default Config Data and DRD. Update examples.
    1.0.4   K Hoang      13/05/2020 Add support to Arduino UNO WiFi R2 
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

#if ( defined(NRF52840_FEATHER) || defined(NRF52832_FEATHER) || defined(NRF52_SERIES) || defined(ARDUINO_NRF52_ADAFRUIT) || \
        defined(NRF52840_FEATHER_SENSE) || defined(NRF52840_ITSYBITSY) || defined(NRF52840_CIRCUITPLAY) || defined(NRF52840_CLUE) || \
        defined(NRF52840_METRO) || defined(NRF52840_PCA10056) || defined(PARTICLE_XENON) || defined(NINA_B302_ublox) )
  #if defined(WIFININA_USE_NRF528XX)
    #undef WIFININA_USE_NRF528XX
    #undef WIFI_USE_NRF528XX
  #endif
  #define WIFININA_USE_NRF528XX      true
  #define WIFI_USE_NRF528XX          true
#else
  #error This code is intended to run only on the NRF528XX boards ! Please check your Tools->Board setting.
#endif

#if defined(WIFININA_USE_NRF528XX)

#if defined(NRF52840_FEATHER)
#define BOARD_TYPE      "NRF52840_FEATHER"
#elif defined(NRF52832_FEATHER)
#define BOARD_TYPE      "NRF52832_FEATHER"
#elif defined(NRF52840_FEATHER_SENSE)
#define BOARD_TYPE      "NRF52840_FEATHER_SENSE"
#elif defined(NRF52840_ITSYBITSY)
#define BOARD_TYPE      "NRF52840_ITSYBITSY"
#elif defined(NRF52840_CIRCUITPLAY)
#define BOARD_TYPE      "NRF52840_CIRCUITPLAY"
#elif defined(NRF52840_CLUE)
#define BOARD_TYPE      "NRF52840_CLUE"
#elif defined(NRF52840_METRO)
#define BOARD_TYPE      "NRF52840_METRO"
#elif defined(NRF52840_PCA10056)
#define BOARD_TYPE      "NRF52840_PCA10056"
#elif defined(PARTICLE_XENON)
#define BOARD_TYPE      "PARTICLE_XENON"
#elif defined(NINA_B302_ublox)
#define BOARD_TYPE      "NINA_B302_ublox"
#elif defined(ARDUINO_NRF52_ADAFRUIT)
#define BOARD_TYPE      "ARDUINO_NRF52_ADAFRUIT"
#elif defined(NRF52_SERIES)
#define BOARD_TYPE      "NRF52_SERIES"
#else
#define BOARD_TYPE      "NRF52 Unknown"
#endif

#endif

// Start location in EEPROM to store config data. Default 0
// Config data Size currently is 128 bytes)
#define EEPROM_START     0

#define EEPROM_SIZE     (2048)

#define USE_BLYNK_WM      true
//#define USE_BLYNK_WM      false

#define USE_SSL             false

#if USE_BLYNK_WM

#include <BlynkSimpleWiFiNINA_nRF52_WM.h>

#else
#include <BlynkSimpleWiFiNINA_nRF52.h>

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
//char ssid[] = "****";
//char pass[] = "****";

char ssid[] = "HueNet1";
char pass[] = "****";

#endif

#define HOST_NAME   "nRF52-WiFiNINA"

#endif      //defines_h

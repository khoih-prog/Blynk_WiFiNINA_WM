/****************************************************************************************************************************
   defines.h for Teensy_WiFiNINA.ino
   For Teensy (4.0, 3.x, LC) using WiFiNINA Shield/Module

   Blynk_WiFiNINA_WM is a library for the Mega, Teensy, SAM DUE, nRF52, STM32 and SAMD boards 
   (https://github.com/khoih-prog/Blynk_WiFiNINA_WM) to enable easy configuration/reconfiguration and
   autoconnect/autoreconnect of WiFiNINA/Blynk

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

//#define USE_BLYNK_WM      true
#define USE_BLYNK_WM      false

#define USE_SSL             false

#if USE_BLYNK_WM
#include <BlynkSimpleWiFiNINA_Teensy_WM.h>

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

#define HOST_NAME   "Teensy-WiFiNINA"

#endif      //defines_h

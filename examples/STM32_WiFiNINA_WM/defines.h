/****************************************************************************************************************************
  defines.h
  For STM32 using WiFiNINA Shield/Module

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
#define _WIFININA_LOGLEVEL_       3

#if ( defined(STM32F0) || defined(STM32F1) || defined(STM32F2) || defined(STM32F3)  ||defined(STM32F4) || defined(STM32F7) || \
      defined(STM32L0) || defined(STM32L1) || defined(STM32L4) || defined(STM32H7)  ||defined(STM32G0) || defined(STM32G4) || \
      defined(STM32WB) || defined(STM32MP1) || defined(STM32L5) )
  #if defined(WIFININA_USE_STM32)
    #undef WIFININA_USE_STM32
    #undef WIFI_USE_STM32
  #endif
  #define WIFININA_USE_STM32      true
  #define WIFI_USE_STM32          true
#else
  #error This code is intended to run only on the STM32-based boards ! Please check your Tools->Board setting.  
#endif

#if WIFININA_USE_STM32

  #if defined(STM32F0)
    #define BOARD_TYPE  "STM32F0"
  #elif defined(STM32F1)
    #define BOARD_TYPE  "STM32F1"
  #elif defined(STM32F2)
    #define BOARD_TYPE  "STM32F2"
  #elif defined(STM32F3)
    #define BOARD_TYPE  "STM32F3"
  #elif defined(STM32F4)
    #define BOARD_TYPE  "STM32F4"
  #elif defined(STM32F7)
    #define BOARD_TYPE  "STM32F7"
  #elif defined(STM32L0)
    #define BOARD_TYPE  "STM32L0"
  #elif defined(STM32L1)
    #define BOARD_TYPE  "STM32L1"
  #elif defined(STM32L4)
    #define BOARD_TYPE  "STM32L4"
  #elif defined(STM32L5)
    #define BOARD_TYPE  "STM32L5"
  #elif defined(STM32H7)
    #define BOARD_TYPE  "STM32H7"
  #elif defined(STM32G0)
    #define BOARD_TYPE  "STM32G0"
  #elif defined(STM32G4)
    #define BOARD_TYPE  "STM32G4"
  #elif defined(STM32WB)
    #define BOARD_TYPE  "STM32WB"
  #elif defined(STM32MP1)
    #define BOARD_TYPE  "STM32MP1"  
  #else
    #warning STM32 unknown board selected
    #define BOARD_TYPE  "STM32 Unknown"
  #endif

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

  /////////////////////////////////////////////

  #if defined(STM32F0) || defined(STM32L0) || defined(STM32G0)
    #error Board STM32F0/L0/G0 not supported. Not enough memory
  #endif

  /////////////////////////////////////////////

  // Add customs headers from v1.1.0
  #define USING_CUSTOMS_STYLE           true
  #define USING_CUSTOMS_HEAD_ELEMENT    true
  #define USING_CORS_FEATURE            true
  
  /////////////////////////////////////////////
  
  // Permit running CONFIG_TIMEOUT_RETRYTIMES_BEFORE_RESET times before reset hardware
  // to permit user another chance to config. Only if Config Data is valid.
  // If Config Data is invalid, this has no effect as Config Portal will persist
  #define RESET_IF_CONFIG_TIMEOUT                   true
  
  // Permitted range of user-defined RETRY_TIMES_RECONNECT_WIFI between 2-5 times
  #define RETRY_TIMES_RECONNECT_WIFI                3
  
  // Permitted range of user-defined CONFIG_TIMEOUT_RETRYTIMES_BEFORE_RESET between 2-100
  #define CONFIG_TIMEOUT_RETRYTIMES_BEFORE_RESET    5
  
  // Config Timeout 120s (default 60s). Applicable only if Config Data is Valid
  #define CONFIG_TIMEOUT                      120000L
  
  // Permit input only one set of WiFi SSID/PWD. The other can be "NULL or "blank"
  // Default is false (if not defined) => must input 2 sets of SSID/PWD
  #define REQUIRE_ONE_SET_SSID_PW             true
  
  #define USE_DYNAMIC_PARAMETERS              true
  
  /////////////////////////////////////////////
  
  #define SCAN_WIFI_NETWORKS                  true
  
  // To be able to manually input SSID, not from a scanned SSID lists
  #define MANUAL_SSID_INPUT_ALLOWED           true
  
  // From 2-15
  #define MAX_SSID_IN_LIST                    8
  
  /////////////////////////////////////////////
  #include <BlynkSimpleWiFiNINA_STM32_WM.h>

#else
  #include <BlynkSimpleWiFiNINA_STM32.h>
  
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

#define HOST_NAME   "STM32-WiFiNINA"

#endif      //defines_h

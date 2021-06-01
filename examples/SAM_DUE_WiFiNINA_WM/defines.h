/****************************************************************************************************************************
  defines.h
  For SAM DUE boards using WiFiNINA Shields

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

#if ( defined(ARDUINO_SAM_DUE) || defined(__SAM3X8E__) )
#if defined(WIFININA_USE_SAM_DUE)
#undef WIFININA_USE_SAM_DUE
#undef WIFI_USE_SAM_DUE
#endif
#define WIFININA_USE_SAM_DUE      true
#define WIFI_USE_SAM_DUE          true
#warning Use SAM_DUE architecture
#endif

#if ( defined(ESP8266) || defined(ESP32) || defined(ARDUINO_AVR_MEGA2560) || defined(ARDUINO_AVR_MEGA) || \
      defined(CORE_TEENSY) || defined(CORE_TEENSY) || !(WIFININA_USE_SAM_DUE) )
#error This code is intended to run on the SAM DUE platform! Please check your Tools->Board setting.
#endif

#if defined(WIFININA_USE_SAM_DUE)

  #if defined(ARDUINO_SAM_DUE)
    #define BOARD_TYPE      "SAM DUE"
  #elif defined(__SAM3X8E__)
    #define BOARD_TYPE      "SAM SAM3X8E"
  #else
    #define BOARD_TYPE      "SAM Unknown"
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
  
  #include <BlynkSimpleWiFiNINA_DUE_WM.h>

#else
  #include <BlynkSimpleWiFiNINA_DUE.h>
  
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

#define HOST_NAME   "SAM-DUE-WiFiNINA"

#endif      //defines_h

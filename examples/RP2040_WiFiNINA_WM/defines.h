/****************************************************************************************************************************
  defines.h for SAMD_WiFiNINA_WM.ino
  For RP2040 using WiFiNINA Shield/Module

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

#if ( defined(ARDUINO_NANO_RP2040_CONNECT) || defined(ARDUINO_ARCH_RP2040) || defined(ARDUINO_RASPBERRY_PI_PICO) || \
      defined(ARDUINO_GENERIC_RP2040) || defined(ARDUINO_ADAFRUIT_FEATHER_RP2040) )
  #if defined(WIFININA_USE_RP2040)
    #undef WIFININA_USE_RP2040
    #undef WIFI_USE_RP2040
  #endif
  #define WIFININA_USE_RP2040      true
  #define WIFI_USE_RP2040          true
#else
  #error This code is intended to run only on the RP2040-based boards ! Please check your Tools->Board setting.
#endif

#if defined(WIFININA_USE_RP2040) && defined(ARDUINO_ARCH_MBED)

  #warning Using ARDUINO_ARCH_MBED
  
  #if ( defined(ARDUINO_NANO_RP2040_CONNECT)    || defined(ARDUINO_RASPBERRY_PI_PICO) || \
        defined(ARDUINO_GENERIC_RP2040) || defined(ARDUINO_ADAFRUIT_FEATHER_RP2040) )
    // Only undef known BOARD_NAME to use better one
    #undef BOARD_NAME
  #endif
  
  #if defined(ARDUINO_RASPBERRY_PI_PICO)
    #define BOARD_NAME      "MBED RASPBERRY_PI_PICO"
  #elif defined(ARDUINO_ADAFRUIT_FEATHER_RP2040)
    #define BOARD_NAME      "MBED ADAFRUIT_FEATHER_RP2040"
  #elif defined(ARDUINO_GENERIC_RP2040)
    #define BOARD_NAME      "MBED GENERIC_RP2040"
  #elif defined(ARDUINO_NANO_RP2040_CONNECT) 
    #define BOARD_NAME      "MBED NANO_RP2040_CONNECT"
  #else
    // Use default BOARD_NAME if exists
    #if !defined(BOARD_NAME)
      #define BOARD_NAME      "MBED Unknown RP2040"
    #endif
  #endif

#endif

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

  #include <BlynkSimpleWiFiNINA_RP2040_WM.h>

#else
  #include <BlynkSimpleWiFiNINA_RP2040.h>
  
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

#define HOST_NAME   "RP2040-WiFiNINA"

#endif      //defines_h

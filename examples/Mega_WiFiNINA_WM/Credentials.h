/****************************************************************************************************************************
   Credentials.h for Mega_WiFiNINA.ino
   For AVR Mega boards using WiFiNINA Shields

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

#ifndef Credentials_h
#define Credentials_h

#if USE_BLYNK_WM

/// Start Default Config Data //////////////////

/*
  // Defined in <BlynkSimpleWiFiNINA_AVR_WM.h>

  #define SSID_MAX_LEN      32
  #define PASS_MAX_LEN      64
  
  typedef struct
  {
  char wifi_ssid[SSID_MAX_LEN];
  char wifi_pw  [PASS_MAX_LEN];
  }  WiFi_Credentials;

  #define BLYNK_SERVER_MAX_LEN      32
  #define BLYNK_TOKEN_MAX_LEN       36

  typedef struct
  {
  char blynk_server[BLYNK_SERVER_MAX_LEN];
  char blynk_token [BLYNK_TOKEN_MAX_LEN];
  }  Blynk_Credentials;

  #define NUM_WIFI_CREDENTIALS      2
  #define NUM_BLYNK_CREDENTIALS     2

  typedef struct Configuration
  {
  char header         [16];
  WiFi_Credentials  WiFi_Creds  [NUM_WIFI_CREDENTIALS];
  Blynk_Credentials Blynk_Creds [NUM_BLYNK_CREDENTIALS];
  int  blynk_port;
  char board_name     [24];
  int  checkSum;
  } Blynk_WM_Configuration;

*/

bool LOAD_DEFAULT_CONFIG_DATA = true;
//bool LOAD_DEFAULT_CONFIG_DATA = false;

Blynk_WM_Configuration defaultConfig =
{
  //char header[16], dummy, not used
#if USE_SSL  
  "SSL",
#else
  "NonSSL",
#endif
  //WiFi_Creds wifi_ssid and wifi_pw
  "SSID1", "password1",
  // Blynk_Creds blynk_server blynk_token
  "account.ddns.net", "token",
  //int  blynk_port;
#if USE_SSL
  9443,
#else
  8080,
#endif
  //int  checkSum, dummy, not used
  0
};

/////////// End Default Config Data /////////////
#endif      // #if USE_BLYNK_WM

#endif    //Credentials_h

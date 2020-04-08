/****************************************************************************************************************************
   BlynkSimpleWiFiNINA_AVR.h
   For AVR boards using WiFiNINA Shields

   Blynk_WiFiNINA_WM is a library for the Mega, Teensy, SAM DUE and SAMD boards (https://github.com/khoih-prog/Blynk_WiFiNINA_WM)
   to enable easy configuration/reconfiguration and autoconnect/autoreconnect of WiFiNINA/Blynk

   Modified from Blynk library v0.6.1 https://github.com/blynkkk/blynk-library/releases
   Built by Khoi Hoang https://github.com/khoih-prog/Blynk_WM
   Licensed under MIT license
   Version: 1.0.0

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
 *****************************************************************************************************************************/


#ifndef BlynkSimpleWiFiNINA_AVR_h
#define BlynkSimpleWiFiNINA_AVR_h

#if ( defined(ESP8266) || defined(ESP32) || defined(CORE_TEENSY) )
#error This code is not intended to run on the ESP8266, ESP32 nor Teensy platform! Please check your Tools->Board setting.
#endif

#if !( defined(ARDUINO_AVR_MEGA2560) || defined(ARDUINO_AVR_MEGA) )
#error This code is intended to run on the Mega2560 platform! Please check your Tools->Board setting.
#endif

#ifndef BLYNK_INFO_CONNECTION
#define BLYNK_INFO_CONNECTION  "WiFiNINA"
#endif

#define BLYNK_SEND_ATOMIC
//#define BLYNK_USE_SSL

#include <WiFiNINA_Generic.h>

#ifdef BLYNK_USE_SSL
  #define BLYNK_SERVER_PORT BLYNK_DEFAULT_PORT_SSL
#else
  #define BLYNK_SERVER_PORT BLYNK_DEFAULT_PORT
#endif

#include <BlynkApiArduino.h>
#include <Blynk/BlynkProtocol.h>
#include <Adapters/BlynkArduinoClient.h>

class BlynkWifiCommon
    : public BlynkProtocol<BlynkArduinoClient>
{
    typedef BlynkProtocol<BlynkArduinoClient> Base;
public:
    BlynkWifiCommon(BlynkArduinoClient& transp)
        : Base(transp)
    {}

    void connectWiFi(const char* ssid, const char* pass)
    {
        int status = WiFi.status();
        // check for the presence of the shield:
        if (status == WL_NO_MODULE) 
        {
            BLYNK_LOG1(BLYNK_F("NoNINA"));
            return;
        }

        BLYNK_LOG2(BLYNK_F("FW:"), WiFi.firmwareVersion());

        // attempt to connect to Wifi network:
        while (status != WL_CONNECTED) 
        {
            BLYNK_LOG2(BLYNK_F("Con2:"), ssid);
            if (pass && strlen(pass)) 
            {
                status = WiFi.begin((char*)ssid, (char*)pass);
            } 
            else 
            {
                status = WiFi.begin((char*)ssid);
            }
            
            if (status == WL_CONNECTED)
            {
              BLYNK_LOG1(BLYNK_F("ConW OK"));
            }
            else
            {
              BLYNK_LOG1(BLYNK_F("ConW not OK"));
            }

            millis_time_t started = BlynkMillis();
            while ((status != WL_CONNECTED) &&
                  (BlynkMillis() - started < 10000))
            {
                BlynkDelay(200);
                status = WiFi.status();
            }
        }

        IPAddress myip = WiFi.localIP();
        BLYNK_LOG_IP("IP:", myip);
    }

    void config(const char* auth,
                const char* domain = BLYNK_DEFAULT_DOMAIN,
                uint16_t    port   = BLYNK_SERVER_PORT)
    {
        Base::begin(auth);
        this->conn.begin(domain, port);
    }

    void config(const char* auth,
                IPAddress   ip,
                uint16_t    port = BLYNK_SERVER_PORT)
    {
        Base::begin(auth);
        this->conn.begin(ip, port);
    }

    void begin(const char* auth,
               const char* ssid,
               const char* pass,
               const char* domain = BLYNK_DEFAULT_DOMAIN,
               uint16_t    port   = BLYNK_SERVER_PORT)
    {
        connectWiFi(ssid, pass);
        config(auth, domain, port);
        while(this->connect() != true) {}
    }

    void begin(const char* auth,
               const char* ssid,
               const char* pass,
               IPAddress   ip,
               uint16_t    port   = BLYNK_SERVER_PORT)
    {
        connectWiFi(ssid, pass);
        config(auth, ip, port);
        while(this->connect() != true) {}
    }

};

//static WiFiSSLClient _blynkWifiClient;
static WiFiClient _blynkWifiClient;

static BlynkArduinoClient _blynkTransport(_blynkWifiClient);
BlynkWifiCommon Blynk(_blynkTransport);

#include <BlynkWidgets.h>

#endif    //BlynkSimpleWiFiNINA_AVR_h

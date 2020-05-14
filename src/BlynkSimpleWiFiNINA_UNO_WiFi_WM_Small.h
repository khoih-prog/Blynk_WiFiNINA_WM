/****************************************************************************************************************************
   BlynkSimpleWiFiNINA_UNO_WiFi_WM.h
   For AVR boards using WiFiNINA Shields

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
    1.0.4   K Hoang      13/05/2020  Add support to Arduino UNO WiFi R2                                    
 *****************************************************************************************************************************/


#ifndef BlynkSimpleWiFiNINA_UNO_WiFi_WM_h
#define BlynkSimpleWiFiNINA_UNO_WiFi_WM_h

#if ( defined(ESP8266) || defined(ESP32) || defined(CORE_TEENSY) )
#error This code is not intended to run on the ESP8266, ESP32 nor Teensy platform! Please check your Tools->Board setting.
#endif

#if !( defined(ARDUINO_AVR_UNO_WIFI_DEV_ED) )
#error This code is intended to run on the Arduino UNO WiFi platform! Please check your Tools->Board setting.
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

#include "WiFiNINA_Pinout_Generic.h"
#include <WiFiWebServer.h>
#include <EEPROM.h>

#ifndef EEPROM_SIZE
#define EEPROM_SIZE     4096
#else
#if (EEPROM_SIZE > 4096)
#warning EEPROM_SIZE must be <= 4096. Reset to 4096
#undef EEPROM_SIZE
#define EEPROM_SIZE     4096
#endif
#if (EEPROM_SIZE < CONFIG_DATA_SIZE)
#warning EEPROM_SIZE must be > CONFIG_DATA_SIZE. Reset to 512
#undef EEPROM_SIZE
#define EEPROM_SIZE     512
#endif
#endif

#ifndef EEPROM_START
#define EEPROM_START     0
#else
#if (EEPROM_START + CONFIG_DATA_SIZE > EEPROM_SIZE)
#error EPROM_START + CONFIG_DATA_SIZE > EEPROM_SIZE. Please adjust.
#endif
#endif

// Configurable items besides fixed Header
#define NUM_CONFIGURABLE_ITEMS    5
typedef struct Configuration
{
  char header         [16];
  char wifi_ssid      [32];
  char wifi_pw        [64];
  char blynk_server   [32];
  char blynk_token    [36];
  int  blynk_port; 
  int  checkSum;
} Blynk_WM_Configuration;

// Currently CONFIG_DATA_SIZE  =   188
uint16_t CONFIG_DATA_SIZE = sizeof(Blynk_WM_Configuration);

#define root_html_template "\
<!DOCTYPE html><html><head><title>MEGA_WM_NINA</title><style>.em{padding-bottom:0px;}div,input{padding:5px;font-size:1em;}input{width:95%;}\
body{text-align: center;}button{background-color:#16A1E7;color:#fff;line-height:2.4rem;font-size:1.2rem;width:100%;}fieldset{border-radius:0.3rem;margin:0px;}\
</style></head><div style=\"text-align:left;display:inline-block;min-width:260px;\">\
<fieldset><div><label>SSID</label><input id=\"id\"><div></div></div><div><label>PWD</label><input id=\"pw\"><div></div></div></fieldset>\
<fieldset><div><label>Server</label><input id=\"sv\"><div></div></div><div><label>Token</label><input id=\"tk\"><div></div></div>\
<div><label>Port</label><input value=\"[[pt]]\"id=\"pt\"><div></div></div></fieldset>\
<button onclick=\"sv()\">Save</button></div><script id=\"jsbin-javascript\">\
function udVal(key,val){var request=new XMLHttpRequest();var url='/?key='+key+'&value='+encodeURIComponent(val);request.open('GET',url,false);request.send(null);}\
function sv(){udVal('id',document.getElementById('id').value);udVal('pw',document.getElementById('pw').value);udVal('sv',document.getElementById('sv').value);\
udVal('tk',document.getElementById('tk').value);udVal('pt',document.getElementById('pt').value);alert('Updated');}</script></html>"

#define BLYNK_SERVER_HARDWARE_PORT    8080

String IPAddressToString(IPAddress _address)
{
  String str = String(_address[0]);
  str += ".";
  str += String(_address[1]);
  str += ".";
  str += String(_address[2]);
  str += ".";
  str += String(_address[3]);
  return str;
}

class BlynkWifiCommon
    : public BlynkProtocol<BlynkArduinoClient>
{
    typedef BlynkProtocol<BlynkArduinoClient> Base;
public:
    BlynkWifiCommon(BlynkArduinoClient& transp)
        : Base(transp)
    {}

    bool connectWiFi(const char* ssid, const char* pass)
    {
        int status = WiFi.status();
        // check for the presence of the shield:
        if (status == WL_NO_MODULE) {
            BLYNK_LOG1(BLYNK_F("NoNINA"));
            return false;
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

            millis_time_t started = BlynkMillis();
            while ((status != WL_CONNECTED) && (BlynkMillis() - started < 10000))
            {
                BlynkDelay(200);
                status = WiFi.status();
            }
        }

        IPAddress myip = WiFi.localIP();
        BLYNK_LOG_IP("IP:", myip);
        
        return (status == WL_CONNECTED);
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
        if (connectWiFi(ssid, pass))
          BLYNK_LOG1(BLYNK_F("b:conW OK"));
          
        config(auth, domain, port);
        while(this->connect() != true) {}
    }

    void begin(const char* auth,
               const char* ssid,
               const char* pass,
               IPAddress   ip,
               uint16_t    port   = BLYNK_SERVER_PORT)
    {
        if (connectWiFi(ssid, pass))
          BLYNK_LOG1(BLYNK_F("b:conW OK"));
          
        config(auth, ip, port);
        while(this->connect() != true) {}
    }

    void begin(const char *iHostname = "")
    {
#define TIMEOUT_CONNECT_WIFI			30000

      if (iHostname[0] == 0)
      {
        String _hostname = "Mega-NINA";

        _hostname.toUpperCase();

        getRFC952_hostname(_hostname.c_str());

      }
      else
      {
        // Prepare and store the hostname only not NULL
        getRFC952_hostname(iHostname);
      }

      BLYNK_LOG2(BLYNK_F("Hostname="), RFC952_hostname);

      if (getConfigData())
      {
        hadConfigData = true;

        config(Blynk_WM_config.blynk_token, Blynk_WM_config.blynk_server, Blynk_WM_config.blynk_port);

        if (connectToWifi(TIMEOUT_CONNECT_WIFI))
        {
          BLYNK_LOG1(BLYNK_F("b:WOK.TryB"));

          int i = 0;
          while ( (i++ < 10) && !this->connect() );

          if  (connected())
          {
            BLYNK_LOG1(BLYNK_F("b:WBOK"));
          }
          else
          {
            BLYNK_LOG1(BLYNK_F("b:WOK,Bno"));
            // failed to connect to Blynk server, will start configuration mode
            startConfigurationMode();
          }
        }
        else
        {
          BLYNK_LOG1(BLYNK_F("b:FailW+B"));
          // failed to connect to Blynk server, will start configuration mode
          startConfigurationMode();
        }
      }
      else
      {
        BLYNK_LOG1(BLYNK_F("b:Nodat.Stay"));
        // failed to connect to Blynk server, will start configuration mode
        hadConfigData = false;
        startConfigurationMode();
      }
    }

#ifndef TIMEOUT_RECONNECT_WIFI
#define TIMEOUT_RECONNECT_WIFI   10000L
#else
    // Force range of user-defined TIMEOUT_RECONNECT_WIFI between 10-60s
#if (TIMEOUT_RECONNECT_WIFI < 10000L)
#warning TIMEOUT_RECONNECT_WIFI too low. Reseting to 10000
#undef TIMEOUT_RECONNECT_WIFI
#define TIMEOUT_RECONNECT_WIFI   10000L
#elif (TIMEOUT_RECONNECT_WIFI > 60000L)
#warning TIMEOUT_RECONNECT_WIFI too high. Reseting to 60000
#undef TIMEOUT_RECONNECT_WIFI
#define TIMEOUT_RECONNECT_WIFI   60000L
#endif
#endif

#ifndef RESET_IF_CONFIG_TIMEOUT
#define RESET_IF_CONFIG_TIMEOUT   true
#endif

#ifndef CONFIG_TIMEOUT_RETRYTIMES_BEFORE_RESET
#define CONFIG_TIMEOUT_RETRYTIMES_BEFORE_RESET          10
#else
    // Force range of user-defined TIMES_BEFORE_RESET between 2-100
#if (CONFIG_TIMEOUT_RETRYTIMES_BEFORE_RESET < 2)
#warning CONFIG_TIMEOUT_RETRYTIMES_BEFORE_RESET too low. Reseting to 2
#undef CONFIG_TIMEOUT_RETRYTIMES_BEFORE_RESET
#define CONFIG_TIMEOUT_RETRYTIMES_BEFORE_RESET   2
#elif (CONFIG_TIMEOUT_RETRYTIMES_BEFORE_RESET > 100)
#warning CONFIG_TIMEOUT_RETRYTIMES_BEFORE_RESET too high. Resetting to 100
#undef CONFIG_TIMEOUT_RETRYTIMES_BEFORE_RESET
#define CONFIG_TIMEOUT_RETRYTIMES_BEFORE_RESET   100
#endif
#endif

    void run()
    {
      static int retryTimes = 0;

      // Lost connection in running. Give chance to reconfig.
      if ( WiFi.status() != WL_CONNECTED || !connected() )
      {
        // If configTimeout but user hasn't connected to configWeb => try to reconnect WiFi / Blynk.
        // But if user has connected to configWeb, stay there until done, then reset hardware
        if ( configuration_mode && ( configTimeout == 0 ||  millis() < configTimeout ) )
        {
          retryTimes = 0;

          if (server)
            server->handleClient();

          return;
        }
        else
        {
#if RESET_IF_CONFIG_TIMEOUT
          // If we're here but still in configuration_mode, permit running TIMES_BEFORE_RESET times before reset hardware
          // to permit user another chance to config.
          if ( configuration_mode && (configTimeout != 0) )
          {
            if (++retryTimes <= CONFIG_TIMEOUT_RETRYTIMES_BEFORE_RESET)
            {
              BLYNK_LOG2(BLYNK_F("r:Wlost&TOut.ConW+B.Retry#"), retryTimes);
            }
            else
            {
              resetFunc();  //call reset
            }
          }
#endif

          // Not in config mode, try reconnecting before forcing to config mode
          if ( WiFi.status() != WL_CONNECTED )
          {
            BLYNK_LOG1(BLYNK_F("r:Wlost.ReconW+B"));
            if (connectToWifi(TIMEOUT_RECONNECT_WIFI))
            {
              BLYNK_LOG1(BLYNK_F("r:WOK.TryB"));

              if (connect())
              {
                BLYNK_LOG1(BLYNK_F("r:W+BOK"));
              }
            }
          }
          else
          {
            BLYNK_LOG1(BLYNK_F("r:Blost.TryB"));
            if (connect())
            {
              BLYNK_LOG1(BLYNK_F("r:BOK"));
            }
          }

          //BLYNK_LOG1(BLYNK_F("run: Lost connection => configMode"));
          //startConfigurationMode();
        }
      }
      else if (configuration_mode)
      {
        configuration_mode = false;
        BLYNK_LOG1(BLYNK_F("r:gotW+Bback"));
      }

      if (connected())
      {
        Base::run();
      }
    }

    void setHostname(void)
    {
      if (RFC952_hostname[0] != 0)
      {
        WiFi.setHostname(RFC952_hostname);
      }
    }
    
    void setConfigPortalIP(IPAddress portalIP = IPAddress(192, 168, 4, 1))
    {
      portal_apIP = portalIP;
    }

    void setConfigPortalChannel(uint8_t channel = 10)
    {
      AP_channel = channel;
    }

    void setConfigPortal(String ssid = "", String pass = "")
    {
      portal_ssid = ssid;
      portal_pass = pass;
    }

    void setSTAStaticIPConfig(IPAddress ip, IPAddress gw, IPAddress sn = IPAddress(255, 255, 255, 0),
                              IPAddress dns_address_1 = IPAddress(0, 0, 0, 0),
                              IPAddress dns_address_2 = IPAddress(0, 0, 0, 0))
    {
      static_IP     = ip;
      static_GW     = gw;
      static_SN     = sn;

      // Default to local GW
      if (dns_address_1 == IPAddress(0, 0, 0, 0))
        static_DNS1   = gw;
      else
        static_DNS1   = dns_address_1;

      // Default to Google DNS (8, 8, 8, 8)
      if (dns_address_2 == IPAddress(0, 0, 0, 0))
        static_DNS2   = IPAddress(8, 8, 8, 8);
      else
        static_DNS2   = dns_address_2;
    }

    String getServerName()
    {
      if (!hadConfigData)
        getConfigData();

      return (String(Blynk_WM_config.blynk_server));
    }

    String getToken()
    {
      if (!hadConfigData)
        getConfigData();

      return (String(Blynk_WM_config.blynk_token));
    }

    int getHWPort()
    {
      if (!hadConfigData)
        getConfigData();

      return (Blynk_WM_config.blynk_port);
    }

    Blynk_WM_Configuration* getFullConfigData(Blynk_WM_Configuration *configData)
    {
      if (!hadConfigData)
        getConfigData();

      // Check if NULL pointer
      if (configData)
        memcpy(configData, &Blynk_WM_config, sizeof(Blynk_WM_Configuration));

      return (configData);
    }

    String getLocalIP(void)
    {
      ipAddress =IPAddressToString(WiFi.localIP());

      //BLYNK_LOG2(BLYNK_F("getLocalIP: IP = "), ipAddress);
      return ipAddress;
    }

    void clearConfigData()
    {
      memset(&Blynk_WM_config, 0, sizeof(Blynk_WM_config));
      EEPROM.put(EEPROM_START, Blynk_WM_config);
    }

    void resetFunc()
    {
      asm volatile ("jmp 0");
    }

  private:
    String ipAddress = "0.0.0.0";

    WiFiWebServer* server;
    bool configuration_mode = false;

    unsigned long configTimeout;
    bool hadConfigData = false;

    Blynk_WM_Configuration Blynk_WM_config;

    String macAddress = "";
    bool wifi_connected = false;

    // For Config Portal, from Blynk_WM v1.0.5
    IPAddress portal_apIP = IPAddress(192, 168, 4, 1);
    uint8_t AP_channel = 10;

    String portal_ssid = "";
    String portal_pass = "";

    // For static IP, from Blynk_WM v1.0.5
    IPAddress static_IP   = IPAddress(0, 0, 0, 0);
    IPAddress static_GW   = IPAddress(0, 0, 0, 0);
    IPAddress static_SN   = IPAddress(255, 255, 255, 0);
    IPAddress static_DNS1 = IPAddress(0, 0, 0, 0);
    IPAddress static_DNS2 = IPAddress(0, 0, 0, 0);

#define RFC952_HOSTNAME_MAXLEN      24
    char RFC952_hostname[RFC952_HOSTNAME_MAXLEN + 1];

    char* getRFC952_hostname(const char* iHostname)
    {
      memset(RFC952_hostname, 0, sizeof(RFC952_hostname));

      size_t len = ( RFC952_HOSTNAME_MAXLEN < strlen(iHostname) ) ? RFC952_HOSTNAME_MAXLEN : strlen(iHostname);

      size_t j = 0;

      for (size_t i = 0; i < len - 1; i++)
      {
        if ( isalnum(iHostname[i]) || iHostname[i] == '-' )
        {
          RFC952_hostname[j] = iHostname[i];
          j++;
        }
      }
      // no '-' as last char
      if ( isalnum(iHostname[len - 1]) || (iHostname[len - 1] != '-') )
        RFC952_hostname[j] = iHostname[len - 1];

      return RFC952_hostname;
    }

    void displayConfigData(void)
    {
      BLYNK_LOG6(BLYNK_F("Hdr="),  Blynk_WM_config.header, BLYNK_F(",SSID="), Blynk_WM_config.wifi_ssid,
                 BLYNK_F(",PW="),  Blynk_WM_config.wifi_pw);
      BLYNK_LOG6(BLYNK_F("Svr="),  Blynk_WM_config.blynk_server, BLYNK_F(",Prt="), Blynk_WM_config.blynk_port,
                 BLYNK_F(",Tok="), Blynk_WM_config.blynk_token);
    }

    void displayWiFiData(void)
    {
      BLYNK_LOG6(BLYNK_F("IP = "), IPAddressToString(WiFi.localIP()), BLYNK_F(", GW = "), IPAddressToString(WiFi.gatewayIP()),
                 BLYNK_F(", SN = "), IPAddressToString(WiFi.subnetMask()));
    }


#define BLYNK_BOARD_TYPE   "SHD_NINA"
#define NO_CONFIG           "blank"



    int calcChecksum()
    {
      int checkSum = 0;
      for (uint16_t index = 0; index < (sizeof(Blynk_WM_config) - sizeof(Blynk_WM_config.checkSum)); index++)
      {
        checkSum += * ( ( (byte*) &Blynk_WM_config ) + index);
      }

      return checkSum;
    }

    bool getConfigData()
    {
      EEPROM.get(EEPROM_START, Blynk_WM_config);

      int calChecksum = calcChecksum();

      BLYNK_LOG4(BLYNK_F("CCSum="), calChecksum, BLYNK_F(",RCSsum="), Blynk_WM_config.checkSum);

      if ( (strncmp(Blynk_WM_config.header, BLYNK_BOARD_TYPE, strlen(BLYNK_BOARD_TYPE)) != 0) ||
           (calChecksum != Blynk_WM_config.checkSum) )
      {
        memset(&Blynk_WM_config, 0, sizeof(Blynk_WM_config));

        //EEPROM.put(EEPROM_START, Blynk_WM_config);

        BLYNK_LOG2(BLYNK_F("InitEEPROM sz="), EEPROM.length());
        // doesn't have any configuration
        strcpy(Blynk_WM_config.header,           BLYNK_BOARD_TYPE);
        strcpy(Blynk_WM_config.wifi_ssid,        NO_CONFIG);
        strcpy(Blynk_WM_config.wifi_pw,          NO_CONFIG);
        strcpy(Blynk_WM_config.blynk_server,     NO_CONFIG);
        Blynk_WM_config.blynk_port = BLYNK_SERVER_HARDWARE_PORT;
        strcpy(Blynk_WM_config.blynk_token,      NO_CONFIG);
        // Don't need
        Blynk_WM_config.checkSum = 0;

        EEPROM.put(EEPROM_START, Blynk_WM_config);

        return false;
      }
      else if ( !strncmp(Blynk_WM_config.wifi_ssid,       NO_CONFIG, strlen(NO_CONFIG))   ||
                !strncmp(Blynk_WM_config.wifi_pw,         NO_CONFIG, strlen(NO_CONFIG) )  ||
                !strncmp(Blynk_WM_config.blynk_server,    NO_CONFIG, strlen(NO_CONFIG) )  ||
                !strncmp(Blynk_WM_config.blynk_token,     NO_CONFIG, strlen(NO_CONFIG) ) )
      {
        // If SSID, PW, Server,Token ="nothing", stay in config mode forever until having config Data.
        return false;
      }
      else
      {
        displayConfigData();
      }

      return true;
    }

    void saveConfigData()
    {
      int calChecksum = calcChecksum();
      Blynk_WM_config.checkSum = calChecksum;
      BLYNK_LOG4(BLYNK_F("SaveEEPROM,sz="), EEPROM.length(), BLYNK_F(",CSum="), calChecksum);

      EEPROM.put(EEPROM_START, Blynk_WM_config);
    }

    bool connectToWifi(int timeout)
    {
      int sleep_time = 250;
      unsigned long currMillis = millis();

      BLYNK_LOG1(BLYNK_F("con2WF:start"));

      // New from Blynk_WM v1.0.5
      if (static_IP != IPAddress(0, 0, 0, 0))
      {
        BLYNK_LOG1(BLYNK_F("UseStatIP"));
        // Set DNS1 = GW
        WiFi.config(static_IP, static_GW, static_GW, static_SN);
      }
      
      setHostname();

      while ( (WiFi.status() != WL_CONNECTED) && ( 0 < timeout ) && ( (millis() - currMillis) < (unsigned long) timeout )  )
      {
        BLYNK_LOG2(BLYNK_F("con2WF:ms="), millis() - currMillis);

        if (connectWiFi(Blynk_WM_config.wifi_ssid, Blynk_WM_config.wifi_pw))
        {
          wifi_connected = true;
        }
        else
        {
          delay(sleep_time);
          timeout -= sleep_time;
        }
      }

      if (wifi_connected)
      {
        BLYNK_LOG1(BLYNK_F("con2WF:OK"));
        displayWiFiData();
      }
      else
      {
        BLYNK_LOG1(BLYNK_F("con2WF:failed"));
      }

      return wifi_connected;
    }

    void handleRequest()
    {
      if (server)
      {
        String key    = server->arg("key");
        String value  = server->arg("value");

        static int number_items_Updated = 0;

        if (key == "" && value == "")
        {
          String result = root_html_template;

          //BLYNK_LOG1(BLYNK_F("h:repl"));

          // Reset configTimeout to stay here until finished.
          configTimeout = 0;

          result.replace("[[id]]",     Blynk_WM_config.wifi_ssid);
          result.replace("[[pw]]",     Blynk_WM_config.wifi_pw);
          result.replace("[[sv]]",     Blynk_WM_config.blynk_server);
          result.replace("[[pt]]",     String(Blynk_WM_config.blynk_port));
          result.replace("[[tk]]",     Blynk_WM_config.blynk_token);

          server->send(200, "text/html", result);
          //BLYNK_LOG1(BLYNK_F("h:sent"));

          return;
        }

        if (number_items_Updated == 0)
        {
          memset(&Blynk_WM_config, 0, sizeof(Blynk_WM_config));
          strcpy(Blynk_WM_config.header, BLYNK_BOARD_TYPE);
        }

        if (key == "id")
        {
          number_items_Updated++;
          if (strlen(value.c_str()) < sizeof(Blynk_WM_config.wifi_ssid) - 1)
            strcpy(Blynk_WM_config.wifi_ssid, value.c_str());
          else
            strncpy(Blynk_WM_config.wifi_ssid, value.c_str(), sizeof(Blynk_WM_config.wifi_ssid) - 1);
        }
        else if (key == "pw")
        {
          number_items_Updated++;
          if (strlen(value.c_str()) < sizeof(Blynk_WM_config.wifi_pw) - 1)
            strcpy(Blynk_WM_config.wifi_pw, value.c_str());
          else
            strncpy(Blynk_WM_config.wifi_pw, value.c_str(), sizeof(Blynk_WM_config.wifi_pw) - 1);
        }

        else if (key == "sv")
        {
          number_items_Updated++;
          if (strlen(value.c_str()) < sizeof(Blynk_WM_config.blynk_server) - 1)
            strcpy(Blynk_WM_config.blynk_server, value.c_str());
          else
            strncpy(Blynk_WM_config.blynk_server, value.c_str(), sizeof(Blynk_WM_config.blynk_server) - 1);
        }
        else if (key == "tk")
        {
          number_items_Updated++;
          if (strlen(value.c_str()) < sizeof(Blynk_WM_config.blynk_token) - 1)
            strcpy(Blynk_WM_config.blynk_token, value.c_str());
          else
            strncpy(Blynk_WM_config.blynk_token, value.c_str(), sizeof(Blynk_WM_config.blynk_token) - 1);
        }
        else if (key == "pt")
        {
          number_items_Updated++;
          Blynk_WM_config.blynk_port = value.toInt();
        }        

        server->send(200, "text/html", "OK");

        if (number_items_Updated == NUM_CONFIGURABLE_ITEMS)
        {
          //BLYNK_LOG1(BLYNK_F("h:UpdEEPROM"));

          saveConfigData();

          //BLYNK_LOG1(BLYNK_F("h:Rst"));

          // TO DO : what command to reset
          // Delay then reset the board after save data
          delay(1000);
          resetFunc();  //call reset
        }
      }   // if (server)
    }

    void startConfigurationMode()
    {
#define CONFIG_TIMEOUT			60000L

      if ( (portal_ssid == "") || portal_pass == "" )
      {
        String randomNum = String(random(0xFFFFFF), HEX);
        randomNum.toUpperCase();

        portal_ssid = "Mega_" + randomNum;
        portal_pass = "MyMega_" + randomNum;
      }

      WiFi.config(portal_apIP);
      
      BLYNK_LOG6(BLYNK_F("stConf:SSID="), portal_ssid, BLYNK_F(",PW="), portal_pass, BLYNK_F(",IP="), portal_apIP);

      // start access point, AP only, channel 10 or configured
      WiFi.beginAP(portal_ssid.c_str(), portal_pass.c_str(), AP_channel);

      if (!server)
      {
        server = new WiFiWebServer;
      }

      // Don't know if it's working or not. Can we use ESP8266_Lib wifi TCP server for this ??

      //See https://stackoverflow.com/questions/39803135/c-unresolved-overloaded-function-type?rq=1

      if (server)
      {
        server->on("/", [this]() { handleRequest(); });
        server->begin();
      }

      // If there is no saved config Data, stay in config mode forever until having config Data.
      // or SSID, PW, Server,Token ="nothing"
      if (hadConfigData)
        configTimeout = millis() + CONFIG_TIMEOUT;
      else
        configTimeout = 0;

      configuration_mode = true;
    }

};


//static WiFiSSLClient _blynkWifiClient;
static WiFiClient _blynkWifiClient;

static BlynkArduinoClient _blynkTransport(_blynkWifiClient);
BlynkWifiCommon Blynk(_blynkTransport);

#include <BlynkWidgets.h>

#endif    //BlynkSimpleWiFiNINA_UNO_WiFi_WM_h

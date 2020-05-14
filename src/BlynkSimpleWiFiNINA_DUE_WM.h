/****************************************************************************************************************************
   BlynkSimpleWiFiNINA_DUE_WM.h
   For SAM DUE boards using WiFiNINA Shields

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


#ifndef BlynkSimpleWiFiNINA_DUE_WM_h
#define BlynkSimpleWiFiNINA_DUE_WM_h

#if ( defined(ARDUINO_SAM_DUE) || defined(__SAM3X8E__) )
#if defined(BLYNK_WIFININA_USE_SAM_DUE)
#undef BLYNK_WIFININA_USE_SAM_DUE
#endif
#define BLYNK_WIFININA_USE_SAM_DUE      true
#endif

#if ( defined(ESP8266) || defined(ESP32) || defined(ARDUINO_AVR_MEGA2560) || defined(ARDUINO_AVR_MEGA) || defined(__SAMD21G18A__)\
   || defined(__SAMD51__) || defined(__SAMD51J20A__) || defined(__SAMD51J19A__) || defined(__SAMD51G19A__) || defined(NRF52_SERIES)\
   || defined(ARDUINO_NRF52_ADAFRUIT) || defined(STM32F0) || defined(STM32F1) || defined(STM32F2) || defined(STM32F3)\
   ||defined(STM32F4) || defined(STM32F7) || defined(CORE_TEENSY) || !(BLYNK_WIFININA_USE_SAM_DUE) )
#error This code is intended to run on the SAM DUE platform! Please check your Tools->Board setting.
#endif

#ifndef BLYNK_WM_DEBUG
#define BLYNK_WM_DEBUG      0
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

//Use DueFlashStorage to simulate EEPROM
#include <DueFlashStorage.h>                 //https://github.com/sebnil/DueFlashStorage

DueFlashStorage dueFlashStorageData;

///////// NEW for DRD /////////////
// These defines must be put before #include <DoubleResetDetector_Generic.h>
// to select where to store DoubleResetDetector_Generic's variable.
// Otherwise, library will use default EEPROM storage
#define  DRD_FLAG_DATA_SIZE     4

#ifndef DRD_GENERIC_DEBUG
#define DRD_GENERIC_DEBUG     false
#endif

#include <DoubleResetDetector_Generic.h>      //https://github.com/khoih-prog/DoubleResetDetector_Generic

// Number of seconds after reset during which a
// subseqent reset will be considered a double reset.
#define DRD_TIMEOUT 10

// RTC Memory Address for the DoubleResetDetector to use
#define DRD_ADDRESS 0

DoubleResetDetector_Generic* drd;

///////// NEW for DRD /////////////

//NEW
#define MAX_ID_LEN                5
#define MAX_DISPLAY_NAME_LEN      16

typedef struct
{
  char id             [MAX_ID_LEN + 1];
  char displayName    [MAX_DISPLAY_NAME_LEN + 1];
  char *pdata;
  uint8_t maxlen;
} MenuItem;
//

///NEW
extern uint16_t NUM_MENU_ITEMS;
extern MenuItem myMenuItems [];

#define SSID_MAX_LEN      32
//From v1.0.10, WPA2 passwords can be up to 63 characters long.
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

// Configurable items besides fixed Header
#define NUM_CONFIGURABLE_ITEMS    ( 2 + (2 * NUM_WIFI_CREDENTIALS) + (2 * NUM_BLYNK_CREDENTIALS) )
typedef struct Configuration
{
  char header         [16];
  WiFi_Credentials  WiFi_Creds  [NUM_WIFI_CREDENTIALS];
  Blynk_Credentials Blynk_Creds [NUM_BLYNK_CREDENTIALS];
  int  blynk_port;
  char board_name     [24];
  int  checkSum;
} Blynk_WM_Configuration;
// Currently CONFIG_DATA_SIZE  =  ( 48 + (96 * NUM_WIFI_CREDENTIALS) + (68 * NUM_BLYNK_CREDENTIALS) ) = 376

uint16_t CONFIG_DATA_SIZE = sizeof(Blynk_WM_Configuration);

///New from v1.0.13
extern bool LOAD_DEFAULT_CONFIG_DATA;
extern Blynk_WM_Configuration defaultConfig;

// -- HTML page fragments
const char WIFININA_HTML_HEAD[]     /*PROGMEM*/ = "<!DOCTYPE html><html><head><title>BlynkWiFiNINA_DUE_WM</title><style>div,input{padding:2px;font-size:1em;}input{width:95%;}\
body{text-align: center;}button{background-color:#16A1E7;color:#fff;line-height:2.4rem;font-size:1.2rem;width:100%;}fieldset{border-radius:0.5rem;margin:0px;}\
</style></head><div style=\"text-align:left;display:inline-block;min-width:260px;\">\
<fieldset><div><label>WiFi SSID</label><input value=\"[[id]]\"id=\"id\"><div></div></div>\
<div><label>PWD</label><input value=\"[[pw]]\"id=\"pw\"><div></div></div>\
<div><label>WiFi SSID1</label><input value=\"[[id1]]\"id=\"id1\"><div></div></div>\
<div><label>PWD1</label><input value=\"[[pw1]]\"id=\"pw1\"><div></div></div></fieldset>\
<fieldset><div><label>Blynk Server</label><input value=\"[[sv]]\"id=\"sv\"><div></div></div>\
<div><label>Token</label><input value=\"[[tk]]\"id=\"tk\"><div></div></div>\
<div><label>Blynk Server1</label><input value=\"[[sv1]]\"id=\"sv1\"><div></div></div>\
<div><label>Token1</label><input value=\"[[tk1]]\"id=\"tk1\"><div></div></div>\
<div><label>Port</label><input value=\"[[pt]]\"id=\"pt\"><div></div></div></fieldset>\
<fieldset><div><label>Board Name</label><input value=\"[[nm]]\"id=\"nm\"><div></div></div></fieldset>";
const char WIFININA_FLDSET_START[]  /*PROGMEM*/ = "<fieldset>";
const char WIFININA_FLDSET_END[]    /*PROGMEM*/ = "</fieldset>";
const char WIFININA_HTML_PARAM[]    /*PROGMEM*/ = "<div><label>{b}</label><input value='[[{v}]]'id='{i}'><div></div></div>";
const char WIFININA_HTML_BUTTON[]   /*PROGMEM*/ = "<button onclick=\"sv()\">Save</button></div>";
const char WIFININA_HTML_SCRIPT[]   /*PROGMEM*/ = "<script id=\"jsbin-javascript\">\
function udVal(key,val){var request=new XMLHttpRequest();var url='/?key='+key+'&value='+encodeURIComponent(val);request.open('GET',url,false);request.send(null);}\
function sv(){udVal('id',document.getElementById('id').value);udVal('pw',document.getElementById('pw').value);\
udVal('id1',document.getElementById('id1').value);udVal('pw1',document.getElementById('pw1').value);\
udVal('sv',document.getElementById('sv').value);udVal('tk',document.getElementById('tk').value);\
udVal('sv1',document.getElementById('sv1').value);udVal('tk1',document.getElementById('tk1').value);\
udVal('pt',document.getElementById('pt').value);udVal('nm',document.getElementById('nm').value);";

const char WIFININA_HTML_SCRIPT_ITEM[]  /*PROGMEM*/ = "udVal('{d}',document.getElementById('{d}').value);";
const char WIFININA_HTML_SCRIPT_END[]   /*PROGMEM*/ = "alert('Updated');}</script>";
const char WIFININA_HTML_END[]          /*PROGMEM*/ = "</html>";
///


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

        BLYNK_LOG2(BLYNK_F("WiFiNINA FW Version:"), WiFi.firmwareVersion());

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
          BLYNK_LOG1(BLYNK_F("b:ConWOK"));
          
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
          BLYNK_LOG1(BLYNK_F("b:ConWOK"));
          
        config(auth, ip, port);
        while(this->connect() != true) {}
    }

    void begin(const char *iHostname = "")
    {
#define TIMEOUT_CONNECT_WIFI			20000

      //// New DRD ////
      drd = new DoubleResetDetector_Generic(DRD_TIMEOUT, DRD_ADDRESS);    
      bool noConfigPortal = true;
   
      if (drd->detectDoubleReset())
      {
#if ( BLYNK_WM_DEBUG > 1)      
        BLYNK_LOG1(BLYNK_F("Double Reset Detected"));
#endif        
        noConfigPortal = false;
      }
      //// New DRD ////
#if ( BLYNK_WM_DEBUG > 2)      
      BLYNK_LOG1(BLYNK_F("======= Start Default Config Data ======="));
      displayConfigData(defaultConfig);
#endif

      if (iHostname[0] == 0)
      {
        String _hostname = "SAMDUE-WiFiNINA";

        _hostname.toUpperCase();

        getRFC952_hostname(_hostname.c_str());

      }
      else
      {
        // Prepare and store the hostname only not NULL
        getRFC952_hostname(iHostname);
      }

      BLYNK_LOG2(BLYNK_F("Hostname="), RFC952_hostname);

#if ( BLYNK_WM_DEBUG > 2)        
        BLYNK_LOG1(noConfigPortal? BLYNK_F("bg: noConfigPortal = true") : BLYNK_F("bg: noConfigPortal = false"));
#endif       

      //// New DRD ////
      //  noConfigPortal when getConfigData() OK and no DRD'ed
      if (getConfigData() && noConfigPortal)
      //// New DRD ////
      {
        hadConfigData = true;

        if (connectMultiWiFi(TIMEOUT_CONNECT_WIFI))
        {
          BLYNK_LOG1(BLYNK_F("b:WOK.TryB"));

          int i = 0;
          while ( (i++ < 10) && !connectMultiBlynk() );

          if  (connected())
          {
            BLYNK_LOG1(BLYNK_F("b:WBOK"));
          }
          else
          {
            BLYNK_LOG1(BLYNK_F("b:WOK,BNo"));
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
      
      //// New DRD ////
      // Call the double reset detector loop method every so often,
      // so that it can recognise when the timeout expires.
      // You can also call drd.stop() when you wish to no longer
      // consider the next reset as a double reset.
      drd->loop();
      //// New DRD ////

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
            BLYNK_LOG1(BLYNK_F("r:WLost.ReconW+B"));

            if (connectMultiWiFi(TIMEOUT_CONNECT_WIFI))
            {
              BLYNK_LOG1(BLYNK_F("r:WOK.TryB"));

              if (connectMultiBlynk())
              {
                BLYNK_LOG1(BLYNK_F("r:W+BOK"));
              }
            }
          }
          else
          {
            BLYNK_LOG1(BLYNK_F("r:BLost.TryB"));
            
            //if (connect())
            if (connectMultiBlynk())
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
        BLYNK_LOG1(BLYNK_F("r:GotW+BBack"));
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
    
    String getWiFiSSID(uint8_t index)
    { 
      if (index >= NUM_WIFI_CREDENTIALS)
        return String("");
        
      if (!hadConfigData)
        getConfigData();

      return (String(Blynk_WM_config.WiFi_Creds[index].wifi_ssid));
    }

    String getWiFiPW(uint8_t index)
    {
      if (index >= NUM_WIFI_CREDENTIALS)
        return String("");
        
      if (!hadConfigData)
        getConfigData();

      return (String(Blynk_WM_config.WiFi_Creds[index].wifi_pw));
    }

    String getServerName(uint8_t index = 255)
    {
      if (index == 255)
      {
        // Current connected Blynk Server
        index = currentBlynkServerIndex;
      }
        
      if (index >= NUM_BLYNK_CREDENTIALS)
        return String("");

      if (!hadConfigData)
        getConfigData();

      return (String(Blynk_WM_config.Blynk_Creds[index].blynk_server));
    }

    String getToken(uint8_t index = 255)
    {
      if (index == 255)
      {
        // Current connected Blynk Server
        index = currentBlynkServerIndex;
      }
          
      if (index >= NUM_BLYNK_CREDENTIALS)
        return String("");

      if (!hadConfigData)
        getConfigData();

      return (String(Blynk_WM_config.Blynk_Creds[index].blynk_token));
    }
    
    String getBoardName()
    {
      if (!hadConfigData)
        getConfigData();

      return (String(Blynk_WM_config.board_name));
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
      
      for (int i = 0; i < NUM_MENU_ITEMS; i++)
      {
        // Actual size of pdata is [maxlen + 1]
        memset(myMenuItems[i].pdata, 0, myMenuItems[i].maxlen + 1);
      }
         
      saveConfigData();
    }

    void resetFunc()
    {
      void(*resetFunc)(void) = 0;
      resetFunc();
    }


  private:
    String ipAddress = "0.0.0.0";

    WiFiWebServer* server;
    bool configuration_mode = false;

    unsigned long configTimeout;
    bool hadConfigData = false;

    Blynk_WM_Configuration Blynk_WM_config;
    
    uint16_t totalDataSize = 0;
    uint8_t currentBlynkServerIndex = 255;

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

    void displayConfigData(Blynk_WM_Configuration configData)
    {
      BLYNK_LOG4(BLYNK_F("Hdr="),       configData.header,
                 BLYNK_F(",BrdName="),  configData.board_name);
      BLYNK_LOG4(BLYNK_F("SSID="),      configData.WiFi_Creds[0].wifi_ssid,
                 BLYNK_F(",PW="),       configData.WiFi_Creds[0].wifi_pw);
      BLYNK_LOG4(BLYNK_F("SSID1="),     configData.WiFi_Creds[1].wifi_ssid,
                 BLYNK_F(",PW1="),      configData.WiFi_Creds[1].wifi_pw);
      BLYNK_LOG4(BLYNK_F("Server="),    configData.Blynk_Creds[0].blynk_server,
                 BLYNK_F(",Token="),    configData.Blynk_Creds[0].blynk_token);
      BLYNK_LOG4(BLYNK_F("Server1="),   configData.Blynk_Creds[1].blynk_server,
                 BLYNK_F(",Token1="),   configData.Blynk_Creds[1].blynk_token);
      BLYNK_LOG2(BLYNK_F("Port="),      configData.blynk_port);
      BLYNK_LOG1(BLYNK_F("======= End Config Data ======="));
    }

    void displayWiFiData(void)
    {
      BLYNK_LOG6(BLYNK_F("IP = "), IPAddressToString(WiFi.localIP()), BLYNK_F(", GW = "), IPAddressToString(WiFi.gatewayIP()),
                 BLYNK_F(", SN = "), IPAddressToString(WiFi.subnetMask()));
    }


#define BLYNK_BOARD_TYPE   "SHD_WiFiNINA"
#define WM_NO_CONFIG          "blank"

    uint16_t EEPROM_SIZE = (IFLASH1_PAGE_SIZE / sizeof(byte)) * 4;

#ifndef EEPROM_START
#define EEPROM_START     0
#warning EEPROM_START not defined. Set to 0
#endif

// Starting positon to store Blynk8266_WM_config
#define BLYNK_EEPROM_START    (EEPROM_START + DRD_FLAG_DATA_SIZE)

    int calcChecksum()
    {
      int checkSum = 0;
      for (uint16_t index = 0; index < (sizeof(Blynk_WM_config) - sizeof(Blynk_WM_config.checkSum)); index++)
      {
        checkSum += * ( ( (byte*) &Blynk_WM_config ) + index);
      }

      return checkSum;
    }

    bool checkDynamicData(void)
    {
      int checkSum = 0;
      int readCheckSum;
      
      uint16_t  byteCount = 0;
      
      //#define BUFFER_LEN            128
      //char readBuffer[BUFFER_LEN + 1];
      
      #define BIG_BUFFER_LEN        768     
      byte bigBuffer[BIG_BUFFER_LEN + 1];      
      
      uint16_t offset = BLYNK_EEPROM_START + sizeof(Blynk_WM_config);      
           
      // Make address 4-byte aligned
      if ( (offset % 4) != 0 )
      {
        offset += 4 - (offset % 4);
      }
      
      // Find the longest pdata, then dynamically allocate buffer. Remember to free when done
      // This is used to store tempo data to calculate checksum to see of data is valid
      // We dont like to destroy myMenuItems[i].pdata with invalid data
      int totalLength = 0;
            
      for (int i = 0; i < NUM_MENU_ITEMS; i++)
      {       
        totalLength += myMenuItems[i].maxlen;
        
        if ( (totalLength > BIG_BUFFER_LEN) || (myMenuItems[i].maxlen > BIG_BUFFER_LEN) )
        {
          // Size too large, abort and flag false
          BLYNK_LOG1(BLYNK_F("ChkCrR: Error Small Buffer."));
          return false;
        }
      }
                         
      // Both Buffers big enough, read all dynamicData to BigBuffer once 
      // as address need to be 4-byte aligned
      byte* dataPointer = (byte* ) dueFlashStorageData.readAddress(offset);
      
      // Prepare buffer, more than enough
      memset(bigBuffer, 0, sizeof(bigBuffer));
      memcpy(bigBuffer, dataPointer, sizeof(bigBuffer));               
         
      // Don't need readBuffer
      // Now to split into individual piece to add to CSum
      for (int i = 0; i < NUM_MENU_ITEMS; i++)
      {       
        char* _pointer = (char*) bigBuffer;
        
        for (uint16_t j = 0; j < myMenuItems[i].maxlen; j++, _pointer++, byteCount++)
        {
          *_pointer = bigBuffer[byteCount];
                  
          checkSum += *_pointer;  
        }    
      }
      
      memcpy(&readCheckSum, &bigBuffer[byteCount], sizeof(readCheckSum));
          
      BLYNK_LOG4(F("ChkCrR:CrCCsum="), String(checkSum, HEX), F(",CrRCsum="), String(readCheckSum, HEX));
           
      if ( checkSum != readCheckSum )
      {
        return false;
      }
      
      return true;    
    }
    
    bool dueFlashStorage_get(void)
    {
      uint16_t offset = BLYNK_EEPROM_START;
            
      byte* dataPointer = (byte* ) dueFlashStorageData.readAddress(offset);
      
      memcpy(&Blynk_WM_config, dataPointer, sizeof(Blynk_WM_config));
      
      offset += sizeof(Blynk_WM_config);
           
      // Make address 4-byte aligned
      if ( (offset % 4) != 0 )
      {
        offset += 4 - (offset % 4);
      }
            
      int checkSum = 0;
      int readCheckSum;
      
      uint16_t  byteCount = 0;
           
      byte buffer[768];
      
      dataPointer = (byte* ) dueFlashStorageData.readAddress(offset);
      
      memcpy(buffer, dataPointer, sizeof(buffer));
      
      totalDataSize = sizeof(Blynk_WM_config) + sizeof(readCheckSum);
   
      for (int i = 0; i < NUM_MENU_ITEMS; i++)
      {       
        char* _pointer = myMenuItems[i].pdata;
        totalDataSize += myMenuItems[i].maxlen;
        
        // Actual size of pdata is [maxlen + 1]
        memset(myMenuItems[i].pdata, 0, myMenuItems[i].maxlen + 1);
                      
        for (uint16_t j = 0; j < myMenuItems[i].maxlen; j++,_pointer++, byteCount++)
        {
          *_pointer = buffer[byteCount];
          
          checkSum += *_pointer;  
         }     
      }
      
      memcpy(&readCheckSum, &buffer[byteCount], sizeof(readCheckSum));
      
      byteCount += sizeof(readCheckSum);      
      
      BLYNK_LOG6(F("CrCCsum="), checkSum, F(",CrRCsum="), readCheckSum, F(",TotalDataSz="), totalDataSize);
      
      if ( checkSum != readCheckSum)
      {
        return false;
      }
      
      return true;
    }    
    
    void dueFlashStorage_put(void)
    {
      uint16_t offset = BLYNK_EEPROM_START;
      
      dueFlashStorageData.write(offset, (byte *) &Blynk_WM_config, sizeof(Blynk_WM_config));
      
      offset += sizeof(Blynk_WM_config);
      
      // Make address 4-byte aligned
      if ( (offset % 4) != 0 )
      {
        offset += 4 - (offset % 4);
      }
      
      int       checkSum = 0;
      uint16_t  byteCount = 0;
           
      // Use 2K buffer, if need more memory, can reduce this
      byte buffer[2048];
         
      for (int i = 0; i < NUM_MENU_ITEMS; i++)
      {       
        char* _pointer = myMenuItems[i].pdata;
        
        //BLYNK_LOG4(F("pdata="), myMenuItems[i].pdata, F(",len="), myMenuItems[i].maxlen);
                     
        for (uint16_t j = 0; j < myMenuItems[i].maxlen; j++, _pointer++, /*offset++,*/ byteCount++)
        {
          if (byteCount >= sizeof(buffer))
          {
            BLYNK_LOG2(BLYNK_F("Danger:dynamic data too long >"), sizeof(buffer));
          }
          
          buffer[byteCount] = *_pointer;          
          checkSum += *_pointer;     
         }
      }
           
      memcpy(&buffer[byteCount], &checkSum, sizeof(checkSum));
      
      byteCount += sizeof(checkSum);
      
      dueFlashStorageData.write(offset, buffer, byteCount);
      
      BLYNK_LOG4(F("CrCCSum="), checkSum, F(",byteCount="), byteCount);
    }    
    
    bool getConfigData()
    {
      bool dynamicDataValid;   
      
      hadConfigData = false;    
          
      // For DUE, DATA_LENGTH = ((IFLASH1_PAGE_SIZE/sizeof(byte))*4) = 1KBytes
      BLYNK_LOG2(BLYNK_F("Simulate EEPROM, sz:"), DATA_LENGTH);

      if (LOAD_DEFAULT_CONFIG_DATA)
      {
        // Load default dynamicData, if checkSum OK => valid data => load
        // otherwise, use default in sketch and just assume it's OK
        if (checkDynamicData())
          dueFlashStorage_get();
          
        dynamicDataValid = true;
      }
      else
      {           
        dynamicDataValid = dueFlashStorage_get();
      }  
            
#if ( BLYNK_WM_DEBUG > 2)      
      BLYNK_LOG1(BLYNK_F("======= Start Stored Config Data ======="));
      displayConfigData(Blynk_WM_config);
#endif

      int calChecksum = calcChecksum();

      BLYNK_LOG4(BLYNK_F("CCSum=0x"), String(calChecksum, HEX),
                 BLYNK_F(",RCSum=0x"), String(Blynk_WM_config.checkSum, HEX));

      if ( (strncmp(Blynk_WM_config.header, BLYNK_BOARD_TYPE, strlen(BLYNK_BOARD_TYPE)) != 0) ||
           (calChecksum != Blynk_WM_config.checkSum) || !dynamicDataValid )
      {
        // Including Credentials CSum
        BLYNK_LOG2(F("InitEEPROM,Datasz="), totalDataSize);
        
        // doesn't have any configuration        
        if (LOAD_DEFAULT_CONFIG_DATA)
        {
          memcpy(&Blynk_WM_config, &defaultConfig, sizeof(Blynk_WM_config));
        }
        else
        {  
          memset(&Blynk_WM_config, 0, sizeof(Blynk_WM_config));

          for (int i = 0; i < NUM_MENU_ITEMS; i++)
          {
            // Actual size of pdata is [maxlen + 1]
            memset(myMenuItems[i].pdata, 0, myMenuItems[i].maxlen + 1);
          }
          
          // Including Credentials CSum
          BLYNK_LOG2(F("InitEEPROM,Datasz="), totalDataSize);

          // doesn't have any configuration
          strcpy(Blynk_WM_config.WiFi_Creds[0].wifi_ssid,       WM_NO_CONFIG);
          strcpy(Blynk_WM_config.WiFi_Creds[0].wifi_pw,         WM_NO_CONFIG);
          strcpy(Blynk_WM_config.WiFi_Creds[1].wifi_ssid,       WM_NO_CONFIG);
          strcpy(Blynk_WM_config.WiFi_Creds[1].wifi_pw,         WM_NO_CONFIG);
          strcpy(Blynk_WM_config.Blynk_Creds[0].blynk_server,   WM_NO_CONFIG);
          strcpy(Blynk_WM_config.Blynk_Creds[0].blynk_token,    WM_NO_CONFIG);
          strcpy(Blynk_WM_config.Blynk_Creds[1].blynk_server,   WM_NO_CONFIG);
          strcpy(Blynk_WM_config.Blynk_Creds[1].blynk_token,    WM_NO_CONFIG);
          Blynk_WM_config.blynk_port = BLYNK_SERVER_HARDWARE_PORT;
          strcpy(Blynk_WM_config.board_name,  WM_NO_CONFIG);

          for (int i = 0; i < NUM_MENU_ITEMS; i++)
          {
            strncpy(myMenuItems[i].pdata, WM_NO_CONFIG, myMenuItems[i].maxlen);
          }
        }
        
        strcpy(Blynk_WM_config.header, BLYNK_BOARD_TYPE);

        #if ( BLYNK_WM_DEBUG > 2)     
        for (int i = 0; i < NUM_MENU_ITEMS; i++)
        {
          BLYNK_LOG4(BLYNK_F("g:myMenuItems["), i, BLYNK_F("]="), myMenuItems[i].pdata );
        }
        #endif
                
        // Don't need
        Blynk_WM_config.checkSum = 0;

        //dueFlashStorage_put();
        saveConfigData();

        return false;
      }
      else if ( !strncmp(Blynk_WM_config.WiFi_Creds[0].wifi_ssid,       WM_NO_CONFIG, strlen(WM_NO_CONFIG) )  ||
                !strncmp(Blynk_WM_config.WiFi_Creds[0].wifi_pw,         WM_NO_CONFIG, strlen(WM_NO_CONFIG) )  ||
                !strncmp(Blynk_WM_config.WiFi_Creds[1].wifi_ssid,       WM_NO_CONFIG, strlen(WM_NO_CONFIG) )  ||
                !strncmp(Blynk_WM_config.WiFi_Creds[1].wifi_pw,         WM_NO_CONFIG, strlen(WM_NO_CONFIG) )  ||
                !strncmp(Blynk_WM_config.Blynk_Creds[0].blynk_server,   WM_NO_CONFIG, strlen(WM_NO_CONFIG) )  ||
                !strncmp(Blynk_WM_config.Blynk_Creds[0].blynk_token,    WM_NO_CONFIG, strlen(WM_NO_CONFIG) )  ||
                !strncmp(Blynk_WM_config.Blynk_Creds[1].blynk_server,   WM_NO_CONFIG, strlen(WM_NO_CONFIG) )  ||
                !strncmp(Blynk_WM_config.Blynk_Creds[1].blynk_token,    WM_NO_CONFIG, strlen(WM_NO_CONFIG) ) )
      {
        // If SSID, PW, Server,Token ="nothing", stay in config mode forever until having config Data.
        return false;
      }
      else
      {
        displayConfigData(Blynk_WM_config);
      }

      return true;
    }

    void saveConfigData()
    {
      int calChecksum = calcChecksum();
      Blynk_WM_config.checkSum = calChecksum;
      
      BLYNK_LOG4(F("SaveData,sz="), totalDataSize, F(",WCSum=0x"), String(calChecksum, HEX));

      dueFlashStorage_put();
    }

    bool connectMultiWiFi(int timeout)
    {
      int sleep_time = 250;
      uint8_t status;
      
      unsigned long currMillis;

      BLYNK_LOG1(F("Connecting MultiWifi..."));

      if (static_IP != IPAddress(0, 0, 0, 0))
      {
        BLYNK_LOG1(F("UseStatIP"));
        WiFi.config(static_IP);
      }
      
      for (int i = 0; i < NUM_WIFI_CREDENTIALS; i++)
      {
        currMillis = millis();
        
        setHostname();
        
        while ( !wifi_connected && ( 0 < timeout ) && ( (millis() - currMillis) < (unsigned long) timeout )  )
        {
          BLYNK_LOG2(F("con2WF:spentMsec="), millis() - currMillis);
          
          status = WiFi.begin(Blynk_WM_config.WiFi_Creds[i].wifi_ssid, Blynk_WM_config.WiFi_Creds[i].wifi_pw);

          if (status == WL_CONNECTED)
          {
            wifi_connected = true;
            // To exit for loop
            i = NUM_WIFI_CREDENTIALS;
            break;
          }
          else
          {
            delay(sleep_time);
          }
        }
      }       

      if (wifi_connected)
      {
        BLYNK_LOG1(F("con2WF:OK"));
        displayWiFiData();
      }
      else
      {
        BLYNK_LOG1(F("con2WF:failed"));
      }

      return wifi_connected;  
    }
    
    bool connectMultiBlynk(void)
    {
#define BLYNK_CONNECT_TIMEOUT_MS      5000L

      for (int i = 0; i < NUM_BLYNK_CREDENTIALS; i++)
      {
        config(Blynk_WM_config.Blynk_Creds[i].blynk_token,
               Blynk_WM_config.Blynk_Creds[i].blynk_server, Blynk_WM_config.blynk_port);

        if (connect(BLYNK_CONNECT_TIMEOUT_MS) )
        {
          BLYNK_LOG4(BLYNK_F("Con2BlynkServer="), Blynk_WM_config.Blynk_Creds[i].blynk_server,
                     BLYNK_F(",Token="), Blynk_WM_config.Blynk_Creds[i].blynk_token);
                     
          currentBlynkServerIndex = i;           
          return true;
        }
      }

      BLYNK_LOG1(BLYNK_F("Blynk not connected"));

      return false;
    }

    // NEW
    void createHTML(String& root_html_template)
    {
      String pitem;
      
      root_html_template = String(WIFININA_HTML_HEAD)  + WIFININA_FLDSET_START;
      
      for (int i = 0; i < NUM_MENU_ITEMS; i++)
      {
        pitem = String(WIFININA_HTML_PARAM);

        pitem.replace("{b}", myMenuItems[i].displayName);
        pitem.replace("{v}", myMenuItems[i].id);
        pitem.replace("{i}", myMenuItems[i].id);
        
        root_html_template += pitem;
      }
      
      root_html_template += String(WIFININA_FLDSET_END) + WIFININA_HTML_BUTTON + WIFININA_HTML_SCRIPT;     
      
      for (int i = 0; i < NUM_MENU_ITEMS; i++)
      {
        pitem = String(WIFININA_HTML_SCRIPT_ITEM);
        
        pitem.replace("{d}", myMenuItems[i].id);
        
        root_html_template += pitem;
      }
      
      root_html_template += String(WIFININA_HTML_SCRIPT_END) + WIFININA_HTML_END;
      
      return;     
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
          String result;
          createHTML(result);

          BLYNK_LOG1(BLYNK_F("h:repl"));

          // Reset configTimeout to stay here until finished.
          configTimeout = 0;

          if ( RFC952_hostname[0] != 0 )
          {
            // Replace only if Hostname is valid
            result.replace("BlynkWiFiNINA_DUE_WM", RFC952_hostname);
          }
          else if ( Blynk_WM_config.board_name[0] != 0 )
          {
            // Or replace only if board_name is valid.  Otherwise, keep intact
            result.replace("BlynkWiFiNINA_DUE_WM", Blynk_WM_config.board_name);
          }

          result.replace("[[id]]",     Blynk_WM_config.WiFi_Creds[0].wifi_ssid);
          result.replace("[[pw]]",     Blynk_WM_config.WiFi_Creds[0].wifi_pw);
          result.replace("[[id1]]",    Blynk_WM_config.WiFi_Creds[1].wifi_ssid);
          result.replace("[[pw1]]",    Blynk_WM_config.WiFi_Creds[1].wifi_pw);
          result.replace("[[sv]]",     Blynk_WM_config.Blynk_Creds[0].blynk_server);
          result.replace("[[tk]]",     Blynk_WM_config.Blynk_Creds[0].blynk_token);
          result.replace("[[sv1]]",    Blynk_WM_config.Blynk_Creds[1].blynk_server);
          result.replace("[[tk1]]",    Blynk_WM_config.Blynk_Creds[1].blynk_token);
          result.replace("[[pt]]",     String(Blynk_WM_config.blynk_port));
          result.replace("[[nm]]",     Blynk_WM_config.board_name);
          
          for (int i = 0; i < NUM_MENU_ITEMS; i++)
          {
            String toChange = String("[[") + myMenuItems[i].id + "]]";
            result.replace(toChange, myMenuItems[i].pdata);
          }

          server->send(200, "text/html", result);
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
          if (strlen(value.c_str()) < sizeof(Blynk_WM_config.WiFi_Creds[0].wifi_ssid) - 1)
            strcpy(Blynk_WM_config.WiFi_Creds[0].wifi_ssid, value.c_str());
          else
            strncpy(Blynk_WM_config.WiFi_Creds[0].wifi_ssid, value.c_str(), sizeof(Blynk_WM_config.WiFi_Creds[0].wifi_ssid) - 1);
        }
        else if (key == "pw")
        {
          number_items_Updated++;
          if (strlen(value.c_str()) < sizeof(Blynk_WM_config.WiFi_Creds[0].wifi_pw) - 1)
            strcpy(Blynk_WM_config.WiFi_Creds[0].wifi_pw, value.c_str());
          else
            strncpy(Blynk_WM_config.WiFi_Creds[0].wifi_pw, value.c_str(), sizeof(Blynk_WM_config.WiFi_Creds[0].wifi_pw) - 1);
        }

        else if (key == "id1")
        {
          number_items_Updated++;
          if (strlen(value.c_str()) < sizeof(Blynk_WM_config.WiFi_Creds[1].wifi_ssid) - 1)
            strcpy(Blynk_WM_config.WiFi_Creds[1].wifi_ssid, value.c_str());
          else
            strncpy(Blynk_WM_config.WiFi_Creds[1].wifi_ssid, value.c_str(), sizeof(Blynk_WM_config.WiFi_Creds[1].wifi_ssid) - 1);
        }
        else if (key == "pw1")
        {
          number_items_Updated++;
          if (strlen(value.c_str()) < sizeof(Blynk_WM_config.WiFi_Creds[1].wifi_pw) - 1)
            strcpy(Blynk_WM_config.WiFi_Creds[1].wifi_pw, value.c_str());
          else
            strncpy(Blynk_WM_config.WiFi_Creds[1].wifi_pw, value.c_str(), sizeof(Blynk_WM_config.WiFi_Creds[1].wifi_pw) - 1);
        }
        else if (key == "sv")
        {
          number_items_Updated++;
          if (strlen(value.c_str()) < sizeof(Blynk_WM_config.Blynk_Creds[0].blynk_server) - 1)
            strcpy(Blynk_WM_config.Blynk_Creds[0].blynk_server, value.c_str());
          else
            strncpy(Blynk_WM_config.Blynk_Creds[0].blynk_server, value.c_str(), sizeof(Blynk_WM_config.Blynk_Creds[0].blynk_server) - 1);
        }
        else if (key == "tk")
        {
          number_items_Updated++;
          if (strlen(value.c_str()) < sizeof(Blynk_WM_config.Blynk_Creds[0].blynk_token) - 1)
            strcpy(Blynk_WM_config.Blynk_Creds[0].blynk_token, value.c_str());
          else
            strncpy(Blynk_WM_config.Blynk_Creds[0].blynk_token, value.c_str(), sizeof(Blynk_WM_config.Blynk_Creds[0].blynk_token) - 1);
        }
        else if (key == "sv1")
        {
          number_items_Updated++;
          if (strlen(value.c_str()) < sizeof(Blynk_WM_config.Blynk_Creds[1].blynk_server) - 1)
            strcpy(Blynk_WM_config.Blynk_Creds[1].blynk_server, value.c_str());
          else
            strncpy(Blynk_WM_config.Blynk_Creds[1].blynk_server, value.c_str(), sizeof(Blynk_WM_config.Blynk_Creds[1].blynk_server) - 1);
        }
        else if (key == "tk1")
        {
          number_items_Updated++;
          if (strlen(value.c_str()) < sizeof(Blynk_WM_config.Blynk_Creds[1].blynk_token) - 1)
            strcpy(Blynk_WM_config.Blynk_Creds[1].blynk_token, value.c_str());
          else
            strncpy(Blynk_WM_config.Blynk_Creds[1].blynk_token, value.c_str(), sizeof(Blynk_WM_config.Blynk_Creds[1].blynk_token) - 1);
        }
        else if (key == "pt")
        {
          number_items_Updated++;
          Blynk_WM_config.blynk_port = value.toInt();
        }
        else if (key == "nm")
        {
          number_items_Updated++;
          if (strlen(value.c_str()) < sizeof(Blynk_WM_config.board_name) - 1)
            strcpy(Blynk_WM_config.board_name, value.c_str());
          else
            strncpy(Blynk_WM_config.board_name, value.c_str(), sizeof(Blynk_WM_config.board_name) - 1);
        }

        for (int i = 0; i < NUM_MENU_ITEMS; i++)
        {
          if (key == myMenuItems[i].id)
          {
            BLYNK_LOG4(F("h:"), myMenuItems[i].id, F("="), value.c_str() );
            number_items_Updated++;

            // Actual size of pdata is [maxlen + 1]
            memset(myMenuItems[i].pdata, 0, myMenuItems[i].maxlen + 1);

            if ((int) strlen(value.c_str()) < myMenuItems[i].maxlen)
              strcpy(myMenuItems[i].pdata, value.c_str());
            else
              strncpy(myMenuItems[i].pdata, value.c_str(), myMenuItems[i].maxlen);
          }
        }

        server->send(200, "text/html", "OK");

        // NEW
        if (number_items_Updated == NUM_CONFIGURABLE_ITEMS + NUM_MENU_ITEMS)
        {
          BLYNK_LOG1(BLYNK_F("h:UpdEEPROM"));

          saveConfigData();

          BLYNK_LOG1(BLYNK_F("h:Rst"));

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

        portal_ssid = "DUE_NINA_" + randomNum;
        portal_pass = "MyDUE_NINA_" + randomNum;
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

#endif    //BlynkSimpleWiFiNINA_DUE_WM_h

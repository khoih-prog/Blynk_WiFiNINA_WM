/****************************************************************************************************************************
  BlynkSimpleWiFiNINA_DUE_WM.h
  For SAM DUE boards using WiFiNINA Shields

  Blynk_WiFiNINA_WM is a library for the Mega, Teensy, SAM DUE, nRF52, STM32 and SAMD boards 
  (https://github.com/khoih-prog/Blynk_WiFiNINA_WM) to enable easy configuration/reconfiguration and
  autoconnect/autoreconnect of WiFiNINA/Blynk

  Modified from Blynk library v0.6.1 https://github.com/blynkkk/blynk-library/releases
  Built by Khoi Hoang https://github.com/khoih-prog/Blynk_WiFiNINA_WM
  Licensed under MIT license


  Original Blynk Library author:
  @file       BlynkSimpleWiFiNINA.h
  @author     Volodymyr Shymanskyy
  @license    This project is released under the MIT License (MIT)
  @copyright  Copyright (c) 2018 Volodymyr Shymanskyy
  @date       Sep 2018
  @brief

  Version: 1.1.0

  Version Modified By   Date        Comments
  ------- -----------  ----------   -----------
  1.0.0   K Hoang      07/04/2020  Initial coding
  1.0.1   K Hoang      09/04/2020  Add support to SAM DUE, Teensy, STM32
  1.0.2   K Hoang      15/04/2020  Fix bug. Add SAMD51 support.
  1.0.3   K Hoang      05/05/2020  Add nRF52 support, MultiWiFi/Blynk, Configurable Config Portal Title, 
                                   Default Config Data and DRD. Update examples.
  1.0.4   K Hoang      13/05/2020  Add support to Arduino UNO WiFi R2 
  1.1.0   K Hoang      28/05/2021  Add support to Nano_RP2040_Connect, RASPBERRY_PI_PICO using Arduino mbed or pico core
                                   Enable scan of WiFi networks for selection in Configuration Portal
 *****************************************************************************************************************************/


#ifndef BlynkSimpleWiFiNINA_DUE_WM_h
#define BlynkSimpleWiFiNINA_DUE_WM_h

#if ( defined(ARDUINO_SAM_DUE) || defined(__SAM3X8E__) )
  #if defined(BLYNK_WIFININA_USE_SAM_DUE)
    #undef BLYNK_WIFININA_USE_SAM_DUE
  #endif
  #define BLYNK_WIFININA_USE_SAM_DUE      true
#else
  #error This code is intended to run on the SAM DUE platform! Please check your Tools->Board setting.  
#endif

#define BLYNK_WIFININA_WM_VERSION        "Blynk_WiFiNINA_WM v1.1.0"

//////////////////////////////////////////////
// From v1.1.0 to display correct BLYNK_INFO_DEVICE

#define BLYNK_USE_128_VPINS

#if defined(BLYNK_INFO_DEVICE)
  #undef BLYNK_INFO_DEVICE
#endif
#define BLYNK_BUFFERS_SIZE    4096

#if defined(BLYNK_INFO_DEVICE)
  #undef BLYNK_INFO_DEVICE
#endif

#if defined(BOARD_NAME)
  #define BLYNK_INFO_DEVICE   BOARD_NAME
#elif defined(BOARD_TYPE)
  #define BLYNK_INFO_DEVICE   BOARD_TYPE
#else
  #define BLYNK_INFO_DEVICE   "SAM-DUE"
#endif

//////////////////////////////////////////////

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

//////////////////////////////////////////////

#include <BlynkWiFiNINA_WM_Debug.h>

// New from v1.1.0
#if !defined(SCAN_WIFI_NETWORKS)
  #define SCAN_WIFI_NETWORKS     true
#endif
	
#if SCAN_WIFI_NETWORKS
  #if !defined(MANUAL_SSID_INPUT_ALLOWED)
    #define MANUAL_SSID_INPUT_ALLOWED     true
  #endif

  #if !defined(MAX_SSID_IN_LIST)
    #define MAX_SSID_IN_LIST     10
  #elif (MAX_SSID_IN_LIST < 2)
    #warning Parameter MAX_SSID_IN_LIST defined must be >= 2 - Reset to 10
    #undef MAX_SSID_IN_LIST
    #define MAX_SSID_IN_LIST      10
  #elif (MAX_SSID_IN_LIST > 15)
    #warning Parameter MAX_SSID_IN_LIST defined must be <= 15 - Reset to 10
    #undef MAX_SSID_IN_LIST
    #define MAX_SSID_IN_LIST      10
  #endif
#else
  #warning SCAN_WIFI_NETWORKS disabled	
#endif

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

#if USE_DYNAMIC_PARAMETERS
  #warning Using Dynamic Parameters
  ///NEW
  extern uint16_t NUM_MENU_ITEMS;
  extern MenuItem myMenuItems [];
  bool *menuItemUpdated = NULL;
#else
  #warning Not using Dynamic Parameters
#endif

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

#define HEADER_MAX_LEN            16
#define BOARD_NAME_MAX_LEN        24

typedef struct Configuration
{
  char header         [HEADER_MAX_LEN];
  WiFi_Credentials  WiFi_Creds  [NUM_WIFI_CREDENTIALS];
  Blynk_Credentials Blynk_Creds [NUM_BLYNK_CREDENTIALS];
  int  blynk_port;
  char board_name     [BOARD_NAME_MAX_LEN];
  int  checkSum;
} Blynk_WM_Configuration;

// Currently CONFIG_DATA_SIZE  =  ( 48 + (96 * NUM_WIFI_CREDENTIALS) + (68 * NUM_BLYNK_CREDENTIALS) ) = 376
uint16_t CONFIG_DATA_SIZE = sizeof(Blynk_WM_Configuration);

///New from v1.0.13
extern bool LOAD_DEFAULT_CONFIG_DATA;
extern Blynk_WM_Configuration defaultConfig;

// -- HTML page fragments

const char WIFININA_HTML_HEAD_START[] /*PROGMEM*/ = "<!DOCTYPE html><html><head><title>BlynkWiFiNINA_DUE_WM</title>";

const char WIFININA_HTML_HEAD_STYLE[] /*PROGMEM*/ = "<style>div,input,select{padding:5px;font-size:1em;}input,select{width:95%;}body{text-align:center;}button{background-color:#16A1E7;color:#fff;line-height:2.4rem;font-size:1.2rem;width:100%;}fieldset{border-radius:0.3rem;margin:0px;}</style>";

const char WIFININA_HTML_HEAD_END[]   /*PROGMEM*/ = "</head><div style='text-align:left;display:inline-block;min-width:260px;'>\
<fieldset><div><label>*WiFi SSID</label><div>[[input_id]]</div></div>\
<div><label>*PWD (8+ chars)</label><input value='[[pw]]' id='pw'><div></div></div>\
<div><label>*WiFi SSID1</label><div>[[input_id1]]</div></div>\
<div><label>*PWD1 (8+ chars)</label><input value='[[pw1]]' id='pw1'><div></div></div></fieldset>\
<fieldset><div><label>Blynk Server</label><input value=\"[[sv]]\"id=\"sv\"><div></div></div>\
<div><label>Token</label><input value=\"[[tk]]\"id=\"tk\"><div></div></div>\
<div><label>Blynk Server1</label><input value=\"[[sv1]]\"id=\"sv1\"><div></div></div>\
<div><label>Token1</label><input value=\"[[tk1]]\"id=\"tk1\"><div></div></div>\
<div><label>Port</label><input value=\"[[pt]]\"id=\"pt\"><div></div></div></fieldset>\
<fieldset><div><label>Board Name</label><input value='[[nm]]' id='nm'><div></div></div></fieldset>";	// DO NOT CHANGE THIS STRING EVER!!!!

const char WIFININA_HTML_INPUT_ID[]   /*PROGMEM*/ = "<input value='[[id]]' id='id'>";
const char WIFININA_HTML_INPUT_ID1[]  /*PROGMEM*/ = "<input value='[[id1]]' id='id1'>";

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

#if SCAN_WIFI_NETWORKS
const char WIFININA_SELECT_START[]      /*PROGMEM*/ = "<select id=";
const char WIFININA_SELECT_END[]        /*PROGMEM*/ = "</select>";
const char WIFININA_DATALIST_START[]    /*PROGMEM*/ = "<datalist id=";
const char WIFININA_DATALIST_END[]      /*PROGMEM*/ = "</datalist>";
const char WIFININA_OPTION_START[]      /*PROGMEM*/ = "<option>";
const char WIFININA_OPTION_END[]        /*PROGMEM*/ = "";			// "</option>"; is not required
const char WIFININA_NO_NETWORKS_FOUND[] /*PROGMEM*/ = "No suitable WiFi networks available!";
#endif

//////////////////////////////////////////

//KH Add repeatedly used const
//KH, from v1.1.0
const char WM_HTTP_HEAD_CL[]         PROGMEM = "Content-Length";
const char WM_HTTP_HEAD_TEXT_HTML[]  PROGMEM = "text/html";
const char WM_HTTP_HEAD_TEXT_PLAIN[] PROGMEM = "text/plain";

const char WM_HTTP_CACHE_CONTROL[]   PROGMEM = "Cache-Control";
const char WM_HTTP_NO_STORE[]        PROGMEM = "no-cache, no-store, must-revalidate";
const char WM_HTTP_PRAGMA[]          PROGMEM = "Pragma";
const char WM_HTTP_NO_CACHE[]        PROGMEM = "no-cache";
const char WM_HTTP_EXPIRES[]         PROGMEM = "Expires";

const char WM_HTTP_CORS[]            PROGMEM = "Access-Control-Allow-Origin";
const char WM_HTTP_CORS_ALLOW_ALL[]  PROGMEM = "*";

//////////////////////////////////////////////

// New from v1.1.0
#if !defined(REQUIRE_ONE_SET_SSID_PW)
  #define REQUIRE_ONE_SET_SSID_PW     false
#endif

#define PASSWORD_MIN_LEN        8

//////////////////////////////////////////////

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
    
    ~BlynkWifiCommon()
    {
      if (server)
      {
        delete server;

#if SCAN_WIFI_NETWORKS
        if (indices)
        {
          free(indices); //indices array no longer required so free memory
        }
#endif
      }
    }

    bool connectWiFi(const char* ssid, const char* pass)
    {
        int status = WiFi.status();
        // check for the presence of the shield:
        if (status == WL_NO_MODULE) {
            WN_LOGERROR(F("NoNINA"));
            return false;
        }

        WN_LOGERROR1(F("WiFiNINA FW Version:"), WiFi.firmwareVersion());

        // attempt to connect to Wifi network:
        while (status != WL_CONNECTED) 
        {
            WN_LOGERROR1(F("Con2:"), ssid);
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
          WN_LOGERROR(F("b:ConWOK"));
          
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
          WN_LOGERROR(F("b:ConWOK"));
          
        config(auth, ip, port);
        while(this->connect() != true) {}
    }

    //////////////////////////////////////////////

    void begin(const char *iHostname = "")
    {
#define RETRY_TIMES_CONNECT_WIFI			3

      if (iHostname[0] == 0)
      {
        String randomNum = String(random(0xFFFFFF), HEX);
        randomNum.toUpperCase();
        
        String _hostname = "Teensy-WiFiNINA-" + randomNum;
        _hostname.toUpperCase();

        getRFC952_hostname(_hostname.c_str());
      }
      else
      {
        // Prepare and store the hostname only not NULL
        getRFC952_hostname(iHostname);
      }
      
      WN_LOGERROR1(F("Hostname="), RFC952_hostname);
      //////

      //// New DRD ////
      drd = new DoubleResetDetector_Generic(DRD_TIMEOUT, DRD_ADDRESS);    
      bool noConfigPortal = true;
   
      if (drd->detectDoubleReset())
      {
#if ( BLYNK_WM_DEBUG > 1)      
        WN_LOGERROR(F("Double Reset Detected"));
#endif        
        noConfigPortal = false;
      }
      //// New DRD ////
      
      if (LOAD_DEFAULT_CONFIG_DATA)
      {
        WN_LOGERROR(F("======= Start Default Config Data ======="));
        displayConfigData(defaultConfig);
      }
      
      hadConfigData = getConfigData();
      
      isForcedConfigPortal = isForcedCP();
      
      //// New DRD/MRD ////
      //  noConfigPortal when getConfigData() OK and no MRD/DRD'ed
      if (hadConfigData && noConfigPortal && (!isForcedConfigPortal) )
      {
        hadConfigData = true;

        if (connectMultiWiFi(RETRY_TIMES_CONNECT_WIFI))
        {
          WN_LOGERROR(F("b:WOK.TryB"));

          int i = 0;
          
          while ( (i++ < 10) && !connectMultiBlynk() );

          if  (connected())
          {
            WN_LOGERROR(F("b:WBOK"));
          }
          else
          {
            WN_LOGERROR(F("b:WOK,BNo"));
            // failed to connect to Blynk server, will start configuration mode
            startConfigurationMode();
          }
        }
        else
        {
          WN_LOGERROR(F("b:FailW+B"));
          // failed to connect to Blynk server, will start configuration mode
          startConfigurationMode();
        }
      }
      else
      {      
        WN_LOGERROR(isForcedConfigPortal? F("bg: isForcedConfigPortal = true") : F("bg: isForcedConfigPortal = false"));
                     
        // If not persistent => clear the flag so that after reset. no more CP, even CP not entered and saved
        if (persForcedConfigPortal)
        {
          WN_LOGERROR1(F("bg:Stay forever in CP:"), isForcedConfigPortal ? F("Forced-Persistent") : (noConfigPortal ? F("No ConfigDat") : F("DRD/MRD")));
        }
        else
        {
          WN_LOGERROR1(F("bg:Stay forever in CP:"), isForcedConfigPortal ? F("Forced-non-Persistent") : (noConfigPortal ? F("No ConfigDat") : F("DRD/MRD")));
          clearForcedCP();
        }
          
        //To permit autoreset after timeout if DRD/MRD or non-persistent forced-CP 
        hadConfigData = isForcedConfigPortal ? true : (noConfigPortal ? false : true);
        
        // failed to connect to WiFi, will start configuration mode
        startConfigurationMode();
      }
    }
    
    //////////////////////////////////////////////

#ifndef RETRY_TIMES_RECONNECT_WIFI
  #define RETRY_TIMES_RECONNECT_WIFI   2
#else
  // Force range of user-defined RETRY_TIMES_RECONNECT_WIFI between 2-5 times
  #if (RETRY_TIMES_RECONNECT_WIFI < 2)
    #warning RETRY_TIMES_RECONNECT_WIFI too low. Reseting to 2
    #undef RETRY_TIMES_RECONNECT_WIFI
    #define RETRY_TIMES_RECONNECT_WIFI   2
  #elif (RETRY_TIMES_RECONNECT_WIFI > 5)
    #warning RETRY_TIMES_RECONNECT_WIFI too high. Reseting to 5
    #undef RETRY_TIMES_RECONNECT_WIFI
    #define RETRY_TIMES_RECONNECT_WIFI   5
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

    //////////////////////////////////////////////

    void run()
    {
      static int retryTimes = 0;
      static bool wifiDisconnectedOnce = false;
      
      // Lost connection in running. Give chance to reconfig.
      // Check WiFi status every 5s and update status
      // Check twice to be sure wifi disconnected is real
      static unsigned long checkstatus_timeout = 0;
      #define WIFI_STATUS_CHECK_INTERVAL    5000L
      
      //// New DRD ////
      // Call the double reset detector loop method every so often,
      // so that it can recognise when the timeout expires.
      // You can also call drd.stop() when you wish to no longer
      // consider the next reset as a double reset.
      drd->loop();
      //// New DRD ////
      
      if ( !configuration_mode && (millis() > checkstatus_timeout) )
      {       
        if (WiFi.status() == WL_CONNECTED)
        {
          wifi_connected = true;
        }
        else
        {
          if (wifiDisconnectedOnce)
          {
            wifiDisconnectedOnce = false;
            wifi_connected = false;
            WN_LOGERROR(F("r:Check&WLost"));
          }
          else
          {
            wifiDisconnectedOnce = true;
          }
        }
        
        checkstatus_timeout = millis() + WIFI_STATUS_CHECK_INTERVAL;
      }

      // Lost connection in running. Give chance to reconfig.
      if ( !wifi_connected || !connected() )
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
              WN_LOGERROR1(F("r:Wlost&TOut.ConW+B.Retry#"), retryTimes);
            }
            else
            {
              resetFunc();  //call reset
            }
          }
#endif

          // Not in config mode, try reconnecting before forcing to config mode
          if ( !wifi_connected )
          {
            WN_LOGERROR(F("r:WLost.ReconW+B"));

            if (connectMultiWiFi(RETRY_TIMES_RECONNECT_WIFI))
            {
              WN_LOGERROR(F("r:WOK.TryB"));

              if (connectMultiBlynk())
              {
                WN_LOGERROR(F("r:W+BOK"));
              }
            }
          }
          else
          {
            WN_LOGERROR(F("r:BLost.TryB"));
            
            //if (connect())
            if (connectMultiBlynk())
            {
              WN_LOGERROR(F("r:BOK"));
            }
          }

          //WN_LOGERROR(F("run: Lost connection => configMode"));
          //startConfigurationMode();
        }
      }
      else if (configuration_mode)
      {
        configuration_mode = false;
        WN_LOGERROR(F("r:GotW+BBack"));
      }

      if (connected())
      {
        Base::run();
      }
    }
    
    //////////////////////////////////////////////

    void setHostname()
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

    String getLocalIP()
    {
      ipAddress =IPAddressToString(WiFi.localIP());

      //WN_LOGERROR1(F("getLocalIP: IP = "), ipAddress);
      return ipAddress;
    }

    void clearConfigData()
    {
      memset(&Blynk_WM_config, 0, sizeof(Blynk_WM_config));
      
#if USE_DYNAMIC_PARAMETERS      
      for (uint16_t i = 0; i < NUM_MENU_ITEMS; i++)
      {
        // Actual size of pdata is [maxlen + 1]
        memset(myMenuItems[i].pdata, 0, myMenuItems[i].maxlen + 1);
      }
#endif
         
      saveConfigData();
    }
    
    //////////////////////////////////////////////
    
    bool isConfigDataValid()
    {
      return hadConfigData;
    }
    
    //////////////////////////////////////////////
    
    // Forced CP => Flag = 0xBEEFBEEF. Else => No forced CP
    // Flag to be stored at (EEPROM_START + DRD_FLAG_DATA_SIZE + CONFIG_DATA_SIZE) 
    // to avoid corruption to current data
    //#define FORCED_CONFIG_PORTAL_FLAG_DATA              ( (uint32_t) 0xDEADBEEF)
    //#define FORCED_PERS_CONFIG_PORTAL_FLAG_DATA         ( (uint32_t) 0xBEEFDEAD)
    
    const uint32_t FORCED_CONFIG_PORTAL_FLAG_DATA       = 0xDEADBEEF;
    const uint32_t FORCED_PERS_CONFIG_PORTAL_FLAG_DATA  = 0xBEEFDEAD;
    
    #define FORCED_CONFIG_PORTAL_FLAG_DATA_SIZE     4
    
    void resetAndEnterConfigPortal()
    {
      persForcedConfigPortal = false;
      
      setForcedCP(false);
      
      // Delay then reset the ESP8266 after save data
      delay(1000);
      resetFunc();
    }
    
    //////////////////////////////////////////////
    
    // This will keep CP forever, until you successfully enter CP, and Save data to clear the flag.
    void resetAndEnterConfigPortalPersistent()
    {
      persForcedConfigPortal = true;
      
      setForcedCP(true);
      
      // Delay then reset the ESP8266 after save data
      delay(1000);
      resetFunc();
    }
    
    //////////////////////////////////////////////

    void resetFunc()
    {
      void(*resetFunc)() = 0;
      resetFunc();
    }


  private:
    String ipAddress = "0.0.0.0";

    WiFiWebServer* server;
    bool configuration_mode = false;

    unsigned long configTimeout;
    bool hadConfigData = false;

    bool isForcedConfigPortal   = false;
    bool persForcedConfigPortal = false;

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

/////////////////////////////////////
    
    // Add customs headers from v1.1.0
    
#if USING_CUSTOMS_STYLE
    const char* WIFININA_HTML_HEAD_CUSTOMS_STYLE = NULL;
#endif
    
#if USING_CUSTOMS_HEAD_ELEMENT
    const char* _CustomsHeadElement = NULL;
#endif
    
#if USING_CORS_FEATURE    
    const char* _CORS_Header        = WM_HTTP_CORS_ALLOW_ALL;   //"*";
#endif
       
    /////////////////////////////////////
    // Add WiFi Scan from v1.1.0
    
#if SCAN_WIFI_NETWORKS
  int WiFiNetworksFound = 0;		// Number of SSIDs found by WiFi scan, including low quality and duplicates
  int *indices;					        // WiFi network data, filled by scan (SSID, BSSID)
  String ListOfSSIDs = "";		  // List of SSIDs found by scan, in HTML <option> format
#endif

    //////////////////////////////////////
    
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
      WN_LOGERROR3(F("Hdr="),       configData.header,
                 F(",BrdName="),  configData.board_name);
      WN_LOGERROR3(F("SSID="),      configData.WiFi_Creds[0].wifi_ssid,
                 F(",PW="),       configData.WiFi_Creds[0].wifi_pw);
      WN_LOGERROR3(F("SSID1="),     configData.WiFi_Creds[1].wifi_ssid,
                 F(",PW1="),      configData.WiFi_Creds[1].wifi_pw);
      WN_LOGERROR3(F("Server="),    configData.Blynk_Creds[0].blynk_server,
                 F(",Token="),    configData.Blynk_Creds[0].blynk_token);
      WN_LOGERROR3(F("Server1="),   configData.Blynk_Creds[1].blynk_server,
                 F(",Token1="),   configData.Blynk_Creds[1].blynk_token);
      WN_LOGERROR1(F("Port="),      configData.blynk_port);
      WN_LOGERROR(F("======= End Config Data ======="));
      
#if USE_DYNAMIC_PARAMETERS     
      for (uint16_t i = 0; i < NUM_MENU_ITEMS; i++)
      {
        WN_LOGERROR5("i=", i, ",id=", myMenuItems[i].id, ",data=", myMenuItems[i].pdata);
      }
#endif
      
      WN_LOGERROR(F("======= End Dynamic Data ======="));
    }

    void displayWiFiData()
    {
      WN_LOGERROR5(F("IP = "), IPAddressToString(WiFi.localIP()), F(", GW = "), IPAddressToString(WiFi.gatewayIP()),
                 F(", SN = "), IPAddressToString(WiFi.subnetMask()));
    }


#define BLYNK_BOARD_TYPE      "SHD_WiFiNINA"
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

    //////////////////////////////////////////////
       
    void saveForcedCP(uint32_t value)
    {
      uint32_t readForcedConfigPortalFlag = value;

      uint16_t offset = BLYNK_EEPROM_START + CONFIG_DATA_SIZE;
            
      dueFlashStorageData.write(offset, (byte *) &readForcedConfigPortalFlag, sizeof(readForcedConfigPortalFlag));
    }
    
    //////////////////////////////////////////////
    
    void setForcedCP(bool isPersistent)
    {
      uint32_t readForcedConfigPortalFlag = isPersistent? FORCED_PERS_CONFIG_PORTAL_FLAG_DATA : FORCED_CONFIG_PORTAL_FLAG_DATA;
 
      WN_LOGERROR(isPersistent ? F("setForcedCP Persistent") : F("setForcedCP non-Persistent"));

      saveForcedCP(readForcedConfigPortalFlag);
    }
    
    //////////////////////////////////////////////
    
    void clearForcedCP()
    {
      uint32_t readForcedConfigPortalFlag = 0;
   
      WN_LOGERROR(F("clearForcedCP"));

      saveForcedCP(readForcedConfigPortalFlag);
    }
    
    //////////////////////////////////////////////

    bool isForcedCP()
    {
      uint32_t readForcedConfigPortalFlag;
      
      // Return true if forced CP (0xDEADBEEF read at offset EPROM_START + DRD_FLAG_DATA_SIZE + CONFIG_DATA_SIZE)
      // => set flag noForcedConfigPortal = false
      uint16_t offset = BLYNK_EEPROM_START + CONFIG_DATA_SIZE;
            
      byte* dataPointer = (byte* ) dueFlashStorageData.readAddress(offset);
      
      memcpy(&readForcedConfigPortalFlag, dataPointer, sizeof(readForcedConfigPortalFlag));
      
      // Return true if forced CP (0xDEADBEEF read at offset EPROM_START + DRD_FLAG_DATA_SIZE + CONFIG_DATA_SIZE)
      // => set flag noForcedConfigPortal = false     
      if (readForcedConfigPortalFlag == FORCED_CONFIG_PORTAL_FLAG_DATA)
      {       
        persForcedConfigPortal = false;
        return true;
      }
      else if (readForcedConfigPortalFlag == FORCED_PERS_CONFIG_PORTAL_FLAG_DATA)
      {       
        persForcedConfigPortal = true;
        return true;
      }
      else
      {       
        return false;
      }
    }
    
    //////////////////////////////////////////////
    
#if USE_DYNAMIC_PARAMETERS
    
    bool checkDynamicData()
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
            
      for (uint8_t i = 0; i < NUM_MENU_ITEMS; i++)
      {       
        totalLength += myMenuItems[i].maxlen;
        
        if ( (totalLength > BIG_BUFFER_LEN) )
        {
          // Size too large, abort and flag false
          WN_LOGDEBUG(F("ChkCrR: Error Small Buffer."));
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
      for (uint8_t i = 0; i < NUM_MENU_ITEMS; i++)
      {       
        char* _pointer = (char*) bigBuffer;
        
        for (uint16_t j = 0; j < myMenuItems[i].maxlen; j++, _pointer++, byteCount++)
        {
          *_pointer = bigBuffer[byteCount];
                  
          checkSum += *_pointer;  
        }    
      }
      
      memcpy(&readCheckSum, &bigBuffer[byteCount], sizeof(readCheckSum));
          
      WN_LOGDEBUG3(F("ChkCrR:CrCCsum=0x"), String(checkSum, HEX), F(",CrRCsum=0x"), String(readCheckSum, HEX));
           
      if ( checkSum != readCheckSum )
      {
        return false;
      }
      
      return true;    
    }
    
    //////////////////////////////////////////////
    
    bool dueFlashStorage_getDynamicData()
    {      
      uint16_t offset = BLYNK_EEPROM_START + sizeof(Blynk_WM_config) + FORCED_CONFIG_PORTAL_FLAG_DATA_SIZE;
           
      // Make address 4-byte aligned
      if ( (offset % 4) != 0 )
      {
        offset += 4 - (offset % 4);
      }
            
      int checkSum = 0;
      int readCheckSum;
      
      uint16_t  byteCount = 0;
           
      #define BIG_BUFFER_LEN        768     
      byte buffer[BIG_BUFFER_LEN + 1];      
      
      byte* dataPointer = (byte* ) dueFlashStorageData.readAddress(offset);
      
      memcpy(buffer, dataPointer, sizeof(buffer));
      
      totalDataSize = sizeof(Blynk_WM_config) + sizeof(readCheckSum);
   
      for (uint8_t i = 0; i < NUM_MENU_ITEMS; i++)
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
      
      WN_LOGERROR5(F("CrCCsum=0x"), String(checkSum, HEX), F(",CrRCsum=0x"), String(readCheckSum, HEX), 
                F(",TotalDataSz="), totalDataSize);
      
      if ( checkSum != readCheckSum)
      {
        return false;
      }
      
      return true;
    }
    
    //////////////////////////////////////////////
    
    void dueFlashStorage_putDynamicData()
    {   
      uint16_t offset = BLYNK_EEPROM_START + sizeof(Blynk_WM_config) + FORCED_CONFIG_PORTAL_FLAG_DATA_SIZE;
      
      // Make address 4-byte aligned
      if ( (offset % 4) != 0 )
      {
        offset += 4 - (offset % 4);
      }
      
      int       checkSum = 0;
      uint16_t  byteCount = 0;
           
      // Use 2K buffer, if need more memory, can reduce this
      byte buffer[2048];
         
      for (uint8_t i = 0; i < NUM_MENU_ITEMS; i++)
      {       
        char* _pointer = myMenuItems[i].pdata;
 
        WN_LOGDEBUG3(F("pdata="), myMenuItems[i].pdata, F(",len="), myMenuItems[i].maxlen);
                     
        for (uint16_t j = 0; j < myMenuItems[i].maxlen; j++, _pointer++, /*offset++,*/ byteCount++)
        {
          if (byteCount >= sizeof(buffer))
          {
            WN_LOGERROR1(F("Danger:dynamic data too long >"), sizeof(buffer));
          }
          
          buffer[byteCount] = *_pointer;          
          checkSum += *_pointer;     
         }
      }
           
      memcpy(&buffer[byteCount], &checkSum, sizeof(checkSum));
      
      byteCount += sizeof(checkSum);
      
      dueFlashStorageData.write(offset, buffer, byteCount);
      
      WN_LOGERROR3(F("CrCCSum=0x"), String(checkSum, HEX), F(",byteCount="), byteCount);
    }
#endif
    
    //////////////////////////////////////////////
    
    void NULLTerminateConfig()
    {
      //#define HEADER_MAX_LEN      16
      //#define SERVER_MAX_LEN      32
      //#define TOKEN_MAX_LEN       36
      
      // NULL Terminating to be sure
      Blynk_WM_config.header[HEADER_MAX_LEN - 1] = 0;
      Blynk_WM_config.WiFi_Creds[0].wifi_ssid[SSID_MAX_LEN - 1] = 0;
      Blynk_WM_config.WiFi_Creds[0].wifi_pw  [PASS_MAX_LEN - 1] = 0;
      Blynk_WM_config.WiFi_Creds[1].wifi_ssid[SSID_MAX_LEN - 1] = 0;
      Blynk_WM_config.WiFi_Creds[1].wifi_pw  [PASS_MAX_LEN - 1] = 0;
      Blynk_WM_config.board_name[BOARD_NAME_MAX_LEN - 1]  = 0;
    }
    
    //////////////////////////////////////////////
    
    bool isWiFiConfigValid()
    {
      #if REQUIRE_ONE_SET_SSID_PW
      // If SSID ="blank" or NULL, or PWD length < 8 (as required by standard) => return false
      // Only need 1 set of valid SSID/PWD
      if (!( ( ( strncmp(Blynk_WM_config.WiFi_Creds[0].wifi_ssid, WM_NO_CONFIG, strlen(WM_NO_CONFIG)) && 
                 strlen(Blynk_WM_config.WiFi_Creds[0].wifi_ssid) >  0 )  &&
             (   strlen(Blynk_WM_config.WiFi_Creds[0].wifi_pw) >= PASSWORD_MIN_LEN ) ) ||
             ( ( strncmp(Blynk_WM_config.WiFi_Creds[1].wifi_ssid, WM_NO_CONFIG, strlen(WM_NO_CONFIG)) && 
                 strlen(Blynk_WM_config.WiFi_Creds[1].wifi_ssid) >  0 )  &&
               ( strlen(Blynk_WM_config.WiFi_Creds[1].wifi_pw) >= PASSWORD_MIN_LEN ) ) ))
      #else
      // If SSID ="blank" or NULL, or PWD length < 8 (as required by standard) => invalid set
      // Need both sets of valid SSID/PWD
      if ( !strncmp(Blynk_WM_config.WiFi_Creds[0].wifi_ssid,   WM_NO_CONFIG, strlen(WM_NO_CONFIG) )  ||
           !strncmp(Blynk_WM_config.WiFi_Creds[0].wifi_pw,     WM_NO_CONFIG, strlen(WM_NO_CONFIG) )  ||
           !strncmp(Blynk_WM_config.WiFi_Creds[1].wifi_ssid,   WM_NO_CONFIG, strlen(WM_NO_CONFIG) )  ||
           !strncmp(Blynk_WM_config.WiFi_Creds[1].wifi_pw,     WM_NO_CONFIG, strlen(WM_NO_CONFIG) )  ||
           ( strlen(Blynk_WM_config.WiFi_Creds[0].wifi_ssid) == 0 ) || 
           ( strlen(Blynk_WM_config.WiFi_Creds[1].wifi_ssid) == 0 ) ||
           ( strlen(Blynk_WM_config.WiFi_Creds[0].wifi_pw)   < PASSWORD_MIN_LEN ) ||
           ( strlen(Blynk_WM_config.WiFi_Creds[1].wifi_pw)   < PASSWORD_MIN_LEN ) )
      #endif     
      {
        // If SSID, PW ="blank" or NULL, set the flag
        WN_LOGERROR(F("Invalid Stored WiFi Config Data"));
           
        // Nullify the invalid data to avoid displaying garbage
        memset(&Blynk_WM_config, 0, sizeof(Blynk_WM_config));
        
        hadConfigData = false;
        
        return false;
      }
      
      return true;
    }
    
    //////////////////////////////////////////////
    
    bool dueFlashStorage_get()
    {
      uint16_t offset = BLYNK_EEPROM_START;
            
      byte* dataPointer = (byte* ) dueFlashStorageData.readAddress(offset);
      
      memcpy(&Blynk_WM_config, dataPointer, sizeof(Blynk_WM_config));
      
      NULLTerminateConfig();
      
      return isWiFiConfigValid();
    }
    
    //////////////////////////////////////////////
   
    void dueFlashStorage_put()
    {
      uint16_t offset = BLYNK_EEPROM_START;
      
      dueFlashStorageData.write(offset, (byte *) &Blynk_WM_config, sizeof(Blynk_WM_config));   
    } 
    
    //////////////////////////////////////////////

    void saveConfigData()
    {
      int calChecksum = calcChecksum();
      Blynk_WM_config.checkSum = calChecksum;
      
      WN_LOGERROR3(F("SaveData,Sz="), totalDataSize, F(",ChkSum=0x"), String(calChecksum, HEX));

      dueFlashStorage_put();

#if USE_DYNAMIC_PARAMETERS      
      dueFlashStorage_putDynamicData();
#endif      
    }

    //////////////////////////////////////////////
    
    // New from v1.0.5
    void loadAndSaveDefaultConfigData()
    {
      // Load Default Config Data from Sketch
      memcpy(&Blynk_WM_config, &defaultConfig, sizeof(Blynk_WM_config));
      strcpy(Blynk_WM_config.header, BLYNK_BOARD_TYPE);
      
      // Including config and dynamic data, and assume valid
      saveConfigData();
          
      WN_LOGERROR(F("======= Start Loaded Config Data ======="));
      displayConfigData(Blynk_WM_config);    
    }
    
    //////////////////////////////////////////////
    
    bool getConfigData()
    {
      bool dynamicDataValid = true;
      int calChecksum;
      
      hadConfigData = false;    
          
      // For DUE, DATA_LENGTH = ((IFLASH1_PAGE_SIZE/sizeof(byte))*4) = 1KBytes
      WN_LOGERROR1(F("Simulate EEPROM, Sz:"), DATA_LENGTH);

      // Use new LOAD_DEFAULT_CONFIG_DATA logic
      if (LOAD_DEFAULT_CONFIG_DATA)
      {     
        // Load Config Data from Sketch
        loadAndSaveDefaultConfigData();
        
        // Don't need Config Portal anymore
        return true; 
      }
      else
      {   
        // Load stored config / dynamic data from dueFlashStorage
        // Verify ChkSum
        // Get config data. If "blank" or NULL, set false flag and exit
        if (!dueFlashStorage_get())
        {
          return false;
        }       
            
        calChecksum = calcChecksum();

        WN_LOGERROR3(F("CCSum=0x"), String(calChecksum, HEX),
                   F(",RCSum=0x"), String(Blynk_WM_config.checkSum, HEX));
                   
#if USE_DYNAMIC_PARAMETERS        
        // Load stored dynamic data from dueFlashStorage
        dynamicDataValid = checkDynamicData();
#endif
        // If checksum = 0 => DueFlashStorage has been cleared (by uploading new FW, etc) => force to CP
        // If bad checksum = 0 => force to CP
        if ( (calChecksum != 0) && (calChecksum == Blynk_WM_config.checkSum) )
        {
          if (dynamicDataValid)
          {   
  #if USE_DYNAMIC_PARAMETERS  
            dueFlashStorage_getDynamicData();
            
            WN_LOGERROR(F("Valid Stored Dynamic Data"));
  #endif        
            WN_LOGERROR(F("======= Start Stored Config Data ======="));
            displayConfigData(Blynk_WM_config);
            
            // Don't need Config Portal anymore
            return true;
          }
          else
          {
            // Invalid Stored config data => Config Portal
            WN_LOGERROR(F("Invalid Stored Dynamic Data. Load default from Sketch"));
            
            // Load Default Config Data from Sketch, better than just "blank"
            loadAndSaveDefaultConfigData();
                             
            // Need Config Portal here as data can be just dummy
            // Even if you don't open CP, you're OK on next boot if your default config data is valid 
            return false;
          }
        }   
      }   

      if ( (strncmp(Blynk_WM_config.header, BLYNK_BOARD_TYPE, strlen(BLYNK_BOARD_TYPE)) != 0) ||
           (calChecksum != Blynk_WM_config.checkSum) || !dynamicDataValid || 
           ( (calChecksum == 0) && (Blynk_WM_config.checkSum == 0) ) )
      {
        // Including Credentials CSum
        WN_LOGERROR1(F("InitCfgFile,sz="), sizeof(Blynk_WM_config));

        // doesn't have any configuration        
        if (LOAD_DEFAULT_CONFIG_DATA)
        {
          memcpy(&Blynk_WM_config, &defaultConfig, sizeof(Blynk_WM_config));
        }
        else
        {
          memset(&Blynk_WM_config, 0, sizeof(Blynk_WM_config));

#if USE_DYNAMIC_PARAMETERS
          for (uint16_t i = 0; i < NUM_MENU_ITEMS; i++)
          {
            // Actual size of pdata is [maxlen + 1]
            memset(myMenuItems[i].pdata, 0, myMenuItems[i].maxlen + 1);
          }
#endif
              
          for (uint16_t i = 0; i < NUM_WIFI_CREDENTIALS; i++)
		      { 		
			      strcpy(Blynk_WM_config.WiFi_Creds[i].wifi_ssid,   WM_NO_CONFIG);
			      strcpy(Blynk_WM_config.WiFi_Creds[i].wifi_pw,     WM_NO_CONFIG);
		      }
		      
		      for (uint16_t i = 0; i < NUM_BLYNK_CREDENTIALS; i++)
		      { 		
			      strcpy(Blynk_WM_config.Blynk_Creds[i].blynk_server,   WM_NO_CONFIG);
			      strcpy(Blynk_WM_config.Blynk_Creds[i].blynk_token,    WM_NO_CONFIG);
		      }
		      
		      Blynk_WM_config.blynk_port = BLYNK_SERVER_HARDWARE_PORT;
		      
          strcpy(Blynk_WM_config.board_name, WM_NO_CONFIG);
          
#if USE_DYNAMIC_PARAMETERS
          for (uint16_t i = 0; i < NUM_MENU_ITEMS; i++)
          {
            strncpy(myMenuItems[i].pdata, WM_NO_CONFIG, myMenuItems[i].maxlen);
          }
#endif          
        }
    
        strcpy(Blynk_WM_config.header, BLYNK_BOARD_TYPE);
        
#if USE_DYNAMIC_PARAMETERS
        for (uint16_t i = 0; i < NUM_MENU_ITEMS; i++)
        {
          WN_LOGDEBUG3(F("g:myMenuItems["), i, F("]="), myMenuItems[i].pdata );
        }
#endif
        
        // Don't need
        Blynk_WM_config.checkSum = 0;

        saveConfigData();

        return false;
      }
      else if ( !isWiFiConfigValid() )
      {
        // If SSID, PW ="blank" or NULL, stay in config mode forever until having config Data.
        return false;
      }
      else
      {
        displayConfigData(Blynk_WM_config);
      }

      return true;
    }
    
    //////////////////////////////////////////////
    
    // New connection logic from v1.1.0
    bool connectMultiWiFi(int retry_time)
    {
      int sleep_time  = 250;
      int index       = 0;
      int new_index   = 0;
      uint8_t status  = WL_IDLE_STATUS;
                       
      static int lastConnectedIndex = 255;

      WN_LOGDEBUG(F("ConMultiWifi"));
      
      if (static_IP != IPAddress(0, 0, 0, 0))
      {
        WN_LOGDEBUG(F("UseStatIP"));
        WiFi.config(static_IP);
      }
      
      if (lastConnectedIndex != 255)
      {
        //  Successive connection, index = ??
        // Checking if new_index is OK
        new_index = (lastConnectedIndex + 1) % NUM_WIFI_CREDENTIALS;
        
        if ( strlen(Blynk_WM_config.WiFi_Creds[new_index].wifi_pw) >= PASSWORD_MIN_LEN )
        {    
          index = new_index;
          WN_LOGDEBUG3(F("Using index="), index, F(", lastConnectedIndex="), lastConnectedIndex);
        }
        else
        {
          WN_LOGERROR3(F("Ignore invalid WiFi PW : index="), new_index, F(", PW="), Blynk_WM_config.WiFi_Creds[new_index].wifi_pw);
          
          // Using the previous valid index
          index = lastConnectedIndex;
        }
      }
      else
      {
        //  First connection ever, index = 0
        if ( strlen(Blynk_WM_config.WiFi_Creds[0].wifi_pw) >= PASSWORD_MIN_LEN )
        {    
          WN_LOGDEBUG(F("First connection, Using index=0"));
        }
        else
        {
          WN_LOGERROR3(F("Ignore invalid WiFi PW : index=0, SSID="), Blynk_WM_config.WiFi_Creds[0].wifi_ssid,
                       F(", PWD="), Blynk_WM_config.WiFi_Creds[0].wifi_pw);
          
          // Using the next valid index
          index = 1;
        }
      } 
         
      WN_LOGERROR3(F("con2WF:SSID="), Blynk_WM_config.WiFi_Creds[index].wifi_ssid,
                   F(",PW="), Blynk_WM_config.WiFi_Creds[index].wifi_pw);
      
      uint8_t numIndexTried = 0;
      
      while ( !wifi_connected && (numIndexTried++ < NUM_WIFI_CREDENTIALS) )
      {         
        while ( 0 < retry_time )
        {      
          WN_LOGDEBUG1(F("Remaining retry_time="), retry_time);
          
          status = WiFi.begin(Blynk_WM_config.WiFi_Creds[index].wifi_ssid, Blynk_WM_config.WiFi_Creds[index].wifi_pw); 
              
          // Need restart WiFi at beginning of each cycle 
          if (status == WL_CONNECTED)
          {
            wifi_connected = true;          
            lastConnectedIndex = index;                                     
            WN_LOGDEBUG1(F("WOK, lastConnectedIndex="), lastConnectedIndex);
            
            break;
          }
          else
          {
            delay(sleep_time);
            retry_time--;
          }         
        }
        
        if (status == WL_CONNECTED)
        {         
          break;
        }
        else
        {        
          if (retry_time <= 0)
          {      
            WN_LOGERROR3(F("Failed using index="), index, F(", retry_time="), retry_time);
            retry_time = RETRY_TIMES_CONNECT_WIFI;  
          }
          
          new_index = (index + 1) % NUM_WIFI_CREDENTIALS;
          
          // only use new index if valid (len >= PASSWORD_MIN_LEN = 8)
          if ( strlen(Blynk_WM_config.WiFi_Creds[new_index].wifi_pw) >= PASSWORD_MIN_LEN )
          {
            index = new_index;
          }
          
          //WiFi.end();
        }
      }

      if (wifi_connected)
      {
        WN_LOGERROR(F("con2WF:OK"));
        
        WN_LOGERROR1(F("IP="), WiFi.localIP() );
        
        displayWiFiData();
      }
      else
      {
        WN_LOGERROR(F("con2WF:failed"));  
        // Can't connect, so try another index next time. Faking this index is OK and lost
        lastConnectedIndex = index;  
      }

      return wifi_connected;  
    }
    
    //////////////////////////////////////////////
    
    bool connectMultiBlynk()
    {
#define BLYNK_CONNECT_TIMEOUT_MS      5000L

      for (int i = 0; i < NUM_BLYNK_CREDENTIALS; i++)
      {
        config(Blynk_WM_config.Blynk_Creds[i].blynk_token,
               Blynk_WM_config.Blynk_Creds[i].blynk_server, Blynk_WM_config.blynk_port);

        if (connect(BLYNK_CONNECT_TIMEOUT_MS) )
        {
          WN_LOGERROR3(F("Con2BlynkServer="), Blynk_WM_config.Blynk_Creds[i].blynk_server,
                     F(",Token="), Blynk_WM_config.Blynk_Creds[i].blynk_token);
                     
          currentBlynkServerIndex = i;           
          return true;
        }
      }

      WN_LOGERROR(F("Blynk not connected"));

      return false;
    }

    //////////////////////////////////////////////
    
    // NEW
    void createHTML(String& root_html_template)
    {
      String pitem;
      
      root_html_template  = WIFININA_HTML_HEAD_START;
      
  #if USING_CUSTOMS_STYLE
      // Using Customs style when not NULL
      if (WIFININA_HTML_HEAD_CUSTOMS_STYLE)
        root_html_template  += WIFININA_HTML_HEAD_CUSTOMS_STYLE;
      else
        root_html_template  += WIFININA_HTML_HEAD_STYLE;
  #else     
      root_html_template  += WIFININA_HTML_HEAD_STYLE;
  #endif
      
  #if USING_CUSTOMS_HEAD_ELEMENT
      if (_CustomsHeadElement)
        root_html_template += _CustomsHeadElement;
  #endif
  

#if SCAN_WIFI_NETWORKS
      WN_LOGDEBUG1(WiFiNetworksFound, F(" SSIDs found, generating HTML now"));
      // Replace HTML <input...> with <select...>, based on WiFi network scan in startConfigurationMode()

      ListOfSSIDs = "";

      for (int i = 0, list_items = 0; (i < WiFiNetworksFound) && (list_items < MAX_SSID_IN_LIST); i++)
      {
        if (indices[i] == -1) 
          continue; 		// skip duplicates and those that are below the required quality
          
        ListOfSSIDs += WIFININA_OPTION_START + String(WiFi.SSID(indices[i])) + WIFININA_OPTION_END;	
        list_items++;		// Count number of suitable, distinct SSIDs to be included in list
      }

      WN_LOGDEBUG(ListOfSSIDs);

      if (ListOfSSIDs == "")		// No SSID found or none was good enough
        ListOfSSIDs = WIFININA_OPTION_START + String(WIFININA_NO_NETWORKS_FOUND) + WIFININA_OPTION_END;

      pitem = String(WIFININA_HTML_HEAD_END);

#if MANUAL_SSID_INPUT_ALLOWED
      pitem.replace("[[input_id]]",  "<input id='id' list='SSIDs'>"  + String(WIFININA_DATALIST_START) + "'SSIDs'>" + ListOfSSIDs + WIFININA_DATALIST_END);
      WN_LOGDEBUG1(F("pitem:"), pitem);
      pitem.replace("[[input_id1]]", "<input id='id1' list='SSIDs'>" + String(WIFININA_DATALIST_START) + "'SSIDs'>" + ListOfSSIDs + WIFININA_DATALIST_END);
      
      WN_LOGDEBUG1(F("pitem:"), pitem);

#else
      pitem.replace("[[input_id]]",  "<select id='id'>"  + ListOfSSIDs + WIFININA_SELECT_END);
      pitem.replace("[[input_id1]]", "<select id='id1'>" + ListOfSSIDs + WIFININA_SELECT_END);
#endif

      root_html_template += pitem + WIFININA_FLDSET_START;

#else

      pitem = String(WIFININA_HTML_HEAD_END);
      pitem.replace("[[input_id]]",  WIFININA_HTML_INPUT_ID);
      pitem.replace("[[input_id1]]", WIFININA_HTML_INPUT_ID1);
      root_html_template += pitem + WIFININA_FLDSET_START;

#endif    // SCAN_WIFI_NETWORKS


#if USE_DYNAMIC_PARAMETERS      
      for (uint16_t i = 0; i < NUM_MENU_ITEMS; i++)
      {
        pitem = String(WIFININA_HTML_PARAM);

        pitem.replace("{b}", myMenuItems[i].displayName);
        pitem.replace("{v}", myMenuItems[i].id);
        pitem.replace("{i}", myMenuItems[i].id);
        
        root_html_template += pitem;
      }
#endif
      
      root_html_template += String(WIFININA_FLDSET_END) + WIFININA_HTML_BUTTON + WIFININA_HTML_SCRIPT;     

#if USE_DYNAMIC_PARAMETERS      
      for (uint16_t i = 0; i < NUM_MENU_ITEMS; i++)
      {
        pitem = String(WIFININA_HTML_SCRIPT_ITEM);
        
        pitem.replace("{d}", myMenuItems[i].id);
        
        root_html_template += pitem;
      }
#endif
      
      root_html_template += String(WIFININA_HTML_SCRIPT_END) + WIFININA_HTML_END;
      
      return;     
    }
       
    //////////////////////////////////////////////

    void serverSendHeaders()
    {
      WN_LOGDEBUG3(F("serverSendHeaders:WM_HTTP_CACHE_CONTROL:"), WM_HTTP_CACHE_CONTROL, "=", WM_HTTP_NO_STORE);
      server->sendHeader(WM_HTTP_CACHE_CONTROL, WM_HTTP_NO_STORE);
      
#if USING_CORS_FEATURE
      // New from v1.1.0, for configure CORS Header, default to WM_HTTP_CORS_ALLOW_ALL = "*"
      WN_LOGDEBUG3(F("serverSendHeaders:WM_HTTP_CORS:"), WM_HTTP_CORS, " : ", _CORS_Header);
      server->sendHeader(WM_HTTP_CORS, _CORS_Header);
#endif
     
      WN_LOGDEBUG3(F("serverSendHeaders:WM_HTTP_PRAGMA:"), WM_HTTP_PRAGMA, " : ", WM_HTTP_NO_CACHE);
      server->sendHeader(WM_HTTP_PRAGMA, WM_HTTP_NO_CACHE);
      
      WN_LOGDEBUG3(F("serverSendHeaders:WM_HTTP_EXPIRES:"), WM_HTTP_EXPIRES, " : ", "-1");
      server->sendHeader(WM_HTTP_EXPIRES, "-1");
    }
       
    //////////////////////////////////////////////

    void handleRequest()
    {
      if (server)
      {
        String key    = server->arg("key");
        String value  = server->arg("value");

        static uint16_t number_items_Updated = 0;

        if (key == "" && value == "")
        {
          // New from v1.1.0         
          serverSendHeaders();        
          //////
          
          String result;
          createHTML(result);

          //WN_LOGERROR(F("h:repl"));

          // Reset configTimeout to stay here until finished.
          configTimeout = 0;
          
          if ( RFC952_hostname[0] != 0 )
          {
            // Replace only if Hostname is valid
            result.replace("BlynkWiFiNINA_SAMD_WM", RFC952_hostname);
          }
          else if ( Blynk_WM_config.board_name[0] != 0 )
          {
            // Or replace only if board_name is valid.  Otherwise, keep intact
            result.replace("BlynkWiFiNINA_SAMD_WM", Blynk_WM_config.board_name);
          }
                   
          if (hadConfigData)
          {
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
          }
          else
          {
            result.replace("[[id]]",  "");
            result.replace("[[pw]]",  "");
            result.replace("[[id1]]", "");
            result.replace("[[pw1]]", "");
            result.replace("[[sv]]",  "");
            result.replace("[[tk]]",  "");
            result.replace("[[sv1]]", "");
            result.replace("[[tk1]]", "");
            result.replace("[[pt]]",  "8080");
            result.replace("[[nm]]",  "SAMD_WiFiNINA");
          }
          
#if USE_DYNAMIC_PARAMETERS          
          for (uint16_t i = 0; i < NUM_MENU_ITEMS; i++)
          {
            String toChange = String("[[") + myMenuItems[i].id + "]]";
            result.replace(toChange, myMenuItems[i].pdata);
          }
#endif

          server->send(200, "text/html", result);

          return;
        }

        if (number_items_Updated == 0)
        {
          memset(&Blynk_WM_config, 0, sizeof(Blynk_WM_config));
          strcpy(Blynk_WM_config.header, BLYNK_BOARD_TYPE);
        }

#if USE_DYNAMIC_PARAMETERS
        if (!menuItemUpdated)
        {
          // Don't need to free
          menuItemUpdated = new bool[NUM_MENU_ITEMS];
          
          if (menuItemUpdated)
          {
            for (uint16_t i = 0; i < NUM_MENU_ITEMS; i++)
            {           
              // To flag item is not yet updated
              menuItemUpdated[i] = false;       
            }
            
            WN_LOGDEBUG1(F("h: Init menuItemUpdated :" ), NUM_MENU_ITEMS);                    
          }
          else
          {
            WN_LOGERROR(F("h: Error can't alloc memory for menuItemUpdated" ));
          }
        }  
#endif

        static bool id_Updated  = false;
        static bool pw_Updated  = false;
        static bool id1_Updated = false;
        static bool pw1_Updated = false;
        static bool sv_Updated  = false;
        static bool tk_Updated  = false;
        static bool sv1_Updated = false;
        static bool tk1_Updated = false;
        static bool pt_Updated  = false;
        static bool nm_Updated  = false;

        if (!id_Updated && (key == String("id")))
        {   
          WN_LOGDEBUG(F("h:repl id"));
          id_Updated = true;
          
          number_items_Updated++;
          
          if (strlen(value.c_str()) < sizeof(Blynk_WM_config.WiFi_Creds[0].wifi_ssid) - 1)
            strcpy(Blynk_WM_config.WiFi_Creds[0].wifi_ssid, value.c_str());
          else
            strncpy(Blynk_WM_config.WiFi_Creds[0].wifi_ssid, value.c_str(), sizeof(Blynk_WM_config.WiFi_Creds[0].wifi_ssid) - 1);
        }
        else if (!pw_Updated && (key == String("pw")))
        {    
          WN_LOGDEBUG(F("h:repl pw"));
          pw_Updated = true;
          
          number_items_Updated++;
          
          if (strlen(value.c_str()) < sizeof(Blynk_WM_config.WiFi_Creds[0].wifi_pw) - 1)
            strcpy(Blynk_WM_config.WiFi_Creds[0].wifi_pw, value.c_str());
          else
            strncpy(Blynk_WM_config.WiFi_Creds[0].wifi_pw, value.c_str(), sizeof(Blynk_WM_config.WiFi_Creds[0].wifi_pw) - 1);
        }
        else if (!id1_Updated && (key == String("id1")))
        {   
          WN_LOGDEBUG(F("h:repl id1"));
          id1_Updated = true;
          
          number_items_Updated++;
          
          if (strlen(value.c_str()) < sizeof(Blynk_WM_config.WiFi_Creds[1].wifi_ssid) - 1)
            strcpy(Blynk_WM_config.WiFi_Creds[1].wifi_ssid, value.c_str());
          else
            strncpy(Blynk_WM_config.WiFi_Creds[1].wifi_ssid, value.c_str(), sizeof(Blynk_WM_config.WiFi_Creds[1].wifi_ssid) - 1);
        }
        else if (!pw1_Updated && (key == String("pw1")))
        {    
          WN_LOGDEBUG(F("h:repl pw1"));
          pw1_Updated = true;
          
          number_items_Updated++;
          
          if (strlen(value.c_str()) < sizeof(Blynk_WM_config.WiFi_Creds[1].wifi_pw) - 1)
            strcpy(Blynk_WM_config.WiFi_Creds[1].wifi_pw, value.c_str());
          else
            strncpy(Blynk_WM_config.WiFi_Creds[1].wifi_pw, value.c_str(), sizeof(Blynk_WM_config.WiFi_Creds[1].wifi_pw) - 1);
        }
        else if (!sv_Updated && (key == String("sv")))
        {    
          WN_LOGDEBUG(F("h:repl sv"));
          sv_Updated = true;
          
          number_items_Updated++;
 
          if (strlen(value.c_str()) < sizeof(Blynk_WM_config.Blynk_Creds[0].blynk_server) - 1)
            strcpy(Blynk_WM_config.Blynk_Creds[0].blynk_server, value.c_str());
          else
            strncpy(Blynk_WM_config.Blynk_Creds[0].blynk_server, value.c_str(), sizeof(Blynk_WM_config.Blynk_Creds[0].blynk_server) - 1);
        }
        else if (!tk_Updated && (key == String("tk")))
        {    
          WN_LOGDEBUG(F("h:repl tk"));
          tk_Updated = true;
          
          number_items_Updated++;
          
          if (strlen(value.c_str()) < sizeof(Blynk_WM_config.Blynk_Creds[0].blynk_token) - 1)
            strcpy(Blynk_WM_config.Blynk_Creds[0].blynk_token, value.c_str());
          else
            strncpy(Blynk_WM_config.Blynk_Creds[0].blynk_token, value.c_str(), sizeof(Blynk_WM_config.Blynk_Creds[0].blynk_token) - 1);
        }
         else if (!sv1_Updated && (key == String("sv1")))
        {    
          WN_LOGDEBUG(F("h:repl sv1"));
          sv1_Updated = true;
          
          number_items_Updated++;
 
          if (strlen(value.c_str()) < sizeof(Blynk_WM_config.Blynk_Creds[1].blynk_server) - 1)
            strcpy(Blynk_WM_config.Blynk_Creds[1].blynk_server, value.c_str());
          else
            strncpy(Blynk_WM_config.Blynk_Creds[1].blynk_server, value.c_str(), sizeof(Blynk_WM_config.Blynk_Creds[1].blynk_server) - 1);
        }
        else if (!tk1_Updated && (key == String("tk1")))
        {    
          WN_LOGDEBUG(F("h:repl tk1"));
          tk1_Updated = true;
          
          number_items_Updated++;
          
          if (strlen(value.c_str()) < sizeof(Blynk_WM_config.Blynk_Creds[1].blynk_token) - 1)
            strcpy(Blynk_WM_config.Blynk_Creds[1].blynk_token, value.c_str());
          else
            strncpy(Blynk_WM_config.Blynk_Creds[1].blynk_token, value.c_str(), sizeof(Blynk_WM_config.Blynk_Creds[1].blynk_token) - 1);
        }
        else if (!pt_Updated && (key == String("pt")))
        {    
          WN_LOGDEBUG(F("h:repl pt"));
          pt_Updated = true;
          
          number_items_Updated++;
          
          Blynk_WM_config.blynk_port = value.toInt();
        }
        else if (!nm_Updated && (key == String("nm")))
        {    
          WN_LOGDEBUG(F("h:repl nm"));
          nm_Updated = true;
          
          number_items_Updated++;
          
          if (strlen(value.c_str()) < sizeof(Blynk_WM_config.board_name) - 1)
            strcpy(Blynk_WM_config.board_name, value.c_str());
          else
            strncpy(Blynk_WM_config.board_name, value.c_str(), sizeof(Blynk_WM_config.board_name) - 1);
        }

#if USE_DYNAMIC_PARAMETERS
        else
        {
          for (uint16_t i = 0; i < NUM_MENU_ITEMS; i++)
          {           
            if ( !menuItemUpdated[i] && (key == myMenuItems[i].id) )
            {
              WN_LOGDEBUG3(F("h:"), myMenuItems[i].id, F("="), value.c_str() );
              
              menuItemUpdated[i] = true;
              
              number_items_Updated++;

              // Actual size of pdata is [maxlen + 1]
              memset(myMenuItems[i].pdata, 0, myMenuItems[i].maxlen + 1);

              if ((int) strlen(value.c_str()) < myMenuItems[i].maxlen)
                strcpy(myMenuItems[i].pdata, value.c_str());
              else
                strncpy(myMenuItems[i].pdata, value.c_str(), myMenuItems[i].maxlen);
                
              break;  
            }
          }
        }  
#endif
        
        WN_LOGDEBUG1(F("h:items updated ="), number_items_Updated);
        WN_LOGDEBUG3(F("h:key ="), key, ", value =", value);

        server->send(200, "text/html", "OK");

#if USE_DYNAMIC_PARAMETERS        
        if (number_items_Updated == NUM_CONFIGURABLE_ITEMS + NUM_MENU_ITEMS)
#else
        if (number_items_Updated == NUM_CONFIGURABLE_ITEMS)
#endif
        {
          WN_LOGERROR(F("h:UpdEEPROM"));

          saveConfigData();

          WN_LOGERROR(F("h:Rst"));

          // TO DO : what command to reset
          // Delay then reset the board after save data
          delay(1000);
          resetFunc();  //call reset
        }
      }   // if (server)
    }

    //////////////////////////////////////////////

#ifndef CONFIG_TIMEOUT
  #warning Default CONFIG_TIMEOUT = 60s
  #define CONFIG_TIMEOUT			60000L
#endif

    void startConfigurationMode()
    {
#if SCAN_WIFI_NETWORKS
	    configTimeout = 0;  // To allow user input in CP
	    
	    WiFiNetworksFound = scanWifiNetworks(&indices);	
#endif

      WiFi.config(portal_apIP);

      if ( (portal_ssid == "") || portal_pass == "" )
      {
        String randomNum = String(random(0xFFFFFF), HEX);
        randomNum.toUpperCase();

        portal_ssid = "DUE_NINA_" + randomNum;
        portal_pass = "MyDUE_NINA_" + randomNum;
      }

      WiFi.config(portal_apIP);
      
      WN_LOGERROR5(F("stConf:SSID="), portal_ssid, F(",PW="), portal_pass, F(",IP="), portal_apIP);

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

#if SCAN_WIFI_NETWORKS

	  // Source code adapted from https://github.com/khoih-prog/ESP_WiFiManager/blob/master/src/ESP_WiFiManager-Impl.h

    int           _paramsCount            = 0;
    int           _minimumQuality         = -1;
    bool          _removeDuplicateAPs     = true;
	
	  //////////////////////////////////////////
    
    void swap(int *thisOne, int *thatOne)
    {
       int tempo;

       tempo    = *thatOne;
       *thatOne = *thisOne;
       *thisOne = tempo;
    }

    //////////////////////////////////////////
	
	  void setMinimumSignalQuality(int quality)
	  {
	    _minimumQuality = quality;
	  }

	  //////////////////////////////////////////

	  //if this is true, remove duplicate Access Points - default true
	  void setRemoveDuplicateAPs(bool removeDuplicates)
	  {
	    _removeDuplicateAPs = removeDuplicates;
	  }

	  //////////////////////////////////////////

	  //Scan for WiFiNetworks in range and sort by signal strength
	  //space for indices array allocated on the heap and should be freed when no longer required  
	  int scanWifiNetworks(int **indicesptr)
	  {
	    WN_LOGDEBUG(F("Scanning Network"));

	    int n = WiFi.scanNetworks();

	    WN_LOGDEBUG1(F("scanWifiNetworks: Done, Scanned Networks n = "), n); 

	    //KH, Terrible bug here. WiFi.scanNetworks() returns n < 0 => malloc( negative == very big ) => crash!!!
	    //In .../esp32/libraries/WiFi/src/WiFiType.h
	    //#define WIFI_SCAN_RUNNING   (-1)
	    //#define WIFI_SCAN_FAILED    (-2)
	    //if (n == 0)
	    if (n <= 0)
	    {
		    WN_LOGDEBUG(F("No network found"));
		    return (0);
	    }
	    else
	    {
		    // Allocate space off the heap for indices array.
		    // This space should be freed when no longer required.
		    int* indices = (int *)malloc(n * sizeof(int));

		    if (indices == NULL)
		    {
		      WN_LOGDEBUG(F("ERROR: Out of memory"));
		      *indicesptr = NULL;
		      return (0);
		    }

		    *indicesptr = indices;
	       
		    //sort networks
		    for (int i = 0; i < n; i++)
		    {
		      indices[i] = i;
		    }

		    WN_LOGDEBUG(F("Sorting"));

		    // RSSI SORT
		    // old sort
		    for (int i = 0; i < n; i++)
		    {
		      for (int j = i + 1; j < n; j++)
		      {
			      if (WiFi.RSSI(indices[j]) > WiFi.RSSI(indices[i]))
			      {
                    //std::swap(indices[i], indices[j]);
                    // Using locally defined swap()
                    swap(&indices[i], &indices[j]);
       			}
		      }
		    }

		    WN_LOGDEBUG(F("Removing Dup"));

		    // remove duplicates ( must be RSSI sorted )
		    if (_removeDuplicateAPs)
		    {
		      String cssid;
		      
		      for (int i = 0; i < n; i++)
		      {
			      if (indices[i] == -1)
			        continue;

			      cssid = WiFi.SSID(indices[i]);
			      
			      for (int j = i + 1; j < n; j++)
			      {
			        if (cssid == WiFi.SSID(indices[j]))
			        {
				        WN_LOGDEBUG1("DUP AP:", WiFi.SSID(indices[j]));
				        indices[j] = -1; // set dup aps to index -1
			        }
			      }
		      }
		    }

		    for (int i = 0; i < n; i++)
		    {
		      if (indices[i] == -1)
			      continue; // skip dups

		      int quality = getRSSIasQuality(WiFi.RSSI(indices[i]));

		      if (!(_minimumQuality == -1 || _minimumQuality < quality))
		      {
			      indices[i] = -1;
			      WN_LOGDEBUG(F("Skipping low quality"));
		      }
		    }

		    WN_LOGDEBUG(F("WiFi networks found:"));
		    
		    for (int i = 0; i < n; i++)
		    {
		      if (indices[i] == -1)
			      continue; // skip dups
		      else
			      WN_LOGDEBUG5(i+1,": ",WiFi.SSID(indices[i]), ", ", WiFi.RSSI(i), "dB");
		    }

		    return (n);
	    }
	  }

	  //////////////////////////////////////////

	  int getRSSIasQuality(int RSSI)
	  {
	    int quality = 0;

	    if (RSSI <= -100)
	    {
		    quality = 0;
	    }
	    else if (RSSI >= -50)
	    {
		    quality = 100;
	    }
	    else
	    {
		    quality = 2 * (RSSI + 100);
	    }

	    return quality;
	  }

  //////////////////////////////////////////

#endif	

};


//static WiFiSSLClient _blynkWifiClient;
static WiFiClient _blynkWifiClient;

static BlynkArduinoClient _blynkTransport(_blynkWifiClient);
BlynkWifiCommon Blynk(_blynkTransport);

#include <BlynkWidgets.h>

#endif    //BlynkSimpleWiFiNINA_DUE_WM_h

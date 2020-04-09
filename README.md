## Blynk_WiFiNINA_WM

[![arduino-library-badge](https://www.ardu-badge.com/badge/Blynk_WiFiNINA_WM.svg?)](https://www.ardu-badge.com/Blynk_WiFiNINA_WM)

### New Releases v1.0.1

1. Add support to ***SAM DUE, Teensy (4.0, 3.x, LC), STM32.***
2. AVR Mega can use dynamic parameters or not, depending on memory availability
3. Support 63 chars WPA2 WiFi password
4. Permit to input special chars such as ***%*** and ***#*** into data fields. Thanks to [brondolin](https://github.com/brondolin) to provide the amazing fix.

### New Releases v1.0.0

1. This release of very-easy-to-use will help you to eliminate hardcoding your Wifi and Blynk credentials for Mega/Teensy boards running WiFiNINA shields, and updating/reflashing every time when you need to change them.
2. Configuration data are stored in configurable location in EEPROM.
3. When WiFi and/or Blynk connection is lost, the WM will try auto-reconnect.
4. `Config Portal Static IP address, Name and Password.`
5. `Static IP address, Gateway, Subnet Mask.`
6. Currently support AVR Mega and SAMD (ZERO, MKR, ***NANO_33_IOT***, M0, M0 Pro, AdaFruit CIRCUITPLAYGROUND_EXPRESS, etc.) boards
7. Enhance GUI.

To help you to eliminate `hardcoding` your Wifi and Blynk credentials for Mega/Teensy boards running WiFiNINA modules/shields, and updating/reflashing every time when you need to change them. Configuration data are saved in configurable location in EEPROM/Flash.

With version `v1.0.0` or later, you now can configure:

1. `Config Portal Static IP address, Name and Password.`
2. `Static IP address, Gateway, Subnet Mask and 2 DNS Servers IP addresses.`

## Prerequisite
 1. [`Arduino IDE 1.8.12 or later` for Arduino](https://www.arduino.cc/en/Main/Software)
 2. [`Blynk library 0.6.1 or later`](https://www.arduino.cc/en/guide/libraries#toc3)
 3. [`Teensy core 1.51 or later`](https://www.pjrc.com/teensy/td_download.html) for Teensy (4.0, 3.6, 3.5, 3,2, 3.1, 3.0, LC) boards
 4. [`Arduino SAM DUE core 1.6.12 or later`](https://www.arduino.cc/en/Guide/ArduinoDue) for SAM DUE ARM Cortex-M3 boards
 5. [`Arduino SAMD core 1.8.5 or later`](https://www.arduino.cc/en/Guide/ArduinoM0) for SAMD ARM Cortex-M0+ boards
 6. [`Adafruit SAMD core 1.5.11 or later`](https://www.adafruit.com/) for SAMD ARM Cortex-M0+ and M4 boards (Nano 33 IoT, etc.)
 7. [`Arduino Core for STM32 v1.8.0 or later`](https://github.com/khoih-prog/Arduino_Core_STM32) for STM32 boards
 8. [`Functional-VLPP library`](https://github.com/khoih-prog/functional-vlpp) to use server's lambda function. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/Functional-Vlpp.svg?)](https://www.ardu-badge.com/Functional-Vlpp)
 9. [`WiFiNINA_Generic library v1.5.0 or later`](https://github.com/khoih-prog/WiFiNINA_Generic)
10. [`WiFiWebServer library`](https://github.com/khoih-prog/WiFiWebServer). To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiWebServer.svg?)](https://www.ardu-badge.com/WiFiWebServer)
11. [`FlashStorage_SAMD library v1.0.0`](https://github.com/khoih-prog/FlashStorage_SAMD) for SAMD21 and SAMD51 boards (ZERO, MKR, NANO_33_IOT, M0, M0 Pro, AdaFruit Itsy-Bitsy M4, etc.)
12. [`DueFlashStorage library`](https://github.com/sebnil/DueFlashStorage) for SAM DUE

## Installation

### Use Arduino Library Manager
The best and easiest way is to use `Arduino Library Manager`. Search for `Blynk_WiFiNINA_WM`, then select / install the latest version.
You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/Blynk_WiFiNINA_WM.svg?)](https://www.ardu-badge.com/Blynk_WiFiNINA_WM) for more detailed instructions.

### Manual Install

Another way to install is to:

1. Navigate to [Blynk_WiFiNINA_WM](https://github.com/khoih-prog/Blynk_WiFiNINA_WM) page.
2. Download the latest release `Blynk_WiFiNINA_WM-master.zip`.
3. Extract the zip file to `Blynk_WiFiNINA_WM-master` directory 
4. Copy whole `Blynk_WiFiNINA_WM-master/src` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### How to use

In your code, to use WiFiManager Blynk features, replace

1. `BlynkSimpleWiFiNINA.h` with `BlynkSimpleWiFiNINA_SAMD_WM.h`    for SAMD boards.
2. `BlynkSimpleWiFiNINA.h` with `BlynkSimpleWiFiNINA_Teensy_WM.h`  for Teensy boards.
3. `BlynkSimpleWiFiNINA.h` with `BlynkSimpleWiFiNINA_DUE_WM.h`     for SAM DUE boards.
4. `BlynkSimpleWiFiNINA.h` with `BlynkSimpleWiFiNINA_STM32_WM.h`   for STM32 boards.
5. `BlynkSimpleWiFiNINA.h` with `BlynkSimpleWiFiNINA_AVR_WM.h`     for Mega boards using dynamic parameters.
6. `BlynkSimpleWiFiNINA.h` with `BlynkSimpleWiFiNINA_AVR_WM_Small.h` for Mega boards not using dynamic parameters if not enough memory.

to use Blynk only, with hardcoded Credentials, replace
1. `BlynkSimpleWiFiNINA.h` with `BlynkSimpleWiFiNINA_SAMD.h`    for SAMD boards.
2. `BlynkSimpleWiFiNINA.h` with `BlynkSimpleWiFiNINA_Teensy.h`  for Teensy boards.
3. `BlynkSimpleWiFiNINA.h` with `BlynkSimpleWiFiNINA_DUE.h`     for SAM DUE boards.
4. `BlynkSimpleWiFiNINA.h` with `BlynkSimpleWiFiNINA_STM32.h`   for STM32 boards.
5. `BlynkSimpleWiFiNINA.h` with `BlynkSimpleWiFiNINA_AVR.h`     for Mega boards.

to use EEPROM to save your configuration data.

### EEPROM info

1. EEPROM_SIZE can be specified from 256 to 4096 bytes for Mega boards.
2. For SAMD21 boards, data is stored in FlashStorage using 256-byte block. For SAMD51 boards, data is stored in FlashStorage using 8-Kbyte block.
3. For SAM DUE boards, data is stored in EEPROM-simulating DueFlashStorage.
4. For Teensy 4.0 boards, EEPROM_SIZE is around 1 Kbytes.
4. For STM32 boards, EEPROM_SIZE presence depends on the selected boards.

### How to add dynamic parameters from sketch

- To add custom parameters, just modify from the example below

```
/////////////// Start dynamic Credentials ///////////////

//Defined in <BlynkSimpleWiFiNINA_SAMD_WM.h>
/**************************************
  #define MAX_ID_LEN                5
  #define MAX_DISPLAY_NAME_LEN      16

  typedef struct
  {
  char id             [MAX_ID_LEN + 1];
  char displayName    [MAX_DISPLAY_NAME_LEN + 1];
  char *pdata;
  uint8_t maxlen;
  } MenuItem;
**************************************/

#define MAX_MQTT_SERVER_LEN      34
char MQTT_Server  [MAX_MQTT_SERVER_LEN]   = "";

#define MAX_MQTT_PORT_LEN        6
char MQTT_Port   [MAX_MQTT_PORT_LEN]  = "";

#define MAX_MQTT_USERNAME_LEN      34
char MQTT_UserName  [MAX_MQTT_USERNAME_LEN]   = "";

#define MAX_MQTT_PW_LEN        34
char MQTT_PW   [MAX_MQTT_PW_LEN]  = "";

#define MAX_MQTT_SUBS_TOPIC_LEN      34
char MQTT_SubsTopic  [MAX_MQTT_SUBS_TOPIC_LEN]   = "";

#define MAX_MQTT_PUB_TOPIC_LEN       34
char MQTT_PubTopic   [MAX_MQTT_PUB_TOPIC_LEN]  = "";

MenuItem myMenuItems [] =
{
  { "mqtt", "MQTT Server",      MQTT_Server,      MAX_MQTT_SERVER_LEN },
  { "mqpt", "Port",             MQTT_Port,        MAX_MQTT_PORT_LEN   },
  { "user", "MQTT UserName",    MQTT_UserName,    MAX_MQTT_USERNAME_LEN },
  { "mqpw", "MQTT PWD",         MQTT_PW,          MAX_MQTT_PW_LEN },
  { "subs", "Subs Topics",      MQTT_SubsTopic,   MAX_MQTT_SUBS_TOPIC_LEN },
  { "pubs", "Pubs Topics",      MQTT_PubTopic,    MAX_MQTT_PUB_TOPIC_LEN },
};

uint16_t NUM_MENU_ITEMS = sizeof(myMenuItems) / sizeof(MenuItem);  //MenuItemSize;
/////// // End dynamic Credentials ///////////

```

If you don't need to add dynamic parameters, use the following in sketch

```
/////////////// Start dynamic Credentials ///////////////

MenuItem myMenuItems [] =
{
};

uint16_t NUM_MENU_ITEMS = sizeof(myMenuItems) / sizeof(MenuItem);  //MenuItemSize;
/////// // End dynamic Credentials ///////////

```

See examples 

1. [SAMD_WiFiNINA](examples/SAMD_WiFiNINA)
2. [Teensy_WiFiNINA](examples/Teensy_WiFiNINA)
3. [SAM_DUE_WiFiNINA](examples/SAM_DUE_WiFiNINA)
4. [STM32_WiFiNINA](examples/STM32_WiFiNINA)
5. [Mega_WiFiNINA](examples/Mega_WiFiNINA)

```
// Force some params in Blynk, only valid for library version 1.0.0 and later
#define TIMEOUT_RECONNECT_WIFI                    10000L
#define RESET_IF_CONFIG_TIMEOUT                   true
#define CONFIG_TIMEOUT_RETRYTIMES_BEFORE_RESET    5

```
To use personalized Config Portal AP SSID and Password, as well as IP Address, e.g. call :

```
// Set config portal SSID and Password
  Blynk.setConfigPortal("SAMD-WiFiNINA", "SAMD-WiFiNINAPass");
  // Set config portal IP address
  Blynk.setConfigPortalIP(IPAddress(192, 168, 200, 1));
```
You can specify STA-mode Static IP address,  Gateway, Subnet Mask, as well as DNS server 1 and 2:

```
  // From v1.0.0, select either one of these to set static IP + DNS
  Blynk.setSTAStaticIPConfig(IPAddress(192, 168, 2, 220), IPAddress(192, 168, 2, 1), IPAddress(255, 255, 255, 0));
```

Then replace `Blynk.begin(...)` with :

1. `Blynk.begin()` to use default DHCP hostname `SAMD-WiFiNINA` or `Mega-WiFiNINA`

or to have a personalized hostname `(RFC952-conformed,- 24 chars max,- only a..z A..Z 0..9 '-' and no '-' as last char)`

2. `Blynk.begin("Personalized-HostName")`

in your code. Keep `Blynk.run()` intact.

That's it.


## So, how it works?
If it cannot connect to the Blynk server in 30 seconds, it will switch to `Configuration Mode`. You will see your built-in LED turned ON. In `Configuration Mode`, it starts a configurable access point, default called `Teensy4_XXXXXX`, `SAMD_XXXXXX`, `DUE_XXXXXX`,`Mega_XXXXXX` or `STM32_XXXXXX`. Connect to it using password `MyTeensy4_XXXXXX`, `MySAMD_XXXXXX`, `MyDUE_XXXXXX`, `MyMega_XXXXXX` or `MySTM32_XXXXXX`.

<p align="center">
    <img src="https://github.com/khoih-prog/Blynk_WiFiNINA_WM/blob/master/pics/AccessPoint.jpg">
</p>

After you connected, please, go to http://192.168.4.1 or the AP IP you specified.

<p align="center">
    <img src="https://github.com/khoih-prog/Blynk_WiFiNINA_WM/blob/master/pics/Main.png">
</p>

Enter your credentials : WiFi SSID/Password, Blynk Server, Port and Token, Board Name.

<p align="center">
    <img src="https://github.com/khoih-prog/Blynk_WiFiNINA_WM/blob/master/pics/Config_Portal.png">
</p>

Then click `Save`. After you restarted, you will see your built-in LED turned OFF. That means, it connected to your Blynk server successfully.

The following is the sample terminal output when running example [SAMD_WiFiNINA](examples/SAMD_WiFiNINA)

1. No Config Data => Config Portal

```

Start Blynk_WiFiNINA_WM using WiFiNINA_Shield on SAMD NANO_33_IOT
Start Blynk_WM
[16286] RFC925 Hostname = SAMD-WiFiNINA
[16287] CrCCSum=2244,CrRCSum=0
[16288] CCSum=0,RCSsum=0
[16288] InitEEPROM,sz=1024,Datasz=336
[16288] pdata=,len=34
[16288] pdata=,len=6
[16289] pdata=,len=34
[16289] pdata=D_WiFiNINA,len=34
[16289] pdata=,len=34
[16289] pdata=,len=34
[16291] CrCCSum=3599
[16291] b:Nodat.Stay
[17052] stConf:SSID=SAMD_NINA_51F485,PW=MySAMD_NINA_51F485,IP=192.168.120.1
```

2. Config Data Ready => Run


```
Start Blynk_WiFiNINA_WM using WiFiNINA_Shield on SAMD NANO_33_IOT
Start Blynk_WM
[19387] RFC925 Hostname = SAMD-WiFiNINA
[19388] CrCCSum=6368,CrRCSum=6368
[19389] CCSum=7055,RCSsum=7055
[19389] Hdr=SHD_WiFiNINA,SSID=HueNet1,PW=****
[19389] Svr=account.duckdns.org,Prt=8080,Tok=****
[19389] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on NANO_33_IOT

[19390] con2WF:start
[20151] con2WF:millis=761
[20151] WiFiNINA Firmware Version: 1.3.0
[20151] Con2:HueNet1
[23346] IP:192.168.2.139
[23346] con2WF:OK
[23346] IP = 192.168.2.139, GW = 192.168.2.1, SN = 255.255.0.0
[23347] b:WOK.TryB
[23348] BlynkArduinoClient.connect: Connecting to account.duckdns.org:8080
[23468] Ready (ping: 6ms).
[23468] Free RAM: 24167
[23539] b:WBOK
BBBBBBBBBB BBBBBBBBBB BBBBBBBBBB BBBBBBBBBB

```

This `Blynk.begin()` is not a blocking call, so you can use it for critical functions requiring in loop(). 
Anyway, this is better for projects using Blynk just for GUI (graphical user interface).

In operation, if WiFi or Blynk connection is lost, `Blynk.run()` will try reconnecting automatically. Therefore, `Blynk.run()` must be called in the `loop()` function. Don't use:

```cpp
void loop()
{
  if (Blynk.connected())
     Blynk.run();
     
  ...
}
```
just

```cpp
void loop()
{
  Blynk.run();
  ...
}
```

## TO DO

 1. Add MultiWiFi feature to enable reconnect to the best / available WiFi AP.
 2. Add MultiBlynk feature to enable reconnect to the best / available Blynk Server.


## DONE

 1. Permit EEPROM size and location configurable to avoid conflict with others.
 2. More flexible to configure reconnection timeout.
 3. For fresh config data, don't need to wait for connecting timeout before entering config portal.
 4. If the config data not entered completely (SSID, password, Server and Blynk token), entering config portal 
 5. Add RFC952 hostname
 6. Add configurable Config Portal IP, SSID and Password
 7. Add configurable Static IP, GW, Subnet Mask IP Addresses.
 8. Enable dynamic custom data
 9. Add checksum for more reliable data
10. Same features for other boards using WiFiNINA WiFi shields such as STM32, Teensy, SAM DUE.

## Example
Please take a look at examples, as well.

```
/* Comment this out to disable prints and save space */
#define DEBUG_WIFI_WEBSERVER_PORT Serial
#define WIFININA_DEBUG_OUTPUT     Serial
#define BLYNK_PRINT Serial

#if    ( defined(ARDUINO_SAMD_ZERO) || defined(ARDUINO_SAMD_MKR1000) || defined(ARDUINO_SAMD_MKRWIFI1010) \
      || defined(ARDUINO_SAMD_NANO_33_IOT) || defined(ARDUINO_SAMD_MKRFox1200) || defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310) \
      || defined(ARDUINO_SAMD_MKRGSM1400) || defined(ARDUINO_SAMD_MKRNB1500) || defined(ARDUINO_SAMD_MKRVIDOR4000) || defined(__SAMD21G18A__) \
      || defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS) )
#if defined(WIFININA_USE_SAMD)
#undef WIFININA_USE_SAMD
#undef WIFI_USE_SAMD
#endif
#define WIFININA_USE_SAMD      true
#define WIFI_USE_SAMD          true
#else
#error This code is intended to run only on the SAMD boards ! Please check your Tools->Board setting.
#endif

#if defined(WIFININA_USE_SAMD)

#if defined(ARDUINO_SAMD_ZERO)
#define BOARD_TYPE      "SAMD Zero"
#elif defined(ARDUINO_SAMD_MKR1000)
#define BOARD_TYPE      "SAMD MKR1000"
#elif defined(ARDUINO_SAMD_MKRWIFI1010)
#define BOARD_TYPE      "SAMD MKRWIFI1010"
#elif defined(ARDUINO_SAMD_NANO_33_IOT)
#define BOARD_TYPE      "SAMD NANO_33_IOT"
#elif defined(ARDUINO_SAMD_MKRFox1200)
#define BOARD_TYPE      "SAMD MKRFox1200"
#elif ( defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310) )
#define BOARD_TYPE      "SAMD MKRWAN13X0"
#elif defined(ARDUINO_SAMD_MKRGSM1400)
#define BOARD_TYPE      "SAMD MKRGSM1400"
#elif defined(ARDUINO_SAMD_MKRNB1500)
#define BOARD_TYPE      "SAMD MKRNB1500"
#elif defined(ARDUINO_SAMD_MKRVIDOR4000)
#define BOARD_TYPE      "SAMD MKRVIDOR4000"
#elif defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS)
#define BOARD_TYPE      "SAMD ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS"
#else
#define BOARD_TYPE      "SAMD Unknown"
#endif
#endif

// Start location in EEPROM to store config data. Default 0
// Config data Size currently is 128 bytes)
#define EEPROM_START     1024

#define USE_BLYNK_WM      true
//#define USE_BLYNK_WM      false

#if USE_BLYNK_WM
#include <BlynkSimpleWiFiNINA_SAMD_WM.h>

/////////////// Start dynamic Credentials ///////////////

//Defined in <BlynkSimpleWiFiNINA_SAMD_WM.h>
/**************************************
  #define MAX_ID_LEN                5
  #define MAX_DISPLAY_NAME_LEN      16

  typedef struct
  {
  char id             [MAX_ID_LEN + 1];
  char displayName    [MAX_DISPLAY_NAME_LEN + 1];
  char *pdata;
  uint8_t maxlen;
  } MenuItem;
**************************************/

#define MAX_MQTT_SERVER_LEN      34
char MQTT_Server  [MAX_MQTT_SERVER_LEN]   = "";

#define MAX_MQTT_PORT_LEN        6
char MQTT_Port   [MAX_MQTT_PORT_LEN]  = "";

#define MAX_MQTT_USERNAME_LEN      34
char MQTT_UserName  [MAX_MQTT_USERNAME_LEN]   = "";

#define MAX_MQTT_PW_LEN        34
char MQTT_PW   [MAX_MQTT_PW_LEN]  = "";

#define MAX_MQTT_SUBS_TOPIC_LEN      34
char MQTT_SubsTopic  [MAX_MQTT_SUBS_TOPIC_LEN]   = "";

#define MAX_MQTT_PUB_TOPIC_LEN       34
char MQTT_PubTopic   [MAX_MQTT_PUB_TOPIC_LEN]  = "";

MenuItem myMenuItems [] =
{
  { "mqtt", "MQTT Server",      MQTT_Server,      MAX_MQTT_SERVER_LEN },
  { "mqpt", "Port",             MQTT_Port,        MAX_MQTT_PORT_LEN   },
  { "user", "MQTT UserName",    MQTT_UserName,    MAX_MQTT_USERNAME_LEN },
  { "mqpw", "MQTT PWD",         MQTT_PW,          MAX_MQTT_PW_LEN },
  { "subs", "Subs Topics",      MQTT_SubsTopic,   MAX_MQTT_SUBS_TOPIC_LEN },
  { "pubs", "Pubs Topics",      MQTT_PubTopic,    MAX_MQTT_PUB_TOPIC_LEN },
};

uint16_t NUM_MENU_ITEMS = sizeof(myMenuItems) / sizeof(MenuItem);  //MenuItemSize;
/////// // End dynamic Credentials ///////////

#else
#include <BlynkSimpleWiFiNINA_SAMD.h>

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

void heartBeatPrint(void)
{
  static int num = 1;

  if (Blynk.connected())
  {
    Serial.print("B");
  }
  else
  {
    Serial.print("F");
  }

  if (num == 80)
  {
    Serial.println();
    num = 1;
  }
  else if (num++ % 10 == 0)
  {
    Serial.print(" ");
  }
}

void check_status()
{
  static unsigned long checkstatus_timeout = 0;

#define STATUS_CHECK_INTERVAL     15000L

  // Send status report every STATUS_REPORT_INTERVAL (60) seconds: we don't need to send updates frequently if there is no status change.
  if ((millis() > checkstatus_timeout) || (checkstatus_timeout == 0))
  {
    // report status to Blynk
    heartBeatPrint();

    checkstatus_timeout = millis() + STATUS_CHECK_INTERVAL;
  }
}

void setup()
{
  // Debug console
  Serial.begin(115200);
  while (!Serial);
  //delay(1000);

  Serial.println("\nStart Blynk_WiFiNINA_WM using WiFiNINA_Shield on " + String(BOARD_TYPE));

#if USE_BLYNK_WM
  Serial.println(F("Start Blynk_WM"));
  Blynk.setConfigPortalIP(IPAddress(192, 168, 120, 1));
  //Blynk.setConfigPortal("SAMD", "MySAMD");
  Blynk.begin("SAMD-WiFiNINA");
#else
  Serial.println(F("Start Blynk"));
  Blynk.begin(auth, ssid, pass, BlynkServer.c_str(), BLYNK_SERVER_HARDWARE_PORT);
#endif
}

#if USE_BLYNK_WM
void displayCredentials(void)
{
  Serial.println("Your stored Credentials :");

  for (int i = 0; i < NUM_MENU_ITEMS; i++)
  {
    Serial.println(String(myMenuItems[i].displayName) + " = " + myMenuItems[i].pdata);
  }
}
#endif

void loop()
{
  Blynk.run();
  check_status();

#if USE_BLYNK_WM
  static bool displayedCredentials = false;

  if (!displayedCredentials)
  {
    for (int i = 0; i < NUM_MENU_ITEMS; i++)
    {
      if (!strlen(myMenuItems[i].pdata))
      {
        break;
      }

      if ( i == (NUM_MENU_ITEMS - 1) )
      {
        displayedCredentials = true;
        displayCredentials();
      }
    }
  }
#endif
}
```
### New Releases v1.0.1

1. Add support to SAM DUE, Teensy (4.0, 3.x, LC), STM32.
2. AVR Mega can select to use dynamic parameters or not, depending on memory availability
3. Support 63 chars WPA2 WiFi password
4. Permit to input special chars such as ***%*** and ***#*** into data fields. Thanks to [brondolin](https://github.com/brondolin) to provide the amazing fix.

### New Releases v1.0.0

1. This release of very-easy-to-use will help you to eliminate hardcoding your Wifi and Blynk credentials for Mega/Teensy boards running WiFiNINA shields, and updating/reflashing every time when you need to change them.
2. Configuration data are stored in configurable location in EEPROM.
3. When WiFi and/or Blynk connection is lost, the WM will try auto-reconnect.
4. `Config Portal Static IP address, Name and Password.`
5. `Static IP address, Gateway, Subnet Mask.`
6. Currently support AVR Mega and SAMD (ZERO, MKR, NANO_33_IOT, M0, M0 Pro, AdaFruit CIRCUITPLAYGROUND_EXPRESS, etc.) boards
7. Enhance GUI.

### Contributions and thanks

1. Thanks to [brondolin](https://github.com/brondolin) to provide the amazing fix to permit input special chars such as ***%*** and ***#*** into data fields.

## Contributing

If you want to contribute to this project:
- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

## Copyright

Copyright 2020- Khoi Hoang

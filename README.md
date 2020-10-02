## Blynk_WiFiNINA_WM

[![arduino-library-badge](https://www.ardu-badge.com/badge/Blynk_WiFiNINA_WM.svg?)](https://www.ardu-badge.com/Blynk_WiFiNINA_WM)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/Blynk_WiFiNINA_WM.svg)](https://github.com/khoih-prog/Blynk_WiFiNINA_WM/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/Blynk_WiFiNINA_WM/blob/master/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/Blynk_WiFiNINA_WM.svg)](http://github.com/khoih-prog/Blynk_WiFiNINA_WM/issues)

---
---

### New Releases v1.0.4

1. Add support to ***Arduino UNO WiFi R2***.

### Major Release v1.0.3

1. Add support to ***nRF52*** boards, such as ***AdaFruit Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B30_ublox, etc.***
2. ***Multiple WiFi Credentials (SSID, Password)*** and system will autoconnect to the available WiFi AP. It will then autoreconnect to the remaining WiFi AP if the current connection is lost.
3. ***Multiple Blynk Credentials (Server, Token)*** and system will autoconnect to the available Blynk Servers.
4. Configurable ***Config Portal Title*** to be either HostName, BoardName or default undistinguishable names.
5. Optional default ***Credentials as well as Dynamic parameters to be optionally autoloaded into Config Portal*** to use or change instead of manually input.
6. ***DoubleDetectDetector*** feature to force Config Portal when double reset is detected within predetermined time, default 10s.
7. Examples are redesigned to separate Credentials / Defines / Dynamic Params / Code so that you can change Credentials / Dynamic Params quickly for each device.
8. Add Board Name

Thanks to [Miguel Alexandre Wisintainer](https://github.com/tcpipchip) for initiating, inspriring, working with, developing, debugging and testing. Without that, support to nRF52, especially ***U-Box B302 running as nRF52840***, has never been started and finished.

Thanks to [Thor Johnson](https://github.com/thorathome) to test, suggest and encourage to add those new features in [Blynk_WM](https://github.com/khoih-prog/Blynk_WM), such as Default Credentials/Dynamic Params, Configurable Config Portal Title, DRD. Now those features are speading fast into libraries having similar functionalities.

### New Releases v1.0.2

1. Add support to ***SAM51 (Itsy-Bitsy M4, Metro M4, Grand Central M4, Feather M4 Express, etc.)***.
2. Fix bug

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

This library is designed to help you eliminate `hardcoding` your Wifi and Blynk credentials for Mega/Teensy boards running WiFiNINA modules/shields, and updating/reflashing every time when you need to change them. Configuration data are saved in configurable location in EEPROM/Flash.

With version `v1.0.0` or later, you now can configure:

1. `Config Portal Static IP address, Name and Password.`
2. `Static IP address, Gateway, Subnet Mask and 2 DNS Servers IP addresses.`

---
---

## Prerequisite

 1. [`Arduino IDE 1.8.13+`](https://www.arduino.cc/en/Main/Software)
 2. [`Blynk library 0.6.1+`](https://www.arduino.cc/en/guide/libraries#toc3)
 3. [`Teensy core 1.53+`](https://www.pjrc.com/teensy/td_download.html) for Teensy (4.0, 3.6, 3.5, 3,2, 3.1, 3.0, LC) boards
 4. [`Arduino SAM DUE core 1.6.12+`](https://www.arduino.cc/en/Guide/ArduinoDue) for SAM DUE ARM Cortex-M3 boards. To install go to Arduino IDE, select Boards Manager, search for ***`DUE`***
 5. [`Arduino SAMD core 1.8.8+`](https://www.arduino.cc/en/Guide/ArduinoM0) for SAMD ARM Cortex-M0+ boards. To install go to Arduino IDE, select Boards Manager, search for ***`Arduino SAMD`*** 
 6. [`Adafruit SAMD core 1.6.3+`](https://www.adafruit.com/) for SAMD ARM Cortex-M0+ and M4 boards (Nano 33 IoT, etc.). To install go to Arduino IDE, select Boards Manager, search for ***`Arduino M4`***
 7. [`Seeeduino SAMD core 1.7.9+`](https://www.seeedstudio.com/) for SAMD21/SAMD51 boards (XIAO M0, Wio Terminal, etc.) 
 8. [`Arduino Core for STM32 v1.9.0+`](https://github.com/khoih-prog/Arduino_Core_STM32) for STM32 boards.To install go to Arduino IDE, select Boards Manager, search for ***`STM32`***
 9. [`Adafruit nRF52 v0.21.0+`](https://www.adafruit.com) for nRF52 boards such as Adafruit NRF52840_FEATHER, NRF52832_FEATHER, NRF52840_FEATHER_SENSE, NRF52840_ITSYBITSY, NRF52840_CIRCUITPLAY, NRF52840_CLUE, NRF52840_METRO, NRF52840_PCA10056, PARTICLE_XENON, ***NINA_B302_ublox***, etc. To install go to Arduino IDE, select Boards Manager, search for ***`Adafruit nRF52`***
10. [`Functional-VLPP library v1.0.1+`](https://github.com/khoih-prog/functional-vlpp) to use server's lambda function. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/Functional-Vlpp.svg?)](https://www.ardu-badge.com/Functional-Vlpp)
11. [`WiFiNINA_Generic library v1.7.1+`](https://github.com/khoih-prog/WiFiNINA_Generic). To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiNINA_Generic.svg?)](https://www.ardu-badge.com/WiFiNINA_Generic)
12. [`WiFiWebServer library v1.0.7+`](https://github.com/khoih-prog/WiFiWebServer). To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiWebServer.svg?)](https://www.ardu-badge.com/WiFiWebServer)
13. [`FlashStorage_SAMD library v1.0.0+`](https://github.com/khoih-prog/FlashStorage_SAMD) for SAMD21 and SAMD51 boards (ZERO, MKR, ***NANO_33_IOT***, M0, M0 Pro, ***AdaFruit Itsy-Bitsy M4***, etc.)
14. [`DueFlashStorage library`](https://github.com/sebnil/DueFlashStorage) for SAM DUE
15. [`Adafruit's LittleFS/InternalFS`](https://www.adafruit.com) for nRF52. Already included if you already installed Adafruit ***nRF52 board package*** from Boards Manager.
16. [`DoubleResetDetector_Generic v1.0.2+`](https://github.com/khoih-prog/DoubleResetDetector_Generic). To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/DoubleResetDetector_Generic.svg?)](https://www.ardu-badge.com/DoubleResetDetector_Generic)

---

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

### VS Code & PlatformIO:
1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install **Blynk_WiFiNINA_WM** library by using [Library Manager](https://docs.platformio.org/en/latest/librarymanager/). Search for Blynk_WiFiNINA_WM in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)


---

### Packages' Patches

 1. ***To be able to compile, run and automatically detect and display BOARD_NAME on nRF52840/nRF52832 boards***, you have to copy the whole [nRF52 0.21.0](Packages_Patches/adafruit/hardware/nrf52/0.21.0) directory into Adafruit nRF52 directory (~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0). 

Supposing the Adafruit nRF52 version is 0.21.0. These files must be copied into the directory:
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/boards.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/variants/NINA_B302_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/variants/NINA_B302_ublox/variant.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/variants/NINA_B112_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/variants/NINA_B112_ublox/variant.cpp`
- ***`~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/cores/nRF5/Udp.h`***

Whenever a new version is installed, remember to copy these files into the new version directory. For example, new version is x.yy.z
These files must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/boards.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B302_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B302_ublox/variant.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B112_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B112_ublox/variant.cpp`
- ***`~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Udp.h`***

 2. ***To be able to compile and run on Teensy boards***, you have to copy the file [Teensy boards.txt](Packages_Patches/hardware/teensy/avr/boards.txt) into Teensy hardware directory (./arduino-1.8.12/hardware/teensy/avr/boards.txt). 

Supposing the Arduino version is 1.8.12. This file must be copied into the directory:

- `./arduino-1.8.12/hardware/teensy/avr/boards.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `./arduino-x.yy.zz/hardware/teensy/avr/boards.txt`

 3. ***To be able to compile and run on SAM DUE boards***, you have to copy the whole [SAM DUE](Packages_Patches/arduino/hardware/sam/1.6.12) directory into Arduino sam directory (~/.arduino15/packages/arduino/hardware/sam/1.6.12). 

Supposing the Arduino SAM core version is 1.6.12. This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/sam/1.6.12/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/sam/x.yy.zz/platform.txt`

 4. ***To be able to compile without error and automatically detect and display BOARD_NAME on Arduino SAMD (Nano-33-IoT, etc) boards***, you have to copy the whole [Arduino SAMD cores 1.8.8](Packages_Patches/arduino/hardware/samd/1.8.8) directory into Arduino SAMD directory (~/.arduino15/packages/arduino/hardware/samd/1.8.8).
 
Supposing the Arduino SAMD version is 1.8.8. These files must be copied into the directory:
- `~/.arduino15/packages/arduino/hardware/samd/1.8.8/platform.txt`
- ***`~/.arduino15/packages/arduino/hardware/samd/1.8.8/cores/arduino/Arduino.h`***

Whenever a new version is installed, remember to copy these files into the new version directory. For example, new version is x.yy.z

These files must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/x.yy.z/platform.txt`
- ***`~/.arduino15/packages/arduino/hardware/samd/x.yy.z/cores/arduino/Arduino.h`***
 
 This is mandatory to fix the ***notorious Arduino SAMD compiler error***. See [Improve Arduino compatibility with the STL (min and max macro)](https://github.com/arduino/ArduinoCore-samd/pull/399)
 
```
 ...\arm-none-eabi\include\c++\7.2.1\bits\stl_algobase.h:243:56: error: macro "min" passed 3 arguments, but takes just 2
     min(const _Tp& __a, const _Tp& __b, _Compare __comp)
```

Whenever the above-mentioned compiler error issue is fixed with the new Arduino SAMD release, you don't need to copy the `Arduino.h` file anymore.

 5. ***To be able to automatically detect and display BOARD_NAME on Adafruit SAMD (Itsy-Bitsy M4, etc) boards***, you have to copy the file [Adafruit SAMD platform.txt](Packages_Patches/adafruit/hardware/samd/1.6.3) into Adafruit samd directory (~/.arduino15/packages/adafruit/hardware/samd/1.6.3). 

Supposing the Adafruit SAMD core version is 1.6.3. This file must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/1.6.3/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/platform.txt`

 6. ***To be able to automatically detect and display BOARD_NAME on Seeeduino SAMD (XIAO M0, Wio Terminal, etc) boards***, you have to copy the file [Seeeduino SAMD platform.txt](Packages_Patches/Seeeduino/hardware/samd/1.7.9) into Adafruit samd directory (~/.arduino15/packages/Seeeduino/hardware/samd/1.7.9). 

Supposing the Seeeduino SAMD core version is 1.7.9. This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/1.7.9/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/platform.txt`

7. ***To use Serial1 on some STM32 boards without Serial1 definition (Nucleo-144 NUCLEO_F767ZI, Nucleo-64 NUCLEO_L053R8, etc.) boards***, you have to copy the files [STM32 variant.h](Packages_Patches/STM32/hardware/stm32/1.9.0) into STM32 stm32 directory (~/.arduino15/packages/STM32/hardware/stm32/1.9.0). You have to modify the files corresponding to your boards, this is just an illustration how to do.

Supposing the STM32 stm32 core version is 1.9.0. These files must be copied into the directory:

- `~/.arduino15/packages/STM32/hardware/stm32/1.9.0/variants/NUCLEO_F767ZI/variant.h` for Nucleo-144 NUCLEO_F767ZI.
- `~/.arduino15/packages/STM32/hardware/stm32/1.9.0/variants/NUCLEO_L053R8/variant.h` for Nucleo-64 NUCLEO_L053R8.

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz,
theses files must be copied into the corresponding directory:

- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/NUCLEO_F767ZI/variant.h`
- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/NUCLEO_L053R8/variant.h`


---
---

### How to use

In your code, to use WiFiManager Blynk features, replace

1. `BlynkSimpleWiFiNINA.h` with `BlynkSimpleWiFiNINA_SAMD_WM.h`    for SAMD boards.
2. `BlynkSimpleWiFiNINA.h` with `BlynkSimpleWiFiNINA_Teensy_WM.h`  for Teensy boards.
3. `BlynkSimpleWiFiNINA.h` with `BlynkSimpleWiFiNINA_nRF52_WM.h`   for nRF52 boards.
4. `BlynkSimpleWiFiNINA.h` with `BlynkSimpleWiFiNINA_DUE_WM.h`     for SAM DUE boards.
5. `BlynkSimpleWiFiNINA.h` with `BlynkSimpleWiFiNINA_STM32_WM.h`   for STM32 boards.
6. `BlynkSimpleWiFiNINA.h` with `BlynkSimpleWiFiNINA_AVR_WM.h`     for Mega boards using dynamic parameters.
7. `BlynkSimpleWiFiNINA.h` with `BlynkSimpleWiFiNINA_AVR_WM_Small.h` for Mega boards not using dynamic parameters if not enough memory.
8. `BlynkSimpleWiFiNINA.h` with `BlynkSimpleWiFiNINA_UNO_WiFi_WM_Small.h` for UNO WiFi R2 boards not using dynamic parameters if not enough memory.

to use Blynk only, with hardcoded Credentials, replace
1. `BlynkSimpleWiFiNINA.h` with `BlynkSimpleWiFiNINA_SAMD.h`     for SAMD boards.
2. `BlynkSimpleWiFiNINA.h` with `BlynkSimpleWiFiNINA_Teensy.h`   for Teensy boards.
3. `BlynkSimpleWiFiNINA.h` with `BlynkSimpleWiFiNINA_nRF52.h`    for nRF52 boards.
4. `BlynkSimpleWiFiNINA.h` with `BlynkSimpleWiFiNINA_DUE.h`      for SAM DUE boards.
5. `BlynkSimpleWiFiNINA.h` with `BlynkSimpleWiFiNINA_STM32.h`    for STM32 boards.
6. `BlynkSimpleWiFiNINA.h` with `BlynkSimpleWiFiNINA_AVR.h`      for Mega boards.
7. `BlynkSimpleWiFiNINA.h` with `BlynkSimpleWiFiNINA_UNO_WiFi.h` for UNO WiFi R2 boards.

to use EEPROM to save your configuration data.

### EEPROM info

1. EEPROM_SIZE can be specified from 256 to 4096 bytes for Mega boards.
2. For SAMD21 boards, data is stored in FlashStorage using 256-byte block. For SAMD51 boards, data is stored in FlashStorage using 8-Kbyte block.
3. For SAM DUE boards, data is stored in EEPROM-simulating DueFlashStorage.
4. For Teensy 4.0 boards, EEPROM_SIZE is around 1 Kbytes.
5. For STM32 boards, EEPROM_SIZE presence depends on the selected boards.
5. For nRF52 boards, data is stored in LittleFS/InternalFS.

---

### How to use default Credentials and have them pre-loaded onto Config Portal

See this example and modify as necessary

1. To load [Default Credentials](examples/SAMD_WiFiNINA_WM/Credentials.h)

```
bool LOAD_DEFAULT_CONFIG_DATA = true;
```

2. To use system default to load "blank" when there is no valid Credentials

```
bool LOAD_DEFAULT_CONFIG_DATA = false;
```

3. Example of [Default Credentials](examples/SAMD_WiFiNINA_WM/Credentials.h)

```cpp
/// Start Default Config Data //////////////////

/*
  // Defined in <BlynkSimpleWiFiNINA_SAMD_WM.h>

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
  //WiFi_Credentials  WiFi_Creds  [NUM_WIFI_CREDENTIALS]
  //WiFi_Creds.wifi_ssid and WiFi_Creds.wifi_pw
  "SSID1", "password1",
  "SSID2", "password2",
  // Blynk_Credentials Blynk_Creds [NUM_BLYNK_CREDENTIALS];
  // Blynk_Creds.blynk_server and Blynk_Creds.blynk_token
  "account.ddns.net",     "token",
  "account.duckdns.org",  "token1", 
  //int  blynk_port;
#if USE_SSL
  9443,
#else
  8080,
#endif
  //char board_name     [24];
  "Air-Control",
  //int  checkSum, dummy, not used
  0
};

/////////// End Default Config Data /////////////
```

---

### How to add dynamic parameters from sketch

- To add custom parameters, just modify from the example below

```
#if USE_BLYNK_WM

#define USE_DYNAMIC_PARAMETERS      true

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

#if USE_DYNAMIC_PARAMETERS

#define MAX_MQTT_SERVER_LEN      34
char MQTT_Server  [MAX_MQTT_SERVER_LEN + 1]   = "default-mqtt-server";

#define MAX_MQTT_PORT_LEN        6
char MQTT_Port   [MAX_MQTT_PORT_LEN + 1]  = "1883";

#define MAX_MQTT_USERNAME_LEN      34
char MQTT_UserName  [MAX_MQTT_USERNAME_LEN + 1]   = "default-mqtt-username";

#define MAX_MQTT_PW_LEN        34
char MQTT_PW   [MAX_MQTT_PW_LEN + 1]  = "default-mqtt-password";

#define MAX_MQTT_SUBS_TOPIC_LEN      34
char MQTT_SubsTopic  [MAX_MQTT_SUBS_TOPIC_LEN + 1]   = "default-mqtt-SubTopic";

#define MAX_MQTT_PUB_TOPIC_LEN       34
char MQTT_PubTopic   [MAX_MQTT_PUB_TOPIC_LEN + 1]  = "default-mqtt-PubTopic";

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

#else

MenuItem myMenuItems [] = {};

uint16_t NUM_MENU_ITEMS = 0;

#endif    //USE_DYNAMIC_PARAMETERS

/////// // End dynamic Credentials ///////////

#endif      //USE_BLYNK_WM

```

### If you don't need to add dynamic parameters, use the following in sketch

```
#define USE_DYNAMIC_PARAMETERS      false
```

```
// Force some params in Blynk, only valid for library version 1.0.0 and later
#define TIMEOUT_RECONNECT_WIFI                    10000L
#define RESET_IF_CONFIG_TIMEOUT                   true
#define CONFIG_TIMEOUT_RETRYTIMES_BEFORE_RESET    5

```
### To use personalized Config Portal AP SSID and Password, as well as IP Address, e.g. call :

```
// Set config portal SSID and Password
  Blynk.setConfigPortal("SAMD-WiFiNINA", "SAMD-WiFiNINAPass");
  // Set config portal IP address
  Blynk.setConfigPortalIP(IPAddress(192, 168, 200, 1));
```

### You can specify STA-mode Static IP address,  Gateway, Subnet Mask, as well as DNS server 1 and 2:

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

---

### Important Notes for using Dynamic Parameters' ids

1. These ids (such as "mqtt" in example) must be ***unique***.

Please be noted that the following ***reserved names are already used in library***:

```
"id"    for WiFi SSID
"pw"    for WiFi PW
"id1"   for WiFi1 SSID
"pw1"   for WiFi1 PW
"sv"    for Blynk Server
"tk"    for Blynk Token
"sv1"   for Blynk Server1
"tk1"   for Blynk Token1
"pt"    for Blynk Port
"nm"    for Board Name
```

---
---

### Examples 

1. [SAMD_WiFiNINA_WM](examples/SAMD_WiFiNINA_WM)
2. [Teensy_WiFiNINA_WM](examples/Teensy_WiFiNINA_WM)
3. [nRF52_WiFiNINA_WM](examples/STM32_WiFiNINA_WM)
4. [SAM_DUE_WiFiNINA_WM](examples/SAM_DUE_WiFiNINA_WM)
5. [STM32_WiFiNINA_WM](examples/STM32_WiFiNINA_WM)
6. [Mega_WiFiNINA_WM](examples/Mega_WiFiNINA_WM)
6. [UNO_WiFiNINA](examples/UNO_WiFiNINA)

---

## So, how it works?

If it cannot connect to the Blynk server in 30 seconds, it will switch to `Configuration Mode`. You will see your built-in LED turned ON. In `Configuration Mode`, it starts a configurable access point, default called `Teensy4_XXXXXX`, `SAMD_XXXXXX`, `NRF52_XXXXXX`, `DUE_XXXXXX`,`Mega_XXXXXX` or `STM32_XXXXXX`. Connect to it using password `MyTeensy4_XXXXXX`, `MySAMD_XXXXXX`, `MyNRF52_XXXXXX`, `MyDUE_XXXXXX`, `MyMega_XXXXXX` or `MySTM32_XXXXXX`.

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

Then click `Save`. 

<p align="center">
    <img src="https://github.com/khoih-prog/Blynk_WiFiNINA_WM/blob/master/pics/Save.png">
</p>

After the board autorestarted, you will see your built-in LED turned OFF. That means, it connected to your Blynk server successfully.

---

### Sample debug terminal output

The following is the sample terminal output when running example [SAMD_WiFiNINA_WM](examples/SAMD_WiFiNINA_WM)

1. No Config Data with **LOAD_DEFAULT_CONFIG_DATA = true** => Config Portal loads default Credentials and dynamic Params

```
Start Blynk_WiFiNINA_WM using WiFiNINA_Shield on SAMD NANO_33_IOT
Start Blynk_WM
Flag read = 0xd0d04321
No doubleResetDetected
SetFlag write = 0xd0d01234
[36272] ======= Start Default Config Data =======
[36272] Hdr=NonSSL,BrdName=Air-Control
[36272] SSID=SSID1,PW=password1
[36273] SSID1=SSID2,PW1=password2
[36273] Server=account.ddns.net,Token=token
[36273] Server1=account.duckdns.org,Token1=token1
[36273] Port=8080
[36273] ======= End Config Data =======
[36274] Hostname=SAMD-WiFiNINA
[36274] bg: noConfigPortal = true
[36274] ChkCrR:CrCCsum=219f,CrRCsum=219f
[36275] CrCCSum=8607,CrRCSum=8607
[36275] ======= Start Stored Config Data =======
[36275] Hdr=SHD_WiFiNINA,BrdName=Air-Control-Nano33-IoT
[36275] SSID=HueNet1,PW=new-password1
[36276] SSID1=HueNet2,PW1=new-password2
[36276] Server=account.ddns.net,Token=new-token
[36276] Server1=account.duckdns.org,Token1=new-token1
[36276] Port=8080
[36276] ======= End Config Data =======
[36277] CCSum=0x3047,RCSum=0x3047
[36277] Hdr=SHD_WiFiNINA,BrdName=Air-Control-Nano33-IoT
[36277] SSID=HueNet1,PW=new-password1
[36277] SSID1=HueNet2,PW1=new-password2
[36278] Server=account.ddns.net,Token=new-token
[36278] Server1=account.duckdns.org,Token1=new-token1
[36278] Port=8080
[36278] ======= End Config Data =======
[36278] Connecting MultiWifi...
[37039] con2WF:spentMsec=761
WiFi-begin: return1 = 6
WiFi-begin: return2 = 6
[47480] con2WF:spentMsec=11202
WiFi-begin: return1 = 6
WiFi-begin: return2 = 6
[56161] con2WF:spentMsec=19883
WiFi-begin: return1 = 6
WiFi-begin: return2 = 6
[64843] con2WF:spentMsec=1
WiFi-begin: return1 = 6
WiFi-begin: return2 = 6
[70416] con2WF:spentMsec=5574
WiFi-begin: return1 = 6
WiFi-begin: return2 = 6
[73985] con2WF:spentMsec=9143
WiFi-begin: return1 = 6
WiFi-begin: return2 = 6
[77554] con2WF:spentMsec=12712
WiFi-begin: return1 = 6
WiFi-begin: return2 = 6
[81122] con2WF:spentMsec=16280
WiFi-begin: return1 = 6
WiFi-begin: return2 = 6
[84691] con2WF:spentMsec=19849
WiFi-begin: return1 = 6
WiFi-begin: return2 = 6
[88260] con2WF:failed
[88260] b:FailW+B
[88261] stConf:SSID=SAMD_NINA_51F485,PW=MySAMD_NINA_51F485,IP=192.168.120.1
WiFi-beginAP3: return1 = 7
WiFi-beginAP3: return2 = 7
Stop doubleResetDetecting
ClearFlag write = 0xd0d04321
Your stored Credentials :
MQTT Server = new-mqtt-server
Port = 1883
MQTT UserName = new-mqtt-username
MQTT PWD = new-mqtt-password
Subs Topics = new-mqtt-SubTopic
Pubs Topics = new-mqtt-PubTopic
FFFFFFFFFF FFFFFFFFFF
```

2. Input valid credentials with **LOAD_DEFAULT_CONFIG_DATA = true** => reboot


```
Start Blynk_WiFiNINA_WM using WiFiNINA_Shield on SAMD NANO_33_IOT
Start Blynk_WM
Flag read = 0xd0d04321
No doubleResetDetected
SetFlag write = 0xd0d01234
[17584] ======= Start Default Config Data =======
[17584] Hdr=NonSSL,BrdName=Air-Control
[17585] SSID=SSID1,PW=password1
[17585] SSID1=SSID2,PW1=password2
[17585] Server=account.ddns.net,Token=token
[17585] Server1=account.duckdns.org,Token1=token1
[17585] Port=8080
[17586] ======= End Config Data =======
[17586] Hostname=SAMD-WiFiNINA
[17586] bg: noConfigPortal = true
[17586] ChkCrR:CrCCsum=219f,CrRCsum=219f
[17587] CrCCSum=8607,CrRCSum=8607
[17587] ======= Start Stored Config Data =======
[17587] Hdr=SHD_WiFiNINA,BrdName=Air-Control-Nano33-IoT
[17588] SSID=HueNet1,PW=****
[17588] SSID1=HueNet2,PW1=****
[17588] Server=192.168.2.112,Token=token
[17588] Server1=account.duckdns.org,Token1=token1
[17589] Port=8080
[17589] ======= End Config Data =======
[17589] CCSum=0x35ea,RCSum=0x35ea
[17589] Hdr=SHD_WiFiNINA,BrdName=Air-Control-Nano33-IoT
[17589] SSID=HueNet1,PW=****
[17590] SSID1=HueNet2,PW1=****
[17590] Server=192.168.2.112,Token=token
[17590] Server1=account.duckdns.org,Token1=token1
[17590] Port=8080
[17590] ======= End Config Data =======
[17591] Connecting MultiWifi...
[18351] con2WF:spentMsec=760
WiFi-begin: return1 = 3
WiFi-begin: return2 = 3
[21532] con2WF:OK
[21532] IP = 192.168.2.92, GW = 192.168.2.1, SN = 255.255.0.0
[21533] b:WOK.TryB
[21534] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on Arduino

[21535] BlynkArduinoClient.connect: Connecting to 192.168.2.112:8080
[21566] Ready (ping: 14ms).
[21637] Con2BlynkServer=192.168.2.112,Token=token
[21637] b:WBOK
Stop doubleResetDetecting
ClearFlag write = 0xd0d04321
Your stored Credentials :
MQTT Server = new-mqtt-server
Port = 1883
MQTT UserName = new-mqtt-username
MQTT PWD = new-mqtt-password
Subs Topics = new-mqtt-SubTopic
Pubs Topics = new-mqtt-PubTopic
BBBBBBBBBB BBBBBBBBBB BBBBBBBBBB BBBBBBBBBB

```

3. Simulate Blynk Server lost => auto(re)connect to the available Blynk Server

```
[21532] IP = 192.168.2.92, GW = 192.168.2.1, SN = 255.255.0.0
[21533] b:WOK.TryB
[21534] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on Arduino

[21535] BlynkArduinoClient.connect: Connecting to 192.168.2.112:8080
[21566] Ready (ping: 14ms).
[21637] Con2BlynkServer=192.168.2.112,Token=token
[21637] b:WBOK
Stop doubleResetDetecting
ClearFlag write = 0xd0d04321
Your stored Credentials :
MQTT Server = new-mqtt-server
Port = 1883
MQTT UserName = new-mqtt-username
MQTT PWD = new-mqtt-password
Subs Topics = new-mqtt-SubTopic
Pubs Topics = new-mqtt-PubTopic
BBBBBBBBBB BBBBBBBBBB BBBBBBBBBB BBBBBBBBBB
[241955] Heartbeat timeout
[241957] r:BLost.TryB
[241957] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on Arduino

[241958] BlynkArduinoClient.connect: Connecting to 192.168.2.112:8080
[244812] Ready (ping: 9ms).
[244883] Con2BlynkServer=192.168.2.112,Token=token
[244883] r:BOK
BBBBBBBBBB BBBBBBBBBB BBBBBBBBBB BBBBBBBBBB


[323979] Heartbeat timeout
[323985] r:BLost.TryB
[323985] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on Arduino

[323986] BlynkArduinoClient.connect: Connecting to 192.168.2.112:8080
[338806] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on Arduino

[338808] BlynkArduinoClient.connect: Connecting to account.duckdns.org:8080
[338841] Ready (ping: 6ms).
[338911] Con2BlynkServer=account.duckdns.org,Token=token1
[338911] r:BOK
BBBBBBBBBB BBBBBBBBBB BBBBBBBBBB BBBBBBBBBB
```

4. DoubleResetDetector detected => Config Portal is opened even if stored Credentials are valid.

```
Start Blynk_WiFiNINA_WM using WiFiNINA_Shield on SAMD NANO_33_IOT
Start Blynk_WM
Flag read = 0xd0d01234
doubleResetDetected
ClearFlag write = 0xd0d04321
[3358] Double Reset Detected
[3358] ======= Start Default Config Data =======
[3359] Hdr=NonSSL,BrdName=Air-Control
[3359] SSID=SSID1,PW=password1
[3359] SSID1=SSID2,PW1=password2
[3359] Server=account.ddns.net,Token=token
[3359] Server1=account.duckdns.org,Token1=token1
[3360] Port=8080
[3360] ======= End Config Data =======
[3360] Hostname=SAMD-WiFiNINA
[3360] bg: noConfigPortal = false
[3360] ChkCrR:CrCCsum=219f,CrRCsum=219f
[3361] CrCCSum=8607,CrRCSum=8607
[3361] ======= Start Stored Config Data =======
[3362] Hdr=SHD_WiFiNINA,BrdName=Air-Control-Nano33-IoT
[3362] SSID=HueNet1,PW=****
[3362] SSID1=HueNet2,PW1=****
[3362] Server=192.168.2.112,Token=token
[3362] Server1=account.duckdns.org,Token1=token1
[3363] Port=8080
[3363] ======= End Config Data =======
[3363] CCSum=0x35ea,RCSum=0x35ea
[3363] Hdr=SHD_WiFiNINA,BrdName=Air-Control-Nano33-IoT
[3364] SSID=HueNet1,PW=****
[3364] SSID1=HueNet2,PW1=****
[3364] Server=192.168.2.112,Token=token
[3364] Server1=account.duckdns.org,Token1=token1
[3364] Port=8080
[3365] ======= End Config Data =======
[3365] b:Nodat.Stay
[4126] stConf:SSID=SAMD_NINA_51F485,PW=MySAMD_NINA_51F485,IP=192.168.120.1
WiFi-beginAP3: return1 = 7
WiFi-beginAP3: return2 = 7
F
Your stored Credentials :
MQTT Server = new-mqtt-server
Port = 1883
MQTT UserName = new-mqtt-username
MQTT PWD = new-mqtt-password
Subs Topics = new-mqtt-SubTopic
Pubs Topics = new-mqtt-PubTopic
```
You can see that the system automatically detects and connects to the available WiFi APs and/or Blynk Servers, whenever interruption happens. This feature is very useful for systems requiring high degree of reliability.

This library's `Blynk.begin()` is not a blocking call, so you can use it for critical functions requiring in loop(). 
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

---
---

## Example [SAMD_WiFiNINA_WM](examples/SAMD_WiFiNINA_WM)

Please take a look at other examples, as well.

#### 1. File [SAMD_WiFiNINA_WM.ino](examples/SAMD_WiFiNINA_WM/SAMD_WiFiNINA_WM.ino)

```cpp
#include "defines.h"
#include "Credentials.h"
#include "dynamicParams.h"

void heartBeatPrint(void)
{
  static int num = 1;

  if (Blynk.connected())
  {
    Serial.print("B");
    Blynk.virtualWrite(V0, "OK");
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

#define STATUS_CHECK_INTERVAL     10000L

  // Send status report every STATUS_REPORT_INTERVAL (10) seconds: we don't need to send updates frequently if there is no status change.
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
  //Blynk.begin("SAMD-WiFiNINA");
  Blynk.begin(HOST_NAME);
#else
  Serial.println(F("Start Blynk"));
  Blynk.begin(auth, ssid, pass, BlynkServer.c_str(), BLYNK_SERVER_HARDWARE_PORT);
#endif
}

#if (USE_BLYNK_WM && USE_DYNAMIC_PARAMETERS)
void displayCredentials(void)
{
  Serial.println("\nYour stored Credentials :");

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

#if (USE_BLYNK_WM && USE_DYNAMIC_PARAMETERS)
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
---

#### 2. File [defines.h](examples/SAMD_WiFiNINA_WM/defines.h)

```cpp
#ifndef defines_h
#define defines_h

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#define DEBUG_WIFI_WEBSERVER_PORT Serial
#define WIFININA_DEBUG_OUTPUT     Serial

#define DRD_GENERIC_DEBUG         true
#define WIFININA_DEBUG            true
#define BLYNK_WM_DEBUG            3

#if ( defined(ARDUINO_SAMD_ZERO) || defined(ARDUINO_SAMD_MKR1000) || defined(ARDUINO_SAMD_MKRWIFI1010) \
   || defined(ARDUINO_SAMD_NANO_33_IOT) || defined(ARDUINO_SAMD_MKRFox1200) || defined(ARDUINO_SAMD_MKRWAN1300) \
   || defined(ARDUINO_SAMD_MKRWAN1310) || defined(ARDUINO_SAMD_MKRGSM1400) || defined(ARDUINO_SAMD_MKRNB1500) \
   || defined(ARDUINO_SAMD_MKRVIDOR4000) || defined(__SAMD21G18A__) || defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS) \
   || defined(__SAMD51__) || defined(__SAMD51J20A__) || defined(__SAMD51J19A__) || defined(__SAMD51G19A__) )
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
#elif defined(__SAMD21G18A__)
#define BOARD_TYPE      "SAMD21G18A"
#elif defined(__SAMD51G19A__)
#define BOARD_TYPE      "SAMD51G19"
#elif defined(__SAMD51J19A__)
#define BOARD_TYPE      "SAMD51J19A"
#elif defined(__SAMD51J20A__)
#define BOARD_TYPE      "SAMD51J20A"
#elif defined(__SAMD51__)
#define BOARD_TYPE      "SAMD51"
#else
#define BOARD_TYPE      "SAMD Unknown"
#endif
#endif

// Start location in EEPROM to store config data. Default 0
// Config data Size currently is 128 bytes)
#define EEPROM_START     0

#define EEPROM_SIZE     (2048)

#define USE_BLYNK_WM      true
//#define USE_BLYNK_WM      false

#define USE_SSL             false

#if USE_BLYNK_WM

#include <BlynkSimpleWiFiNINA_SAMD_WM.h>

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
//char ssid[] = "****";
//char pass[] = "****";

char ssid[] = "HueNet1";
char pass[] = "****";

#endif

#define HOST_NAME   "SAMD-WiFiNINA"

#endif      //defines_h
```
---

#### 3. File [Credentials.h](examples/SAMD_WiFiNINA_WM/Credentials.h)

```cpp
#ifndef Credentials_h
#define Credentials_h

#if USE_BLYNK_WM

/// Start Default Config Data //////////////////

/*
  // Defined in <BlynkSimpleWiFiNINA_SAMD_WM.h>

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
  //WiFi_Credentials  WiFi_Creds  [NUM_WIFI_CREDENTIALS]
  //WiFi_Creds.wifi_ssid and WiFi_Creds.wifi_pw
  "SSID1", "password1",
  "SSID2", "password2",
  // Blynk_Credentials Blynk_Creds [NUM_BLYNK_CREDENTIALS];
  // Blynk_Creds.blynk_server and Blynk_Creds.blynk_token
  "account.ddns.net",     "token",
  "account.duckdns.org",  "token1", 
  //int  blynk_port;
#if USE_SSL
  9443,
#else
  8080,
#endif
  //char board_name     [24];
  "Air-Control",
  //int  checkSum, dummy, not used
  0
};

/////////// End Default Config Data /////////////

#endif    //#if USE_BLYNK_WM

#endif    //Credentials_h
```

---

#### 4. File [dynamicParams.h](examples/SAMD_WiFiNINA_WM/dynamicParams.h)

```cpp
#ifndef dynamicParams_h
#define dynamicParams_h

#if USE_BLYNK_WM

#define USE_DYNAMIC_PARAMETERS      true

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

#if USE_DYNAMIC_PARAMETERS

#define MAX_MQTT_SERVER_LEN      34
char MQTT_Server  [MAX_MQTT_SERVER_LEN + 1]   = "default-mqtt-server";

#define MAX_MQTT_PORT_LEN        6
char MQTT_Port   [MAX_MQTT_PORT_LEN + 1]  = "1883";

#define MAX_MQTT_USERNAME_LEN      34
char MQTT_UserName  [MAX_MQTT_USERNAME_LEN + 1]   = "default-mqtt-username";

#define MAX_MQTT_PW_LEN        34
char MQTT_PW   [MAX_MQTT_PW_LEN + 1]  = "default-mqtt-password";

#define MAX_MQTT_SUBS_TOPIC_LEN      34
char MQTT_SubsTopic  [MAX_MQTT_SUBS_TOPIC_LEN + 1]   = "default-mqtt-SubTopic";

#define MAX_MQTT_PUB_TOPIC_LEN       34
char MQTT_PubTopic   [MAX_MQTT_PUB_TOPIC_LEN + 1]  = "default-mqtt-PubTopic";

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

#else

MenuItem myMenuItems [] = {};

uint16_t NUM_MENU_ITEMS = 0;

#endif    //USE_DYNAMIC_PARAMETERS

/////// // End dynamic Credentials ///////////

#endif      //USE_BLYNK_WM

#endif      //dynamicParams_h
```
---
---

## TO DO

 1. Same features for other boards.
 2. Bug finding and exterminating.


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
11. Same features for other boards using SAMD51 besides SAMD21.
12. Add MultiWiFi feature to enable reconnect to the available WiFi AP.
13. Add MultiBlynk feature to enable reconnect to the available Blynk Server.
14. WiFi Password max length is 63, as in WPA2 standards
15. Permit to input special chars such as ***%*** and ***#*** into data fields.
16. Add Dynamic Parameters with checksum
17. Default Credentials and dynamic parameters
18. DoubleDetectDetector to force Config Portal when double reset is detected within predetermined time, default 10s.
19. Configurable Config Portal Title
20. Re-structure all examples to separate Credentials / Defines / Dynamic Params / Code so that you can change Credentials / Dynamic Params quickly for each device.

---
---

### New Releases v1.0.4

1. Add support to ***Arduino UNO WiFi***.

#### Major Release v1.0.3

1. 2. Add support to ***nRF52*** boards, such as ***AdaFruit Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B30_ublox, etc.***
2. ***Multiple WiFi Credentials (SSID, Password)*** and system will autoconnect to the available WiFi AP. It will then autoreconnect to the remaining WiFi AP if the current connection is lost.
3. ***Multiple Blynk Credentials (Server, Token)*** and system will autoconnect to the available Blynk Servers.
4. Configurable ***Config Portal Title*** to be either HostName, BoardName or default undistinguishable names.
5. Optional default ***Credentials as well as Dynamic parameters to be optionally autoloaded into Config Portal*** to use or change instead of manually input.
6. ***DoubleDetectDetector*** feature to force Config Portal when double reset is detected within predetermined time, default 10s.
7. Examples are redesigned to separate Credentials / Defines / Dynamic Params / Code so that you can change Credentials / Dynamic Params quickly for each device.
8. Add Board Name

Thanks to [Miguel Alexandre Wisintainer](https://github.com/tcpipchip) for initiating, inspriring, working with, developing, debugging and testing. Without that, support to nRF52, especially ***U-Box B302 running as nRF52840***, has never been started and finished.

Thanks to [Thor Johnson](https://github.com/thorathome) to test, suggest and encourage to add those new features in [Blynk_WM](https://github.com/khoih-prog/Blynk_WM), such as Default Credentials/Dynamic Params, Configurable Config Portal Title, DRD. Now those features are speading fast into libraries having similar functionalities.

### New Releases v1.0.2

1. Add support to ***SAM51 (Itsy-Bitsy M4, Metro M4, Grand Central M4, Feather M4 Express, etc.)***.
2. Fix bug

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

---

### Contributions and thanks

1. Thanks to [brondolin](https://github.com/brondolin) to provide the amazing fix to permit input special chars such as ***%*** and ***#*** into data fields.
2. Thanks to [Miguel Alexandre Wisintainer](https://github.com/tcpipchip) for initiating, inspriring, working with, developing, debugging and testing. Without that, support to nRF52, especially ***U-Box B302 running as nRF52840***, has never been started and finished. See [u-blox nina b](https://github.com/khoih-prog/WiFiNINA_Generic/issues/1)
and [ESP32-based U-BLOX NINA W102 running ENC28J60](https://u-blox-ethernet-ninaw.blogspot.com/).
3. Thanks to [Thor Johnson](https://github.com/thorathome) to test, suggest and encourage to add those new features in [Blynk_WM](https://github.com/khoih-prog/Blynk_WM), such as Default Credentials/Dynamic Params, Configurable Config Portal Title, DRD. Now those features are speading fast into libraries having similar functionalities.

<table>
  <tr>
    <td align="center"><a href="https://github.com/thorathome"><img src="https://github.com/thorathome.png" width="100px;" alt="igrr"/><br /><sub><b>⭐️ Thor Johnson</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/brondolin"><img src="https://github.com/brondolin.png" width="100px;" alt="brondolin"/><br /><sub><b>brondolin</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/tcpipchip"><img src="https://github.com/tcpipchip.png" width="100px;" alt="tcpipchip"/><br /><sub><b>Miguel Wisintainer</b></sub></a><br /></td>
  </tr> 
</table>

---

## Contributing

If you want to contribute to this project:
- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License

- The library is licensed under [MIT](https://github.com/khoih-prog/Blynk_WiFiNINA_WM/blob/master/LICENSE)

---

## Copyright

Copyright 2020- Khoi Hoang


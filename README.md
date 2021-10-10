## Blynk_WiFiNINA_WM

[![arduino-library-badge](https://www.ardu-badge.com/badge/Blynk_WiFiNINA_WM.svg?)](https://www.ardu-badge.com/Blynk_WiFiNINA_WM)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/Blynk_WiFiNINA_WM.svg)](https://github.com/khoih-prog/Blynk_WiFiNINA_WM/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/Blynk_WiFiNINA_WM/blob/master/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/Blynk_WiFiNINA_WM.svg)](http://github.com/khoih-prog/Blynk_WiFiNINA_WM/issues)

--
---

## Table of Contents

* [Why do we need this Blynk_WiFiNINA_WM library](#why-do-we-need-this-blynk_wifinina_wm-library)
  * [Features](#features)
  * [Currently supported Boards](#currently-supported-boards)
  * [Currently supported shields/modules](#currently-supported-shieldsmodules)
* [Changelog](changelog.md)
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
    * [For Blynk v0.6.1](#for-blynk-v061)
    * [For Blynk v1.0.1](#for-blynk-v101)
  * [Manual Install](#manual-install)
    * [For Blynk v0.6.1](#for-blynk-v061-1)
    * [For Blynk v1.0.1](#for-blynk-v101-1)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [Packages' Patches](#packages-patches)
  * [1. For Adafruit nRF52840 and nRF52832 boards](#1-for-adafruit-nRF52840-and-nRF52832-boards)
  * [2. For Teensy boards](#2-for-teensy-boards)
  * [3. For Arduino SAM DUE boards](#3-for-arduino-sam-due-boards)
  * [4. For Arduino SAMD boards](#4-for-arduino-samd-boards)
      * [For core version v1.8.10+](#for-core-version-v1810)
      * [For core version v1.8.9-](#for-core-version-v189-)
  * [5. For Adafruit SAMD boards](#5-for-adafruit-samd-boards)
  * [6. For Seeeduino SAMD boards](#6-for-seeeduino-samd-boards)
  * [7. For STM32 boards](#7-for-stm32-boards) 
    * [7.1. For STM32 boards to use LAN8720](#71-for-stm32-boards-to-use-lan8720)
    * [7.2. For STM32 boards to use Serial1](#72-for-stm32-boards-to-use-serial1)
  * [8. For RP2040-based boards using Earle Philhower arduino-pico core](#8-for-rp2040-based-boards-using-earle-philhower-arduino-pico-core)
    * [8.1. To use BOARD_NAME](#81-to-use-board_name)
    * [8.2. To avoid compile error relating to microsecondsToClockCycles](#82-to-avoid-compile-error-relating-to-microsecondstoclockcycles)
  * [9. For Portenta_H7 boards using Arduino IDE in Linux](#9-for-portenta_h7-boards-using-arduino-ide-in-linux)
* [How to use](#how-to-use)
  * [ 1. Basic usage](#1-basic-usage)
  * [ 2. EEPROM info](#2-eeprom-info)
  * [ 3. To use personalized Config Portal AP SSID, Password and IP Address](#3-to-use-personalized-config-portal-ap-ssid-password-and-ip-address)
  * [ 4. To specify STA-mode Static IP address, Gateway, Subnet Mask, DNS server 1 and 2](#4-to-specify-sta-mode-static-ip-address-gateway-subnet-mask-dns-server-1-and-2)
* [HOWTO use default Credentials and have them pre-loaded onto Config Portal](#howto-use-default-credentials-and-have-them-pre-loaded-onto-config-portal)
  * [ 1. To load Default Credentials](#1-to-load-default-credentials)
  * [ 2. To use system default to load "blank" when there is no valid Credentials](#2-to-use-system-default-to-load-blank-when-there-is-no-valid-credentials)
  * [ 3. Example of Default Credentials](#3-example-of-default-credentials)
  * [ 4. How to add dynamic parameters from sketch](#4-how-to-add-dynamic-parameters-from-sketch)
  * [ 5. If you don't need to add dynamic parameters](#5-if-you-dont-need-to-add-dynamic-parameters)
  * [ 6. To use custom HTML Style](#6-to-use-custom-html-style)
  * [ 7. To use custom Head Elements](#7-to-use-custom-head-elements)
  * [ 8. To use CORS Header](#8-to-use-cors-header)
  * [ 9. To use and input only one set of WiFi SSID and PWD](#9-to-use-and-input-only-one-set-of-wifi-ssid-and-pwd)
    * [ 9.1 If you need to use and input only one set of WiFi SSID/PWD](#91-if-you-need-to-use-and-input-only-one-set-of-wifi-ssidpwd)
    * [ 9.2 If you need to use both sets of WiFi SSID/PWD](#92-if-you-need-to-use-both-sets-of-wifi-ssidpwd)
  * [10. To enable auto-scan of WiFi networks for selection in Configuration Portal](#10-to-enable-auto-scan-of-wifi-networks-for-selection-in-configuration-portal)
    * [10.1 Enable auto-scan of WiFi networks for selection in Configuration Portal](#101-enable-auto-scan-of-wifi-networks-for-selection-in-configuration-portal)
    * [10.2 Disable manually input SSIDs](#102-disable-manually-input-ssids)
    * [10.3 Select maximum number of SSIDs in the list](#103-select-maximum-number-of-ssids-in-the-list)
* [Important Notes for using Dynamic Parameters' ids](#important-notes-for-using-dynamic-parameters-ids)
* [Why using this Blynk_WiFiNINA_WM with MultiWiFi-MultiBlynk features](#why-using-this-blynk_wifinina_wm-with-multiwifi-multiblynk-features)
* [Examples](#examples)
  * [ 1. SAMD_WiFiNINA_WM](examples/SAMD_WiFiNINA_WM)
  * [ 2. Teensy_WiFiNINA_WM](examples/Teensy_WiFiNINA_WM)
  * [ 3. nRF52_WiFiNINA_WM](examples/nRF52_WiFiNINA_WM)
  * [ 4. SAM_DUE_WiFiNINA_WM](examples/SAM_DUE_WiFiNINA_WM)
  * [ 5. STM32_WiFiNINA_WM](examples/STM32_WiFiNINA_WM)
  * [ 6. Mega_WiFiNINA_WM](examples/Mega_WiFiNINA_WM)
  * [ 7. UNO_WiFiNINA](examples/UNO_WiFiNINA)
  * [ 8. RP2040_WiFiNINA_WM](examples/RP2040_WiFiNINA_WM) **New**
* [So, how it works?](#so-how-it-works)
* [Example SAMD_WiFiNINA_WM](#example-samd_wifinina_wm)
  * [1. File SAMD_WiFiNINA_WM.ino](#1-file-samd_wifinina_wmino)
  * [2. File defines.h](#2-file-definesh) 
  * [3. File Credentials.h](#3-file-credentialsh) 
  * [4. File dynamicParams.h](#4-file-dynamicparamsh) 
* [Debug Terminal Output Samples](#debug-terminal-output-samples)
  * [1. SAMD_WiFiNINA_WM using WiFiNINA_Shield on SAMD NANO_33_IOT](#1-samd_wifinina_wm-using-wifinina_shield-on-samd-nano_33_iot)
    * [1.1. No Config Data without LOAD_DEFAULT_CONFIG_DATA => Config Portal](#11-no-config-data-without-load_default_config_data--config-portal)
    * [1.2. Input valid Credentials and Save => Exit Config Portal](#12-input-valid-credentials-and-save--exit-config-portal)
    * [1.3 Lost a WiFi and autoconnect to another WiFi AP](#13-lost-a-wifi-and-autoconnect-to-another-wifi-ap)
    * [1.4 DRD detected and Config Portal is forcefully opened](#14-drd-detected-and-config-portal-is-forcefully-opened)
  * [2. RP2040_WiFiNINA_WM using WiFiNINA_Shield on MBED NANO_RP2040_CONNECT](#2-rp2040_wifinina_wm-using-wifinina_shield-on-mbed-nano_rp2040_connect)
    * [2.1. No Config Data without LOAD_DEFAULT_CONFIG_DATA => Config Portal](#21-no-config-data-without-load_default_config_data--config-portal)
    * [2.2. Input valid Credentials and Save => Exit Config Portal](#22-input-valid-credentials-and-save--exit-config-portal)
* [Debug](#debug)
* [Troubleshooting](#troubleshooting)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)

---
---

### Why do we need this [Blynk_WiFiNINA_WM library](https://github.com/khoih-prog/Blynk_WiFiNINA_WM)

#### Features

This is a Blynk and WiFiNINA WiFiManager Library for configuring/auto(re)connecting boards to available MultiBlynk servers at runtime. Connection is with or without SSL. Configuration data to be saved in either LittleFS, SPIFFS, EEPROM, DueFlashStorage or FlashStorage. Default Credentials as well as Dynamic custom parameters can be added and modified easily without coding knowledge. 

DoubleResetDetector is used to force Config Portal opening even if the Credentials are still valid.

This is the new library, adding to the current Blynk_WiFiManager. It's designed to help you eliminate `hardcoding` your Blynk credentials in **Teensy, SAM DUE, SAMD21, SAMD51, nRF52, ESP8266, ESP32, RP2040-based, etc. boards using WiFiNINA shields.

- You can update Blynk Credentials any time you need to change via Configure Portal. Data are saved in configurable locations in LittleFS, EEPROM, DueFlashStorage, FlashStorage_SAMD or FlashStorage_STM32
- Teensy 2.0++ and 2.0 not supported.
- STM32 must have 64K+ Flash to use Blynk WiFiManager features
- **DoubleDetectDetector** feature to force Config Portal when double reset is detected within predetermined time, default 10s.
- Configurable **Config Portal Title** to be either BoardName or default undistinguishable names.
- Examples are redesigned to separate Credentials / Defines / Dynamic Params / Code so that you can change Credentials / Dynamic Params quickly for each device

The **RP2040-based boards, such as RASPBERRY_PI_PICO**, are currently supported using [**Earle Philhower's arduino-pico** core](https://github.com/earlephilhower/arduino-pico) or [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed) with Blynk/WiFiManager features thanks to LittleFS support. 

New recent features:

- **MultiWiFi** feature for configuring/auto(re)connecting **Generic WiFi (WiFiNINA, WINC1500/WiFi101, WiFiEsp, etc.)** shields to the available MultiWiFi APs at runtime.
- **DoubleDetectDetector** feature to force Config Portal when double reset is detected within predetermined time, default 10s.
- **Powerful-yet-simple-to-use feature to enable adding dynamic custom parameters** from sketch and input using the same Config Portal. Config Portal will be auto-adjusted to match the number of dynamic parameters.
- Optional default **Credentials as well as Dynamic parameters to be optionally autoloaded into Config Portal** to use or change instead of manually input.
- Dynamic custom parameters to be saved **automatically in non-volatile memory, such as Teensy EEPROM, SAMD EEPROM-emulated FlashStorage_SAMD, STM32F/L/H/G/WB/MP1 EEPROM-emulated FlashStorage_STM32, SAM DUE DueFlashStorage or nRF52/RP2040 LittleFS**.
- Configurable **Config Portal Title** to be either BoardName or default undistinguishable names.
- Examples are designed to separate Credentials / Defines / Dynamic Params / Code so that you can change Credentials / Dynamic Params quickly for each device.
- Control Config Portal from software or Virtual Switches
- To permit autoreset after configurable timeout if DRD/MRD or non-persistent forced-CP
- Use new nRF52, RP2040 LittleFS, SAMD FlashStorage_SAMD and STM32F/L/H/G/WB/MP1 FlashStorage_STM32 features
- **Scan WiFi networks** for selection in Configuration Portal

---

#### Currently supported Boards

This [**EthernetWebServer** library](https://github.com/khoih-prog/EthernetWebServer) currently supports these following boards:

 1. **nRF52 boards**, such as **AdaFruit Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B302_ublox, NINA_B112_ublox, etc.**
 2. **SAM DUE**
 3. **SAMD21**
  - Arduino SAMD21: ZERO, MKRs, NANO_33_IOT, etc.
  - Adafruit SAMD21 (M0): ItsyBitsy M0, Feather M0, Feather M0 Express, Metro M0 Express, Circuit Playground Express, Trinket M0, PIRkey, Hallowing M0, Crickit M0, etc.
  - Seeeduino:  LoRaWAN, Zero, Femto M0, XIAO M0, Wio GPS Board, etc.
  
 4. **SAMD51**
  - Adafruit SAMD51 (M4): Metro M4, Grand Central M4, ItsyBitsy M4, Feather M4 Express, Trellis M4, Metro M4 AirLift Lite, MONSTER M4SK Express, Hallowing M4, etc.
  - Seeeduino: Wio Terminal, Grove UI Wireless
  
 5. **Teensy (4.1, 4.0, 3.6, 3.5, 3,2, 3.1, 3.0)**
 
 6. **AVR Mega1280, 2560, ADK.**
 
 7. RP2040-based boards, such as **Nano RP2040 Connect**, using [**Arduino mbed OS for Nano boards**](https://github.com/arduino/ArduinoCore-mbed).

 8. RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed) or [**Earle Philhower's arduino-pico** core](https://github.com/earlephilhower/arduino-pico).

---

#### Currently supported shields/modules

1. WiFiNINA (u-blox W102,etc.) using [`WiFiNINA_Generic library`](https://github.com/khoih-prog/WiFiNINA_Generic).


---
---


## Prerequisites

 1. [`Arduino IDE v1.8.16+`](https://github.com/arduino/Arduino). Use [Arduino IDE v1.8.13](https://github.com/arduino/Arduino/releases/tag/1.8.13) for Teensy boards.
 2. [`Blynk library 1.0.1`](https://github.com/blynkkk/blynk-library/releases/tag/v0.6.1). [![Latest release](https://img.shields.io/github/release/blynkkk/blynk-library.svg)](https://github.com/blynkkk/blynk-library/releases/latest/). Never use the `Blynk beta` versions.
 3. [`Teensy core 1.55+`](https://www.pjrc.com/teensy/td_download.html) for Teensy (4.x, 3.6, 3.5, 3,2, 3.1, 3.0, LC) boards.
 4. [`Arduino SAM DUE core 1.6.12+`](https://github.com/arduino/ArduinoCore-sam) for SAM DUE ARM Cortex-M3 boards
 5. [`Arduino SAMD core 1.8.11+`](https://www.arduino.cc/en/Guide/ArduinoM0) for SAMD ARM Cortex-M0+ boards. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-samd.svg)](https://github.com/arduino/ArduinoCore-samd/releases/latest)
 6. [`Adafruit SAMD core 1.7.5+`](https://www.adafruit.com/) for SAMD ARM Cortex-M0+ and M4 boards (Nano 33 IoT, etc.). [![GitHub release](https://img.shields.io/github/release/adafruit/ArduinoCore-samd.svg)](https://github.com/adafruit/ArduinoCore-samd/releases/latest)
 7. [`Seeeduino SAMD core 1.8.2+`](https://github.com/Seeed-Studio/ArduinoCore-samd) for SAMD21/SAMD51 boards (XIAO M0, Wio Terminal, etc.). [![Latest release](https://img.shields.io/github/release/Seeed-Studio/ArduinoCore-samd.svg)](https://github.com/Seeed-Studio/ArduinoCore-samd/releases/latest/)
 8. [`Arduino Core for STM32 v2.1.0+`](https://github.com/stm32duino/Arduino_Core_STM32) for STM32F/L/H/G/WB/MP1 boards. [![GitHub release](https://img.shields.io/github/release/stm32duino/Arduino_Core_STM32.svg)](https://github.com/stm32duino/Arduino_Core_STM32/releases/latest)
 
 9. [`Adafruit nRF52 v1.1.0`](https://github.com/adafruit/Adafruit_nRF52_Arduino) for nRF52 boards such as Adafruit NRF52840_FEATHER, NRF52832_FEATHER, NRF52840_FEATHER_SENSE, NRF52840_ITSYBITSY, NRF52840_CIRCUITPLAY, NRF52840_CLUE, NRF52840_METRO, NRF52840_PCA10056, PARTICLE_XENON, **NINA_B302_ublox**, etc. [![GitHub release](https://img.shields.io/github/release/adafruit/Adafruit_nRF52_Arduino.svg)](https://github.com/adafruit/Adafruit_nRF52_Arduino/releases/latest)
 
10. [`Arduino mbed_rp2040 core 2.5.2+`](https://github.com/arduino/ArduinoCore-mbed) for Arduino RP2040-based boards, such as **Arduino Nano RP2040 Connect, RASPBERRY_PI_PICO, etc.**. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-mbed.svg)](https://github.com/arduino/ArduinoCore-mbed/releases/latest)
11. [`Earle Philhower's arduino-pico core v1.9.5+`](https://github.com/earlephilhower/arduino-pico) for RP2040-based boards such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, etc. [![GitHub release](https://img.shields.io/github/release/earlephilhower/arduino-pico.svg)](https://github.com/earlephilhower/arduino-pico/releases/latest)
12. [`Functional-VLPP library v1.0.2+`](https://github.com/khoih-prog/functional-vlpp) to use server's lambda function. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/Functional-Vlpp.svg?)](https://www.ardu-badge.com/Functional-Vlpp)
13. [`WiFiNINA_Generic library v1.8.13+`](https://github.com/khoih-prog/WiFiNINA_Generic). To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiNINA_Generic.svg?)](https://www.ardu-badge.com/WiFiNINA_Generic)
14. [`WiFiWebServer library v1.4.1+`](https://github.com/khoih-prog/WiFiWebServer) if necessary to use certain WiFi/WiFiNINA features. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiWebServer.svg?)](https://www.ardu-badge.com/WiFiWebServer)
15. [`FlashStorage_SAMD library v1.2.0+`](https://github.com/khoih-prog/FlashStorage_SAMD) for SAMD21 and SAMD51 boards (ZERO, MKR, NANO_33_IOT, M0, M0 Pro, AdaFruit Itsy-Bitsy M4, etc.) if necessary to use certain features. [![GitHub release](https://img.shields.io/github/release/khoih-prog/FlashStorage_SAMD.svg)](https://github.com/khoih-prog/FlashStorage_SAMD/releases/latest)
16. [`FlashStorage_STM32 library v1.1.0+`](https://github.com/khoih-prog/FlashStorage_STM32) for STM32F/L/H/G/WB/MP1 boards. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/FlashStorage_STM32.svg?)](https://www.ardu-badge.com/FlashStorage_STM32)
17. [`DueFlashStorage library v1.0.0+`](https://github.com/sebnil/DueFlashStorage) for SAM DUE if necessary to use certain features. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/DueFlashStorage.svg?)](https://www.ardu-badge.com/DueFlashStorage).
18. [`Adafruit's LittleFS/InternalFS`](https://www.adafruit.com) for nRF52. Already included if you already installed Adafruit **nRF52 board package** from Boards Manager.
19. [`DoubleResetDetector_Generic v1.7.2+`](https://github.com/khoih-prog/DoubleResetDetector_Generic) if necessary to use some examples. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/DoubleResetDetector_Generic.svg?)](https://www.ardu-badge.com/DoubleResetDetector_Generic) if necessary to use certain features.

---

## Installation

### Use Arduino Library Manager

The best and easiest way is to use `Arduino Library Manager`. Search for [**Blynk_WiFiNINA_WM**](https://github.com/khoih-prog/Blynk_WiFiNINA_WM), then select / install the latest version.
You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/Blynk_WiFiNINA_WM.svg?)](https://www.ardu-badge.com/Blynk_WiFiNINA_WM) for more detailed instructions.

Then copy

#### For Blynk v0.6.1

1. [BlynkDetectDevice.h](LibraryPatches/Blynk-0.6.1/Blynk/BlynkDetectDevice.h) to folder ~/Arduino/libraries/Blynk/src/Blynk to overwrite the original file `BlynkDetectDevice.h`.
2. [BlynkProtocol.h](LibraryPatches/Blynk-0.6.1/Blynk/BlynkProtocol.h) to folder ~/Arduino/libraries/Blynk/src/Blynk to overwrite the original file `BlynkProtocol.h`.
3. [BlynkDebug.cpp](LibraryPatches/Blynk-0.6.1/utility/BlynkDebug.cpp) to folder ~/Arduino/libraries/Blynk/src/utility to overwrite the original file `BlynkDebug.cpp`.

#### For Blynk v1.0.1

1. [BlynkDetectDevice.h](LibraryPatches/Blynk-1.0.1/Blynk/BlynkDetectDevice.h) to folder ~/Arduino/libraries/Blynk/src/Blynk to overwrite the original file `BlynkDetectDevice.h`.
2. [BlynkDebug.cpp](LibraryPatches/Blynk-1.0.1/utility/BlynkDebug.cpp) to folder ~/Arduino/libraries/Blynk/src/utility to overwrite the original file `BlynkDebug.cpp`.

---

### Manual Install

1. Navigate to [**Blynk_WiFiNINA_WM**](https://github.com/khoih-prog/Blynk_WiFiNINA_WM) page.
2. Download the latest release `Blynk_WiFiNINA_WM-master.zip`.
3. Extract the zip file to `Blynk_WiFiNINA_WM-master` directory 
4. Copy the whole 
  - `Blynk_WiFiNINA_WM-master` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

Then copy

#### For Blynk v0.6.1

1. [BlynkDetectDevice.h](LibraryPatches/Blynk-0.6.1/Blynk/BlynkDetectDevice.h) to folder ~/Arduino/libraries/Blynk/src/Blynk to overwrite the original file `BlynkDetectDevice.h`.
2. [BlynkProtocol.h](LibraryPatches/Blynk-0.6.1/Blynk/BlynkProtocol.h) to folder ~/Arduino/libraries/Blynk/src/Blynk to overwrite the original file `BlynkProtocol.h`.
3. [BlynkDebug.cpp](LibraryPatches/Blynk-0.6.1/utility/BlynkDebug.cpp) to folder ~/Arduino/libraries/Blynk/src/utility to overwrite the original file `BlynkDebug.cpp`.

#### For Blynk v1.0.1

1. [BlynkDetectDevice.h](LibraryPatches/Blynk-1.0.1/Blynk/BlynkDetectDevice.h) to folder ~/Arduino/libraries/Blynk/src/Blynk to overwrite the original file `BlynkDetectDevice.h`.
2. [BlynkDebug.cpp](LibraryPatches/Blynk-1.0.1/utility/BlynkDebug.cpp) to folder ~/Arduino/libraries/Blynk/src/utility to overwrite the original file `BlynkDebug.cpp`.
  
  
### VS Code & PlatformIO

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**Blynk_WiFiNINA_WM** library](https://platformio.org/lib/show/12374/Blynk_WiFiNINA_WM) by using [Library Manager](https://platformio.org/lib/show/12374/Blynk_WiFiNINA_WM/installation). Search for **Blynk_WiFiNINA_WM** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)


---
---

### Packages' Patches

#### 1. For Adafruit nRF52840 and nRF52832 boards

**To be able to compile, run and automatically detect and display BOARD_NAME on nRF52840/nRF52832 boards**, you have to copy the whole [nRF52 Packages_Patches](Packages_Patches/adafruit/hardware/nrf52/1.1.0) directory into Adafruit nRF52 directory (~/.arduino15/packages/adafruit/hardware/nrf52/1.1.0). 

Supposing the Adafruit nRF52 version is 1.1.0. These files must be copied into the directory:
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.1.0/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.1.0/boards.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.1.0/cores/nRF5/Udp.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.1.0/cores/nRF5/Print.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.1.0/cores/nRF5/Print.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.1.0/variants/NINA_B302_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.1.0/variants/NINA_B302_ublox/variant.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.1.0/variants/NINA_B112_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.1.0/variants/NINA_B112_ublox/variant.cpp`
- **`~/.arduino15/packages/adafruit/hardware/nrf52/1.1.0/cores/nRF5/Udp.h`**

Whenever a new version is installed, remember to copy these files into the new version directory. For example, new version is x.yy.z
These files must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/boards.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Udp.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Print.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Print.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B302_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B302_ublox/variant.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B112_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B112_ublox/variant.cpp`
- **`~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Udp.h`**

#### 2. For Teensy boards
 
 **To be able to compile and run on Teensy boards**, you have to copy the files in [**Packages_Patches for Teensy directory**](Packages_Patches/hardware/teensy/avr) into Teensy hardware directory (./arduino-1.8.15/hardware/teensy/avr/boards.txt). 

Supposing the Arduino version is 1.8.15. These files must be copied into the directory:

- `./arduino-1.8.15/hardware/teensy/avr/boards.txt`
- `./arduino-1.8.15/hardware/teensy/avr/cores/teensy/Stream.h`
- `./arduino-1.8.15/hardware/teensy/avr/cores/teensy3/Stream.h`
- `./arduino-1.8.15/hardware/teensy/avr/cores/teensy4/Stream.h`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
These files must be copied into the directory:

- `./arduino-x.yy.zz/hardware/teensy/avr/boards.txt`
- `./arduino-x.yy.zz/hardware/teensy/avr/cores/teensy/Stream.h`
- `./arduino-x.yy.zz/hardware/teensy/avr/cores/teensy3/Stream.h`
- `./arduino-x.yy.zz/hardware/teensy/avr/cores/teensy4/Stream.h`

#### 3. For Arduino SAM DUE boards
 
 **To be able to compile and run on SAM DUE boards**, you have to copy the whole [SAM DUE](Packages_Patches/arduino/hardware/sam/1.6.12) directory into Arduino sam directory (~/.arduino15/packages/arduino/hardware/sam/1.6.12). 

Supposing the Arduino SAM core version is 1.6.12. This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/sam/1.6.12/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/sam/x.yy.zz/platform.txt`

#### 4. For Arduino SAMD boards
 
 ***To be able to compile, run and automatically detect and display BOARD_NAME on Arduino SAMD (Nano-33-IoT, etc) boards***, you have to copy the whole [Arduino SAMD Packages_Patches](Packages_Patches/arduino/hardware/samd/1.8.11) directory into Arduino SAMD directory (~/.arduino15/packages/arduino/hardware/samd/1.8.11).
 
#### For core version v1.8.10+

Supposing the Arduino SAMD version is 1.8.11. Now only one file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/1.8.11/platform.txt`

Whenever a new version is installed, remember to copy this files into the new version directory. For example, new version is x.yy.zz

This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/x.yy.zz/platform.txt`
 
#### For core version v1.8.9-

Supposing the Arduino SAMD version is 1.8.9. These files must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/1.8.9/platform.txt`
- ***`~/.arduino15/packages/arduino/hardware/samd/1.8.9/cores/arduino/Arduino.h`***

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

#### 5. For Adafruit SAMD boards
 
 ***To be able to compile, run and automatically detect and display BOARD_NAME on Adafruit SAMD (Itsy-Bitsy M4, etc) boards***, you have to copy the whole [Adafruit SAMD Packages_Patches](Packages_Patches/adafruit/hardware/samd/1.7.5) directory into Adafruit samd directory (~/.arduino15/packages/adafruit/hardware/samd/1.7.5). 

Supposing the Adafruit SAMD core version is 1.7.5. This file must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/1.7.5/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/samd/1.7.5/cores/arduino/Print.h`
- `~/.arduino15/packages/adafruit/hardware/samd/1.7.5/cores/arduino/Print.cpp`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/cores/arduino/Print.h`
- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/cores/arduino/Print.cpp`

#### 6. For Seeeduino SAMD boards
 
 ***To be able to compile, run and automatically detect and display BOARD_NAME on Seeeduino SAMD (XIAO M0, Wio Terminal, etc) boards***, you have to copy the whole [Seeeduino SAMD Packages_Patches](Packages_Patches/Seeeduino/hardware/samd/1.8.2) directory into Seeeduino samd directory (~/.arduino15/packages/Seeeduino/hardware/samd/1.8.2). 

Supposing the Seeeduino SAMD core version is 1.8.2. This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.2/platform.txt`
- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.2/cores/arduino/Arduino.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.2/cores/arduino/Print.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.2/cores/arduino/Print.cpp`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/platform.txt`
- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/cores/arduino/Arduino.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/cores/arduino/Print.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/cores/arduino/Print.cpp`

#### 7. For STM32 boards

#### 7.1 For STM32 boards to use LAN8720

To use LAN8720 on some STM32 boards 

- **Nucleo-144 (F429ZI, NUCLEO_F746NG, NUCLEO_F746ZG, NUCLEO_F756ZG)**
- **Discovery (DISCO_F746NG)**
- **STM32F4 boards (BLACK_F407VE, BLACK_F407VG, BLACK_F407ZE, BLACK_F407ZG, BLACK_F407VE_Mini, DIYMORE_F407VGT, FK407M1)**

you have to copy the files [stm32f4xx_hal_conf_default.h](Packages_Patches/STM32/hardware/stm32/2.1.0/system/STM32F4xx) and [stm32f7xx_hal_conf_default.h](Packages_Patches/STM32/hardware/stm32/2.1.0/system/STM32F7xx) into STM32 stm32 directory (~/.arduino15/packages/STM32/hardware/stm32/2.1.0/system) to overwrite the old files.

Supposing the STM32 stm32 core version is 2.1.0. These files must be copied into the directory:

- `~/.arduino15/packages/STM32/hardware/stm32/2.1.0/system/STM32F4xx/stm32f4xx_hal_conf_default.h` for STM32F4.
- `~/.arduino15/packages/STM32/hardware/stm32/2.1.0/system/STM32F7xx/stm32f7xx_hal_conf_default.h` for Nucleo-144 STM32F7.

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz,
theses files must be copied into the corresponding directory:

- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/system/STM32F4xx/stm32f4xx_hal_conf_default.h`
- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/system/STM32F7xx/stm32f7xx_hal_conf_default.h


#### 7.2 For STM32 boards to use Serial1

**To use Serial1 on some STM32 boards without Serial1 definition (Nucleo-144 NUCLEO_F767ZI, Nucleo-64 NUCLEO_L053R8, etc.) boards**, you have to copy the files [STM32 variant.h](Packages_Patches/STM32/hardware/stm32/2.1.0) into STM32 stm32 directory (~/.arduino15/packages/STM32/hardware/stm32/2.1.0). You have to modify the files corresponding to your boards, this is just an illustration how to do.

Supposing the STM32 stm32 core version is 2.1.0. These files must be copied into the directory:

- `~/.arduino15/packages/STM32/hardware/stm32/2.1.0/variants/STM32F7xx/F765Z(G-I)T_F767Z(G-I)T_F777ZIT/NUCLEO_F767ZI/variant.h` for Nucleo-144 NUCLEO_F767ZI.
- `~/.arduino15/packages/STM32/hardware/stm32/2.1.0/variants/STM32L0xx/L052R(6-8)T_L053R(6-8)T_L063R8T/NUCLEO_L053R8/variant.h` for Nucleo-64 NUCLEO_L053R8.

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz,
theses files must be copied into the corresponding directory:

- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/STM32F7xx/F765Z(G-I)T_F767Z(G-I)T_F777ZIT/NUCLEO_F767ZI/variant.h`
- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/STM32L0xx/L052R(6-8)T_L053R(6-8)T_L063R8T/NUCLEO_L053R8/variant.h`

#### 8. For RP2040-based boards using [Earle Philhower arduino-pico core](https://github.com/earlephilhower/arduino-pico)

#### 8.1 To use BOARD_NAME

 **To be able to automatically detect and display BOARD_NAME on RP2040-based boards (RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040, GENERIC_RP2040, etc) boards**, you have to copy the file [RP2040 platform.txt](Packages_Patches/rp2040/hardware/rp2040/1.4.0) into rp2040 directory (~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0). 

Supposing the rp2040 core version is 1.4.0. This file must be copied into the directory:

- `~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/rp2040/hardware/rp2040/x.yy.zz/platform.txt`

With core after v1.5.0, this step is not necessary anymore thanks to the PR [Add -DBOARD_NAME="{build.board}" #136](https://github.com/earlephilhower/arduino-pico/pull/136).

#### 8.2 To avoid compile error relating to microsecondsToClockCycles

Some libraries, such as [Adafruit DHT-sensor-library](https://github.com/adafruit/DHT-sensor-library), require the definition of microsecondsToClockCycles(). **To be able to compile and run on RP2040-based boards**, you have to copy the files in [**RP2040 Arduino.h**](Packages_Patches/rp2040/hardware/rp2040/1.4.0/cores/rp2040/Arduino.h) into rp2040 directory (~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0).

Supposing the rp2040 core version is 1.4.0. This file must be copied to replace:

- `~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0/cores/rp2040/Arduino.h`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied to replace:

- `~/.arduino15/packages/rp2040/hardware/rp2040/x.yy.zz/cores/rp2040/Arduino.h`

With core after v1.5.0, this step is not necessary anymore thanks to the PR [Add defs for compatibility #142](https://github.com/earlephilhower/arduino-pico/pull/142).


#### 9. For Portenta_H7 boards using Arduino IDE in Linux

  **To be able to upload firmware to Portenta_H7 using Arduino IDE in Linux (Ubuntu, etc.)**, you have to copy the file [portenta_post_install.sh](Packages_Patches/arduino/hardware/mbed_portenta/2.4.1/portenta_post_install.sh) into mbed_portenta directory (~/.arduino15/packages/arduino/hardware/mbed_portenta/2.4.1/portenta_post_install.sh). 
  
  Then run the following command using `sudo`
  
```
$ cd ~/.arduino15/packages/arduino/hardware/mbed_portenta/2.4.1
$ chmod 755 portenta_post_install.sh
$ sudo ./portenta_post_install.sh
```

This will create the file `/etc/udev/rules.d/49-portenta_h7.rules` as follows:

```
# Portenta H7 bootloader mode UDEV rules

SUBSYSTEMS=="usb", ATTRS{idVendor}=="2341", ATTRS{idProduct}=="035b", GROUP="plugdev", MODE="0666"
```

Supposing the ArduinoCore-mbed core version is 2.4.1. Now only one file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/mbed_portenta/2.4.1/portenta_post_install.sh`

Whenever a new version is installed, remember to copy this files into the new version directory. For example, new version is x.yy.zz

This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/mbed_portenta/x.yy.zz/portenta_post_install.sh`

---
---

### How to use

#### 1. Basic usage

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

to use EEPROM/LittlFS/FlashStorage_SAMD/FlashStorage_STM32 to save your configuration data.


#### 2. EEPROM info

1. EEPROM_SIZE can be specified from 256 to 4096 bytes for Mega boards.
2. For SAMD21 boards, data is stored in FlashStorage using 256-byte block. For SAMD51 boards, data is stored in FlashStorage using 8-Kbyte block.
3. For SAM DUE boards, data is stored in EEPROM-simulating DueFlashStorage.
4. For Teensy 4.0 boards, EEPROM_SIZE is around 1 Kbytes.
5. For STM32 boards, EEPROM_SIZE presence depends on the selected boards.
5. For nRF52/RP2040 boards, data is stored in LittleFS/InternalFS.

#### 3. To use personalized Config Portal AP SSID, Password and IP Address

```
// Set config portal SSID and Password
  Blynk.setConfigPortal("SAMD-WiFiNINA", "SAMD-WiFiNINAPass");
  // Set config portal IP address
  Blynk.setConfigPortalIP(IPAddress(192, 168, 200, 1));
```

#### 4. To specify STA-mode Static IP address, Gateway, Subnet Mask, DNS server 1 and 2

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
---


### HOWTO Use default Credentials and have them pre-loaded onto Config Portal

See this example and modify as necessary

#### 1. To load [Default Credentials](examples/SAMD_WiFiNINA_WM/Credentials.h)

```cpp
bool LOAD_DEFAULT_CONFIG_DATA = true;
```

#### 2. To use system default to load "blank" when there is no valid Credentials

```cpp
bool LOAD_DEFAULT_CONFIG_DATA = false;
```

#### 3. Example of [Default Credentials](examples/SAMD_WiFiNINA_WM/Credentials.h)

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

//bool LOAD_DEFAULT_CONFIG_DATA = true;
bool LOAD_DEFAULT_CONFIG_DATA = false;

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

### 4. How to add dynamic parameters from sketch

- To add custom parameters, just modify the example below

```cpp
#if USE_BLYNK_WM

//#define USE_DYNAMIC_PARAMETERS      true
// USE_DYNAMIC_PARAMETERS defined in defined.h

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
#### 5. If you don't need to add dynamic parameters

Use the following code snippet in sketch

```cpp
#define USE_DYNAMIC_PARAMETERS     false
```

or

```cpp
/////////////// Start dynamic Credentials ///////////////

MenuItem myMenuItems [] = {};

uint16_t NUM_MENU_ITEMS = 0;
/////// // End dynamic Credentials ///////////

```

#### 6. To use custom HTML Style

```
const char NewCustomsStyle[] /*PROGMEM*/ = "<style>div,input{padding:5px;font-size:1em;}input{width:95%;}body{text-align: center;}\
button{background-color:blue;color:white;line-height:2.4rem;font-size:1.2rem;width:100%;}fieldset{border-radius:0.3rem;margin:0px;}</style>";

...

Blynk.setCustomsStyle(NewCustomsStyle);
```

#### 7. To use custom Head Elements


```
Blynk.setCustomsHeadElement("<style>html{filter: invert(10%);}</style>");
```

#### 8. To use CORS Header

```
Blynk.setCORSHeader("Your Access-Control-Allow-Origin");
```


#### 9. To use and input only one set of WiFi SSID and PWD

#### 9.1 If you need to use and input only one set of WiFi SSID/PWD

```
// Permit input only one set of WiFi SSID/PWD. The other can be "NULL or "blank"
// Default is false (if not defined) => must input 2 sets of SSID/PWD
#define REQUIRE_ONE_SET_SSID_PW       true
```
But it's always advisable to use and input both sets for reliability.
 
#### 9.2 If you need to use both sets of WiFi SSID/PWD

```
// Permit input only one set of WiFi SSID/PWD. The other can be "NULL or "blank"
// Default is false (if not defined) => must input 2 sets of SSID/PWD
#define REQUIRE_ONE_SET_SSID_PW       false
```

#### 10. To enable auto-scan of WiFi networks for selection in Configuration Portal

#### 10.1 Enable auto-scan of WiFi networks for selection in Configuration Portal


```
#define SCAN_WIFI_NETWORKS                  true
```

The manual input of SSIDs is default enabled, so that users can input arbitrary SSID, not only from the scanned list. This is for the sample use-cases in which users can input the known SSIDs of another place, then send the boards to that place. The boards can connect to WiFi without users entering Config Portal to re-configure.

#### 10.2 Disable manually input SSIDs

```
// To disable manually input SSID, only from a scanned SSID lists
#define MANUAL_SSID_INPUT_ALLOWED           false
```

This is for normal use-cases in which users can only select an SSID from a scanned list of SSIDs to avoid typo mistakes and/or security.

#### 10.3 Select maximum number of SSIDs in the list

The maximum number of SSIDs in the list is seletable from 2 to 15. If invalid number of SSIDs is selected, the default number of 10 will be used.


```
// From 2-15
#define MAX_SSID_IN_LIST                    8
```

---
---

### Why using this [Blynk_WiFiNINA_WM](https://github.com/khoih-prog/Blynk_WiFiNINA_WM) with MultiWiFi-MultiBlynk features

You can see that the system **automatically detects and connects to the available WiFi APs and/or Blynk Servers**, whenever interruption happens. This feature is very useful for systems requiring high degree of reliability.

Moreover, this `Blynk.begin()` is **not a blocking call**, so you can use it for critical functions requiring in loop().

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


### Important Notes for using Dynamic Parameters' ids

1. These ids (such as "mqtt" in example) must be **unique**.

Please be noted that the following **reserved names are already used in library**:

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
7. [UNO_WiFiNINA](examples/UNO_WiFiNINA)
8. [RP2040_WiFiNINA_WM](examples/RP2040_WiFiNINA_WM) **New**

---
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
---

## Example [SAMD_WiFiNINA_WM](examples/SAMD_WiFiNINA_WM)

Please take a look at other examples, as well.

#### 1. File [SAMD_WiFiNINA_WM.ino](examples/SAMD_WiFiNINA_WM/SAMD_WiFiNINA_WM.ino)

```cpp
#include "defines.h"
#include "Credentials.h"
#include "dynamicParams.h"

void heartBeatPrint()
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

  Serial.print("\nStart SAMD_WiFiNINA_WM using WiFiNINA_Shield on ");
  Serial.println(BOARD_NAME);

#if USE_BLYNK_WM
  Serial.println(BLYNK_WIFININA_WM_VERSION);
  Serial.println(DOUBLERESETDETECTOR_GENERIC_VERSION);
  
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
void displayCredentials()
{
  Serial.println("\nYour stored Credentials :");

  for (uint16_t i = 0; i < NUM_MENU_ITEMS; i++)
  {
    Serial.print(myMenuItems[i].displayName);
    Serial.print(F(" = "));
    Serial.println(myMenuItems[i].pdata);
  }
}

void displayCredentialsInLoop()
{
  static bool displayedCredentials = false;

  if (!displayedCredentials)
  {
    for (uint16_t i = 0; i < NUM_MENU_ITEMS; i++)
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
}
#endif

void loop()
{
  Blynk.run();
  check_status();

#if (USE_BLYNK_WM && USE_DYNAMIC_PARAMETERS)
  displayCredentialsInLoop();
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
#define _WIFININA_LOGLEVEL_       3

#if    ( defined(ARDUINO_SAMD_ZERO) || defined(ARDUINO_SAMD_MKR1000) || defined(ARDUINO_SAMD_MKRWIFI1010) \
      || defined(ARDUINO_SAMD_NANO_33_IOT) || defined(ARDUINO_SAMD_MKRFox1200) || defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310) \
      || defined(ARDUINO_SAMD_MKRGSM1400) || defined(ARDUINO_SAMD_MKRNB1500) || defined(ARDUINO_SAMD_MKRVIDOR4000) || defined(__SAMD21G18A__) \
      || defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS) || defined(__SAMD21E18A__) || defined(__SAMD51__) || defined(__SAMD51J20A__) || defined(__SAMD51J19A__) \
      || defined(__SAMD51G19A__) || defined(__SAMD21G18A__) )
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
  #elif defined(ADAFRUIT_ITSYBITSY_M4_EXPRESS)
    #define BOARD_TYPE      "SAMD ADAFRUIT_ITSYBITSY_M4_EXPRESS"
  #elif defined(__SAMD21E18A__)
    #define BOARD_TYPE      "SAMD21E18A"
  #elif defined(__SAMD21G18A__)
    #define BOARD_TYPE      "SAMD21G18A"
  #elif defined(__SAMD51G19A__)
    #define BOARD_TYPE      "SAMD51G19A"
  #elif defined(__SAMD51J19A__)
    #define BOARD_TYPE      "SAMD51J19A"
  #elif defined(__SAMD51J20A__)
    #define BOARD_TYPE      "SAMD51J20A"
  #elif defined(__SAM3X8E__)
    #define BOARD_TYPE      "SAM3X8E"
  #elif defined(__CPU_ARC__)
    #define BOARD_TYPE      "CPU_ARC"
  #elif defined(__SAMD51__)
    #define BOARD_TYPE      "SAMD51"
  #else
    #define BOARD_TYPE      "SAMD Unknown"
  #endif

#endif

#if !defined(BOARD_NAME)
  #define BOARD_NAME    BOARD_TYPE
#endif

// Start location in EEPROM to store config data. Default 0
// Config data Size currently is 128 bytes)
#define EEPROM_START      0
#define EEPROM_SIZE       (2 * 1024)

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

//bool LOAD_DEFAULT_CONFIG_DATA = true;
bool LOAD_DEFAULT_CONFIG_DATA = false;

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

//#define USE_DYNAMIC_PARAMETERS      true
// USE_DYNAMIC_PARAMETERS defined in defined.h

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

### Debug Terminal output Samples

#### 1. SAMD_WiFiNINA_WM using WiFiNINA_Shield on SAMD NANO_33_IOT

The following is the sample terminal output when running example [SAMD_WiFiNINA_WM](examples/SAMD_WiFiNINA_WM)


#### 1.1 No Config Data without LOAD_DEFAULT_CONFIG_DATA => Config Portal

No Config Data with **LOAD_DEFAULT_CONFIG_DATA = true** => Config Portal loads default Credentials and dynamic Params

```
Start SAMD_WiFiNINA_WM using WiFiNINA_Shield on SAMD_NANO_33_IOT
Blynk_WiFiNINA_WM v1.1.2
DoubleResetDetector_Generic v1.7.2
Start Blynk_WM
[WN] Hostname=SAMD-WiFiNINA
Flag read = 0xd0d04321
No doubleResetDetected
SetFlag write = 0xd0d01234
[WN] Invalid Stored WiFi Config Data
[WN] bg: isForcedConfigPortal = false
[WN] bg:Stay forever in CP:No ConfigDat
[WN] stConf:SSID=SAMD_NINA_51F485,PW=MySAMD_NINA_51F485,IP=192.168.120.1
F
Your stored Credentials :
MQTT Server = default-mqtt-server
Port = 1883
MQTT UserName = default-mqtt-username
MQTT PWD = default-mqtt-password
Subs Topics = default-mqtt-SubTopic
Pubs Topics = default-mqtt-PubTopic
Stop doubleResetDetecting
ClearFlag write = 0xd0d04321
FFFFFFFFF FFFFFFFFFF FFFFF
Start SAMD_WiFiNINA_WM using WiFiNINA_Shield on 
SAMD_NANO_33_IOT
Blynk_WiFiNINA_WM v1.1.2
DoubleResetDetector_Generic v1.7.2
Start Blynk_WM
[WN] Hostname=SAMD-WiFiNINA
Flag read = 0xffffffff
No doubleResetDetected
SetFlag write = 0xd0d01234
[WN] CCSum=0x16c92,RCSum=0xffffffff
[WN] ChkCrR:CrCCsum=0xaf50,CrRCsum=0xffffffff
[WN] InitCfgFile,sz=376
[WN] SaveEEPROM,Sz=1024,DataSz=0,WCSum=0x16ca
[WN] CrCCSum=0xc30
[WN] bg: isForcedConfigPortal = false
[WN] bg:Stay forever in CP:No ConfigDat
[WN] stConf:SSID=SAMD_NINA_51F485,PW=MySAMD_NINA_51F485,IP=192.168.120.1
F
Your stored Credentials :
MQTT Server = blank
Port = blank
MQTT UserName = blank
MQTT PWD = blank
Subs Topics = blank
Pubs Topics = blank
Stop doubleResetDetecting
ClearFlag write = 0xd0d04321
FFFF
```

#### 1.2 Input valid Credentials and Save => Exit Config Portal

Input valid credentials with **LOAD_DEFAULT_CONFIG_DATA = true** => reboot


```
Start SAMD_WiFiNINA_WM using WiFiNINA_Shield on SAMD_NANO_33_IOT
Blynk_WiFiNINA_WM v1.1.2
DoubleResetDetector_Generic v1.7.2
Start Blynk_WM
[WN] Hostname=SAMD-WiFiNINA
Flag read = 0xd0d04321
No doubleResetDetected
SetFlag write = 0xd0d01234
[WN] CCSum=0x3667,RCSum=0x3667
[WN] ChkCrR:pdata=new-mqtt-server,len=34
[WN] ChkCrR:pdata=1883,len=6
[WN] ChkCrR:pdata=new-mqtt-username,len=34
[WN] ChkCrR:pdata=new-mqtt-password,len=34
[WN] ChkCrR:pdata=new-mqtt-SubTopic,len=34
[WN] ChkCrR:pdata=new-mqtt-PubTopic,len=34
[WN] ChkCrR:CrCCsum=0x219f,CrRCsum=0x219f
[WN] CrCCSum=219f,CrRCSum=219f
[WN] Valid Stored Dynamic Data
[WN] ======= Start Stored Config Data =======
[11384] Hdr=SHD_WiFiNINA,BrdName=SAMD_WiFiNINA
[11384] SSID=HueNet1,PW=password
[11384] SSID1=HueNet2,PW1=password
[11384] Server=account.duckdns.org,Token=token
[11385] Server1=account.ddns.net,Token1=token1
[11385] Port=8080
[11385] ======= End Config Data =======
[WN] i=0,id=mqtt,data=new-mqtt-server
[WN] i=1,id=mqpt,data=1883
[WN] i=2,id=user,data=new-mqtt-username
[WN] i=3,id=mqpw,data=new-mqtt-password
[WN] i=4,id=subs,data=new-mqtt-SubTopic
[WN] i=5,id=pubs,data=new-mqtt-PubTopic
[11386] ======= End Dynamic Data =======
[WN] ConMultiWifi
[WN] First connection, Using index=0
[WN] con2WF:SSID=HueNet1,PW=password
[WN] Remaining retry_time=3
[WN] WOK, lastConnectedIndex=0
[WN] con2WF:OK
[WN] IP=192.168.2.114
[14491] IP = 192.168.2.114, GW = 192.168.2.1, SN = 255.255.255.0
[14492] b:WOK.TryB
[14492] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v1.0.1 on NANO_33_IOT

[14493] Connecting to account.duckdns.org:8080
[14661] Ready (ping: 11ms).
[14730] Con2BlynkServer=account.duckdns.org,Token=token
[14730] b:WBOK
Stop doubleResetDetecting
ClearFlag write = 0xd0d04321
B
Your stored Credentials :
MQTT Server = new-mqtt-server
Port = 1883
MQTT UserName = new-mqtt-username
MQTT PWD = new-mqtt-password
Subs Topics = new-mqtt-SubTopic
Pubs Topics = new-mqtt-PubTopic
BBBBBBBBB BBBBBBBBBB BB

```

#### 1.3 Lost a WiFi and autoconnect to another WiFi AP

Simulate Blynk Server lost => auto(re)connect to the available Blynk Server


```
[21532] IP = 192.168.2.92, GW = 192.168.2.1, SN = 255.255.0.0
[21533] b:WOK.TryB
[21534] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v1.0.1 on NANO_33_IOT

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
        /___/ v1.0.1 on NANO_33_IOT

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
        /___/ v1.0.1 on NANO_33_IOT

[323986] BlynkArduinoClient.connect: Connecting to 192.168.2.112:8080
[338806] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v1.0.1 on NANO_33_IOT

[338808] BlynkArduinoClient.connect: Connecting to account.duckdns.org:8080
[338841] Ready (ping: 6ms).
[338911] Con2BlynkServer=account.duckdns.org,Token=token1
[338911] r:BOK
BBBBBBBBBB BBBBBBBBBB BBBBBBBBBB BBBBBBBBBB
```

#### 1.4 DRD detected and Config Portal is forcefully opened

4. DoubleResetDetector detected => Config Portal is opened even if stored Credentials are valid.

```
Start SAMD_WiFiNINA_WM using WiFiNINA_Shield on SAMD NANO_33_IOT
Blynk_WiFiNINA_WM v1.1.2
DoubleResetDetector_Generic v1.7.2
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

#### 2. RP2040_WiFiNINA_WM using WiFiNINA_Shield on MBED NANO_RP2040_CONNECT

The following is the sample terminal output when running example [SAMD_WiFiNINA_WM](examples/SAMD_WiFiNINA_WM)

#### 2.1 No Config Data without LOAD_DEFAULT_CONFIG_DATA => Config Portal

No Config Data with **LOAD_DEFAULT_CONFIG_DATA = true** => Config Portal loads default Credentials and dynamic Params

```
Start RP2040_WiFiNINA_WM using WiFiNINA_Shield on MBED NANO_RP2040_CONNECT
Blynk_WiFiNINA_WM v1.1.2
DoubleResetDetector_Generic v1.7.2
Start Blynk_WM
[WN] Hostname=nRF52-WiFiNINA
LittleFS size (KB) = 64
LittleFS Mount OK
LittleFS Flag read = 0xd0d04321
Flag read = 0xd0d04321
No doubleResetDetected
Saving DOUBLERESETDETECTOR_FLAG to DRD file : 0xd0d01234
Saving DRD file OK
SetFlag write = 0xd0d01234
[WN] CCSum=0x147c,RCSum=0x0
[WN] CrCCsum=0x228e,CrRCsum=0x2000d83c
[WN] InitCfgFile,sz=376
[WN] bg: isForcedConfigPortal = false
[WN] bg:Stay forever in CP:No ConfigDat
[WN] clearForcedCP
[WN] SaveCPFile 
[WN] OK
[WN] SaveBkUpCPFile 
[WN] OK
[8605] stConf:SSID=RP2040_NINA_51F485,PW=MyRP2040_NINA_51F485,IP=192.168.120.1
F
Your stored Credentials :
MQTT Server = blank
Port = blank
MQTT UserName = blank
MQTT PWD = blank
Subs Topics = blank
Pubs Topics = blank
Stop doubleResetDetecting
Saving to DRD file : 0xd0d04321
Saving DRD file OK
LittleFS Flag read = 0xd0d04321
ClearFlag write = 0xd0d04321
FFFFFFFFF F[111701] h:UpdLittleFS
[112398] h:Rst
```

#### 2.2 Input valid Credentials and Save => Exit Config Portal

Input valid credentials with **LOAD_DEFAULT_CONFIG_DATA = true** => reboot


```
Start RP2040_WiFiNINA_WM using WiFiNINA_Shield on MBED NANO_RP2040_CONNECT
Blynk_WiFiNINA_WM v1.1.2
DoubleResetDetector_Generic v1.7.2
Start Blynk_WM
[WN] Hostname=nRF52-WiFiNINA
LittleFS size (KB) = 64
LittleFS Mount OK
LittleFS Flag read = 0xd0d04321
Flag read = 0xd0d04321
No doubleResetDetected
Saving DOUBLERESETDETECTOR_FLAG to DRD file : 0xd0d01234
Saving DRD file OK
SetFlag write = 0xd0d01234
[WN] CCSum=0x3361,RCSum=0x3361
[WN] CrCCsum=0x219f,CrRCsum=0x219f
[WN] Valid Stored Dynamic Data
[WN] ======= Start Stored Config Data =======
[1236] Hdr=SHD_WiFiNINA,BrdName=SAMD_WiFiNINA
[1236] SSID=HueNet1,PW=password
[1236] SSID1=HueNet,PW1=password
[1237] Server=192.168.2.112,Token=token
[1237] Server1=account.duckdns.org,Token1=token1
[1238] Port=8080
[1238] ======= End Config Data =======
[WN] i=0,id=mqtt,data=new-mqtt-server
[WN] i=1,id=mqpt,data=1883
[WN] i=2,id=user,data=new-mqtt-username
[WN] i=3,id=mqpw,data=new-mqtt-password
[WN] i=4,id=subs,data=new-mqtt-SubTopic
[WN] i=5,id=pubs,data=new-mqtt-PubTopic
[1241] ======= End Dynamic Data =======
[WN] con2WF:SSID=HueNet1,PW=password
[WN] con2WF:OK
[WN] IP=192.168.2.153
[4819] IP = 192.168.2.153, GW = 192.168.2.1, SN = 255.255.255.0
[4822] b:WOK.TryB
[4823] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on MBED NANO_RP2040_CONNECT

[4824] BlynkArduinoClient.connect: Connecting to 192.168.2.112:8080
[4854] Ready (ping: 17ms).
[4924] Con2BlynkServer=192.168.2.112,Token=token
[4924] b:WBOK
B
Your stored Credentials :
MQTT Server = new-mqtt-server
Port = 1883
MQTT UserName = new-mqtt-username
MQTT PWD = new-mqtt-password
Subs Topics = new-mqtt-SubTopic
Pubs Topics = new-mqtt-PubTopic
Stop doubleResetDetecting
Saving to DRD file : 0xd0d04321
Saving DRD file OK
LittleFS Flag read = 0xd0d04321
ClearFlag write = 0xd0d04321
BB
```

---
---

#### Debug

Debug is enabled by default on Serial. To disable, add at the beginning of sketch

```cpp
/* Comment this out to disable prints and save space */
/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#define DEBUG_WIFI_WEBSERVER_PORT Serial
#define WIFININA_DEBUG_OUTPUT     Serial

#define DRD_GENERIC_DEBUG         true
#define WIFININA_DEBUG            true
#define BLYNK_WM_DEBUG            3
#define _WIFININA_LOGLEVEL_       3
```

---

## Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of the board's core, `WiFiNINA_Generic, DoubleResetDetector_Generic, WiFiWebServer, etc.)` libraries or this library version.

Sometimes, the library will only work if you update the boatd's core to the newer or older version because some function compatibility.

---
---


### Issues

Submit issues to: [Blynk_WiFiNINA_WM issues](https://github.com/khoih-prog/Blynk_WiFiNINA_WM/issues)

---
---

## TO DO

 1. Same features for other boards.
 2. Bug finding and exterminating.

---

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
15. Permit to input special chars such as **%** and **#** into data fields.
16. Add Dynamic Parameters with checksum
17. Default Credentials and dynamic parameters
18. DoubleDetectDetector to force Config Portal when double reset is detected within predetermined time, default 10s.
19. Configurable Config Portal Title
20. Re-structure all examples to separate Credentials / Defines / Dynamic Params / Code so that you can change Credentials / Dynamic Params quickly for each device.
21. Configurable **Customs HTML Headers**, including Customs Style, Customs Head Elements, CORS Header
22. Add functions to control Config Portal from software or Virtual Switches.
23. Permit optionally inputting one set of WiFi SSID/PWD by using `REQUIRE_ONE_SET_SSID_PW == true`
24. Enforce WiFi Password minimum length of 8 chars
25. Enable **scan of WiFi networks** for selection in Configuration Portal
26. Add support to **Arduino Nano RP2040 Connect** using [**Arduino mbed OS for Nano boards**](https://github.com/arduino/ArduinoCore-mbed).
27. Add support to RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Earle Philhower's arduino-pico** core](https://github.com/earlephilhower/arduino-pico).
28. Add support to RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed)
29. Use more efficient **FlashStorage_STM32**](https://github.com/khoih-prog/FlashStorage_STM32) and [**FlashStorage_SAMD**](https://github.com/khoih-prog/FlashStorage_SAMD) library versions.
30. Add Table of Contents and Version String
31. Add Blynk library Patches for **MBED RP2040-based (Nano_RP2040_Connect, etc.) boards**

---

### Contributions and Thanks

1. Thanks to [brondolin](https://github.com/brondolin) to provide the amazing fix to permit input special chars such as **%** and **#** into data fields.
2. Thanks to [Miguel Wisintainer](https://github.com/tcpipchip) for initiating, inspriring, working with, developing, debugging and testing. Without that, support to nRF52, especially **U-Blox B302 running as nRF52840**, has never been started and finished. See [u-blox nina b](https://github.com/khoih-prog/WiFiNINA_Generic/issues/1)
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


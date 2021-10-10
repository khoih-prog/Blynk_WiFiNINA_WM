## Blynk_WiFiNINA_WM

[![arduino-library-badge](https://www.ardu-badge.com/badge/Blynk_WiFiNINA_WM.svg?)](https://www.ardu-badge.com/Blynk_WiFiNINA_WM)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/Blynk_WiFiNINA_WM.svg)](https://github.com/khoih-prog/Blynk_WiFiNINA_WM/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/Blynk_WiFiNINA_WM/blob/master/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/Blynk_WiFiNINA_WM.svg)](http://github.com/khoih-prog/Blynk_WiFiNINA_WM/issues)

--
---

## Table of Contents

* [Changelog](#changelog)
  * [Releases v1.1.2](#releases-v112)
  * [Releases v1.1.1](#releases-v111)
  * [Major Releases v1.1.0](#major-releases-v110)
  * [Releases v1.0.4](#releases-v104)
  * [Major Releases v1.0.3](#major-releases-v103)
  * [Releases v1.0.2](#releases-v102)
  * [Releases v1.0.1](#releases-v101)
  * [Releases v1.0.0](#releases-v100)


---
---

## Changelog

### Releases v1.1.2

1. Update `platform.ini` and `library.json` to use original `khoih-prog` instead of `khoih.prog` after PIO fix
2. Update `Packages' Patches`

### Releases v1.1.1

1. Add Blynk library Patches for **MBED RP2040-based (Nano_RP2040_Connect, etc.) boards**

### Major Releases v1.1.0

 1. Add support to RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Earle Philhower's arduino-pico** v1.6.2+ core](https://github.com/earlephilhower/arduino-pico).
 2. Add support to RP2040-based boards, such as **Nano_RP2040_Connect, RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Arduino-mbed RP2040** v2.1.0+ core](https://github.com/arduino/ArduinoCore-mbed).
 3. Enable scan of WiFi networks for selection in Configuration Portal. Check [PR for v1.3.0 - Enable scan of WiFi networks #10](https://github.com/khoih-prog/WiFiManager_NINA_Lite/pull/10). Now you can select optional **SCAN_WIFI_NETWORKS**, **MANUAL_SSID_INPUT_ALLOWED** to be able to manually input SSID, not only from a scanned SSID lists and **MAX_SSID_IN_LIST** (from 2-6 for ESP8266-AT or 2-15 for other)
 4. Use more efficient [FlashStorage_SAMD v1.1.0](https://github.com/khoih-prog/FlashStorage_SAMD) and [FlashStorage_STM32 v1.0.0](https://github.com/khoih-prog/FlashStorage_STM32)
 5. Add functions to control Config Portal from software or Virtual Switches. Check [How to trigger a Config Portal from code #25](https://github.com/khoih-prog/Blynk_WM/issues/25)
 6. Configurable **Customs HTML Headers**, including Customs Style, Customs Head Elements, CORS Header.
 7. Fix MultiWiFi connection bug. Check [SAMD MultiWiFi issues when first WiFi SSID configured in CP is invalid or not available #6](https://github.com/khoih-prog/WiFiManager_NINA_Lite/issues/6)
 8. Fix invalid "blank" or NULL Config Data treated as Valid. Check [WiFiManager connection attempt to unconfigured ("blank") SSID after restart on SAMD #8](https://github.com/khoih-prog/WiFiManager_NINA_Lite/issues/8)
 9. Permit optionally inputting one set of WiFi SSID/PWD by using `REQUIRE_ONE_SET_SSID_PW == true`
10. Enforce WiFi Password minimum length of 8 chars
11. Enhance MultiWiFi connection logic
12. Minor enhancement to not display garbage when data is invalid
13. Tested with new [Arduino Core for STM32 v2.0.0](https://github.com/stm32duino/Arduino_Core_STM32) and add support to new STM32L5 boards
14. Optimize code. 
15. Update examples
16. Update `Packages' Patches
17. Fix compiler warnings.

### Releases v1.0.4

1. Add support to **Arduino UNO WiFi R2**.

### Major Releases v1.0.3

1. Add support to **nRF52** boards, such as **AdaFruit Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B30_ublox, etc.**
2. **Multiple WiFi Credentials (SSID, Password)** and system will autoconnect to the available WiFi AP. It will then autoreconnect to the remaining WiFi AP if the current connection is lost.
3. **Multiple Blynk Credentials (Server, Token)** and system will autoconnect to the available Blynk Servers.
4. Configurable **Config Portal Title** to be either HostName, BoardName or default undistinguishable names.
5. Optional default **Credentials as well as Dynamic parameters to be optionally autoloaded into Config Portal** to use or change instead of manually input.
6. **DoubleDetectDetector** feature to force Config Portal when double reset is detected within predetermined time, default 10s.
7. Examples are redesigned to separate Credentials / Defines / Dynamic Params / Code so that you can change Credentials / Dynamic Params quickly for each device.
8. Add Board Name

Thanks to [Miguel Wisintainer](https://github.com/tcpipchip) for initiating, inspriring, working with, developing, debugging and testing. Without that, support to nRF52, especially **U-Blox B302 running as nRF52840**, has never been started and finished.

Thanks to [Thor Johnson](https://github.com/thorathome) to test, suggest and encourage to add those new features in [Blynk_WM](https://github.com/khoih-prog/Blynk_WM), such as Default Credentials/Dynamic Params, Configurable Config Portal Title, DRD. Now those features are speading fast into libraries having similar functionalities.

### Releases v1.0.2

1. Add support to **SAM51 (Itsy-Bitsy M4, Metro M4, Grand Central M4, Feather M4 Express, etc.)**.
2. Fix bug

### Releases v1.0.1

1. Add support to **SAM DUE, Teensy (4.0, 3.x, LC), STM32.**
2. AVR Mega can use dynamic parameters or not, depending on memory availability
3. Support 63 chars WPA2 WiFi password
4. Permit to input special chars such as **%** and **#** into data fields. Thanks to [brondolin](https://github.com/brondolin) to provide the amazing fix.

### Releases v1.0.0

1. This release of very-easy-to-use will help you to eliminate hardcoding your Wifi and Blynk credentials for Mega/Teensy boards running WiFiNINA shields, and updating/reflashing every time when you need to change them.
2. Configuration data are stored in configurable location in EEPROM.
3. When WiFi and/or Blynk connection is lost, the WM will try auto-reconnect.
4. `Config Portal Static IP address, Name and Password.`
5. `Static IP address, Gateway, Subnet Mask.`
6. Currently support AVR Mega and SAMD (ZERO, MKR, **NANO_33_IOT**, M0, M0 Pro, AdaFruit CIRCUITPLAYGROUND_EXPRESS, etc.) boards
7. Enhance GUI.

This library is designed to help you eliminate `hardcoding` your Wifi and Blynk credentials for Mega/Teensy boards running WiFiNINA modules/shields, and updating/reflashing every time when you need to change them. Configuration data are saved in configurable location in EEPROM/Flash.

With version `v1.0.0` or later, you now can configure:

1. `Config Portal Static IP address, Name and Password.`
2. `Static IP address, Gateway, Subnet Mask and 2 DNS Servers IP addresses.`




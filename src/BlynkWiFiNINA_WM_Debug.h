/*********************************************************************************************************************************
  WiFiManager_NINA_Lite_Debug.h
  For Mega, Teensy, SAM DUE, SAMD and STM32 boards using WiFiNINA modules/shields

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

  Version: 1.1.2

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
  1.1.1   K Hoang      09/06/2020  Add Blynk library Patches for **MBED RP2040-based (Nano_RP2040_Connect, etc.) boards
  1.1.2   K Hoang      09/06/2020  Update `platform.ini` and `library.json`
  **********************************************************************************************************************************/

#ifndef WiFiManager_NINA_Lite_Debug_h
#define WiFiManager_NINA_Lite_Debug_h

#if !defined(WIFININA_DEBUG)
  #define WIFININA_DEBUG    false
#endif

#ifdef WIFININA_DEBUG_OUTPUT
  #define DBG_PORT_WN       WIFININA_DEBUG_OUTPUT
#else
  #define DBG_PORT_WN       Serial
#endif

// Change _WIFININA_LOGLEVEL_ to set tracing and logging verbosity
// 0: DISABLED: no logging
// 1: ERROR: errors
// 2: WARN: errors and warnings
// 3: INFO: errors, warnings and informational (default)
// 4: DEBUG: errors, warnings, informational and debug

#ifndef _WIFININA_LOGLEVEL_
  #define _WIFININA_LOGLEVEL_       0
#endif

//////////////////////////////////////////

const char WN_MARK[] = "[WN] ";

#define WN_PRINT_MARK   DBG_PORT_WN.print(WN_MARK)

#define WN_PRINT        DBG_PORT_WN.print
#define WN_PRINTLN      DBG_PORT_WN.println

//////////////////////////////////////////

#define WN_LOGERROR0(x)     if(_WIFININA_LOGLEVEL_>0) { WN_PRINT(x); }
#define WN_LOGERROR(x)      if(_WIFININA_LOGLEVEL_>0) { WN_PRINT_MARK; WN_PRINTLN(x); }
#define WN_LOGERROR1(x,y)   if(_WIFININA_LOGLEVEL_>0) { WN_PRINT_MARK; WN_PRINT(x); WN_PRINTLN(y); }
#define WN_LOGERROR2(x,y,z) if(_WIFININA_LOGLEVEL_>0) { WN_PRINT_MARK; WN_PRINT(x); WN_PRINT(y); WN_PRINTLN(z); }
#define WN_LOGERROR3(x,y,z,w) if(_WIFININA_LOGLEVEL_>0) { WN_PRINT_MARK; WN_PRINT(x); WN_PRINT(y); WN_PRINT(z); WN_PRINTLN(w); }
#define WN_LOGERROR5(x,y,z,w,xx,yy) if(_WIFININA_LOGLEVEL_>0) { WN_PRINT_MARK; WN_PRINT(x); WN_PRINT(y); WN_PRINT(z); WN_PRINT(w); WN_PRINT(xx); WN_PRINTLN(yy); }

//////////////////////////////////////////

#define WN_LOGWARN0(x)     if(_WIFININA_LOGLEVEL_>1) { WN_PRINT(x); }
#define WN_LOGWARN(x)      if(_WIFININA_LOGLEVEL_>1) { WN_PRINT_MARK; WN_PRINTLN(x); }
#define WN_LOGWARN1(x,y)   if(_WIFININA_LOGLEVEL_>1) { WN_PRINT_MARK; WN_PRINT(x); WN_PRINTLN(y); }
#define WN_LOGWARN2(x,y,z) if(_WIFININA_LOGLEVEL_>1) { WN_PRINT_MARK; WN_PRINT(x); WN_PRINT(y); WN_PRINTLN(z); }
#define WN_LOGWARN3(x,y,z,w) if(_WIFININA_LOGLEVEL_>1) { WN_PRINT_MARK; WN_PRINT(x); WN_PRINT(y); WN_PRINT(z); WN_PRINTLN(w); }
#define WN_LOGWARN5(x,y,z,w,xx,yy) if(_WIFININA_LOGLEVEL_>1) { WN_PRINT_MARK; WN_PRINT(x); WN_PRINT(y); WN_PRINT(z); WN_PRINT(w); WN_PRINT(xx); WN_PRINTLN(yy); }

//////////////////////////////////////////

#define WN_LOGINFO0(x)     if(_WIFININA_LOGLEVEL_>2) { WN_PRINT(x); }
#define WN_LOGINFO(x)      if(_WIFININA_LOGLEVEL_>2) { WN_PRINT_MARK; WN_PRINTLN(x); }
#define WN_LOGINFO1(x,y)   if(_WIFININA_LOGLEVEL_>2) { WN_PRINT_MARK; WN_PRINT(x); WN_PRINTLN(y); }
#define WN_LOGINFO2(x,y,z) if(_WIFININA_LOGLEVEL_>3) { WN_PRINT_MARK; WN_PRINT(x); WN_PRINT(y); WN_PRINTLN(z); }
#define WN_LOGINFO3(x,y,z,w) if(_WIFININA_LOGLEVEL_>3) { WN_PRINT_MARK; WN_PRINT(x); WN_PRINT(y); WN_PRINT(z); WN_PRINTLN(w); }
#define WN_LOGINFO5(x,y,z,w,xx,yy) if(_WIFININA_LOGLEVEL_>2) { WN_PRINT_MARK; WN_PRINT(x); WN_PRINT(y); WN_PRINT(z); WN_PRINT(w); WN_PRINT(xx); WN_PRINTLN(yy); }

//////////////////////////////////////////

#define WN_LOGDEBUG0(x)     if(_WIFININA_LOGLEVEL_>3) { WN_PRINT(x); }
#define WN_LOGDEBUG(x)      if(_WIFININA_LOGLEVEL_>3) { WN_PRINT_MARK; WN_PRINTLN(x); }
#define WN_LOGDEBUG1(x,y)   if(_WIFININA_LOGLEVEL_>3) { WN_PRINT_MARK; WN_PRINT(x); WN_PRINTLN(y); }
#define WN_LOGDEBUG2(x,y,z) if(_WIFININA_LOGLEVEL_>3) { WN_PRINT_MARK; WN_PRINT(x); WN_PRINT(y); WN_PRINTLN(z); }
#define WN_LOGDEBUG3(x,y,z,w) if(_WIFININA_LOGLEVEL_>3) { WN_PRINT_MARK; WN_PRINT(x); WN_PRINT(y); WN_PRINT(z); WN_PRINTLN(w); }
#define WN_LOGDEBUG5(x,y,z,w,xx,yy) if(_WIFININA_LOGLEVEL_>3) { WN_PRINT_MARK; WN_PRINT(x); WN_PRINT(y); WN_PRINT(z); WN_PRINT(w); WN_PRINT(xx); WN_PRINTLN(yy); }

//////////////////////////////////////////

#endif    //WiFiManager_NINA_Lite_Debug_h

/****************************************************************************************************************************
  SAMD_WiFiNINA_WM.ino
  For SAMD using WiFiNINA Shield/Module

  Blynk_WiFiNINA_WM is a library for the Mega, Teensy, SAM DUE, nRF52, STM32, SAMD and RP2040 boards 
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

/****************************************************************************************************************************
  UNO_WiFiNINA.ino
  For AVR UNO WiFi Rev2 boards using WiFiNINA Shields

  For AVR Mega boards using WiFiNINA Shields

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
// To install WiFiNINA_Generic library (https://github.com/khoih-prog/WiFiNINA_Generic)
// and Blynk_WiFiNINA_WM  (https://github.com/khoih-prog/Blynk_WiFiNINA_WM)

#include <BlynkSimpleWiFiNINA_UNO_WiFi.h>

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

  Serial.println("\nStart UNO_WiFiNINA using WiFiNINA_Shield on UNO WiFi");

#if USE_LOCAL_SERVER
  Blynk.begin(auth, ssid, pass, BlynkServer.c_str(), BLYNK_SERVER_HARDWARE_PORT);
#else
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
  Blynk.begin(auth, ssid, pass);
#endif
}

void loop()
{
  Blynk.run();
  check_status();
}


//***************************************************************************
//* 
//* Projekt Name		: ESP32FwMinOTA  
//* Haupt-Titel	    : 
//* Unter-Titel	    :  
//* Datei Name		  : "ESP32FwMinOTA.ino" 
//* Init-Datum      : 15.04.2026
//* Version         : 00.02.00
//* Github      	  : "TI650/ESP32FwMinOTA"
//* Support Fax		  : 
//* Support Mobil	  :
//* Support eMail	  : 
//* 
//* -------------------------------------------------------------------------
//* 
//* IDE             : ARDUINO / Visual Sudio Code / Github
//* Compiler        : 
//* Target MCU		  : ESP32 (ESP8266=prüfen)
//*           		     
//* -------------------------------------------------------------------------
//*
//*
//* Beschreibung:
//* -------------
//* Minimal Firmware für ESP32 zur Realisierung OTA-Updates
//* =======================
//* - 
//* - 
//* - 
//*     
//*     
//*    
//*
//* ToDo´s:
//* -------------
//* - Funktionsprüfung auf ESP8266 Platformen
//* - WiFi Station Mode
//* - Telnet Funktion Port 23
//* - MQTT Client
//* - WiFi Station Mode

//*
//***************************************************************************
//
// --------------------------------------------------------------------------
// System-Const
// --------------------------------------------------------------------------
//

/*
//#define DESTINATION_HOME   // Produktivsystem = DEFAULT
//#define DESTINATION_TI650  // Testsystem im Wohnmobil
#define DESTINATION_N465   // Testsystem im Wohnwagen
// ---
#define ESP32NODEMCU30P   // Target-Board = NodeMCU ESP32 - 30Pin Version 
//#define WEMOSD1MINI       // Target-Board = Wemos D1 Mini (ESP8266)
//#define KC868A16V31       // Target-Board = Kincony KC868-A16 V3.1 (ESP32)
//#define KC868A6V14        // Target-Board = Kincony KC868-A6  V1.4 (ESP32)
// --- 
*/

// !!!! VERY IMPORTANT TO EDIT THE CONFIG FILE !!!! 
// *** Include Basic Configuration like: Destinatio, Platform, Credicals, HW Rates etc
// *** Select the System-Destination --> in Config.h
// *** Select the Target Board --> in Config.h
#include "Config.h"


//
// --------------------------------------------------------------------------
// HW-Const
// --------------------------------------------------------------------------
//

//
// --------------------------------------------------------------------------
// INCLUDES
// --------------------------------------------------------------------------
//
// #include <string.h>
// #include <Wire.h>              // Lib for IIC
#include <WiFi.h>
#include <NetworkClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <HTTPUpdateServer.h>
//#include <NTPClient.h>
//#include <WiFiUdp.h>
// #include <PubSubClient.h>      // Lib for IIC


// --------------------------------------------------------------------------
// HARDWARE-DEFINES
// --------------------------------------------------------------------------

#ifdef IIC_SSD1306
  // --- BEGIN Definitions for LCD SSD1306
  #include <U8g2lib.h>  // Include the U8g2 library for controlling the OLED display
  #include <Wire.h>     // Include the Wire library for I2C communication
  // Initialize the display using the software I2C method (SCL = IO18, SDA = IO8)
  U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0,  IIC_SCL, IIC_SDA, U8X8_PIN_NONE);  // Screen rotation: U8G2_R0
#endif
// --------------------------------------------------------------------------
// SOFTWARE-DEFINES
// --------------------------------------------------------------------------

// - Test Speed Evaluation (TSP)
unsigned long vTSE_CyclesPerSec = 0;
// --

// - Time relayted function in Loop()
unsigned long previousMillis = 0;
const long interval = 1000; // Blink every 1000ms if BuildIn-LED available
// --

// - Network and OTA Server
const char *host      = STA_HOSTNAME;
const char *ssid      = STA_SSID;
const char *password  = STA_PSK;
WebServer httpServer(80);
HTTPUpdateServer httpUpdater;
// --

// --------------------------------------------------------------------------
// DEBUG-DEFINES
// --------------------------------------------------------------------------


// --------------------------------------------------------------------------
// SYSTEM-DEFINES
// --------------------------------------------------------------------------


// --------------------------------------------------------------------------
// Forward Declaration for SUB and Func
// --------------------------------------------------------------------------
// BASICS      - SUB-Routines and Functions
// APPLICATION - SUB-Routines and Functions



// **************************************************************************
// **************************************************************************
// --------------------------------------------------------------------------
// SUB-Routines and Functions
// --------------------------------------------------------------------------
//

#ifdef IIC_SSD1306
void page1() {    // Function to display page 1 content
  unsigned long vSysSec = millis() /1000;
  uint8_t vStd = vSysSec / 3600;
  vSysSec %= 3600;
  uint8_t vMin = vSysSec / 60;
  vSysSec %= 60;
  uint8_t vSec = vSysSec;

  IPAddress ipa = WiFi.localIP();
  uint8_t IP_array[4] = {ipa[0],ipa[1],ipa[2],ipa[3]};
  
  // Ausgabe per firstpage / nextpage
  u8g2.firstPage();                     // Prepare the first page for drawing
  u8g2.setFontPosTop();                 // Set the text position at the top of the display
  u8g2.setFont(u8g2_font_timB10_tf);    // Use the Times Roman font, Bold, size 10
  u8g2.setCursor( 0, 0);                // Position the cursor at coordinates (x, y)
  u8g2.print(STA_HOSTNAME);             // Display the text on the screen
  u8g2.drawLine( 0, 15, 90, 15);

  u8g2.setFont(u8g2_font_timR08_tf);    // Use the Times Roman font, size 8
  u8g2.setCursor(99, 0);  u8g2.printf("%02d:%02d", vMin, vSec);     
  u8g2.setCursor(99, 8);  u8g2.printf("c:%04d", vTSE_CyclesPerSec);   
 
  u8g2.setCursor( 0,16);  u8g2.printf("ssid: %s", WiFi.SSID());     
  u8g2.setCursor( 0,26);  u8g2.printf("ip:     %03d.%03d.%03d.%03d", ipa[0],ipa[1],ipa[2],ipa[3]);
  u8g2.setCursor( 0,36);  u8g2.printf("ota:   %03d.%03d.%03d.%03d/update", ipa[0],ipa[1],ipa[2],ipa[3]);
  u8g2.setCursor( 0,46);  u8g2.printf("Intf: IIC, ..."); 
//  u8g2.setCursor( 0,46);  u8g2.printf("Intf: IIC,NTP, Telnet, MQTT, SD, IIC, OW..."); 

  u8g2.setCursor( 0,56);  u8g2.printf("Cycle/s:%04d", vTSE_CyclesPerSec);   
  u8g2.setCursor(85,56);  u8g2.printf("%03d:%02d:%02d", vStd, vMin, vSec);     
   
  u8g2.nextPage();  // Continue to the next page until all pages are drawn

/*   
  // Ausgabe per Buffer
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB12_tr);
  u8g2.drawStr(10,20,"LCD");      
  u8g2.drawStr(10,40,"initialisiert");          
  u8g2.sendBuffer();    
*/


}
#endif


void page2() {

  Serial.printf("Speedtest Cycles/s: %lu \n", vTSE_CyclesPerSec);

#ifdef BUILDIN_LED
  digitalWrite(BUILDIN_LED_PIN, !digitalRead(BUILDIN_LED_PIN)); // Schaltet LED um
#endif

}


// --------------------------------------------------------------------------
// BASIC SUB-Routines and Functions
// --------------------------------------------------------------------------
//

//
// --------------------------------------------------------------------------
//

//
// --------------------------------------------------------------------------
// **************************************************************************/
// --------------------------------------------------------------------------
//  V O I D   S E T U P ( )
// --------------------------------------------------------------------------
//
void setup(){

  //Serial.begin(UART_BAUD_RATE);
  Serial.begin(115200);
  Serial.println(F(CHARSET_HEADLINE_ASTERIX));
  Serial.println(F("SYSTEM BOOT"));
  Serial.println(F(CHARSET_HEADLINE_ASTERIX));
  Serial.println(F("Main HW/SW Boot:"));

  // ---
  Serial.printf("+ SERIAL0: ");
  Serial.printf("  BAUD: %i ", UART_BAUD_RATE);
  Serial.printf("  --> done \n");
  // ---
  Serial.printf("+ WIFI: \n");
  Serial.printf("  Hostname: %s ", STA_HOSTNAME);
//  Serial.printf("  Connecting to: %s \n", STA_SSID);
  Serial.printf("  Mode: %i \n", WIFI_AP_STA);
  WiFi.mode(WIFI_AP_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    WiFi.begin(ssid, password);
    Serial.print("   > WiFi failed, retrying. \n");
  }
  Serial.printf("  Connected to: ");  Serial.println(WiFi.SSID());
  Serial.printf("  IP Address  : ");  Serial.println(WiFi.localIP());
  Serial.printf("  MAC Adress  : ");  Serial.println(WiFi.macAddress());
  Serial.printf("  --> done \n");
 
  // --- mDNS - Namensauflösung für Update-Funktion
  Serial.printf("+ mDNS: ");
  if (MDNS.begin(host)) {
    Serial.printf("  Responder started ");
  }
  Serial.printf("  --> done \n");
  Serial.printf(" +HTTP: \n");
  httpUpdater.setup(&httpServer);
  httpServer.begin();
  Serial.printf("  HTTP-Server: --> done \n");
  MDNS.addService("http", "tcp", 80);
  Serial.printf("  mDNS Updated: --> done \n");
  Serial.printf("  --> HTTPUpdateServer ready! Open http://%s.local/update in your browser\n", host);
 
  // ---
 
 #ifdef IIC_SSD1306
  // Set the I2C address for the display to 0x3C
  u8g2.setI2CAddress(IIC_SSD1306_addr*2); // (0x3C*2);  // I2C address shift for 8-bit format
 // Initialize the display
  u8g2.begin();
 // Enable UTF-8 character printing for the display
  u8g2.enableUTF8Print();  // Allow UTF-8 encoded text to be printed
  Serial.println(F("+ Display SSD1306 --> done"));
#endif

  Serial.println(F("SYSTEM BOOT --> succesfull done"));
  Serial.println(F(CHARSET_HEADLINE_ASTERIX));

  // - Functionalities
#ifdef BUILDIN_LED
  pinMode(BUILDIN_LED_PIN, OUTPUT);
#endif

  //
}


//
// --------------------------------------------------------------------------
// **************************************************************************/
// --------------------------------------------------------------------------
//  V O I D   L O O P ( )
// --------------------------------------------------------------------------
//
void loop()
{

  ///// Begin of time controlled routine
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval)   {
    previousMillis = currentMillis; // Save the last time
 
#ifdef IIC_SSD1306
    page1();// Call the page1() function to draw content on the display
#endif
    page2();

    vTSE_CyclesPerSec = 0;
     
  }
  ///// Begin of time controlled routine

  vTSE_CyclesPerSec = vTSE_CyclesPerSec + 1;

  httpServer.handleClient();

}

//
// --------------------------------------------------------------------------
// **************************************************************************/


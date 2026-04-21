
//***************************************************************************
// EDITED:
// 16.04.2026 All : Just Formating, No Changes
// 19.04.2026 All : Versionsinformationen angepasst
// 
//***************************************************************************

//***************************************************************************
// ** PROJECT - DEFINITIONS **
//***************************************************************************

// --------------------------------------------------------------------------
// ** Selection of: Destination (Network) / Target Board (Platform) **
// ------
// *** Select the System-Destination - uncomment all others!!
//     - Relay to Config_NET.h
#define DESTINATION_HOME   // Produktivsystem = DEFAULT
//#define DESTINATION_TI650  // Testsystem im Wohnmobil
//#define DESTINATION_N465   // Testsystem im Wohnwagen
// ---
// *** Select the Target Board - uncomment all others!!
//     - Relay to Config_HW.h
#define ESP32NODEMCU30P   // Target-Board = NodeMCU ESP32 - 30Pin Version 
//#define WEMOSD1MINI       // Target-Board = Wemos D1 Mini (ESP8266)
//#define KC868A16V31       // Target-Board = Kincony KC868-A16 V3.1 (ESP32)
//#define KC868A6V14        // Target-Board = Kincony KC868-A6  V1.4 (ESP32)
// --- 

// --------------------------------------------------------------------------
// ** PROJECT VERSION **
// ------
// Set Version Data
// --------------------------------------------------------------------------
#define VERS_MAJOR       0
#define VERS_MINOR       2
#define VERS_PATCH       0
#define VERS_COMPILEDATE "20260419"

// --------------------------------------------------------------------------
// ** NETWORK **
// ------
// User defined Network details and creditials should be stored in Config_NET.h.
// In case of no Config_NET.h file update following outlined definitions.
// --------------------------------------------------------------------------
/*
#define STA_SSID        ""
#define STA_PSK         ""
#define STA_HOSTNAME    "SW_Minimal"
#define MQTT_SERVER     ""
#define MQTT_PORT       1883
#define MQTT_USER       ""
#define MQTT_PW         ""
*/
#include "Config_NET.h" // *** Include Network Configuration With Credicals ...

// --------------------------------------------------------------------------
// ** HARDWARE **
// ------
// Include hardware configuration depending of selected target. 
// --------------------------------------------------------------------------
#include "Config_HW.h" // *** Include Hardware Configuration ...

// --------------------------------------------------------------------------
// ...
// ------
// ...
// --------------------------------------------------------------------------
//***************************************************************************
// ** END OF PROJECT - DEFINITIONS **
//***************************************************************************


//***************************************************************************
// ** MAIN DEFINITIONS **
//***************************************************************************

// *** UART / Serial0 / Serial2
#define UART_BAUD_RATE      115200         // 115200 baud 
#define UART_BAUD_RATE2      19200         //  19200 baud 

// *** NTP - Time Server
#define NTP_TIMEOFFSET       3600          // Correction to timezone in sec.

// *** ...

// *** Define Chararrays - Const for Printing
#define CHARSET_HEADLINE_STICH   "------------------------------"
#define CHARSET_HEADLINE_ASTERIX "******************************"
#define CHARSET_TESTLINE         "123456789012345678901234567890"

//***************************************************************************
// ** END OF MAIN DEFINITIONS **
//***************************************************************************

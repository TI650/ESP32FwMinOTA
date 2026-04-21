//***************************************************************************
//
// --------------------------------------------------------------------------
// ChangeLog
// ------
// SW: ESP32FwMinOTA ehemals KC868A16V31_Minimal
// --------------------------------------------------------------------------
// 
// **14.04.2026**  -  **Initial**
// ----------
// 
// **15.04.2026**  -  **First Release**
// ----------
// 
// **16.04.2026**  -  **Second Commit**
// - Software wurde portiert von KC868A16V31_Minimal nach ESP32FwMinOTA
// - KC868A16V31_Minimal wird beendet und gelöscht
// ----------
// 
// **21.04.2026**  -  **Second Release**
// - Config_HW.h angepasst
// - *.ino Speedtest cycles per second eingefügt, Ergebnis per serial
// - *.ino Buildin LED blinkt im 1sec Takt, sofern vorhanden. Siehe "#ifdef BUILDIN_LED"
// - *.ino Display SSD1306 eingefügt, sofern vorhanden. Siehe "#ifdef IIC_SSD1306"
// - *.ino wesentliche Networkdaten auf Display eingefügt
// ----------
// 
// **...04.2026**  -  **...**
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
// --------------------------------------------------------------------------
//
//***************************************************************************

/*
--- Internetseiten:
--- NTPClient
  "https://randomnerdtutorials.com/esp32-ntp-client-date-time-arduino-ide/"
--- Strings zerlegen
  "https://wokwi.com/projects/387981592243403777"
--- LillyGo TTGO T-Display
  "https://done.land/components/microcontroller/families/esp/esp32/developmentboards/esp32s/t-display/"
--- MQTT
  "https://randomnerdtutorials.com/esp32-mqtt-publish-subscribe-arduino-ide/"
	"https://arduinoblog.de/mqtt-mit-esp32/"
	"https://wokwi.com/projects/387432873865029633"
	"https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/protocols/mqtt.html"
--- char / Strings
  "https://wolles-elektronikkiste.de/character-arrays-vs-strings"


	
*/

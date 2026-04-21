//***************************************************************************
// EDITED:
// 15.04.2026 DESTINATION_N465 : DESTINATION_N465 added
//
//***************************************************************************

//***************************************************************************
// --------------------------------------------------------------------------
// Netzwerkdefinitionen
// ------
//   - Festlegungen für das Netzwerk in dem das System laufen soll
// --------------------------------------------------------------------------
// ---
#ifdef DESTINATION_HOME  // Produktivsystem
  #warning "DESTINATION_HOME"

  #define STA_SSID        "AMK-HOME"
  #define STA_PSK         "0107196207021962"
  #define STA_HOSTNAME    "ESP32-FwMin"

  #define MQTT_SERVER     "192.168.101.200"
  #define MQTT_PORT       1884
  #define MQTT_USER       "DVES_USER"
  #define MQTT_PW         "12345"
#endif//
#ifdef DESTINATION_TI650  // Testsystem im Wohnmobil
  #warning "DESTINATION_TI650"

  #define STA_SSID        "TI650_RUT"
  #define STA_PSK         "0107196207021962"
  #define STA_HOSTNAME    "ESP32-FwMin"

  #define MQTT_SERVER     "192.168.102.20"
  #define MQTT_PORT       1883
  #define MQTT_USER       "root"
  #define MQTT_PW         "Caspar123#"
#endif
// ---
#ifdef DESTINATION_N465  // Testsystem im Wohnwagen
  #warning "DESTINATION_N465"

  #define STA_SSID        "MK703_RUT950"
  #define STA_PSK         "0107196207021962"
  #define STA_HOSTNAME    "ESP32-FwMin"

  #define MQTT_SERVER     "192.168.100.20"
  #define MQTT_PORT       1883
  #define MQTT_USER       "root"
  #define MQTT_PW         "Caspar123#"
#endif

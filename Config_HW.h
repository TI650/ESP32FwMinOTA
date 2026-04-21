//***************************************************************************
// EDITED:
// 16.04.2026 ESP32NODEMCU30P : OneWirePin added
// 17.04.2026 ESP32NODEMCU30P : Global Info --> Has Build-In-LED
//            WEMOSD1MINI     : Global Info --> Has Build-In-LED
//            ESP32NODEMCU30P : Global Info --> Has Display SSD1306
//            KC868A16V31     : Global Info --> Has Display SSD1306
//            KC868A6V14      : Global Info --> Has Display SSD1306
// 20.04.2026 ESP32NODEMCU30P : Boardauswahl für Arduino ergänzt
//***************************************************************************

//***************************************************************************
// --------------------------------------------------------------------------
// Targetdefinitionen
// ------
//   - Pin und Port Definitionen
// --------------------------------------------------------------------------
//
#ifdef ESP32NODEMCU30P   // Target-Board = NodeMCU ESP32 - 30Pin Version 
  // Board in Arduino: ESP32-WROOM-DA Module  --> (ESP-WROOM-32)  [ESP32-D0WDQ6 (revision v1.0)]
  // Board in Arduino: NodeMCU-32S            --> (ESP-32D)       [ESP32-D0WD-V3 (revision v3.1)]
  // Board in Arduino: ESP32 Dev Module       --> (ESP-32D)       [ESP32-D0WD-V3 (revision v3.1)]
  // Build-In-LED
  #define BUILDIN_LED             // Global Info --> Has Build-In-LED
  #define BUILDIN_LED_PIN      2  // built-in LED-Pin
  #define BUILDIN_LED_ON       1  // Value for LED = ON
  #define BUILDIN_LED_OFF      0  // Value for LED = Off
  // Serial Port 0
  // -- by Libary default config
  // Serial Port 2
  #define RX2                 16  // GPIO_16
  #define TX2                 17  // GPIO_17
  // I2C - Serial Data Interface
  #define IIC_SDA             21  // GPIO_21
  #define IIC_SCL             22  // GPIO_22
  #define IIC_SSD1306             // Global Info --> Has Display SSD1306
  #define IIC_SSD1306_addr  0x3c  // SSD1306 display: i2c address:0x3c
  // One-Wire (pull-up resistance needed):
  #define OneWire1            27  // GPIO_27
  // SPI - Serial Data Interface for SD-Card
  #define SD_SCK              18  // GPIO_18
  #define SD_MISO             19  // GPIO_19
  #define SD_MOSI             23  // GPIO_23
  #define SD_CS                5  // GPIO_05


#endif
// ---
#ifdef WEMOSD1MINI       // Target-Board = Wemos D1 Mini (ESP8266) 
  // Board in Arduino: LOLIN(WEMOS) D1 R2 & mini--> ??
  // Build-In-LED
  #define BUILDIN_LED             // Global Info --> Has Build-In-LED
  #define BUILDIN_LED_PIN      2  // built-in LED-Pin
  #define BUILDIN_LED_ON       0  // Value for LED = ON
  #define BUILDIN_LED_OFF      1  // Value for LED = Off

#endif
// ---
#ifdef KC868A16V31       // Target-Board = Kincony KC868-A16 V3.1 (ESP32) 
  // Board in Arduino: ESP32-S3-Box  --> OK
  // Analog Eingänge
  #define ANALOG_A1            4  // GPIO_04
  #define ANALOG_A2            6  // GPIO_06
  #define ANALOG_A3            7  // GPIO_07
  #define ANALOG_A4            5  // GPIO_05
  // I2C - Serial Data Interface
  #define IIC_SDA              9  // GPIO_09
  #define IIC_SCL             10  // GPIO_10
  #define IIC_InputA_addr   0x21
  #define IIC_InputB_addr   0x22
  #define IIC_RelayA_addr   0x24
  #define IIC_RelayB_addr   0x25
  #define IIC_EEPROM_addr   0x50  // 24C02  EEPROM i2c address: 0x50
  #define IIC_RTC_addr      0x68  // DS3231 RTC i2c address: 0x68
  #define IIC_SSD1306             // Global Info --> Has Display SSD1306
  #define IIC_SSD1306_addr  0x3c  // SSD1306 display: i2c address:0x3c
  // One-Wire (pull-up resistance on PCB):
  #define OneWire1            47  // GPIO_47
  #define OneWire2            48  // GPIO_48
  #define OneWire3            38  // GPIO_38
  // SPI for Ethernet (W5500) I/O define:
  #define ETH_SCK             42  // GPIO_42
  #define ETH_MOSI            43  // GPIO_43
  #define ETH_MISO            44  // GPIO_44
  #define ETH_CS              15  // GPIO_15
  // RS485 
  #define RS485RX             17  // GPIO_17
  #define RS485TX             16  // GPIO_16
  // SPI for SD Card
  #define SD_MOSI             12  // GPIO_12
  #define SD_SCK              13  // GPIO_13
  #define SD_MISO             14  // GPIO_14
  #define SD_CS               11  // GPIO_11
  #define SD_CD               21  // GPIO_21
  // RF433MHz wireless
  #define RF433MHzRX           8  // GPIO_08
  #define RF433MHzTX          18  // GPIO_18
  // Systemfunctions Pins
  #define INT_PIN              2  // GPIO_02
  #define RESET_PIN            1  // GPIO_01
/*
free GPIOs (without pull-up resistance on PCB):
free gpio-1:GPIO39
free gpio-2:GPIO40
free gpio-3:GPIO41
-----------------
free gpio on PCB (beside ESP32-S3 module)
GPIO39
GPIO40
GPIO41
*/
#endif
// ---
#ifdef KC868A6V14        // Target-Board = Kincony KC868-A6  V1.4 (ESP32)
  // I2C - Serial Data Interface
  #define IIC_SDA              4  // GPIO_04
  #define IIC_SCL             15  // GPIO_15
  #define IIC_SSD1306             // Global Info --> Has Display SSD1306
  #define IIC_SSD1306_addr  0x3c  // SSD1306 display: i2c address:0x3c

#endif

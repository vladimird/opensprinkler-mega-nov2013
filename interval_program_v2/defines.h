// Arduino library code for OpenSprinkler Generation 2

/* Macro definitions and Arduino pin assignments
 Creative Commons Attribution-ShareAlike 3.0 license
 Apr 2013 @ Rayshobby.net
 */

#ifndef _Defines_h
#define _Defines_h

// Firmware version
#define SVC_FW_VERSION  200 // firmware version (e.g. 2.0.0 etc)
// if this number is different from stored in EEPROM,
// an EEPROM reset will be automatically triggered

#define MAX_EXT_BOARDS    5 // maximum number of ext. boards (each expands 8 stations)
// total number of stations: (1+MAX_EXT_BOARDS) * 8
// increasing this number will consume more memory and EEPROM space

#define STATION_NAME_SIZE 16 // size of each station name, default is 16 letters max

// Internal EEPROM Defines
#define INT_EEPROM_SIZE         2048    // ATmega644 eeprom size
#define ADDR_EEPROM_OPTIONS     0x0000  // address where options are stored, 64 bytes reserved
#define ADDR_EEPROM_PASSWORD    0x0040	// address where password is stored, 16 bytes reserved
#define ADDR_EEPROM_LOCATION    0x0050  // address where location is stored, 32 bytes reserved
#define ADDR_EEPROM_STN_NAMES   0x0070  // address where station names are stored
#define ADDR_EEPROM_RUNONCE     (ADDR_EEPROM_STN_NAMES+(MAX_EXT_BOARDS+1)*8*STATION_NAME_SIZE)
// address where run-once data is stored
#define ADDR_EEPROM_MAS_OP      (ADDR_EEPROM_RUNONCE+(MAX_EXT_BOARDS+1)*8*2)
// address where master operation bits are stored
#define ADDR_EEPROM_USER        (ADDR_EEPROM_MAS_OP+(MAX_EXT_BOARDS+1))
// address where program schedule data is stored

#define DEFAULT_PASSWORD        "admin"
#define DEFAULT_LOCATION        "brisbane+queensland" 
// zip code, city name or any google supported location strings
// IMPORTANT: use , or + in place of space
// So instead of 'New York', use 'New,York' or 'New+York'

// macro define of each option
// See OpenSprinkler.cpp for details on each option
typedef enum {
  OPTION_FW_VERSION = 0,
  OPTION_TIMEZONE,
  OPTION_USE_NTP,
  OPTION_USE_DHCP,
  OPTION_STATIC_IP1,
  OPTION_STATIC_IP2,
  OPTION_STATIC_IP3,
  OPTION_STATIC_IP4,
  OPTION_GATEWAY_IP1,
  OPTION_GATEWAY_IP2,
  OPTION_GATEWAY_IP3,
  OPTION_GATEWAY_IP4,
  OPTION_HTTPPORT_0,
  OPTION_HTTPPORT_1,
  OPTION_NETFAIL_RECONNECT,
  OPTION_EXT_BOARDS,
  OPTION_SEQUENTIAL,
  OPTION_STATION_DELAY_TIME,
  OPTION_MASTER_STATION,
  OPTION_MASTER_ON_ADJ,
  OPTION_MASTER_OFF_ADJ,
  OPTION_USE_RAINSENSOR,
  OPTION_RAINSENSOR_TYPE,
  OPTION_WATER_LEVEL,
  OPTION_SELFTEST_TIME,
  OPTION_IGNORE_PASSWORD,
  OPTION_DEVICE_ID,
  OPTION_LCD_CONTRAST,
  OPTION_LCD_BACKLIGHT,
  OPTION_RESET,
  NUM_OPTIONS	// total number of options
} 
OS_OPTION_t;

// Option Flags
#define OPFLAG_NONE        0x00  // default flag, this option is not editable
#define OPFLAG_SETUP_EDIT  0x01  // this option is editable during startup
#define OPFLAG_WEB_EDIT    0x02  // this option is editable on the Options webpage


// =====================================
// ====== Arduino Pin Assignments ======
// =====================================

// ------ Define hardware version here ------
#define SVC_HW_VERSION 20

#ifndef SVC_HW_VERSION
#error "==This error is intentional==: you must define SVC_HW_VERSION in arduino-xxxx/libraries/OpenSprinklerGen2/defines.h"
#endif

#if SVC_HW_VERSION == 20

#define PIN_RF_DATA       28    // RF data pin 

//===== Shift Register =====//
//#define PIN_SR_LATCH       3    // shift register latch pin
//#define PIN_SR_DATA       21    // shift register data pin
//#define PIN_SR_CLOCK      22    // shift register clock pin
//#define PIN_SR_OE          1    // shift register output enable pin

//===== Digital Outputs =====//  
#define PIN_STN_S1        46      // use these when switching relays
#define PIN_STN_S2        44      // without shift register i.e.
#define PIN_STN_S3        42      // control signal is directly from
#define PIN_STN_S4        40      // arduino digital output pins
#define PIN_STN_S5        47      
#define PIN_STN_S6        45
#define PIN_STN_S7        43
#define PIN_STN_S8        41

// ===== Added for Freetronics LCD Shield =====

#define PIN_LCD_RS         8    // LCD rs pin - default = 19
#define PIN_LCD_EN         9    // LCD enable pin - default = 18
#define PIN_LCD_D4         22  // LCD d4 pin - default = 20
#define PIN_LCD_D5         5    // LCD d5 pin - default = 21
#define PIN_LCD_D6         6    // LCD d6 pin - default = 22
#define PIN_LCD_D7         7    // LCD d7 pin - default = 23
#define PIN_LCD_BACKLIGHT  23    // LCD backlight pin - default = 12
#define PIN_LCD_CONTRAST  36    // LCD contrast pin - default = 13
#define PIN_ETHER_CS      4    // Ethernet controller chip select pin - default = 4
#define PIN_SD_CS         10    // SD card chip select pin - default = 0
#define PIN_RAINSENSOR    39    // rain sensor is connected to pin D3 - default = 11
#define BUTTON_ADC_PIN    A0    // A0 is the button ADC input

/*
  #define PIN_BUTTON_1      31    // button 1
 #define PIN_BUTTON_2      30    // button 2
 #define PIN_BUTTON_3      29    // button 3 
 */
// ADC readings expected for the 5 buttons on the ADC input
#define RIGHT_10BIT_ADC    0    // right
#define UP_10BIT_ADC     145    // up
#define DOWN_10BIT_ADC   329    // down
#define LEFT_10BIT_ADC   505    // left
#define SELECT_10BIT_ADC 741    // select
#define BUTTONHYSTERESIS  10    // hysteresis for valid button sensing window

#define BUTTON_RIGHT              1  // 
#define BUTTON_UP                 2  // 
#define BUTTON_DOWN               3  // 
#define BUTTON_LEFT               4  // 
#define BUTTON_SELECT             5  // 

// ===== Added for Freetronics LCD Shield =====

#endif 

// ====== Button Defines ======
#define BUTTON_1            0x01
#define BUTTON_2            0x02
#define BUTTON_3            0x04

// button status values
#define BUTTON_NONE         0x00  // no button pressed
#define BUTTON_MASK         0x0F  // button status mask
#define BUTTON_FLAG_HOLD    0x80  // long hold flag
#define BUTTON_FLAG_DOWN    0x40  // down flag
#define BUTTON_FLAG_UP      0x20  // up flag

// button timing values
#define BUTTON_DELAY_MS        1  // short delay (milliseconds)
#define BUTTON_HOLD_MS       800  // long hold expiration time (milliseconds)
#define BUTTON_IDLE_TIMEOUT    8  // timeout if no button is pressed within certain number of seconds

// button mode values
#define BUTTON_WAIT_NONE       0  // do not wait, return value immediately
#define BUTTON_WAIT_RELEASE    1  // wait until button is release
#define BUTTON_WAIT_HOLD       2  // wait until button hold time expires

// ====== Timing Defines ======
#define DISPLAY_MSG_MS      2000  // message display time (milliseconds)

// ====== Ethernet Defines ======
#define ETHER_BUFFER_SIZE   1100  // if buffer size is increased, you must check the total RAM consumption
// otherwise it may cause the program to crash

// ===== Added for W5100 and Auto-Reboot =====                                
#define TMP_BUFFER_SIZE      255    // scratch buffer size - default = 48  
#define AUTO_REBOOT          true   // flag to auto reboot the processor every 24 hours
#define REBOOT_HR            12     // hour to perform daily reboot
#define REBOOT_MIN           00     // min  to perform daily reboot
#define REBOOT_SEC           00     // sec  to perform daily reboot

#define SHOW_MEMORY  true           // flag for testing - displays free memory instead of station info

#define STATIC_IP_1  192            // Default IP to be stored in eeprom on first run
#define STATIC_IP_2  168
#define STATIC_IP_3  1
#define STATIC_IP_4  210

#define STATIC_GW_1  192            // Default Gateway to be stored in eeprom on first run
#define STATIC_GW_2  168
#define STATIC_GW_3  1
#define STATIC_GW_4  1

#define STATIC_PORT0  80            // Default Port to be stored in eeprom on first run
#define STATIC_PORT1  0
// ===== Added for W5100 and Auto-Reboot =====

#endif





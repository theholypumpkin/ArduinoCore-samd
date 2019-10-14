/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _VARIANT_GREOVE_UI_M4_WIRELESS
#define _VARIANT_GREOVE_UI_M4_WIRELESS

// The definitions here needs a SAMD core >=1.6.10
#define ARDUINO_SAMD_VARIANT_COMPLIANCE 10610

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

/** Frequency of the board main oscillator */
#define VARIANT_MAINOSC		(32768ul)

/** Master clock frequency */
#define VARIANT_MCK        (F_CPU)

#define VARIANT_GCLK0_FREQ (F_CPU)
#define VARIANT_GCLK1_FREQ (48000000UL)
#define VARIANT_GCLK2_FREQ (100000000UL)

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
#include "SERCOM.h"
#include "Uart.h"
#endif // __cplusplus

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

// Number of pins defined in PinDescription array
#define PINS_COUNT           (96u)
#define NUM_DIGITAL_PINS     (34u)
#define NUM_ANALOG_INPUTS    (10u)
#define NUM_ANALOG_OUTPUTS   (2u)
#define analogInputToDigitalPin(p)  ((p < 8) ? 67 + (p) : (p < 16) ? 54 + (p) - 8 : (p < 18) ? 12 + (p) - 16 : (p == 18) ? 9 : -1)

#define digitalPinToPort(P)        ( &(PORT->Group[g_APinDescription[P].ulPort]) )
#define digitalPinToBitMask(P)     ( 1 << g_APinDescription[P].ulPin )
//#define analogInPinToBit(P)        ( )
#define portOutputRegister(port)   ( &(port->OUT.reg) )
#define portInputRegister(port)    ( &(port->IN.reg) )
#define portModeRegister(port)     ( &(port->DIR.reg) )
#define digitalPinHasPWM(P)        ( g_APinDescription[P].ulPWMChannel != NOT_ON_PWM || g_APinDescription[P].ulTCChannel != NOT_ON_TIMER )

/*
 * digitalPinToTimer(..) is AVR-specific and is not defined for SAMD
 * architecture. If you need to check if a pin supports PWM you must
 * use digitalPinHasPWM(..).
 *
 * https://github.com/arduino/Arduino/issues/1833
 */
// #define digitalPinToTimer(P)

// LEDs
#define PIN_LED_13           (13u)
#define PIN_LED_RXL          (13u)
#define PIN_LED_TXL          (13u)
#define PIN_LED              PIN_LED_13
#define PIN_LED2             PIN_LED_RXL
#define PIN_LED3             PIN_LED_TXL
#define LED_BUILTIN          PIN_LED_13
#define PIN_NEOPIXEL         (13u)

/*
 * Analog pins
 */
#define PIN_A0               (0ul)
#define PIN_A1               (PIN_A0 + 1)
#define PIN_A2               (PIN_A0 + 2)
#define PIN_A3               (PIN_A0 + 3)
#define PIN_A4               (PIN_A0 + 4)
#define PIN_A5               (PIN_A0 + 5)
#define PIN_A6               (PIN_A0 + 6)
#define PIN_A7               (PIN_A0 + 7)
#define PIN_A8               (PIN_A0 + 8)
#define PIN_A9               (PIN_A0 + 9)

#define PIN_DAC0             (11ul)
#define PIN_DAC1             (12ul)

static const uint8_t A0  = PIN_A0;
static const uint8_t A1  = PIN_A1;
static const uint8_t A2  = PIN_A2;
static const uint8_t A3  = PIN_A3;
static const uint8_t A4  = PIN_A4;
static const uint8_t A5  = PIN_A5;
static const uint8_t A6  = PIN_A6 ;
static const uint8_t A7  = PIN_A7 ;
static const uint8_t A8  = PIN_A8 ;
static const uint8_t A9  = PIN_A9 ;

static const uint8_t DAC0 = PIN_DAC0;
static const uint8_t DAC1 = PIN_DAC1;

#define ADC_RESOLUTION		12

/*
 * USB
 */
#define PIN_USB_HOST_ENABLE (14ul)
#define PIN_USB_DM          (15ul)
#define PIN_USB_DP          (16ul)
/*
 * other digital pin
 */
#define EXT_0    (17ul)
#define EXT_1    (EXT_0 + 1)
#define EXT_2    (EXT_0 + 2)
#define EXT_3    (EXT_0 + 3)
#define EXT_4    (EXT_0 + 4)
#define EXT_5    (EXT_0 + 5)
#define EXT_6    (EXT_0 + 6)
#define EXT_7    (EXT_0 + 7)
#define EXT_8    (EXT_0 + 8)

#define BUTTON_1 EXT_0
#define BUTTON_2 EXT_1
#define BUTTON_3 EXT_2

/*
 * Serial interfaces
 */

// Serial1
#define PIN_SERIAL1_RX       (27ul)
#define PIN_SERIAL1_TX       (26ul)
#define PAD_SERIAL1_RX       (SERCOM_RX_PAD_1)
#define PAD_SERIAL1_TX       (UART_TX_PAD_0)
#define SERCOM_SERIAL1		  sercom1

// Serial2
#define PIN_SERIAL2_RX       (28ul)
#define PIN_SERIAL2_TX       (29ul)
#define PAD_SERIAL2_RX       (SERCOM_RX_PAD_1)
#define PAD_SERIAL2_TX       (UART_TX_PAD_0)
#define SERCOM_SERIAL2		  sercom2

/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 2

#define PIN_WIRE_SDA        (30)
#define PIN_WIRE_SCL        (31)
#define PERIPH_WIRE         sercom3
#define WIRE_IT_HANDLER     SERCOM3_Handler

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

#define PIN_WIRE1_SDA       (32)
#define PIN_WIRE1_SCL       (33)
#define PERIPH_WIRE1        sercom4
#define WIRE1_IT_HANDLER    SERCOM4_Handler

static const uint8_t SDA1 = PIN_WIRE1_SDA;
static const uint8_t SCL1 = PIN_WIRE1_SCL;

#define PIN_GYROSCOPE_WIRE_SDA       PIN_WIRE_SDA
#define PIN_GYROSCOPE_WIRE_SCL       PIN_WIRE_SCL
#define GYROSCOPE_WIRE Wire1
#define GYROSCOPE_ADC1               (93u)
#define GYROSCOPE_ADC2               (94u)
#define GYROSCOPE_ADC3               (95u)

/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 4

#define PIN_SPI_MISO       (46)
#define PIN_SPI_MOSI       (47)
#define PIN_SPI_SCK        (48)
#define PIN_SPI_SS         (49)
#define PERIPH_SPI         sercom5
#define PAD_SPI_TX         SPI_PAD_0_SCK_1
#define PAD_SPI_RX         SERCOM_RX_PAD_2

static const uint8_t SS	  = PIN_SPI_SS;
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK  = PIN_SPI_SCK;

#define PIN_SPI3_MISO         (34u)
#define PIN_SPI3_MOSI         (35u)
#define PIN_SPI3_SCK          (36u)
#define PIN_SPI3_SS           (37u)
#define PERIPH_SPI3           sercom7
#define PAD_SPI3_TX           SPI_PAD_3_SCK_1
#define PAD_SPI3_RX           SERCOM_RX_PAD_2

static const uint8_t SS3	 = PIN_SPI3_SS;
static const uint8_t MOSI3 = PIN_SPI3_MOSI;
static const uint8_t MISO3 = PIN_SPI3_MISO;
static const uint8_t SCK3  = PIN_SPI3_SCK;

#define PIN_SPI1_MISO       (38)
#define PIN_SPI1_MOSI       (39)
#define PIN_SPI1_SCK        (40)
#define PIN_SPI1_SS         (41)
#define PERIPH_SPI1         sercom0
#define PAD_SPI1_TX         SPI_PAD_0_SCK_1
#define PAD_SPI1_RX         SERCOM_RX_PAD_2

static const uint8_t SS1	 = PIN_SPI1_SS;
static const uint8_t MOSI1 = PIN_SPI1_MOSI;
static const uint8_t MISO1 = PIN_SPI1_MISO;
static const uint8_t SCK1  = PIN_SPI1_SCK;

#define PIN_SPI2_MISO       (42)
#define PIN_SPI2_MOSI       (43)
#define PIN_SPI2_SCK        (44)
#define PIN_SPI2_SS         (45)
#define PERIPH_SPI2         sercom6
#define PAD_SPI2_TX         SPI_PAD_0_SCK_1
#define PAD_SPI2_RX         SERCOM_RX_PAD_2

static const uint8_t SS2	 = PIN_SPI2_SS;
static const uint8_t MOSI2 = PIN_SPI2_MOSI;
static const uint8_t MISO2 = PIN_SPI2_MISO;
static const uint8_t SCK2  = PIN_SPI2_SCK;


// Needed for SD library
#define SDCARD_SPI          SPI2
#define SDCARD_MISO_PIN     PIN_SPI2_MISO
#define SDCARD_MOSI_PIN     PIN_SPI2_MOSI
#define SDCARD_SCK_PIN      PIN_SPI2_SCK
#define SDCARD_SS_PIN       PIN_SPI2_SS

// Needed for LCD library
#define LCD_SPI          SPI3
#define LCD_MISO_PIN     PIN_SPI3_MISO
#define LCD_MOSI_PIN     PIN_SPI3_MOSI
#define LCD_SCK_PIN      PIN_SPI3_SCK
#define LCD_SS_PIN       PIN_SPI3_SS
#define LCD_BACKLIGHT    (74U)
#define LCD_DC           (75u) 
#define LCD_RESET        (76U)
#define LCD_XL           (88u) 
#define LCD_YU           (89u) 
#define LCD_XR           (90u) 
#define LCD_YD           (91u) 

// Needed for ESP32 
#define ESP32_SPI          SPI1
#define ESP32_MISO_PIN     PIN_SPI1_MISO
#define ESP32_MOSI_PIN     PIN_SPI1_MOSI
#define ESP32_SCK_PIN      PIN_SPI1_SCK
#define ESP32_SS_PIN       PIN_SPI1_SS

//QSPI Pins
#define PIN_QSPI_SCK    (50u)
#define PIN_QSPI_CS     (51u)
#define PIN_QSPI_IO0    (52u)
#define PIN_QSPI_IO1    (53u)
#define PIN_QSPI_IO2    (54u)
#define PIN_QSPI_IO3    (55u)

/*
 * I2S Interfaces
 */
#define I2S_INTERFACES_COUNT 1

#define I2S_DEVICE          0
#define I2S_CLOCK_GENERATOR 3

#define PIN_I2S_SCK0          (60u)
#define PIN_I2S_FS0           (56u)
#define PIN_I2S_MCK0          (58u)

#define PIN_I2S_SCK1          (61u)
#define PIN_I2S_FS1           (57u)
#define PIN_I2S_MCK1          (59)

#define PIN_I2S_SDO          (63u)
#define PIN_I2S_SDI          (62u)
#define PIN_I2S_SCK          PIN_I2S_SCK0
#define PIN_I2S_FS           PIN_I2S_FS0
#define PIN_I2S_MCK          PIN_I2S_MCK0


//extra pin define
//Buzzer
#define BUZZER_CTR          (73u)

//ESP32
#define ESP32_GPIO4         (64u)
#define ESP32_GPIO25        (66u)
#define ESP32_GPIO0         (67u)

#define ESP32_GPIO34        (68u)
#define ESP32_GPIO38        (69u)
#define ESP32_GPIO39        (70u)
#define ESP32_GPIO21        (71u)
#define ESP32_GPIO33        (72u)

#define ESP32_GPIO16        (77u)
#define ESP32_GPIO17        (78u)
#define ESP32_GPIO26        (79u)
#define ESP32_GPIO36        (80u)
#define ESP32_GPIO37        (81u)

#define ESP32_GPIO15        (82u)
#define ESP32_GPIO23        (83u)
#define ESP32_GPIO22        (84u)
#define ESP32_GPIO18        (85u)

//MIC
#define MIC_INPUT          (92u)



#if !defined(VARIANT_QSPI_BAUD_DEFAULT)
  // TODO: meaningful value for this
  #define VARIANT_QSPI_BAUD_DEFAULT 5000000
#endif

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus

/*	=========================
 *	===== SERCOM DEFINITION
 *	=========================
*/
extern SERCOM sercom0;
extern SERCOM sercom1;
extern SERCOM sercom2;
extern SERCOM sercom3;
extern SERCOM sercom4;
extern SERCOM sercom5;
extern SERCOM sercom6;
extern SERCOM sercom7;

extern Uart Serial1;
extern Uart Serial2;

#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_USBVIRTUAL      Serial
#define SERIAL_PORT_MONITOR         Serial
// Serial has no physical pins broken out, so it's not listed as HARDWARE port
#define SERIAL_PORT_HARDWARE        Serial1
#define SERIAL_PORT_HARDWARE_OPEN   Serial1

#endif /* _VARIANT_GREOVE_UI_M4_WIRELESS */


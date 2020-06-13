#pragma once

#include <Arduino.h>
#include <Wire.h>
#include <axp20x.h>

// TTGO T-Beam Rev1 pinout
#define LORA_SCK 5
#define LORA_MISO 19
#define LORA_MOSI 27
#define LORA_SS 18
#define LORA_DI0 26
#define LORA_RST 23
#define GPS_RX_PIN 34
#define GPS_TX_PIN 12
#define I2C_SDA 21
#define I2C_SCL 22
#define PMU_IRQ 35
#define USER_BUTTON 36

//! Error Codes
#define TBHR1_PASS            (0)
#define TBHR1_FAIL            (-1)
#define TBHR1_INVALID         (-2)
#define TBHR1_NOT_INIT        (-3)
#define TBHR1_NOT_SUPPORT     (-4)
#define TBHR1_ARG_INVALID     (-5)

typedef enum {
   TBHR1_LED_OFF,
   TBHR1_LED_ON,
   TBHR1_LED_BLINK_1HZ,
   TBHR1_LED_BLINK_4HZ
} tbhr1_onboard_led_status_t;

typedef uint8_t (*axp_com_fptr_t)(uint8_t dev_addr, uint8_t reg_addr, uint8_t *data, uint8_t len);

class tbhr1_Class
{
public:
   /**
   * Constructor without argument by default will try to power on everything and set onboard LED
   * to blink with 1Hz.
   * @return  Returns TBHR1_PASS in case everythzing could be initialized properly, otherwise
   * returns TBHR1_FAIL.
   */
   int init();

   /**
   * Set status of onboard led (on | off | blinking 1Hz | blinking 4Hz)
   * @param  tbhr1_onboard_led_status_t param: Set status of the led, use one of the following
   * parameters:
   * - TBHR1_LED_OFF
   * - TBHR1_LED_ON
   * - TBHR1_LED_BLINK_1HZ
   * - TBHR1_LED_BLINK_4HZ
   * @return  Returns TBHR1_ARG_INVALID | TBHR1_FAIL | TBHR1_PASS
   */
   int setOnboardLedStatus(tbhr1_onboard_led_status_t param);
private:
   /**
   * Check if AXP192 is available on I2C bus
   * @return true in case found, else false.
   */
   bool scanI2CforAxp192(void);
   
};
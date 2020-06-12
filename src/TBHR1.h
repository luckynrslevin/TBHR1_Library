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

class tbhr1_Class
{
public:
   void init();
private:
};
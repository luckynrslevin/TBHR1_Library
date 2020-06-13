#include "tbhr1.h"

#include <Wire.h>
#include <axp20x.h>

AXP20X_Class axp;

int tbhr1_Class::init()
{
    int retValue = TBHR1_PASS;
    Wire.begin(I2C_SDA, I2C_SCL);
    Wire.beginTransmission(AXP192_SLAVE_ADDRESS);
    if (Wire.endTransmission() == 0) {
        if (!axp.begin(Wire, AXP192_SLAVE_ADDRESS)) {
            // power on everything
            if (axp.setPowerOutPut(AXP192_LDO2, AXP202_ON) != AXP_PASS)
                retValue = TBHR1_FAIL;
            if (axp.setPowerOutPut(AXP192_LDO3, AXP202_ON) != AXP_PASS)
                retValue = TBHR1_FAIL;
            if (axp.setPowerOutPut(AXP192_DCDC1, AXP202_ON) != AXP_PASS)
                retValue = TBHR1_FAIL;
            if (axp.setPowerOutPut(AXP192_DCDC2, AXP202_ON) != AXP_PASS)
                retValue = TBHR1_FAIL;
            if (axp.setPowerOutPut(AXP192_DCDC3, AXP202_ON) != AXP_PASS)
                retValue = TBHR1_FAIL;
            if (axp.setPowerOutPut(AXP192_EXTEN, AXP202_ON) != AXP_PASS)
                retValue = TBHR1_FAIL;
            if (axp.setDCDC1Voltage(3300) != AXP_PASS)
                retValue = TBHR1_FAIL; //Set Pin header 3.3V line to 3.3V. Processor is happy down to 1.8V which saves power
            // Set mode of blue onboard LED (OFF, ON, Blinking 1Hz, Blinking 4 Hz)
            if (axp.setChgLEDMode(AXP20X_LED_BLINK_1HZ) != AXP_PASS)
                retValue = TBHR1_FAIL;
        }
    } else {
        retValue = TBHR1_FAIL;
    }
    return retValue;
}

int tbhr1_Class::setOnboardLedStatus(tbhr1_onboard_led_status_t param)
{
    switch(param) {
        case TBHR1_LED_OFF:
        if (axp.setChgLEDMode(AXP20X_LED_OFF) != AXP_PASS)
            return TBHR1_FAIL;
        break;
        case TBHR1_LED_BLINK_1HZ:
        if (axp.setChgLEDMode(AXP20X_LED_BLINK_1HZ) != AXP_PASS)
            return TBHR1_FAIL;
        break;
        case TBHR1_LED_BLINK_4HZ:
        if (axp.setChgLEDMode(AXP20X_LED_BLINK_4HZ) != AXP_PASS)
            return TBHR1_FAIL;
        break;
        case TBHR1_LED_ON:
        if (axp.setChgLEDMode(AXP20X_LED_LOW_LEVEL) != AXP_PASS)
            return TBHR1_FAIL;
        break;
        default:
            return TBHR1_ARG_INVALID;
        break;
    }
    return TBHR1_PASS;
}
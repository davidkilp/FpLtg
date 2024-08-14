#pragma once

#include "FT260.h"

typedef struct {
	uint8_t chan0;
	uint8_t chan1;
	uint8_t chan2;
	uint8_t chan3;
} PCA9632_PWMx_t;

class PCA9632 {

private:
	FT260_HANDLE _mhandle;
    FT260* _ft260;
	uint8_t _i2c_address;
    FT260_STATUS checkFT260Status(std::string msg, FT260_STATUS ftstatus);

public:
	PCA9632(uint8_t i2c_address);

    enum Reg
    {
        MODE1 = 0x00,           // Mode register 1
        MODE2 = 0x01,           // Mode register 2
        PWM0 = 0x02,            // brightness congtrol LED0
        PWM1 = 0x03,            // brightness congtrol LED1
        PWM2 = 0x04,            // brightness congtrol LED2
        PWM3 = 0x05,            // brightness congtrol LED3
        GRPPWM = 0x06,          // group duty cycle control
        GRPFREQ = 0x07,         // group frequency
        LEDOUT = 0x08,          // LED output state
        SUBADR1 = 0x09,         // I2C-bus subaddress1
        SUBADR2 = 0x0A,         // I2C-bus subaddress2
        SUBADR3 = 0x0B,         // I2C-bus subaddress3
        ALLCALLADR = 0x0C       // LED All Call I2C bus address
    };

    enum PCA9632_LEDOUT
    {
        LDRx_OFF = 0x00,
        LDRx_ON = 0x01,
        LDRx_PWM = 0x02,
        LDRx_GRPPWM = 0x03
    };

	int WriteReg(uint8_t reg, uint8_t value);
	int ReadReg(uint8_t reg, uint8_t & value);
	int WritePwmxRegs(PCA9632_PWMx_t *pwmx);
	int ReadPwmxRegs(PCA9632_PWMx_t *pwmx);
};


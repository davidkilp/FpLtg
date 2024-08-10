#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <iostream>
#include <iomanip>
#include <format>

#include "PCA9632.h"
#include "FT260.h"

PCA9632::PCA9632(uint8_t i2c_address)
{
	std::cout << std::format("Create a PCA9632 device for I2C Address: 0x{:02X}\n", i2c_address);
	FT260* ft260 = FT260::GetInstance();
	FT260_HANDLE ft260handle = ft260->getHandle();
	_mhandle = ft260handle;
	_i2c_address = i2c_address;
	std::cout << std::format("FT260 handle {:p}\n", ft260handle);

    std::cout << std::format("Initializing the LED strip at 0x{:02X}", i2c_address) << std::endl;
    // Initialize the current LED strip
    // Configure PCA9632 Mode Register 1 (00h) to Enable oscillator, no auto-increment
    // Set Mode Register 1 = 00000000
    WriteReg(MODE1, 0x00);

    // Configure PCA9632 device for External N-Type driver without pullups INVRT(4)=1, OUTDRV(2)=1 or INVRT=0, OUTDRV=1
    // Set Mode Register 2 (MODE2 = 0x01) 0001 0101 = 0x15
    WriteReg(MODE2, 0x15);


    std::cout << "Set current strip LEDOUT (08h) to turn on all LEDs using Indiv + GRPPWM registers" << std::endl;
    // Set Front LEDOUT (08h) to turn on all LEDs using Indiv + GRPPWM registers
    WriteReg(LEDOUT, 
		LDRx_GRPPWM << 4 |
        LDRx_GRPPWM << 2 |
        LDRx_GRPPWM
    );

}

int PCA9632::WriteReg(uint8_t reg, uint8_t value)
{
	FT260_STATUS ftstatus;
	//std::cout << std::format("Writing 0x{:02X} to register 0x{:02X} at I2C Address: 0x{:02X} using handle: {:p}\n", value, reg, _i2c_address, _mhandle);
	ftstatus = _ft260->writeSingleByte(_i2c_address, reg, value);

	return 0;
}

int PCA9632::ReadReg(uint8_t reg, uint8_t & value)
{
	FT260_STATUS ftstatus;
	//std::cout << std::format("Reading register 0x{:02X} at I2C Address: 0x{:02X}\n", reg, _i2c_address);
	ftstatus = _ft260->readSingleByte(_i2c_address, reg, value);

	return 0;
}

/**
*	WritePwmxRegs 
*/
int PCA9632::WritePwmxRegs(PCA9632_PWMx_t *pwmx)
{
	FT260_STATUS ftstatus;
	uint8_t writebuf[5]{};
	uint8_t CtrlRegister = 0xA2;   // auto-increment indv bright starting at register 0x02(PWM0)

	//std::cout << std::format("Writing PWMx registers to I2C Address: 0x{:02X}, chan0: 0x{:02X}, chan1: 0x{:02X}, chan2: 0x{:02X}, chan3: 0x{:02X}\n", _i2c_address, pwmx->chan0, pwmx->chan1, pwmx->chan2, pwmx->chan3);

	writebuf[0] = CtrlRegister;		// first byte is the PCA9632 Register to start at
	writebuf[1] = pwmx->chan0;
	writebuf[2] = pwmx->chan1;
	writebuf[3] = pwmx->chan2;
	writebuf[4] = pwmx->chan3;
	ftstatus = _ft260->writeMultipleBytes(_i2c_address, writebuf, 5);

	return 0;
}

int PCA9632::ReadPwmxRegs(PCA9632_PWMx_t *pwmx)
{
	FT260_STATUS ftstatus;
	uint8_t ioBuffer[10] = {};
	uint8_t CtrlRegister = 0xA2;   // auto-increment indv bright starting at register 0x02(PWM0)

	//std::cout << std::format("Reading PWMx registers from I2C Address: 0x{:02X}\n", _i2c_address);

	// first we need to write the CtrlRegister we are going to read (handled by call)
	ftstatus = _ft260->readMultipleBytes(_i2c_address, CtrlRegister, ioBuffer, 4);
	if (ftstatus != FT260_OK) {
		std::string error(_ft260->FT260StatusToString(ftstatus));
		std::cerr << "readMultipleBytes fails: " << error << std::endl;
	}
	else
	{
		pwmx->chan0 = ioBuffer[0];
		pwmx->chan1 = ioBuffer[1];
		pwmx->chan2 = ioBuffer[2];
		pwmx->chan3 = ioBuffer[3];
	}

	return 0;
}


#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <iostream>
#include <iomanip>
#include <format>

#include "FpLtg.h"
#include "PCA9632.h"


/*
 * Constructor for an generic RGB strip on either front or back
 *
 */
FpLtg::FpLtg(RBGStrip strip)
{
	std::cout << "FpLtg() Constructor for strip: " << static_cast<int>(strip) << std::endl;
	if (strip == RBGStrip::Front)
		_pca9632 = new PCA9632(0x60);
	else
		_pca9632 = new PCA9632(0x63);
}

void FpLtg::setRGB(uint8_t red, uint8_t green, uint8_t blue)
{
	PCA9632_PWMx_t colors;

	/* NOTE the colors requested needs to match the way the PCA9632 output are connected */
	colors.chan0 = green;
	colors.chan1 = red;
	colors.chan2 = blue;
	colors.chan3 = 0;

	_pca9632->WritePwmxRegs(&colors);
}

void FpLtg::getRGB(uint8_t& red, uint8_t& green, uint8_t& blue)
{
	PCA9632_PWMx_t colors;
	_pca9632->ReadPwmxRegs(&colors);
	green = colors.chan0;
	red = colors.chan1;
	blue = colors.chan2;
}


/**
 * set/clear bit 5 (DBLNK) in MODE2 register
 */
void FpLtg::setBlink(bool blink)
{
	uint8_t mode2;
	_pca9632->ReadReg(PCA9632::Reg::MODE2, mode2);
	if (blink)
	{
		mode2 |= (1 << 5);	// set bit 5
	}
	else
	{
		mode2 &= ~(1 << 5); // clear bit 5
	}
	_pca9632->WriteReg(PCA9632::Reg::MODE2, mode2);
}

bool FpLtg::getBlink()
{
	uint8_t mode2;
	_pca9632->ReadReg(PCA9632::Reg::MODE2, mode2);
	return (mode2 & (1 << 5)) ? true : false;
}

void FpLtg::setBrightness(uint8_t brightness)
{
	uint8_t value = 0;
	// validate/check input: 0 - 15)
	value = brightness & 0x0F;

	value = brightness << 0x04;		// put in proper location

	_pca9632->WriteReg(PCA9632::Reg::GRPPWM, value);
}

uint8_t FpLtg::getBrightness()
{
	uint8_t value = 0;
	_pca9632->ReadReg(PCA9632::Reg::GRPPWM, value);
	return value >> 4;	// lower 4-bits unused in Group PWM mode.
}

void FpLtg::setBlinkRate(uint8_t rate)
{
	_pca9632->WriteReg(PCA9632::Reg::GRPFREQ, rate);
}

uint8_t FpLtg::getBlinkRate()
{
	uint8_t rate = 0;
	_pca9632->ReadReg(PCA9632::Reg::GRPFREQ, rate);
	return rate;
}

/*
 ** Get/Set Duty Cycle: value 0-15
 *  NOTE: in Group PWM mode this is the same value as the brightness control
 */
void FpLtg::setDutyCycle(uint8_t dutycycle)
{
	setBrightness(dutycycle);
}

uint8_t FpLtg::getDutyCycle()
{
	return getBrightness();
}

// Helper methods for constructor and exported methods
extern "C" LIGHTING_API FpLtg* FpLtg_Instantiate(RBGStrip strip)
{
	return new FpLtg(strip);
}

extern "C" LIGHTING_API void FpLtg_setRGB(FpLtg* p, uint8_t red, uint8_t green, uint8_t blue)
{
	p->setRGB(red, green, blue);
}

extern "C" LIGHTING_API void FpLtg_getRGB(FpLtg* p, uint8_t& red, uint8_t& green, uint8_t& blue)
{
	p->getRGB(red, green, blue);
}

extern "C" LIGHTING_API void FpLtg_setBlink(FpLtg* p, bool blink)
{
	p->setBlink(blink);
}

extern "C" LIGHTING_API bool FpLtg_getBlink(FpLtg* p)
{
	return p->getBlink();
}

extern "C" LIGHTING_API void FpLtg_setBrightness(FpLtg* p, uint8_t brightness)
{
	p->setBrightness(brightness);
}

extern "C" LIGHTING_API uint8_t FpLtg_getBrightness(FpLtg* p)
{
	return p->getBrightness();
}

extern "C" LIGHTING_API void FpLtg_setBlinkRate(FpLtg* p, uint8_t rate)
{
	p->setBlinkRate(rate);
}

extern "C" LIGHTING_API uint8_t FpLtg_getBlinkRate(FpLtg* p)
{
	return p->getBlinkRate();
}

extern "C" LIGHTING_API void FpLtg_setDutyCycle(FpLtg* p, uint8_t dutycycle)
{
	p->setDutyCycle(dutycycle);
}

extern "C" LIGHTING_API uint8_t FpLtg_getDutyCycle(FpLtg* p)
{
	return p->getDutyCycle();
}

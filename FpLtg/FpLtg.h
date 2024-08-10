#pragma once

#include "PCA9632.h"

#ifdef FPLTG_EXPORTS		// <LIBNAME>_EXPORT
#define LIGHTING_API __declspec(dllexport)
#else
#define LIGHTING_API __declspec(dllimport)
#endif

enum class RBGStrip {
	Front,
	Back
};

/**
 * Face Pod RBG LED Lighting Control Class
 *
 */
class FpLtg {

private:
	PCA9632* _pca9632;

public:
	FpLtg(RBGStrip strip);

	void setRGB(uint8_t red, uint8_t green, uint8_t blue);
	void getRGB(uint8_t & red, uint8_t & green, uint8_t & blue);
	void setBlink(bool blink);
	bool getBlink();
	void setBrightness(uint8_t brightness);
	uint8_t getBrightness();
	void setBlinkRate(uint8_t rate);
	uint8_t getBlinkRate();
	void setDutyCycle(uint8_t dutycycle);
	uint8_t getDutyCycle();

};

// Helper methods for constructor and exported methods
extern "C" LIGHTING_API FpLtg* FpLtg_Instantiate(RBGStrip strip);

extern "C" LIGHTING_API void FpLtg_setRGB(FpLtg* p, uint8_t red, uint8_t green, uint8_t blue);

extern "C" LIGHTING_API void FpLtg_getRGB(FpLtg* p, uint8_t& red, uint8_t& green, uint8_t& blue);

extern "C" LIGHTING_API void FpLtg_setBlink(FpLtg* p, bool blink);

extern "C" LIGHTING_API bool FpLtg_getBlink(FpLtg* p);

extern "C" LIGHTING_API void FpLtg_setBrightness(FpLtg* p, uint8_t brightness);

extern "C" LIGHTING_API uint8_t FpLtg_getBrightness(FpLtg* p);

extern "C" LIGHTING_API void FpLtg_setBlinkRate(FpLtg* p, uint8_t rate);

extern "C" LIGHTING_API uint8_t FpLtg_getBlinkRate(FpLtg* p);

extern "C" LIGHTING_API void FpLtg_setDutyCycle(FpLtg* p, uint8_t dutycycle);

extern "C" LIGHTING_API uint8_t FpLtg_getDutyCycle(FpLtg* p);

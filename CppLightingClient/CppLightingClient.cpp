#include <iostream>
#include <iomanip>
#include <format>
#include <chrono>
#include <thread>

#include "FpLtg.h"

typedef struct {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	uint8_t brightness;
	uint8_t blinkrate;
	uint8_t dutycycle;  // 0 - 15
	bool blink;
} LightStripState_t;

static LightStripState_t FrontStripState;
static LightStripState_t BackStripState;

void runTest(FpLtg* ledFront, FpLtg* ledBack)
{
	std::cout << "Starting Tests" << std::endl;


	//ledFront->setRGB(0x10, 0x20, 0x30);
	FpLtg_setRGB(ledFront, 0x10, 0x20, 0x30);
	FpLtg_setRGB(ledBack, 0x11, 0x22, 0x33);

	// adjust brightness
	for (uint8_t i = 0; i < 15; i++)
	{
		FpLtg_setBrightness(ledFront, i);
		FpLtg_setBrightness(ledBack, i);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

	FpLtg_setBlinkRate(ledFront, 10);
	FpLtg_setBlinkRate(ledBack, 20);

	FpLtg_setDutyCycle(ledFront, 8);
	FpLtg_setDutyCycle(ledBack, 8);

	// duty cycle at ~50%
	FpLtg_setBlink(ledFront, true);
	FpLtg_setBlink(ledBack, true);

	std::this_thread::sleep_for(std::chrono::milliseconds(1500));

	// adjust duty cycle
	for (uint8_t i = 0; i < 15; i++)
	{
		FpLtg_setDutyCycle(ledFront, i);
		FpLtg_setDutyCycle(ledBack, i);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

	// reset duty cycle at ~50%
	FpLtg_setDutyCycle(ledFront, 8);
	FpLtg_setDutyCycle(ledBack, 8);

	// disable blinking
	FpLtg_setBlink(ledFront, false);
	FpLtg_setBlink(ledBack, false);


}

// Get all current values so we can restore them when done
void getLedStrips(FpLtg* ledFront, FpLtg* ledBack)
{
	FpLtg_getRGB(ledFront, FrontStripState.red, FrontStripState.green, FrontStripState.blue);
	FpLtg_getRGB(ledBack, BackStripState.red, BackStripState.green, BackStripState.blue);

	FrontStripState.brightness = FpLtg_getBrightness(ledFront);
	BackStripState.brightness = FpLtg_getBrightness(ledBack);

	FrontStripState.dutycycle = FpLtg_getDutyCycle(ledFront);
	BackStripState.dutycycle = FpLtg_getDutyCycle(ledBack);

	FrontStripState.blinkrate = FpLtg_getBlinkRate(ledFront);
	BackStripState.blinkrate = FpLtg_getBlinkRate(ledBack);

	FrontStripState.blink = FpLtg_getBlink(ledFront);
	BackStripState.blink = FpLtg_getBlink(ledBack);
}

static void restoreLedStrips(FpLtg* ledFront, FpLtg* ledBack)
{
	FpLtg_setRGB(ledFront, FrontStripState.red, FrontStripState.green, FrontStripState.blue);
	FpLtg_setRGB(ledBack, BackStripState.red, BackStripState.green, BackStripState.blue);

	FpLtg_setBrightness(ledFront, FrontStripState.brightness);
	FpLtg_setBrightness(ledBack, BackStripState.brightness);

	FpLtg_setDutyCycle(ledFront, FrontStripState.dutycycle);
	FpLtg_setDutyCycle(ledBack, BackStripState.dutycycle);

	FpLtg_setBlinkRate(ledFront, FrontStripState.blinkrate);
	FpLtg_setBlinkRate(ledBack, BackStripState.blinkrate);

	FpLtg_setBlink(ledFront, FrontStripState.blink);
	FpLtg_setBlink(ledBack, BackStripState.blink);
}

int main(int argc, char* argv[])
{
	int ret = 0;
	std::cout << "RGB LED Strip Test Client" << std::endl;
	
	try
	{
		// Initialize hardware
		FpLtg* ledFront = FpLtg_Instantiate(RBGStrip::Front);
		FpLtg* ledBack = FpLtg_Instantiate(RBGStrip::Back);

		getLedStrips(ledFront, ledBack);
		runTest(ledFront, ledBack);
		//restoreLedStrips(ledFront, ledBack);;

	}
	catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
		ret = -1;
	}

	std::cout << "Testing complete" << std::endl;

	return ret;
}

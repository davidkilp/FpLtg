# FpLtg - HID Gate Lighting & Audio Control

## Summary
Controls the Front and Back lighting strips for the HID gate.

Solution includes separate builds for :

 * C++ DLL that hides all the low level details: FpLtg.dll
 * A Cpp command line demo program that uses the DLL: CppLightingClient.exe
 * A .NET conmmand line demo program that uses the DLL: Console_dotNET_client.exe
 * A .NET Forms GUI demo application using the DLL through interop services: LightingDemo.exe
 * A program installer for the GUI demo application: HID Lighting Demo Setup.exe
 
The primary output is the FpLtg.dll which can be included in users program to control the lighting strips.

## Requirements
* Visual Studio 2022
* .NET 8 Runtime must be installed on hosted system. See: [.NET 8 Runtime Installer:](https://dotnet.microsoft.com/en-us/download/dotnet/thank-you/runtime-desktop-8.0.2-windows-x64-installer)
* LibFT260.dll from FTDI Chip. A copy is included here but the original can be obtained from [[FTDI directly](https://ftdichip.com/products/ft260q/])


## API

The FpLtg.dll provides the following API for user programs:

```
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
```


## Usage

Find the .NET GUI application, LightingDemo.exe, and launch it. 

![screenshot](https://github.com/davidkilp/FpLtg/blob/master/HID-LightingDemo_sceenshot.jpg)

When Blinking is Enabled, the Brightness control will control the Duty Cycle (On/Off time per period) of the blinking at
the selected blink rate. The blinking rate can be changed in 256 linear steps from 0 (41 ms, frequency 24 Hz)
to 255 (10.73 seconds).


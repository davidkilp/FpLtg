# FpLtg - HID Gate Lighting & Audio Control

## Summary
Controls the Front and Back lighting strips for the HID gate.

Solution includes separate builds for :

 * C++ DLL that hides all the low level details
 * A Cpp command line demo program that uses the DLL
 * A .NET conmmand line demo program that uses the DLL
 * A .NET Forms GUI demo application using the DLL through interop services.
 * A program installer for the GUI demo application.
 
The primary output is the FpLtg.dll which can be included in users program to control the lighting strips.

## Requirements
* Visual Studio 2022
* .NET 8 Runtime must be installed on hosted system. See: [.NET 8 Runtime Installer:](https://dotnet.microsoft.com/en-us/download/dotnet/thank-you/runtime-desktop-8.0.2-windows-x64-installer)
* LibFT260.dll from FTDI Chip. A copy is included here but the original can be obtained from [[FTDI directly](https://ftdichip.com/products/ft260q/])

## Usage

Find the .NET GUI application, LightingDemo.exe, and launch it. 

![screenshot](https://github.com/davidkilp/FpLtg/blob/master/HID-LightingDemo_sceenshot.jpg)

When Blinking is Enabled, the Brightness control will control the Duty Cycle (On/Off time per period) of the blinking at
the selected blink rate. The blinking rate can be changed in 256 linear steps from 00h (41 ms, frequency 24 Hz)
to FFh (10.73 seconds).


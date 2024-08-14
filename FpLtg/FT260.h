#pragma once

#include <mutex>

#include "LibFT260.h"
#include <stdint.h>
#include <string>

const uint16_t FT260_Vid = 0x0403;
const uint16_t FT260_Pid = 0x6030;

#define I2C_100KHZ  100
#define I2C_400KHZ  400

const std::string sFT260Status[] =
{
    "FT260_OK",
    "FT260_INVALID_HANDLE",
    "FT260_DEVICE_NOT_FOUND",
    "FT260_DEVICE_NOT_OPENED",
    "FT260_DEVICE_OPEN_FAIL",
    "FT260_DEVICE_CLOSE_FAIL",
    "FT260_INCORRECT_INTERFACE",
    "FT260_INCORRECT_CHIP_MODE",
    "FT260_DEVICE_MANAGER_ERROR",
    "FT260_IO_ERROR",
    "FT260_INVALID_PARAMETER",
    "FT260_NULL_BUFFER_POINTER",
    "FT260_BUFFER_SIZE_ERROR",
    "FT260_UART_SET_FAIL",
    "FT260_RX_NO_DATA",
    "FT260_GPIO_WRONG_DIRECTION",
    "FT260_INVALID_DEVICE",
    "FT260_INVALID_OPEN_DRAIN_SET",
    "FT260_INVALID_OPEN_DRAIN_RESET",
    "FT260_I2C_READ_FAIL",
    "FT260_OTHER_ERROR"
};


class FT260 {

private:
	static FT260_HANDLE _handle;
	static FT260 * _pinstance;
	static std::mutex _mutex;

protected:
	/* The Singleton constructor/destructor should always be
	 * private to prevent direct call with new/delete
	 */

	/*
	 * constructor need to open connection to the FT260 device
	 */
	FT260();

	/*
	 * destructor needs to free this up
	 */
	~FT260();

public:
    /**
     * Singletons should not be cloneable.
     */
    FT260(FT260 &other) = delete;

    /**
     * Singletons should not be assignable.
     */
    void operator=(const FT260 &) = delete;

    /**
     * This is the static method that controls the access to the singleton
     * instance. On the first run, it creates a singleton object and places it
     * into the static field. On subsequent runs, it returns the client existing
     * object stored in the static field.
     */
    static FT260 *GetInstance();

    // Read a single byte from a register.
    FT260_STATUS readSingleByte(uint8_t i2cAddress, uint8_t registerAddress, uint8_t& value);

    // Write a single byte into a register.
    FT260_STATUS writeSingleByte(uint8_t i2cAddress, uint8_t registerAddress, uint8_t value);

    // Read multiple bytes from a register into buffer byte array.
    FT260_STATUS readMultipleBytes(uint8_t i2cAddress, uint8_t startAddress, uint8_t* buffer, uint16_t bufferSize);

    // Write multiple bytes to register from buffer byte array.
    FT260_STATUS writeMultipleBytes(uint8_t i2cAddress, uint8_t* buffer, uint16_t bufferSize);

    FT260_HANDLE getHandle() {
        return _handle;
    }

    const char* FT260StatusToString(FT260_STATUS status);
};


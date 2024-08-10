#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <iostream>
#include <format>

#include "FT260.h"

#define DEBUG	1
#ifdef DEBUG
#define D(x)   x
#else
#define D(x)
#endif

FT260::FT260()
{
    FT260_STATUS ftStatus = FT260_OTHER_ERROR;
    FT260_HANDLE mhandle = INVALID_HANDLE_VALUE;

    std::cout << "FT260 Constructor\n";

    // Open device by VID/PID
    ftStatus = FT260_OpenByVidPid(FT260_Vid, FT260_Pid, 0, &mhandle);
    if (FT260_OK != ftStatus)
    {
        //printf("Open device by VID/PID failed: %s\n", FT260StatusToString(ftStatus));
        std::string error(FT260StatusToString(ftStatus));
        std::cerr << "FT260_OpenByVidPid fails: " << error << std::endl;
        throw std::runtime_error("FT260 Open fails error: " + error);
    }

    _handle = mhandle;  // save the handle
    std::cout << std::format("FT260 handle {:p}\n", FT260::_handle);

    std::cout << "FT260 Device found and opened!" << std::endl;

    //Initialize as an I2C Master, read/write to an I2C slave
    ftStatus = FT260_I2CMaster_Init(mhandle, I2C_100KHZ);
    if (ftStatus != FT260_OK) {
        printf("FT260_I2CMaster_Init() returns: %d\n", ftStatus);
        std::string error(FT260StatusToString(ftStatus));
        throw std::runtime_error("FT260_I2CMaster_Init fails error: " + error);
    }

    std::cout << "FT260 we are now I2C Master controller" << std::endl;

    uint8 I2Cstatus;
    ftStatus = FT260_I2CMaster_GetStatus(mhandle, &I2Cstatus);
    //std::cout << std::format("I2C Status = 0x{:02X}\n ", I2Cstatus);

    std::cout << "Configuring FT260 GPIO" << std::endl;

    // configure GPIO2 output function
    ftStatus = FT260_SelectGpioGFunction(mhandle, FT260_GPIOG_GPIO);
    if (ftStatus != FT260_OK) {
        std::string error(FT260StatusToString(ftStatus));
        std::cout << "GPIO set error: " << error << std::endl;
    }

    // Amp Enable 
    ftStatus = FT260_GPIO_SetDir(mhandle, FT260_GPIO_2, 1); // GPIO output
    ftStatus = FT260_GPIO_Write(mhandle, FT260_GPIO_2, 1);  // enable AMP

    // Audio Mute
    ftStatus = FT260_GPIO_SetDir(mhandle, FT260_GPIO_H, 1); // GPIO output
    ftStatus = FT260_GPIO_Write(mhandle, FT260_GPIO_H, 1);  // Not muted


    std::cout << "ft260IO() constructor initialization complete" << std::endl;

}

	/*
	 * destructor needs to close the handle and clean up
	 */
FT260::~FT260()
{
	std::cout << "FT260 Destructor\n";
    FT260_Close(_handle);
}

/**
 * Static methods should be defined outside the class.
 */
FT260_HANDLE FT260::_handle {nullptr};
FT260 * FT260::_pinstance{nullptr};
std::mutex FT260::_mutex;


/**
 * The first time we call GetInstance we will lock the storage location
 *      and then we make sure again that the variable is null and then we
 *      set the value. RU:
 */
FT260 *FT260::GetInstance()
{
    std::lock_guard<std::mutex> lock(_mutex);
    if (_pinstance == nullptr)
    {
        _pinstance = new FT260();
    }
    return _pinstance;
}

const char* FT260::FT260StatusToString(FT260_STATUS status)
{
    switch (status)
    {
    case  0:
        return sFT260Status[0].c_str();
    case  1:
        return sFT260Status[1].c_str();
    case  2:
        return sFT260Status[2].c_str();
    case  3:
        return sFT260Status[3].c_str();
    case  4:
        return sFT260Status[4].c_str();
    case  5:
        return sFT260Status[5].c_str();
    case  6:
        return sFT260Status[6].c_str();
    case  7:
        return sFT260Status[7].c_str();
    case  8:
        return sFT260Status[8].c_str();
    case  9:
        return sFT260Status[9].c_str();
    case 10:
        return sFT260Status[10].c_str();
    case 11:
        return sFT260Status[11].c_str();
    case 12:
        return sFT260Status[12].c_str();
    case 13:
        return sFT260Status[13].c_str();
    case 14:
        return sFT260Status[14].c_str();
    case 15:
        return sFT260Status[15].c_str();
    case 16:
        return sFT260Status[16].c_str();
    case 17:
        return sFT260Status[17].c_str();
    default:
        return "Not a valid FT260 status";
    }
}

// Read a single byte from a register.
FT260_STATUS FT260::readSingleByte(uint8_t i2cAddress, uint8_t registerAddress, uint8_t& value)
{
    FT260_STATUS ftStatus = FT260_OK;
    DWORD readLength = 0;
    DWORD writeLength = 0;
    DWORD numBytesToRead = 0;
    DWORD numBytesToWrite = 0;
    uint8_t buffer[3] = {};

    D(printf("Read 1 byte from 0x%02X at address: 0x%02X\n", i2cAddress, registerAddress); )

    // first write register to read
    numBytesToWrite = 1;
    buffer[0] = registerAddress;
    ftStatus = FT260_I2CMaster_Write(_handle, i2cAddress, FT260_I2C_START_AND_STOP, buffer, numBytesToWrite, &writeLength);
    if ((ftStatus != FT260_OK) || (writeLength != numBytesToWrite))
    {
        printf("FT260_I2CMaster_Write setting register fails: %d\n", ftStatus);
        return ftStatus;
    }

    // Now lets read the byte specified
    numBytesToRead = 1;
    value = 0;
    ftStatus = FT260_I2CMaster_Read(_handle, i2cAddress, FT260_I2C_START_AND_STOP, buffer, numBytesToRead, &readLength, 5000);
    if ((ftStatus != FT260_OK) || (readLength != numBytesToRead))
    {
        printf("FT260_I2CMaster_Read() fails: %d\n", ftStatus);
        return ftStatus;
    }
    value = buffer[0];
    D(printf("FT260_I2C_Read  ftStatus : % d  Read Length : %d, value: 0x%02X\n", ftStatus, readLength, value); )

    return ftStatus;
}

// Write a single byte into a register.
FT260_STATUS FT260::writeSingleByte(uint8_t i2cAddress, uint8_t registerAddress, uint8_t value)
{
    FT260_STATUS ftStatus = FT260_OK;
    DWORD writeLength = 0;
    DWORD numBytesToWrite = 0;
    uint8_t buffer[3] = {};

    D(printf("Write 1 byte (0x%02X) to 0x%02X at address: 0x%02X\n", value, i2cAddress, registerAddress); )

    // first write register to write
    buffer[0] = registerAddress;
    buffer[1] = value;
    numBytesToWrite = 2;
    ftStatus = FT260_I2CMaster_Write(_handle, i2cAddress, FT260_I2C_START_AND_STOP, buffer, numBytesToWrite, &writeLength);
    if ((ftStatus != FT260_OK) || (writeLength != numBytesToWrite))
    {
        printf("FT260_I2CMaster_Write setting register fails: %d\n", ftStatus);
        return ftStatus;
    }

    return ftStatus;
}

// Read multiple bytes from a register into buffer byte array with auto-increment
FT260_STATUS FT260::readMultipleBytes(uint8_t i2cAddress, uint8_t startAddress, uint8_t* buffer, uint16_t bufferSize)
{
    FT260_STATUS ftStatus = FT260_OK;
    DWORD readLength = 0;
    DWORD numBytesToRead = 0;

    D(printf("Reading %u bytes starting at address: 0x%02X\n", bufferSize, startAddress); )

    // First write address to start read from with auto-increment
    writeMultipleBytes(i2cAddress, &startAddress, 1);

    // Now lets read the byte specified
    numBytesToRead = bufferSize;
    ftStatus = FT260_I2CMaster_Read(_handle, i2cAddress, FT260_I2C_START_AND_STOP, buffer, numBytesToRead, &readLength, 5000);
    D(printf("FT260_I2C_Read  ftStatus : % d  Read Length : %d\n", ftStatus, readLength); )

    return ftStatus;
}

// Write multiple bytes to register from buffer byte array with auto-increment 
FT260_STATUS FT260::writeMultipleBytes(uint8_t i2cAddress, uint8_t* buffer, uint16_t bufferSize)
{
    FT260_STATUS ftStatus = FT260_OK;
    DWORD writeLength = 0;
    DWORD numBytesToWrite = 0;
    uint32_t bytesToSend = bufferSize;

    D(printf("Write %u bytes to 0x%02X starting at address: 0x%02X\n", bytesToSend, i2cAddress, buffer[0]); )

    numBytesToWrite = bufferSize;
    ftStatus = FT260_I2CMaster_Write(_handle, i2cAddress, FT260_I2C_START_AND_STOP, buffer, numBytesToWrite, &writeLength);
    if ((ftStatus != FT260_OK) || (writeLength != numBytesToWrite))
    {
        printf("FT260_I2CMaster_Write data write multiple fails: %d wrote: %d\n", ftStatus, writeLength);
        return ftStatus;
    }

    return ftStatus;
}

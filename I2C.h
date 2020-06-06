#ifndef I2C__H
#define I2C__H

#include <cstdint>

int connect_to_device(int dev_address);
uint8_t read_8b(int i2c_handle, uint8_t xl_address);
uint16_t read_16b(int i2c_handle, uint8_t xl_address);
int write_8b(int i2c_handle, uint8_t xl_address, uint8_t byte_to_write);

#endif
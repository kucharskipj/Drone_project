#include "I2C.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>
#include <stdlib.h>
#include <string.h>

int connect_to_device(int dev_address){
    int i2c_handle = open("/dev/i2c-1",O_RDWR);
    if (i2c_handle < 0) throw "Error opening file!";
    if (ioctl(i2c_handle, I2C_SLAVE, dev_address) < 0) throw "ioctl error!";
}

uint16_t read_16b(int i2c_handle, uint8_t xl_address){
    char rx_buffer[32];
    char tx_buffer[32];
    int op_result = 0;
    memset(rx_buffer, 0, sizeof(rx_buffer));
    memset(tx_buffer, 0, sizeof(tx_buffer));
    tx_buffer[0] = xl_address;
    op_result = write(i2c_handle, tx_buffer,1);
    if (op_result != 1) throw "No ACK bit!";
    op_result = read(i2c_handle, rx_buffer, 2);
    uint16_t value = (rx_buffer[0] << 8 ) | rx_buffer[1];
    return value;
}

uint8_t read_8b(int i2c_handle, uint8_t xl_address){
    char rx_buffer[32];
    char tx_buffer[32];
    int op_result = 0;
    memset(rx_buffer, 0, sizeof(rx_buffer));
    memset(tx_buffer, 0, sizeof(tx_buffer));
    tx_buffer[0] = xl_address;
    op_result = write(i2c_handle, tx_buffer,1);
    if (op_result != 1) throw "No ACK bit!";
    op_result = read(i2c_handle, rx_buffer, 1);
    uint8_t value = rx_buffer[0];
    return value;
}

int write_8b(int i2c_handle, uint8_t xl_address, uint8_t byte_to_write){
    uint8_t buffer[2];
    buffer[0] = xl_address;
    buffer[1] = byte_to_write;
    return (int)write(i2c_handle, buffer, 2);
}

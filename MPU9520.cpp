#include "MPU9520.h"
#include "I2C.h"
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>

MPU9520::MPU9520(int _imu_i2c_address) : imu_i2c_address(_imu_i2c_address) {
    this->open_connection();
    this->check_id();
    this->read_acc_range();
    this->read_w_range();
}

std::vector<double> MPU9520::read_imu(){
    for(int i = 0; i < vec.size(); ++i){
        vec[i] = read_16b(i2c_handle, address_to_read[i]);
    }
    return vec;
}

std::vector<double> MPU9520::read_acceleration(){
    this->read_imu();
    std::vector<double>::const_iterator first = vec.begin();
    std::vector<double>::const_iterator last = vec.begin() + 3;
    std::vector<double> n_vec(first, last);
    return n_vec;
}

std::vector<double> MPU9520::read_angular_velocity(){
    this->read_imu();
    std::vector<double>::const_iterator first = vec.end() - 3;
    std::vector<double>::const_iterator last = vec.end();
    std::vector<double> n_vec(first, last);
    return n_vec;
}

void MPU9520::open_connection(){

    this->i2c_handle = connect_to_device(imu_i2c_address);
    this->connection_state = true;
}

void MPU9520::set_acc_range(){
    write_8b(i2c_handle, ACC_RANGE_ADD, ACC_RANGE_1000);
}

void MPU9520::set_w_range(){
    write_8b(i2c_handle, W_RANGE_ADD, W_RANGE_1000);
}

void MPU9520::read_acc_range(){
    this->acc_range = read_8b(i2c_handle, ACC_RANGE_ADD);
}

void MPU9520::read_w_range(){
    this->w_range = read_8b(i2c_handle, W_RANGE_ADD);
}

void MPU9520::check_id(){
    if(read_8b(i2c_handle, IMU_ID_ADD) != IMU_ID) throw "unknown IMU!";
}

bool MPU9520::is_connected(){
    return connection_state;
}
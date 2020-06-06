#ifndef MPU9520__H
#define MPU9520__H

#include "interface/IMU.h"

#define ACC_X 0x3B
#define ACC_Y 0x3D
#define ACC_Z 0x3F
#define W_X 0x43
#define W_Y 0x45
#define W_Z 0x47
#define ACC_RANGE_ADD 0x21
#define W_RANGE_ADD 0xAB
#define ACC_RANGE_1000 0b01010001
#define W_RANGE_1000 0b01010001
#define IMU_ID_ADD 0x55
#define IMU_ID 0b00000000

class MPU9520 : public IMU{
    private:
        bool connection_state;
        int i2c_handle;
        int imu_i2c_address;
        int acc_range;
        int w_range;
        std::vector<double> vec;
        std::vector<int> address_to_read {ACC_X, ACC_Y, ACC_Z, W_X, W_Y, W_Z};

    public:
        MPU9520() = delete;
        MPU9520(int _imu_i2c_address);
        virtual std::vector<double> read_imu() override;
        virtual std::vector<double> read_acceleration() override;
        virtual std::vector<double> read_angular_velocity() override;
        virtual void open_connection() override;
        void set_acc_range();
        void set_w_range();
        void read_acc_range();
        void read_w_range();
        void check_id();
        bool is_connected();
};

#endif
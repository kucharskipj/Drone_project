#ifndef IMU__H
#define IMU__H

#include <vector>

class IMU{
    public:
        virtual std::vector<double> read_imu() = 0;
        virtual std::vector<double> read_acceleration() = 0;
        virtual std::vector<double> read_angular_velocity() = 0;
        virtual void open_connection() = 0;
};

#endif
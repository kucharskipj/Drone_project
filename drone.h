#ifndef DRONE__H
#define DRONE__H

#include "MPU9520.h"
#include "on_pins_4.h"
#include "battery_1S.h"
#include "web_socket.h"

class Drone{
    public:
        Drone() = delete;
        Drone(IMU* a, Motors* b, Control* c, Battery* d);
};

#endif
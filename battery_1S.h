#ifndef BATTERY_1S__H
#define BATTERY_1S__H

#include "interface/battery.h"

class Battery_1S : public Battery{
    public:
        virtual int read_battery_level();
};

#endif
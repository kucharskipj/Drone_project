#ifndef BATTERY__H
#define BATTERY__H

class Battery{
    public:
        virtual int read_battery_level() = 0;
};

#endif
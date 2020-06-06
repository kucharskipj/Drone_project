#ifndef CONTROL__H
#define CONTROLL__H

#include <vector>

class Control{
    public:
        virtual std::vector<double> read_controler() = 0;
};

#endif
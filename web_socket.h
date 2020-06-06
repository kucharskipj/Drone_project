#ifndef WEB_SOCKET__H
#define WEB_SOCKET__H

#include "interface/control.h"

class Web_socket : public Control{
    public:
        virtual std::vector<double> read_controler();
};

#endif
class IMU{
    public:
    int connection_state;
    virtual std::vector<double> read_IMU() = 0;
    virtual std::vector<double> read_acceleration() = 0;
    virtual std::vector<double> read_angular_velocity() = 0;
    virtual void open_connection() = 0;
};

class MPU9520 : public IMU{

    MPU9520(int _imu_i2c_address){
        //zainicjowanie połączenia przez I2C
        //jak nie udało sie ustawić połączenia i zidentyfikować czujnika to rzuć exception
    }
    virtual std::vector<double> read_IMU();
    virtual std::vector<double> read_acceleration();
    virtual std::vector<double> read_angular_velocity();
    virtual void open_connection();
    std::vector<double> read_magnetometer(){};

    void set_acc_range();
    void set_vel_range();
};

class Motors{
    virtual void change_motors_state() = 0;
};

class on_pins_4 : public Motors{
    on_pins_4(std::vector<int> pins_numbers){
        //tutaj inicjowanie połączenia z silnikami
    }
    virtual void change_motors_state();
};

class Control{
    virtual std::vector<double> read_controler() = 0;
};

class Web_socket : public Control{
    virtual std::vector<double> read_controler();
    std::void send_stream();
};

class Battery{
    int read_battery_level();
};


//sharepointer czy new? można wywołać bezpośrednio w wywołaniu obiektu?
class Drone{
    Drone() = delete;
    Drone(IMU* a, Motors* b, Control* c, Battery* d){
        //tutaj może wywołanie kolejnych konstruktorów, więc jak coś podrodze się wywali to tutaj
        
    };
};
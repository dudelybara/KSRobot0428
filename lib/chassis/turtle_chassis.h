#ifndef turtle_chassis
#define turtle_chassis

#include "Arduino.h"
#include "basic_chassis.h"

#define SAFE_DISTANCE 75 // distance to obstacle in centimeters 

class TurtleChassis : public BasicChassis {
    int speed = 200;
    int turn_delay = 300;
    public:
    void forward(unsigned long ms);
    void backward(unsigned long ms);
    void stop();
    void turn_right();
    void turn_left();
    void autonomous();
};

#endif // turtle_chassis
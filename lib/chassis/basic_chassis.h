#ifndef basic_chassis
#define basic_chassis

#include <Servo.h>
#include <Ultrasonic.h>
#include "ksr_pinout.h"

class BasicChassis {

    Servo echo_servo;
    Ultrasonic* sonic_sensor;
    public:
    BasicChassis() {
    pinMode(Pin::motor_rb_dir, OUTPUT);  
    pinMode(Pin::motor_la_dir, OUTPUT);
    // echo_servo.attach(Pin::servo);
    sonic_sensor = new Ultrasonic(Pin::ult_sonic_tr1g, Pin::ult_sonic_echo);
    Serial.write("1");
    }

    void set_servo(int degree){
        echo_servo.attach(Pin::servo);
        Serial.write(degree);
        int prev = echo_servo.read();
        echo_servo.write(degree);
        if (prev != degree)
            delay(100); // wait for servo to actually turn
    }

    unsigned int ping(){
        return sonic_sensor->read();
    }

    void r_motor(int dir, int speed){
        digitalWrite(Pin::motor_rb_dir, dir);      
        analogWrite(Pin::motor_rb_speed, speed);   // PWM regulate speed
    }

    void l_motor(int dir, int speed){
        digitalWrite(Pin::motor_la_dir, dir);      
        analogWrite(Pin::motor_la_speed, speed);   // PWM regulate speed
    }
};

#endif // basic_chassis
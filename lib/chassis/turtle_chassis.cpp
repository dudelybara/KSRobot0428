#include "turtle_chassis.h"

void TurtleChassis::forward(unsigned long ms){
    r_motor(1, speed);
    l_motor(1, speed);
    delay(ms);
    stop(); 
}
void TurtleChassis::backward(unsigned long ms){
    r_motor(0, speed);
    l_motor(0, speed);
    delay(ms);
    stop(); 
}
void TurtleChassis::stop(){
    r_motor(0, 0);
    l_motor(0, 0); 
}
void TurtleChassis::turn_right(){
    r_motor(1, speed);
    l_motor(0, speed);
    delay(turn_delay);
    stop();
}
void TurtleChassis::turn_left(){
    r_motor(0, speed);
    l_motor(1, speed);
    delay(turn_delay);
    stop();
}

void TurtleChassis::autonomous(){
    
    set_servo(90);
    if (ping() > SAFE_DISTANCE){
        forward(100);
        return;
    }
    set_servo(150);
    unsigned int d_left = ping();
    set_servo(30);
    unsigned int d_right = ping();

    if (d_right > d_left && d_right > SAFE_DISTANCE){
        turn_right();
        return;        
    }
    else if (d_left > SAFE_DISTANCE){
        turn_left();
        return;      
    }

    // better turn around -_-
    turn_right();
    turn_right();

    return;
}
#include "main.h"

pros::ADIDigitalIn limitSwitch (7);
void load(){
    if (!limitSwitch.get_value()){
        cata.move(100);
    } else {
        cata.move(0);
    }
}

void shoot(){
    cata.move(110);
}
#include "main.h"

pros::ADIDigitalIn limitSwitch (8);
void load(){
    if (!limitSwitch.get_value()){
        cata.move(100);
    } else {
        cata.move(0);
    }
}

void shoot(){
    cata.move(100);
}
#include "main.h"

pros::ADIDigitalIn limitSwitch (6);
void load(){
    if (!limitSwitch.get_value()){
        cata.move(127);
    } else {
        cata.move(0);
    }
}

void shoot(){
    cata.move(111);
}
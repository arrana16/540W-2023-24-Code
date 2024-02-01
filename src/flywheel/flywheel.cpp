#include "main.h"
PID flyWheelPID(200, 0, 0, false, 0);
PID autonflyWheelPID(4, 0, 0, false, 0);
pros::Motor flywheel(15);

double change = 0;
int vol = 0;

void flyWheelSpin(double rpm) {
    change = flyWheelPID.calculate(rpm/5, flywheel.get_actual_velocity());
    change += rpm*4.48;

    if (change>11999) {
        change = 11999;
    }

    flywheel.move_voltage(change);
}

void flyWheelStop() {
    flywheel.move_voltage(0);
}
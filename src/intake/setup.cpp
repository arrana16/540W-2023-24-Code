#include "main.h"

pros::Motor intake1
(20, pros::E_MOTOR_GEARSET_18, true);

void moveForward() {
    intake1.move_velocity(200);
}

void moveBackward() {
    intake1.move_velocity(-200);
}
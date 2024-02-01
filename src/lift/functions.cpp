#include "main.h"

void liftMove(int angle) {
    liftMotors.move(liftPID.calculate(angle, liftRot.get_angle()/100));
};
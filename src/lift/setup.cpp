#include "main.h"

pros::Motor_Group liftMotors({l3, r3});
pros::Rotation liftRot(4, false);
PID liftPID(10, 0, 10, false, 0);
#include "main.h"
#include "pros/adi.hpp"

double WHEELTRACK = 30;
double MAXLINVEL = 76.576;
double MAXANGVEL = 7;
double WHEEL_DIAMETER = 3.25;

pros::Controller cont(pros::E_CONTROLLER_MASTER);
pros::ADIMotor LED(8);
#include "main.h"

double WHEELTRACK = 30;
double MAXLINVEL = 76.576;
double MAXANGVEL = 7;
double WHEEL_DIAMETER = 3.25;

pros::Controller cont(pros::E_CONTROLLER_MASTER);
pros::ADIDigitalOut wings(5, false);
pros::ADIDigitalOut lift(6, false);
pros::ADIDigitalOut vWing(4, false);
pros::ADIDigitalOut LED(8, true);
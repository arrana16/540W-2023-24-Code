#include "main.h"

void setVels(int linVel, int angVel) {
    int leftVel = linVel - (angVel*WHEELTRACK/2);
    int rightVel = linVel - (angVel*WHEELTRACK/2);

    left_side_motors.move_velocity(leftVel/MAXLINVEL*600);
    right_side_motors.move_velocity(leftVel/MAXLINVEL*600);

    /*
    left_side_motors.move_voltage(leftSidePID.calculate(leftVel, left_side_motors.get_actual_velocities().at(0)));
    right_side_motors.move_voltage(rightSidePID.calculate(leftVel, right_side_motors.get_actual_velocities().at(0)));
    */
};

void simpleDrive(int y, int turn) {
    left_side_motors.move(y + turn);
    right_side_motors.move(y - turn);
}
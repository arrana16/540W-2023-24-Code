#include "lemlib/chassis/chassis.hpp"
#include "main.h"
#include "lemlib/api.hpp"

pros::Motor l1(1, pros::E_MOTOR_GEARSET_18, false);
pros::Motor r1(2, pros::E_MOTOR_GEARSET_18, false);

pros::MotorGroup left_side_motors({l1});
pros::MotorGroup right_side_motors({r1});

lemlib::Drivetrain_t drivetrain {
    &left_side_motors,
    &right_side_motors,
    10,
    4,
    200
};

lemlib::Chassis chassis();
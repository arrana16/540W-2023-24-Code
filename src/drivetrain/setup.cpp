#include "main.h"


PID leftSidePID(2, 0,0, false, 0);
PID rightSidePID(2, 0,0, false, 0);

pros::Motor l1(1, pros::E_MOTOR_GEARSET_18, true);
pros::Motor l2(4, pros::E_MOTOR_GEARSET_18, true);
pros::Motor l3(5, pros::E_MOTOR_GEARSET_18, false);

pros::Motor r1(6, pros::E_MOTOR_GEARSET_18, false);
pros::Motor r2(7, pros::E_MOTOR_GEARSET_18, false);
pros::Motor r3(8, pros::E_MOTOR_GEARSET_18, true);

pros::MotorGroup left_side_motors({l1, l2, l3});
pros::MotorGroup right_side_motors({r1, r2, r3});

lemlib::Drivetrain_t drivetrain {
    &left_side_motors,
    &right_side_motors,
    10,
    4,
    200
};

lemlib::OdomSensors_t sensors {
};
lemlib::ChassisController_t lateralController {
    8, // kP
    30, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    5 // slew rate
};
 
// turning PID
lemlib::ChassisController_t angularController {
    4, // kP
    40, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    0 // slew rate
};

lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);
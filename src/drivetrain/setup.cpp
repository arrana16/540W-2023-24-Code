#include "main.h"

// Create PID objects for left and right side feedback
PID leftSideFeedback(0, 0, 0, false, 0);
PID rightSideFeedback(0, 0, 0, false, 0);

// Create motor objects for the left side
pros::Motor l1(11, pros::E_MOTOR_GEARSET_18, true);
pros::Motor l2(12, pros::E_MOTOR_GEARSET_18, true);
pros::Motor l3(13, pros::E_MOTOR_GEARSET_18, true);

// Create motor objects for the right side
pros::Motor r1(18, pros::E_MOTOR_GEARSET_18, false);
pros::Motor r2(19, pros::E_MOTOR_GEARSET_18, false);
pros::Motor r3(20, pros::E_MOTOR_GEARSET_18, false);

// Create motor groups for the left and right side motors
pros::MotorGroup left_side_motors({l1, l2, l3});
pros::MotorGroup right_side_motors({r1, r2, r3});

// Create motor groups for the left and right PTO (Power Take-Off) motors
pros::MotorGroup left_PTO({l1, l2});
pros::MotorGroup right_PTO({r1, r2});

// Create an ADIEncoder object for x and y axis (commented out)
// pros::ADIEncoder xEnc(1, 2, true);
// pros::ADIEncoder yEnc(3, 4, true);

// Create an Imu object for inertial sensor
pros::Imu inertial_seonsor(6);

// Create TrackingWheel objects for left and right side encoders
lemlib::TrackingWheel left_side_enc(&left_side_motors, 3.25, -5.5, 450);
lemlib::TrackingWheel right_side_enc(&right_side_motors, 3.25, 5.5, 450);

// Create a Drivetrain_t object with the necessary components
lemlib::Drivetrain_t drivetrain {
    &left_side_motors,
    &right_side_motors,
    10.5, // wheelbase
    3.25, // wheel radius
    450 // ticks per revolution
};

// Create an OdomSensors_t object with the necessary components
lemlib::OdomSensors_t sensors {
    &left_side_enc,
    &right_side_enc,
    nullptr, // x encoder (commented out)
    nullptr, // y encoder (commented out)
    &inertial_seonsor
};

// Create a ChassisController_t object for lateral control
lemlib::ChassisController_t lateralController {
    4.7, // kP
    20, // kD
    0.05, // smallErrorRange
    400, // smallErrorTimeout
    0.3, // largeErrorRange
    500, // largeErrorTimeout
    2.5 // slew rate
};

// Create a ChassisController_t object for angular control (turning)
lemlib::ChassisController_t angularController {
    7.9, // kP
    90, // kD
    1.5, // smallErrorRange
    600, // smallErrorTimeout
    3, // largeErrorRange
    800, // largeErrorTimeout
    10 // slew rate
};

// Create a Chassis object with the necessary components
lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);
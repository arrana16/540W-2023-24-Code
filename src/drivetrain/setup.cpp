#include "main.h"


PID leftSidePID(2, 0,0, false, 0);
PID rightSidePID(2, 0,0, false, 0);

pros::Motor l1(14, pros::E_MOTOR_GEARSET_18, true);
pros::Motor l2(15, pros::E_MOTOR_GEARSET_18, true);
pros::Motor l3(16, pros::E_MOTOR_GEARSET_18, false);

pros::Motor r1(17, pros::E_MOTOR_GEARSET_18, false);
pros::Motor r2(18, pros::E_MOTOR_GEARSET_18, false);
pros::Motor r3(19, pros::E_MOTOR_GEARSET_18, true);

pros::MotorGroup left_side_motors({l1, l2, l3});
pros::MotorGroup right_side_motors({r1, r2, r3});

pros::ADIEncoder xEnc(1, 2, true);
pros::ADIEncoder yEnc(3, 4, true);
pros::Imu inertial_seonsor(11);

lemlib::TrackingWheel left_side_enc(&left_side_motors, 3.25, -5.5, 450);
lemlib::TrackingWheel right_side_enc(&right_side_motors, 3.25, 5.5, 450);

lemlib::Drivetrain_t drivetrain {
    &left_side_motors,
    &right_side_motors,
    10,
    3.25,
    450
};

lemlib::OdomSensors_t sensors {
    &left_side_enc,
    &right_side_enc,
    nullptr,
    nullptr,
    &inertial_seonsor

};
lemlib::ChassisController_t lateralController {
    3.5, // kP
    0, // kD
    0.05, // smallErrorRange
    400, // smallErrorTimeout
    0.3, // largeErrorRange
    500, // largeErrorTimeout
    2.5 // slew rate
};
 
// turning PID
lemlib::ChassisController_t angularController {
    3.3, // kP
    30, // kD
    0.5, // smallErrorRange
    3000, // smallErrorTimeout
    3, // largeErrorRange
    5000, // largeErrorTimeout
    0 // slew rate
};

lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);
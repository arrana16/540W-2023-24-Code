#include "main.h"


PID leftSideFeedback(0, 0,0, false, 0);
PID rightSideFeedback(0, 0,0, false, 0);


pros::Motor l1(20, pros::E_MOTOR_GEARSET_18, true);
pros::Motor l2(19, pros::E_MOTOR_GEARSET_18, true);
pros::Motor l3(18, pros::E_MOTOR_GEARSET_18, false);

pros::Motor r1(11, pros::E_MOTOR_GEARSET_18, false);
pros::Motor r2(12, pros::E_MOTOR_GEARSET_18, false);
pros::Motor r3(13, pros::E_MOTOR_GEARSET_18, true);

pros::MotorGroup left_side_motors({l1, l2, l3});
pros::MotorGroup right_side_motors({r1, r2, r3});

pros::MotorGroup left_PTO({l1 ,l2});
pros::MotorGroup right_PTO({r1, r2});

// pros::ADIEncoder xEnc(1, 2, true);
// pros::ADIEncoder yEnc(3, 4, true);
pros::Imu inertial_seonsor(6);

lemlib::TrackingWheel left_side_enc(&left_side_motors, 3.25, -5.5, 450);
lemlib::TrackingWheel right_side_enc(&right_side_motors, 3.25, 5.5, 450);

lemlib::Drivetrain_t drivetrain {
    &left_side_motors,
    &right_side_motors,
    10.5,
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
    4.7, // kP
    20, // kD
    0.05, // smallErrorRange
    400, // smallErrorTimeout
    0.3, // largeErrorRange
    500, // largeErrorTimeout
    2.5 // slew rate
};
 
// turning PID
lemlib::ChassisController_t angularController {
    7.9, // kP
    90, // kD
    1.5, // smallErrorRange
    600, // smallErrorTimeout
    3, // largeErrorRange
    800, // largeErrorTimeout
    10 // slew rate
};

lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);
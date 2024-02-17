// Include necessary header file
#include "main.h"

// Define PID controllers for flywheel
PID flyWheelPID(200, 0, 0, false, 0);
PID autonflyWheelPID(4, 0, 0, false, 0);

// Declare flywheel motor
pros::Motor flywheel(15);

// Declare variables
double change = 0;
int vol = 0;

// Function to spin the flywheel at a desired RPM
void flyWheelSpin(double rpm) {
    // Calculate the change in voltage using PID controller
    change = flyWheelPID.calculate(rpm/5, flywheel.get_actual_velocity());
    change += rpm*4.48;

    // Limit the maximum change in voltage to 11999
    if (change > 11999) {
        change = 11999;
    }

    // Apply the calculated voltage change to the flywheel motor
    flywheel.move_voltage(change);
}

// Function to stop the flywheel
void flyWheelStop() {
    // Set the voltage of the flywheel motor to 0
    flywheel.move_voltage(0);
}
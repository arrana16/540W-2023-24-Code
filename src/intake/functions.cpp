// This file contains the implementation of intake functions.

#include "main.h"

// Function to intake the object
void intake() {
    intake1.move(127);
}

// Function to outtake the object
void outtake() {
    intake1.move(-127);
}

// Function to possess the object
void possess() {
    intake1.move(50);
}

// Function to hold the intake
void hold() {
    intake1.move(0);
}

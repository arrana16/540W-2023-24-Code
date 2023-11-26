#include "main.h"

void skills() {
    pros::ADIDigitalOut wings(7);

	chassis.setPose(25.2, 12, -120);
	
    cata.move(100);

    pros::delay(30000);
    cata.move(0);
	chassis.moveTo(30.4, 13, 2000, 70);
	chassis.moveTo(42, 6, 2000, 70);

	//chassis.turnTo(90, 0, 6000, false, 70);
	chassis.moveTo(110, 6, 2000, 90);

	chassis.moveTo(110, 33, 2000, 90);
	chassis.moveTo(85, 72, 2000, 90);
	chassis.turnTo(chassis.getPose().x+26, chassis.getPose().y, 2000, false, 90);
	simpleDrive(-100, 0);
	pros::delay(500);
	simpleDrive(0, 0);
	chassis.setPose(82, 72, 90);
	wings.set_value(true);
	chassis.moveTo(112, 72, 2000, 120);
}

void right_side_auto(){
    pros::ADIDigitalOut wings(7);
    chassis.setPose(112.5, 8.5, 0);

    chassis.moveTo(112.5, 19, 1100, 150);
    chassis.turnTo(130, 34, 700, false, 80);
    chassis.moveTo(130, 34, 800, 80, false);
    chassis.turnTo(130, 60, 600, false, 80);
    outtake();
    pros::delay(700);
    simpleDrive(100, 0);
    pros::delay(280);
    simpleDrive(-100, 0);
    pros::delay(150);
    simpleDrive(0,0);
    chassis.turnTo(chassis.getPose().x-30, chassis.getPose().y, 700, false, 80);
    simpleDrive(-50, 0);
    pros::delay(500);
    simpleDrive(0,0);

    chassis.setPose(136.5, 33, -90);
    intake1.move(60);
    chassis.moveTo(77, 40.5, 2000, 100);
    intake1.move(0);
    chassis.moveTo(97.4, 38.4, 700, 80);
    chassis.turnTo(120, 72, 500, false, 80);
    outtake();
    pros::delay(400);
    intake1.move(60);
    chassis.moveTo(77, 61, 1000, 80);
    pros::delay(400);
    intake1.move(0);
    chassis.moveTo(82, 72, 200, 80);

    chassis.turnTo(chassis.getPose().x+80, chassis.getPose().y, 2000, false, 70);
    outtake();
    wings.set_value(true);
    pros::delay(300);
    simpleDrive(90,0);
    pros::delay(800);
    simpleDrive(-30,0);
    pros::delay(100);
    simpleDrive(0,0);

}

void left_side_auto(){
    pros::ADIDigitalOut wings(7);

    chassis.setPose(31.5, 10.5, 180);
    chassis.moveTo(31.5, 19, 1100, 100);

    chassis.turnTo(14, 34, 700, false, 80);
    chassis.moveTo(14, 34, 800, 80, false);
    chassis.turnTo(14, 60, 400, false, 80);
    outtake();

    pros::delay(200);
    simpleDrive(100, 0);
    pros::delay(280);
    simpleDrive(-100, 0);
    pros::delay(150);
    simpleDrive(0,0);
    chassis.turnTo(chassis.getPose().x+30, chassis.getPose().y, 700, false, 80);
    simpleDrive(-50, 0);
    pros::delay(500);
    simpleDrive(0,0);

    chassis.setPose(7.5, 33, -90);
    chassis.moveTo(20.4, 16, 800, 100);
    wings.set_value(true);
    chassis.turnTo(20.4, 50, 500, false, 80);

}

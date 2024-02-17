#include "main.h"
#include "okapi/api/control/util/flywheelSimulator.hpp"

void skills() {
    LED.set_value(255);
    pros::Task task{[=] {
			intake1.move(-30);
			pros::delay(400);
			hold();
            while (true){
                flyWheelSpin(-2750);
            }
    }};
    chassis.setPose(38, 10, 0);
    chassis.moveTo(9 ,32, 1300, 200);
    chassis.turnTo(9, 90, 1000, false, 100);
    outtake();
    simpleDrive(127, 0);
    pros::delay(500);
    simpleDrive(0, 0);

    chassis.moveTo(14, 32, 1000, 200);
    chassis.turnTo(144, 72, 500, false, 100);
    simpleDrive(-50,0);
    pros::delay(800);
    simpleDrive(0,0);


    //chassis.setPose(11, 32, chassis.getPose().theta, false);
    pros::delay(200);


    pros::delay(30000);

    
    simpleDrive(50, 0);
    pros::delay(450);
    simpleDrive(0,0);
    chassis.moveTo(36, 16, 1500, 200);
    chassis.turnTo(109, 17, 500, true, 100);
    chassis.moveTo(109, 17, 2500, 200);
    chassis.turnTo(133, 44, 800, true, 100);
    simpleDrive(-127, 0);
    pros::delay(700);
    simpleDrive(45, 0);
    pros::delay(250);
    simpleDrive(-127, 0);
    pros::delay(500);
    simpleDrive(0,0);

    chassis.setPose(134, 38, chassis.getPose().theta, false);
    chassis.moveTo(129, 32, 1000, 150);
    /*

    chassis.moveTo(109, 33, 1500, 200);
    chassis.moveTo(77, 72, 800, 200);
    */
    chassis.moveTo(86, 32, 2000, 200);
    chassis.moveTo(76, 72, 1400, 200);
    chassis.turnTo(144, 80, 1100);
    // wings.set_value(true); 
    simpleDrive(127, 0);
    
    /*
    wings.set_value(true);
    simpleDrive(127, 0);
    pros::delay(1500);
    simpleDrive(-50, 0);
    pros::delay(300);
    wings.set_value(false);
    simpleDrive(0,0);
    chassis.turnTo(1000, chassis.getPose().y, 500, false, 100);
    simpleDrive(-100, 0);
    pros::delay(400);
    simpleDrive(0, 0);

    chassis.setPose(84, 64, 0, false);
    chassis.moveTo(90, 90, 1000, 200);

    chassis.turnTo(144, 72, 500, false, 100);
    wings.set_value(true);
    simpleDrive(127, 0);
    pros::delay(1500);
    simpleDrive(-30, 0);
    pros::delay(200);
    simpleDrive(0,0);
    wings.set_value(false);
    */
    

}

void far_side_auto(){
    LED.set_value(255);
    pros::Task task{[=] {
			intake1.move(-30);
			pros::delay(400);
			hold();
    }};
    
	chassis.setPose(108, 12, 0);
	chassis.moveTo(104, 57, 1200, 200);
	pros::delay(50);
	hold();
	chassis.turnTo(10000, 57, 600, false, 100);
    outtake();;
    pros::delay(300);
    intake();
    chassis.turnTo(97, 72, 350, false, 100);
    chassis.moveTo(97, 72, 800, 100);
    chassis.turnTo(10000, 72, 600, false, 100);
	outtake();
    
	pros::delay(150);
	chassis.turnTo(80, 75, 600, false, 100);
	intake1.move(100);
	chassis.moveTo(74, 75, 750, 200);
    pros::delay(150);
	hold();
	chassis.turnTo(10000, 80, 800, false, 100);
    pros::delay(80);
	outtake();
	pros::delay(150);
    // wings.set_value(true);
    chassis.moveTo(300, 80, 900,200);
    // wings.set_value(false);
	chassis.setPose(114, 80, chassis.getPose().theta);
	chassis.moveTo(100, 80, 700, 150);
	chassis.turnTo(82, 60, 450, false, 100);
	intake();
	chassis.moveTo(82, 60, 900, 170);
	pros::delay(300);
	simpleDrive(-100, 0);
	pros::delay(450);
	simpleDrive(0, 0);
	chassis.turnTo(10000, chassis.getPose().y, 600, false, 100);
	outtake();
	pros::delay(150);
	simpleDrive(110, 0);
	pros::delay(700);
	simpleDrive(0, 0);

	
	chassis.setPose(111, 72, chassis.getPose().theta, false);
	chassis.moveTo(100, 72, 500, 100);
	chassis.moveTo(105, 14, 1750, 200);
    intake();
	chassis.turnTo(76.5, 14, 550, false, 100);
	chassis.moveTo(86, 12, 1100, 200);
	pros::delay(100);
	hold();
    
    /*
	chassis.moveTo(110, 15, 1000, 200);
	chassis.turnTo(140, 60, 650, false, 100);
	chassis.moveTo(130, 35, 950, 200);
	chassis.turnTo(132, 80, 200, false, 100);
	outtake();
	pros::delay(200);
	simpleDrive(127, 0);
	*/

}

void close_side_auto(){
    chassis.setPose(31.5, 8.5, 0);
    LED.set_value(true);
    outtake();
    pros::delay(250);
    hold();

    chassis.moveTo(31.5, 19, 1100, 100);

    chassis.turnTo(10, 34, 700, false, 80);
    chassis.moveTo(10, 34, 800, 80, false);
    chassis.turnTo(10, 60, 400, false, 80);
    outtake();

    pros::delay(350);
    simpleDrive(127, 0);
    pros::delay(600);
    simpleDrive(-80,0);
    pros::delay(300);
    simpleDrive(0,0);
    chassis.turnTo(1000, chassis.getPose().y, 500, false, 80);
    simpleDrive(-100, 0);
    pros::delay(700);
    simpleDrive(0, 0);
    chassis.setPose(7.5, 37, 90);
    chassis.moveTo(24, 18, 800, 100);
    // vWing.set_value(true); 
    chassis.turnTo(50, 50, 500, false, 80);
    // vWing.set_value(false);
    pros::delay(1000);
    chassis.moveTo(35, 16, 2000, 90);   
    outtake();
    chassis.moveTo(56, 16, 1000, 100);
    pros::delay(300);

    /*
    pros::delay(200);
    simpleDrive(0,0);
    chassis.turnTo(chassis.getPose().x+30, chassis.getPose().y, 700, false, 80);
    simpleDrive(-35, 0);
    pros::delay(850);
    simpleDrive(0,0);

    chassis.setPose(7.5, 33, 90);
    chassis.moveTo(26, 16, 800, 100);
    wings.set_value(true);
    pros::delay(300);
    chassis.turnTo(50, 16, 500, false, 80);
    wings.set_value(false);
    pros::delay(300);
    chassis.moveTo(35, 4, 800, 80, false);
    chassis.turnTo(100, 4, 500, true, 80);
    chassis.moveTo(69, 4, 2500, 40);
    */

}

void driverSkills() {
    LED.set_value(255);
    pros::Task task{[=] {
			intake1.move(-30);
			pros::delay(400);
			hold();
            while (true){
                flyWheelSpin(-2750);
            }
    }};
    chassis.setPose(38, 10, 0);
    chassis.moveTo(9 ,32, 1300, 200);
    chassis.turnTo(9, 90, 1000, false, 100);
    outtake();
    simpleDrive(127, 0);
    pros::delay(500);
    simpleDrive(0, 0);

    chassis.moveTo(14, 32, 1000, 200);
    chassis.turnTo(144, 72, 500, false, 100);
    simpleDrive(-50,0);
    pros::delay(800);
    simpleDrive(0,0);
}
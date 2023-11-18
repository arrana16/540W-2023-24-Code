#include "main.h"
#include "pros/misc.h"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);
	//autonomous();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	/*
	pros::ADIDigitalOut wings(8);

	chassis.calibrate();
	chassis.setPose(25.2, 12, -120);
	
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
	*/
	
	
	/*
	pros::delay(500);
	while (true){
		cata.move(95);
	}
	*/

}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);

	int lasty= 0 ;
	int limit = 10;
	double yexp = 2.12;
	double rotexp = 3.8;

	pros::Imu inertial_seonsor(11);
	pros::ADIDigitalOut wings(8);

	while (true) {
		lemlib::Pose pose = chassis.getPose(); // get the current position of the robot
        pros::lcd::print(0, "x: %f", pose.x); // print the x position
        pros::lcd::print(1, "y: %f", pose.y); // print the y position
        pros::lcd::print(2, "heading: %f", pose.theta);
        pros::lcd::print(3, "heading: %f", inertial_seonsor.get_heading());

		int left = master.get_analog(ANALOG_LEFT_Y);
		int right = master.get_analog(ANALOG_RIGHT_Y);

		int y = cont.get_analog(ANALOG_LEFT_Y);
        int rot = cont.get_analog(ANALOG_RIGHT_X);
		
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
			intake();
		} else {
			hold();
		}

		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
			outtake();
		} else if (!master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
			hold();
		};


		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)){
			hold();
		};

		if (!master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
			load();
		}

		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
			shoot();
		};

		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A)){
			wings.set_value(true);
		} if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)){
			wings.set_value(false);
		}

		

		if (y>=0){
			y=(pow(y, yexp)*127)/pow(127, yexp);
		} else {
			y=(pow(abs(y), yexp)*-127)/pow(127, yexp);
		}

		if (rot>=0){
			rot=(pow(rot, rotexp)*127)/pow(127, rotexp);
		} else {
			rot=(pow(abs(rot), rotexp)*-127)/pow(127, rotexp);
		}

		if (y-lasty>limit) {
			y=lasty+limit;
		} else if (y-lasty<-1*limit) {
			y=lasty-limit;
		}
		
		if (rot>90){
			rot=90;
		} else if (rot<-90){
			rot=-90;
		}

		if (y>110){
			y=110;
		} else if (y<-110){
			y=-110;
		}
		if (y>-3&&y<3) {
			y=y-abs(rot)*0.2;
		}
		simpleDrive(y, rot);

		lasty = y;
		pros::delay(20);
	}
}

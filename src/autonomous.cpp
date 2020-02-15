//Include necessary headers
#include "main.h"
#include "subsystem_headers/globals.hpp"
#include "subsystem_headers/drive.hpp"
#include "subsystem_headers/intake.hpp"
#include "subsystem_headers/angler.hpp"
#include "subsystem_headers/arm.hpp"

//Helper functions
void tray_deploy(void) {
    arm_aut(ARM_TOWER_2, 200, false);
    arm_aut(0, 200, false);
}

//Autons
void auton_red(void) {

}

void auton_blue(void) {
}

void auton_one_point(void) {
    drive_aut_simple("DRIVE", -24, false);
    drive_aut_simple("DRIVE", 24, false);
    tray_deploy();
}

void auton_skills(void) {

}

void auton_test(void) {
    drive_aut_path("TEST_AUT_CURVE", false, false, false);
    drive_aut_path("TEST_AUT_CURVE", true, false, false);
    drive_aut_path("TEST_AUT_DRIVE", false, false, false);
    drive_aut_path("TEST_AUT_DRIVE", true, false, false);
    drive_aut_path("TEST_AUT_PIVOT", false, false, false);
    drive_aut_path("TEST_AUT_PIVOT", true, false, false);
}

//Main callback for autonomous routine
void autonomous(void) {
    if (sel_auton == possible_autons.at(0)) {
        auton_red();
    } else if (sel_auton == possible_autons.at(1)) {
        auton_blue();
    } else if (sel_auton == possible_autons.at(2)) {
        auton_one_point();
    } else if (sel_auton == possible_autons.at(3)) {
        auton_skills();
    } else if (sel_auton == possible_autons.at(4)) {
        auton_test();
    }
}
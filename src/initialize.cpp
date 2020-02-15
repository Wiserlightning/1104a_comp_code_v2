//Include necessary headers
#include "main.h"
#include "subsystem_headers/globals.hpp"
#include "subsystem_headers/globals_pros.hpp"
#include "subsystem_headers/drive.hpp"

//Important variables
unsigned cur_obj;

//Helper Functions
void auton_selection(void) {
    cur_obj = 0;
    pros::lcd::print(0, "Auton Selector v1.12.2snap_234f2");
    pros::lcd::print(1, "[LEFT] and [RIGHT] to scroll.");
    pros::lcd::print(2, "[CENTER] to select.");
    while (true) {
        pros::lcd::print(3, "SELECTED AUTON: %s", possible_autons.at(cur_obj));
        if (pros::lcd::read_buttons() == LCD_BTN_LEFT) {
            if (cur_obj == 0) {
                pros::lcd::print(4, "ERROR: UNDERFLOW ERR");
                pros::delay(1000);
                pros::lcd::clear_line(4);
            } else {
                cur_obj--;
                pros::delay(500);
            }
        } else if (pros::lcd::read_buttons() == LCD_BTN_RIGHT) {
            if (cur_obj == num_of_autons) {
                pros::lcd::print(4, "ERROR: OVERFLOW ERR");
                pros::delay(1000);
                pros::lcd::clear_line(4);
            } else {
                cur_obj++;
                pros::delay(500);
            }
        } else if (pros::lcd::read_buttons() == LCD_BTN_CENTER) {
            sel_auton = possible_autons.at(cur_obj);
            pros::lcd::clear_line(3);
            pros::lcd::print(3, "AUTON SELECTED");
            pros::delay(500);
            pros::lcd::clear_line(3);
            pros::lcd::clear_line(4);
            break;
        }
        pros::delay(5);
    }

    pros::lcd::print(4, "FINAL AUTON: %s", sel_auton);
    pros::delay(2000);
    pros::delay(1000);
    pros::lcd::shutdown();
}

void pre_init(void) {
    pros::lcd::initialize();
    pros::delay(1000);

    pros::lcd::print(0, "SETTING ZEROES...");
    arm.set_brake_mode(BRAKE_HOLD);
    angler.set_brake_mode(BRAKE_HOLD);
    arm.move_velocity(-200);
    angler.move_velocity(-200);
    pros::delay(1000);
    arm.move_velocity(0);
    angler.move_velocity(0);
    arm.tare_position();
    angler.tare_position();

    pros::lcd::print(0, "ZEROES SET.");
    pros::lcd::print(1, "PRE-INIT COMPLETE");
    pros::delay(1000);
    pros::lcd::clear();
}

//Main callback for initialization
void initialize(void) {
    pre_init();
    auton_selection();
    drive_aut_gen_paths();
}
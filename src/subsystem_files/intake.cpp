#include "subsystem_headers\globals_pros.hpp"
#include "subsystem_headers\intake.hpp"

using namespace pros;

//Helper functions
void set_intake_velocity(int intake_velocity) {
    intake_left.set_brake_mode(BRAKE_HOLD);
    intake_right.set_brake_mode(BRAKE_HOLD);
    intake_left.move_velocity(intake_velocity);
    intake_right.move_velocity(intake_velocity);
}

void set_intake_brake_mode(motor_brake_mode_e intake_brake) {
    intake_left.set_brake_mode(intake_brake);
    intake_right.set_brake_mode(intake_brake);
}

//Main functions
void intake_op(void) {
    set_intake_brake_mode(BRAKE_HOLD);
    if (master_controller.get_digital(BUTTON_R1) == true && master_controller.get_digital(BUTTON_R2) == true) {
        set_intake_velocity(-200);
    } else if (master_controller.get_digital(BUTTON_R1)) {
        set_intake_velocity(200);
    }else if (master_controller.get_digital(BUTTON_R2)) {
        if (arm.get_position() > 300) {
            set_intake_velocity(-75);
        } else {
            set_intake_velocity(-200);
        }
    } else {
        set_intake_velocity(0);
    }
}

void intake_aut(int intake_aut_velocity) {
    set_intake_velocity(intake_aut_velocity);
}
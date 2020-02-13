#include "subsystem_headers\globals_pros.hpp"
#include "subsystem_headers\intake.hpp"

//Helper functions
void set_intake_velocity(int intake_velocity) {
    intake_left.set_brake_mode(BRAKE_HOLD);
    intake_right.set_brake_mode(BRAKE_HOLD);
    intake_left.move_velocity(intake_velocity);
    intake_right.move_velocity(intake_velocity);
}

//Main functions
void intake_op(void) {
    if (master_controller.get_digital(BUTTON_R1) || master_controller.get_digital(BUTTON_R2)) {
        if (arm.get_position() > 300) {
            set_intake_velocity(-75);
        } else {
            set_intake_velocity(200 * (master_controller.get_digital(BUTTON_R1) - master_controller.get_digital(BUTTON_R2)));
        }
    } else if (master_controller.get_digital(BUTTON_R1) && master_controller.get_digital(BUTTON_R2)) {
        set_intake_velocity(-200);
    }
}

void intake_aut(int intake_aut_velocity) {
    set_intake_velocity(intake_aut_velocity);
}
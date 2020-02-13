#include "subsystem_headers\globals_pros.hpp"
#include "subsystem_headers\arm.hpp"
#include "subsystem_headers\tray.hpp"

using namespace pros;

//Helper FUNCS.
void set_arm_vel(int vel_arm){
    arm.move_velocity(vel_arm);
}

void set_arm_aut(float dist_arm, int vel_arm) {
    arm.move_absolute(dist_arm, vel_arm);
}

void set_arm_brke(motor_brake_mode_e_t brke_arm) {
    arm.set_brake_mode(brke_arm);
}


//MAIN FUNCS.
void arm_op(void) {
    set_arm_brke(BRAKE_HOLD);
    if (master_controller.get_digital(BUTTON_L1) || (master_controller.get_digital(BUTTON_L2))) {
        set_arm_vel(200 * (master_controller.get_digital(BUTTON_L1) - master_controller.get_digital(BUTTON_L2)));
    } else if (master_controller.get_digital(BUTTON_RIGHT)) {
        set_arm_aut(ARM_TOW1, 200); //we have to still define ARM_TOW1
    } else if (master_controller.get_digital(BUTTON_UP)) {
        set_arm_aut(ARM_TOW2, 200); //we have to still define ARM_TOW2
    } else {
        set_arm_vel(0);
    }   
}

void arm_aut(float dist_arm, int vel_arm, bool async_arm) {
    set_arm_brke(BRAKE_HOLD);
    set_arm_aut(dist_arm, vel_arm);
    if (async_arm == false) {
        while (!(arm.get_position() < (dist_arm + 5) && (arm.get_position() > (dist_arm - 5)))) {
            delay(1);
        }
    }
}

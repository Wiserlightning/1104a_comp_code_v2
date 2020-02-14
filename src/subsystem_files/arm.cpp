#include "subsystem_headers\globals_pros.hpp"
#include "subsystem_headers\globals.hpp"
#include "subsystem_headers\arm.hpp"

int arm_mode;

using namespace pros;

//MAIN FUNCS.
void arm_op(void) {
    arm.set_brake_mode(BRAKE_HOLD);
    if (master_controller.get_digital(BUTTON_L1) || (master_controller.get_digital(BUTTON_L2))) {
        arm.move_velocity(200 * (master_controller.get_digital(BUTTON_L1) - master_controller.get_digital(BUTTON_L2)));
    } else if (master_controller.get_digital(BUTTON_RIGHT)) {
        arm.move_absolute(ARM_TOWER_1, 200);
    } else if (master_controller.get_digital(BUTTON_UP)) {
        arm.move_absolute(ARM_TOWER_2, 200);
    } else {
        arm.move_velocity(0);
    }
}

void arm_aut(float dist_arm, int vel_arm, bool async_arm) {
    arm.set_brake_mode(BRAKE_HOLD);
    arm.move_absolute(dist_arm, vel_arm);
    if (async_arm == false) {
        while (!(arm.get_position() < (dist_arm + 5) && (arm.get_position() > (dist_arm - 5)))) {
            delay(1);
        }
    }
}

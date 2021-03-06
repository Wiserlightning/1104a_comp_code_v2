#include "subsystem_headers\angler.hpp"
#include "subsystem_headers\globals.hpp"
#include "subsystem_headers\globals_pros.hpp"

int mode_angler = 0;

using namespace pros;

//MAIN FUNCS.
void angler_op(void) {
    int vel_angler;
    if (master_controller.get_analog(JOY_LY) > 0) {
        vel_angler = std::ceil((-0.018 * angler.get_position()) + 60);
    } else if (master_controller.get_analog(JOY_LY) < 0) {
        vel_angler = -100;
    } else {
        vel_angler = 0;
    }

    angler.set_brake_mode(BRAKE_HOLD);
    angler.move_velocity(vel_angler);
}


void angler_aut(int stack_angler) {
    angler.set_brake_mode(BRAKE_HOLD);
    switch (stack_angler) {
        case 0:
            angler.move_velocity(0);
            break;
        case 1:
            while (!(angler.get_position() < (ANGLER_STACK + 5) && (angler.get_position() > (ANGLER_STACK - 5)))) {
                angler.move_velocity(std::ceil((-0.018 * angler.get_position()) + 60));
                delay(1);
            }
            break;
        case 2:
            while (!(angler.get_position() < (ANGLER_STACK + 5) && (angler.get_position() > (ANGLER_STACK - 5)))) {
                angler.move_velocity(-100);
                delay(1);
            }
            break;
    };
}

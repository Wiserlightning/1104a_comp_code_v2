#include "subsystem_headers\angler.hpp"
#include "subsystem_headers\globals_pros.hpp"

int mode_angler = 0;

using namespace pros;

//HELPER FUNCS.
void set_angler_velocity(int vel_angler){
    angler.move_velocity(vel_angler);
}

void set_angler_aut(float dist_angler, int vel_angler) {
    angler.move_absolute(dist_angler, vel_angler);
}

void set_angler_brake(motor_brake_mode_e brke_angler) {
    angler.set_brake_mode(brke_angler);
}

//MAIN FUNCS.
void angler_op(void) {
    int vel_angler;
    if (master_controller.get_analog(JOY_LY) > 0) {
            if (angler.get_position() < 1500) {
                vel_angler = 75;
            } else {
                vel_angler = 5;
            }
        } else if (master_controller.get_analog(JOY_LY) < 0) {
            vel_angler = -100;
        } else {
            vel_angler = 0;
        }
        set_angler_brake(BRAKE_HOLD);
        set_angler_velocity(vel_angler);
    }


void angler_aut(float dist_angler, int vel_angler, bool async_angler) {
    set_angler_brake(BRAKE_HOLD);
    set_angler_aut(dist_angler, vel_angler);
    if (async_angler == false) {
        while (!(angler.get_position() < (dist_angler + 5) && (angler.get_position() > (dist_angler - 5)))) {
            delay(1);
        }
    }
}

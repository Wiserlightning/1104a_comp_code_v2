#include "subsystem_headers\globals.hpp"
#include "subsystem_headers\two_bar.hpp"
#include "subsystem_headers\tray.hpp"

using namespace pros;

//Helper FUNCS.
void set_twbr_vel(int vel_twbr){
    tw_br.move_velocity(vel_twbr);
}

void set_twbr_aut(float dist_twbr, int vel_twbr) {
    tw_br.move_absolute(dist_twbr, vel_twbr);
}

void set_twbr_brke(motor_brake_mode_e_t brke_twbr) {
    tw_br.set_brake_mode(brke_twbr);
}


//MAIN FUNCS.
void two_bar_op(void) {
    set_twbr_brke(BRKE_HOLD);
    if (mstr_ctrl.get_digital(BUT_L1) || (mstr_ctrl.get_digital(BUT_L2))) {
        set_twbr_vel(200 * (mstr_ctrl.get_digital(BUT_L1) - mstr_ctrl.get_digital(BUT_L2)));
    } else if (mstr_ctrl.get_digital(BUT_RT)) {
        set_twbr_aut(ARM_TOW1, 200);
    } else if (mstr_ctrl.get_digital(BUT_UP)) {
        set_twbr_aut(ARM_TOW2, 200);
    } else {
        set_twbr_vel(0);
    }
}

void two_bar_aut(float dist_twbr, int vel_twbr, bool async_twbr) {
    set_twbr_brke(BRKE_HOLD);
    set_twbr_aut(dist_twbr, vel_twbr);
    if (async_twbr == false) {
        while (!(tw_br.get_position() < (dist_twbr + 5) && (tw_br.get_position() > (dist_twbr - 5)))) {
            delay(1);
        }
    }
}
//I still have to define some functions/int that we previously used
#include "subsystem_headers\tray.hpp"
#include "subsystem_headers\tray.hpp"

int mode_tray = 0;

using namespace pros;

//HELPER FUNCS.
void set_tray_vel(int vel_tray){
    tray.move_velocity(vel_tray);
}

void set_tray_aut(float dist_tray, int vel_tray) {
    tray.move_absolute(dist_tray, vel_tray);
}

void set_tray_brke(motor_brake_mode_e_t brke_tray) {
    tray.set_brake_mode(brke_tray);
}

//MAIN FUNCS.
void tray_op(void) {
    double vel_tray;
    if (sel_drive == "TANK") {
        if (mstr_ctrl.get_digital(BUT_UP)) {
            if (tray.get_position() < 1500) {
                vel_tray = 75;
            } else {
                vel_tray = 5;
            }
        } else if (mstr_ctrl.get_digital(BUT_DWN)) {
            vel_tray = -100;
        } else {
            vel_tray = 0;
        }
    } else {
        if (mstr_ctrl.get_analog(JOY_LY) > 0) {
            if (tray.get_position() < 1500) {
                vel_tray = 75;
            } else {
                vel_tray = 5;
            }
        } else if (mstr_ctrl.get_analog(JOY_LY) < 0) {
            vel_tray = -100;
        } else {
            vel_tray = 0;
        }
    }
    set_tray_brke(BRKE_HOLD);
    set_tray_vel(vel_tray);
}

void tray_aut(float dist_tray, int vel_tray, bool async_tray) {
    set_tray_brke(BRKE_HOLD);
    set_tray_aut(dist_tray, vel_tray);
    if (async_tray == false) {
        while (!(tray.get_position() < (dist_tray + 5) && (tray.get_position() > (dist_tray - 5)))) {
            delay(1);
        }
    }
}

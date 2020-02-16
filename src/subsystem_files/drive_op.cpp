#include "subsystem_headers/globals_pros.hpp"
#include "subsystem_headers/drive.hpp"

using namespace pros;

//Helper functions
void set_drive_brake_mode(motor_brake_mode_e drive_brake_mode) {
    drive_top_left.set_brake_mode(drive_brake_mode);
    drive_top_right.set_brake_mode(drive_brake_mode);
    drive_bottom_left.set_brake_mode(drive_brake_mode);
    drive_bottom_right.set_brake_mode(drive_brake_mode);
}

void set_drive_voltage(int drive_velocity_left, int drive_velocity_right) {
    drive_top_left.move(drive_velocity_left);
    drive_top_right.move(drive_velocity_right);
    drive_bottom_left.move(drive_velocity_left);
    drive_bottom_right.move(drive_velocity_right);
}

//Main functions
void drive_op(void) {
    set_drive_brake_mode(BRAKE_COAST);
    set_drive_voltage(
        master_controller.get_analog(JOY_RY) + master_controller.get_analog(JOY_RX),
        master_controller.get_analog(JOY_RY) - master_controller.get_analog(JOY_RX)
    );
}

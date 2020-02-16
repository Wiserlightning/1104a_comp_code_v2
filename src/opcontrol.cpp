//Include necessary headers
#include "main.h"
#include "subsystem_headers/angler.hpp"
#include "subsystem_headers/arm.hpp"
#include "subsystem_headers/drive.hpp"
#include "subsystem_headers/globals_pros.hpp"
#include "subsystem_headers/intake.hpp"

//Main callback for operator control
void opcontrol(void) {
    while (1) {
        angler_op();
        arm_op();
        drive_op();
        intake_op();
        pros::delay(5);
    }
}
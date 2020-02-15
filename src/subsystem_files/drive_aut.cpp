#include "subsystem_headers/drive.hpp"
#include "subsystem_headers/globals.hpp"
#include "okapi/api.hpp"

using namespace okapi;

//Controller declarations
auto okapi_drive_chassis = ChassisControllerBuilder()
    .withMotors({19, 20}, {9, 10})
    .withDimensions(Motor::gearset::green, {{4_in, 10_in}, imev5GreenTPR})
    .build();

auto okapi_chassis_controller = AsyncMotionProfileControllerBuilder()
    .withOutput(okapi_drive_chassis)
    .withLimits({0.5, 1.0, 5.0})
    .buildMotionProfileController();

//Main functions
void drive_aut_simple(std::string drive_aut_mode, float drive_aut_value, bool drive_aut_async) {
    if (drive_aut_mode == "DRIVE") {
        okapi_drive_chassis->moveDistanceAsync(drive_aut_value * 1_in);
    } else if (drive_aut_mode == "TURN") {
        okapi_drive_chassis->turnAngleAsync(drive_aut_value * 1_deg);
    }

    if (drive_aut_async == false) {
        okapi_drive_chassis->waitUntilSettled();
    }
}

void drive_aut_path(std::string drive_aut_path, bool drive_aut_rev, bool drive_aut_mir, bool drive_aut_async) {
    okapi_chassis_controller->setTarget(drive_aut_path, drive_aut_rev, drive_aut_mir);
    if (drive_aut_async == false) {
        okapi_chassis_controller->waitUntilSettled();
    }
}

void drive_aut_gen_paths(void) {
    if (sel_auton == possible_autons.at(0)) {

    } else if (sel_auton == possible_autons.at(1)) {

    } else if (sel_auton == possible_autons.at(2)) {

    } else if (sel_auton == possible_autons.at(3)) {

    } else if (sel_auton == possible_autons.at(4)) {
        okapi_chassis_controller->generatePath(
            {{0_ft, 0_ft, 0_deg},
            {2_ft, 2_ft, 90_deg}},
            "TEST_AUT_CURVE"
        );
        okapi_chassis_controller->generatePath(
            {{0_ft, 0_ft, 0_deg},
            {2_ft, 0_ft, 0_deg}},
            "TEST_AUT_DRIVE"
        );
        okapi_chassis_controller->generatePath(
            {{0_ft, 0_ft, 0_deg},
            {0_ft, 0_ft, 90_deg}},
            "TEST_AUT_PIVOT"
        );
    }
}

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
    .withLimits({0.75, 1.5, 5})
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
        okapi_chassis_controller->generatePath(
            {{0_ft, 0_ft, 0_deg},
            {2_ft, 0_in, 0_deg}},
            "ONE_POINT_ONE"
        );
    } else if (sel_auton == possible_autons.at(3)) {
        okapi_chassis_controller->generatePath(
            {{0_ft, 0_ft, 0_deg},
            {122_in, 0_in, 0_deg}},
            "SKILLS_AUT_ONE"
        );
        okapi_chassis_controller->generatePath(
            {{0_ft, 0_ft, 0_deg},
            {33_in, 0_in, 0_deg}},
            "SKILLS_AUT_TWO"
        );
        okapi_chassis_controller->generatePath(
            {{0_ft, 0_ft, 0_deg},
            {22_in, 17_in, 37_deg}},
            "SKILLS_AUT_THREE"
            );
        okapi_chassis_controller->generatePath(
            {{0_ft, 0_ft, 0_deg},
            {1_in, 0_in, 0_deg}},
            "SKILLS_AUT_FOUR"
        );
    okapi_chassis_controller->generatePath(
            {{0_ft, 0_ft, 0_deg},
            {10_in, 0_in, 0_deg}},
            "SKILLS_AUT_FIVE"
        );
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

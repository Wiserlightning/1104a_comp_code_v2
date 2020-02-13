#include "subsystem_headers/drive.hpp"
#include "okapi/api.hpp"

using namespace okapi;

auto okapi_drive_chassis = ChassisControllerBuilder()
    .withMotors({19, 20}, {-9, -10})
    .withDimensions(Motor::gearset::green, {{4_in, 10_in}, imev5GreenTPR})
    .build();

auto okapi_chassis_controller = AsyncMotionProfileControllerBuilder()

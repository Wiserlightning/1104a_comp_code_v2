#include "subsystem_headers/globals.hpp"

//Initialization related values
const std::vector<std::string> possible_autons = {
    "RED",
    "BLUE",
    "ONE_POINT",
    "SKILLS",
    "TEST"
};
const unsigned num_of_autons = possible_autons.size() - 1;
std::string sel_auton;
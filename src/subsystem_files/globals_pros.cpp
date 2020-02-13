//Include necessary headers
#include "subsystem_headers/globals_pros.hpp"

//Declare namespace
using namespace pros;

//Declare hardware

/*Drive*/
Motor drive_top_left(19, GREEN_CARTRIDGE, false, ENCODER_TIC);
Motor drive_top_right(9, GREEN_CARTRIDGE, true, ENCODER_TIC);
Motor drive_bottom_left(20, GREEN_CARTRIDGE, false, ENCODER_TIC);
Motor drive_bottom_right(10, GREEN_CARTRIDGE, true, ENCODER_TIC);

/*Intake*/
Motor intake_left(11, GREEN_CARTRIDGE, false, ENCODER_TIC);
Motor intake_right(1, GREEN_CARTRIDGE, true, ENCODER_TIC);

/*Linkages*/
Motor arm(2, GREEN_CARTRIDGE, false, ENCODER_TIC);
Motor tray(8, RED_CARTRIDGE, true, ENCODER_TIC);

/*Controllers*/
Controller master_controller(CONTROL_MASTER);
 //Include necessary headers
#include "api.h"

//Start of header guard
#ifndef GLOBALS_PROS_HPP
#define GLOBALS_PROS_HPP

/*Controller Joysticks*/
#define JOY_LX pros::controller_analog_e_t::E_CONTROLLER_ANALOG_LEFT_X
#define JOY_LY pros::controller_analog_e_t::E_CONTROLLER_ANALOG_LEFT_Y
#define JOY_RX pros::controller_analog_e_t::E_CONTROLLER_ANALOG_RIGHT_X
#define JOY_RY pros::controller_analog_e_t::E_CONTROLLER_ANALOG_RIGHT_Y

/*Controller Buttons*/
#define BUTTON_L1 pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_L1
#define BUTTON_L2 pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_L2
#define BUTTON_R1 pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_R1
#define BUTTON_R2 pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_R2
#define BUTTON_A pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_A
#define BUTTON_B pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_B
#define BUTTON_X pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_X
#define BUTTON_Y pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_Y
#define BUTTON_UP pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_UP
#define BUTTON_DOWN pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_DOWN
#define BUTTON_LEFT pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_LEFT
#define BUTTON_RIGHT pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_RIGHT

/*Controller Types*/
#define CONTROL_MASTER pros::controller_id_e_t::E_CONTROLLER_MASTER

/*Brake Modes*/
#define BRAKE_HOLD pros::motor_brake_mode_e::E_MOTOR_BRAKE_HOLD
#define BRAKE_COAST pros::motor_brake_mode_e::E_MOTOR_BRAKE_COAST

/*Cartridges*/
#define GREEN_CARTRIDGE pros::motor_gearset_e::E_MOTOR_GEARSET_18
#define RED_CARTRIDGE pros::motor_gearset_e::E_MOTOR_GEARSET_36

/*Encoder Units*/
#define ENCODER_TIC pros::motor_encoder_units_e::E_MOTOR_ENCODER_COUNTS

//Define hardware prototypes

/*Drive*/
extern pros::Motor drive_top_left;
extern pros::Motor drive_top_right;
extern pros::Motor drive_bottom_left;
extern pros::Motor drive_bottom_right;

/*Intake*/
extern pros::Motor intake_left;
extern pros::Motor intake_right;

/*Linkages*/
extern pros::Motor arm;
extern pros::Motor angler;

/*Controllers*/
extern pros::Controller master_controller;

//End of header guard
#endif
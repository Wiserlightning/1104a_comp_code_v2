//Include necessary libraries
#include <string>

//Start of header guard
#ifndef DRIVE_HPP
#define DRIVE_HPP

//Define drive functions
extern void drive_op(void);
extern void drive_aut_simple(std::string drive_aut_mode, float drive_aut_value, bool drive_aut_async);
extern void drive_aut_path(std::string drive_aut_path, bool drive_aut_rev, bool drive_aut_mir, bool drive_aut_async);
extern void drive_aut_gen_paths(void);

//End of header guard
#endif
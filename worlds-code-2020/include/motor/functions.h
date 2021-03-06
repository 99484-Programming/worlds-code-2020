#ifndef _motor_functions_H_
#define _motor_functions_H_

#include "vex.h"
#include "motor/class.h"

// set target functions ===========================================================================
void left_set (int input);
void right_set (int input);
void chassis_set (int input);
void intake_set (int input);
void motors_set (int input);

// update functions  ==============================================================================
void motors_update_vars          () ; // update vars
void motors_update_power_vel     () ; // update power vel
void motors_update_power_vol     () ; // update power vol
void motors_update_power         () ; // update power
void motors_update_rotation_vars () ; // update rotation vars

// reset rotation =================================================================================
void left_reset_rotation ();
void right_reset_rotation ();
void chassis_reset_rotation ();
void intake_reset_rotation ();
void motors_reset_rotation ();

#endif
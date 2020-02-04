#ifndef _Usercontrol_H_
#define _Usercontrol_H_

#include "vex.h"
#include "controller.h"
#include "pragma.h"
#include "motor/class.h"
#include "motor/functions.h"
#include "custom_math.h"

// constants
#define TANK_DRIVE_JOYSTICK_THRESHOLD    5
#define ARCADE_DRIVE_JOYSTICK_THRESHOLD 10

// simple tank ctrl w/ threshold ==================================================================
void user_tank_1 () ;

// tanks ctrl w/ threshold and fast/slow ==========================================================
#define user_tank_2_fast_multiplier 1.0
#define user_tank_2_slow_multiplier 0.6
#define user_tank_2_turn_multiplier 1.0

extern int user_tank_2_mode                ; // 0 is slow, 1 is fast
extern double user_tank_2_speed_multiplier ;

void user_tank_2 () ;

// arcade ctrl w/ threshold and fast/slow =========================================================
// /*
#define user_arcade_1_fast_multiplier 1.0
#define user_arcade_1_slow_multiplier 0.4

extern int user_arcade_1_mode ; // 0 is slow, 1 is fast

void user_arcade_1 () ;
// */

// intake control 1 ===============================================================================
void user_intake_1 () ;

// intake control 2 ===============================================================================
#define user_intake_2_intake_fast_power   90
#define user_intake_2_intake_slow_power   40
#define user_intake_2_outtake_slow_power -40
#define user_intake_2_outtake_fast_power -90

void user_intake_2 () ;

// tilter control 1 ===============================================================================
#define user_tilter_1_up_power   100
#define user_tilter_1_down_power -80

void user_tilter_1 () ;

// tilter control 2 - slows down near the top =====================================================
#define user_tilter_2_up_power_super_fast   100
#define user_tilter_2_up_power_fast          30
#define user_tilter_2_up_power_slow          20
#define user_tilter_2_down_power_fast       -90
#define user_tilter_2_down_power_slow       -60
#define user_tilter_2_down_power_super_slow -20

#define user_tilter_2_up_pos_1   1500
#define user_tilter_2_up_pos_2   2250
#define user_tilter_2_up_pos_3   2850
#define user_tilter_2_down_pos_1  300
#define user_tilter_2_down_pos_2  100

void user_tilter_2 () ;

// tilter control 3 - slows down near the top =====================================================
#define user_tilter_3_up_power_super_fast   100
#define user_tilter_3_up_power_fast          50
#define user_tilter_3_up_power_slow          30
#define user_tilter_3_down_power_fast       -90
#define user_tilter_3_down_power_slow       -60
#define user_tilter_3_down_power_super_slow -20
 
#define user_tilter_3_up_pos_1   1300+200
#define user_tilter_3_up_pos_2   1600+200
#define user_tilter_3_up_pos_3   2550+200
#define user_tilter_3_down_pos_1  300
#define user_tilter_3_down_pos_2  100
 
extern bool user_tilter_3_setup_done ;
extern int user_tilter_3_setup_count ;
 
void user_tilter_3 () ;

// arm control 1 - just a simplest code
void user_arm_1    () ;

#endif
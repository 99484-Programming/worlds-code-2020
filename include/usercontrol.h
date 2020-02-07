#ifndef _Usercontrol_H_
#define _Usercontrol_H_

#include "vex.h"
#include "controller.h"
#include "pragma.h"
#include "motor/class.h"
#include "motor/functions.h"
#include "custom_math.h"
#include "sejun_code.h"

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

// arm control josh - kinda dumb
void user_arm_josh ();

// arm control 1 =================================================================================
void user_arm_1 () ;

// arm and tray control 1 - simple combined control ===============================================
#define user_arm_tray_1_tray_moe 50 // 
#define user_arm_tray_1_arm_moe  25 // 

#define user_arm_tray_1_tray_1    100 // slow down tray
#define user_arm_tray_1_tray_2    300 // tray is down
#define user_arm_tray_1_tray_3   1300 // automatic movement position
#define user_arm_tray_1_tray_4   1500 // start slowing down position
#define user_arm_tray_1_tray_5   2250 // even slower
#define user_arm_tray_1_tray_6   2850 // very top position

#define user_arm_tray_1_arm_1    0 // position for intaking
// #define user_arm_tray_1_arm_2  700 // low towers
// #define user_arm_tray_1_arm_3 1400 // high towers
#define user_arm_tray_1_arm_4 2100 // upper limit for the arm

#define user_arm_tray_1_tray_up   ctlr_buttonRIGHT
#define user_arm_tray_1_tray_down ctlr_buttonDOWN
#define user_arm_tray_1_arm_up    ctlr_buttonY
#define user_arm_tray_1_arm_down  ctlr_buttonB

#define user_arm_tray_1_tray_up_pwr_1      100 // default power
#define user_arm_tray_1_tray_up_pwr_2       30 // slow power 1
#define user_arm_tray_1_tray_up_pwr_3       20 // slowest power
#define user_arm_tray_1_tray_auto_up_pwr    70 // for automatically raising the tray
#define user_arm_tray_1_tray_auto_down_pwr -50 // for automatically lowering the tray
#define user_arm_tray_1_tray_down_pwr_1    -90 // default power
#define user_arm_tray_1_tray_down_pwr_2    -20 // slow power
#define user_arm_tray_1_arm_up_pwr         100 // default power
#define user_arm_tray_1_arm_down_pwr       -90 // default power

void user_arm_tray_1 ();

#endif
#include "usercontrol.h"

// simple tank ctrl w/ threshold ==================================================================
void user_tank_1 ()
{
  // set left power (take into account the threshold)
  left_set(ctlr_axis3);
  if (abs(ctlr_axis3) < TANK_DRIVE_JOYSTICK_THRESHOLD)
  {
    left_set(0);
  }

  // set right power (same as left)
  right_set(ctlr_axis2);
  if (abs(ctlr_axis2) < TANK_DRIVE_JOYSTICK_THRESHOLD)
  {
    right_set(0);
  }
}

// tanks ctrl w/ threshold and fast/slow + slow turns  ============================================
int user_tank_2_mode = 1; // 0 is slow, 1 is fast
double user_tank_2_speed_multiplier; // used to keep track of how fast it should be going

void user_tank_2 ()
{
  // change drive most based on button input
  if (ctlr_buttonL2)
  {
    user_tank_2_mode = 0;
  }
  else
  {
    user_tank_2_mode = 1;
  }

  // change drive multiplier
  if (user_tank_2_mode)
  {
    user_tank_2_speed_multiplier = user_tank_2_fast_multiplier;
  }
  else
  {
    user_tank_2_speed_multiplier = user_tank_2_slow_multiplier;
  }
  // slow down turns
  if (math_sgn_i(ctlr_axis2) != math_sgn_i(ctlr_axis3) && math_sgn_i(ctlr_axis2) + math_sgn_i(ctlr_axis3) == 0)
  {
    user_tank_2_speed_multiplier *= user_tank_2_turn_multiplier;
  }

  // set left power (and drive threshold)
  left_set(ctlr_axis3 * user_tank_2_speed_multiplier);
  if (abs(ctlr_axis3) < TANK_DRIVE_JOYSTICK_THRESHOLD)
  {
    left_set(0);
  }

  // set right power (and drive threshold)
  right_set(ctlr_axis2 * user_tank_2_speed_multiplier);
  if (abs(ctlr_axis2) < TANK_DRIVE_JOYSTICK_THRESHOLD)
  {
    right_set(0);
  }
}

// arcade ctrl w/ threshold and fast/slow =========================================================
// /*
int user_arcade_1_mode = 1;
int user_arcade_1_l       ;
int user_arcade_1_r       ;

void user_arcade_1 ()
{
  if (ctlr_buttonUP_pressed)
  {
    user_arcade_1_mode = 1;
  }
  if (ctlr_buttonLEFT_pressed)
  {
    user_arcade_1_mode = 0;
  }

  user_arcade_1_l = math_restrict_i(ctlr_axis2 + ctlr_axis4, -100, 100);
  if (user_arcade_1_mode)
  {
    user_arcade_1_l = user_arcade_1_l * user_arcade_1_fast_multiplier;
  }
  else
  {
    user_arcade_1_l = user_arcade_1_l * user_arcade_1_slow_multiplier;
  }
  if (abs(user_arcade_1_l) < ARCADE_DRIVE_JOYSTICK_THRESHOLD)
  {
    left_set(user_arcade_1_l);
  }

  user_arcade_1_r = math_restrict_i(ctlr_axis2 - ctlr_axis4, -100, 100);
  if (user_arcade_1_mode)
  {
    user_arcade_1_l = user_arcade_1_r * user_arcade_1_fast_multiplier;
  }
  else
  {
    user_arcade_1_r = user_arcade_1_r * user_arcade_1_slow_multiplier;
  }
  if (abs(user_arcade_1_r) < ARCADE_DRIVE_JOYSTICK_THRESHOLD)
  {
    right_set(user_arcade_1_r);
  }
}
// */

// intake control 1 ===============================================================================
void user_intake_1 ()
{
  intake(-100);
  tilt(-5);
  sleep(1800);

  stop();

  if (ctlr_buttonR1 && !ctlr_buttonR2)
  {
    intake_set(-100);
  }
  else if (ctlr_buttonR2 && !ctlr_buttonR1)
  {
    intake_set(100);
  }
  else
  {
    intake_set(0);
  }
}

// intake control 2 ===============================================================================
// press R1 for fast intake
// press R2 for slow intake
// hold L1 for  outtaking

void user_intake_2 ()
{
  if (ctlr_buttonR1) // fast intaking
  {
    intake_set(user_intake_2_intake_fast_power);
  }
  else if (ctlr_buttonL1) // slow intake
  {
    intake_set(user_intake_2_intake_slow_power);
  }
  else if (ctlr_buttonL1) // outtaking
  {
    intake_set(user_intake_2_outtake_fast_power);
  }
  else
  {
    intake_set(0);
    // if (tilter.rotation_get() < user_tilter_2_down_pos_2 + 300 && ctlr_buttonUP)
    // {
    //   intake_set(-90);
    // }
  }
}

// tilter control 1 ===============================================================================
// press R1 to go up
// press R2 to go down

void user_tilter_1 ()
{
  if (ctlr_buttonUP)
  {
    tilter.set_target(100);
  }
  else if (ctlr_buttonDOWN)
  {
    tilter.set_target(-100);
  }
  else
  {
    tilter.set_target(0);
  }
}

// tilter control 2 - slows down near the top =====================================================
void user_tilter_2 ()
{
  if (ctlr_buttonUP) // if the up button is pressed
  {
    tilter.update_power_mode_set(0);
    if (tilter.rotation_get() < user_tilter_2_up_pos_1) // if we are not close to verticle
    {
      tilter.set_target(user_tilter_2_up_power_super_fast);
    }
    else if (tilter.rotation_get() < user_tilter_2_up_pos_2) // if we are close to verticle
    {
      tilter.set_target(user_tilter_2_up_power_fast);
    }
    else if (tilter.rotation_get() < user_tilter_2_up_pos_3) // if we are closer to verticle
    {
      tilter.set_target(user_tilter_2_up_power_slow);
    }
    else // if we are past the limit
    {
      tilter.set_target(-20);
    }
  }
  else if (ctlr_buttonDOWN) // if down button is pressed
  {
    tilter.update_power_mode_set(0);
    tilter.set_target(user_tilter_2_down_power_fast);
  }
  else
  {
    if (tilter.rotation_get() > user_tilter_2_up_pos_1 && tilter.rotation_get() < user_tilter_2_up_pos_3)
    {
      tilter.update_power_mode_set(1);
      tilter.set_target(15);
    }
    else if (tilter.rotation_get() > user_tilter_2_up_pos_3)
    {
      tilter.update_power_mode_set(1);
      tilter.set_target(-20);
    }
    else
    {
      tilter.update_power_mode_set(0);
      tilter.set_target(0);
    }
  }
}

// tilter control 3 - slows down near the top and resets in the beginning =========================
bool user_tilter_3_setup_done = false;
int user_tilter_3_setup_count = 0;

void user_tilter_3 ()
{
  if (ctlr_buttonUP || ctlr_buttonDOWN) {
    user_tilter_3_setup_done = true;
  }
  if (!user_tilter_3_setup_done) {
    user_tilter_3_setup_count += 1;
    tilter.update_power_mode_set(true);
    tilter.set_target(-30);
    if (fabs(tilter.rotation_change_get()) == 0.0 &&
        user_tilter_3_setup_count > 20) {
      tilter.rotation_reset();
      user_tilter_3_setup_done = true;
    }
  } else {
    tilter.update_power_mode_set(false);
  }

  if (ctlr_buttonUP) // if the up button is pressed
  {
    tilter.update_power_mode_set(0);
    if (tilter.rotation_get() <
        user_tilter_3_up_pos_1) // if we are not close to verticle
    {
      tilter.set_target(user_tilter_3_up_power_super_fast);
    } else if (tilter.rotation_get() <
               user_tilter_3_up_pos_2) // if we are close to verticle
    {
      tilter.set_target(user_tilter_3_up_power_fast);
    } else if (tilter.rotation_get() <
               user_tilter_3_up_pos_3) // if we are closer to verticle
    {
      tilter.set_target(user_tilter_3_up_power_slow);
    } else // if we are past the limit
    {
      tilter.set_target(-20);
    }
  } else if (ctlr_buttonDOWN) // if down button is pressed
  {
    tilter.update_power_mode_set(0);
    tilter.set_target(user_tilter_3_down_power_fast);
  } else {
    if (tilter.rotation_get() > user_tilter_3_up_pos_1 &&
        tilter.rotation_get() < user_tilter_3_up_pos_3) {
      tilter.update_power_mode_set(1);
      tilter.set_target(15);
    } else if (tilter.rotation_get() > user_tilter_3_up_pos_3) {
      tilter.update_power_mode_set(1);
      tilter.set_target(-20);
    } else if (user_tilter_3_setup_done) {
      tilter.update_power_mode_set(0);
      tilter.set_target(0);
    }
  }
}

// arm control josh - kinda dumb ==================================================================
void user_arm_josh()
{
  if (ctlr_buttonX)
  {
    arm.set_target(100);
  }
  else if (ctlr_buttonB)
  {
    arm.set_target(-75);
  }
  else
  {
    arm.set_target(0);
  }
}

// arm control 1 - moves the tilter as well =======================================================
void user_arm_1 ()
{
  
 if (ctlr_buttonX)
 {
  
 }
}

// arm and tray control 1 - simple combined control ===============================================
int user_arm_tray_1_tray_automatic = 0; // 0 when button input works, 1 when target is down, 2 when target is up
int user_arm_tray_1_arm_down_button_duration = 0; // how long the arm down button has been pressed for

void user_arm_tray_1 ()
{
  if (user_arm_tray_1_arm_down) // update arm_down_button_duration variable
  {
    user_arm_tray_1_arm_down_button_duration += 20;
  }
  else
  {
    user_arm_tray_1_arm_down_button_duration = 0;
  }

  if (user_arm_tray_1_arm_up) // button input for automatic tray control
  {
    user_arm_tray_1_tray_automatic = 2;
  }
  else if (user_arm_tray_1_arm_down_button_duration >= 750)
  {
    user_arm_tray_1_tray_automatic = 1;
  }

  // automatic tray control
  if (user_arm_tray_1_tray_automatic == 2) // if the tray target is up
  {
    if (tilter.rotation_get() < user_arm_tray_1_tray_3) // if the tray is too low
    {
      tilter.set_target(user_arm_tray_1_tray_auto_up_pwr);
    }
    else if (tilter.rotation_get() > user_arm_tray_1_tray_3)  // if the tray is above the target
    {
      if (tilter.rotation_get() > user_arm_tray_1_tray_3 + user_arm_tray_1_tray_moe) // if the tray is in the margin of error
      {
        tilter.set_target(0);
      }
      else // if the tray is too high
      {
        tilter.set_target(user_arm_tray_1_tray_auto_down_pwr);
      }
    }
  }
  else if (user_arm_tray_1_tray_automatic == 1) // if the tray target is down
  {
    if (tilter.rotation_get() > user_arm_tray_1_tray_1) // if the tray is too high
    {
      tilter.set_target(user_arm_tray_1_tray_auto_down_pwr);
    }
    else // if the tray is down - DONE
    {
      tilter.set_target(0);
      user_arm_tray_1_tray_automatic = 0; // engage usercontrol for the tray
    }
  }
  else // usercontrol for the tray
  {
    if (user_arm_tray_1_tray_up) // if the up button is pressed
    {
      if (tilter.rotation_get() < user_tilter_2_up_pos_1) // if we are not close to verticle
      {
        tilter.set_target(user_tilter_2_up_power_super_fast);
      }
      else if (tilter.rotation_get() < user_tilter_2_up_pos_2) // if we are close to verticle
      {
        tilter.set_target(user_tilter_2_up_power_fast);
      }
      else if (tilter.rotation_get() < user_tilter_2_up_pos_3) // if we are closer to verticle
      {
        tilter.set_target(user_tilter_2_up_power_slow);
      }
      else // if we are past the limit
      {
        tilter.set_target(-20);
      }
    }
    else if (ctlr_buttonDOWN) // if down button is pressed
    {
      tilter.set_target(user_tilter_2_down_power_fast);
    }
  }
}
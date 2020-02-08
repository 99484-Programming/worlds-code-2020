#include "vex.h"
#include "pragma.h"
#include "motor/class.h"

// set target functions ===========================================================================
void left_set (int input)
{
  left_front.set_target(input);
  left_back.set_target(input);
}
void right_set (int input)
{
  right_front.set_target(input);
  right_back.set_target(input);
}
void chassis_set (int input)
{
  left_set(input);
  right_set(input);
}
void intake_set (int input)
{
  intake_l.set_target(input);
  intake_r.set_target(input);
}
void motors_set (int input)
{
  for (std::list<Motor>::iterator it=Motors.begin(); it != Motors.end(); ++it)
  {
    it->set_target(input);
  }
}

// update functions  ==============================================================================
// update vars
void motors_update_vars ()
{
  left_front.update_vars();
  left_back.update_vars();
  right_front.update_vars();
  right_back.update_vars();
  intake_l.update_vars();
  intake_r.update_vars();
  tray.update_vars();
}
// update power vel
void motors_update_power_vel ()
{
  left_front.update_power_vel();
  left_back.update_power_vel();
  right_front.update_power_vel();
  right_back.update_power_vel();
  intake_l.update_power_vel();
  intake_r.update_power_vel();
  tray.update_power_vel();
}
// update power vol
void motors_update_power_vol ()
{
  left_front.update_power_vol();
  left_back.update_power_vol();
  right_front.update_power_vol();
  right_back.update_power_vol();
  intake_l.update_power_vol();
  intake_r.update_power_vol();
  tray.update_power_vol();
}
// update power
void motors_update_power ()
{
  left_front.update_power();
  left_back.update_power();
  right_front.update_power();
  right_back.update_power();
  intake_l.update_power();
  intake_r.update_power();
  tray.update_power();
}
// update rotation vars
void motors_update_rotation_vars ()
{
  left_front.update_rotation_vars();
  left_back.update_rotation_vars();
  right_front.update_rotation_vars();
  right_back.update_rotation_vars();
  intake_l.update_rotation_vars();
  intake_r.update_rotation_vars();
  tray.update_rotation_vars();
}

// reset rotation =================================================================================
void left_reset_rotation ()
{
  left_front.rotation_reset();
  left_back.rotation_reset();
}
void right_reset_rotation ()
{
  right_front.rotation_reset();
  right_back.rotation_reset();
}
void chassis_reset_rotation ()
{
  left_reset_rotation();
  right_reset_rotation();
}
void intake_reset_rotation ()
{
  intake_l.rotation_reset();
  intake_r.rotation_reset();
}
void motors_reset_rotation ()
{
  chassis_reset_rotation();
  intake_reset_rotation();
  tray.rotation_reset();
}
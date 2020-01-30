#include "vex.h"
#include "pragma.h"
#include "motor/class.h"
#include "custom_math.h"
#include "autonomous/functions.h"
#include "autonomous/routes.h"

// route wait function
void auton_route_wait (int input)
{
  auton_wait(input);
  while (!auton_wait_done())
  {
    auton_standard_update_beg();    
    auton_standard_update_fin();
  }
}

// testing routes =================================================================================
void auton_route_testing_4 ()
{
}

void auton_route_testing_3 ()
{
}

void auton_route_testing_2 () // 1 cube i think
{
  a_drive(-50, 950);

  a_drive(100, 1250);

  chassis_set(0);

  a_wait(3000);
}

void auton_route_testing_1 () // stacking testing
{
  a_outtake_small();
  a_wait(500);

  a_tilter_up();
  a_wait(500);

  a_drive(15, 500);

  a_tilter_mid();
  a_wait(250);

  a_drive(-50, 750);

  a_tilter_down();
  a_wait(500);
}

// blank and template
void auton_route_0 ()
{
  // initialize stuff

  // set initial commands

  // while loop
    // loop that needs updating
    // other loop that needs updating
    // wait command
  
  // set other initial commands

  // while loops
    // loop that needs updating
    // other loop that needs updating
    // wait command
}

// auton route 1
void auton_route_1 ()
{
}

// auton route 2
void auton_route_2 ()
{
  
}

// auton route 3
void auton_route_3 ()
{
  
}

// auton route 4
void auton_route_4 ()
{
  
}

// auton route 5
void auton_route_5 ()
{
  
}

// auton route 6
void auton_route_6 ()
{
  
}

// auton route 11 (Skills 1)
void auton_route_11 ()
{
  
}

// auton route 12 (Skills 2)
void auton_route_12 ()
{
  
}

// extra autons 
void auton_route_13 ()
{
  
}

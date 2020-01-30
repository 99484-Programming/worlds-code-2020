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

// 5 points red (15 seconds) [unprotected]
void auton_route_1 ()
{
  Chassis_forward(40);
  intake(100);
  sleep(3000);
  
  stop();
  intake(100);
  sleep(1000);
  
  Chassis_forward(40);
  intake(100);
  sleep(1200);

  stop();
  intake(30);
  sleep(100);

  Chassis_forward(-100);
  intake(100);
  sleep(2000);
  
  stop();
  sleep(300);

  Chassis_forward(60);
  intake(40);
  sleep(600);

  stop();
  sleep(300);

  Chassis_right(-50);
  Chassis_left(50);
  sleep(810);

  stop();
  sleep(300);
  
  Chassis_forward(40);
  intake(-30);
  sleep(1000);

  stop();
  sleep(300);

  tilt(30);
  sleep(3000);

  stop();
  sleep(300);

  Chassis_forward(-100);
  sleep(200);

  stop();
}

// 5 point red (15 seconds) [protected]
void auton_route_2 ()
{
  right_back.resetRotation(); 
  while(right_back.rotation(rotationUnits::raw)<2300)
  {
    Chassis_forward(40);
    if(right_back.rotation(rotationUnits::raw)<1000) {
      intake(100);
    }
    else if(right_back.rotation(rotationUnits::raw)<1700) {
      intake(0);
    }
    else {
      intake(100);
    }
  }
  stop();
  right_back.resetRotation(); 
  while(right_back.rotation(rotationUnits::raw) > -300)
  {
    Chassis_forward(-100);
    intake(30);
  }
  


  
  stop();
  sleep(300);

  right_back.resetRotation();
  while(right_back.rotation(rotationUnits::raw)<1700)
  {
    Chassis_forward(50);
    intake(100);
  }
  stop();
  sleep(200);

  
  stop();
  sleep(300);

  right_back.resetRotation();
  while(right_back.rotation(rotationUnits::raw)<925)
  {
    Chassis_right(50);
    Chassis_left(-50);
    intake(100);
  }

  right_back.resetRotation();
  while(right_back.rotation(rotationUnits::raw)<3150)
  {
    Chassis_forward(50);
    if(right_back.rotation(rotationUnits::raw)<1000) {
      intake(100);
    }
    else if(right_back.rotation(rotationUnits::raw)<2000) {
      intake(0);
    }
    else {
      intake(100);
    }
  }

  stop();
  sleep(500);

  intake(-20);
  sleep(300);

  tilt(30);
  sleep(3000);

  right_back.resetRotation();
  while(right_back.rotation(rotationUnits::raw)<400)
  {
    Chassis_forward(-50);
  }

  Chassis_forward(-50);
  sleep(500);
}

// RED grab a couple cubes (15 seconds) [protected]
void auton_route_3 ()
{
  intake_set(100);
  a_forward(250, 40);
  a_forward(2000, 70);
  a_forward(3500, 40);
  a_wait(250);
  a_forward(3000, 50);
  a_wait(100);
  a_forward(4500, 40);
  a_wait(500);
}

// 5 points blue (15 seconds) [unprotected]
void auton_route_4 ()
{
  Chassis_forward(40);
  intake(100);
  sleep(3000);

  stop();
  intake(100);
  sleep(1000);

  Chassis_forward(40);
  intake(100);
  sleep(1200);

  stop();
  intake(30);
  sleep(100);

  Chassis_forward(-100);
  intake(100);
  sleep(2000);

  stop();
  sleep(300);

  Chassis_forward(60);
  intake(40);
  sleep(600);

  stop();
  sleep(300);

  Chassis_right(-50);
  Chassis_left(50);
  sleep(750);

  stop();
  sleep(300);

  Chassis_forward(40);
  intake(-30);
  sleep(1000);

  stop();
  sleep(300);

  tilt(30);
  sleep(3000);

  stop();
  sleep(300);

  Chassis_forward(-100);
  sleep(200);

  stop();
}

// 3 points blue (15 seconds) [protected]
void auton_route_5 ()
{
  intake_set(100);
  a_forward(1250, 30);
  a_wait(500);

  a_turn(1750, 15);
  a_wait(500);

  a_forward(1250, 30);
  a_wait(500);

  a_turn(1100, 15);
  intake_set(0);

  a_forward(350, 20);
  a_wait(500);

  a_stack();
  a_wait(500);

  a_drive(-20, 750);
  a_tilter_down();

  a_wait(250);
}

// 5 point blue (15 seconds) [protected]
void auton_route_6 ()
{
  intake_set(100);
  a_forward(250, 40);
  a_forward(2000, 70);
  a_forward(3500, 40);
  a_wait(250);
  a_forward(3000, 50);
  a_wait(100);
  a_forward(4000, 40);
  a_wait(500);

  a_turn(2750, 30);
  a_reset_and_wait(500);

  a_forward(500,  30);
  a_forward(2500, 75);
  intake_set(50);
  a_forward(3850, 20);
  a_wait(500);
  
  a_stack();
  a_wait(500);

  a_drive(-100, 500);
  a_tilter_down();

  a_wait(500);
}

// 12 point auton
void auton_route_11 ()
{
  Chassis_forward(40); //forward to line of 3
  intake(100);
  sleep(2000);

  Chassis_forward(30);//intake full line of 3
  intake(100);
  sleep(1700);
  
  Chassis_forward(-100);//go back to hit wall
  intake(100);
  sleep(2000);

  stop();
  intake(100);
  sleep(200);
  stop();

  Chassis_forward(40);//get away from wall
  sleep(500);

  stop();
  sleep(500);

  left_back.resetRotation(); //turn to move to line of 4
  while(left_back.rotation(rotationUnits::raw) < 650) 
  {
    Chassis_left(20);
    Chassis_right(-20);
  }

  Chassis_forward(45);//move to line of 4
  sleep(2000);

  right_back.resetRotation(); //prepare to aline
  while(right_back.rotation(rotationUnits::raw) < 650) 
  {
    Chassis_left(-20);
    Chassis_right(20);
  }

  Chassis_forward(-60); //hit wall to aline
  sleep(700);

  Chassis_forward(50);
  intake(100);// get 3 blocks in line of 3 (needs to be checked)
  sleep(2900);
  stop();
  intake(100);
  sleep(100);
  
  stop();
  Chassis_forward(30);
  sleep(700);
  //Turn to aline to tower
  left_back.resetRotation();
  while(right_back.rotation(rotationUnits::raw) < 1100)
  {
    Chassis_left(20);
    Chassis_right(-20);
  }
  stop();
  
  stop();
  sleep(200);
  

  intake(100);//intake to get tower
  sleep(1200);
  
  stop();
  sleep(200);

  right_back.resetRotation();
  while(right_back.rotation(rotationUnits::raw) < 20) 
  {
    Chassis_left(-10);
    Chassis_right(10);
  }

  Chassis_forward(40);
  sleep(3000);//aline with goal

  //foward to goal

  stop();
  sleep(300);

  tilt(30); //place blocks
  sleep(3300);

  stop();
  sleep(1000);

  Chassis_forward(-100);
  sleep(300);
  
  stop();
}

// 12 point auton route 2 - Joshua
void auton_route_12 ()
{
  // intake the first set of 4
  intake_set(100);
  a_forward(1200, 70);
  a_forward(4000, 20);
  a_wait(500);
  intake_set(100);
  
  // weird turn
  int time1 = 100;
  int turn1 = 400;
  int pwr1 = 20;
  a_turn(-turn1, pwr1);
  a_wait(time1);
  int pwr2 = 45;
  int pwr3 = 60;
  int dist1 = 4000;
  left_set(pwr2);
  right_set(pwr3);
  chassis_reset_rotation();
  while (right_front.rotation_get() < dist1)
  {
    auton_standard_update_beg();auton_standard_update_fin();
  }
  chassis_set(0); a_wait(time1);
  a_turn(-turn1-100, pwr1);
  intake_set(50);
  a_wait(500);

  // grab another cube
  chassis_reset_rotation();
  intake_set(100);
  a_forward(1000, 25);
  auton_intake_1_stop();
  a_forward(1250, 20);
  a_wait(500);

  // turn and tower
  a_turn(-600, 15);
  a_reset_and_wait(250);
  a_forward(50, 20);
  a_wait(250);
  intake_set(100);
  a_wait(1000);
  intake_set(75);

  // turn and forward to goal
  a_turn(360, 15);
  a_reset_and_wait(500);
  a_forward(3350, 40); 
  a_wait(500);
  a_turn(-500,15);
  a_reset_and_wait(500);
  intake_set(-40);
  a_forward(350, 20);
  intake_set(0);
  a_wait(500);

  // stack
  a_stack();

  // backup
  a_drive(-20, 500);
  a_wait(500);
}

// another sejun auton
void auton_route_13 ()
{
  right_back.resetRotation(); // intake 4 cube
  while (right_back.rotation(rotationUnits::raw) < 600)
  {
    intake(100);
    Chassis_forward(100);
  }

  sleep(20);

  right_back.resetRotation(); // hit the wall
  while (right_back.rotation(rotationUnits::raw) > -600)
  {
    intake(100);
    Chassis_forward(-100);
  }

  sleep(20);

  right_back.resetRotation(); // go forward a bit
  while (right_back.rotation(rotationUnits::raw) < 100)
  {
    intake(100);
    Chassis_forward(40);
  }

  sleep(20);

  right_back.resetRotation(); // turn left
  while (right_back.rotation(rotationUnits::raw) > -650)
  {
    Chassis_right(-50);
    Chassis_left(50);
    intake(100);
  }

  sleep(20);

  right_back.resetRotation(); // go towards the 4th line
  while (right_back.rotation(rotationUnits::raw) < 500)
  {
    Chassis_forward(100);
    intake(100);
  }

  sleep(20);

  right_back.resetRotation(); // hit the line
  while (right_back.rotation(rotationUnits::raw) > -100)
  {
    Chassis_forward(100);
    intake(100);
  }

  sleep(20);

  right_back.resetRotation();
  while (right_back.rotation(rotationUnits::raw) < 650)
  {
    Chassis_forward(100);
    intake(100);
  }
}

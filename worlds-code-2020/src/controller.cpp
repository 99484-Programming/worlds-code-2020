#include "vex.h"
#include "pragma.h"

int ctlr_axis1       = 0 ;
int ctlr_axis2       = 0 ;
int ctlr_axis3       = 0 ;
int ctlr_axis4       = 0 ;
int ctlr_buttonR1    = 0 ;
int ctlr_buttonR2    = 0 ;
int ctlr_buttonL1    = 0 ;
int ctlr_buttonL2    = 0 ;
int ctlr_buttonA     = 0 ;
int ctlr_buttonB     = 0 ;
int ctlr_buttonX     = 0 ;
int ctlr_buttonY     = 0 ;
int ctlr_buttonUP    = 0 ;
int ctlr_buttonDOWN  = 0 ;
int ctlr_buttonLEFT  = 0 ;
int ctlr_buttonRIGHT = 0 ;

int ctlr_axis1_prev       = 0 ;
int ctlr_axis2_prev       = 0 ;
int ctlr_axis3_prev       = 0 ;
int ctlr_axis4_prev       = 0 ;
int ctlr_buttonR1_prev    = 0 ;
int ctlr_buttonR2_prev    = 0 ;
int ctlr_buttonL1_prev    = 0 ;
int ctlr_buttonL2_prev    = 0 ;
int ctlr_buttonA_prev     = 0 ;
int ctlr_buttonB_prev     = 0 ;
int ctlr_buttonX_prev     = 0 ;
int ctlr_buttonY_prev     = 0 ;
int ctlr_buttonUP_prev    = 0 ;
int ctlr_buttonDOWN_prev  = 0 ;
int ctlr_buttonLEFT_prev  = 0 ;
int ctlr_buttonRIGHT_prev = 0 ;

int ctlr_buttonR1_pressed    = 0 ;
int ctlr_buttonR2_pressed    = 0 ;
int ctlr_buttonL1_pressed    = 0 ;
int ctlr_buttonL2_pressed    = 0 ;
int ctlr_buttonA_pressed     = 0 ;
int ctlr_buttonB_pressed     = 0 ;
int ctlr_buttonX_pressed     = 0 ;
int ctlr_buttonY_pressed     = 0 ;
int ctlr_buttonUP_pressed    = 0 ;
int ctlr_buttonDOWN_pressed  = 0 ;
int ctlr_buttonLEFT_pressed  = 0 ;
int ctlr_buttonRIGHT_pressed = 0 ;

int ctlr_buttonR1_released    = 0 ;
int ctlr_buttonR2_released    = 0 ;
int ctlr_buttonL1_released    = 0 ;
int ctlr_buttonL2_released    = 0 ;
int ctlr_buttonA_released     = 0 ;
int ctlr_buttonB_released     = 0 ;
int ctlr_buttonX_released     = 0 ;
int ctlr_buttonY_released     = 0 ;
int ctlr_buttonUP_released    = 0 ;
int ctlr_buttonDOWN_released  = 0 ;
int ctlr_buttonLEFT_released  = 0 ;
int ctlr_buttonRIGHT_released = 0 ;

void ctlr_updateVars()
{
  ctlr_axis1_prev       = ctlr_axis1       ;
  ctlr_axis2_prev       = ctlr_axis2       ;
  ctlr_axis3_prev       = ctlr_axis3       ;
  ctlr_axis4_prev       = ctlr_axis4       ;
  ctlr_buttonR1_prev    = ctlr_buttonR1    ;
  ctlr_buttonR2_prev    = ctlr_buttonR2    ;
  ctlr_buttonL1_prev    = ctlr_buttonL1    ;
  ctlr_buttonL2_prev    = ctlr_buttonL2    ;
  ctlr_buttonA_prev     = ctlr_buttonA     ;
  ctlr_buttonB_prev     = ctlr_buttonB     ;
  ctlr_buttonX_prev     = ctlr_buttonX     ;
  ctlr_buttonY_prev     = ctlr_buttonY     ;
  ctlr_buttonUP_prev    = ctlr_buttonUP    ;
  ctlr_buttonDOWN_prev  = ctlr_buttonDOWN  ;
  ctlr_buttonLEFT_prev  = ctlr_buttonLEFT  ;
  ctlr_buttonRIGHT_prev = ctlr_buttonRIGHT ;

  ctlr_axis1       = Controller_1.Axis1.value()          ;
  ctlr_axis2       = Controller_1.Axis2.value()          ;
  ctlr_axis3       = Controller_1.Axis3.value()          ;
  ctlr_axis4       = Controller_1.Axis4.value()          ;
  ctlr_buttonR1    = Controller_1.ButtonR1.pressing()    ;
  ctlr_buttonR2    = Controller_1.ButtonR2.pressing()    ;
  ctlr_buttonL1    = Controller_1.ButtonL1.pressing()    ;
  ctlr_buttonL2    = Controller_1.ButtonL2.pressing()    ;
  ctlr_buttonA     = Controller_1.ButtonA.pressing()     ;
  ctlr_buttonB     = Controller_1.ButtonB.pressing()     ;
  ctlr_buttonX     = Controller_1.ButtonX.pressing()     ;
  ctlr_buttonY     = Controller_1.ButtonY.pressing()     ;
  ctlr_buttonUP    = Controller_1.ButtonUp.pressing()    ;
  ctlr_buttonDOWN  = Controller_1.ButtonDown.pressing()  ;
  ctlr_buttonLEFT  = Controller_1.ButtonLeft.pressing()  ;
  ctlr_buttonRIGHT = Controller_1.ButtonRight.pressing() ;

  ctlr_buttonR1_pressed    = (ctlr_buttonR1_prev    == 0 && ctlr_buttonR1    == 1) ? 1 : 0;
  ctlr_buttonR2_pressed    = (ctlr_buttonR2_prev    == 0 && ctlr_buttonR2    == 1) ? 1 : 0;
  ctlr_buttonL1_pressed    = (ctlr_buttonL1_prev    == 0 && ctlr_buttonL1    == 1) ? 1 : 0;
  ctlr_buttonL2_pressed    = (ctlr_buttonL2_prev    == 0 && ctlr_buttonL2    == 1) ? 1 : 0;
  ctlr_buttonA_pressed     = (ctlr_buttonA_prev     == 0 && ctlr_buttonA     == 1) ? 1 : 0;
  ctlr_buttonB_pressed     = (ctlr_buttonB_prev     == 0 && ctlr_buttonB     == 1) ? 1 : 0;
  ctlr_buttonX_pressed     = (ctlr_buttonX_prev     == 0 && ctlr_buttonX     == 1) ? 1 : 0;
  ctlr_buttonY_pressed     = (ctlr_buttonY_prev     == 0 && ctlr_buttonY     == 1) ? 1 : 0;
  ctlr_buttonUP_pressed    = (ctlr_buttonUP_prev    == 0 && ctlr_buttonUP    == 1) ? 1 : 0;
  ctlr_buttonDOWN_pressed  = (ctlr_buttonDOWN_prev  == 0 && ctlr_buttonDOWN  == 1) ? 1 : 0;
  ctlr_buttonLEFT_pressed  = (ctlr_buttonLEFT_prev  == 0 && ctlr_buttonLEFT  == 1) ? 1 : 0;
  ctlr_buttonRIGHT_pressed = (ctlr_buttonRIGHT_prev == 0 && ctlr_buttonRIGHT == 1) ? 1 : 0;

  ctlr_buttonR1_released    = (ctlr_buttonR1_prev    == 1 && ctlr_buttonR1    == 0) ? 1 : 0;
  ctlr_buttonR2_released    = (ctlr_buttonR2_prev    == 1 && ctlr_buttonR2    == 0) ? 1 : 0;
  ctlr_buttonL1_released    = (ctlr_buttonL1_prev    == 1 && ctlr_buttonL1    == 0) ? 1 : 0;
  ctlr_buttonL2_released    = (ctlr_buttonL2_prev    == 1 && ctlr_buttonL2    == 0) ? 1 : 0;
  ctlr_buttonA_released     = (ctlr_buttonA_prev     == 1 && ctlr_buttonA     == 0) ? 1 : 0;
  ctlr_buttonB_released     = (ctlr_buttonB_prev     == 1 && ctlr_buttonB     == 0) ? 1 : 0;
  ctlr_buttonX_released     = (ctlr_buttonX_prev     == 1 && ctlr_buttonX     == 0) ? 1 : 0;
  ctlr_buttonY_released     = (ctlr_buttonY_prev     == 1 && ctlr_buttonY     == 0) ? 1 : 0;
  ctlr_buttonUP_released    = (ctlr_buttonUP_prev    == 1 && ctlr_buttonUP    == 0) ? 1 : 0;
  ctlr_buttonDOWN_released  = (ctlr_buttonDOWN_prev  == 1 && ctlr_buttonDOWN  == 0) ? 1 : 0;
  ctlr_buttonLEFT_released  = (ctlr_buttonLEFT_prev  == 1 && ctlr_buttonLEFT  == 0) ? 1 : 0;
  ctlr_buttonRIGHT_released = (ctlr_buttonRIGHT_prev == 1 && ctlr_buttonRIGHT == 0) ? 1 : 0;
}
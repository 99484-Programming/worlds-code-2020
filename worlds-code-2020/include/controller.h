#ifndef _Controller_H_
#define _Controller_H_

#include "vex.h"
#include "pragma.h"

extern int ctlr_axis1       ;
extern int ctlr_axis2       ;
extern int ctlr_axis3       ;
extern int ctlr_axis4       ;
extern int ctlr_buttonR1    ;
extern int ctlr_buttonR2    ;
extern int ctlr_buttonL1    ;
extern int ctlr_buttonL2    ;
extern int ctlr_buttonA     ;
extern int ctlr_buttonB     ;
extern int ctlr_buttonX     ;
extern int ctlr_buttonY     ;
extern int ctlr_buttonUP    ;
extern int ctlr_buttonDOWN  ;
extern int ctlr_buttonLEFT  ;
extern int ctlr_buttonRIGHT ;

extern int ctlr_axis1_prev       ;
extern int ctlr_axis2_prev       ;
extern int ctlr_axis3_prev       ;
extern int ctlr_axis4_prev       ;
extern int ctlr_buttonR1_prev    ;
extern int ctlr_buttonR2_prev    ;
extern int ctlr_buttonL1_prev    ;
extern int ctlr_buttonL2_prev    ;
extern int ctlr_buttonA_prev     ;
extern int ctlr_buttonB_prev     ;
extern int ctlr_buttonX_prev     ;
extern int ctlr_buttonY_prev     ;
extern int ctlr_buttonUP_prev    ;
extern int ctlr_buttonDOWN_prev  ;
extern int ctlr_buttonLEFT_prev  ;
extern int ctlr_buttonRIGHT_prev ;

extern int ctlr_buttonR1_pressed    ;
extern int ctlr_buttonR2_pressed    ;
extern int ctlr_buttonL1_pressed    ;
extern int ctlr_buttonL2_pressed    ;
extern int ctlr_buttonA_pressed     ;
extern int ctlr_buttonB_pressed     ;
extern int ctlr_buttonX_pressed     ;
extern int ctlr_buttonY_pressed     ;
extern int ctlr_buttonUP_pressed    ;
extern int ctlr_buttonDOWN_pressed  ;
extern int ctlr_buttonLEFT_pressed  ;
extern int ctlr_buttonRIGHT_pressed ;

extern int ctlr_buttonR1_released    ;
extern int ctlr_buttonR2_released    ;
extern int ctlr_buttonL1_released    ;
extern int ctlr_buttonL2_released    ;
extern int ctlr_buttonA_released     ;
extern int ctlr_buttonB_released     ;
extern int ctlr_buttonX_released     ;
extern int ctlr_buttonY_released     ;
extern int ctlr_buttonUP_released    ;
extern int ctlr_buttonDOWN_released  ;
extern int ctlr_buttonLEFT_released  ;
extern int ctlr_buttonRIGHT_released ;

void ctlr_updateVars();

#endif
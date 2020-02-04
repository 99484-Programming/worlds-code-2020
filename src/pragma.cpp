#include "vex.h"
#include "motor/class.h"

vex::brain            Brain;
vex::competition Competition;

vex::controller Controller_1 = vex::controller();
  
// ================ name =========== port ======== reverse = slew? = voltage? = act pwr = tar pwr = rot === d rot
Motor left_front  ( "left front"   , vex::PORT13 , false   , false , false    , false   , false   , true  , false );
Motor left_back   ( "left back"    , vex::PORT14 , false   , false , false    , false   , false   , true  , false );
Motor right_front ( "right front"  , vex::PORT20 , true    , false , false    , false   , false   , true  , false );
Motor right_back  ( "right back"   , vex::PORT19 , true    , false , false    , false   , false   , true  , false );
Motor intake_l    ( "left intake"  , vex::PORT2  , false   , false , false    , false   , false   , true  , false );
Motor intake_r    ( "right intake" , vex::PORT10 , true    , false , false    , false   , false   , true  , false );
Motor tilter      ( "tilter"       , vex::PORT11 , false   , false , false    , false   , false   , true  , false );
Motor arm         ( "arm"          , vex::PORT9  , false   , false , false    , false   , false   , true ,  false );

std::list<Motor> Motors = {left_front  ,
/* ==================== */ left_back   ,
/* ==================== */ right_front ,
/* ==================== */ right_back  ,
/* ==================== */ intake_l    ,
/* ==================== */ intake_r    ,
/* ==================== */ tilter     };
#include <kipr/wombat.h>
#include "arm.h"
#include "door.h"
#include "reset.h"
#include "drive.h"
#include "turns.h"

int main()
    
{   
    // reset the robot.
    full_reset();
    
    right_ninety_degree_tank_turn();
    
    // Drive up to the center black line.
    
	drive_until_right_black();
    
    drive_until_right_white();
    
    drive_until_right_black();
    
    drive_until_right_white();
    
    drive_in_centimeters(5);
    
    right_ninety_degree_tank_turn();
    
    // Start following the center black line.
    
    follow_the_black_line_in_centimeters(130);
    
    // Start halfway turning towards the bottles to open the door.
    
    left_fourty_five_degree_tank_turn();
    
    door_open();
    
    backup_in_centimeters(1);
    
    // Turn the rest of the way.
    
    left_slightly_smaller_than_fourty_five_degree_tank_turn();
    
    drive_in_centimeters(1);
    
    drive_until_front_bump();
    
    drive_in_centimeters(5);
    
    // Begin to pick up the bottles.
    
    arm_down();
    
    door_close();
    
    arm_up();
    
    backup_in_centimeters(5);
    
    ao();
    msleep(1000);
    
    // Turn to the beverage station.
    
    right_one_hundred_and_eighty_degree_tank_turn();
    
    drive_in_centimeters(5);
    
    right_ninety_degree_tank_turn();
    
    follow_the_black_line_in_centimeters(40);
    
    // Prepare to set the bottles in the beverage station.
    
    left_ninety_degree_tank_turn();
    
    drive_in_centimeters(10);
    
    // Set down the bottles into the beverage station.
    
    arm_down();
    
    door_open();
    
    arm_up();
    
    
    // Back away after setting the bottles down.
    
    backup_in_centimeters(20);
    
    door_close();

    return 0;
}

#define ARM 1
#define UP 0
#define DOWN 838

void arm_up() {
    /*
    set_servo_position(ARM, UP);
    enable_servos();
    printf("Current arm servo position is: %d\n", get_servo_position(ARM));
    
    int current = get_servo_position(ARM);
    
    int increment = 10;
    while (current > 0) {
        if (current - increment > 0) {
            current -= 10;
        } else {
            break;
        }
        
		set_servo_position(ARM, current);
        msleep(200);
        printf("Current arm servo position is: %d\n", get_servo_position(ARM));
    }
	disable_servo(ARM);
    */

    // Enable the Servos.
    enable_servos();
    
    printf("[arm_up] Servo Enabled %d\n.", get_servo_enabled(ARM));

    // Print the arms initial servo position.
    printf("[arm_up] The arm's servo position is at %d.\n", get_servo_position(ARM));

    int location_to_move_to = get_servo_position(ARM);

    // While the arm's current position is greater than up.
    while(get_servo_position(ARM) > UP) {
		
        location_to_move_to = get_servo_position(ARM) - 20;
        printf("[arm_up] Planning to move to %d\n.", location_to_move_to);
        
        // Determine the amount to move.
        if(location_to_move_to < UP) {
            break;
        }
        
        // Lift the arm a tiny bit.
        set_servo_position(ARM, location_to_move_to);
        msleep(200);

        // Print the arm's current position!
        printf("[arm_up] The arm is lifting but is currently at %d.\n",get_servo_position(ARM));
    } 
}

void arm_up_fast() {
    // Enable the Servos.
    enable_servos();
    
    set_servo_position(ARM, UP);
}

// arm down.
void arm_down() {
    
    // enable the servos.
    enable_servos();
    printf("[ARM_DOWN] The servo is at %d!\n",get_servo_position(ARM));
    
    // While the arm's servo position is less than down.
    while(get_servo_position(ARM) < DOWN) {
        
        // Slowly lower the arm.
        set_servo_position(ARM, get_servo_position(ARM) + 70);
        msleep(200);
        printf("[ARM_DOWN] The arm is lowering but is currently at %d\n",get_servo_position(ARM));
    } 
}

// arm up.
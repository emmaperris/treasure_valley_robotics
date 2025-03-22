#define ARM 1
#define UP 0
#define DOOR 0
#define CLOSED 20


void arm_reset() {
    set_servo_position(ARM,UP);
    // Enable the Servos.
    enable_servos();

    printf("[arm_reset] Servo Enabled %d\n.", get_servo_enabled(ARM));

    // Print the arms initial servo position.
    printf("[arm_reset] The arm's servo position is at %d.\n", get_servo_position(ARM));

    int location_to_move_to = 0;

    // While the arm's current position is greater than up.
    while(get_servo_position(ARM) - 30 > UP) {

        // Determine the amount to move.
        location_to_move_to = get_servo_position(ARM) - 20;
        printf("[arm_reset] Planning to move to %d\n.", location_to_move_to);
        
        // Determine the amount to move.
        if(location_to_move_to < UP) {
            break;
        }

        // Lift the arm a tiny bit.
        set_servo_position(ARM, location_to_move_to);
        msleep(200);

        // Print the arm's current position!
        printf("[arm_reset] The arm is lifting but is currently at %d.\n",get_servo_position(ARM));
    } 
}

void door_reset() {
    
    set_servo_position(DOOR,CLOSED);

    // enable the servos.
    enable_servos();

    // Print if the servo is enabled or not.
    printf("The door servo being enabled is %d!\n",get_servo_enabled(DOOR));

    // Set a new integer to zero.
    int amount_to_close = 0;

    // While the door's servo is less than open.
    while(get_servo_position(DOOR) > CLOSED) {

        // Update amount to open integer.
        amount_to_close = get_servo_position(DOOR) - 70;
        
        if(amount_to_close < CLOSED) {
            break;
        }

        // Set the servo position.
        set_servo_position(DOOR, amount_to_close);
        msleep(200);

        // Print how much we just opened and what our door's current position is.
        printf("We just closed %d! Our current position is %d.\n",amount_to_close,get_servo_position(DOOR));
    } 
}


void full_reset() {

    printf("We are doing a full reset.\n");

    door_reset();
    arm_reset();
    ao();
    msleep(1000);
}
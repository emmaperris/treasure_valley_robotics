#define DOOR 0
#define CLOSED 20
#define OPEN 1300
        
// in and out.
// door open.
void door_open() {

    // enable the servos.
    enable_servos();
    
    // Print if the servo is enabled or not.
    printf("The door servo being enabled is %d!\n",get_servo_enabled(DOOR));
    
    // Set a new integer to zero.
    int amount_to_open = 0;
    
    // While the door's servo is less than open.
    while(get_servo_position(DOOR) < OPEN) {
        
        // Update amount to open integer.
        amount_to_open = get_servo_position(DOOR) + 70;
        
        // Set the servo position.
        set_servo_position(DOOR, amount_to_open);
        msleep(200);
        
        // Print how much we just opened and what our door's current position is.
        printf("We just opened %d! Our current position is %d.\n",amount_to_open,get_servo_position(DOOR));
    } 
}

// door closed.
void door_close() {

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
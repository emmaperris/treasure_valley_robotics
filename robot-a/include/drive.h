#define RIGHT_BACK_WHEEL 0
#define RIGHT_FRONT_WHEEL 1
#define LEFT_FRONT_WHEEL 2
#define LEFT_BACK_WHEEL 3
#define RIGHT_TOPHAT 1
#define LEFT_TOPHAT 2
#define LIGHT_SENSOR 0
#define FRONT_BUMP 0
#define BACK_BUMP 1
#define FULL_POWER 100
#define THREE_QUARTERS_POWER 75
#define HALF_POWER 50
#define QUARTER_POWER 25
#define REVERSE_FULL_POWER -100
#define REVERSE_THREE_QUARTERS_POWER -75
#define REVERSE_HALF_POWER -50
#define REVERSE_QUARTER_POWER -25
#define OFF 0
#define LEFT_BLACK 1000
#define RIGHT_BLACK 3800
#define ONE_CENTIMETER 75
#define SECOND 1000

void drive_until_right_black() {
    // While the right tophat sensor value is less than that sensor's black.
    while(analog(RIGHT_TOPHAT) < RIGHT_BLACK) {

        // Power all the motors.
        motor(RIGHT_BACK_WHEEL, HALF_POWER);
        motor(RIGHT_FRONT_WHEEL, HALF_POWER);
        motor(LEFT_FRONT_WHEEL, HALF_POWER);
        motor(LEFT_BACK_WHEEL, HALF_POWER);

        // How often to check.
        msleep(200);

        printf("The right tophat sensor's value is %d. Still searching for black.\n",analog(RIGHT_TOPHAT));
    }

    printf("We found black! Right tophat sensor's value is %d!\n",analog(RIGHT_TOPHAT));
    ao();
    msleep(500);
}

void drive_until_right_white() {
    // While the right tophat sensor value is less than that sensor's black.
    while(analog(RIGHT_TOPHAT) > RIGHT_BLACK) {

        // Power all the motors.
        motor(RIGHT_BACK_WHEEL, HALF_POWER);
        motor(RIGHT_FRONT_WHEEL, HALF_POWER);
        motor(LEFT_FRONT_WHEEL, HALF_POWER);
        motor(LEFT_BACK_WHEEL, HALF_POWER);

        // How often to check.
        msleep(200);

        printf("The right tophat sensor's value is %d. Still looking for white.\n",analog(RIGHT_TOPHAT));
    }

    printf("We can see white! Right tophat sensor's value is currently %d!\n",analog(RIGHT_TOPHAT));
    ao();
    msleep(500);
}

void drive_in_centimeters(int centimeters) {
    printf("I'm driving forward, using centimeters!\n");
    
    // Clear all the motors.

    clear_motor_position_counter(RIGHT_FRONT_WHEEL);
    clear_motor_position_counter(RIGHT_BACK_WHEEL);
    clear_motor_position_counter(LEFT_FRONT_WHEEL);
    clear_motor_position_counter(LEFT_BACK_WHEEL);

    int distance_to_travel = ONE_CENTIMETER * centimeters;
    int distance_traveled = 0;
    
    // While distance traveled is less than distance to travel.

    while(distance_traveled < distance_to_travel) {
        
        // All motors drive forward at full power.
        
        motor(RIGHT_FRONT_WHEEL, FULL_POWER);
        motor(RIGHT_BACK_WHEEL, FULL_POWER);
        motor(LEFT_FRONT_WHEEL, FULL_POWER);
        motor(LEFT_BACK_WHEEL, FULL_POWER);
        printf("%d\n", distance_traveled);
        printf("%d\n", distance_to_travel);
        msleep(200);
        
        // Set distance traveled to the current motor position. 
        
        distance_traveled = get_motor_position_counter(RIGHT_FRONT_WHEEL);
        printf("%d centimeters forwards\n", (distance_traveled / ONE_CENTIMETER));
    }
    ao();
}

void follow_the_black_line_in_centimeters(int centimeters) {
    printf("I'm following the black line, using centimeters!\n");
    
    // Clear all motors.

    clear_motor_position_counter(RIGHT_FRONT_WHEEL);
    clear_motor_position_counter(RIGHT_BACK_WHEEL);
    clear_motor_position_counter(LEFT_FRONT_WHEEL);
    clear_motor_position_counter(LEFT_BACK_WHEEL);

    int distance_to_travel = ONE_CENTIMETER * centimeters;
    int distance_traveled = 0;
    
    // While distance traveled is less than distance to travel.

    while(distance_traveled < distance_to_travel) {
        
        // If the right tophat sensor is on white.
        
        if(analog(RIGHT_TOPHAT) < RIGHT_BLACK) {

            printf("We are turning to the left!\n");
            
            // Turn to the left.

            motor(RIGHT_FRONT_WHEEL, HALF_POWER);
            motor(LEFT_FRONT_WHEEL, OFF);
            motor(LEFT_BACK_WHEEL, OFF);
            motor(RIGHT_BACK_WHEEL, HALF_POWER);
            
            // Reset distance traveled.
            
            distance_traveled = get_motor_position_counter(RIGHT_FRONT_WHEEL) + get_motor_position_counter(LEFT_FRONT_WHEEL) ;
        }
        
        // If the right tophat sensor is on black.

        if(analog(RIGHT_TOPHAT) > RIGHT_BLACK) {

            printf("We are turning to the right!\n");
            
            // Turn to the right.

            motor(RIGHT_FRONT_WHEEL, OFF);
            motor(LEFT_FRONT_WHEEL, HALF_POWER);
            motor(LEFT_BACK_WHEEL, HALF_POWER);
            motor(RIGHT_BACK_WHEEL, OFF);
            
            // Reset distance traveled.
            
            distance_traveled = get_motor_position_counter(LEFT_FRONT_WHEEL) + get_motor_position_counter(RIGHT_FRONT_WHEEL);
        }
    }
    ao();
}

void follow_the_black_line(int time) {
    time = time * 1000;
    int time_passed = 0;
    
    // While time that has passed is less than time, the argument passed in when the function is called in main, run this loop.

    while(time_passed < time) {

        // If the right tophat sensor is on black.
        
        if(analog(RIGHT_TOPHAT) > RIGHT_BLACK) {

            printf("We are turning to the left!\n");
            
            // Turn to the left.

            motor(RIGHT_FRONT_WHEEL, HALF_POWER);
            motor(LEFT_FRONT_WHEEL, OFF);
            motor(LEFT_BACK_WHEEL, OFF);
            motor(RIGHT_BACK_WHEEL, HALF_POWER);
        }
        
        // If the right tophat sensor is on white.

        if(analog(RIGHT_TOPHAT) < RIGHT_BLACK) {

            printf("We are turning to the right!\n");
            
            // Turn to the right.

            motor(RIGHT_FRONT_WHEEL, OFF);
            motor(LEFT_FRONT_WHEEL, HALF_POWER);
            motor(LEFT_BACK_WHEEL, HALF_POWER);
            motor(RIGHT_BACK_WHEEL, OFF);

        }
        msleep(150);
        
        // Reset time passed.
        time_passed = time_passed + 250;
    }
}

void backup_in_centimeters(int centimeters) {
    printf("I'm driving forward, using centimeters!\n");
    
    // Clear all the motors.

    clear_motor_position_counter(RIGHT_FRONT_WHEEL);
    clear_motor_position_counter(RIGHT_BACK_WHEEL);
    clear_motor_position_counter(LEFT_FRONT_WHEEL);
    clear_motor_position_counter(LEFT_BACK_WHEEL);

    int distance_to_travel = -(ONE_CENTIMETER * centimeters);
    int distance_traveled = 0;
    
    // While distance traveled is less than distance to travel.

    while(distance_traveled > distance_to_travel) {
        
        // All motors run in reverse.
        
        motor(RIGHT_FRONT_WHEEL, REVERSE_HALF_POWER);
        motor(RIGHT_BACK_WHEEL, REVERSE_HALF_POWER);
        motor(LEFT_FRONT_WHEEL, REVERSE_HALF_POWER);
        motor(LEFT_BACK_WHEEL, REVERSE_HALF_POWER);
        printf("%d\n", distance_traveled);
        printf("%d\n", distance_to_travel);
        msleep(200);
        
        // Reset distance traveled. 
        
        distance_traveled = get_motor_position_counter(RIGHT_FRONT_WHEEL);
        printf("%d centimeters forwards\n", (distance_traveled / ONE_CENTIMETER));
    }
    ao();
}

void drive_until_front_bump() {
    printf("We are driving until our front bump sensor bumps something!\n");
    
    // While the front bump sensor is not currently pressed.
    
    while(digital(FRONT_BUMP) < 1) {
        
        // All motors drive forward.
        
        motor(LEFT_FRONT_WHEEL, HALF_POWER);
        motor(RIGHT_FRONT_WHEEL, HALF_POWER);
        motor(LEFT_BACK_WHEEL, HALF_POWER);
        motor(RIGHT_BACK_WHEEL, HALF_POWER);
        msleep(SECOND * 0.25);
    }
    printf("We bumped something with our front bump sensor!\n");
    ao();
}
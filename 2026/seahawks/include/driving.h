#define FULL_POWER 1000
#define THREE_QUARTERS_POWER 750
#define HALF_POWER 500
#define QUARTER_POWER 250
#define REVERSE_FULL_POWER -1000
#define REVERSE_THREE_QUARTERS_POWER -750
#define REVERSE_HALF_POWER -500
#define REVERSE_QUARTER_POWER -250
#define FRONT_LEFT_MOTOR 2
#define FRONT_RIGHT_MOTOR 1
#define BACK_LEFT_MOTOR 0
#define BACK_RIGHT_MOTOR 3
#define LIGHT_SENSOR 0
#define RIGHT_TOPHAT_SENSOR 1
#define LEFT_TOPHAT_SENSOR
#define BLACK 3000
#define SECOND 1000
#define 90_DEGREES 1.8
#define ONE_CENTIMETER 75

// LIST OF NECESSARY FUNCTIONS:

// DRIVING UNTIL FUNCTIONS:

// TOPHAT SENSOR BASED:

// drive_until_both_black

// drive_until_left_black

// drive_until_right_black

// crab_walk_left_until_left_black

// crab_walk_right_until_left_black

// crab_walk_left_until_right_black

// crab_walk_right_until_right_black

// backup_until_both_black

// backup_until_left_black

// backup_until_right_black

// square_up_on_black

// backup_and_square_up_on_black

// follow_the_line_until_both_black

// BUMP SENSOR BASED:

// drive_until_front_bump

// backup_until_back_bump

// DRIVING IN AMOUNT FUNCTIONS:

// drive_in_centimeters

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

        // All motors drive forward at half power.

        mav(RIGHT_FRONT_WHEEL, HALF_POWER);
        mav(RIGHT_BACK_WHEEL, HALF_POWER);
        mav(LEFT_FRONT_WHEEL, HALF_POWER);
        mav(LEFT_BACK_WHEEL, HALF_POWER);
        printf("%d\n", distance_traveled);
        printf("%d\n", distance_to_travel);
        msleep(200);

        // Set distance traveled to the current motor position. 

        distance_traveled = get_motor_position_counter(RIGHT_FRONT_WHEEL);
        printf("%d centimeters forwards\n", (distance_traveled / ONE_CENTIMETER));
    }
    ao();
}

// backup_in_centimeters

// turn_right_in_centimeters

// turn_left_in_centimeters

// follow_the_line_in_centimeters

// crab_walk_left_in_centimeters

void crab_walk_left_in_centimeters(int centimeters) {
    printf("I'm crabwalking to the left, using centimeters!\n");

    // Clear all the motors.

    clear_motor_position_counter(FRONT_RIGHT_MOTOR);
    clear_motor_position_counter(BACK_RIGHT_MOTOR);
    clear_motor_position_counter(FRONT_LEFT_MOTOR);
    clear_motor_position_counter(BACK_LEFT_MOTOR);

    int distance_to_travel = ONE_CENTIMETER * centimeters;
    int distance_traveled = 0;

    // While distance traveled is less than distance to travel.

    while(distance_traveled < distance_to_travel) {

        // All motors drive forward at full power.

        mav(RIGHT_FRONT_WHEEL, QUARTER_POWER);
        mav(RIGHT_BACK_WHEEL, REVERSE_QUARTER_POWER);
        mav(LEFT_FRONT_WHEEL, REVERSE_QUARTER_POWER);
        mav(LEFT_BACK_WHEEL, QUARTER_POWER);
        printf("%d\n", distance_traveled);
        printf("%d\n", distance_to_travel);
        msleep(200);

        // Set distance traveled to the current motor position. 

        distance_traveled = get_motor_position_counter(RIGHT_FRONT_WHEEL);
        printf("%d centimeters forwards\n", distance_traveled);
    }
    ao();
}

// crab_walk_right_in_centimeters

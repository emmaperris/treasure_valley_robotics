#define RIGHT_BACK_WHEEL 0
#define RIGHT_FRONT_WHEEL 1
#define LEFT_FRONT_WHEEL 2
#define LEFT_BACK_WHEEL 3
#define RIGHT_TOPHAT 1
#define LEFT_TOPHAT 2
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
#define NINETY_DEGREES 2700
#define FOURTY_FIVE_DEGREES 1325
#define TWENTY_THREE_DEGREES 713
#define ONE_HUNDRED_AND_EIGHTY_DEGREES 5400

void right_ninety_degree_tank_turn() {
    
  	// Turn to the right.
    
    motor(RIGHT_FRONT_WHEEL, REVERSE_HALF_POWER);
    motor(RIGHT_BACK_WHEEL, REVERSE_HALF_POWER);
    motor(LEFT_FRONT_WHEEL, HALF_POWER);
    motor(LEFT_BACK_WHEEL, HALF_POWER);
    msleep(NINETY_DEGREES);
    
    // Stop for one second.
    
    ao();
    msleep(1000);
}

void right_one_hundred_and_eighty_degree_tank_turn() {
    
    // Turn to the right.
    
    motor(RIGHT_FRONT_WHEEL, REVERSE_HALF_POWER);
    motor(RIGHT_BACK_WHEEL, REVERSE_HALF_POWER);
    motor(LEFT_FRONT_WHEEL, HALF_POWER);
    motor(LEFT_BACK_WHEEL, HALF_POWER);
    msleep(ONE_HUNDRED_AND_EIGHTY_DEGREES);
    
    // Stop for one second.
    
    ao();
    msleep(1000);
}

void right_twenty_three_degree_tank_turn() {
    
    // Turn to the right.
    
    motor(RIGHT_FRONT_WHEEL, REVERSE_HALF_POWER);
    motor(RIGHT_BACK_WHEEL, REVERSE_HALF_POWER);
    motor(LEFT_FRONT_WHEEL, HALF_POWER);
    motor(LEFT_BACK_WHEEL, HALF_POWER);
    msleep(TWENTY_THREE_DEGREES);
    
    // Stop for one second.
    
    ao();
    msleep(1000);
}

void left_ninety_degree_tank_turn() {
    
    // Turn to the left.
    
    motor(LEFT_FRONT_WHEEL, REVERSE_HALF_POWER);
    motor(LEFT_BACK_WHEEL, REVERSE_HALF_POWER);
    motor(RIGHT_FRONT_WHEEL, HALF_POWER);
    motor(RIGHT_BACK_WHEEL, HALF_POWER);
    msleep(NINETY_DEGREES);
    
    // Stop for one second.
    
    ao();
    msleep(1000);
}

void left_fourty_five_degree_tank_turn() {
    
    // Turn to the left.
    
    motor(LEFT_FRONT_WHEEL, REVERSE_HALF_POWER);
    motor(LEFT_BACK_WHEEL, REVERSE_HALF_POWER);
    motor(RIGHT_FRONT_WHEEL, HALF_POWER);
    motor(RIGHT_BACK_WHEEL, HALF_POWER);
    msleep(FOURTY_FIVE_DEGREES);
    
    // Stop for one second.
    
    ao();
    msleep(1000);
}

void left_slightly_smaller_than_fourty_five_degree_tank_turn() {
    
    // Turn to the left.
    
    motor(LEFT_FRONT_WHEEL, REVERSE_HALF_POWER);
    motor(LEFT_BACK_WHEEL, REVERSE_HALF_POWER);
    motor(RIGHT_FRONT_WHEEL, HALF_POWER);
    motor(RIGHT_BACK_WHEEL, HALF_POWER);
    msleep(1200);
    
    // Stop for one second.
    
    ao();
    msleep(1000);
}
    
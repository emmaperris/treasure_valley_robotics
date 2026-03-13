#include <kipr/wombat.h>

#define HALFPOWER 50
#define QUARTERPOWER 15
#define FULLPOWER 100
#define STOP 0
#define MOTORRIGHT 3
#define MOTORLEFT 0
#define SECOND 1000
#define LIGHTSENSOR 0  //analog
#define BUMPSENSOR 0  //digital
#define TOPHATRIGHT 2
#define TOPHATLEFT 1
#define TOPHATRIGHTBACK 4
#define TOPHATLEFTBACK 3
#define BLACK 4000
//

// Drive until both front tophat sensors hit white.
void drive_until_both_white() { 

    while (analog(TOPHATRIGHT || TOPHATLEFT) > BLACK) {

        if (analog(TOPHATRIGHT) > BLACK) {
            motor(MOTORLEFT, HALFPOWER);
            msleep(SECOND * 0.2);
        }

        if (analog(TOPHATLEFT) > BLACK) {
            motor(MOTORRIGHT, HALFPOWER);
            msleep(SECOND * 0.2);
        }

    }

}


// Drive until both front tophat sensors hit black.
void drive_until_both_black() { 

    while (analog(TOPHATRIGHT || TOPHATLEFT) < BLACK) {

        if (analog(TOPHATRIGHT) < BLACK) {
            motor(MOTORLEFT, HALFPOWER);
            msleep(SECOND * 0.2);
        }

        if (analog(TOPHATLEFT) < BLACK) {
            motor(MOTORRIGHT, HALFPOWER);
            msleep(SECOND * 0.2);
        }

    }

}


// Drive until both back tophat sensors hit white.
void drive_until_both_white_back() { 

    while (analog(TOPHATRIGHTBACK || TOPHATLEFTBACK) > BLACK) {

        if (analog(TOPHATRIGHTBACK) > BLACK) {
            motor(MOTORLEFT, HALFPOWER * -1);
            msleep(SECOND * 0.2);
        }

        if (analog(TOPHATLEFTBACK) > BLACK) {
            motor(MOTORRIGHT, HALFPOWER * -1);
            msleep(SECOND * 0.2);
        }

    }

}


// Drive until both back tophat sensors hit black.
void drive_until_both_black_back() { 

    while (analog(TOPHATRIGHTBACK || TOPHATLEFTBACK) < BLACK) {

        if (analog(TOPHATRIGHTBACK) < BLACK) {
            motor(MOTORLEFT, HALFPOWER * -1);
            msleep(SECOND * 0.2);
        }

        if (analog(TOPHATLEFTBACK) < BLACK) {
            motor(MOTORRIGHT, HALFPOWER * -1);
            msleep(SECOND * 0.2);
        }

    }

}


// Follow the black line until both front tophat sensors hit black.
void follow_black_line_until_both_black() {

    while (analog(TOPHATRIGHT || TOPHATLEFT) < BLACK) {

        if (analog(TOPHATRIGHT) > BLACK) {
            motor(MOTORLEFT, HALFPOWER);
            motor(MOTORRIGHT, STOP);
            msleep(SECOND * 0.2);
        }

        if (analog(TOPHATLEFT) > BLACK) {
            motor(MOTORLEFT, STOP);
            motor(MOTORRIGHT, HALFPOWER);
            msleep(SECOND * 0.2);
        }

    }

}


// Follow the black line BACKWARDS until both back tophat sensors hit black.
void follow_black_line_until_both_black_backwards() {

    while (analog(TOPHATRIGHTBACK || TOPHATLEFTBACK) < BLACK) {

        if (analog(TOPHATRIGHTBACK) > BLACK) {
            motor(MOTORLEFT, HALFPOWER * -1);
            motor(MOTORRIGHT, STOP);
            msleep(SECOND * 0.2);
        }

        if (analog(TOPHATLEFTBACK) > BLACK) {
            motor(MOTORLEFT, STOP);
            motor(MOTORRIGHT, HALFPOWER * -1);
            msleep(SECOND * 0.2);
        }

    }

}


// Follow the black line with just the right sensor.
void follow_black_line_on_right() {

    while(analog(TOPHATLEFT) < BLACK) {

        if(analog(TOPHATRIGHT) > BLACK) {
            motor(MOTORRIGHT, HALFPOWER);
            motor(MOTORLEFT, STOP);
            msleep(SECOND * 0.2);
        }

        if(analog(TOPHATRIGHT) < BLACK) {
            motor(MOTORRIGHT, STOP);
            motor(MOTORLEFT, HALFPOWER);
            msleep(SECOND * 0.2);
        }

    }

}


// Follow the black line with just the left sensor.
void follow_black_line_on_left() {

    while(analog(TOPHATRIGHT) < BLACK) {

        if(analog(TOPHATLEFT) > BLACK) {
            motor(MOTORRIGHT, STOP);
            motor(MOTORLEFT, HALFPOWER);
            msleep(SECOND * 0.2);
        }

        if(analog(TOPHATLEFT) > BLACK) {
            motor(MOTORRIGHT, HALFPOWER);
            motor(MOTORLEFT, STOP);
            msleep(SECOND * 0.2);
        }

    }

}


// Follow the black line for X amount of time.
void follow_black_line_for_time(int time) {

    int current_time = 0;

    while (current_time < time) {

        if (analog(TOPHATRIGHTBACK) > BLACK) {
            motor(MOTORLEFT, HALFPOWER * -1);
            motor(MOTORRIGHT, STOP);
            msleep(SECOND * 0.2);
        }

        if (analog(TOPHATLEFTBACK) > BLACK) {
            motor(MOTORLEFT, STOP);
            motor(MOTORRIGHT, HALFPOWER * -1);
            msleep(SECOND * 0.2);
        }

        current_time = current_time + 1;

    }

}


// Follow the black line with back sensors for X amount of time.
//NOT FINFISHED
void follow_black_line_for_time_backwards(int time) {

    int current_time = 0;

    while (current_time < time) {

        if (analog(TOPHATRIGHT) > BLACK) {
            motor(MOTORLEFT, HALFPOWER);
            motor(MOTORRIGHT, STOP);
            msleep(SECOND * 0.2);
        }

        if (analog(TOPHATLEFT) > BLACK) {
            motor(MOTORLEFT, STOP);
            motor(MOTORRIGHT, HALFPOWER);
            msleep(SECOND * 0.2);
        }

        current_time = current_time + 1;

    }

}


// Wait for X amount of time.
void wait_for_time(int time) {

    int current_time = 0;

    while(current_time < time) {
        ao();
        current_time = current_time + 1;
    }

}


// Turn left into the black line.
void black_line_left_turn() {

    while(analog(TOPHATRIGHT) < BLACK) {
        motor(MOTORRIGHT, QUARTERPOWER);
        motor(MOTORLEFT, HALFPOWER);
        msleep(SECOND * 0.2);
    }

}


// Turn right into the black line.
void black_line_right_turn() {

    while(analog(TOPHATLEFT) < BLACK) {
        motor(MOTORLEFT, QUARTERPOWER);
        motor(MOTORRIGHT, HALFPOWER);
        msleep(SECOND * 0.2);
    }

}


// Turn left until white is sensed.
void white_space_left_turn() {

    while(analog(TOPHATRIGHT) > BLACK) {
        motor(MOTORRIGHT, QUARTERPOWER);
        motor(MOTORLEFT, HALFPOWER);
        msleep(SECOND * 0.2);
    }

}


// Turn right until white is sensed.
void white_space_right_turn() {

    while(analog(TOPHATLEFT) > BLACK) {
        motor(MOTORLEFT, QUARTERPOWER);
        motor(MOTORRIGHT, HALFPOWER);
        msleep(SECOND * 0.2);
    }

}


// Turn left into black line directly (no other wheel movement).
void black_line_left_turn_direct() {

    while(analog(TOPHATRIGHT) < BLACK) {
        motor(MOTORRIGHT, STOP);
        motor(MOTORLEFT, HALFPOWER);
        msleep(SECOND * 0.2);
    }

}


// Turn right into black line directly (no other wheel movement).
void black_line_right_turn_direct() {

    while(analog(TOPHATLEFT) < BLACK) {
        motor(MOTORRIGHT, HALFPOWER);
        motor(MOTORLEFT, STOP);
        msleep(SECOND * 0.2);
    }

}


// Turn left until white is sensed directly (no other wheel movement).
void white_space_left_turn_direct() {

    while(analog(TOPHATRIGHT) > BLACK) {
        motor(MOTORRIGHT, STOP);
        motor(MOTORLEFT, HALFPOWER);
        msleep(SECOND * 0.2);
    }

}


// Turn right until white is sensed directly (no other wheel movement).
void white_space_right_turn_direct() {

    while(analog(TOPHATLEFT) > BLACK) {
        motor(MOTORRIGHT, HALFPOWER);
        motor(MOTORLEFT, STOP);
        msleep(SECOND * 0.2);
    }

}


// Back up while turning to the left until bump sensor is pressed.
void back_bump_left_turn() {

    while(digital(BUMPSENSOR) < 1) {
        motor(MOTORRIGHT, QUARTERPOWER * -1);
        motor(MOTORLEFT, HALFPOWER * -1);
        msleep(SECOND * 0.2);
    }

}


//
// Set the servo position greater and move safely to the position.
void position_servo_greater(int servo, int desired_servo_position) {

    int current_servo_position = get_servo_position(servo);
    enable_servos();

    while (current_servo_position < desired_servo_position) {
        set_servo_position(servo, current_servo_position + 20);
        current_servo_position = current_servo_position + 20;
    }
    disable_servos();

}


// Set the servo position less and move safely to the position.
void position_servo_less(int servo, int desired_servo_position) {

    int current_servo_position = get_servo_position(servo);
    enable_servos();

    while (current_servo_position > desired_servo_position) {
        set_servo_position(servo, current_servo_position - 20);
        current_servo_position = current_servo_position - 20;
    }
    disable_servos();

}


//
int main()
{   
    /*
    black_line_left_turn();
    printf("ONE\n");

    white_space_left_turn();
    printf("two\n");

    black_line_left_turn();
    printf("three\n");

    white_space_left_turn();
    printf("four\n");
    */
    follow_black_line_on_right();
    printf("five\n");
    /*
    drive_until_both_white();

    black_line_right_turn();

    drive_until_both_white();

    drive_until_both_black();

    black_line_right_turn_direct();

    white_space_right_turn_direct();

    black_line_right_turn_direct();

    follow_black_line_until_both_black();

    follow_black_line_until_both_black_backwards();
    */

    printf("RUN COMPLETE\n");
    return 0;
}
//

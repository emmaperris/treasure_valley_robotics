#include <kipr/wombat.h>

#define SECOND 1000
#define LEFTMOTOR 3 
#define RIGHTMOTOR 0
#define HALFPOWERleft 51.5 
#define HALFPOWERright 50
#define HALFPOWERBACKWARDSright -50
#define HALFPOWERBACKWARDSleft -51.5
#define TOPHATright 0
#define TOPHATleft 1
#define PARALLELOGRAMSERVO 0
#define BLACK 3300
#define LEVERBUMPSENSOR 2
#define LIGHTSENSOR 0
#define PARALLELOGRAMOPEN 1000
#define PARALLELOGRAMCLOSED 50
#define MOTORROTATION 3100
#define CLAWOPERATIONMOTOR 2
#define CLAWHEIGHTMOTOR 1
#define HALFPOWERclaw 50
#define HALFPOWERBACKWARDSclaw -50
#define CLAWROTATION 11390

void close_parallelogram() {
    enable_servos();
    int current_servo_position = get_servo_position(PARALLELOGRAMSERVO);
    while(current_servo_position > PARALLELOGRAMCLOSED) {
        int increment = 20;
        if (current_servo_position - increment < PARALLELOGRAMCLOSED) {
            set_servo_position(PARALLELOGRAMSERVO, PARALLELOGRAMCLOSED);
        } else {
            set_servo_position(PARALLELOGRAMSERVO, current_servo_position - increment);
        }
        current_servo_position = get_servo_position(PARALLELOGRAMSERVO);
        msleep(SECOND * 0.1);
    }
    disable_servos();
}

void open_parallelogram() {
    printf("here");
    set_servo_position(PARALLELOGRAMSERVO, PARALLELOGRAMCLOSED);
    enable_servos();
    int increment = 20;
    int current_servo_position = get_servo_position(PARALLELOGRAMSERVO);
    printf("%d\n", current_servo_position);
    while(current_servo_position < PARALLELOGRAMOPEN) {
        current_servo_position = get_servo_position(PARALLELOGRAMSERVO);
        if (current_servo_position + increment > PARALLELOGRAMOPEN) {
            set_servo_position(PARALLELOGRAMSERVO, PARALLELOGRAMOPEN);
        } else {
            set_servo_position(PARALLELOGRAMSERVO, current_servo_position + increment);
        }
        current_servo_position = get_servo_position(PARALLELOGRAMSERVO);
        msleep(SECOND * 0.1);
    }
    disable_servos();
}

//raise the claw
void raise_claw() {
    clear_motor_position_counter(CLAWHEIGHTMOTOR);
    while(get_motor_position_counter(CLAWHEIGHTMOTOR) < MOTORROTATION) {
        motor(CLAWHEIGHTMOTOR, HALFPOWERclaw);
        msleep(SECOND * 0.2);
    }
    ao();
}

void lower_claw() {
    clear_motor_position_counter(CLAWHEIGHTMOTOR);
    while(get_motor_position_counter(CLAWHEIGHTMOTOR) > CLAWROTATION * -1) {
        motor(CLAWHEIGHTMOTOR, HALFPOWERclaw * -1);
        msleep(SECOND * 0.2);
    }
    ao();
}

void close_claw() {
    clear_motor_position_counter(CLAWOPERATIONMOTOR);
    while(get_motor_position_counter(CLAWOPERATIONMOTOR) > CLAWROTATION * -1) {
        printf("%d\n", get_motor_position_counter(CLAWOPERATIONMOTOR));
        motor(CLAWOPERATIONMOTOR, HALFPOWERclaw * -1);
        msleep(SECOND * 0.2);
    }
}

void open_claw() {
    clear_motor_position_counter(CLAWOPERATIONMOTOR);
    while(get_motor_position_counter(CLAWOPERATIONMOTOR) < CLAWROTATION) {
        printf("%d\n", get_motor_position_counter(CLAWOPERATIONMOTOR));
        motor(CLAWOPERATIONMOTOR, HALFPOWERclaw);
        msleep(SECOND * 0.2);
    }
}
void drive_until_bump() {
    while(digital(LEVERBUMPSENSOR) == 0) {

        if(analog(TOPHATright) < BLACK) {
            motor(RIGHTMOTOR, HALFPOWERright);
            motor(LEFTMOTOR, 0);
            msleep(SECOND * 0.5);
        }

        if(analog(TOPHATleft) < BLACK) {
            motor(LEFTMOTOR, HALFPOWERleft);
            motor(RIGHTMOTOR, 0);
            msleep(SECOND * 0.5);
        }
    }
}

int main()
{
    //rise_rotation();
    
    
    close_claw();


    /*

    //gradually turn until the black
    while(analog(TOPHATright) < BLACK || analog(TOPHATleft) < BLACK) {
        printf("analog0: %d  analog1: %d black: %d\n", analog(TOPHATright), analog(TOPHATleft), BLACK);
        motor(RIGHTMOTOR, 31.5);
        motor(LEFTMOTOR, HALFPOWERleft);
        msleep(SECOND * 0.2);
    }

    //drive until white
    while(analog(TOPHATright && TOPHATleft) > BLACK) {
        motor(RIGHTMOTOR, 31.5);
        motor(LEFTMOTOR, 30);
        msleep(SECOND * 0.2);
    }
    printf("White!\n");
    ao();

    //drive until black
    while(analog(TOPHATleft) < BLACK) {
        motor(RIGHTMOTOR, 45);
        motor(LEFTMOTOR, 43.5);
        msleep(SECOND * 0.2);
    }
    printf("Black!\n");
    ao();

    //drive until white
    while(analog(TOPHATleft && TOPHATright) > BLACK) {
        motor(RIGHTMOTOR, 31.5);
        motor(LEFTMOTOR, 30);
        msleep(SECOND * 0.2);
    }
    printf("White!\n");
    ao();

    //turn until left side hits black
    while(analog(TOPHATleft) < BLACK) {
        motor(LEFTMOTOR, 30);
        motor(RIGHTMOTOR, -31.5);
        msleep(SECOND * 0.2);
    }
    printf("On the line!\n");
    ao();

    //follow the black line
    //while both top hats are not on black.
    while(analog(TOPHATright) < BLACK || analog(TOPHATleft) < BLACK) {
        printf("analog0: %d  analog1: %d black: %d\n", analog(TOPHATright), analog(TOPHATleft), BLACK);

        if(analog(TOPHATright) < BLACK) {
            motor(RIGHTMOTOR, HALFPOWERright);
            motor(LEFTMOTOR, 0);
            msleep(SECOND * 0.5);
        }

        if(analog(TOPHATleft) < BLACK) {
            motor(LEFTMOTOR, HALFPOWERleft);
            motor(RIGHTMOTOR, 0);
            msleep(SECOND * 0.5);
        }

    }
    printf("analog0: %d  analog1: %d black: %d\n", analog(TOPHATright), analog(TOPHATleft), BLACK);
    printf("Both on Black!\n");
    ao();

    //follow the black line to the potato line
    // While both top hats are not on black.
    while(analog(TOPHATright) < BLACK || analog(TOPHATleft) < BLACK) {
        printf("analog0: %d  analog1: %d black: %d\n", analog(TOPHATright), analog(TOPHATleft), BLACK);

        if(analog(TOPHATright) < BLACK) {
            motor(RIGHTMOTOR, HALFPOWERright);
            motor(LEFTMOTOR, 0);
            msleep(SECOND * 0.5);
        }

        if(analog(TOPHATleft) < BLACK) {
            motor(LEFTMOTOR, HALFPOWERleft);
            motor(RIGHTMOTOR, 0);
            msleep(SECOND * 0.5);
        }

    }
    printf("analog0: %d  analog1: %d black: %d\n", analog(TOPHATright), analog(TOPHATleft), BLACK);
    printf("Both on Black!\n");
    ao();

    //turn a little bit
    motor(RIGHTMOTOR, HALFPOWERright);
    msleep(SECOND * 1.5);

    //turn until white
    while(analog(TOPHATright) < BLACK) {
        motor(RIGHTMOTOR, HALFPOWERright);
        msleep(SECOND * 0.5);
    }

    //drive until bump on Potato Pole
    while(LEVERBUMPSENSOR == 0) {

        if(analog(TOPHATright) < BLACK) {
            motor(RIGHTMOTOR, HALFPOWERright);
            motor(LEFTMOTOR, 0);
            msleep(SECOND * 0.5);
        }

        if(analog(TOPHATleft) < BLACK) {
            motor(LEFTMOTOR, HALFPOWERleft);
            motor(RIGHTMOTOR, 0);
            msleep(SECOND * 0.5);
        }
    }

    //back up a bit
    motor(RIGHTMOTOR, HALFPOWERBACKWARDSright);
    motor(LEFTMOTOR, HALFPOWERBACKWARDSleft);
    msleep(SECOND * 0.5);

    //grab the potato
    //close the claw
    void close_rotation() {
        clear_motor_position_counter(CLAWOPERATIONMOTOR);
        while(get_motor_position_counter(CLAWOPERATIONMOTOR) < MOTORROTATION) {
            motor(CLAWOPERATIONMOTOR, HALFPOWERclaw);
            msleep(SECOND * 0.2);
        }
    }

    //back up slightly
    //do not hit the back end of the robot on the pole
    motor(RIGHTMOTOR, HALFPOWERright);
    motor(LEFTMOTOR, HALFPOWERleft);
    msleep(SECOND);

    //turn around to go backwards
    while(analog(TOPHATleft) < BLACK) {
        motor(LEFTMOTOR, HALFPOWERleft);
        msleep(SECOND * 0.5);
    }

    while(analog(TOPHATleft) > BLACK) {
        motor(LEFTMOTOR, HALFPOWERleft);
        msleep(SECOND * 0.5);
    }

    while(analog(TOPHATleft) < BLACK) {
        motor(LEFTMOTOR, HALFPOWERleft);
        msleep(SECOND * 0.5);
    }

    //follow the black line to the potato line in the opposite direction
    //while both top hats are not on black
    while(analog(TOPHATright) < BLACK || analog(TOPHATleft) < BLACK) {
        printf("analog0: %d  analog1: %d black: %d\n", analog(TOPHATright), analog(TOPHATleft), BLACK);

        if(analog(TOPHATright) < BLACK) {
            motor(RIGHTMOTOR, HALFPOWERright);
            motor(LEFTMOTOR, 0);
            msleep(SECOND * 0.5);
        }

        if(analog(TOPHATleft) < BLACK) {
            motor(LEFTMOTOR, HALFPOWERleft);
            motor(RIGHTMOTOR, 0);
            msleep(SECOND * 0.5);
        }

    }
    printf("analog0: %d  analog1: %d black: %d\n", analog(TOPHATright), analog(TOPHATleft), BLACK);
    printf("Both on Black!\n");
    ao();

    */

    //open_parallelogram();

    /*
    //raise the claw
    void rise_rotation() {
        clear_motor_position_counter(CLAWHEIGHTMOTOR);
        while(get_motor_position_counter(CLAWHEIGHTMOTOR) < MOTORROTATION) {
            motor(CLAWHEIGHTMOTOR, HALFPOWERclaw);
            msleep(SECOND * 0.2);
        }
    }

    //drive until white
    while(analog(TOPHATright && TOPHATleft) > BLACK) {
        motor(RIGHTMOTOR, 31.5);
        motor(LEFTMOTOR, 30);
        msleep(SECOND * 0.2);
    }
    printf("White!\n");
    ao();

    //continue follow the black line to the potato line backwards
    //while both top hats are not on black
    while(analog(TOPHATright) < BLACK || analog(TOPHATleft) < BLACK) {
        printf("analog0: %d  analog1: %d black: %d\n", analog(TOPHATright), analog(TOPHATleft), BLACK);

        if(analog(TOPHATright) < BLACK) {
            motor(RIGHTMOTOR, HALFPOWERright);
            motor(LEFTMOTOR, 0);
            msleep(SECOND * 0.5);
        }

        if(analog(TOPHATleft) < BLACK) {
            motor(LEFTMOTOR, HALFPOWERleft);
            motor(RIGHTMOTOR, 0);
            msleep(SECOND * 0.5);
        }

    }
    printf("analog0: %d  analog1: %d black: %d\n", analog(TOPHATright), analog(TOPHATleft), BLACK);
    printf("Both on Black!\n");
    ao();

    //drive until white
    while(analog(TOPHATright && TOPHATleft) > BLACK) {
        motor(RIGHTMOTOR, 31.5);
        motor(LEFTMOTOR, 30);
        msleep(SECOND * 0.2);
    }
    printf("White!\n");
    ao();

    //drive until bump on Fry Pole
    while(LEVERBUMPSENSOR == 0) {

        if(analog(TOPHATright) < BLACK) {
            motor(RIGHTMOTOR, HALFPOWERright);
            motor(LEFTMOTOR, 0);
            msleep(SECOND * 0.5);
        }

        if(analog(TOPHATleft) < BLACK) {
            motor(LEFTMOTOR, HALFPOWERleft);
            motor(RIGHTMOTOR, 0);
            msleep(SECOND * 0.5);
        }
    }

    //drop the potato in the fry thingy
    //open the claw
    void open_rotation() {
        clear_motor_position_counter(CLAWOPERATIONMOTOR);
        while(get_motor_position_counter(CLAWOPERATIONMOTOR) > MOTORROTATION * -1) {
            motor(CLAWOPERATIONMOTOR, HALFPOWERBACKWARDSclaw);
            msleep(SECOND * 0.2);
        }
    }

    printf("RUN COMPLETE!\n");

    */

    return 0;
}

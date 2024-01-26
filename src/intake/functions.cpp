#include "main.h"

void intake(){
    intake1.move(80);
    intake2.move(80);
}

void outtake(){
    intake1.move(-127);
    intake2.move(-127);
}

void posess(){
    intake1.move(50);
}

void hold(){
    intake1.move(0);
}


#include "main.h"

void setVels(int linVel, int angVel) {
    int leftVel = linVel - (angVel*WHEELTRACK/2);
    int rightVel = linVel - (angVel*WHEELTRACK/2);
    
    
};
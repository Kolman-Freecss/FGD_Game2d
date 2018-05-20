#include "Timer.h"

int Timer::time = 0;

void Timer::timerTIC() {
    time++;
}

int Timer::getTime() {
    return time;
}

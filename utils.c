#include "utils.h"

#include <time.h>
#include <stdio.h>
#include <windows.h>

void startCountdown(int seconds) {
    int remainingMinutes;
    int remainingSeconds;
    while (seconds >= 0) {
        remainingMinutes = seconds / 60;
        remainingSeconds = seconds % 60;
        printf("\rRemaining: %02d:%02d ", remainingMinutes, remainingSeconds);
        fflush(stdout);
        Sleep(1000);
        seconds--;
    }
}
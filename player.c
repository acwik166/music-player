#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"
#include "song.h"
#include "utils.h"

void startPlaying(struct Player* player) {
    if (player == NULL) {
        printf("Could not play songs.\n");
        return;
    }

    player->isPlaying = 1;

    printf("=========\n");
    printf("Now playing: %s\n", player->current->title);
    printf("Author: %s\n", player->current->author);
    startCountdown(player->current->duration);
}
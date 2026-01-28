#define MINIAUDIO_IMPLEMENTATION
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "miniaudio.h"

#include "player.h"
#include "song.h"
#include "utils.h"

void startPlaying(struct Player* player) {
    if (player == NULL) {
        printf("Could not play songs.\n");
        return;
    }

    ma_result result;
    ma_engine engine;

    result = ma_engine_init(NULL, &engine);
    if (result != MA_SUCCESS) {
        return;
    }

    player->isPlaying = 1;
    while (player->isPlaying) {
        printf("=========\n");
        printf("Now playing: %s\n", player->current->title);
        printf("Author: %s\n", player->current->author);
    
    
    
        ma_engine_play_sound(&engine, player->current->path, NULL);
    
        startCountdown(player->current->duration);
    }

    printf("Press Enter to quit...");
    getchar();

    ma_engine_uninit(&engine);
}

// void nextSong() {

// }
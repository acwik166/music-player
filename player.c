#define MINIAUDIO_IMPLEMENTATION
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "miniaudio.h"

#include "player.h"
#include "song.h"
#include "utils.h"

void loadSongsFromDir(struct Player* player) {
    if (player == NULL) {
        printf("Could not load from directory.\n");
        return;
    }

    
    DIR* dr;
    struct dirent *en;
    dr = opendir(".\\songs");
    if (dr) {
        while ((en = readdir(dr)) != NULL) {
            char* filename = strtok(en->d_name, ".");
            printf("%s\n", filename);
        }
        closedir(dr);
    }

}

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

    while (player->isPlaying && player->current != NULL) {
        ma_sound sound;
    
        if (ma_sound_init_from_file(&engine,
                                player->current->path,
                                0,
                                NULL,
                                NULL,
                                &sound) != MA_SUCCESS) {
            printf("Failed to load sound\n");
            return;
        }

        // ma_uint64 length;
        // ma_uint64 frames = ma_sound_get_length_in_pcm_frames(&sound, &length);
        // ma_uint32 rate = ma_engine_get_sample_rate(&engine);
        // float duration = (float)frames / rate;
        // printf("%f", duration);

        printf("=========\n");
        printf("Now playing: %s\n", player->current->title);
        printf("Author: %s\n", player->current->author);

        ma_sound_start(&sound);
        startCountdown(player->current->duration);
        ma_sound_stop(&sound);
        ma_sound_uninit(&sound);
        
        nextSong(player);
    }
    ma_engine_uninit(&engine);
}

void nextSong(struct Player* player) {
    struct Player* current_player = player;
    if (current_player->current->next != NULL) {
        current_player->current = current_player->current->next;
    }
}
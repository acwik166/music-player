#ifndef SONG_C
#define SONG_C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "song.h"

// Song managament

struct Song* createSong(char* title, char* author, int duration) {
    struct Song* song = malloc(sizeof(struct Song));

    if (song == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    song->id = 1;
    strcpy(song->title, title);
    strcpy(song->author, author);
    song->duration = duration;
    song->prev = NULL;
    song->next = NULL;

    return song;
}

struct Player* addSong(struct Player* player, struct Song* song) {
    if (song == NULL) {
        printf("Could not add song.\n");
        return NULL;
    }

    if (player == NULL) {
        struct Player* player = malloc(sizeof(struct Player));

        player->head = song;
        player->current = NULL;
        player->tail = song;
        player->songCount = 1;
        player->isPlaying = 0;

        return player;
    }

    struct Song* current = song;
    struct Song* temp = player->head;
    current->next = player->head;
    temp->prev = current;
    player->head = current;

    player->songCount = player->songCount++;

    return player;
}

#endif
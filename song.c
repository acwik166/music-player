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

#endif
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
        player->current = song;
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
    player->current = current;
    player->songCount++;

    return player;
}

void displaySongs(struct Player* player) {
    if (player == NULL) {
        printf("Could not display songs.\n");
        return;
    }

    int count = 0;

    struct Song* current = player->head;

    printf("Songs list\n");
    printf("===========\n");

    while (current != NULL) {
        printf("Song id: %d\n", current->id);
        printf("Song title: %s\n", current->title);
        printf("Song author: %s\n", current->title);
        printf("Song duration: %d\n", current->duration);
        (current->next != NULL) ? printf("Song next: %s\n", current->next->title) : printf("Start of playlist\n");
        (current->prev != NULL) ? printf("Song prev: %s\n", current->prev->title) : printf("End of playlist\n");

        printf("\n");

        count++;
        current = current->next;
    }
    printf("===========\n");
}
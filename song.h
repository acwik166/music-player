#ifndef SONG_H
#define SONG_H

#define MAX_TITLE 50
#define MAX_AUTHOR 50

struct Song {
    int id;
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    int duration; // in seconds
    struct Song* prev;
    struct Song* next;
};

struct Player {
    struct Song* head;
    struct Song* current;
    struct Song* tail;
    int songCount;
    int isPlaying;
};

struct Song* createSong(char* title, char* author, int duration);
struct Player* addSong(struct Player* head, struct Song* song);


#endif
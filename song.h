#ifndef SONG_H
#define SONG_H

#define MAX_TITLE 50
#define MAX_AUTHOR 50
#define MAX_SONG_PATH 50

struct Song {
    int id;
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    int duration; // in seconds
    char path[MAX_SONG_PATH];
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

struct Song* createSong(char* title, char* author, int duration, char* path);
struct Player* addSong(struct Player* player, struct Song* song);
void displaySongs(struct Player* player);


#endif
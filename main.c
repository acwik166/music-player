#include <stdio.h>
#include <stdlib.h>

#include "song.h"
#include "player.h"

int main() {
    struct Song* headSong = malloc(sizeof(struct Song));
    struct Player* player = malloc(sizeof(struct Player));

    loadSongsFromDir(player);

    headSong = createSong("I need a girl", "Diddy", 187, "songs\\pitbull.mp3");
    player = addSong(NULL, headSong);

    struct Song* newSong = createSong("Wants and needs", "Drake", 175, "songs\\pitbull.mp3");
    player = addSong(player, newSong);
    
    struct Song* thirdSong = createSong("Drip too hard", "Gunna", 10, "songs\\pitbull.mp3");
    player = addSong(player, thirdSong);

    printf("Music player\n");
    printf("==============\n");
    
    int menuIsActive = 1;
    int option;
    
    while (menuIsActive) {
        printf("Choose and option\n");
        printf("1.Play playlist\n");
        printf("2.Set playback type\n");
        printf("3.Display all songs\n");
        printf("4.Exit\n");

        scanf("%d", &option);

        switch (option) {
            case 1: 
                startPlaying(player);
                break;
            case 3:
                displaySongs(player);
            default: 
                printf("Specify another option.\n");
                break;
        }
    }

    return 0;
}
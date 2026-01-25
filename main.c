#include <stdio.h>
#include <stdlib.h>


#include "song.h"

int main() {
    struct Song* headSong = malloc(sizeof(struct Song));
    struct Player* player = malloc(sizeof(struct Player));

    headSong = createSong("I need a girl", "Diddy", 187);

    printf("Song created title: %s\n", headSong->title);
    printf("Song created author: %s\n", headSong->author);

    printf("\n");

    player = addSong(NULL, headSong);

    printf("Player head title: %s\n", player->head->title);
    printf("Player tail title: %s\n", player->tail->title);
    
    struct Song* newSong = createSong("Wants and needs", "Drake", 175);
    player = addSong(player, newSong);

    printf("\n");
    
    printf("Player head title: %s\n", player->head->title);
    printf("Player tail title: %s\n", player->tail->title);
    
    struct Song* thirdSong = createSong("Drip too hard", "Gunna", 175);
    player = addSong(player, thirdSong);

    printf("\n");

    displaySongs(player);

    return 0;
}
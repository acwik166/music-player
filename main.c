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

    displaySongs(player);

    startPlaying(player);
    return 0;
}
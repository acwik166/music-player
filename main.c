#include <stdio.h>
#include <stdlib.h>


#include "song.h"

int main() {
    struct Song* headSong = malloc(sizeof(struct Song));

    headSong = createSong("I need a girl", "Diddy", 187);

    printf("%s\n", headSong->title);
    printf("%s", headSong->author);

    return 0;
}
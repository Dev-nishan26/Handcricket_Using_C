
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "global.h"
void ClearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Pause() {
    printf("\nPress ENTER to continue...");
    getchar();
}
void Rule(){
    ClearScreen();
   printf("=====BOWLING STYLES=======\n");
   printf("AGRESSIVE:5,6,4\nGOOGLY:1,3,4\nRANDOME:1-6\nNORMAL:2,3,4\n\n");
     printf("======BATTING STYLES =======\nPULL SHOT:5,6,4\nCOVER DRIVER:1,3,4\nAGGRESSIVE:4,5,6\nDEFENSIVE:1,2,3\n");

   Pause();
}


void GetStatsFilename(char *buffer, size_t buffer_size) {
    if (username[0] == '\0')
        strncpy(buffer, "default_stats.dat", buffer_size);
    else
        snprintf(buffer, buffer_size, "%s_stats.dat", username);
}

void TossScreen() {
    while (1) {
        ClearScreen();
        printf("=== TOSS SCREEN ===\n");
        printf("1. Bat First\n2. Bowl First\n3. My Profile\n4. Game Rulebook\n5. Logout\nChoose: ");
        int c;
        scanf("%d", &c);
        getchar();
        if (c == 1) PlayMatch(true);
        else if (c == 2) PlayMatch(false);
        else if (c == 3) ShowProfile(); 
        else if (c==4) Rule();
        else if (c == 5) break;
       
        
        else printf("Invalid choice!\n");
    }
}

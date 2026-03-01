#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "global.h"



#define MAX_USERNAME_LEN 31
#define MAX_PASSWORD_LEN 31
#define MAX_OPTIONS 6



PlayerStats playerStats = {0};
char username[MAX_USERNAME_LEN + 1] = "";
char password[MAX_PASSWORD_LEN + 1] = "";




int main(int argc,char*argv[]) {
    srand(time(NULL));
    if (argc == 3) { 
        strncpy(username, argv[1], MAX_USERNAME_LEN);
        strncpy(password, argv[2], MAX_PASSWORD_LEN);

       
        if (CheckCredentials(username, password)) {
            printf("Auto-login successful! Welcome %s.\n", username);
            LoadStats();
            Pause();
            TossScreen();
            printf("\nGoodbye!\n");
            return 0;
        } }
    LoginOrRegister();
    printf("\nGoodbye!\n");
    printf("idont care");
    return 0;
}
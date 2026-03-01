


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "global.h"


void LoginOrRegister() {
    int choice;
    while (1) {
        ClearScreen();
        printf("============ HAND CRICKET==============\n");
             printf("====Develod By Nishan and Tahlil===\n");





       
        printf("1. Register\n2. Login\n3. Exit\nChoose: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            printf("\nEnter new username: ");
            fgets(username, sizeof(username), stdin);
            username[strcspn(username, "\n")] = '\0';

            printf("Enter password: ");
            fgets(password, sizeof(password), stdin);
            password[strcspn(password, "\n")] = '\0';

            if (RegisterUser(username, password))
                printf("Registration successful!\n");
            else
                printf("Username already exists!\n");
            Pause();
        } else if (choice == 2) {
            printf("\nEnter username: ");
            fgets(username, sizeof(username), stdin);
            username[strcspn(username, "\n")] = '\0';

            printf("Enter password: ");
            fgets(password, sizeof(password), stdin);
            password[strcspn(password, "\n")] = '\0';

            if (CheckCredentials(username, password)) {
                printf("Login successful! Welcome %s.\n", username);
                LoadStats();
                Pause();
              
          TossScreen();
            } else {
                printf("Invalid username or password!\n");
                Pause();
            }
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice!\n");
            Pause();
        }
    }
}
bool CheckCredentials(const char *user, const char *pass) {
    FILE *file = fopen("users.dat", "r");
    if (!file) return false;
    char u[64], p[64];
    while (fscanf(file, "%s %s", u, p) == 2) {
        if (strcmp(user, u) == 0 && strcmp(pass, p) == 0) {
            fclose(file);
            return true;
        }
    }
    fclose(file);
    return false;
}

bool RegisterUser(const char *user, const char *pass) {
    FILE *file = fopen("users.dat", "r");
    char u[64], p[64];
    if (file) {
        while (fscanf(file, "%s %s", u, p) == 2) {
            if (strcmp(user, u) == 0) {
                fclose(file);
                return false; 
            }
        }
        fclose(file);
    }
    file = fopen("users.dat", "a");
    if (!file) return false;
    fprintf(file, "%s %s\n", user, pass);
    fclose(file);
    return true;
}

#include "global.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>
int GetComputerMove();
void PlayMatch(bool playerBatsFirst) {
    int player_score = 0, comp_score = 0, target = 0;
    bool player_out = false, comp_out = false;
    int player_balls = 0, comp_balls = 0;
               
    ClearScreen();
    printf("=== Match Started ===\n");
    printf("You chose to %s first.\n", playerBatsFirst ? "BAT" : "BOWL");
    int max_balls=100;
                
int *first_innings_player_moves = malloc(max_balls * sizeof(int));
int *first_innings_comp_moves   = malloc(max_balls * sizeof(int));
int first_innings_player_balls = 0;
int first_innings_comp_balls   = 0;


int *second_innings_player_moves = malloc(max_balls * sizeof(int));
int *second_innings_comp_moves   = malloc(max_balls * sizeof(int));
int second_innings_player_balls = 0;
int second_innings_comp_balls   = 0;
int wicket;

       printf("Enter wicket: ");
       scanf("%d",&wicket);

    if (playerBatsFirst) {
        
   


     int count=0;

        
        printf("\n-- You are BATTING first --\n");
        while (!player_out) { 
          
    
            Sleep(500);
            int player_move, comp_move = GetComputerMove();
                     
                  Style s = GetBowlingStyle(comp_move);
                 RevealStyle(s, "Computer bowling style");



            printf("Choose (1-6): ");
            scanf("%d", &player_move);
            getchar();
            
            if (player_move>6||player_move<1)
            {
                printf("invalid\n");
                continue;
            }
         
first_innings_player_moves[first_innings_player_balls] = player_move;
first_innings_comp_moves[first_innings_comp_balls] = comp_move;
first_innings_player_balls++;
first_innings_comp_balls++;


            if (player_move == comp_move) {
                printf("OUT! Computer guessed %d\n", comp_move);
                Beep(600,300);
                // player_out = true;
                count++;
                playerStats.innings_batted++;
                playerStats.total_balls++;
                printf("wicket!%d wicket left!\n",wicket-count);
                // target = player_score + 1;
                // printf("You set a target of %d\n", target);
            } else {
                player_score += player_move;
                player_balls++;
                playerStats.total_runs += player_move;
                playerStats.total_balls++;
                 printf("Computer move:%d\n",comp_move);
                printf("You scored %d (Total: %d)\n", player_move, player_score);
            }
            if (count==wicket)
            {   target = player_score + 1;
                printf("You set a target of %d\n", target);
                player_out=true;
            }
            
        }

        printf("\n-- Computer is BATTING now --\n");
        int count2=0;
        while (!comp_out && comp_score < target) {Sleep(500);
            int player_move, comp_move = GetComputerMove();
             Style s = GetBattingStyle(comp_move);
                RevealStyle(s, "Computer batting style");


            printf("Bowl (1-6): ");
            scanf("%d", &player_move);
            getchar();
             if (player_move>6||player_move<1)
            {
                printf("invalid\n");
                continue;
            }
           
second_innings_player_moves[second_innings_player_balls] = player_move;
second_innings_comp_moves[second_innings_comp_balls] = comp_move;
second_innings_player_balls++;
second_innings_comp_balls++;


            if (player_move == comp_move) {
                printf("Computer chose %d\n", comp_move);
                // comp_out = true;
                count2++;
                Beep(600,300);
                printf("wicket!%d wicket left!\n",wicket-count2);
                playerStats.total_wickets_taken++;
                playerStats.innings_bowled++;
            } else {
                comp_score += comp_move;
                comp_balls++;
                
                printf("Computer scored %d (Total: %d)\n", comp_move, comp_score);
            }
            
            if (comp_score >= target) {
                printf("\nComputer reached the target!\n");
                break;
            }
             if (count2==wicket)
            {  
                
                comp_out=true;

            }
        }
    } else { int count=0;int count2=0;
        printf("\n-- Computer is BATTING first --\n");
        while (!comp_out) { Sleep(500);
            int player_move, comp_move = GetComputerMove();
         
            Style s = GetBattingStyle(comp_move);
RevealStyle(s, "Computer batting style");


            printf("Bowl (1-6): ");
            scanf("%d", &player_move);
            getchar();
             if (player_move>6||player_move<1)
            {
                printf("invalid\n");
                continue;
            }
        
first_innings_player_moves[first_innings_player_balls] = player_move;
first_innings_comp_moves[first_innings_comp_balls] = comp_move;
first_innings_player_balls++;
first_innings_comp_balls++;

            if (player_move == comp_move) {
                printf("WICKET! Computer chose %d\n", comp_move);
                // comp_out = true;
                Beep(600,300);
                count++;
                printf("wicket left:%d\n",wicket-count);
                playerStats.total_wickets_taken++;
                playerStats.innings_bowled++;
                // target = comp_score + 1;
                // printf("Target set: %d\n", target);
            } else {
                comp_score += comp_move;
                comp_balls++;
             
                printf("Computer scored %d (Total: %d)\n", comp_move, comp_score);
            }
             if (count==wicket)
            {   target = comp_score + 1;
                printf("comp set a target of %d\n", target);
                comp_out=true;
            }
        }

        printf("\n-- You are BATTING now --\n");
        while (!player_out && player_score < target) {Sleep(500);
            int player_move, comp_move = GetComputerMove();
                Style s = GetBowlingStyle(comp_move);
               
                 RevealStyle(s, "Computer bowling style");


            printf("Choose (1-6): ");
            scanf("%d", &player_move);
            getchar();
             if (player_move>6||player_move<1)
            {
                printf("invalid\n");
                continue;
            }
          
second_innings_player_moves[second_innings_player_balls] = player_move;
second_innings_comp_moves[second_innings_comp_balls] = comp_move;
second_innings_player_balls++;
second_innings_comp_balls++;


            if (player_move == comp_move) {
                printf("OUT! Computer guessed %d\n", comp_move);
                // player_out = true;
                count2++;
                Beep(600,300);
                printf("wicket left:%d\n",wicket-count2);
                playerStats.total_balls++;
                  playerStats.innings_batted++;
            
                    } else {
                player_score += player_move;
                player_balls++;
                playerStats.total_runs += player_move;
                playerStats.total_balls++;
                 printf("Computer move:%d\n",comp_move);
                printf("You scored %d (Total: %d)\n", player_move, player_score);
            }

            if (player_score >= target) {
                printf("\nYou reached the target!\n");
                break;
            }
            if (count==wicket)
            {
              player_out=true;
            }
            
        }
    }

    bool playerWon = false;
    printf("\n=== MATCH RESULT ===\n");
    if (playerBatsFirst) {
        if (comp_score >= target) {
            printf("Computer wins by %d runs!\n", comp_score - (target - 1));
        } else {
            printf("%s wins! Computer was all out at %d.\n", username, comp_score);
            playerWon = true;
        }
    } else {
        if (player_score >= target) {
            printf("%s wins by %d wickets!\n", username, 1);
            playerWon = true;
        } else {
            printf("Computer wins! You were all out at %d.\n", player_score);
        }
    }

    UpdateStatsForMatch(playerWon);
    char choice;
printf("\nDo you want to see the moves of this match? (y/n): ");
scanf(" %c", &choice);
getchar();

if (choice == 'y' || choice == 'Y') {
    printf("\n--- First Innings Moves ---\n");
    printf("Player:   ");
    for (int i = 0; i < first_innings_player_balls; i++)
        printf("%d ", first_innings_player_moves[i]);
    printf("\nComputer: ");
    for (int i = 0; i < first_innings_comp_balls; i++)
        printf("%d ", first_innings_comp_moves[i]);
    printf("\n");

    printf("\n--- Second Innings Moves ---\n");
    printf("Player:   ");
    for (int i = 0; i < second_innings_player_balls; i++)
        printf("%d ", second_innings_player_moves[i]);
    printf("\nComputer: ");
    for (int i = 0; i < second_innings_comp_balls; i++)
        printf("%d ", second_innings_comp_moves[i]);
    printf("\n");
}
free(first_innings_player_moves);
free(first_innings_comp_moves);
free(second_innings_player_moves);
free(second_innings_comp_moves);

    Pause();
}

// Gameplay
int GetComputerMove() {
    return (rand() % MAX_OPTIONS) + 1;
}

Style GetBowlingStyle(int comp_move) {
   
    int possible[3];
    int count = 0;

    if (comp_move == 1 || comp_move == 3 || comp_move == 4)
        possible[count++] = STYLE_GOOGLY;

    if (comp_move == 6 || comp_move == 5 || comp_move == 4)
        possible[count++] = STYLE_AGGRESSIVE;

    if (comp_move == 2 || comp_move == 3 || comp_move == 4)
        possible[count++] = STYLE_NORMAL;

    if (count == 0) return STYLE_RANDOM_STYLE;

    return possible[rand() % count];
}
Style GetBattingStyle(int comp_move) {
    int possible[3];
    int count = 0;

    if (comp_move == 5 || comp_move == 6 || comp_move == 4)
        possible[count++] = STYLE_AGGRESSIVE;

    if (comp_move == 1 || comp_move == 2 || comp_move == 3)
        possible[count++] = STYLE_DEFENSIVE;

    if (comp_move == 1 || comp_move == 4 || comp_move == 3)
        possible[count++] = STYLE_COVER_DRIVE;

    if (comp_move == 5 || comp_move == 6 || comp_move == 4)
        possible[count++] = STYLE_PULL_SHOT;

    return possible[rand() % count];
}
void PrintStyle(Style s) {
    switch (s) {
        case STYLE_GOOGLY: 
    
            printf("Googly" );
            break;

        case STYLE_AGGRESSIVE: 
            printf("Aggressive ");
            break;

        case STYLE_NORMAL: 
            printf("Normal");
            break;

        case STYLE_RANDOM_STYLE: 
            printf("Unpredictable ");
            break;

        case STYLE_DEFENSIVE: 
            printf("Defensive");
            break;

        case STYLE_COVER_DRIVE: 
            printf("Cover Drive ");
            break;

        case STYLE_PULL_SHOT:
            printf("Pull Shot");
            break;
    }
}
void RevealStyle(Style s, const char *text) {
    printf("%s", text);
    Sleep(60);
    printf(".");
    Sleep(60);
    printf(".");
    Sleep(60);
      Sleep(60);
    printf(".");
    Sleep(60);
    printf(".");
    Sleep(60);
      Sleep(60);
    printf(".");
    Sleep(60);
    printf(".");
    Sleep(60);
      Sleep(60);
    printf(".");
    Sleep(60);
    printf(".");
      Sleep(60);
    printf(".");
    Sleep(60);
    printf(".");
    Sleep(60);
      Sleep(60);
    printf(".");
    Sleep(60);
    printf(".");
    Sleep(60);
      Sleep(60);
    printf(".");
    Sleep(60);
    printf(".");
    Sleep(60);
      Sleep(60);
    printf(".");
    Sleep(60);
    printf(".");
    Sleep(60);
    Sleep(500);
    printf(".\n");

   
    PrintStyle(s);
    printf("\n");

    Sleep(1300); 
    ClearScreen();
}

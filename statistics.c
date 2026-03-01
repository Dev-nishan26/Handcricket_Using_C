


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "global.h"
void LoadStats() {
    char filename[64];
    GetStatsFilename(filename, sizeof(filename));
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        if (fscanf(file, "%d %d %d %d %d %d %d",
                   &playerStats.total_runs,
                   &playerStats.total_balls,
                   &playerStats.innings_batted,
                   &playerStats.innings_bowled,
                   &playerStats.total_matches_played,
                   &playerStats.total_wins,
                   &playerStats.total_wickets_taken) != 7)
            playerStats = (PlayerStats){0};
        fclose(file);
    } else playerStats = (PlayerStats){0};
}

void SaveStats() {
    char filename[64];
    GetStatsFilename(filename, sizeof(filename));
    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        fprintf(file, "%d %d %d %d %d %d %d",
                playerStats.total_runs,
                playerStats.total_balls,
                playerStats.innings_batted,
                playerStats.innings_bowled,
                playerStats.total_matches_played,
                playerStats.total_wins,
                playerStats.total_wickets_taken);
        fclose(file);
    }
}





void UpdateStatsForMatch(bool playerWon) {
    playerStats.total_matches_played++;
    if (playerWon) playerStats.total_wins++;
    SaveStats();
}

void ShowProfile() {
    ClearScreen();
    printf("=== %s's Profile ===\n", username);
    float runRate = playerStats.total_balls > 0 ? (float)playerStats.total_runs / playerStats.total_balls * 6.0f : 0.0f;
    float winRate = playerStats.total_matches_played > 0 ? (float)playerStats.total_wins / playerStats.total_matches_played * 100.0f : 0.0f;

    printf("Matches Played: %d\n", playerStats.total_matches_played);
    printf("Wins: %d (%.1f%%)\n", playerStats.total_wins, winRate);
    printf("Runs Scored: %d\n", playerStats.total_runs);
    printf("Balls Faced: %d\n", playerStats.total_balls);
    printf("Run Rate: %.2f\n", runRate);
    printf("Total Innings Batted: %d\n", playerStats.innings_batted);
    printf("Innings Bowled: %d\n", playerStats.innings_bowled);
    printf("Wickets Taken: %d\n", playerStats.total_wickets_taken);
    Pause();
}




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>


#define MAX_USERNAME_LEN 31
#define MAX_PASSWORD_LEN 31
#define MAX_OPTIONS 6 
#define FILENAME_BUFFER_SIZE 64
typedef enum {
    STYLE_GOOGLY,
    STYLE_AGGRESSIVE,
    STYLE_NORMAL,
    STYLE_RANDOM_STYLE,
    STYLE_DEFENSIVE,
    STYLE_COVER_DRIVE,
    STYLE_PULL_SHOT
} Style;



typedef struct PlayerStats {
    int total_runs;
    int total_balls;
    int innings_batted;
    int innings_bowled;
    int total_matches_played;
    int total_wins;
    int total_wickets_taken;
} PlayerStats;


extern PlayerStats playerStats;
extern char username[MAX_USERNAME_LEN + 1];
extern char password[MAX_PASSWORD_LEN + 1];



void ClearScreen(void);
void Pause(void);


void GetStatsFilename(char *buffer, size_t buffer_size);
void LoadStats(void);
void SaveStats(void);


bool CheckCredentials(const char *user, const char *pass);
bool RegisterUser(const char *user, const char *pass);
void LoginOrRegister(void);

int GetComputerMove(void);
void UpdateStatsForMatch(bool playerWon);
void ShowProfile(void);
void PlayMatch(bool playerBatsFirst);
void TossScreen(void);

void PrintStyle(Style s);
Style GetBattingStyle(int comp_move);
Style GetBowlingStyle(int comp_move);
void RevealStyle(Style s, const char *text);
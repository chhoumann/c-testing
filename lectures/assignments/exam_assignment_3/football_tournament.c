/*
*   Author: Christian Bager Bach Houmann
*   Due date: 06/12/2019
*   Purpose: 

fopen fil så den er åbnet til stream.
Læs enhver linje og tilføj til array af structs (kamp array). Så der skal laves et struct "kamp". 182 kampe.
    ugedag, dato (uden årstal), klokkeslæt, de to hold, kampens resultat og tilskuertal.

Nu skal der så gennemløbes alle kampresultater for at lave et hold-array hvor et hold er en struct. 14 hold.
    string holdnavn
    int point
        Vundet kamp = 3 point
        Uafgjort = 1 point
        Tabt = 0 point
    int mål-af-hold
    int mål-mod-hold

Til sidst skal holdene sorteres så man kan se stillingen i turneringen. Der sorteres primært efter point og sekundært efter målforskel.
    Dette skal udskrives pænt som:
        Holdnavn Point Mål-af-hold Mål-mod-hold

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WIN_POINTS 3
#define DRAW_POINTS 1
#define LOSS_POINTS 0
#define CHARACTERS_IN_TEAM_NAME 4
#define NUMBER_OF_TEAMS 14

typedef struct {
    char team_name[CHARACTERS_IN_TEAM_NAME];
    int points;
    int goals_scored;
    int goals_against;
} team;

typedef struct {
    char day_of_week[3];
    int date;
    int month;
    double time;
    char home_team[CHARACTERS_IN_TEAM_NAME];
    char opponent_team[CHARACTERS_IN_TEAM_NAME];
    int home_team_score;
    int opponent_team_score;
    int viewer_count;
} match;

int count_lines_from_file();
match* match_reader(void);
team* create_teams(match* matches);
team * team_sort(match * matches, team * teams, int i, int j, int match_count);
int team_name_duplicate_checker(char *name, team* teams);


int main(void) {
    int i;
    match* matches = match_reader();
   
    team* teams = create_teams(matches);

    printf("TEAM NAME | POINTS | GOALS SCORED | GOALS SCORED AGAINST\n");
    for (i = 0; i < NUMBER_OF_TEAMS; i++){
        printf("%s  %d  %d  %d\n", teams[i].team_name, teams[i].points, teams[i].goals_scored, teams[i].goals_against);
    }


    return 0;
}

/* This is here so that it's possible to have more than a fixed (182) matches and still use the program.
 # Reads file and counts number of lines. */
int count_lines_from_file() {
    FILE* my_file = fopen("./kampe-2018-2019.txt", "r");
    int ch, number_of_lines = 0;
    do {
        ch = fgetc(my_file);
        if (ch == '\n')
            number_of_lines++;
    } while (ch != EOF);

    if (ch != '\n' && number_of_lines != 0)
        number_of_lines++;

    free(my_file);
    return number_of_lines;
}

/* Returns an array of all played matches. */
match* match_reader(void) {
    FILE *match_file = fopen("./kampe-2018-2019.txt", "r");
    int match_count = count_lines_from_file();
    int i = 0;
    match* matches = malloc(match_count * sizeof(match));
    match new_match;

    while (i < match_count){
        fscanf(match_file, "%s %d %*c %d %lf %s %*c %s %d %*c %d %d", 
        &new_match.day_of_week, &new_match.date, &new_match.month, &new_match.time,
        &new_match.home_team, &new_match.opponent_team, &new_match.home_team_score, &new_match.opponent_team_score,
        &new_match.viewer_count);

        matches[i] = new_match;
        i++;
    }
    free(match_file);
    return matches;
}

int h(char *name) {
    if (strcmp(name, "VB") == 0)
        return 0;
    if (strcmp(name, "HOB") == 0)
        return 1;
    if (strcmp(name, "SDR") == 0)
        return 2;
    if (strcmp(name, "AaB") == 0)
        return 3;
    if (strcmp(name, "FCM") == 0)
        return 4;
    if (strcmp(name, "AGF") == 0)
        return 5;
    if (strcmp(name, "FCN") == 0)
        return 6;
    if (strcmp(name, "EFB") == 0)
        return 7;
    if (strcmp(name, "VEN") == 0)
        return 8;
    if (strcmp(name, "OB") == 0)
        return 9;
    if (strcmp(name, "FCK") == 0)
        return 10;
    if (strcmp(name, "ACH") == 0)
        return 11;
    if (strcmp(name, "RFC") == 0)
        return 12;
    if (strcmp(name, "BIF") == 0)
        return 13;
}

team* create_teams(match* matches) {
    /* Should put team names into array of teams and count stats. */
    int match_count = count_lines_from_file();
    team *teams = malloc(NUMBER_OF_TEAMS * sizeof(team));
    team new_team;
    int i = 0, index = 0;    
    char name[4];

    /* Setup */
    for (i = 0; i < NUMBER_OF_TEAMS; i++){
        strcpy(name, matches[i].home_team);
        index = h(name);

        strncpy(new_team.team_name, matches[i].home_team, CHARACTERS_IN_TEAM_NAME);
        new_team.goals_against = 0;
        new_team.goals_scored = 0;
        new_team.points = 0;

        teams[index] = new_team;
    }

    /* Home team */
    for (i = 0; i < match_count; i++){
        strcpy(name, matches[i].home_team);
        index = h(name);
        
        teams[index].goals_against += matches[i].opponent_team_score;
        teams[index].goals_scored += matches[i].home_team_score;
        if (matches[i].home_team_score < matches[i].opponent_team_score)
            teams[index].points += LOSS_POINTS;
        if (matches[i].home_team_score > matches[i].opponent_team_score)
            teams[index].points += WIN_POINTS;
        if (matches[i].home_team_score == matches[i].opponent_team_score)
            teams[index].points += DRAW_POINTS;
    }

    
    /* Opponent team */
    for (i = 0; i < match_count; i++){
        strcpy(name, matches[i].opponent_team);
        index = h(name);
        
        teams[index].goals_scored += matches[i].opponent_team_score;
        teams[index].goals_against += matches[i].home_team_score;
        if (matches[i].home_team_score > matches[i].opponent_team_score)
            teams[index].points += LOSS_POINTS;
        if (matches[i].home_team_score < matches[i].opponent_team_score)
            teams[index].points += WIN_POINTS;
        if (matches[i].home_team_score == matches[i].opponent_team_score)
            teams[index].points += DRAW_POINTS;
    }
    return teams;
}
/*
Yatzy Game.

***** SCORING *****
    Upper Section
        Ones                                                                    Score: The sum of all dice showing the number 1.
        Twos                                                                    Score: The sum of all dice showing the number 2.
        Threes                                                                  Score: The sum of all dice showing the number 3.
        Fours                                                                   Score: The sum of all dice showing the number 4.
        Fives                                                                   Score: The sum of all dice showing the number 5.
        Sixes                                                                   Score: The sum of all dice showing the number 6.
    Lower Section
        One Pair:           Two dice showing the same number.                   Score: Sum of those two dice.
        Two Pairs:          Two different pairs of dice.                        Score: Sum of dice in those two pairs.
        Three of a Kind:    Three dice showing the same number.                 Score: Sum of those three dice.
        Four of a Kind:     Four dice with the same number.                     Score: Sum of those four dice.
        Small Straight:     The combination 1-2-3-4-5.                          Score: 15 points.
        Large Straight:     The combination 2-3-4-5-6.                          Score: 20 points.
        Full House:         Any set of three combined with a different pair.    Score: Sum of all the dice.
        Chance:             Any combination of dice.                            Score: Sum of all the dice.
        Yatzy:              All five dice with the same number.                 Score: 50 points.

        Two Pairs and Full House must have different numbers, so 1-5-5-6-6 will give 22 points as Two Pairs, but 1-5-5-5-5 will give nothing.

***** LOGIC *****
[X]    Roll 5 die unless there is any reserved.
[X]    Forced Yatzy; categories are rolled for sequentially.
[X]    Each category gets it\'s own function - except for the upper section. That should be doable using parameters.
[X]    Points should be tracked. Functions return the amount of points received.
[X]    Three rolls are given each attempt at a category. Should be able to keep throws that are relevant.
[ ]    Upper section. Need to make it so that you get the bonus if you get all 5 the same.
[ ]    Lower section.   


*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIE_MAX_EYES 6
#define ALL_DIE 5 /* This is to accommodate any wishes of using more than a set number of dice. */

/* Function delcarations */
int* roll_multiple_dies(int *rolls, int n);
int upperSection(int category);
int usHandler(void);
int compare(const void * a, const void * b);
int sortRolls(void);
int onePair(void);


int main(void){
    /* Declaration & preparing for randomization later using srand. */
    int totalPoints = 0;
    srand(time(NULL));
    /* Add points handling */
    // totalPoints = usHandler();
    onePair();

    return 0;
}

int* roll_multiple_dies(int *rolls, int n){
    int i;
    for (i = 0; i < n; i++)
        rolls[i] = (rand() % DIE_MAX_EYES) + 1;
        
    return rolls;
}

int upperSection(int category){
    int keptDice = 0;
    int j, i;

    /* Getting array of rolls. */
    int temp_array[ALL_DIE];
    int* rolls = roll_multiple_dies(temp_array, ALL_DIE);

    /* Prints rolls */
    printf("Rolls: ");
    for (i = 0; i < ALL_DIE - 1; i++)
        printf("%d, ", rolls[i]);
    printf("%d.\n", rolls[ALL_DIE - 1]);

    /* Matching */
    for (j = 0; j < ALL_DIE; j++)
        if (rolls[j] == category)
            keptDice++;

    return keptDice * category;

}

int usHandler(void){
    /* Declarations */
    int i;
    int points = 0, totalPoints = 0;

    /* Upper Section */
    printf("Results | Upper Section\n");
    for (i = 1; i <= 6; i++){
        points = upperSection(i);
        totalPoints += points;
        printf("%ds - you scored %d points!\n", i, points);
    }
    printf("Your total points: %d", totalPoints);

    /* Bonus handler */
    if (totalPoints > 63){
        totalPoints += 50;
        printf("\nYou were awarded a bonus of 50 points because you scored more than 63 in the upper section!\n");
    }

    return totalPoints;
}

int compare(const void * a, const void * b){
   return (*(double*)a - *(double*)b);
}

int onePair(void){
    int i;
    /* Rolls -> Sort the rolls -> Check for two of the same integer in a row */
    /* CURRENT ISSUE: DOESN'T SORT PROPERLY */
    /* ROLLS | Getting array of rolls. */
    int temp_array[ALL_DIE];
    int* rolls = roll_multiple_dies(temp_array, ALL_DIE);

    /* ROLLS | Prints rolls */
    printf("Rolls: ");
    for (i = 0; i < ALL_DIE - 1; i++)
        printf("%d, ", rolls[i]);
    printf("%d.\n", rolls[ALL_DIE - 1]);

    /* ROLLS | Sorts the rolls */
    qsort(rolls, ALL_DIE, sizeof(int), compare);

    /* ROLLS | Prints rolls */
    printf("Rolls: ");
    for (i = 0; i < ALL_DIE - 1; i++)
        printf("%d, ", rolls[i]);
    printf("%d.\n", rolls[ALL_DIE - 1]);

    return 0;

}
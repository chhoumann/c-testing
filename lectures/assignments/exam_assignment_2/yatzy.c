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
#define ALL_DIE 5
#define MAX_THROWS 3

/* Function delcarations */
int* roll_multiple_dies(int *rolls, int n);
int upperSection(int category);
static int pointTracker(int points);


int main(void){
    /* Declaration & preparing for randomization later srand. */
    srand(time(NULL));
    int i, points = 0, totalPoints = 0;
    
    printf("Results\n");
    for (int i = 1; i <= 6; i++){
        points = upperSection(i);
        totalPoints += points;
        printf("%ds - you scored %d points!\n", i, points);
    }
    printf("Your total points: %d", totalPoints);

    return 0;
}

int* roll_multiple_dies(int *rolls, int n){
    for (int i = 0; i < n; i++)
        rolls[i] = (rand() % DIE_MAX_EYES) + 1;
        
    return rolls;
}

int upperSection(int category){
    int keptDice = 0;

    /* Throws and matches die to category */
   for(int i = 0; i < MAX_THROWS; i++){
        /* Getting array of rolls based on amount of throws. */
        int temp_array[ALL_DIE - keptDice];
        int* rolls = roll_multiple_dies(temp_array, ALL_DIE - keptDice);

        /* Matching */
        for (int j = 0; j < ALL_DIE - keptDice; j++)
            if (rolls[j] == category)
                keptDice++;
    }

    return keptDice * category;

}
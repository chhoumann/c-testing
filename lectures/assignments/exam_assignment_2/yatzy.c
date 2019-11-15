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
int upperHandler(void);
int descendingSorting(int * rollArray);
int sortRolls(void);
int onePair(void);
int twoPairs(void);
int threeOfAKind(void);
int fourOfAKind(void);
int smallStraight(void);
int largeStright(void);
int fullHouse(void);
int chance(void);
int yatzy(void);
int lowerHandler(void);


int main(void){
    /* Declaration & preparing for randomization later using srand. */
    int totalPoints = 0;
    srand(time(NULL));
    /* Add points handling */
    // totalPoints = upperHandler();
    
    
    

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

int upperHandler(void){
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

int descendingSorting(int * rollArray){
   int i, j, 
       n = ALL_DIE;

    /* Sorts array in descending order. Had to do it this way because qsort would not work for me. */
   for (i = 0; i < n; i++){
       for (j = 0; j < n; j++){
           if (rollArray[j] < rollArray[i]){
               int temp = rollArray[i];
               rollArray[i] = rollArray[j];
               rollArray[j] = temp;
           }
       }
   }
   return * rollArray;
}

int onePair(void){
    int j, stopOnFirst, 
        points = 0;
    /* Rolls -> Sort the rolls -> Check for two of the same integer in a row */
    /* Getting array of rolls. */
    int temp_array[ALL_DIE];
    int* rolls = roll_multiple_dies(temp_array, ALL_DIE);

    /* Sorts the rolls */
    *rolls = descendingSorting(rolls);

    /* Checks for two of the same integer in a row */
    for (j = 0, stopOnFirst = 0; (j < ALL_DIE - 1) && (stopOnFirst == 0); j++){
        if (rolls[j] == rolls[j+1]){
            points = 2 * rolls[j];
            stopOnFirst = 1;
        }
    }

    return points;

}

int twoPairs(void){
    int j, i, stopCond,
        points = 0,
        firstNum = 0;
    /* Rolls -> Sort the rolls -> Check for two of the same integer in a row twice; the pairs must be different from one another. */

    /* Getting array of rolls. */
    int temp_array[ALL_DIE];
    int* rolls = roll_multiple_dies(temp_array, ALL_DIE);

    /* Sorts the rolls */
    *rolls = descendingSorting(rolls);

    /* Check for two of the same integer in a row - the pairs must be different from one another. */
    for (j = 0; j < ALL_DIE - 1; j++){
        /* First pair */
        if (rolls[j] == rolls[j+1]){
            points = 2 * rolls[j];
            firstNum = rolls[j];
            /* Second pair */
            for (i = 0, stopCond = 0; (i < ALL_DIE - 1) && (stopCond == 0); i++){
                if ((rolls[i] == rolls[i+1]) && (rolls[i] != firstNum)){
                    points += 2 * rolls[i];
                    stopCond = 1;
                } else {
                    points = 0;
                }
            }
        }

    }
    return points;
}

int threeOfAKind(void){
    int i,
        points = 0;

    /* Roll -> Sort -> Look for i & i+1 & i+2 being identical */

    /* Getting array of rolls. */
    int temp_array[ALL_DIE];
    int* rolls = roll_multiple_dies(temp_array, ALL_DIE);

    /* Sorts the rolls */
    *rolls = descendingSorting(rolls);

    /* Looking for 3 identical integers in a row */
    for(i = 0; i < ALL_DIE - 2; i++){
        if ((rolls[i] == rolls[i+1]) && (rolls[i] == rolls[i+2]))
            points = rolls[i] * 3;
    }

    return points;
}

int fourOfAKind(void){
    int i,
        points = 0;

    /* Roll -> Sort -> Look for i & i+1 & i+2 & i+3 being identical */

    /* Getting array of rolls. */
    int temp_array[ALL_DIE];
    int* rolls = roll_multiple_dies(temp_array, ALL_DIE);

    /* Sorts the rolls */
    *rolls = descendingSorting(rolls);

    /* TEMP PRINT */
    printf("Rolls: ");
    for (i = 0; i < ALL_DIE; i++)
        printf(" %d ", rolls[i]);

    /* Looking for 4 identical integers in a row */
    for(i = 0; i < ALL_DIE - 3; i++){
        if ((rolls[i] == rolls[i+1]) && (rolls[i] == rolls[i+2]) && (rolls[i] == rolls[i+3]))
            points = rolls[i] * 4;
    }

    return points;
}
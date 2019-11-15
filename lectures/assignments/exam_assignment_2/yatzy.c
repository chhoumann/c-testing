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
int largeStraight(void);
int fullHouse(void);
int chance(void);
int yatzy(void);
int lowerHandler(void);


int main(void){
    /* Declaration & preparing for randomization later using srand. */
    int totalPoints = 0;
    srand(time(NULL));

    /* Add points handling */
    totalPoints = upperHandler() + lowerHandler();

    printf("\nTotal Points: %d\n", totalPoints);
    printf("Thank you for playing.");

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
    int j;

    /* Getting array of rolls. */
    int temp_array[ALL_DIE];
    int* rolls = roll_multiple_dies(temp_array, ALL_DIE);

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
        printf("     Upper Section   | Points\n");
    for (i = 1; i <= 6; i++){
        points = upperSection(i);
        totalPoints += points;
        printf("               %ds   | %d\n", i, points);
    }
    printf("Your total points so far: %d", totalPoints);

    /* Bonus handler */
    if (totalPoints > 63){
        totalPoints += 50;
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

    /* Looking for 4 identical integers in a row */
    for(i = 0; i < ALL_DIE - 3; i++){
        if ((rolls[i] == rolls[i+1]) && (rolls[i] == rolls[i+2]) && (rolls[i] == rolls[i+3]))
            points = rolls[i] * 4;
    }

    return points;
}

int smallStraight(void){
    int i, j, k, f, g;
    /* Rolls -> Check if there is 1-2-3-4-5 in the array */

    /* Getting array of rolls. */
    int temp_array[ALL_DIE];
    int* rolls = roll_multiple_dies(temp_array, ALL_DIE);

    for (i = 0; i < ALL_DIE; i++){
        if (rolls[i] == 1) {
            for (j = 0; j < ALL_DIE; j++){
                if (rolls[j] == 2){
                    for (k = 0; k < ALL_DIE; k++){
                        if (rolls[k] == 3) {
                            for (f = 0; f < ALL_DIE; f++){
                                if (rolls[f] == 4){
                                    for (g = 0; g < ALL_DIE; g++){
                                        if (rolls[g] == 5){
                                            return 15; /* One gets 15 points for getting rolls 1-2-3-4-5. */
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int largeStraight(void){
    int i, j, k, f, g;
    /* Rolls -> Check if there is 2-3-4-5-6 in the array */

    /* Getting array of rolls. */
    int temp_array[ALL_DIE];
    int* rolls = roll_multiple_dies(temp_array, ALL_DIE);

    for (i = 0; i < ALL_DIE; i++){
        if (rolls[i] == 2) {
            for (j = 0; j < ALL_DIE; j++){
                if (rolls[j] == 3){
                    for (k = 0; k < ALL_DIE; k++){
                        if (rolls[k] == 4) {
                            for (f = 0; f < ALL_DIE; f++){
                                if (rolls[f] == 5){
                                    for (g = 0; g < ALL_DIE; g++){
                                        if (rolls[g] == 6){
                                            return 20; /* One gets 20 points for getting rolls 2-3-4-5-6. */
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int fullHouse(void){
    int i, j,
        points = 0,
        sameCheck = 0;
    /* Rolls -> Sort -> Combine three of a kind with one pair - but their numbers cannot be the same. So rolling fx. 55555 will not count. */

    /* Getting array of rolls. */
    int temp_array[ALL_DIE];
    int* rolls = roll_multiple_dies(temp_array, ALL_DIE);

    /* Sorts the rolls */
    *rolls = descendingSorting(rolls);

    /* Looking for 3 identical integers in a row */
    for(i = 0; i < ALL_DIE - 2; i++){
        if ((rolls[i] == rolls[i+1]) && (rolls[i] == rolls[i+2])){
            points = rolls[i] * 3;
            sameCheck = rolls[i];
            /* Checks for two of the same integer in a row */
            for (j = 0; j < ALL_DIE - 1; j++){
                if ((rolls[j] == rolls[j+1]) && (rolls[j] != sameCheck)){
                    points += 2 * rolls[j];
                    return points;
            } 
    }
        }
    }

    
    return 0;
}

int chance(void){
    int i, 
        points = 0;
    /* Rolls -> Sort the rolls -> Sum the 5 best rolls -> Return sum as points */

    /* Getting array of rolls. */
    int temp_array[ALL_DIE];
    int* rolls = roll_multiple_dies(temp_array, ALL_DIE);

    /* Sorts the rolls */
    *rolls = descendingSorting(rolls);

    /* Get 5 best and return */    
    for (i = 0; i < 5; i++)
        points += rolls[i];
    
    return points;
}

int yatzy(void){
    int i;
    /* Rolls -> Sort the rolls -> Check if 5 of the same integer in a row -> Return 50 points */

    /* Getting array of rolls. */
    int temp_array[ALL_DIE];
    int* rolls = roll_multiple_dies(temp_array, ALL_DIE);

    /* Sorts the rolls */
    *rolls = descendingSorting(rolls);

    /* Check if 5 of the same integer in a row and return 50 points if true */
    for(i = 0; i < ALL_DIE - 4; i++){
        if ((rolls[i] == rolls[i+1]) && (rolls[i] == rolls[i+2]) && (rolls[i] == rolls[i+3]) && (rolls[i] == rolls[i+4]))
            return 50;
    }
    
    return 0;
}

int lowerHandler(void){
    int temp = 0,
        totalpoints = 0;
    /* Use all lower section functions and return total points  */

    printf("\n    Lower Section   | Points:");
    /* One Pair */
    temp = onePair(); totalpoints = temp;
    printf("\n         One Pair   | %d", (temp == 0 ? 0 : temp));

    /* Two Pairs */
    temp = twoPairs(); totalpoints += temp;
    printf("\n        Two Pairs   | %d", (temp == 0 ? 0 : temp));

    /* Three of a Kind */
    temp = threeOfAKind(); totalpoints += temp;
    printf("\n  Three of a Kind   | %d", (temp == 0 ? 0 : temp));

    /* Four of a Kind */
    temp = fourOfAKind(); totalpoints += temp;
    printf("\n   Four of a Kind   | %d", (temp == 0 ? 0 : temp));

    /* Small Straight */
    temp = smallStraight(); totalpoints += temp;
    printf("\n   Small Straight   | %d", (temp == 0 ? 0 : temp));

    /* Large Straight */
    temp = largeStraight(); totalpoints += temp;
    printf("\n   Large Straight   | %d", (temp == 0 ? 0 : temp));

    /* Full House */
    temp = fullHouse(); totalpoints += temp;
    printf("\n       Full House   | %d", (temp == 0 ? 0 : temp));

    /* Chance */
    temp = chance(); totalpoints += temp;
    printf("\n           Chance   | %d", (temp == 0 ? 0 : temp));

    /* Yatzy */
    temp = yatzy(); totalpoints += temp;
    printf("\n            Yatzy   | %d", (temp == 0 ? 0 : temp));

    return totalpoints;
}
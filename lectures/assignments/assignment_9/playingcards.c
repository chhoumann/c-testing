/*
*   Author: Christian Bager Bach Houmann
*   Due date: 25/11/2019
*   Purpose: Printing a sorted deck of cards. First comes clubs, then diamonds, then hearts, and last comes spades.
*/
#include <stdio.h>
#include <stdlib.h>
/* Club = Klør | Heart = Hjerter | Spar = Spade | Diamond = Ruder */
typedef enum {Club = 1, Diamond, Heart, Spade, None} card_type;
typedef enum {
    Two = 2,    Three,      Four,
    Five,       Six,        Seven,
    Eight,      Nine,       Ten,
    Knight,     Queen,      King,
    Ace,        Joker
} card_value;

typedef struct {
    card_type type;
    card_value value;
} card;

card array_of_cards[55];

int make_deck(void);

int main(void){

    make_deck();

    /* Print deck */
    for(int i = 0; i < 56; i++){        
        switch (array_of_cards[i].value){
            case 2:     printf("Two of ");      break;
            case 3:     printf("Three of ");    break;
            case 4:     printf("Four of ");     break;
            case 5:     printf("Five of ");     break;
            case 6:     printf("Six of ");      break;
            case 7:     printf("Seven of ");    break;
            case 8:     printf("Eight of ");    break;
            case 9:     printf("Nine of ");     break;
            case 10:    printf("Ten of ");      break;
            case 11:    printf("Knight of ");   break;
            case 12:    printf("Queen of ");    break;
            case 13:    printf("King of ");     break;
            case 14:    printf("Ace of ");      break;
            case 15:    printf("Joker.\n");     break;
            default:                            break;
        }

        switch (array_of_cards[i].type)
        {
            case 1:     printf("Clubs.\n");     break;
            case 2:     printf("Diamonds.\n");  break;
            case 3:     printf("Hearts.\n");    break;
            case 4:     printf("Spades.\n");    break;
            default:                            break;
        }
    }
    

    return 0;
}

int make_deck(void){
    int i,j,temp,
        x = 0;
    for(i = 1; i <= 4; i++){
        for (j = 2; j <= 14; j++){
            array_of_cards[x].type  = i;
            array_of_cards[x].value = j;
            x++;
        }
    }
    
    array_of_cards[53].value = Joker; array_of_cards[53].type = None;
    array_of_cards[54].value = Joker; array_of_cards[54].type = None;
    array_of_cards[55].value = Joker; array_of_cards[55].type = None;

    return 0;
}




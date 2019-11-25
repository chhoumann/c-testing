#include <stdio.h>
#include <stdlib.h>

typedef enum {Heart, Spade, Club, Diamond} card_type;
typedef enum {
    One = 1,    Two,        Three,
    Four,       Five,       Six,
    Seven,      Eight,      Nine,
    Ten,        Knight,     Queen,
    King,       Joker = 0
} card_value;

typedef struct {
    card_type type;
    card_value value;
} card;

card array_of_cards[55];

int sort_cards(void);
void make_deck(void);

int main(void){
    make_deck();

    printf("%d and %d", array_of_cards[4].type, array_of_cards[4].value);

    return 0;
}

void make_deck(void){
    for(int i = 0; i < 52; i++){
        for (int j = 0; j < 13; j++){
                array_of_cards[i*j].type  = i;
                array_of_cards[i*j].value = j;
        }
    }

}

int sort_cards(void){

    return 0;
}
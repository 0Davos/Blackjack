//
// Created by odavis1 on 1/26/2024.
//

#ifndef M1OEP_ODAVIS1_DECK_H
#define M1OEP_ODAVIS1_DECK_H

#include <iostream>
#include <vector>
#include "Card.h"
using namespace std;


class Deck {
private:
    //Deck creation, with max size clarified
    vector<Card> deck;
    const int DECK_SIZE = 52;
public:
    //Default Constructor
    //Creates a deck
    //Requires nothing
    //Creates and pushes all cards into vector of cards named deck
    Deck();

    //Shuffles the deck (vector of cards)
    //Requires and returns nothing
    void shuffle();

    //Removes the first card in the deck
    //Requires and returns nothing
    void removeCard();

    //Returns the first card in the deck
    //Requires nothing, returns a Card
    Card returnFirstCard();
};
#endif //M1OEP_ODAVIS1_DECK_H

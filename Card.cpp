//
// Created by odavis1 on 1/26/2024.
//

#include "Card.h"
#include <iostream>
using namespace std;

Card::Card(int v, string s) {
    value = v;
    suit = s;
}

Card::Card(int v, string s, string faceCardName) {
    value = v;
    suit = s;
    cardName = faceCardName;
}

int Card::getValue() {
    return value;
}

string Card::getSuit() {
    return suit;
}

string Card::getCardName(){
    return cardName;
}


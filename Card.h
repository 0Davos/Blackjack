//
// Created by odavis1 on 1/26/2024.
//

#ifndef M1OEP_ODAVIS1_CARD_H
#define M1OEP_ODAVIS1_CARD_H

#include <iostream>
using namespace std;

class Card{
private:
    int value;
    string suit;
    string cardName;
public:
    //Default Constructor
    //Creates a card
    //Requiring an int for value, and a string for suit
    //Modifies value and suit
    Card(int v, string s);

    //Overloaded Constructor
    //Creates a more specific card
    //Requiring an int for value, a string for suit, and a string for a face card name
    //Modifies value, suit, and face card name
    Card(int v, string s, string faceCardName);

    //Returns the value of a card
    //Requires nothing
    int getValue();

    //Returns name of suit
    //Requires nothing
    string getSuit();

    //Returns the name of the card
    //Requires nothing
    string getCardName();
};

#endif //M1OEP_ODAVIS1_CARD_H

//
// Created by odavis1 on 1/25/2024.
//

#ifndef M1OEP_ODAVIS1_BLACKJACK_H
#define M1OEP_ODAVIS1_BLACKJACK_H
#include "Deck.h"
#include "Card.h"
#include "betting.h"
#include <iostream>
#include <vector>

class Blackjack{
private:
    vector<Card> userHand;
    vector<Card> dealerHand;
    Deck deck1 = Deck();
public:
    //Default Constructor
    //Makes a game of blackjack
    //Requires nothing
    //Creates a deck, shuffles it, tells player the rules
    //Gives userHand and dealerHand card
    //Calls userTurn and then dealerTurn, and declares a winner
    Blackjack();

    //Runs a user's turn
    //Allow user to hit or stay, and includes user validation
    //Requires and returns nothing
    void userTurn(Betting &b);

    //Runs a dealer's turn
    //Checks for where the user ended,
    // and will hit until they have a score higher than user (or bust)
    // if user hadn't already busted
    //Also prints out every additon to dealer's hand
    //Requires and returns nothing
    void dealerTurn();

    //Adds a card to either the user or dealer's hand
    //Also removes that card from the original deck
    //Requires a vector<Card> to know if a user or dealer hand should be affected
    //Requires a string for further validation
    //Returns nothing
    void hit(vector<Card> &userOrDealer, string UorD);

    //Returns an int that's the total value of user's hand
    //Requires nothing
    int userValue();

    //Returns an int that's the total value of dealer's hand
    //Requires nothing
    int dealerValue();

    //Prints out the rules for blackjack
    //Returns and requires nothing
    static void blackjackRules();
};
#endif //M1OEP_ODAVIS1_BLACKJACK_H

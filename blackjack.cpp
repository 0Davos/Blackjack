//
// Created by odavis1 on 2/23/2024.
//

#include "blackjack.h"
#include "Deck.h"
#include "betting.h"
#include <string>
#include <iostream>

using namespace std;

Blackjack::Blackjack() {
    //create a deck and shuffle it
    deck1.shuffle();

    //Set up our betting
    Betting betting;

    //Tell the rules
    blackjackRules();

    //Give cards to user and dealer
    userHand.push_back(deck1.returnFirstCard());
    deck1.removeCard();
    dealerHand.push_back(deck1.returnFirstCard());
    deck1.removeCard();
    userHand.push_back(deck1.returnFirstCard());
    deck1.removeCard();
    dealerHand.push_back(deck1.returnFirstCard());
    deck1.removeCard();


    //User and Dealer's turn
    userTurn(betting);
    dealerTurn();

    //Compare User and Dealer's ending hand values
    if (userValue() > 21) {
        cout << "Dealer Won. Try again!\n\n" << endl;
        //Only add 1 game, and end betting round
        betting.addAGame();
        betting.endBettingRound();
    }
    if (21 >= userValue()) {
        if (userValue() > dealerValue()) {
            cout << "You Won! Congratulations!! \n\n" << endl;
            //Add a win (get back 2x bet), game, then end the round
            betting.wonGame();
            betting.addAWin();
            betting.addAGame();
            betting.endBettingRound();
        }
        else if (userValue() == dealerValue()) {
            cout << "Tied game. Try again! \n\n" << endl;
            //Add a game, get back 1x bet, then end round
            betting.addAGame();
            betting.drawGame();
            betting.endBettingRound();
        }
        else if (dealerValue() > 21) {
            cout << "Dealer busted, you win! Congratulations!! \n\n" << endl;
            //Add a win (get back 2x bet), game, then end round
            betting.wonGame();
            betting.addAWin();
            betting.addAGame();
            betting.endBettingRound();
        }
        else if (userValue() < dealerValue()) {
            cout << "Dealer Won. Try again! \n\n" << endl;
            //Add a game, end the round
            betting.addAGame();
            betting.endBettingRound();
        }
    }
    //When a game is over, we print out the User's current stats
    cout << betting.printStats() << endl;
}

void Blackjack::userTurn(Betting &b) {
    cout << "Would you like to continue, or start a new game?" << endl;
    //Verifying user input as "continue" or "new"
    string choice;
    bool correctInput = false;
    while (!correctInput) {
        getline(cin, choice);
        //Create a new betting file
        if (choice == "new" || choice == "New") {
            b = Betting();
            cout << "Creating a new file: " << endl;
            cout << b.printStats() << endl;
            correctInput = true;
        }
        //Continuing betting file
        else if (choice == "continue" || choice == "Continue") {
            b = Betting("savedGame");

            cout << "Continuing previous file: " << endl;
            cout << b.printStats() << endl;
            correctInput = true;
        }
        else {
            cout << "Please input 'new' or 'continue'." << endl;
            correctInput = false;
        }
    }
    if (b.getMoney() == 0) {
        cout << "Current file has no money. Creating a new file instead." << endl;
        b = Betting();
        cout << b.printStats() << endl;
    }
    cout << "\n" << endl;


    //Initial bet. Must be between 1 and max userMoney, and is also an integer
    cout << "How much would you like to initially bet? Only whole numbers, please. " << endl;
    int validInt = 0;
    string outputNum;
    bool notANum;
    while (!validInt) {
        getline(cin, outputNum);

        //This for loop checks if there are spaces, and if there are, we increase a count.
        int count = 0;
        for (int i = outputNum.size(); i > 0; i--) {
            if (isspace(outputNum[i])) {
                count += 1;
            }
        }
        if (count > 0) {
            cout << "Invalid input. Enter a number: ";
            outputNum = "";
        }
        else if (outputNum.empty()) {
            cout << "No input. Enter a number: ";
        }
        //If the user gave us a string with no spaces and isn't empty, we check to see if it's only a number
        // As well as if it is negative, with the "-" needing to be the first in the string, with a total string length of more than 1
        else if (!outputNum.empty()) {
            for (int i = outputNum.size() - 1; i >= 0; i--) {
                if (!(outputNum[i] == '0' || outputNum[i] == '1' || outputNum[i] == '2' || outputNum[i] == '3' ||
                      outputNum[i] == '4' || outputNum[i] == '5' || outputNum[i] == '6' || outputNum[i] == '7' ||
                      outputNum[i] == '8' || outputNum[i] == '9')) {
                    notANum = true;

                    char dash = '-';
                    if ((outputNum[i] == dash) && (i == 0) && outputNum.size() > 1) {
                        notANum = true;
                    }
                }
            }
            //However if the string is an int,
            // we check to see if it's bigger than userMoney, or smaller than 1,
            // If it is, we reject the input
            if (!notANum) {
                if (stoi(outputNum) > b.getMoney() || stoi(outputNum) < 1) {
                    validInt = false;
                    notANum = true;
                }
            }

            //If the string has letters or is out of bounds, we set user input to 0 and tell them to reinput a number
            if (notANum) {
                cout << "Invalid input. Enter a valid number: ";
                outputNum = "";
                notANum = false;

            }
            //If the string doesn't have non numbers, break the while loop, its just numbers.
            else if (!notANum) {
                validInt = true;
            }
        }
    }
        cout << "You Bet " + outputNum << endl;
        b.initialBet(stoi(outputNum));
        cout << "Current " + b.printMoney() << endl;

        //Tell user their hand
        cout << "Your hand is: A " + userHand.at(0).getCardName() + " and a " + userHand.at(1).getCardName() << endl;
        cout << "Hand total is: " + to_string(userValue()) << endl;

        //Tell user one of the cards in the dealer's hand.
        cout << "\nDealer's hand: You can see a " + dealerHand.at(0).getCardName() +
                ". Dealer also has one hidden card." << endl;
        cout << "-----------------------------------------------------------------" << endl;


        //Doubling down only happens if userValue starts at 9, 10 or 11.
        //User can double their bet, and will be given one more card
        bool DDorHit = false;
        if (userValue() == 9 || userValue() == 10 || userValue() == 11) {
            cout << "Would you like to double down [y/n]? You will be given another card, and your bet will increase 2x. You won't be able to hit again." << endl;
            string ddInput;
            bool correctDDInput = false;
            while (!correctDDInput) {
                getline(cin, ddInput);
                if (ddInput == "y" || ddInput == "Y") {
                    b.doubleDownBet();
                    correctDDInput = true;
                    DDorHit = true;
                    hit(userHand, "user");
                    cout << "Your hand value is now " + to_string(userValue()) +
                            "\nYour new bet is " + to_string(b.getBet()) + "\n" << endl;
                }
                else if (ddInput == "n" || ddInput == "N") {
                    correctDDInput = true;
                    DDorHit = false;
                }
                else {
                    cout << "Please input 'y' or 'n' " << endl;
                }
            }
        }

        if (!DDorHit) {
            bool hitTrue = false;
            string hitStayInput;
            cout << "Would you like to hit or stay? " << endl;
            //We're going to loop around this information in case the user would like to hit multiple times
            while (!hitTrue) {
                //Hit or stay input validation, loop for validation, loop for hits, no loops for stay
                getline(cin, hitStayInput);

                //Input validation, if input isn't 'hit', 'Hit', 'stay', or 'Stay', we will ask them again
                while (!(hitStayInput == "hit") && !(hitStayInput == "Hit") &&
                       !(hitStayInput == "stay") && !(hitStayInput == "Stay")) {
                    hitStayInput = "";
                    cout << "Please input hit or stay. " << endl;
                    getline(cin, hitStayInput);
                }
                //If the user hits
                if (hitStayInput == "hit" || hitStayInput == "Hit") {
                    hit(userHand, "user");
                    cout << "Your hand value is now " + to_string(userValue()) << endl;

                    //Check user's hand value -- if it's greater than 21, they lose
                    //If at 21, they don't get an option to hit again, they have Blackjack, automatically dealer's turn
                    //If less than 21, we give them option to hit or stay again.
                    if (userValue() > 21) {
                        cout << "Bust! Over 21." << endl;
                        hitTrue = true;
                    } else if (userValue() == 21) {
                        cout << "Blackjack!!\nNow the dealer's turn" << endl;
                        hitTrue = true;
                    } else {
                        cout << "Would you like to hit again, or stay? " << endl;
                    }
                }
                    //If the user stays, end user's turn by turning hitTrue to true.
                else if (hitStayInput == "stay" || hitStayInput == "Stay") {
                    cout << "Your turn is over!" << endl;
                    hitTrue = true;
                }
            }
            cout << "-----------------------------------------------------------------" << endl;
        }
}

void Blackjack::dealerTurn() {
    //Tell user the dealer's full hand
    cout << "Dealer's starting hand is: A " + dealerHand.at(0).getCardName() + " and a " + dealerHand.at(1).getCardName() << endl;
    cout << "Dealer's hand total is: " + to_string(dealerValue()) << endl;

    //We're only going to have the dealer do something if they have a value of less than that of the user
    bool hitTrue = false;
    int hitCount = 0;
    while (dealerValue() < userValue() && !hitTrue) {
        //Check at the start of each loop if the dealer's value is the user's value or greater,
        //so they don't hit, and their turn is over
        if (dealerValue() >= userValue() || userValue() > 21) {
            hitTrue = true;
            cout << "Dealer doesn't need to hit." << endl;
        }

        //Since there's only one player, we only care if the dealer's value is less than the one player's to win
        else if (dealerValue() < userValue()) {
            hitCount += 1;
            hit(dealerHand, "dealer");
            cout << "Dealer's hand value is " + to_string(dealerValue()) << endl;
        }

        if (dealerValue() > 21) {
            cout << "Dealer's ending hand value is: " + to_string(dealerValue()) << endl;
            hitTrue = true;
        }
    }
}

void Blackjack::hit(vector<Card> &userOrDealer, string UorD) {
    //To customize our text output
    string UDView;
    if (UorD == "user")
        UDView = "User";
    if (UorD == "dealer")
        UDView = "Dealer";
    //Add a card to either user or dealer's hand
    //Then remove that card from deck
    userOrDealer.push_back(deck1.returnFirstCard());
    deck1.removeCard();
    cout << "Dealer added a card to " + UDView + "'s hand. It's a " + userOrDealer.at(userOrDealer.size()- 1).getCardName() << endl;
}

int Blackjack::userValue() {
    int count = 0;

    //Loop for the amount of cards in the user's hand, and add their values up with an int
    for (int i = 0; userHand.size() > i; i++) {
        count +=userHand.at(i).getValue();
    }
    return count;
}

int Blackjack::dealerValue() {
    int count = 0;
    //Loop for the amount of cards in the dealer's hand, and add their values up with an int
    for (int i = 0; dealerHand.size() > i; i++) {
        count += dealerHand.at(i).getValue();
    }
    return count;
}

void Blackjack::blackjackRules() {
    cout << "-----------------This is Owen's Blackjack game!-----------------" << endl;
    cout << "----------------------------------------------------------------" << endl;

    cout << "The rules are simple. The goal is to get to a value of 21, without going over 21. All 'face cards' (J, Q, K) are worth 10, "
            "\nand Aces are worth 1 or 11, with 11 being the standard when you're told your current hand value. "

            "\nAfter you're given your first two cards, you can choose to hit or stay, either getting a new card (hit), "
            "\nor staying with your current amount of cards (stay). "
            "\nYou can hit as many times as you want, but you don't want to go over 21!"

            "The dealer's turn will be after yours. \nThey need to get a higher score than yours to win."

            "\n\nBetting: \nFirst you will be asked for an initial bet. If you win, you'll earn double your bet. If you tie, you get back your initial bet. "
            "\nDoubling down is an event where your hand value is initially 9, 10 or 11. You'll get only one more card.\n"

            "---------------------------Good luck!---------------------------\n" << endl;
}


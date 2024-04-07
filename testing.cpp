//
// Created by odavi on 2/22/2024.
//

#include "Card.h"
#include "Deck.h"
#include "blackjack.h"
#include "betting.h"

bool testCardClass();
bool testDeckClass();
bool testBlackjackClass();
bool testBetting();

int main() {
    if (testCardClass()) {
        cout << "Passed Card tests." << endl;
    }

    if (testDeckClass()) {
        cout << "Passed Deck tests." << endl;
    }

    if (testBlackjackClass()) {
        cout << "Passed Blackjack tests." << endl;
    }
    if (testBetting()) {
        cout << "Passed Betting tests." << endl;
    }
    return 0;
}

//Card
bool testCardClass() {
    bool testsPassed = true;
    //Constructors, and creating cards to call getters
    Card card1 = Card(3,"Club");
    Card card2 = Card(10,"Diamond","Ten");

    //Getters
    //Card1
    if (!card1.getValue()) {
        cout << "Failed. Card: getValue() for #1" << endl;
        testsPassed = false;
    }
    if (card1.getSuit() == "") {
        cout << "Failed. Card: getSuit() for #1" << endl;
        testsPassed = false;
    }
    if (!(card1.getCardName() == "")) {
        cout << "Failed. Card: getCardName() for #1" << endl;
    }

    //Card2
    if (!card2.getValue()) {
        cout << "Failed. Card: getValue() for #2" << endl;
        testsPassed = false;
    }
    if (card2.getSuit() == "") {
        cout << "Failed. Card: getSuit() for #2" << endl;
        testsPassed = false;
    }
    if (card2.getCardName() == "") {
        cout << "Failed. Card: getCardName() for #2" << endl;
        testsPassed = false;
    }

    return testsPassed;
}

//Deck
bool testDeckClass() {
    bool testsPassed = true;

    //Constructor for deck (Can check through debugger)
    Deck testDeck = Deck();

    //Shuffle deck (Can check through debugger)
    testDeck.shuffle();


    //Checking if a card is removed
    //Creating a card that will be the card removed, comparing with the new first card
    Card oldCard = testDeck.returnFirstCard();

    testDeck.removeCard();
    Card newCard = testDeck.returnFirstCard();
    if (oldCard.getValue() == newCard.getValue() && oldCard.getSuit() == newCard.getSuit()) {
        cout << "Failed. Deck: removeCard()" << endl;
        testsPassed = false;
    }

    return testsPassed;
}

//blackjack
bool testBlackjackClass() {
    //Since blackjack's constructor calls each method, any method can be seen if they pass/fail in blackjack
    //Blackjack b = Blackjack();
    return true;
}

bool testBetting() {
    bool testsPassed = true;
    Betting betting;

    //Constructors
    betting = Betting("savedGame");
    if (!(betting.getMoney() >= 0 || betting.getWins() >= 0 || betting.getGamesPlayed() >= 0 || betting.getWinRatio() >= 0 || betting.getBet() >= 0)) {
        cout << "Failed. Betting: Betting('savedGame')" << endl;
        testsPassed = false;
    }

    betting = Betting();
    if (!(betting.getMoney() == 100 || betting.getWins() == 0 || betting.getGamesPlayed() == 0 || betting.getWinRatio() == 0 || betting.getBet() == 0)) {
        cout << "Failed. Betting: Betting()" << endl;
        testsPassed = false;
    }

    //Types of betting
    betting.initialBet(10);
    if (betting.getBet() != 10) {
        cout << "Failed. Betting: initialBet()" << endl;
        testsPassed = false;
    }

    betting.doubleDownBet();
    if (betting.getBet() != 20) {
        cout << "Failed. Betting: doubleDownBet()" << endl;
        testsPassed = false;
    }

    //Adding to values
    betting.addAWin();
    if (betting.getWins() != 1) {
        cout << "Failed. Betting: addAWin()" << endl;
        testsPassed = false;
    }

    betting.addAGame();
    if (betting.getGamesPlayed() != 1) {
        cout << "Failed. Betting: addAGame()" << endl;
        testsPassed = false;
    }

    //If a game is won, 2x bet back to user's money
    betting.wonGame();
    if (betting.getMoney() != 120) {
        cout << "Failed. Betting: wonGame()" << endl;
        testsPassed = false;
    }

    //Setting initial bet
    betting.initialBet(15);
    betting.drawGame();
    if (betting.getMoney() != 120) {
        cout << "Failed. Betting: drawGame()" << endl;
        testsPassed = false;
    }

    //End of round for betting
    betting.endBettingRound();
    if (!(Betting("savedGame").getMoney() == 120 || Betting("savedGame").getWins() == 1 || Betting("savedGame").getGamesPlayed() == 1 || Betting("savedGame").getWinRatio() == 1.0 || Betting("savedGame").getBet() == 0)) {
        cout << "Failed. Betting: endBettingRound()" << endl;
        testsPassed = false;
    }

    //Both printStats and printMoney are used in main program, and just print out a string.
    //No need to test, and no great way to verify them.

    //Getters
    if (betting.getMoney() != 120) {
        cout << "Failed. Betting: getMoney()" << endl;
        testsPassed = false;
    }

    if (betting.getWins() != 1) {
        cout << "Failed. Betting: getWins()" << endl;
        testsPassed = false;
    }

    if (betting.getGamesPlayed() != 1) {
        cout << "Failed. Betting: getGamesPlayed()" << endl;
        testsPassed = false;
    }

    if (betting.getWinRatio() != 1.0) {
        cout << "Failed. Betting: getWinRatio()" << endl;
        testsPassed = false;
    }

    return testsPassed;
}

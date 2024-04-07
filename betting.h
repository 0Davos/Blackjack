//
// Created by odavi on 2/24/2024.
//

#ifndef M1OEP_ODAVIS1_BETTING_H
#define M1OEP_ODAVIS1_BETTING_H
#include <iostream>


class Betting{
private:
    int userMoney = 0;
    int wins = 0;
    int gamesPlayed = 0;
    float winRatio = 0.0;

    int currentBet = 0;
public:
    //Default Constructor
    //Requires nothing
    //Sets new values for all private values.
    //Money = 100, wins = 0, games played = 0, win ratio = 0.0
    Betting();

    //Overloaded Constructor
    //Requires a string for a file
    //Sets new values for all private values based on file
    Betting(std::string continueFile);

    //Sets a bet amount, and removes that amount from total userMoney
    //Requires an integer for the bet amount
    //Returns nothing
    void initialBet(int bet);

    //Doubles initial bet, if userMoney has enough money, and removes that amount form userMoney
    //Requires nothing, returns nothing
    void doubleDownBet();

    //Adds one win
    //Requires nothing, returns nothing
    void addAWin();

    //Adds one game
    //Requires nothing, returns nothing
    void addAGame();

    //If a game is won, double the current bet amount, and add it to userMoney
    //Requires nothing, returns nothing
    void wonGame();

    //If a game is drawn, add current bet back to userMoney
    //Requires nothing, returns nothing
    void drawGame();

    //When a game is over, the betting round ends.
    //Re-set win ratio, making sure a "divide by zero" error doesn't occur
    //Puts all values into file to be saved
    //Requires nothing, returns nothing
    void endBettingRound();

    //Shows user all of their stats
    //Requires nothing
    //Returns stats for userMoney, wins, gamesPlayed and winRatio
    std::string printStats();

    //Shows user their current money
    //Requires nothing
    //Returns "Money: " + userMoney
    std::string printMoney();

    //Getter for userMoney
    //Requires nothing
    //Returns userMoney
    int getMoney();

    //Getter for wins
    //Requires nothing
    //Returns wins
    int getWins();

    //Getter for games played
    //Requires nothing
    //Returns gamesPlayed
    int getGamesPlayed();

    //Getter for win ratio
    //Requires nothing
    //Returns winRatio
    float getWinRatio();

    //Getter for current bet
    //Requires nothing
    //Returns currentBet
    int getBet();
};
#endif //M1OEP_ODAVIS1_BETTING_H

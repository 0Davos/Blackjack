//
// Created by odavi on 2/24/2024.
//
#include "betting.h"
#include <fstream>
using namespace std;

Betting::Betting() {
    //Set initial $ to 100, #wins = 0, # games played = 0, win ratio = 0
    userMoney = 100;
    wins = 0;
    gamesPlayed = 0;
    winRatio = 0;
}

Betting::Betting(string continueFile) {
    //Open continueFile, set values
    ifstream inFile("../" + continueFile);
    string newline;

    if (inFile) {
        inFile >> userMoney;
        inFile >> wins;
        inFile >> gamesPlayed;
        inFile >> winRatio;
    }
}

void Betting::initialBet(int bet) {
    currentBet = bet;
    userMoney = userMoney - bet;
}

void Betting::doubleDownBet() {
    if (userMoney >= currentBet * 2) {
        userMoney = userMoney - currentBet;
        currentBet = currentBet * 2;
    }

}

void Betting::addAWin() {
    wins += 1;
}

void Betting::addAGame() {
    gamesPlayed += 1;
}

void Betting::wonGame() {
    userMoney = userMoney + (currentBet * 2);
}

void Betting::drawGame() {
    userMoney = userMoney + currentBet;
}

void Betting::endBettingRound() {
    //Make sure no dividing by 0 error is possible
    if (gamesPlayed > 0)
        winRatio = float(wins) / float(gamesPlayed);
    else
        winRatio = 0;

    //Put all new values back into a file to be saved
    ofstream outputPrint;
    outputPrint.open ("../savedGame");
    outputPrint << to_string(userMoney) + "\n";
    outputPrint << to_string(wins) + "\n";
    outputPrint << to_string(gamesPlayed) + "\n";
    outputPrint << to_string(winRatio) + "\n";
    outputPrint.close();

}


string Betting::printStats() {
    return "Current stats: \n"
           "Money: " + to_string(userMoney) + "\n"
            "# of wins: " + to_string(wins) + "\n"
            "# of games played: " + to_string(gamesPlayed) + "\n"
            "Win ratio: " + to_string(winRatio) + "\n";
}

string Betting::printMoney() {
    return "Money: " + to_string(userMoney);
}

int Betting::getMoney() {
    return userMoney;
}

int Betting::getWins() {
    return wins;
}

int Betting::getGamesPlayed() {
    return gamesPlayed;
}

float Betting::getWinRatio() {
    return winRatio;
}

int Betting::getBet() {
    return currentBet;
}


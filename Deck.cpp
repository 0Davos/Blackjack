//
// Created by odavis1 on 1/26/2024.
//

#include "Deck.h"
#include <algorithm>
#include <random>
using namespace std;

Card Deck::returnFirstCard() {
    return deck.at(0);
}

void Deck::removeCard() {
    deck.erase(deck.begin());
}

void Deck::shuffle() {
    srand((int) time(0));
    int random = rand();

    auto rng = std::default_random_engine(random);
    std::shuffle(std::begin(deck), std::end(deck), rng);
}

Deck::Deck() {
    Card diamondTwo = Card(2, "diamond", "Two");
    Card diamondThree = Card(3, "diamond","Three");
    Card diamondFour = Card(4, "diamond","Four");
    Card diamondFive = Card(5, "diamond","Five");
    Card diamondSix = Card(6, "diamond","Six");
    Card diamondSeven = Card(7, "diamond","Seven");
    Card diamondEight = Card(8, "diamond","Eight");
    Card diamondNine = Card(9, "diamond","Nine");
    Card diamondTen = Card(10, "diamond","Ten");
    Card diamondJ = Card(10, "diamond", "Jack");
    Card diamondQ = Card(10, "diamond", "Queen");
    Card diamondK = Card(10, "diamond", "King");
    Card diamondA = Card(11, "diamond","Ace");
    deck.push_back(diamondTwo);
    deck.push_back(diamondThree);
    deck.push_back(diamondFour);
    deck.push_back(diamondFive);
    deck.push_back(diamondSix);
    deck.push_back(diamondSeven);
    deck.push_back(diamondEight);
    deck.push_back(diamondNine);
    deck.push_back(diamondTen);
    deck.push_back(diamondJ);
    deck.push_back(diamondQ);
    deck.push_back(diamondK);
    deck.push_back(diamondA);

    Card heartTwo = Card(2, "heart","Two");
    Card heartThree = Card(3, "heart","Three");
    Card heartFour = Card(4, "heart","Four");
    Card heartFive = Card(5, "heart","Five");
    Card heartSix = Card(6, "heart","Six");
    Card heartSeven = Card(7, "heart","Seven");
    Card heartEight = Card(8, "heart","Eight");
    Card heartNine = Card(9, "heart","Nine");
    Card heartTen = Card(10, "heart","Ten");
    Card heartJ = Card(10, "heart", "Jack");
    Card heartQ = Card(10, "heart", "Queen");
    Card heartK = Card(10, "heart", "King");
    Card heartA = Card(11, "heart","Ace");
    deck.push_back(heartTwo);
    deck.push_back(heartThree);
    deck.push_back(heartFour);
    deck.push_back(heartFive);
    deck.push_back(heartSix);
    deck.push_back(heartSeven);
    deck.push_back(heartEight);
    deck.push_back(heartNine);
    deck.push_back(heartTen);
    deck.push_back(heartJ);
    deck.push_back(heartQ);
    deck.push_back(heartK);
    deck.push_back(heartA);

    Card clubTwo = Card(2, "club", "Two");
    Card clubThree = Card(3, "club","Three");
    Card clubFour = Card(4, "club","Four");
    Card clubFive = Card(5, "club","Five");
    Card clubSix = Card(6, "club","Six");
    Card clubSeven = Card(7, "club","Seven");
    Card clubEight = Card(8, "club","Eight");
    Card clubNine = Card(9, "club","Nine");
    Card clubTen = Card(10, "club","Ten");
    Card clubJ = Card(10, "club", "Jack");
    Card clubQ = Card(10, "club", "Queen");
    Card clubK = Card(10, "club", "King");
    Card clubA = Card(11, "club","Ace");
    deck.push_back(clubTwo);
    deck.push_back(clubThree);
    deck.push_back(clubFour);
    deck.push_back(clubFive);
    deck.push_back(clubSix);
    deck.push_back(clubSeven);
    deck.push_back(clubEight);
    deck.push_back(clubNine);
    deck.push_back(clubTen);
    deck.push_back(clubJ);
    deck.push_back(clubQ);
    deck.push_back(clubK);
    deck.push_back(clubA);

    Card spadeTwo = Card(2, "spade","Two");
    Card spadeThree = Card(3, "spade","Three");
    Card spadeFour = Card(4, "spade","Four");
    Card spadeFive = Card(5, "spade","Five");
    Card spadeSix = Card(6, "spade","Six");
    Card spadeSeven = Card(7, "spade","Seven");
    Card spadeEight = Card(8, "spade","Eight");
    Card spadeNine = Card(9, "spade","Nine");
    Card spadeTen = Card(10, "spade","Ten");
    Card spadeJ = Card(10, "spade", "Jack");
    Card spadeQ = Card(10, "spade", "Queen");
    Card spadeK = Card(10, "spade", "King");
    Card spadeA = Card(11, "spade","Ace");
    deck.push_back(spadeTwo);
    deck.push_back(spadeThree);
    deck.push_back(spadeFour);
    deck.push_back(spadeFive);
    deck.push_back(spadeSix);
    deck.push_back(spadeSeven);
    deck.push_back(spadeEight);
    deck.push_back(spadeNine);
    deck.push_back(spadeTen);
    deck.push_back(spadeJ);
    deck.push_back(spadeQ);
    deck.push_back(spadeK);
    deck.push_back(spadeA);
}
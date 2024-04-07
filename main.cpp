//
// Created by odavis1 on 1/25/2024.
//

#include "blackjack.h"

int main() {
    bool playgame = true;
    cout << "Would you like to play blackjack? [y/n] " << endl;
    while (playgame) {
        string s;
        getline(cin, s);
        if (s == "y" || s == "yes" || s == "Yes") {
            Blackjack blackjack = Blackjack();
            cout << "\n\nWould you like to play again? [y/n] " << endl;
        }
        else if (s == "n" || s == "no" || s == "No") {
            playgame = false;
        }
        else {
            cout << "Please input 'y' or 'n' " << endl;
        }
    }
    return 0;
}
# Blackjack - Owen Davis
## Summary of Program
This program is the classic game of Blackjack (also called 21), and is
a user vs. dealer setup. The goal is to get as 
close to 21 without going over. All face cards worth 10, Aces worth 11. 
You're given two cards, as is the dealer, and told one of the dealer's cards. 
You can stay or hit to get closer to 21. 

This program is completely in C++.

I have included a testing program, which goes over all functions in Card, Deck, and Betting.
The blackjack class's functions are all completely tested in the main program.

## Concepts used
I have three "Has-A" class relationships, with Blackjack having a Deck, Blackjack having a Betting system, 
and a Deck having multiple cards. I also included two file I/O functions within Betting to read from a file, 
and later write to it.

## Any known bugs at time of submission
Aces are usually worth both 1 and 11 at any time, but I had a 
difficult time figuring out how to fix this.

## Citations for any code not written by you or the instructor
I used this for the code on how to randomly shuffle the deck. 
User703016 gave an answer to a question on stack overflow. 
(The code implemented in mine is in Deck.cpp on line 22,23). 
Code on lines 19,20 were implemented with the help of a Teacher's Assistant.
https://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector

Cplusplus.com to explain how to use erase().
https://cplusplus.com/reference/vector/vector/erase/

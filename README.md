# M2OEP-odavis1

## My Name
Owen Davis

## Summary of Program, Module 2 Concepts Used
This program is the classic game of Blackjack (or 21), and is
a user vs. dealer setup. The goal is to get as 
close to 21 without going over. All face cards worth 10, Aces worth 11. 
You're given two cards, as is the dealer, and told one of the dealer's cards. 
You can hit or stay to get closer to 21. 

I have included a testing program, which goes over all functions in Card, Deck, and Betting,
but with the blackjack, it's class's functions are all completely tested in the main program.

I have three "Has-A" class relationships, with Blackjack having a Deck, Blackjack having a Betting system, 
and a Deck having a card (multiple). I also included two file I/O functions within Betting to read from a file, 
and later write to it.

## Any known bugs at time of submission
- Aces are usually worth both 1 and 11 at any time, but I had a 
difficult time figuring out how to fix this. (Possibly leaving it at 11
until User or Dealer goes above 21, then checking to see if they have any 
aces, and then subtracting their total by 10? But the only issue is if on 
the rare occasion a player gets two aces in their hand at one time, how do 
we decide if both are 11, one's 11 and one's 1, or both are 1's)

## Future work (how you could expand the program with more time)
1. Create a casino, and be able to choose which game you want to play
2. Expand Betting to accept any named file input from user
3. Creating a "continue" state so a continue can work for multiple runs, 
less input required from the user from every round.

## Citations for any code not written by you or the instructor
I used this for the code on how to randomly shuffle the deck. 
User703016 gave an answer to a question on stack overflow. 
(The code implemented in mine is in Deck.cpp on line 22,23). 
Code on lines 19,20 were implemented with the help of a TA.
https://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector

Cplusplus.com to explain how to use erase().
https://cplusplus.com/reference/vector/vector/erase/

## The grade you think you have earned (based on the grading rubric, with justification)
I think I've earned about 125 points. 

1. Main program complexity and usability: Takes from great section. (I think so at least, so 40 points)
    1. Great section - Uses many concepts from Module 2. Interactive with all user input validated correctly, 
and sufficiently complex for an open-ended project.
2. Testing Program: Takes from great section (20 points)
   1. Great section - Robust testing of all functions.

3. Concept: Is-A and Has-A: I feel each Has-A relationship is 
implemented and defined properly, and is important as a relationship. 
As per the grading rubric, 20 points can be awarded for each time this concept is used. 
   1. Blackjack has-a Deck (20 points)
   2. Blackjack has-a Betting system (20 points)
   3. A Deck has-a Card (multiple) (20 points)
4. Concepts: File input/output: two instances, one of each in the Betting class.
   1. Betting(string continueFile) is file input (5 points)
   2. endBettingRound() is file output (5 points)
5. Style and documentation: Generally well organized, no point loss (0 points)
6. Video: Has multiple runs, and shows user validation (0 points) 
7. Lifespan of project: Over 3 days, 5 point loss (-5 points)

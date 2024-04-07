cmake_minimum_required(VERSION 3.8)
project(M1OEP-odavis1)

set(CMAKE_CXX_STANDARD 14)

add_executable(main.cpp
        blackjack.cpp
        Card.cpp
        Deck.cpp
        main.cpp
        betting.cpp)
add_executable(testing.cpp
        blackjack.cpp
        Card.cpp
        Deck.cpp
        testing.cpp
        betting.cpp)
#pragma once
#include <iostream>

//1 --------------------------

enum class Suit {clubs, diamonds, hearts, spades};

enum class Rank {two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};

std::string suitToString(Suit suit);

std::string rankToString(Rank rank);

//1e: mye mer presist og kan ikke blandes like lett med andre ting

//----------------------------


//2 --------------------------

class Card {
private:
    Suit s;
    Rank r;

public:
    Card(Suit suit, Rank rank);
    //std::string getSuit(std::string suit);
    //std::string getRank(std::string rank);
    Suit getSuit();
    Rank getRank();
    std::string toString();

};

//----------------------------
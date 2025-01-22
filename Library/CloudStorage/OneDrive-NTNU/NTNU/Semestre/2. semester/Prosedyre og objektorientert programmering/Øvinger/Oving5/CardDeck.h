#pragma once
#include <iostream>
#include <vector>
#include "Card.h"
#include <random>

//3 --------------------------

class CardDeck {
private:
    //std::vector<Card> cards;
public:
    CardDeck();
    //std::vector<Card> getMyPrivateVector = cards;
    std::vector<Card> cards;
    void swap(int a, int b);
    void print();
    void shuffle();
    Card drawCard();

};

//----------------------------

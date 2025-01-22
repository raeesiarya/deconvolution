#pragma once
#include "CardDeck.h"
#include "Card.h"
#include <vector>

bool isAce(Card card);

class BlackJack {
private:
    CardDeck deck;
    std::vector<Card> dealerHand;
    std::vector<Card> playerHand;
    int playerHandSum = 0;
    int dealerHandSum = 0;

public:
    int getCardValue(Card kort);
    int getHandScore(std::vector<Card> kortt);
    bool askPlayerDrawCard();
};
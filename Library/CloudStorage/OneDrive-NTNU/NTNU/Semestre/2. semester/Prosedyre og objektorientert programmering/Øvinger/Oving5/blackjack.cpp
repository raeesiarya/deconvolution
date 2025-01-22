#include "blackjack.h"
#include "Card.h"
#include "CardDeck.h"
#include <iostream>

bool isAce(Card card) {
    return card.getRank() == Rank::ace;
}

int BlackJack::getCardValue(Card kort) {
    if(isAce(kort) == 1) {
        return 11;
    }
    else {
        //return kort;
        return static_cast<int>(kort.getRank());
    }
}

int BlackJack::getHandScore(std::vector<Card> kortt) {
    int poeng = 0;

    for(int i = 0; i < kortt.size(); i++) {
        Card cardd = kortt.at(i);

        if(isAce(cardd)) {
            if(poeng + getCardValue(cardd) > 10) {
                poeng++;
            }
            else {
                poeng += 11;
            }
        }
        else {
            poeng += getCardValue(cardd);
        }
    }
    return poeng;

}

bool BlackJack::askPlayerDrawCard() {
    int svar;
    std::cout << "Ønsker du et nytt kort?(Ja: skriv 1, Nei: skriv 0)";
    std::cin >> svar;
    if(svar == 1) {
        return true;
    }
    else if(svar == 0) {
        return false;
    }
    return false;
}

//4f: må få fakkings getHandScore til å funke for å gjøre oppgaven.

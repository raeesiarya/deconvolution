#include <iostream>
#include "Card.h"
#include "CardDeck.h"
#include "blackjack.h"

int main() {
    
    //1 --------------------------
    Suit suit{Suit::clubs};
    std::cout << suitToString(suit) << std::endl;

    Rank rank{Rank::three};
    std::cout << rankToString(rank) << std::endl;
    //----------------------------


    //2 --------------------------
    Card card(Suit::hearts, Rank::ace);
    std::cout << card.toString() <<  std::endl;
    //----------------------------

    //3 --------------------------
    CardDeck cdeck;
    cdeck.shuffle();
    //cdeck.swap(5,8); 
    //cdeck.shuffle();
    //cdeck.print();
    //std::cout << cdeck.drawCard().toString() << std::endl;

    //----------------------------


    //4 --------------------------
    Card kort = cdeck.drawCard();
    BlackJack bjack;
    std::cout << kort.toString() << std::endl;
    std::cout << isAce(kort) << std::endl;


    //std::cout << cdeck.getMyPrivateVector() << std::endl;
    //std::cout << bjack.getCardValue(kort) << std::endl;
    std::cout << bjack.getHandScore(cdeck.cards);
    //std::vector<Card>& kortsss = cdeck.getMyPrivateVector();
    //std::vector<Card> kortVektor;
    //kortVektor.push_back(kortsss);
    //int poengsum = bjack.getHandScore(kortVektor);


    //----------------------------

    return 0;
}
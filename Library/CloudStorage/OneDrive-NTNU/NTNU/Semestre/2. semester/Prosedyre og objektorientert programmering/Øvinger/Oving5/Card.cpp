#include <iostream>
#include "Card.h"

//1 --------------------------

std::string suitToString(Suit suit) {
    switch(suit) {
        case Suit::clubs:
            return "clubs";
            break;
        case Suit::diamonds :
            return "diamonds";
            break;
        case Suit::hearts :
            return "hearts";
            break;
        case Suit::spades :
            return "spades";
            break;
    }
}

std::string rankToString(Rank rank) {
    switch(rank) {
        case Rank::two:
            return "Two";
            break;
        case Rank::three:
            return "Three";
            break;
        case Rank::four:
            return "Four";
            break;
        case Rank::five:
            return "Five";
            break;
        case Rank::six:
            return "Six";
            break;
        case Rank::seven:
            return "Seven";
            break;
        case Rank::eight:
            return "Eight";
            break;
        case Rank::nine:
            return "Nine";
            break;
        case Rank::ten:
            return "Ten";
            break;
        case Rank::jack:
            return "Jack";
            break;
        case Rank::queen:
            return "Queen";
            break;
        case Rank::king:
            return "King";  
            break; 
        case Rank::ace:
            return "Ace";
            break;
    }
}


//----------------------------


//2 --------------------------

Card::Card(Suit suit, Rank rank) : s(suit), r(rank) {}


Suit Card::getSuit() {
    return s;
}

Rank Card::getRank() {
    return r;
} 

std::string Card::toString() {
    return rankToString(r) + " of " + suitToString(s);
}
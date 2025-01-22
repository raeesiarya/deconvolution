#include <iostream>
#include "CardDeck.h"
#include <vector>
#include <random>

//3 --------------------------

CardDeck::CardDeck() {
        cards.clear();
        for(int s = 0; s < 4; s++) {
            for(int r = 2; r < 15; r++) {
                Card newCard(static_cast<Suit>(s), static_cast<Rank>(r));
                cards.push_back(newCard);
            }
        }
    };

    void CardDeck::swap(int a, int b) {
        //std::cout << cards[a].toString() << ", " << cards[b].toString() << std::endl;
        Card temp = cards[a];
        cards[a] = cards[b];
        cards[b] = temp;
        //std::cout << cards[a].toString() << ", " << cards[b].toString() << std::endl;
    };


    void CardDeck::print() {
        //std::cout << cards.size() << std::endl;
        //std::cout << cards[15].toString() << std::endl;
       for (Card card:cards) {
        std::cout << card.toString() << std::endl;
       }
    };


    void CardDeck::shuffle() {
        for(int k = 0; k < 1000; k++) {
            swap(rand() % cards.size(), rand() % cards.size());
        }
    }
    Card CardDeck::drawCard() {
        if(cards.size() > 0) {
            Card firstcard = cards[0];
            cards.erase(cards.begin());
            return firstcard;
        }
        throw std::runtime_error("Ingen flere kort igjen!"); // kaster et unntak
    }

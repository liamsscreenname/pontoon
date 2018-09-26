#ifndef CARD_H
#define CARD_H

#include "Enums.h"

#include <string>

class Card{
private:
	Rank rank;
	Suit suit;

	//Helper Functions to return the name of the rank and suit
	std::string rankName() const;
	std::string suitName() const;

public:
	Card(const Rank, const Suit);

	Rank getRank() const;
	Suit getSuit() const;

	//Print out the name of the card to the console, i.e. "Ace of Spades"
	void printCard() const;
};

#endif
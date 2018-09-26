#ifndef HAND_H
#define HAND_H

#include "Deck.h"
#include "PontoonCard.h"

class PontoonHand: public Deck<PontoonCard>{
private:
	int handValue; //Total value of the hand

public:
	PontoonHand();

	void printHand() const; //Prints each card in the hand
	int getHandValue() const;
	void resetValue(); //Reset hand value to zero

	void addCardToHand(const PontoonCard&);
};

#endif
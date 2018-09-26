#include "PontoonHand.h"
#include "PontoonCard.h"
#include "Deck.h"

#include <deque>

PontoonHand::PontoonHand(): handValue(0) {}

void PontoonHand::printHand() const{
	std::deque<PontoonCard>::const_iterator it;
	for (it = firstCard(); it < lastCard(); it++)
		it -> printCard();
}

void PontoonHand::addCardToHand(const PontoonCard &c){
	Deck::addCardToTop(c);
	handValue += c.getValue();
}

int PontoonHand::getHandValue() const{
	return handValue;
}

void PontoonHand::resetValue(){
	handValue = 0;
}

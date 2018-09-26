#include "PontoonCard.h"

PontoonCard::PontoonCard(const Rank r, const Suit s): Card(r,s){
	//Set value of the card to the rank, unless it's Jack, Queen or King, in which case the value is 10.
	if (getRank() <= 10)
		value = getRank();
	else
		value = 10;
}

int PontoonCard::getValue() const{
	return value;
}
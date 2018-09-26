#ifndef PONTOONCARD_H
#define PONTOONCARD_H

#include "Card.h"

class PontoonCard: public Card{
private:
	int value;

public:
	PontoonCard(const Rank, const Suit);

	int getValue() const;
};

#endif
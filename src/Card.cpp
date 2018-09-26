#include "Card.h"

#include <iostream>
#include <string>

using namespace std;

Card::Card(const Rank r, const Suit s): rank(r), suit(s){}

string Card::rankName() const{
	switch (rank){
		case ACE:
			return "Ace";
		case TWO:
			return "Two";
		case THREE:
			return "Three";
		case FOUR:
			return "Four";
		case FIVE:
			return "Five";
		case SIX:
			return "Six";
		case SEVEN:
			return "Seven";
		case EIGHT:
			return "Eight";
		case NINE:
			return "Nine";
		case TEN:
			return "Ten";
		case JACK:
			return "Jack";
		case QUEEN:
			return "Queen";
		case KING:
			return "King";
		default:
			return "Exception (rank)";
			//Add exception here
	}
}

string Card::suitName() const{
	switch (suit){
		case CLUBS:
			return "clubs";
		case DIAMONDS:
			return "diamonds";
		case HEARTS:
			return "hearts";
		case SPADES:
			return "spades";
		default:
			return "Exception (suit)";
			//Add exception here
	}
}

Rank Card::getRank() const{
	return rank;
}

Suit Card::getSuit() const{
	return suit;
}

void Card::printCard() const{
	cout << rankName() << " of " << suitName() << endl;
}

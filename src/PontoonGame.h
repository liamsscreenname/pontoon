#ifndef PONTOONGAME_H
#define PONTOONGAME_H

#include "Deck.h"
#include "PontoonCard.h"
#include "PontoonHand.h"
#include "Gamelog.h"

class PontoonGame{
private:
	Deck<PontoonCard> deck;
	PontoonHand player, dealer;
	Gamelog gameLog;

public:
	PontoonGame(); //Constructor to initialise and shuffle deck
	~PontoonGame(); //Destructor

	bool playAgain() const;
	void newGame(); //Return all cards to deck, shuffle and start again

	void dealTwo(PontoonHand&);
	void twist(PontoonHand&);

	void playerRound();
	void dealerRound();

	void game();
};

#endif
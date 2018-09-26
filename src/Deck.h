#ifndef DECK_H
#define DECK_H

#include <deque>
#include <vector>
#include <ctime>
#include <cstdlib> //for random number
#include <algorithm> //for std::fill

template<typename CARDTYPE>
class Deck{
private:
	std::deque<CARDTYPE> deck;

public:
	Deck<CARDTYPE>(){ //Constructor
		srand(time(0)); //Seed random number generator;
	}

	int cardsInDeck() const{ //Return the current number of cards in the deck
		return deck.size();
	} 

	void addCardToTop(const CARDTYPE& card){ //Add card to top of deck
		deck.push_front(card);
	} 

	CARDTYPE& nextCard(){
		CARDTYPE &temp = deck.front(); //Temporarily store reference to top card
		deck.pop_front(); //Remove top card from the deck
		return temp; //Return reference to removed card
	}; 

	typename std::deque<CARDTYPE>::const_iterator firstCard() const{ //Return a reference to the first card of the deck, to be used for iterating
		return deck.cbegin();
	}

	typename std::deque<CARDTYPE>::const_iterator lastCard() const{ //Return a reference to the last card of the deck, to be used for iterating
		return deck.cend();
	}

	void shuffle(){ //Shuffles the deck
		std::vector<CARDTYPE> storage; //Create an array to temporarily store all cards
		int initialDeckSize = cardsInDeck();
		for (int i = 0; i < initialDeckSize; i++){ //Remove all cards from deck and place in storage
			storage.insert(storage.end(), nextCard()); 
		}
		int randNums[initialDeckSize]; //Array to hold numbers already generated, to avoid repetition of numbers. 
		std::fill_n(randNums, initialDeckSize, initialDeckSize+1); //Initialise all elements to be outside the random number generator range
		int currentNum;
		bool alreadyPicked{true};

		for (int i = 0; i < initialDeckSize; i++){
			alreadyPicked = true;
			while (alreadyPicked){
				currentNum = rand() % initialDeckSize;
				for (int j = 0; j < initialDeckSize; j++){ //Search through the array of numbers already selected, and if the current one is in there a new number will be generated
					if (currentNum == randNums[j]){
						alreadyPicked = true;
						break;
					}
					alreadyPicked = false;
				}
				if (!alreadyPicked){
					addCardToTop(storage[currentNum]);
					randNums[i] = currentNum;
				}
			} 
		}
	}; 
};

#endif
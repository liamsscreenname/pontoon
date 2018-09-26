#include "PontoonGame.h"
#include "Deck.h"
#include "PontoonCard.h"
#include "PontoonHand.h"
#include "Enums.h"

#include <iostream>
#include <string>

using namespace std;

PontoonGame::PontoonGame(){ 
	for (int i = 0; i < 4; i++){
		for (int j = 1; j < 14; j++){
			deck.addCardToTop(PontoonCard(static_cast<Rank>(j), static_cast<Suit>(i))); //Add standard 52 cards to the deck
		}
	}
	newGame();
}

PontoonGame::~PontoonGame(){

}

bool PontoonGame::playAgain() const{
	string input;
	while (input != "Y" || input != "y" || input != "N" || input != "n"){ 
		cout << "\nPlay again? (yes(y) or no(n)" << endl;
		cin >> input;
		if (input == "Y" || input == "y")
			return true;
		else if (input == "N" || input == "n")
			return false;
	}
}

void PontoonGame::newGame(){
	int handSize = player.cardsInDeck(); //Temporary int to store initial number of cards in player and dealers hands...
	for (int i = 0; i < handSize; i++){ //...so that the correct number of cards are taken from the players hands and returned to the deck
		deck.addCardToTop(player.nextCard());
	}
	player.resetValue();
	handSize = dealer.cardsInDeck();
	for (int i = 0; i < handSize; i++){
		deck.addCardToTop(dealer.nextCard());
	}
	dealer.resetValue();
	deck.shuffle();
	gameLog.startRound();
	game();
}

void PontoonGame::dealTwo(PontoonHand &h){
	for (int i = 0; i < 2; i++){
		h.addCardToHand(deck.nextCard());
	}
}

void PontoonGame::twist(PontoonHand &h){
	cout << "\nDealing next card..." << endl;
	h.addCardToHand(deck.nextCard());
}

void PontoonGame::playerRound(){
	cout << "\nYour cards: " << endl;
	player.printHand();
	cout << "\nYour score: " << player.getHandValue() << endl;
	while (player.getHandValue() < 21 && player.cardsInDeck() < 5){
		cout << "\nWould you like to stick(s) or twist(t)?" << endl;
		string input;
		cin >> input;
		if (input == "s" || input == "S" || input == "stick" || input == "Stick" || input == "STICK"){
			cout << "\nYou have stuck on " << player.getHandValue() << endl;
			break;
		}
		else if (input == "t" || input == "T" || input == "twist" || input == "Twist" || input == "TWIST"){
			twist(player);
			cout << "\nYour cards: " << endl;
			player.printHand();
			if (player.getHandValue() < 21)
				cout << "\nYour score: " << player.getHandValue() << endl;
		}
	}
	if (player.getHandValue() == 21)
		cout << "\nTwenty One!";
	else if (player.getHandValue() > 21)
		cout << "\nBust!" << endl;
	else if (player.cardsInDeck() == 5)
		cout << "\nMaximum number of cards reached. Your final score: " << player.getHandValue() << endl;
}

void PontoonGame::dealerRound(){
	cout << "\nDealer's cards: " << endl;
	dealer.printHand();
	cout << "\nDealer's score: " << dealer.getHandValue() << endl;
	while (dealer.getHandValue() < 21 && dealer.cardsInDeck() < 5){
		twist(dealer);
		cout << "\nDealer's cards: " << endl;
		dealer.printHand();
		cout << "\nDealer's score: " << dealer.getHandValue() << endl;
	}
	if (dealer.getHandValue() == 21)
		cout << "\nDealer gets Twenty One!" << endl;
	else if (dealer.getHandValue() > 21)
		cout << "\nDealer bust!" << endl;
}

void PontoonGame::game(){
	cout << "\nDealing to player..." << endl; //Deal two cards to each player
	dealTwo(player);
	cout << "\nDealing to Dealer..." << endl;
	dealTwo(dealer);
	cout << "\nYour turn." << endl;

	playerRound(); //Player's turn

	if (player.getHandValue() > 21){ // Dealer wins (player's score goes over 21)
		cout << "\nYou lose! Better luck next time!" << endl;
		gameLog.endRound(-1); //-1 is log's code for a loss
		if (playAgain()){
			newGame();
			return; 
		}
		else
			return;
	}
	dealerRound(); //Dealer's turn'

	//Compare player and dealer's hand scores
	if (dealer.getHandValue() > 21 || dealer.getHandValue() < player.getHandValue()){ //Player wins (Dealer goes bust or player's hand value is greater)
		cout << "\nYou win! Congratulations!" << endl;
		gameLog.endRound(1); //1 is log's code for a win
		if (playAgain()){
			newGame();
			return;
		}
		else
			return;
	}

	else if (player.getHandValue() == dealer.getHandValue()){ //Hand values are the same, so player with the lowest number of cards in their hand wins
		if (player.cardsInDeck() > dealer.cardsInDeck()){
			cout << "\nYou lose! Better luck next time!" << endl;
			gameLog.endRound(-1);
		}
		else if (dealer.cardsInDeck() > player.cardsInDeck()){
			cout << "\nYou win! Congratulations!" << endl;
			gameLog.endRound(1);
		}
		else{ // If both players have the same score and the same number of cards in their hand, the game is a draw
			cout << "\nDraw." << endl;
			gameLog.endRound(0); //0 is log's code for a draw
		}
		if (playAgain()){
			newGame();
			return;
		}
		else
			return;
	}

	else{ //Dealer wins (player is bust or dealer's hand value is greater)
		cout << "\nYou lose! Better luck next time!" << endl;
		gameLog.endRound(-1);
		if (playAgain()){
			newGame();
			return; 
		}
		else
			return;
	}
}
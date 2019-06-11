//============================================================================
// Name        : main.cpp
// Author      : Dominic Quintero
// Version     :
// Copyright   :
// Description : Testing file
//============================================================================

#include "Deck.h"
#include "TerminalPlayer.h"
#include "ComputerPlayer.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;
int main(){
	// Initialize game
	string playerName;
	cout << "Enter player name: ";
	cin >> playerName;

	// Create players and deck
	TerminalPlayer player1(playerName);
	ComputerPlayer player2(playerName);
	Deck theDeck;
	theDeck.shuffle();

	// Populate hands of players
	for (int i = 0; i < MAX_HAND_SIZE; i++)
	{
		player1.receiveCard(theDeck.draw());
		player2.receiveCard(theDeck.draw());
	}

	// Determines who goes first
	int coinFlip = 0;
	bool player1First;
	srand (time(NULL));
	coinFlip = rand() % 1 + 0;

	if (coinFlip == 1)
		player1First = true;
	else
		player1First = false;

	// Game loop, game goes until deck is empty and either player 1 or 2 has no cards left
	while (player1.hasCards() || player2.hasCards())
	{
		Card Joker, cardP1, cardP2, tempP2;
		bool validSelect = true;

		try{
			// Determines who goes first
			if (player1First){
				cardP1 =  player1.playCard(Joker);
				cardP2 =  player2.playCard(cardP1);
			}
			else{
				cardP2 =  player2.playCard(Joker);
				tempP2 = cardP2;
				cardP1 =  player1.playCard(cardP2);
			}
		}
		catch(const std::out_of_range& oor){
			// Catch error, return computers played card to hand, make valid = false
			cout << oor.what() << endl;
			player2.receiveCard(tempP2);
			validSelect = false;
			cout << "\n";
		}

		// If choice is not valid, return back to start of loop
		if(validSelect){
			// Displays chosen cards of player & cpu
			cout << player2 << ": " << cardP2 << endl;
			cout << player1 << ": " << cardP1 << endl;

			// Award points for proper conditions
			if (cardP1 == cardP2)
				cout << "Tie" << endl;
			else if (cardP1 < cardP2){
				cout << player2 << " wins!" << endl;
				player2.addScore(1);
				player1First = false;
			}
			else{
				cout << player1 << " wins" << endl;
				player1.addScore(1);
				player1First = true;
			}

			// Create space between turns
			cout << "\n";
			// Replenish cards at end of round if deck is not empty, break out of loop if empty and either player has no cards left
			if (!theDeck.isEmpty()){
				player1.receiveCard(theDeck.draw());
				player2.receiveCard(theDeck.draw());
			}
			else if (theDeck.isEmpty() && (!player1.hasCards() || !player2.hasCards()))
				break;
		}
	}

	// Find the winner of the game and prompt who won
	cout << "Final Scores:" << endl;
	cout << player1 << "'s score: " << player1.getScore() << endl;
	cout << player2 << "'s score: " << player2.getScore() << endl;

	if (player1.getScore() > player2.getScore())
		cout << player1 << " wins";
	else
		cout << player2 << " wins";

	cout << " the game!" << endl;
}


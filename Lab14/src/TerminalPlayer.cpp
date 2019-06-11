/*
 * TerminalPlayer.cpp
 *
 *  Created on: May 6, 2019
 *      Author: student
 */
#include "TerminalPlayer.h"

using namespace std;
TerminalPlayer::TerminalPlayer(std::string name) : Player::Player(name)
{
	//Empty, passes protected values
}

const Card TerminalPlayer::playCard(const Card opponentCard)
{
	unsigned select;
	int handSize = hand.size();

	// check if opponentCard is a joker, it so terminal player is going first, else we are going second
	if (opponentCard.isJoker())
		cout << "You are going first" << endl;
	else
		cout << "Your opponent played " << opponentCard << endl;

	// Display cards and prompt user to pick a card
	for (int i = 0; i < handSize; i++){
		cout << i+1 << ". " << hand[i]<< "\n";
	}
	cout << "Select a card" << endl;

	// Prevents user from entering non-numeric selection
    while(!(cin >> select)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw std::out_of_range ("Please choose a valid card.");
    }

	// Error Check
	if (select > unsigned(handSize) || select <= 0)
		throw std::out_of_range ("Please choose a valid card.");

	// Remove selected card from hand, -1 from select because its 1-3 not 0-2
	Card cardSelected = hand[select-1];
	hand.erase (hand.begin() + select-1);
	return cardSelected;
}

// Output players name
std::ostream& operator <<(std::ostream& out, const Player& p)
{
	out << p.name;
	return out;
}

TerminalPlayer::~TerminalPlayer(){
	//Empty deconstructor
}


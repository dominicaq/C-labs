/*
 * ComputerPlayer.cpp
 *
 *  Created on: May 13, 2019
 *      Author: student
 */
#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(std::string name) : Player::Player(name)
{
	// Assigns default computer player name, constructor cant be blank or it wont compile
	this->name = "CPU";
}

// Randomly chooses between 0 through handsize, returns chosen card
const Card ComputerPlayer::playCard(const Card opponentCard)
{
	int randNumber, handSize = hand.size();
	srand (time(NULL));

	randNumber = rand() % handSize + 0;
	Card cardSelected = hand[randNumber];
	hand.erase (hand.begin() + randNumber);
	return cardSelected;
}


ComputerPlayer::~ComputerPlayer(){
	//Empty deconstructor
}

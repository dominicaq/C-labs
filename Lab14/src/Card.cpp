/*
 * Card.cpp
 *
 *  Created on: Apr 26, 2019
 *      Author: dquintero
 */

#include "Card.h"

// Default constructor
Card::Card(){
	cardSuit = Spades;
	cardRank = Joker;
}

// Constructor with parameters
Card::Card(Suit s, Rank r){
	cardSuit = s;
	cardRank = r;
}

// Output to terminal
std::ostream& operator <<(std::ostream& out, const Card&c){
	out << rankNames[c.cardRank] << " of " << suitNames[c.cardSuit];
	return out;
}

// Check if cards are equal
bool operator ==(const Card &lhs, const Card &rhs){
	return (lhs.cardRank == rhs.cardRank);
}

// Check if card rank is greater than other card rank
bool operator <(const Card &lhs, const Card &rhs){
	return (lhs.cardRank < rhs.cardRank);
}


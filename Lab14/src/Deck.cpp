/*
 * Deck.cpp
 *
 *  Created on: Apr 26, 2019
 *      Author: dquintero
 */

#include "Deck.h"
#include <algorithm>
#include <stdexcept>

// Default constructor
Deck::Deck()
{
	std::vector<Card>initDeck;

	// Creating a stack of 52 cards, excluding joker cards
	for(int i = 0; i < 4;i++)
	{
		Card::Suit suit = static_cast<Card::Suit>(i);

		for(int j = 1; j < 14; j++)
		{
			Card::Rank rank = static_cast<Card::Rank>(j);
			Card card(suit,rank);
			initDeck.push_back(card);
		}
	}

	// Set default values
	cardDeck = initDeck;
	nextCard = 0;
}

// Randomize deck
void Deck::shuffle()
{
	std::random_shuffle(cardDeck.begin(), cardDeck.end());
	nextCard = 0;
}

// Check if deck is empty
bool Deck::isEmpty() const
{
	return (nextCard >= MaxCards);
}

// Draw a card from deck and resize, if empty is true throw exception
const Card Deck::draw()
{
	if (!isEmpty())
	{
		Card ret = cardDeck[nextCard++];
		return ret;
	}
	else
		throw std::out_of_range ("Deck is empty, cannot draw");
}

Deck::~Deck() {
	// Empty
}

/*
 * TerminalPlayer.h
 *
 *  Created on: May 6, 2019
 *      Author: student
 */

#ifndef TERMINALPLAYER_H_
#define TERMINALPLAYER_H_

#include "Player.h"
#include <limits>
#include <stdexcept>

class TerminalPlayer : public Player {
public:
	TerminalPlayer(std::string name);
	virtual ~TerminalPlayer();

	virtual const Card playCard(const Card opponentCard);
	friend std::ostream& operator <<(std::ostream& out, const Player& p);
};

#endif

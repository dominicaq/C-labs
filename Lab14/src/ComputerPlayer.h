/*
 * ComputerPlayer.h
 *
 *  Created on: May 13, 2019
 *      Author: student
 */

#ifndef COMPUTERPLAYER_H_
#define COMPUTERPLAYER_H_

#include "Player.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class ComputerPlayer : public Player {
public:
	ComputerPlayer(std::string name);
	virtual~ComputerPlayer();

	// Returns a random card from hand
	virtual const Card playCard(const Card opponentCard);

};

#endif /* COMPUTERPLAYER_H_ */

/******************************************************
**Program: card_games.h
**Author: Daniel Kirkpatrick
**Date:
**Description: Contains the function prototypes for card_games.cpp
**Input:
**Output:
******************************************************/
#ifndef CARD_GAMES_H_
#define CARD_GAMES_H_

#include <iostream>

#include "deck.h"
#include "player.h"

//using namespace std;

class card_games {
public:
	card_games();
	static char choose_game();
	virtual void play();

private:
	char game_picked;

protected:
	deck d;
	player p;


};
#endif /* CARD_GAMES_H_ */

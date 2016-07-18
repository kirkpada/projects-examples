/******************************************************
**Program: player.h
**Author: Daniel Kirkpatrick
**Date:
**Description: Contains class and prototypes for player.cpp
**Input:
**Output:
******************************************************/
#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <algorithm>

#include "card.h"
#include "deck.h"

using namespace std;

class player {
public:
	player();
	void create_hand(int);
	void increase_hand(int, int);
	void decrease_hand(int, int);
	void show_hand(int);
	card get_hand(int);
	void rank_sort(int);

	static vector<card> p1;
	static vector<card> p2;
	static vector<card> p3;
	static vector<card> p4;
	static vector<card> p5;
	static vector<card> p6;
};

#endif /* PLAYER_H_ */

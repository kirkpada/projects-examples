/******************************************************
**Program: deck.h
**Author: Daniel Kirkpatrick
**Date:
**Description: Contains class and prototypes for deck.cpp
**Input:
**Output:
******************************************************/
#ifndef DECK_H_
#define DECK_H_

#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <vector>

#include "card.h"

using namespace std;

class deck {
public:
	string suit(int);
	string rank(int);
	card create_card(int, int);
	void fill_deck();
	void shuffle_deck();
	card draw_card(card*);
	void deck_size(int);
	card get_card(int);

	static vector<card> d;

};

#endif /* DECK_H_ */

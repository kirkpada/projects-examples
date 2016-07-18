/******************************************************
**Program: go_fish.h
**Author: Daniel Kirkpatrick
**Date:
**Description: Contains class and prototypes for go_fish.cpp
**Input:
**Output:
******************************************************/
#ifndef GO_FISH_H_
#define GO_FISH_H_

#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <vector>

#include "card_games.h"
#include "card.h"
#include "deck.h"
#include "player.h"

using namespace std;

class go_fish : public card_games {
public:
	go_fish();
	void play();
	void fish_rules();
	int init_players();
	void two_players();
	void three_players();
	void four_players();
	void five_players();
	void six_players();
	void ask_player();
	void turn();
	void check_player_hand(int, int, string);
	void draw_taken_cards();      //<--- finish this
	void go_fish_draw(int);
	void match_four(string);
	void discard_four(string);
	void empty_hand();
	void empty_deck();

private:
	int play_num;
	int turn_count;
	int player_pick;
	int players;
	string card_rank;
	deck d;
	player p;
};
#endif /* GO_FISH_H_ */

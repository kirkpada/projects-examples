/******************************************************
**Program: poker.h
**Author: Daniel Kirkpatrick
**Date:
**Description: Contains function prototypes for poker.cpp
**Input:
**Output:
******************************************************/
#ifndef POKER_H_
#define POKER_H_

#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <algorithm>

#include "card_games.h"
#include "card.h"
#include "deck.h"
#include "player.h"

using namespace std;

class poker : public card_games {
public:
	poker();
	void play();
	void poker_rules();
	int init_players();
	void new_hands();
	void two_players();
	void three_players();
	void four_players();
	void five_players();
	void six_players();
	int num_hands();
	void turn();
	void ask_player();
	void discard_unwanted(int);
	void draw_new_cards(int);
	void hand_check();
	void three_of_kind();
	void straight();
	void flush();
	void full_house();
	void four_of_kind(); 
	void straight_flush();
	void no_hand();
	void point_keeper(int, int);
	void point_printer();

private:
	int play_num;
	int turn_count;
	int pick_card;
	int players;
	int hands;
	int game_counter;
	int p1_points;
	int p2_points;
	int p3_points;
	int p4_points;
	int p5_points;
	int p6_points;
	string card_rank;
	deck d;
	player p;
};
#endif /* POKER_H_ */

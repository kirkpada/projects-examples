/******************************************************
**Program: game_driver.cpp
**Author: Daniel Kirkpatrick
**Date:
**Description: Driver file for the games
**Input:
**Output:
******************************************************/

#include <iostream>
#include <string>

#include "card_games.h"
#include "poker.h"
#include "go_fish.h"

using namespace std;

vector<card> deck::d;
vector<card> player::p1;
vector<card> player::p2;
vector<card> player::p3;
vector<card> player::p4;
vector<card> player::p5;
vector<card> player::p6;

int main()
{
    srand(time(0));

	card_games *game;

	char game_choice;

	//select which game to play
	game_choice = game->choose_game();

	//select poker
	if(game_choice == 'p')
	{
		game = new poker;
	}
	//select go fish
	else if(game_choice == 'g')
	{
		game = new go_fish;
	}

	game->play();

	return 0;
}

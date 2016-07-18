/******************************************************
**Program: card_games.cpp
**Author: Daniel Kirkpatrick
**Date:
**Description: Selects which game to play and runs it
**Input:
**Output:
******************************************************/

#include "card_games.h"

//default constructor
card_games::card_games()
{
	game_picked = ' ';
}//***************** end ask_player **********************


//select which game to play
char card_games::choose_game()
{
    char game_picked = ' ';
	cout << "Please select which game you want to play!!" << endl;
	cout << "Choose (p) for 5 card Poker or choose (g) for Go Fish: " << endl;
	cin >> game_picked;

	return game_picked;
}//***************** end choose_game **********************


//Pure virtual function
void card_games::play()
{
    //empty
}//***************** end play **********************

/*******************************************************************
** Program Filename: connect_four.h
** Author: Daniel Kirkpatrick
** Date: 
** Description: Contains struct and function prototypes for
** 		connect_four.cpp
** Input:
** Output:
********************************************************************/



struct game{
	char **p1_board[rows][cols];
	char p1;
	char p2;
};


//******* Function Prototypes ********
void init_board(game*, int, int);
void print_board(game*, int, int);

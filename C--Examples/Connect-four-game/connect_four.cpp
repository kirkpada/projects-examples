/*******************************************************************
** Program Filename: connect_four.cpp
** Author: Daniel Kirkpatrick
** Date:
** Description: Functions for connect four game
** Input:
** Output:
********************************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "./connect_four.h"

using namespace std;

/********************************************************************
** Function: init_board
** Description: used to create gameboard
** Parameters: game* gb, int max_rows, int max_cols
** Pre-Conditions:
** Post-Conditions:
********************************************************************/ 
void init_board(game* gb, int max_rows, int max_cols){
	for(int rows=0; rows<max_rows ; rows++){
		for(int cols=0; cols<max_cols ; cols++){
			gb->p1_board[rows][cols] = ' ';
		}
	}

}//end init_board

/*******************************************************************
** Function: p1_choice
** Description: determins what color p1 is
** Parameters: game* gb
** Pre-Conditions:
** Post-Conditions:
********************************************************************/ 
char p1_choice(game* gb){
	cout << "Player 1: choose red or yellow (r or y): ";
	cin >> gb->p1;
	cout << "Player 1 is: " << gb->p1;
	cout << endl;

	return gb->p1;
}//end p1_choice

/*******************************************************************
** Function: ps_choice
** Description: determines what color p2 is based on p1 selection
** Parameters: game* gb
** Pre-Conditions:
** Post-Conditions:
********************************************************************/ 
char p2_choice(game* gb){
	if(gb->p1 == 'r'){
		gb->p2 = 'y';
		cout << "Player 2 is: " << gb->p2;
		cout << endl;
	}
	else{
		gb->p2 = 'r';
		cout << "Player 2 is: " << gb->p2;
		cout << endl;
	}
	
	return gb->p2;
}//end p2_choice

/*******************************************************************
** Function: determine_first_player
** Description:	using random num gen to determine who plays first
** Parameters: game* gb
** Pre-Conditions:
** Post-Conditions:
********************************************************************/ 
int determine_first_player(game* gb){
	int rand_turn;
	rand_turn = (rand()%2)+1;
	if(rand_turn == 1){
		cout << "Player 1 goes first!!" << endl;
		cout << "Good luck!" << endl;
	}
	else{
		cout << "Player 2 goes first!!" << endl;
		cout << "Good luck!" << endl;
	}

	return rand_turn;
}//end determine turn

/*******************************************************************
** Function: fill_board
** Description: inserts pieces into the gameboard
** Parameters: game* gb, int p_turn
** Pre-Conditions:
** Post-Conditions:
********************************************************************/ 
int fill_board(game* gb, int p_turn, int max_col){
	int row=0, col, turn;

	turn = p_turn;
	
	if(turn == 1){
		cout << "Player 1: Which column would you like to place a piece: ";
		cin >> col;
		while(col>max_col && col<0){
			cout << "You entered a column that is out of bounds!!" << endl;
			cout << "Pick another column: ";
			cin >> col;
		}
		if(gb->p1_board[row][col] == 'r' || gb->p1_board[row][col] == 'y'){
			row++;
			gb->p1_board[row][col] = gb->p1;
		}
		else{
			gb->p1_board[row][col] = gb->p1;
		}
		turn++;
	}

	else if(turn == 2){
		cout << "Player 2: Which column would you like to place a piece: ";
		cin >> col;
		while(col>max_col && col<0){
			cout << "You entered a column that is out of bounds!!" << endl;
			cout << "Pick another column: ";
			cin >> col;
		}
		if(gb->p1_board[row][col] == 'r' || gb->p1_board[row][col] == 'y'){
			row++;
			gb->p1_board[row][col] = gb->p2;
		}
		else{
			gb->p1_board[row][col] = gb->p2;
		}
		turn--;
	}

	return turn;
}//end fill_board

/*******************************************************************
** Function: print_board
** Description: prints the game board after every turn
** Parameters: game* gb
** Pre-Conditions:
** Post-Conditions:
********************************************************************/ 
void print_board(game* gb, int rows, int cols){
	for(int init_row=0;init_row<=rows;init_row++){
		for(int init_col=0;init_col<=cols;init_col++){
			cout << "|";
			cout << gb->p1_board[init_row][init_col];
			cout << "|";
		}

		cout << endl;

		for(int col_leng=0;col_leng<=cols;col_leng++){
			cout << "___";
		}
		cout << endl;
	}

}//end print_board

/*******************************************************************
** Function: win_check
** Description: checks to see who wins
** Parameters: game* gb
** Pre-Conditions:
** Post-Conditions:
********************************************************************/
//int win_check(game*){


//}//end win_check

/*******************************************************************
** Function: print_winner
** Description: prints out which player wins
** Parameters: game* gb, int winner, int order
** Pre-Conditions:
** Post-Conditions:
********************************************************************/ 
/*int print_winner(game* gb, int winner, int order){
	//if there is a winner
	if(winner == 1){
		if(order == 1){
			cout << "\nThe winner is: Player 1!" << endl;
			print_board(gb);
			return 1;
		}
		else if(order == 2){
			cout << "\nThe winner is: Player 2!" << endl;
			print_board(gb);
			return 1;
		}
	}
	//no winner still
	else{
		return 0;
	}

}//end print_winner */

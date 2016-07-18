/*******************************************************************
** Program Filename: play_cf.cpp
** Author: Daniel Kirkpatrick
** Date:
** Description: Driver file for connect four game
** Input:
** Output:
********************************************************************/

#include <iostream>
#include "./connect_four.h"

using namespace std;

int main (int argc, char* argv[]){
	srand((unsigned)time(0));
	game gb;	

	int rows = atoi(argv[2]);
	int cols = atoi(argv[4]);
	int con_piece = atoi(argv[6]);

	cout << "rows: " << rows << endl;
	cout << "cols: " << cols << endl;
	cout << "connecting pieces: " << con_piece << endl;
	cout << endl;
	cout << endl;

	cout << "making board" << endl;
	init_board(&gb, rows, cols);

	//p1_choice(&gb);
	//p2_choice(&gb);
	//determine_first_player(&gb);
	cout << "showing board" << endl;
	print_board(&gb, rows, cols);

}//end main

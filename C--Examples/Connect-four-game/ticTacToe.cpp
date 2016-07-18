#include <iostream>
#include <ctime>
#include <cstdlib>

#define MAX_ROWS 3
#define MAX_COLS 3
using namespace std;

//struct for game
struct tic_tac_toe{
	char board[MAX_ROWS][MAX_COLS];
	char player1;
	char player2;

};

//******************** Function Prototypes ********************
void initialize_board(tic_tac_toe*);
char determine_player1_choice(tic_tac_toe*);
char determine_player2_choice(tic_tac_toe*);
int determine_player_turn(tic_tac_toe*);
int fill_board(tic_tac_toe*, int);
void print_board(tic_tac_toe*);
void is_full(int);
int check_for_winner(tic_tac_toe*);
int print_winner_results(tic_tac_toe*, int, int);


//Main functions (driver)
int main(){
	srand((unsigned)time(0));
	tic_tac_toe game;

	int winner = 0, count = 0, order = 0, nextTurn = 0, winCheck = 0, breakCheck = 0, replay = 1;

	do{
		initialize_board(&game);
		determine_player1_choice(&game);
		determine_player2_choice(&game);
		order = determine_player_turn(&game);
		print_board(&game);
		nextTurn = fill_board(&game, order);

		while(count < 9){
			print_board(&game);
			nextTurn = fill_board(&game, nextTurn);
			count ++;
			is_full(count);
			winCheck = check_for_winner(&game);
			breakCheck = print_winner_results(&game, winCheck, order);
			if(breakCheck == 1){
				break;
			}
		}
		cout << "Would you like to play again?" << endl;
		cout << "1 - yes, 0 - no: ";
		cin >> replay;
	}
	while(replay == 1);


	return 0;
}

//******************** Game Functions ********************

//creates the game board
void initialize_board(tic_tac_toe *g){
	int rows, cols;

	for(rows = 0; rows < MAX_ROWS; rows++){
		for(cols = 0; cols < MAX_COLS; cols++){
			g->board[rows][cols] = ' ';
		}
	}
}//end init_board

//determines if player 1 is x or o 
char determine_player1_choice(tic_tac_toe *g){
	//set what player 1 is
	cout << "Player 1: which would you like to be? (x or o): ";
	cin >> g->player1;
	cout << "Player 1 is: " << g->player1; 	
	cout << endl;
	return g->player1;
}//end determine p1

//determine is player 2 is x or o
char determine_player2_choice(tic_tac_toe *g){
	//sets what player 2 is based on player 1 selection 
	if(g->player1 == 'x'){
		g->player2 = 'o';
		cout << "Player 2 is: " << g->player2;
		cout << endl;
	}
	else{
		g->player2 = 'x';
		cout << "Player 2 is: " << g->player2;
		cout << endl;
	}
	return g->player2;
}//end determine p2

//randomly selects which player goes first 
int determine_player_turn(tic_tac_toe *g){
	int rand_turn;
	rand_turn = (rand()%2)+1;
	if(rand_turn == 1){
		cout << "Player 1 goes first!" << endl;
	}
	else{
		cout << "Player 2 goes first!" << endl;
	}
	return rand_turn; 
}//end determine turn

//allows players to pick where they put pieces
int fill_board(tic_tac_toe *g, int player_turn){
	int row, col, turn;

	turn = player_turn;

	if(turn == 1){
		cout << "Player 1: Where would you like to place your piece?" << endl; 
		cout << g->player1 << endl;
		cout << "Which row: ";
		cin >> row;
		while(row > 2){
			if(row > 2){
				cout << "You entered a number that is out of bounds!!" << endl;
				cout << "Insert a number between 0 and 2!!: ";
				cin >> row;
			}
		}
		cout << "Which col: ";
		cin >> col;
		while(col > 2){
			if(col > 2){
				cout << "You entered a number that is out of bounds!!" << endl;
				cout << "Insert a number between 0 and 2!!: ";
				cin >> col;
			}
		}
		if(g->board[row][col] == 'x' || g->board[row][col] == 'o'){
			cout << "The spot is already taken!!" << endl;
			print_board(g);
			fill_board(g, turn);
		}
		else{	
			g->board[row][col] = g->player1;

		}
		turn ++;
	}
	else if(turn == 2){
		cout << "Player 2: Where would you like to place your piece?" << endl; 
		cout << g->player2 <<endl;
		cout << "Which row: ";
		cin >> row;
		while(row > 2){
			if(row > 2){
				cout << "You entered a number that is out of bounds!!" << endl;
				cout << "Insert a number between 0 and 2!!: ";
				cin >> row;
			}
		}
		cout << "Which col: ";
		cin >> col;
		while(col > 2){
			if(col > 2){
				cout << "You entered a number that is out of bounds!!" << endl;
				cout << "Insert a number between 0 and 2!!: ";
				cin >> col;
			}
		}
		if(g->board[row][col] == 'x' || g->board[row][col] == 'o'){
			cout << "The spot is already taken!!" << endl;
			print_board(g);
			fill_board(g, turn);
		}
		else{
			g->board[row][col] = g->player2;

		}
		turn --;
	}

	return turn;
}//end fill_board

//prints the board 
void print_board(tic_tac_toe *g){
	cout << "  " << g->board[0][0]  << " | " << g->board[0][1]  << " | " << g->board[0][2]  <<  endl;
	cout << "-------------" << endl;
	cout << "  " << g->board[1][0] << " | " << g->board[1][1]  << " | " << g->board[1][2]  <<  endl;
	cout << "-------------" << endl;
	cout << "  " << g->board[2][0]  << " | " << g->board[2][1]  << " | " << g->board[2][2]  <<  endl;
}//end print

//checks to see if the board is full
void is_full(int count){
	if(count == 9){
		cout << "Nobody has won!!" << endl;
		cout << "Game is a tie!!" << endl;
	
}//end full check

//checks to see if someone won
int check_for_winner(tic_tac_toe *g){
	//row wins
	if(g->board[0][0] == 'x' &&  g->board[0][1] == 'x' && g->board[0][2] == 'x' || g->board[0][0] == 'o' && g->board[0][1] == 'o' && g->board[0][2] == 'o'){
		return 1;
	}	
	if(g->board[1][0] == 'x' &&  g->board[1][1] == 'x' && g->board[1][2] == 'x' || g->board[1][0] == 'o' && g->board[1][1] == 'o' && g->board[1][2] == 'o'){
		return 1;
	}
	if(g->board[2][0] == 'x' &&  g->board[2][1] == 'x' && g->board[2][2] == 'x' || g->board[2][0] == 'o' && g->board[2][1] == 'o' && g->board[2][2] == 'o'){
		return 1;
	}
	//col wins
	if(g->board[0][0] == 'x' &&  g->board[1][0] == 'x' && g->board[2][0] == 'x' || g->board[0][0] == 'o' && g->board[1][0] == 'o' && g->board[2][0] == 'o'){
		return 1;
	}
	if(g->board[0][1] == 'x' &&  g->board[1][1] == 'x' && g->board[2][1] == 'x' || g->board[0][1] == 'o' && g->board[1][1] == 'o' && g->board[2][1] == 'o'){
		return 1;
	}	
	if(g->board[0][2] == 'x' &&  g->board[1][2] == 'x' && g->board[2][2] == 'x' || g->board[0][2] == 'o' && g->board[1][2] == 'o' && g->board[2][2] == 'o'){
		return 1;
	}
	//diagonal wins
	if(g->board[0][0] == 'x' &&  g->board[1][1] == 'x' && g->board[2][2] == 'x' || g->board[0][0] == 'o' && g->board[1][1] == 'o' && g->board[2][2] == 'o'){
		return 1;
	}
	if(g->board[0][2] == 'x' &&  g->board[1][1] == 'x' && g->board[2][0] == 'x' || g->board[0][2] == 'o' && g->board[1][1] == 'o' && g->board[2][0] == 'o'){
		return 1;
	}
	else{
		return 0;
	}
}//end winner check 

//prints whoever the winner is
int print_winner_results(tic_tac_toe *g, int winner, int order){
	if(winner == 1){
		if(order == 1){
			cout << "\nThe winner is: Player 1!!" << endl;
			print_board(g);
			return 1;
		}
		else if(order == 2){
			cout << "\nThe winner is: Player 2!!" << endl;
			print_board(g);
			return 1;
		}
	}
	else{
		return 0;
	}
}//end print for winner

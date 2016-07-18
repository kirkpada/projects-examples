/******************************************************
**Program: go_fish.cpp
**Author: Daniel Kirkpatrick
**Date:
**Description: Contains the rules for game
**Input:
**Output:
******************************************************/

#include "go_fish.h"

//default constructor
go_fish::go_fish()
{
	turn_count = 1;
	play_num = 0;
	player_pick = 0;
	players = 0;
	string card_rank = " ";
}//***************** end go_fish **********************


//Plays selected game
void go_fish::play()
{
	go_fish game;

	//start of game
	d.deck::fill_deck();
	game.fish_rules();
	players = game.init_players();

	do
	{
		game.empty_hand();
		game.empty_deck();
		p.show_hand(players);
		game.ask_player();
		game.turn();

	} while (d.d.size() != 0 || p.p1.size() != 0 || p.p2.size() != 0 || p.p3.size() != 0 || p.p4.size() != 0 || p.p5.size() != 0 || p.p6.size() != 0);

}//***************** end play_goFish **********************


//game rules
void go_fish::fish_rules()
{
	cout << "Welcome to Go Fish! :D" << endl;
	cout << endl;
	cout << "Here are some simple rules!" << endl;
	cout << "Match four (4) of the same rank to decrease the size of your hand!!" << endl;
	cout << "First person to run out of cards wins!!" << endl;
	cout << "If deck runs out first the game is a tie!!" << endl;
	cout << endl;
	cout << "Good luck! :D" << endl;
}


//create player and initial hands
int go_fish::init_players()
{
	cout << endl;
	cout << "How many players? (2-6): ";
	cin >> play_num;
	cout << endl;

	if (play_num == 2)
	{
		two_players();
	}
	else if (play_num == 3)
	{
		three_players();
	}
	else if (play_num == 4)
	{
		four_players();
	}
	else if (play_num == 5)
	{
		five_players();
	}
	else if (play_num == 6)
	{
		six_players();
	}
	return play_num;
}//***************** end init_players **********************


//Creates hands for two players
void go_fish::two_players()
{
	p.p1.resize(7);
	p.create_hand(1);
	p.rank_sort(1);
	p.p2.resize(7);
	p.create_hand(2);
	p.rank_sort(2);
}//***************** end two_players **********************


//Creates hands for three players
void go_fish::three_players()
{
	p.p1.resize(7);
	p.create_hand(1);
	p.rank_sort(1);
	p.p2.resize(7);
	p.create_hand(2);
	p.rank_sort(2);
	p.p3.resize(7);
	p.create_hand(3);
	p.rank_sort(3);
}//***************** end three_players **********************


//Creates hands for four players
void go_fish::four_players()
{
	p.p1.resize(7);
	p.create_hand(1);
	p.rank_sort(1);
	p.p2.resize(7);
	p.create_hand(2);
	p.rank_sort(2);
	p.p3.resize(7);
	p.create_hand(3);
	p.rank_sort(3);
	p.p4.resize(7);
	p.create_hand(4);
	p.rank_sort(4);
}//***************** end four_players **********************


//Creates hands for five players
void go_fish::five_players()
{
	p.p1.resize(7);
	p.create_hand(1);
	p.rank_sort(1);
	p.p2.resize(7);
	p.create_hand(2);
	p.rank_sort(2);
	p.p3.resize(7);
	p.create_hand(3);
	p.rank_sort(3);
	p.p4.resize(7);
	p.create_hand(4);
	p.rank_sort(4);
	p.p5.resize(7);
	p.create_hand(5);
	p.rank_sort(5);
}//***************** end five_players **********************


//Creates hands for six players
void go_fish::six_players()
{
	p.p1.resize(7);
	p.create_hand(1);
	p.rank_sort(1);
	p.p2.resize(7);
	p.create_hand(2);
	p.rank_sort(2);
	p.p3.resize(7);
	p.create_hand(3);
	p.rank_sort(3);
	p.p4.resize(7);
	p.create_hand(4);
	p.rank_sort(4);
	p.p5.resize(7);
	p.create_hand(5);
	p.rank_sort(5);
	p.p6.resize(7);
	p.create_hand(6);
	p.rank_sort(6);
}//***************** end six_players **********************


//ask player for rank
void go_fish::ask_player()
{
	go_fish g;

	cout << "Player " << turn_count << "'s turn" << endl;
	cout << "Don't take cards from yourself!! :P" << endl;
	cout << "Which player would you like to ask?: ";
	cin >> player_pick;
	while(player_pick > play_num){
		cout << "That player doesn't exist" << endl;
		cout << "Pick again: ";
		cin >> player_pick;
		cout << endl;
		p.show_hand(play_num);
	}
	cout << endl;
	cout << "Which card do you want?: ";
	cin >> card_rank;
	cout << endl;

	go_fish::check_player_hand(player_pick, turn_count, card_rank);
}//***************** end ask_player **********************


//player turn
void go_fish::turn()
{
	if (turn_count == 1)
	{
		turn_count = 2;
	}
	else if (turn_count == 2)
	{
		if (turn_count == play_num)
		{
			turn_count = 1;
		}
		else
		{
			turn_count = 3;
		}
	}
	else if (turn_count == 3)
	{
		if (turn_count == play_num)
		{
			turn_count = 1;
		}
		else
		{
			turn_count = 4;
		}
	}
	else if (turn_count == 4)
	{
		if (turn_count == play_num)
		{
			turn_count = 1;
		}
		else
		{
			turn_count = 5;
		}
	}
	else if (turn_count == 5)
	{
		if (turn_count == play_num)
		{
			turn_count = 1;
		}
		else
		{
			turn_count = 6;
		}
	}
	else if (turn_count == 6)
	{
		if (turn_count == play_num)
		{
			turn_count = 1;
		}
	}
}//***************** end turn **********************

//checks player hand for rank
void go_fish::check_player_hand(int play_pick, int play_turn, string rank)
{
	unsigned int count = 0, rank_count = 0;

	if(play_pick == 1)
	{
		cout << "checking for: " << rank << endl;
		cout << endl;
		for (unsigned int i = 0; i < p.p1.size(); i++)
		{
			if (rank == p.p1[i].rank)
			{
				if (play_turn == 2)
				{
					p.increase_hand(2, 1);
					p.p2[p.p2.size() - 1].rank = p.p1[i].rank;
					p.p2[p.p2.size() - 1].suit = p.p1[i].suit;
					if(rank == p.p1[i].rank){
						p.p1.erase(p.p1.begin()+i);
						rank_count ++;
					}
					i = 0;
					count = 0;
				}
				match_four(card_rank);
				if (play_turn == 3)
				{
					p.increase_hand(3, 1);
					p.p3[p.p3.size() - 1].rank = p.p1[i].rank;
					p.p3[p.p3.size() - 1].suit = p.p1[i].suit;
					if(rank == p.p1[i].rank){
						p.p1.erase(p.p1.begin()+i);
						rank_count++;
					}
					i = 0;
					count = 0;
				}
				match_four(card_rank);
				if (play_turn == 4)
				{
					p.increase_hand(4, 1);
					p.p4[p.p4.size() - 1].rank = p.p1[i].rank;
					p.p4[p.p4.size() - 1].suit = p.p1[i].suit;
					if(rank == p.p1[i].rank){
						p.p1.erase(p.p1.begin()+i);
						rank_count++;
					}
					i = 0;
					count = 0;
				}
				match_four(card_rank);
				if (play_turn == 5)
				{
					p.increase_hand(5, 1);
					p.p5[p.p5.size() - 1].rank = p.p1[i].rank;
					p.p5[p.p5.size() - 1].suit = p.p1[i].suit;
					if(rank == p.p1[i].rank){
						p.p1.erase(p.p1.begin()+i);
						rank_count++;
					}
					i = 0;
					count = 0;
				}
				match_four(card_rank);
				if (play_turn == 6)
				{
					p.increase_hand(6, 1);
					p.p6[p.p6.size() - 1].rank = p.p1[i].rank;
					p.p6[p.p6.size() - 1].suit = p.p1[i].suit;
					if(rank == p.p1[i].rank){
						p.p1.erase(p.p1.begin()+i);
						rank_count++;
					}
					i = 0;
					count = 0;
				}
				match_four(card_rank);
			}
			else
			{
				count++;
			}
		}
		if (count == p.p1.size())
		{
			go_fish::go_fish_draw(play_turn);
		}
	}
	else if (play_pick == 2)
	{
		cout << "checking for: " << rank << endl;
		cout << endl;
		for (unsigned int i = 0; i < p.p2.size(); i++)
		{
			if (rank == p.p2[i].rank)
			{
				if (play_turn == 1)
				{
					p.increase_hand(1, 1);
					p.p1[p.p1.size() - 1].rank = p.p2[i].rank;
					p.p1[p.p1.size() - 1].suit = p.p2[i].suit;
					if(rank == p.p2[i].rank){
						p.p2.erase(p.p2.begin()+i);
						rank_count++;
					}
					i = 0;
					count = 0;
				}
				match_four(card_rank);
				if (play_turn == 3)
				{
					p.increase_hand(3, 1);
					p.p3[p.p3.size() - 1].rank = p.p2[i].rank;
					p.p3[p.p3.size() - 1].suit = p.p2[i].suit;
					if(rank == p.p2[i].rank){
						p.p2.erase(p.p2.begin()+i);
						rank_count ++;
					}
					i = 0;
					count = 0;
				}
				match_four(card_rank);
                if (play_turn == 4)
				{
					p.increase_hand(4, 1);
					p.p4[p.p4.size() - 1].rank = p.p2[i].rank;
					p.p4[p.p4.size() - 1].suit = p.p2[i].suit;
					if(rank == p.p2[i].rank){
						p.p2.erase(p.p2.begin()+i);
						rank_count++;
					}
					i = 0;
					count = 0;
				}
				match_four(card_rank);
                if (play_turn == 5)
				{
					p.increase_hand(5, 1);
					p.p5[p.p5.size() - 1].rank = p.p2[i].rank;
					p.p5[p.p5.size() - 1].suit = p.p2[i].suit;
					if(rank == p.p2[i].rank){
						p.p2.erase(p.p2.begin()+i);
						rank_count++;
					}
					i = 0;
					count = 0;
				}
				match_four(card_rank);
                if (play_turn == 6)
				{
					p.increase_hand(6, 1);
					p.p6[p.p6.size() - 1].rank = p.p2[i].rank;
					p.p6[p.p6.size() - 1].suit = p.p2[i].suit;
					if(rank == p.p2[i].rank){
						p.p2.erase(p.p2.begin()+i);
						rank_count++;
					}
					i = 0;
					count = 0;
				}
				match_four(card_rank);
			}
			else
			{
				count++;
			}
		}
		if (count == p.p2.size())
		{
			go_fish::go_fish_draw(play_turn);
		}
	}
	else if(play_pick == 3)
	{
		cout << "checking for: " << rank << endl;
		for (unsigned int i = 0; i < p.p3.size(); i++)
		{
			if (rank == p.p3[i].rank)
			{
				if (play_turn == 1)
				{
					p.increase_hand(1, 1);
					p.p1[p.p1.size() - 1].rank = p.p3[i].rank;
					p.p1[p.p1.size() - 1].suit = p.p3[i].suit;
					if(rank == p.p3[i].rank){
						p.p3.erase(p.p3.begin()+i);
						rank_count ++;
					}
					i = 0;
					count = 0;
				}
				match_four(card_rank);
                if (play_turn == 2)
				{
					p.increase_hand(2, 1);
					p.p2[p.p2.size() - 1].rank = p.p3[i].rank;
					p.p2[p.p2.size() - 1].suit = p.p3[i].suit;
					if(rank == p.p3[i].rank){
						p.p3.erase(p.p3.begin()+i);
						rank_count ++;
					}
					i = 0;
					count = 0;
				}
				match_four(card_rank);
                if (play_turn == 4)
				{
					p.increase_hand(4, 1);
					p.p4[p.p4.size() - 1].rank = p.p3[i].rank;
					p.p4[p.p4.size() - 1].suit = p.p3[i].suit;
					if(rank == p.p3[i].rank){
						p.p3.erase(p.p3.begin()+i);
						rank_count ++;
					}
					i = 0;
					count = 0;
				}
				match_four(card_rank);
                if (play_turn == 5)
				{
					p.increase_hand(5, 1);
					p.p5[p.p5.size() - 1].rank = p.p3[i].rank;
					p.p5[p.p5.size() - 1].suit = p.p3[i].suit;
					if(rank == p.p3[i].rank){
						p.p3.erase(p.p3.begin()+i);
						rank_count ++;
					}
					i = 0;
					count = 0;
				}
				match_four(card_rank);
                if (play_turn == 6)
				{
					p.increase_hand(6, 1);
					p.p6[p.p6.size() - 1].rank = p.p3[i].rank;
					p.p6[p.p6.size() - 1].suit = p.p3[i].suit;
					if(rank == p.p3[i].rank){
						p.p3.erase(p.p3.begin()+i);
						rank_count ++;
					}
					i = 0;
					count = 0;
				}
				match_four(card_rank);
			}
			else
			{
				count++;
			}
		}
		if (count == p.p3.size())
		{
			go_fish::go_fish_draw(play_turn);
		}
	}
	else if(play_pick == 4)
	{
		cout << "checking for: " << rank << endl;
		for (unsigned int i = 0; i < p.p4.size(); i++)
		{
			if (rank == p.p4[i].rank)
			{
				if (play_turn == 1)
				{
					p.increase_hand(1, 1);
					p.p1[p.p1.size() - 1].rank = p.p4[i].rank;
					p.p1[p.p1.size() - 1].suit = p.p4[i].suit;
					if(rank == p.p4[i].rank){
						p.p4.erase(p.p4.begin()+i);
						rank_count ++;
					}
					i = 0;
					count = 0;
				}
				match_four(card_rank);
                if (play_turn == 2)
				{
					p.increase_hand(2, 1);
					p.p2[p.p2.size() - 1].rank = p.p4[i].rank;
					p.p2[p.p2.size() - 1].suit = p.p4[i].suit;
					if(rank == p.p4[i].rank){
						p.p4.erase(p.p4.begin()+i);
						rank_count ++;
					}
					i = 0;
					count = 0;
				}
				match_four(card_rank);
                if (play_turn == 3)
				{
					p.increase_hand(3, 1);
					p.p3[p.p3.size() - 1].rank = p.p4[i].rank;
					p.p3[p.p3.size() - 1].suit = p.p4[i].suit;
					if(rank == p.p4[i].rank){
						p.p4.erase(p.p4.begin()+i);
						rank_count ++;
					}
					i = 0;
					count = 0;
				}
				match_four(card_rank);
                if (play_turn == 5)
				{
					p.increase_hand(4, 1);
					p.p5[p.p5.size() - 1].rank = p.p4[i].rank;
					p.p5[p.p5.size() - 1].suit = p.p4[i].suit;
					if(rank == p.p4[i].rank){
						p.p4.erase(p.p4.begin()+i);
						rank_count ++;
					}
					i = 0;
					count = 0;
				}
				match_four(card_rank);
                if (play_turn == 6)
				{
					p.increase_hand(6, 1);
					p.p6[p.p6.size() - 1].rank = p.p4[i].rank;
					p.p6[p.p6.size() - 1].suit = p.p4[i].suit;
					if(rank == p.p4[i].rank){
						p.p4.erase(p.p4.begin()+i);
						rank_count ++;
					}
					i = 0;
					count = 0;
				}
				match_four(card_rank);
			}
			else
			{
				count++;
			}
		}
		if (count == p.p4.size())
		{
			go_fish::go_fish_draw(play_turn);
		}
	}
	else if(play_pick == 5)
	{
		cout << "checking for: " << rank << endl;
		for (unsigned int i = 0; i < p.p5.size(); i++)
		{
			if (rank == p.p5[i].rank)
			{
				if (play_turn == 1)
				{
					p.increase_hand(1, 1);
					p.p1[p.p1.size() - 1].rank = p.p5[i].rank;
					p.p1[p.p1.size() - 1].suit = p.p5[i].suit;
					if(rank == p.p5[i].rank){
						p.p5.erase(p.p5.begin()+i);
						rank_count ++;
					}
					i = 0;
					count = 0;
				}
				match_four(card_rank);
                if (play_turn == 2)
				{
					p.increase_hand(2, 1);
					p.p2[p.p2.size() - 1].rank = p.p5[i].rank;
					p.p2[p.p2.size() - 1].suit = p.p5[i].suit;
					if(rank == p.p5[i].rank){
						p.p5.erase(p.p5.begin()+i);
						rank_count ++;
					}
					i = 0;
					count = 0;
				}
				match_four(card_rank);
                if (play_turn == 3)
				{
					p.increase_hand(3, 1);
					p.p3[p.p3.size() - 1].rank = p.p5[i].rank;
					p.p3[p.p3.size() - 1].suit = p.p5[i].suit;
					if(rank == p.p5[i].rank){
						p.p5.erase(p.p5.begin()+i);
						rank_count ++;
					}
					i = 0;
					count = 0;
				}
				match_four(card_rank);
                if (play_turn == 4)
				{
					p.increase_hand(4, 1);
					p.p4[p.p4.size() - 1].rank = p.p5[i].rank;
					p.p4[p.p4.size() - 1].suit = p.p5[i].suit;
					if(rank == p.p5[i].rank){
						p.p5.erase(p.p5.begin()+i);
						rank_count ++;
					}
					i = 0;
					count = 0;
				}
				match_four(card_rank);
                if (play_turn == 6)
				{
					p.increase_hand(6, 1);
					p.p6[p.p6.size() - 1].rank = p.p5[i].rank;
					p.p6[p.p6.size() - 1].suit = p.p5[i].suit;
					if(rank == p.p5[i].rank){
						p.p5.erase(p.p5.begin()+i);
						rank_count ++;
					}
					i = 0;
					count = 0;
				}
				match_four(card_rank);
			}
			else
			{
				count++;
			}
		}
		if (count == p.p5.size())
		{
			go_fish::go_fish_draw(play_turn);
		}
	}
	else if(play_pick == 6)
	{
		cout << "checking for: " << rank << endl;
		for (unsigned int i = 0; i < p.p6.size(); i++)
		{
			if (rank == p.p6[i].rank)
			{
				if (play_turn == 1)
				{
					p.increase_hand(1, 1);
					p.p1[p.p1.size() - 1].rank = p.p6[i].rank;
					p.p1[p.p1.size() - 1].suit = p.p6[i].suit;
					if(rank == p.p6[i].rank){
						p.p6.erase(p.p6.begin()+i);
						rank_count ++;
					}
					i = 0;
					count = 0;
				}
				match_four(card_rank);
                if (play_turn == 2)
				{
					p.increase_hand(2, 1);
					p.p2[p.p2.size() - 1].rank = p.p6[i].rank;
					p.p2[p.p2.size() - 1].suit = p.p6[i].suit;
					if(rank == p.p6[i].rank){
						p.p6.erase(p.p6.begin()+i);
						rank_count ++;
					}
					i = 0;
					count = 0;
				}
				match_four(card_rank);
                if (play_turn == 3)
				{
					p.increase_hand(3, 1);
					p.p3[p.p3.size() - 1].rank = p.p6[i].rank;
					p.p3[p.p3.size() - 1].suit = p.p6[i].suit;
					if(rank == p.p6[i].rank){
						p.p6.erase(p.p6.begin()+i);
						rank_count ++;
					}
					i = 0;
					count = 0;
				}
				match_four(card_rank);
                if (play_turn == 4)
				{
					p.increase_hand(4, 1);
					p.p4[p.p4.size() - 1].rank = p.p6[i].rank;
					p.p4[p.p4.size() - 1].suit = p.p6[i].suit;
					if(rank == p.p6[i].rank){
						p.p6.erase(p.p6.begin()+i);
						rank_count ++;
					}
					i = 0;
					count = 0;
				}
				match_four(card_rank);
                if (play_turn == 5)
				{
					p.increase_hand(5, 1);
					p.p5[p.p5.size() - 1].rank = p.p6[i].rank;
					p.p5[p.p5.size() - 1].suit = p.p6[i].suit;
					if(rank == p.p6[i].rank){
						p.p6.erase(p.p6.begin()+i);
						rank_count ++;
					}
					i = 0;
					count = 0;
				}
				match_four(card_rank);
			}
			else
			{
				count++;
			}
		}
		if (count == p.p6.size())
		{
			go_fish::go_fish_draw(play_turn);
		}
	}

	p.rank_sort(play_turn);
}//***************** end check_player_hand **********************

/*
//if cards taken, draw new
void go_fish::draw_taken_cards()
{
	if (turn == 1)
	{
		single[0] = hand[0].deck::draw_card(single);
		p.p1[p.p1.size() - 1].rank = single[0].rank;
		p.p1[p.p1.size() - 1].suit = single[0].suit;
	}
	if (turn == 1)
	{
		single[0] = hand[0].deck::draw_card(single);
		p.p1[p.p1.size() - 1].rank = single[0].rank;
		p.p1[p.p1.size() - 1].suit = single[0].suit;
	}
	if (turn == 1)
	{
		single[0] = hand[0].deck::draw_card(single);
		p.p1[p.p1.size() - 1].rank = single[0].rank;
		p.p1[p.p1.size() - 1].suit = single[0].suit;
	}
	if (turn == 1)
	{
		single[0] = hand[0].deck::draw_card(single);
		p.p1[p.p1.size() - 1].rank = single[0].rank;
		p.p1[p.p1.size() - 1].suit = single[0].suit;
	}
	if (turn == 1)
	{
		single[0] = hand[0].deck::draw_card(single);
		p.p1[p.p1.size() - 1].rank = single[0].rank;
		p.p1[p.p1.size() - 1].suit = single[0].suit;
	}
	if (turn == 1)
	{
		single[0] = hand[0].deck::draw_card(single);
		p.p1[p.p1.size() - 1].rank = single[0].rank;
		p.p1[p.p1.size() - 1].suit = single[0].suit;
	}
}//***************** end draw_taken_cards **********************
*/

//draw if player doesn't have rank card
void go_fish::go_fish_draw(int turn)
{
	cout << "GO FISH!" << endl;
	card *single = new card[1];
	deck *hand = new deck[1];

	if(turn == 1)
	{
		p.increase_hand(1, 1);
		single[0] = hand[0].deck::draw_card(single);
		p.p1[p.p1.size()-1].rank = single[0].rank;
		p.p1[p.p1.size()-1].suit = single[0].suit;
		cout << "You draw: " << single[0].rank << single[0].suit << endl;
		match_four(single[0].rank);
	}
	else if(turn == 2)
	{
		p.increase_hand(2, 1);
		single[0] = hand[0].deck::draw_card(single);
		p.p2[p.p2.size()-1].rank = single[0].rank;
		p.p2[p.p2.size()-1].suit = single[0].suit;
		cout << "You draw: " << single[0].rank << single[0].suit << endl;
		match_four(single[0].rank);
	}
	else if(turn == 3)
	{
		p.increase_hand(3, 1);
		single[0] = hand[0].deck::draw_card(single);
		p.p3[p.p3.size()-1].rank = single[0].rank;
		p.p3[p.p3.size()-1].suit = single[0].suit;
		cout << "You draw: " << single[0].rank << single[0].suit << endl;
		match_four(single[0].rank);
	}
	else if(turn == 4)
	{
		p.increase_hand(4, 1);
		single[0] = hand[0].deck::draw_card(single);
		p.p4[p.p4.size()-1].rank = single[0].rank;
		p.p4[p.p4.size()-1].suit = single[0].suit;
		cout << "You draw: " << single[0].rank << single[0].suit << endl;
		match_four(single[0].rank);
	}
	else if(turn == 5)
	{
		p.increase_hand(5, 1);
		single[0] = hand[0].deck::draw_card(single);
		p.p5[p.p5.size()-1].rank = single[0].rank;
		p.p5[p.p5.size()-1].suit = single[0].suit;
		cout << "You draw: " << single[0].rank << single[0].suit << endl;
		match_four(single[0].rank);
	}
	else if(turn == 6)
	{
		p.increase_hand(6, 1);
		single[0] = hand[0].deck::draw_card(single);
		p.p6[p.p6.size()-1].rank = single[0].rank;
		p.p6[p.p6.size()-1].suit = single[0].suit;
		cout << "You draw: " << single[0].rank << single[0].suit << endl;
		match_four(single[0].rank);
	}

	delete[] hand;
	delete[] single;
}//***************** end go_fish_draw **********************


//check to match four same ranked cards
void go_fish::match_four(string rank)
{
	int match = 0, counter = 0;
	card *holder = new card[4];

    //for player 1
    if(turn_count == 1)
    {
        for (unsigned int i = 0; i < p.p1.size(); i++)
        {
            if (rank == p.p1[i].rank)
            {
                holder[counter].rank = p.p1[i].rank;
                counter ++;
                if(counter == 4)
                {
                    match = 1;
                    break;
                }
            }
        }
    }
    else if(turn_count == 2)
    {
        for (unsigned int i = 0; i < p.p2.size(); i++)
        {
            if (rank == p.p2[i].rank)
            {
                holder[counter].rank = p.p2[i].rank;
                counter ++;
                if(counter == 4)
                {
                    match = 1;
                    break;
                }
            }
        }
    }
    if(turn_count == 3)
    {
        for (unsigned int i = 0; i < p.p3.size(); i++)
        {
            if (rank == p.p3[i].rank)
            {
                holder[counter].rank = p.p3[i].rank;
                counter ++;
                if(counter == 4)
                {
                    match = 1;
                    break;
                }
            }
        }
    }
    if(turn_count == 4)
    {
        for (unsigned int i = 0; i < p.p4.size(); i++)
        {
            if (rank == p.p4[i].rank)
            {
                holder[counter].rank = p.p4[i].rank;
                counter ++;
                if(counter == 4)
                {
                    match = 1;
                    break;
                }
            }
        }
    }
    if(turn_count == 5)
    {
        for (unsigned int i = 0; i < p.p5.size(); i++)
        {
            if (rank == p.p5[i].rank)
            {
                holder[counter].rank = p.p5[i].rank;
                counter ++;
                if(counter == 4)
                {
                    match = 1;
                    break;
                }
            }
        }
    }
    if(turn_count == 6)
    {
        for (unsigned int i = 0; i < p.p6.size(); i++)
        {
            if (rank == p.p6[i].rank)
            {
                holder[counter].rank = p.p6[i].rank;
                counter ++;
                if(counter == 4)
                {
                    match = 1;
                    break;
                }
            }
        }
    }

	if(match == 1)
	{
		go_fish::discard_four(rank);
	}

	delete[] holder;
}//***************** end match_four **********************


//discard matched ranked cards
void go_fish::discard_four(string rank)
{
	cout << "You have a match!!" << endl;
	//for player 1
	if(turn_count == 1)
    {
        for (unsigned int i = 0; i < p.p1.size(); i++)
        {
            if(rank == p.p1[i].rank)
            {
                p.p1.erase(p.p1.begin()+i);
                i = 0;
            }
        }
    }
    if(turn_count == 2)
    {
        for (unsigned int i = 0; i < p.p2.size(); i++)
        {
            if(rank == p.p2[i].rank)
            {
                p.p2.erase(p.p2.begin()+i);
                i = 0;
            }
        }
    }
    if(turn_count == 3)
    {
        for (unsigned int i = 0; i < p.p3.size(); i++)
        {
            if(rank == p.p3[i].rank)
            {
                p.p3.erase(p.p3.begin()+i);
                i = 0;
            }
        }
    }
    if(turn_count == 4)
    {
        for (unsigned int i = 0; i < p.p4.size(); i++)
        {
            if(rank == p.p4[i].rank)
            {
                p.p4.erase(p.p4.begin()+i);
                i = 0;
            }
        }
    }
    if(turn_count == 5)
    {
        for (unsigned int i = 0; i < p.p5.size(); i++)
        {
            if(rank == p.p5[i].rank)
            {
                p.p5.erase(p.p5.begin()+i);
                i = 0;
            }
        }
    }
    if(turn_count == 6)
    {
        for (unsigned int i = 0; i < p.p6.size(); i++)
        {
            if(rank == p.p6[i].rank)
            {
                p.p6.erase(p.p6.begin()+i);
                i = 0;
            }
        }
    }

}//***************** end discard_four **********************


//checks for empty hand
void go_fish::empty_hand()
{
	if (p.p1.size() == 0 && play_num >= 2)
	{
		cout << endl;
		cout << "Player 1 wins!!";
		cout << endl;
	}
	else if (p.p2.size() == 0 && play_num >= 2)
	{
		cout << endl;
		cout << "Player 2 wins!!";
		cout << endl;
	}
	else if (p.p3.size() == 0 && play_num >= 3)
	{
		cout << endl;
		cout << "Player 3 wins!!";
		cout << endl;
	}
	else if (p.p4.size() == 0 && play_num >= 4)
	{
		cout << endl;
		cout << "Player 4 wins!!";
		cout << endl;
	}
	else if (p.p5.size() == 0 && play_num >= 5)
	{
		cout << endl;
		cout << "Player 5 wins!!";
		cout << endl;
	}
	else if (p.p6.size() == 0 && play_num >= 6)
	{
		cout << endl;
		cout << "Player 6 wins!!";
		cout << endl;
	}
}
//***************** end empty_hand **********************


//check to see if deck is empty (call for tie)
void go_fish::empty_deck()
{
	if (deck::d.size() == 0)
	{
		cout << "Game is tied!" << endl;
	}
}
//***************** end empty_deck **********************




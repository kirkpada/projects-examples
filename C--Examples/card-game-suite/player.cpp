/******************************************************
**Program: player.cpp
**Author: Daniel Kirkpatrick
**Date:
**Description: Contains implementation for player info
**Input:
**Output:
******************************************************/

#include "player.h"

//
player::player()
{

}

//create hand and input cards into vectors
void player::create_hand(int p_num)
{
	deck *temp_card = new deck[1];
	card *temp = new card[7];

	if(p_num == 1)
	{
		for (unsigned int i = 0; i < p1.size(); i++)
		{
			temp[i] = temp_card[0].deck::draw_card(temp);
			p1[i].rank = temp[i].rank;
			p1[i].suit = temp[i].suit;
		}
	}
	else if(p_num == 2)
	{
		for (unsigned int i = 0; i < p2.size(); i++)
		{
			temp[i] = temp_card[0].deck::draw_card(temp);
			p2[i].rank = temp[i].rank;
			p2[i].suit = temp[i].suit;
		}
	}
	else if (p_num == 3)
	{
		for (unsigned int i = 0; i < p3.size(); i++)
		{
			temp[i] = temp_card[0].deck::draw_card(temp);
			p3[i].rank = temp[i].rank;
			p3[i].suit = temp[i].suit;
		}
	}
	else if (p_num == 4)
	{
		for (unsigned int i = 0; i < p4.size(); i++)
		{
			temp[i] = temp_card[0].deck::draw_card(temp);
			p4[i].rank = temp[i].rank;
			p4[i].suit = temp[i].suit;
		}
	}
	else if (p_num == 5)
	{
		for (unsigned int i = 0; i < p5.size(); i++)
		{
			temp[i] = temp_card[0].deck::draw_card(temp);
			p5[i].rank = temp[i].rank;
			p5[i].suit = temp[i].suit;
		}
	}
	else if (p_num == 6)
	{
		for (unsigned int i = 0; i < p6.size(); i++)
		{
			temp[i] = temp_card[0].deck::draw_card(temp);
			p6[i].rank = temp[i].rank;
			p6[i].suit = temp[i].suit;
		}
	}

	delete[] temp;
	delete[] temp_card;

}
//***************** end create_hand **********************


//increase size of player hand
void player::increase_hand(int player, int increase)
{
	if(player == 1)
	{
		int bigger = p1.size() + increase;
		//bigger = bigger + increase;
		p1.resize(bigger);
	}
	else if(player == 2)
	{
		int bigger = p2.size() + increase;
		//bigger = bigger + increase;
		p2.resize(bigger);
	}
	else if(player == 3)
	{
		int bigger = p3.size();
		bigger = bigger + increase;
		p3.resize(bigger);
	}
	else if(player == 4)
	{
		int bigger = p4.size();
		bigger = bigger + increase;
		p4.resize(bigger);
	}
	else if(player == 5)
	{
		int bigger = p5.size();
		bigger = bigger + increase;
		p5.resize(bigger);
	}
	else if(player == 6)
	{
		int bigger = p6.size();
		bigger = bigger + increase;
		p6.resize(bigger);
	}
}
//***************** end increase_hand **********************


//decrease size of player hand
void player::decrease_hand(int player, int dec)
{
	if(player == 1)
	{
		int smaller = p1.size();
		smaller = smaller + dec;
		p1.resize(smaller);
	}
	else if(player == 2)
	{
		int smaller = p2.size();
		smaller = smaller + dec;
		p2.resize(smaller);
	}
	else if(player == 3)
	{
		int smaller = p3.size();
		smaller = smaller + dec;
		p3.resize(smaller);
	}
	else if(player == 4)
	{
		int smaller = p4.size();
		smaller = smaller + dec;
		p4.resize(smaller);
	}
	else if(player == 5)
	{
		int smaller = p5.size();
		smaller = smaller + dec;
		p5.resize(smaller);
	}
	else if(player == 6)
	{
		int smaller = p6.size();
		smaller = smaller - dec;
		p6.resize(smaller);
	}
}
//***************** end decrease_hand **********************


//shows the current hand
void player::show_hand(int play_num)
{
	if (play_num == 1)
	{
		cout << "player 1 hand: ";
		for (unsigned int i = 0; i < p1.size(); i++)
		{
			cout << p1[i].rank << p1[i].suit << " ";
		}
		cout << endl;
		cout << endl;
	}
	else if (play_num == 2)
	{
		cout << "player 1 hand: ";
		for (unsigned int i = 0; i < p1.size(); i++)
		{
			cout << p1[i].rank << p1[i].suit << " ";
		}
		cout << endl;
		cout << endl;
		cout << "player 2 hand: ";
		for (unsigned int i = 0; i < p2.size(); i++)
		{
			cout << p2[i].rank << p2[i].suit << " ";
		}
		cout << endl;
		cout << endl;
	}
	else if (play_num == 3)
	{
		cout << "player 1 hand: ";
		for (unsigned int i = 0; i < p1.size(); i++)
		{
			cout << p1[i].rank << p1[i].suit << " ";
		}
		cout << endl;
		cout << endl;
		cout << "player 2 hand: ";
		for (unsigned int i = 0; i < p2.size(); i++)
		{
			cout << p2[i].rank << p2[i].suit << " ";
		}
		cout << endl;
		cout << endl;
		cout << "player 3 hand: ";
		for (unsigned int i = 0; i < p3.size(); i++)
		{
			cout << p3[i].rank << p3[i].suit << " ";
		}
		cout << endl;
		cout << endl;
	}
	else if (play_num == 4)
	{
		cout << "player 1 hand: ";
		for (unsigned int i = 0; i < p1.size(); i++)
		{
			cout << p1[i].rank << p1[i].suit << " ";
		}
		cout << endl;
		cout << endl;
		cout << "player 2 hand: ";
		for (unsigned int i = 0; i < p2.size(); i++)
		{
			cout << p2[i].rank << p2[i].suit << " ";
		}
		cout << endl;
		cout << endl;
		cout << "player 3 hand: ";
		for (unsigned int i = 0; i < p3.size(); i++)
		{
			cout << p3[i].rank << p3[i].suit << " ";
		}
		cout << endl;
		cout << endl;
		cout << "player 4 hand: ";
		for (unsigned int i = 0; i < p4.size(); i++)
		{
			cout << p4[i].rank << p4[i].suit << " ";
		}
		cout << endl;
		cout << endl;
	}
	else if (play_num == 5)
	{
		cout << "player 1 hand: ";
		for (unsigned int i = 0; i < p1.size(); i++)
		{
			cout << p1[i].rank << p1[i].suit << " ";
		}
		cout << endl;
		cout << endl;
		cout << "player 2 hand: ";
		for (unsigned int i = 0; i < p2.size(); i++)
		{
			cout << p2[i].rank << p2[i].suit << " ";
		}
		cout << endl;
		cout << endl;
		cout << "player 3 hand: ";
		for (unsigned int i = 0; i < p3.size(); i++)
		{
			cout << p3[i].rank << p3[i].suit << " ";
		}
		cout << endl;
		cout << endl;
		cout << "player 4 hand: ";
		for (unsigned int i = 0; i < p4.size(); i++)
		{
			cout << p4[i].rank << p4[i].suit << " ";
		}
		cout << endl;
		cout << endl;
		cout << "player 5 hand: ";
		for (unsigned int i = 0; i < p5.size(); i++)
		{
			cout << p5[i].rank << p5[i].suit << " ";
		}
		cout << endl;
		cout << endl;
	}
	else if (play_num == 6)
	{
		cout << "player 1 hand: ";
		for (unsigned int i = 0; i < p1.size(); i++)
		{
			cout << p1[i].rank << p1[i].suit << " ";
		}
		cout << endl;
		cout << endl;
		cout << "player 2 hand: ";
		for (unsigned int i = 0; i < p2.size(); i++)
		{
			cout << p2[i].rank << p2[i].suit << " ";
		}
		cout << endl;
		cout << endl;
		cout << "player 3 hand: ";
		for (unsigned int i = 0; i < p3.size(); i++)
		{
			cout << p3[i].rank << p3[i].suit << " ";
		}
		cout << endl;
		cout << endl;
		cout << "player 4 hand: ";
		for (unsigned int i = 0; i < p4.size(); i++)
		{
			cout << p4[i].rank << p4[i].suit << " ";
		}
		cout << endl;
		cout << endl;
		cout << "player 5 hand: ";
		for (unsigned int i = 0; i < p5.size(); i++)
		{
			cout << p5[i].rank << p5[i].suit << " ";
		}
		cout << endl;
		cout << endl;
		cout << "player 6 hand: ";
		for (unsigned int i = 0; i < p6.size(); i++)
		{
			cout << p6[i].rank << p6[i].suit << " ";
		}
		cout << endl;
		cout << endl;
	}
}
//***************** end show_hand **********************


//get player hand
card player::get_hand(int play_num)
{
	if (play_num == 1)
	{
		for (unsigned int i = 0; i < p1.size(); i++)
		{
			return p1[i];
		}
	}
	else if (play_num == 2)
	{
		for (unsigned int i = 0; i < p2.size(); i++)
		{
			return p2[i];
		}
	}
	else if (play_num == 3)
	{
		for (unsigned int i = 0; i < p3.size(); i++)
		{
			return p3[i];
		}
	}
	else if (play_num == 4)
	{
		for (unsigned int i = 0; i < p4.size(); i++)
		{
			return p4[i];
		}
	}
	else if (play_num == 5)
	{
		for (unsigned int i = 0; i < p5.size(); i++)
		{
			return  p5[i];
		}
	}
	else if (play_num == 6)
	{
		for (unsigned int i = 0; i < p6.size(); i++)
		{
			return p6[i];
		}
	}
}
//***************** end get_card **********************


void player::rank_sort(int play_num)
{
	card *temp = new card[1];

	if (play_num == 1)
	{
		for (unsigned int i = 0; i < p1.size() - 1; i++)
		{
			for(unsigned int x = 0; x < p1.size()-1; x++){
				if (p1[x].rank > p1[x + 1].rank)
				{
					temp[0].rank = p1[x].rank;
					temp[0].suit = p1[x].suit;
					p1[x].rank = p1[x+1].rank;
					p1[x].suit = p1[x+1].suit;
					p1[x+1].rank = temp[0].rank;
					p1[x+1].suit = temp[0].suit;
				}
			}
		}
	}
	if (play_num == 2)
	{
		for (unsigned int i = 0; i < p2.size() - 1; i++)
		{
			for(unsigned int x = 0; x < p2.size()-1; x++){
				if (p2[x].rank > p2[x + 1].rank)
				{
					temp[0].rank = p2[x].rank;
					temp[0].suit = p2[x].suit;
					p2[x].rank = p2[x+1].rank;
					p2[x].suit = p2[x+1].suit;
					p2[x+1].rank = temp[0].rank;
					p2[x+1].suit = temp[0].suit;
				}
			}
		}
	}
	if (play_num == 3)
	{
		for (unsigned int i = 0; i < p3.size() - 1; i++)
		{
			for(unsigned int x = 0; x < p3.size()-1; x++){
				if (p3[x].rank > p3[x + 1].rank)
				{
					temp[0].rank = p3[x].rank;
					temp[0].suit = p3[x].suit;
					p3[x].rank = p3[x + 1].rank;
					p3[x].suit = p3[x + 1].suit;
					p3[x + 1].rank = temp[0].rank;
					p3[x + 1].suit = temp[0].suit;
				}
			}
		}
	}
	if (play_num == 4)
	{
		for (unsigned int i = 0; i < p4.size() - 1; i++)
		{
			for(unsigned int x = 0; x < p4.size()-1; x++){
				if (p4[x].rank > p4[x + 1].rank)
				{
					temp[0].rank = p4[x].rank;
					temp[0].suit = p4[x].suit;
					p4[x].rank = p4[x + 1].rank;
					p4[x].suit = p4[x + 1].suit;
					p4[x + 1].rank = temp[0].rank;
					p4[x + 1].suit = temp[0].suit;
				}
			}
		}
	}
	if (play_num == 5)
	{
		for (unsigned int i = 0; i < p5.size() - 1; i++)
		{
			for(unsigned int x = 0; x < p5.size()-1; x++){
				if (p5[x].rank > p5[x + 1].rank)
				{
					temp[0].rank = p5[x].rank;
					temp[0].suit = p5[x].suit;
					p5[x].rank = p5[x + 1].rank;
					p5[x].suit = p5[x + 1].suit;
					p5[x + 1].rank = temp[0].rank;
					p5[x + 1].suit = temp[0].suit;
				}
			}
		}
	}
	if (play_num == 6)
	{
		for (unsigned int i = 0; i < p6.size() - 1; i++)
		{
			for(unsigned int x = 0; x < p6.size()-1; x++){
				if (p6[x].rank > p6[x + 1].rank)
				{
					temp[0].rank = p6[x].rank;
					temp[0].suit = p6[x].suit;
					p6[x].rank = p6[x + 1].rank;
					p6[x].suit = p6[x + 1].suit;
					p6[x + 1].rank = temp[0].rank;
					p6[x + 1].suit = temp[0].suit;
				}
			}
		}
	}
}

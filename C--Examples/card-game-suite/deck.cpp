/******************************************************
**Program: deck.cpp
**Author: Daniel Kirkpatrick
**Date:
**Description: Contains implementation for creating a deck
**Input:
**Output:
******************************************************/

#include "deck.h"

//randomly generate card suit
string deck::suit(int s){
	string suit;

	if(s == 0){
		suit = "C";
	}
	else if(s == 1){
		suit = "S";
	}
	else if(s == 2){
		suit = "H";
	}
	else if(s == 3){
		suit = "D";
	}

	return suit;

}
//***************** end suit **********************


//randomly generate card rank
string deck::rank(int r){
	string rank;

	if (r == 0){
		rank = "A";
	}
	else if (r == 1){
		rank = "2";
	}
	else if (r == 2){
		rank = "3";
	}
	else if (r == 3){
		rank = "4";
	}
	else if (r == 4){
		rank = "5";
	}
	else if (r == 5){
		rank = "6";
	}
	else if (r == 6){
		rank = "7";
	}
	else if (r == 7){
		rank = "8";
	}
	else if (r == 8){
		rank = "9";
	}
	else if (r == 9){
		rank = "10";
	}
	else if (r == 10){
		rank = "J";
	}
	else if (r == 11){
		rank = "Q";
	}
	else if (r == 12){
		rank = "K";
	}		

	return rank;

}
//***************** end rank **********************


//create a single card
card deck::create_card(int r, int s){
	card *c = new card[1];

	c->rank = deck::rank(r);
	c->suit = deck::suit(s);

	return *c;

}
//***************** end create_card **********************


//fill deck with created cards
void deck::fill_deck(){
	d.resize(52);
	int j = 0;
	int s_count = 0,  r_count = 0;

	for (unsigned int i = 0; i < d.size(); i++)
	{
		//create single card at a time
		d.at(i) = deck::create_card(r_count, s_count);

		//counts up to 13 cards for each suit
		if (r_count == 12)
		{
			r_count = 0;
		}
		else
		{
			r_count++;
		}

		//changes suit after 13 cards are counted
		if (i == 12 || i == 25 || i == 38)
		{
			s_count++;
		}
		j++;
	}

	deck::shuffle_deck();
}
//***************** end fill_deck **********************


//shuffles deck after it is filled
void deck::shuffle_deck(){
	int shuffle1, shuffle2, count = 0;
	string temp;

	for (unsigned int i = 0; i < d.size(); i++)
	{
		shuffle1 = rand() % 52;
		shuffle2 = rand() % 52;
		
		swap(d[shuffle1], d[shuffle2]);

		count++;
	}
}
//***************** end shuffle_deck **********************


//draw a card off the top of the deck
card deck::draw_card(card *c)
{
	int deck_end = 0;

	deck_end = d.size()-1;

	*c = deck::get_card(deck_end);
	deck_end = d.size();
	deck::deck_size(1);

	return *c;
}
//***************** end draw_card **********************


//decreases the size of deck after a card is drawn
void deck::deck_size(int d_resize){
	int decrease = 0;

	decrease = d.size()-d_resize;

	//decrease the size of the vector
	d.resize(decrease);
}
//***************** end deck_size **********************


card deck::get_card(int card_index)
{
	card *single = new card[1];

	single->rank = d[card_index].rank;
	single->suit = d[card_index].suit;
	
	return *single;
}
//***************** end get_card **********************

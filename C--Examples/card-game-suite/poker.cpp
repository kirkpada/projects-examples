/******************************************************
**Program: poker.cpp
**Author: Daniel Kirkpatrick
**Date:
**Description: Contains implementation for poker game
**Input:
**Output:
******************************************************/

#include "poker.h"

//poker default constructor
poker::poker()
{
	turn_count = 1;
	play_num = 0;
	pick_card = 0;
	players = 0;
	hands = 0;
	game_counter = 0;
	p1_points = 0;
	p2_points = 0;
	p3_points = 0;
	p4_points = 0;
	p5_points = 0;
	p6_points = 0;
	string card_rank = " ";
}//***************** end poker **********************


//Plays selected game
void poker::play()
{
    poker game;

    d.deck::fill_deck();
	game.poker_rules();
	players = game.init_players();
	hands = game.num_hands();

	do{
        for(int x = 0; x < players; x++)
        {
		   p.show_hand(players);
            game.ask_player();
            game.hand_check();
            game.turn();
        }

        p.show_hand(players);
        game.point_printer();
        game_counter++;
        if(game_counter!=hands)
        {
		   cout << "New hands!!" << endl;
		   cout << endl;
	       game.new_hands();
    	}
	}while(game_counter != hands);


	cout << "No more hands to play! Game over!!" << endl;
	cout << "Final scores are:" << endl;
	game.point_printer();

}//***************** end play_poker **********************


//Explains rules for poker
void poker::poker_rules()
{
	cout << "You are now playing poker!! :D" << endl;
	cout << endl;
	cout << "Here are some simple rules!" << endl;
	cout << "There is a running count for each played hand." << endl;
	cout << "The person with the highest point count at the end wins!!!" << endl;
	cout << "Each person is allowed to discard up to 4 cards from their hand ONCE!!" << endl;
	cout << endl;
	cout << "Here are the hands and points for each hand:" << endl;
	cout << "Three of a Kind (3 of same rank) = 10 points" << endl;
	cout << "Straight (5 cards in a row) = 15 points" << endl;
	cout << "Flush (Any 5 cards of same suit) = 20 points" << endl;
	cout << "Full House (3 cards of one rank and 2 cards of another rank) = 25 points" << endl;
	cout << "Four of a Kind (4 of same rank) = 30 points" << endl;
	cout << "Straight Flush (5 cards in a row with same suit) = 50 points" << endl;
	cout << endl;
	cout << "Good luck! :D" << endl;
}//***************** end poker_rules **********************


//create player and initial hands
int poker::init_players()
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


//Deal new hands to players after each round
void poker::new_hands()
{
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
}//***************** end new_hands **********************


//Creates hands for two players
void poker::two_players()
{
	p.p1.resize(5);
	p.create_hand(1);
	p.rank_sort(1);
	p.p2.resize(5);
	p.create_hand(2);
	p.rank_sort(2);
}//***************** end two_players **********************


//Creates hands for three players
void poker::three_players()
{
	p.p1.resize(5);
	p.create_hand(1);
	p.rank_sort(1);
	p.p2.resize(5);
	p.create_hand(2);
	p.rank_sort(2);
	p.p3.resize(5);
	p.create_hand(3);
	p.rank_sort(3);
}//***************** end three_players **********************


//Creates hands for four players
void poker::four_players()
{
	p.p1.resize(5);
	p.create_hand(1);
	p.rank_sort(1);
	p.p2.resize(5);
	p.create_hand(2);
	p.rank_sort(2);
	p.p3.resize(5);
	p.create_hand(3);
	p.rank_sort(3);
	p.p4.resize(5);
	p.create_hand(4);
	p.rank_sort(4);
}//***************** end four_players **********************


//Creates hands for five players
void poker::five_players()
{
	p.p1.resize(5);
	p.create_hand(1);
	p.rank_sort(1);
	p.p2.resize(5);
	p.create_hand(2);
	p.rank_sort(2);
	p.p3.resize(5);
	p.create_hand(3);
	p.rank_sort(3);
	p.p4.resize(5);
	p.create_hand(4);
	p.rank_sort(4);
	p.p5.resize(5);
	p.create_hand(5);
	p.rank_sort(5);
}//***************** end five_players **********************


//Creates hands for six players
void poker::six_players()
{
	p.p1.resize(5);
	p.create_hand(1);
	p.rank_sort(1);
	p.p2.resize(5);
	p.create_hand(2);
	p.rank_sort(2);
	p.p3.resize(5);
	p.create_hand(3);
	p.rank_sort(3);
	p.p4.resize(5);
	p.create_hand(4);
	p.rank_sort(4);
	p.p5.resize(5);
	p.create_hand(5);
	p.rank_sort(5);
	p.p6.resize(5);
	p.create_hand(6);
	p.rank_sort(6);
}//***************** end six_players **********************


//Number of hands to play
int poker::num_hands()
{
    cout << "How many hands would you like to play?: ";
    cin >> hands;

    return hands;
}//***************** end six_players **********************


//Checks to see whos turn it is
void poker::turn()
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


//Asks players if they want to discard unwanted cards
void poker::ask_player()
{
	poker g;

	cout << "Player " << turn_count << "'s turn" << endl;
	cout << "How many cards do you want to discard? (choose up to 4): ";
	cin >> pick_card;
	cout << endl;
	while(pick_card > 5){
		cout << "You can only discard up to 4!!!" << endl;
		cout << "Pick again: ";
		cin >> pick_card;
		cout << endl;
		p.show_hand(players);
	}
	if(pick_card > 0)
	{
    discard_unwanted(pick_card);
	}
}//***************** end ask_player **********************


//Discards cards from players hand
void poker::discard_unwanted(int picked)
{
    int discard;

    cout << "Pick which cards do you want to discard: " << endl;
    cout << endl;

    if(picked == 1){
        cout << "1st Card(0-4): ";
        cin >> discard;
	   cout << endl;
        if(turn_count == 1){
            cout << "Discarding: " << p.p1[discard].rank << p.p1[discard].suit << endl;
            p.p1.erase(p.p1.begin() + discard);
        }
        if(turn_count == 2){
            cout << "Discarding: " << p.p2[discard].rank << p.p2[discard].suit << endl;
            p.p2.erase(p.p2.begin() + discard);
        }
        if(turn_count == 3){
            cout << "Discarding: " << p.p3[discard].rank << p.p3[discard].suit << endl;
            p.p3.erase(p.p3.begin() + discard);
        }
        if(turn_count == 4){
            cout << "Discarding: " << p.p4[discard].rank << p.p4[discard].suit << endl;
            p.p4.erase(p.p4.begin() + discard);
        }
        if(turn_count == 5){
            cout << "Discarding: " << p.p5[discard].rank << p.p5[discard].suit << endl;
            p.p5.erase(p.p5.begin() + discard);
        }
        if(turn_count == 6){
            cout << "Discarding: " << p.p6[discard].rank << p.p6[discard].suit << endl;
            p.p6.erase(p.p6.begin() + discard);
        }

        p.show_hand(players);
        draw_new_cards(picked);
    }
    if(picked == 2){
        cout << "1st Card(0-4): ";
        cin >> discard;
	   cout << endl;
        if(turn_count == 1){
            cout << "Discarding: " << p.p1[discard].rank << p.p1[discard].suit << endl;
            p.p1.erase(p.p1.begin() + discard);
        }
        if(turn_count == 2){
            cout << "Discarding: " << p.p2[discard].rank << p.p2[discard].suit << endl;
            p.p2.erase(p.p2.begin() + discard);
        }
        if(turn_count == 3){
            cout << "Discarding: " << p.p3[discard].rank << p.p3[discard].suit << endl;
            p.p3.erase(p.p3.begin() + discard);
        }
        if(turn_count == 4){
            cout << "Discarding: " << p.p4[discard].rank << p.p4[discard].suit << endl;
            p.p4.erase(p.p4.begin() + discard);
        }
        if(turn_count == 5){
            cout << "Discarding: " << p.p5[discard].rank << p.p5[discard].suit << endl;
            p.p5.erase(p.p5.begin() + discard);
        }
        if(turn_count == 6){
            cout << "Discarding: " << p.p6[discard].rank << p.p6[discard].suit << endl;
            p.p6.erase(p.p6.begin() + discard);
        }
        p.show_hand(players);

        cout << "2nd Card(0-3): ";
        cin >> discard;
	   cout << endl;
        if(turn_count == 1){
            cout << "Discarding: " << p.p1[discard].rank << p.p1[discard].suit << endl;
            p.p1.erase(p.p1.begin() + discard);
        }
        if(turn_count == 2){
            cout << "Discarding: " << p.p2[discard].rank << p.p2[discard].suit << endl;
            p.p2.erase(p.p2.begin() + discard);
        }
        if(turn_count == 3){
            cout << "Discarding: " << p.p3[discard].rank << p.p3[discard].suit << endl;
            p.p3.erase(p.p3.begin() + discard);
        }
        if(turn_count == 4){
            cout << "Discarding: " << p.p4[discard].rank << p.p4[discard].suit << endl;
            p.p4.erase(p.p4.begin() + discard);
        }
        if(turn_count == 5){
            cout << "Discarding: " << p.p5[discard].rank << p.p5[discard].suit << endl;
            p.p5.erase(p.p5.begin() + discard);
        }
        if(turn_count == 6){
            cout << "Discarding: " << p.p6[discard].rank << p.p6[discard].suit << endl;
            p.p6.erase(p.p6.begin() + discard);
        }
        p.show_hand(players);
        draw_new_cards(picked);
	}
	if(picked == 3){
        cout << "1st Card(0-4): ";
        cin >> discard;
	   cout << endl;
        if(turn_count == 1){
            cout << "Discarding: " << p.p1[discard].rank << p.p1[discard].suit << endl;
            p.p1.erase(p.p1.begin() + discard);
        }
        if(turn_count == 2){
            cout << "Discarding: " << p.p2[discard].rank << p.p2[discard].suit << endl;
            p.p2.erase(p.p2.begin() + discard);
        }
        if(turn_count == 3){
            cout << "Discarding: " << p.p3[discard].rank << p.p3[discard].suit << endl;
            p.p3.erase(p.p3.begin() + discard);
        }
        if(turn_count == 4){
            cout << "Discarding: " << p.p4[discard].rank << p.p4[discard].suit << endl;
            p.p4.erase(p.p4.begin() + discard);
        }
        if(turn_count == 5){
            cout << "Discarding: " << p.p5[discard].rank << p.p5[discard].suit << endl;
            p.p5.erase(p.p5.begin() + discard);
        }
        if(turn_count == 6){
            cout << "Discarding: " << p.p6[discard].rank << p.p6[discard].suit << endl;
            p.p6.erase(p.p6.begin() + discard);
        }
        p.show_hand(players);

        cout<< "2nd Card(0-3): ";
        cin >> discard;
	   cout << endl;
        if(turn_count == 1){
            cout << "Discarding: " << p.p1[discard].rank << p.p1[discard].suit << endl;
            p.p1.erase(p.p1.begin() + discard);
        }
        if(turn_count == 2){
            cout << "Discarding: " << p.p2[discard].rank << p.p2[discard].suit << endl;
            p.p2.erase(p.p2.begin() + discard);
        }
        if(turn_count == 3){
            cout << "Discarding: " << p.p3[discard].rank << p.p3[discard].suit << endl;
            p.p3.erase(p.p3.begin() + discard);
        }
        if(turn_count == 4){
            cout << "Discarding: " << p.p4[discard].rank << p.p4[discard].suit << endl;
            p.p4.erase(p.p4.begin() + discard);
        }
        if(turn_count == 5){
            cout << "Discarding: " << p.p5[discard].rank << p.p5[discard].suit << endl;
            p.p5.erase(p.p5.begin() + discard);
        }
        if(turn_count == 6){
            cout << "Discarding: " << p.p6[discard].rank << p.p6[discard].suit << endl;
            p.p6.erase(p.p6.begin() + discard);
        }
        p.show_hand(players);

        cout << "3rd Card(0-2): ";
	   cin >> discard; 
	   cout << endl;
        if(turn_count == 1){
            cout << "Discarding: " << p.p1[discard].rank << p.p1[discard].suit << endl;
            p.p1.erase(p.p1.begin() + discard);
        }
        if(turn_count == 2){
            cout << "Discarding: " << p.p2[discard].rank << p.p2[discard].suit << endl;
            p.p2.erase(p.p2.begin() + discard);
        }
        if(turn_count == 3){
            cout << "Discarding: " << p.p3[discard].rank << p.p3[discard].suit << endl;
            p.p3.erase(p.p3.begin() + discard);
        }
        if(turn_count == 4){
            cout << "Discarding: " << p.p4[discard].rank << p.p4[discard].suit << endl;
            p.p4.erase(p.p4.begin() + discard);
        }
        if(turn_count == 5){
            cout << "Discarding: " << p.p5[discard].rank << p.p5[discard].suit << endl;
            p.p5.erase(p.p5.begin() + discard);
        }
        if(turn_count == 6){
            cout << "Discarding: " << p.p6[discard].rank << p.p6[discard].suit << endl;
            p.p6.erase(p.p6.begin() + discard);
        }
        p.show_hand(players);
        draw_new_cards(picked);
	}
	if(picked == 4){
        cout << "1st Card(0-4): ";
        cin >> discard;
	   cout << endl;
        if(turn_count == 1){
            cout << "Discarding: " << p.p1[discard].rank << p.p1[discard].suit << endl;
            p.p1.erase(p.p1.begin() + discard);
        }
        if(turn_count == 2){
            cout << "Discarding: " << p.p2[discard].rank << p.p2[discard].suit << endl;
            p.p2.erase(p.p2.begin() + discard);
        }
        if(turn_count == 3){
            cout << "Discarding: " << p.p3[discard].rank << p.p3[discard].suit << endl;
            p.p3.erase(p.p3.begin() + discard);
        }
        if(turn_count == 4){
            cout << "Discarding: " << p.p4[discard].rank << p.p4[discard].suit << endl;
            p.p4.erase(p.p4.begin() + discard);
        }
        if(turn_count == 5){
            cout << "Discarding: " << p.p5[discard].rank << p.p5[discard].suit << endl;
            p.p5.erase(p.p5.begin() + discard);
        }
        if(turn_count == 6){
            cout << "Discarding: " << p.p6[discard].rank << p.p6[discard].suit << endl;
            p.p6.erase(p.p6.begin() + discard);
        }
        p.show_hand(players);

        cout << "2nd Card(0-3): ";
        cin >> discard;
	   cout << endl;
        if(turn_count == 1){
            cout << "Discarding: " << p.p1[discard].rank << p.p1[discard].suit << endl;
            p.p1.erase(p.p1.begin() + discard);
        }
        if(turn_count == 2){
            cout << "Discarding: " << p.p2[discard].rank << p.p2[discard].suit << endl;
            p.p2.erase(p.p2.begin() + discard);
        }
        if(turn_count == 3){
            cout << "Discarding: " << p.p3[discard].rank << p.p3[discard].suit << endl;
            p.p3.erase(p.p3.begin() + discard);
        }
        if(turn_count == 4){
            cout << "Discarding: " << p.p4[discard].rank << p.p4[discard].suit << endl;
            p.p4.erase(p.p4.begin() + discard);
        }
        if(turn_count == 5){
            cout << "Discarding: " << p.p5[discard].rank << p.p5[discard].suit << endl;
            p.p5.erase(p.p5.begin() + discard);
        }
        if(turn_count == 6){
            cout << "Discarding: " << p.p6[discard].rank << p.p6[discard].suit << endl;
            p.p6.erase(p.p6.begin() + discard);
        }
        p.show_hand(players);

        cout << "3rd Card(0-2): ";
        cin >> discard;
	   cout << endl;
        if(turn_count == 1){
            cout << "Discarding: " << p.p1[discard].rank << p.p1[discard].suit << endl;
            p.p1.erase(p.p1.begin() + discard);
        }
        if(turn_count == 2){
            cout << "Discarding: " << p.p2[discard].rank << p.p2[discard].suit << endl;
            p.p2.erase(p.p2.begin() + discard);
        }
        if(turn_count == 3){
            cout << "Discarding: " << p.p3[discard].rank << p.p3[discard].suit << endl;
            p.p3.erase(p.p3.begin() + discard);
        }
        if(turn_count == 4){
            cout << "Discarding: " << p.p4[discard].rank << p.p4[discard].suit << endl;
            p.p4.erase(p.p4.begin() + discard);
        }
        if(turn_count == 5){
            cout << "Discarding: " << p.p5[discard].rank << p.p5[discard].suit << endl;
            p.p5.erase(p.p5.begin() + discard);
        }
        if(turn_count == 6){
            cout << "Discarding: " << p.p6[discard].rank << p.p6[discard].suit << endl;
            p.p6.erase(p.p6.begin() + discard);
        }
        p.show_hand(players);

        cout << "4th Card(0-1): ";
	   cin >> discard; 
	   cout << endl;
        if(turn_count == 1){
            cout << "Discarding: " << p.p1[discard].rank << p.p1[discard].suit << endl;
            p.p1.erase(p.p1.begin() + discard);
        }
        if(turn_count == 2){
            cout << "Discarding: " << p.p2[discard].rank << p.p2[discard].suit << endl;
            p.p2.erase(p.p2.begin() + discard);
        }
        if(turn_count == 3){
            cout << "Discarding: " << p.p3[discard].rank << p.p3[discard].suit << endl;
            p.p3.erase(p.p3.begin() + discard);
        }
        if(turn_count == 4){
            cout << "Discarding: " << p.p4[discard].rank << p.p4[discard].suit << endl;
            p.p4.erase(p.p4.begin() + discard);
        }
        if(turn_count == 5){
            cout << "Discarding: " << p.p5[discard].rank << p.p5[discard].suit << endl;
            p.p5.erase(p.p5.begin() + discard);
        }
        if(turn_count == 6){
            cout << "Discarding: " << p.p6[discard].rank << p.p6[discard].suit << endl;
            p.p6.erase(p.p6.begin() + discard);
        }
        p.show_hand(players);
        draw_new_cards(picked);
	}
}//***************** end discard_unwanted **********************


//Player draws new cards depending on how many discarded
void poker::draw_new_cards(int picked)
{
	cout << endl;
    cout << "drawing " << picked << " cards" << endl;
    cout << endl;
    card *single = new card[picked];
	deck *hand = new deck[1];

    for(int i = 0; i < picked; i++)
    {
        if(turn_count == 1)
        {
            p.increase_hand(1, 1);
            single[0] = hand[0].deck::draw_card(single);
            p.p1[p.p1.size()-1].rank = single[0].rank;
            p.p1[p.p1.size()-1].suit = single[0].suit;
            cout << "Drawing: " << single[0].rank << single[0].suit << endl;
		  p.rank_sort(1);
        }
        else if(turn_count == 2)
        {
            p.increase_hand(2, 1);
            single[0] = hand[0].deck::draw_card(single);
            p.p2[p.p2.size()-1].rank = single[0].rank;
            p.p2[p.p2.size()-1].suit = single[0].suit;
            cout << "Drawing: " << single[0].rank << single[0].suit << endl;
		  p.rank_sort(2);
        }
        else if(turn_count == 3)
        {
            p.increase_hand(3, 1);
            single[0] = hand[0].deck::draw_card(single);
            p.p3[p.p3.size()-1].rank = single[0].rank;
            p.p3[p.p3.size()-1].suit = single[0].suit;
            cout << "Drawing: " << single[0].rank << single[0].suit << endl;
		  p.rank_sort(3);
        }
        else if(turn_count == 4)
        {
            p.increase_hand(4, 1);
            single[0] = hand[0].deck::draw_card(single);
            p.p4[p.p4.size()-1].rank = single[0].rank;
            p.p4[p.p4.size()-1].suit = single[0].suit;
            cout << "Drawing: " << single[0].rank << single[0].suit << endl;
		  p.rank_sort(4);
        }
        else if(turn_count == 5)
        {
            p.increase_hand(5, 1);
            single[0] = hand[0].deck::draw_card(single);
            p.p5[p.p5.size()-1].rank = single[0].rank;
            p.p5[p.p5.size()-1].suit = single[0].suit;
            cout << "Drawing: " << single[0].rank << single[0].suit << endl;
		  p.rank_sort(5);
        }
        else if(turn_count == 6)
        {
            p.increase_hand(6, 1);
            single[0] = hand[0].deck::draw_card(single);
            p.p6[p.p6.size()-1].rank = single[0].rank;
            p.p6[p.p6.size()-1].suit = single[0].suit;
            cout << "Drawing: " << single[0].rank << single[0].suit << endl;
		  p.rank_sort(6);
        }
    }
	delete[] hand;
	delete[] single;
}//***************** end draw_new_cards **********************


//Checks each players hand to see if anyone has a hand
void poker::hand_check()
{
    if(turn_count == 1)
    {
        straight_flush();
    	four_of_kind();
    	full_house();
    	flush();
        straight();
        three_of_kind();
        no_hand();
    }
    if(turn_count == 2)
    {
        straight_flush();
    	four_of_kind();
    	full_house();
    	flush();
        straight();
        three_of_kind();
        no_hand();
    }
    if(turn_count == 3)
    {
        straight_flush();
    	four_of_kind();
    	full_house();
    	flush();
        straight();
        three_of_kind();
        no_hand();
    }
    if(turn_count == 4)
    {
        straight_flush();
    	four_of_kind();
    	full_house();
    	flush();
        straight();
        three_of_kind();
        no_hand();
    }
    if(turn_count == 5)
    {
        straight_flush();
    	four_of_kind();
    	full_house();
    	flush();
        straight();
        three_of_kind();
        no_hand();
    }
    if(turn_count == 6)
    {
    	straight_flush();
    	four_of_kind();
    	full_house();
    	flush();
        straight();
        three_of_kind();
    	no_hand();
    }
}//***************** end hand_check **********************


//Checks to see if player has 3 of a kind
void poker::three_of_kind()
{
    //for player 1
    if(turn_count == 1)
    {
	    if ((p.p1[0].rank == p.p1[1].rank && p.p1[1].rank == p.p1[2].rank) ||
		   (p.p1[1].rank == p.p1[2].rank && p.p1[2].rank == p.p1[3].rank) ||
		    (p.p1[2].rank == p.p1[3].rank && p.p1[3].rank == p.p1[4].rank)){
		    cout << "Player 1 got a 3 of a kind!" << endl;
		    point_keeper(turn_count, 10);
	    }
    }
    if(turn_count == 2)
    {
	    if ((p.p2[0].rank == p.p2[1].rank && p.p2[1].rank == p.p2[2].rank) ||
		    (p.p2[1].rank == p.p2[2].rank && p.p2[2].rank == p.p2[3].rank) ||
		    (p.p2[2].rank == p.p2[3].rank && p.p2[3].rank == p.p2[4].rank)){
		    cout << "Player 2 got a 3 of a kind!" << endl;
		    point_keeper(turn_count, 10);
	    }
    }
    if(turn_count == 3)
    {
	    if ((p.p3[0].rank == p.p3[1].rank && p.p3[1].rank == p.p3[2].rank) ||
		    (p.p3[1].rank == p.p3[2].rank && p.p3[2].rank == p.p3[3].rank) ||
		    (p.p3[2].rank == p.p3[3].rank && p.p3[3].rank == p.p3[4].rank)){
		    cout << "Player 3 got a 3 of a kind!" << endl;
		    point_keeper(turn_count, 10);
	    }
    }
    if(turn_count == 4)
    {
	    if ((p.p4[0].rank == p.p4[1].rank && p.p4[1].rank == p.p4[2].rank) ||
		    (p.p4[1].rank == p.p4[2].rank && p.p4[2].rank == p.p4[3].rank) ||
		    (p.p4[2].rank == p.p4[3].rank && p.p4[3].rank == p.p4[4].rank)){
		    cout << "Player 4 got a 3 of a kind!" << endl;
		    point_keeper(turn_count, 10);
	    }
    }
    if(turn_count == 5)
    {
	    if ((p.p5[0].rank == p.p5[1].rank && p.p5[1].rank == p.p5[2].rank) ||
		    (p.p5[1].rank == p.p5[2].rank && p.p5[2].rank == p.p5[3].rank) ||
		    (p.p5[2].rank == p.p5[3].rank && p.p5[3].rank == p.p5[4].rank)){
		    cout << "Player 5 got a 3 of a kind!" << endl;
		    point_keeper(turn_count, 10);
	    }
    }
    if (turn_count == 6)
    {
	    if ((p.p6[0].rank == p.p6[1].rank && p.p6[1].rank == p.p6[2].rank) ||
		   (p.p6[1].rank == p.p6[2].rank && p.p6[2].rank == p.p6[3].rank) ||
		    (p.p6[2].rank == p.p6[3].rank && p.p6[3].rank == p.p6[4].rank)){
		    cout << "Player 6 got a 3 of a kind!" << endl;
		    point_keeper(turn_count, 10);
	    }
    }

}//***************** end three_of_kind **********************


//Checks to see if player has a straight
void poker::straight()
{
	if(turn_count == 1)
	{
		if(p.p1[1].rank == p.p1[0].rank+"1" && p.p1[2].rank == p.p1[1].rank+"1" && 
			p.p1[3].rank == p.p1[2].rank+"1" && p.p1[4].rank == p.p1[3].rank+"1")
		{
			cout << "Player 1 got a straight!" << endl;
			point_keeper(turn_count, 15);
		}
	}
	if(turn_count == 2)
	{
		if(p.p2[1].rank == p.p2[0].rank+"1" && p.p2[2].rank == p.p2[1].rank+"1" && 
			p.p2[3].rank == p.p2[2].rank+"1" && p.p2[4].rank == p.p2[3].rank+"1")
		{
			cout << "Player 2 got a straight!" << endl;
			point_keeper(turn_count, 15);
		}
	}
	if(turn_count == 3)
	{
		if(p.p3[1].rank == p.p3[0].rank+"1" && p.p3[2].rank == p.p3[1].rank+"1" && 
			p.p3[3].rank == p.p3[2].rank+"1" && p.p3[4].rank == p.p3[3].rank+"1")
		{
			cout << "Player 3 got a straight!" << endl;
			point_keeper(turn_count, 15);
		}
	}
	if(turn_count == 4)
	{
		if(p.p4[1].rank == p.p4[0].rank+"1" && p.p4[2].rank == p.p4[1].rank+"1" && 
			p.p4[3].rank == p.p4[2].rank+"1" && p.p4[4].rank == p.p4[3].rank+"1")
		{
			cout << "Player 4 got a straight!" << endl;
			point_keeper(turn_count, 15);
		}
	}
	if(turn_count == 5)
	{
		if(p.p5[1].rank == p.p5[0].rank+"1" && p.p5[2].rank == p.p5[1].rank+"1" && 
			p.p5[3].rank == p.p5[2].rank+"1" && p.p5[4].rank == p.p5[3].rank+"1")
		{
			cout << "Player 5 got a straight!" << endl;
			point_keeper(turn_count, 15);
		}
	}
	if(turn_count == 6)
	{
		if(p.p6[1].rank == p.p6[0].rank+"1" && p.p6[2].rank == p.p6[1].rank+"1" && 
			p.p6[3].rank == p.p6[2].rank+"1" && p.p6[4].rank == p.p6[3].rank+"1")
		{
			cout << "Player 6 got a straight!" << endl;
			point_keeper(turn_count, 15);
		}
	}

}//***************** end straight **********************


//Checks to see if player has a flush
void poker::flush()
{
    //for player 1
    if(turn_count == 1)
    {
	    if (p.p1[0].suit == p.p1[1].suit && p.p1[1].suit == p.p1[2].suit && p.p1[2].suit == p.p1[3].suit &&
		    p.p1[3].suit == p.p1[4].suit && p.p1[4].suit == p.p1[5].suit){
		    cout << "Player 1 got a flush!" << endl;
		    point_keeper(turn_count, 20);
	    }
    }
    if(turn_count == 2)
    {
	    if (p.p2[0].suit == p.p2[1].suit && p.p2[1].suit == p.p2[2].suit && p.p2[2].suit == p.p2[3].suit &&
		    p.p2[3].suit == p.p2[4].suit && p.p2[4].suit == p.p2[5].suit){
		    cout << "Player 2 got a flush!" << endl;
		    point_keeper(turn_count, 20);
	    }
    }
    if(turn_count == 3)
    {
	    if (p.p3[0].suit == p.p3[1].suit && p.p3[1].suit == p.p3[2].suit && p.p3[2].suit == p.p3[3].suit &&
		    p.p3[3].suit == p.p3[4].suit && p.p3[4].suit == p.p3[5].suit){
		    cout << "Player 3 got a flush!" << endl;
		    point_keeper(turn_count, 20);
	    }
    }
    if(turn_count == 4)
    {
	    if (p.p4[0].suit == p.p4[1].suit && p.p4[1].suit == p.p4[2].suit && p.p4[2].suit == p.p4[3].suit &&
		    p.p4[3].suit == p.p4[4].suit && p.p4[4].suit == p.p4[5].suit){
		    cout << "Player 4 got a flush!" << endl;
		    point_keeper(turn_count, 20);
	    }
    }
    if(turn_count == 5)
    {
	    if (p.p5[0].suit == p.p5[1].suit && p.p5[1].suit == p.p5[2].suit && p.p5[2].suit == p.p5[3].suit &&
		    p.p5[3].suit == p.p5[4].suit && p.p5[4].suit == p.p5[5].suit){
		    cout << "Player 5 got a flush!" << endl;
		    point_keeper(turn_count, 20);
	    }
    }
    if(turn_count == 6)
    {
	    if (p.p6[0].suit == p.p6[1].suit && p.p6[1].suit == p.p6[2].suit && p.p6[2].suit == p.p6[3].suit &&
		    p.p6[3].suit == p.p6[4].suit && p.p6[4].suit == p.p6[5].suit){
		    cout << "Player 6 got a flush!" << endl;
		    point_keeper(turn_count, 20);
	    }
    }
}//***************** end flush **********************


//Checks to see if player has a full house
void poker::full_house()
{
	//for player 1
	if (turn_count == 1)
	{
		if ((p.p1[0].rank == p.p1[1].rank && p.p1[1].rank == p.p1[2].rank && p.p1[3].rank == p.p1[4].rank) ||
			(p.p1[0].rank == p.p1[1].rank && p.p1[2].rank == p.p1[3].rank && p.p1[3].rank == p.p1[4].rank)){
			cout << "Player 1 got a full house!" << endl;
			point_keeper(turn_count, 25);
		}
	}
	if (turn_count == 2)
	{
		if ((p.p2[0].rank == p.p2[1].rank && p.p2[1].rank == p.p2[2].rank && p.p2[3].rank == p.p2[4].rank) ||
			(p.p2[0].rank == p.p2[1].rank && p.p2[2].rank == p.p2[3].rank && p.p2[3].rank == p.p2[4].rank)){
			cout << "Player 2 got a full house!" << endl;
			point_keeper(turn_count, 25);
		}
	}
	if (turn_count == 3)
	{
		if ((p.p3[0].rank == p.p3[1].rank && p.p3[1].rank == p.p3[2].rank && p.p3[3].rank == p.p3[4].rank) ||
			(p.p3[0].rank == p.p3[1].rank && p.p3[2].rank == p.p3[3].rank && p.p3[3].rank == p.p3[4].rank)){
			cout << "Player 3 got a full house!" << endl;
			point_keeper(turn_count, 25);
		}
	}
	if (turn_count == 4)
	{
		if ((p.p4[0].rank == p.p4[1].rank && p.p4[1].rank == p.p4[2].rank && p.p4[3].rank == p.p4[4].rank) ||
			(p.p4[0].rank == p.p4[1].rank && p.p4[2].rank == p.p4[3].rank && p.p4[3].rank == p.p4[4].rank)){
			cout << "Player 4 got a full house!" << endl;
			point_keeper(turn_count, 25);
		}
	}
	if (turn_count == 5)
	{
		if ((p.p5[0].rank == p.p5[1].rank && p.p5[1].rank == p.p5[2].rank && p.p5[3].rank == p.p5[4].rank) ||
			(p.p5[0].rank == p.p5[1].rank && p.p5[2].rank == p.p5[3].rank && p.p5[3].rank == p.p5[4].rank)){
			cout << "Player 5 got a full house!" << endl;
			point_keeper(turn_count, 25);
		}
	}
	if (turn_count == 6)
	{
		if ((p.p6[0].rank == p.p6[1].rank && p.p6[1].rank == p.p6[2].rank && p.p6[3].rank == p.p6[4].rank) ||
			(p.p6[0].rank == p.p6[1].rank && p.p6[2].rank == p.p6[3].rank && p.p6[3].rank == p.p6[4].rank)){
			cout << "Player 6 got a full house!" << endl;
			point_keeper(turn_count, 25);
		}
	}
}//***************** end full_house **********************


//Checks to see if player has a four of a kind
void poker::four_of_kind()
{
    int match = 0, counter = 0;
	card *holder = new card[4];

	//for player 1
	if (turn_count == 1)
	{
		if ((p.p1[0].rank == p.p1[1].rank && p.p1[1].rank == p.p1[2].rank && p.p1[2].rank == p.p1[3].rank) ||
			(p.p1[1].rank == p.p1[2].rank && p.p1[2].rank == p.p1[3].rank && p.p1[3].rank == p.p1[4].rank)){
			cout << "Player 1 got a 4 of a kind!" << endl;
			point_keeper(turn_count, 30);
		}
		else
			three_of_kind();
	}
	if (turn_count == 2)
	{
		if ((p.p2[0].rank == p.p2[1].rank && p.p2[1].rank == p.p2[2].rank && p.p2[2].rank == p.p2[3].rank) ||
			(p.p2[1].rank == p.p2[2].rank && p.p2[2].rank == p.p2[3].rank && p.p2[3].rank == p.p2[4].rank)){
			cout << "Player 2 got a 4 of a kind!" << endl;
			point_keeper(turn_count, 30);
		}
		else
			three_of_kind();
	}
	if (turn_count == 3)
	{
		if ((p.p3[0].rank == p.p3[1].rank && p.p3[1].rank == p.p3[2].rank && p.p3[2].rank == p.p3[3].rank) ||
			(p.p3[1].rank == p.p3[2].rank && p.p3[2].rank == p.p3[3].rank && p.p3[3].rank == p.p3[4].rank)){
			cout << "Player 3 got a 4 of a kind!" << endl;
			point_keeper(turn_count, 30);
		}
		else
			three_of_kind();
	}
	if (turn_count == 4)
	{
		if ((p.p4[0].rank == p.p4[1].rank && p.p4[1].rank == p.p4[2].rank && p.p4[2].rank == p.p4[3].rank) ||
			(p.p4[1].rank == p.p4[2].rank && p.p4[2].rank == p.p4[3].rank && p.p4[3].rank == p.p4[4].rank)){
			cout << "Player 4 got a 4 of a kind!" << endl;
			point_keeper(turn_count, 30);
		}
		else
			three_of_kind();
	}
	if (turn_count == 5)
	{
		if ((p.p5[0].rank == p.p5[1].rank && p.p5[1].rank == p.p5[2].rank && p.p5[2].rank == p.p5[3].rank) ||
			(p.p5[1].rank == p.p5[2].rank && p.p5[2].rank == p.p5[3].rank && p.p5[3].rank == p.p5[4].rank)){
			cout << "Player 5 got a 4 of a kind!" << endl;
			point_keeper(turn_count, 30);
		}
		else
			three_of_kind();
	}
	if (turn_count == 6)
	{
		if ((p.p6[0].rank == p.p6[1].rank && p.p6[1].rank == p.p6[2].rank && p.p6[2].rank == p.p6[3].rank) ||
			(p.p6[1].rank == p.p6[2].rank && p.p6[2].rank == p.p6[3].rank && p.p6[3].rank == p.p6[4].rank)){
			cout << "Player 6 got a 4 of a kind!" << endl;
			point_keeper(turn_count, 30);
		}
		else
			three_of_kind();
	}
}//***************** end four_of_kind **********************


//Checks to see if player has a straight flush
void poker::straight_flush()
{
if(turn_count == 1)
	{
		//straight condition
		if(p.p1[1].rank == p.p1[0].rank+"1" && p.p1[2].rank == p.p1[1].rank+"1" && 
			p.p1[3].rank == p.p1[2].rank+"1" && p.p1[4].rank == p.p1[3].rank+"1")
		{
			//flush condition
			if (p.p1[0].suit == p.p1[1].suit && p.p1[1].suit == p.p1[2].suit && p.p1[2].suit == p.p1[3].suit &&
		    p.p1[3].suit == p.p1[4].suit && p.p1[4].suit == p.p1[5].suit){
				cout << "Player 1 got a straight flush!" << endl;
				point_keeper(turn_count, 50);
			}
		}
	}
	if(turn_count == 2)
	{
		if(p.p2[1].rank == p.p2[0].rank+"1" && p.p2[2].rank == p.p2[1].rank+"1" && 
			p.p2[3].rank == p.p2[2].rank+"1" && p.p2[4].rank == p.p2[3].rank+"1")
		{
			if (p.p2[0].suit == p.p2[1].suit && p.p2[1].suit == p.p2[2].suit && p.p2[2].suit == p.p2[3].suit &&
		    p.p2[3].suit == p.p2[4].suit && p.p2[4].suit == p.p2[5].suit){
				cout << "Player 2 got a straight flush!" << endl;
				point_keeper(turn_count, 50);
			}
		}
	}
	if(turn_count == 3)
	{
		if(p.p3[1].rank == p.p3[0].rank+"1" && p.p3[2].rank == p.p3[1].rank+"1" && 
			p.p3[3].rank == p.p3[2].rank+"1" && p.p3[4].rank == p.p3[3].rank+"1")
		{
			if (p.p3[0].suit == p.p3[1].suit && p.p3[1].suit == p.p3[2].suit && p.p3[2].suit == p.p3[3].suit &&
		    p.p3[3].suit == p.p3[4].suit && p.p3[4].suit == p.p3[5].suit){
				cout << "Player 3 got a straight flush!" << endl;
				point_keeper(turn_count, 50);
			}
		}
	}
	if(turn_count == 4)
	{
		if(p.p4[1].rank == p.p4[0].rank+"1" && p.p4[2].rank == p.p4[1].rank+"1" && 
			p.p4[3].rank == p.p4[2].rank+"1" && p.p4[4].rank == p.p4[3].rank+"1")
		{
			if (p.p4[0].suit == p.p4[1].suit && p.p4[1].suit == p.p4[2].suit && p.p4[2].suit == p.p4[3].suit &&
		    p.p4[3].suit == p.p4[4].suit && p.p4[4].suit == p.p4[5].suit){
				cout << "Player 4 got a straight flush!" << endl;
				point_keeper(turn_count, 50);
			}
		}
	}
	if(turn_count == 5)
	{
		if(p.p5[1].rank == p.p5[0].rank+"1" && p.p5[2].rank == p.p5[1].rank+"1" && 
			p.p5[3].rank == p.p5[2].rank+"1" && p.p5[4].rank == p.p5[3].rank+"1")
		{
			if (p.p5[0].suit == p.p5[1].suit && p.p5[1].suit == p.p5[2].suit && p.p5[2].suit == p.p5[3].suit &&
		    p.p5[3].suit == p.p5[4].suit && p.p5[4].suit == p.p5[5].suit){
				cout << "Player 5 got a straight flush!" << endl;
				point_keeper(turn_count, 50);
			}
		}
	}
	if(turn_count == 6)
	{
		if(p.p6[1].rank == p.p6[0].rank+"1" && p.p6[2].rank == p.p6[1].rank+"1" && 
			p.p6[3].rank == p.p6[2].rank+"1" && p.p6[4].rank == p.p6[3].rank+"1")
		{
			if (p.p6[0].suit == p.p6[1].suit && p.p6[1].suit == p.p6[2].suit && p.p6[2].suit == p.p6[3].suit &&
		    p.p6[3].suit == p.p6[4].suit && p.p6[4].suit == p.p6[5].suit){
				cout << "Player 6 got a straight flush!" << endl;
				point_keeper(turn_count, 50);
			}
		}
	}
}//***************** end straight_flush **********************


//Prints message if no one has a hand
void poker::no_hand()
{
    cout << "You got no points!!!" << endl;
}//***************** end no_hand **********************

//Keeps track of all players points
void poker::point_keeper(int player_turn, int points)
{
    if(player_turn == 1){
        p1_points = p1_points + points;
    }
    if(player_turn == 2){
        p2_points = p2_points + points;
    }
    if(player_turn == 3){
        p3_points = p3_points + points;
    }
    if(player_turn == 4){
        p4_points = p4_points + points;
    }
    if(player_turn == 5){
        p5_points = p5_points + points;
    }
    if(player_turn == 6){
        p6_points = p6_points + points;
    }
}//***************** end point_keeper **********************


//Prints points for each player
void poker::point_printer()
{
    if(play_num == 2)
    {
        cout << endl;
        cout << "Player 1 current points: " << p1_points << endl;
        cout << "Player 2 current points: " << p2_points << endl;
        cout << endl;
    }
    if(play_num == 3)
    {
        cout << endl;
        cout << "Player 1 current points: " << p1_points << endl;
        cout << "Player 2 current points: " << p2_points << endl;
        cout << "Player 3 current points: " << p3_points << endl;
        cout << endl;
    }
    if(play_num == 4)
    {
        cout << endl;
        cout << "Player 1 current points: " << p1_points << endl;
        cout << "Player 2 current points: " << p2_points << endl;
        cout << "Player 3 current points: " << p3_points << endl;
        cout << "Player 4 current points: " << p4_points << endl;
        cout << endl;
    }
    if(play_num == 5)
    {
        cout << endl;
        cout << "Player 1 current points: " << p1_points << endl;
        cout << "Player 2 current points: " << p2_points << endl;
        cout << "Player 3 current points: " << p3_points << endl;
        cout << "Player 4 current points: " << p4_points << endl;
        cout << "Player 5 current points: " << p5_points << endl;
        cout << endl;
    }
    if(play_num == 6)
    {
        cout << endl;
        cout << "Player 1 current points: " << p1_points << endl;
        cout << "Player 2 current points: " << p2_points << endl;
        cout << "Player 3 current points: " << p3_points << endl;
        cout << "Player 4 current points: " << p4_points << endl;
        cout << "Player 5 current points: " << p5_points << endl;
        cout << "Player 6 current points: " << p6_points << endl;
        cout << endl;
    }

}//***************** end point_printer **********************

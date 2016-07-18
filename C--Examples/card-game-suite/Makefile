CC = g++
prog_file = play_cards
$(prog_file): game_driver.o card_games.o poker.o go_fish.o player.o deck.o
	$(CC) game_driver.o card_games.o poker.o go_fish.o player.o deck.o -o $(prog_file)
game_driver.o: game_driver.cpp
	$(CC) -c game_driver.cpp
card_games.o: card_games.cpp
	$(CC) -c card_games.cpp
poker.o: poker.cpp
	$(CC) -c poker.cpp
go_fish.o: go_fish.cpp
	$(CC) -c go_fish.cpp
player.o: player.cpp
	$(CC) -c player.cpp
deck.o: deck.cpp
	$(CC) -c deck.cpp


clean:
	rm -f *.out *.o $(prog_file)

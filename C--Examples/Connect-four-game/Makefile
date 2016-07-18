CC=g++
prog_file = play_cf
$(prog_file): connect_four.o play_cf.o
	$(CC) connect_four.o play_cf.o -o $(prog_file)
connect_four.o: connect_four.cpp
	$(CC) -c connect_four.cpp
play_cf.o: play_cf.cpp
	$(CC) -c play_cf.cpp

clean:
	rm -f *.out *.o $(prog_file)

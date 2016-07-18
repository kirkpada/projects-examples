CC = g++
prog_file = heat_diff

$(prog_file): heat_diff_driver.o heat_diff.o
	$(CC) heat_diff_driver.o heat_diff.o -o $(prog_file)

heat_diff_driver.o: heat_diff_driver.cpp
	$(CC) -c heat_diff_driver.cpp

heat_diff.o: heat_diff.cpp
	$(CC) -c heat_diff.cpp


clean:
	rm -f *.out *.o $(prog_file)
	rm -f heat_bin.dat

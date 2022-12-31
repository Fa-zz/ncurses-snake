CXX = g++
CXXFLAGS = -Wall

main: main.cpp Board.hpp
	$(CXX) $(CXXFLAGS) main.cpp -lncurses -o main

clean:
	# rm *.o*
	rm main

run:
	./main
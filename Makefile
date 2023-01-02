CXX = g++
CXXFLAGS = -Wall

main: main.cpp Board.hpp SnakeGame.hpp Drawable.hpp Apple.hpp Empty.hpp
	$(CXX) $(CXXFLAGS) main.cpp -lncurses -o main

clean:
	# rm *.o*
	rm main

run:
	./main
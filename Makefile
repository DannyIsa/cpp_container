# daniisakov@gmail.com

.PHONY: all Main test valgrind clean

all: demo

Main: demo
	./demo

demo: Demo.cpp MyContainer.o
	g++ -std=c++17 -Wall -Wextra -g -o demo Demo.cpp MyContainer.o

test: test_runner
	./test_runner

test_runner: test.cpp MyContainer.o
	g++ -std=c++17 -Wall -Wextra -g -o test_runner test.cpp MyContainer.o

MyContainer.o: MyContainer.cpp MyContainer.hpp
	g++ -std=c++17 -Wall -Wextra -g -c MyContainer.cpp -o MyContainer.o

valgrind: test_runner
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./test_runner

clean:
	rm -rf MyContainer.o demo test_runner *.dSYM

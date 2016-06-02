CC=g++
CFLAGS=-std=c++11 -Wall -Werror -Wextra

all: clean test_repl

clean:
	@rm -f *.o
	@rm -f test_repl

test_repl:
	${CC} ${CFLAGS} test_repl.cpp shoddy.cpp -o test_repl
	./test_repl

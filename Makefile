
OBJS = game.o board.o engine.o

connect4: $(OBJS)
	g++ -o connect4 $(OBJS) -lncurses

game.o: game.cc board.h engine.h
	g++    game.cc -c

board.o: board.cc board.h
	g++  -Wall -Werror board.cc -c

engine.o: engine.cc engine.h board.h
	g++ -Wall -Werror engine.cc -c


clean:
	rm -f *~ *.o connect4

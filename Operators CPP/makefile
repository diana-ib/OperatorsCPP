Ass4:Game.o Map.o Robot.o
	g++ Game.o Map.o Robot.o -o Ass4
Game.o:Game.cpp Game.h Robot.h Map.h
	g++ -c Game.cpp Game.h
Map.o:Map.cpp Map.h Robot.h
	g++ -c Map.cpp Map.h
Robot.o:Robot.cpp Robot.h
	g++ -c Robot.cpp Robot.h
clean:
	rm -f *.o

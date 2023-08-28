CC=g++
EXE_FILE=wumpus_run

all: $(EXE_FILE)

$(EXE_FILE): room_class.o game_class.o event_class.o wumpus_class.o pit_class.o bat_class.o gold_class.o funcs.o wumpus_main.cpp
	$(CC) room_class.o game_class.o event_class.o wumpus_class.o pit_class.o bat_class.o gold_class.o funcs.o wumpus_main.cpp -lncurses -o $(EXE_FILE)
	clear

debug: room_class.o game_class.o event_class.o wumpus_class.o pit_class.o bat_class.o gold_class.o funcs.o wumpus_main.cpp
	$(CC) room_class.o game_class.o event_class.o wumpus_class.o pit_class.o bat_class.o gold_class.o funcs.o wumpus_main.cpp -lncurses -g -o $(EXE_FILE)
	clear

room_class.o: room_class.cpp roomheader.h
	$(CC) -c room_class.cpp

game_class.o: game_class.cpp gameheader.h
	$(CC) -c game_class.cpp

event_class.o: event_class.cpp eventheader.h
	$(CC) -c event_class.cpp

wumpus_class.o: wumpus_class.cpp wumpusheader.h
	$(CC) -c wumpus_class.cpp

pit_class.o: pit_class.cpp pitheader.h
	$(CC) -c pit_class.cpp

bat_class.o: bat_class.cpp batheader.h
	$(CC) -c bat_class.cpp

gold_class.o: gold_class.cpp goldheader.h
	$(CC) -c gold_class.cpp

funcs.o: funcs.cpp funcsheader.h
	$(CC) -c funcs.cpp

clean:
	rm -f *.o $(EXE_FILE)
	clear

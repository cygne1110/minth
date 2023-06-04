CC = g++
CPPFLAGS = -Wall -Iinclude/
OPT = -O3 -lncursesw
OBJ = obj/main.o obj/room.o obj/floor.o obj/utils.o obj/game.o
EXEC = minth

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(OPT)

install: $(EXEC)

obj/main.o: main.cpp
	$(CC) -c $(CPPFLAGS) -o $@ $<

obj/%.o: src/%.cpp include/%.hpp
	$(CC) -c $(CPPFLAGS) -o $@ $<

clean:
	rm -f obj/*.o $(EXEC)

.PHONY: clean install


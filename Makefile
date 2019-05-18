CC = g++
PR = -std=c++17 -g
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:%.cpp=%.o)
LDFLAGS = -lSDL2_image -lSDL2_ttf -lSDL2
INC = -Isrc/ 

all: main

main: $(OBJ)
	$(CC) $(PR) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(PR) -c $< -o $@ $(INC)

clean:
	rm -f $(OBJ) main

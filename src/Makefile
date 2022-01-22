CC = g++ 
CFLAGS = -std=c++17 -c -g -Og -Wall -pedantic
OBJ = main.o image_crypto.o
DEPS = main.cpp image_crypto.cpp image_crypto.hpp
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
EXE = cipher

all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp %.hpp
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm $(OBJ) $(EXE)

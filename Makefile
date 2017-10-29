CC=g++

MAIN_SRC= main.cpp $(D1)/sys.hpp $(D1)/sys.cpp $(D1)/world.hpp $(D1)/world.cpp $(D2)/utils.cpp $(D2)/utils.hpp  


INC_PARAMS=$(foreach d, $(INC), -I$d)
INC= $(D1) $(D2)
D1= src
D2= tool

LIBS= -lSDL2
PROG_NAME=Archon


all: $(SRCS)
	$(CC) -o $(PROG_NAME) $(MAIN_SRC) -w $(LIBS) $(INC_PARAMS) -Wall
	$(info ******START*********)

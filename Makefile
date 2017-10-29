CC=g++
SRCS= main.cpp sys.hpp sys.cpp world.hpp world.cpp utils.cpp utils.hpp
LIBS= -lSDL2
PROG_NAME=Archon


all: $(PROG_NAME)

$(PROG_NAME): $(SRCS)
	$(CC) -o $(PROG_NAME) $(SRCS) -w $(LIBS) 
	$(info ******START*********)

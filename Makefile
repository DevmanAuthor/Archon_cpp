CC=g++
CFLAGS = -I
SRCS= main.cpp sys.hpp sys.cpp
LIBS= -lSDL2
PROG_NAME=Archon


all: $(PROG_NAME)

$(PROG_NAME): $(SRCS)
	$(CC) -o $(PROG_NAME) $(SRCS) -w $(LIBS)
	$(info ******START*********)

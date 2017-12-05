cc=gcc
srcs=main.c sys.c game.c world.c sprite.c 
exen=main
libs=-lSDL2 -lncurses -lSDL2_image -lGL -lGLU -lGLEW 
dirs=

all: $(srcs)
	$(cc) $(srcs) -o $(exen) -w $(libs) -g 
	$(info   **********STARTED*************)

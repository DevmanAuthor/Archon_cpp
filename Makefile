cc=gcc
srcs=main.c sys.c game.c world.c sprite.c 
exen=main
libs=-lSDL2 -lncurses -lSDL2_image
dirs=

all: $(srcs)
	$(cc) $(srcs) -o $(exen) -w $(libs) -g 
	$(info   **********STARTED*************)

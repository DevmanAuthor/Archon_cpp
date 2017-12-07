_cc=g++
sys=system
uni=universe

_srcs=main.c $(sys)/sys.c $(sys)/game.c $(sys)/utils.c $(uni)/world.c $(uni)/arena.c $(uni)/entity.c 
_bin=Hinom
_libs=-lSDL2 -lncurses -lSDL2_image -lSDL2_gfx 
_dirs=-I$(sys) -I$(uni)

all: $(srcs)
	$(_cc) $(_srcs) -o $(_bin) -w $(_libs) -g $(_dirs) 
	$(info   **********STARTED*************)

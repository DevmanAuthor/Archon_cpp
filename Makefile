_cc=g++
sys=system
uni=universe

_srcs=main.c $(sys)/sys.c $(sys)/game.c $(sys)/utils.c $(uni)/world.c $(uni)/arena.c $(uni)/entity.c 
_bin=Hinom
_libs= -lmingw32 -lSDL2main -lSDL2 -lSDL2_image 
_dirs=-I$(sys) -I$(uni)

all: $(srcs)
	$(_cc) $(_srcs) -o $(_bin) -w $(_libs) -g $(_dirs) 
	$(info   **********STARTED*************)

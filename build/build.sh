if [ "$1" == "local" ]; then
	cd ..
	make all && cd /media/sf_WinShare/
	rm -r -f Archon_sdl
	cp -r  ~/Projects/Archon_sdl  /media/sf_WinShare 
fi

if [ "$2" == "remote" ]; then
	cd .. 
	make all 
	git push -f origin master
fi



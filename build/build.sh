if [ "$1" == "local" ]; then
	cd ..
	make all && cd /media/sf_vdf/
	rm -r -f Archon_sdl
	cp -r  ~/Projects/Archon_sdl  /media/sf_vdf 
fi

if [ "$2" == "remote" ]; then
	cd .. 
	make all
	git add -a
        git commit -m -a	
	git push -f origin master
fi



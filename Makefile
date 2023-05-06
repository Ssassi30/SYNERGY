progmenu:ES.o bounding_box.o bckg1.o perso1.o serie.o minimap.o menu.o mainmenu.o 
	gcc ES.o bounding_box.o bckg1.o perso1.o serie.o minimap.o menu.o mainmenu.o -o progmenu -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -g
mainmenu.o:mainmenu.c
	gcc -c mainmenu.c -g
menu.o:menu.c
	gcc -c menu.c -g 
minimap.o:minimap.c
	gcc -c minimap.c -g 
serie.o:serie.c
	gcc -c serie.c -g 
perso1.o:perso1.c
	gcc -c perso1.c -g 
bckg1.o:bckg1.c
	gcc -c bckg1.c -g 
bounding_box.o:bounding_box.c
	gcc -c bounding_box.c -g 
ES.o:ES.c
	gcc -c ES.c -g 

build: main.o snake/game.o term/screen.o
	gcc -o itg @flags main.o snake/game.o term/screen.o

main.o:
	gcc -c @flags main.c

snake/game.o:
	gcc -c @flags snake/game.c -o snake/game.o

term/screen.o:
	gcc -c @flags term/screen.c -o term/screen.o

clean:
	rm *.o ./*/*.o itg

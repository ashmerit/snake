all: build/snake


build/snake: build/main.o build/game.o build/snake.o build/fruit.o
	gcc -std=c23 -o $@ build/main.o build/game.o build/snake.o build/fruit.o -lSDL3


build/main.o: src/main.c src/include/game.h
	gcc -std=c23 -o $@ -O3 -c src/main.c -Isrc/include -Wall -Wextra -fanalyzer

build/game.o: src/game.c src/include/game.h src/include/snake.h src/include/fruit.h
	gcc -std=c23 -o $@ -O3 -c src/game.c -Isrc/include -Wall -Wextra -fanalyzer

build/snake.o: src/snake.c src/include/snake.h
	gcc -std=c23 -o $@ -O3 -c src/snake.c -Isrc/include -Wall -Wextra -fanalyzer

build/fruit.o: src/fruit.c src/include/fruit.h
	gcc -std=c23 -o $@ -O3 -c src/fruit.c -Isrc/include -Wall -Wextra -fanalyzer


.PHONY: clean run
clean:
	rm build/*

run: build/snake
	./build/snake

#ifndef __GAME_H__
#define __GAME_H__



#include "snake.h"
#include "fruit.h"

enum SnakeGameState
{
	RUNNING,
	GAME_OVER
};

struct SnakeGame
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	enum SnakeGameState state;

	struct Fruit fruit;
	struct Snake snake;
};

void game_init(struct SnakeGame*);
void game_run(struct SnakeGame*);
void game_close(struct SnakeGame*);


#endif

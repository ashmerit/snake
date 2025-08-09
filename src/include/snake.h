#ifndef __SNAKE_H__
#define __SNAKE_H__


#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>

enum SnakeDirection
{
	RIGHT,
	UP,
	LEFT,
	DOWN
};

struct SnakeNode
{
	SDL_Point position;
	enum SnakeDirection direction;
};

struct Snake
{
	int length;
	struct SnakeNode* nodes;
};

void snake_init(struct Snake*);
void snake_move(struct Snake*);
void snake_append_body(struct Snake*);
void snake_render(struct Snake*, SDL_Renderer*);
void snake_destroy(struct Snake*);


#endif

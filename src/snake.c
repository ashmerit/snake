#include <SDL3/SDL_render.h>

#include "include/snake.h"


void snake_init(struct Snake* snake)
{
	snake->length = 1;

	snake->nodes = SDL_malloc(sizeof(struct SnakeNode) * snake->length);
	snake->nodes[0].position = (SDL_Point){ 0, 0 };
	snake->nodes[0].direction = RIGHT;
}

void snake_move(struct Snake* snake)
{
	for (int index = snake->length - 1; index > 0; index--)
	{
		snake->nodes[index] = snake->nodes[index - 1];
	}

	switch (snake->nodes[0].direction)
	{
		case RIGHT: snake->nodes[0].position.x++; break;
		case UP:    snake->nodes[0].position.y--; break;
		case LEFT:  snake->nodes[0].position.x--; break;
		case DOWN:  snake->nodes[0].position.y++; break;
	}
}

void snake_append_body(struct Snake* snake)
{
	snake->nodes = SDL_realloc(snake->nodes, ++(snake->length) * sizeof(struct SnakeNode));

	switch (snake->nodes[snake->length - 1].direction)
	{
		case RIGHT:
			snake->nodes[snake->length - 1].position = (SDL_Point){
    			snake->nodes[snake->length - 2].position.x - 1,
    			snake->nodes[snake->length - 2].position.y
    		};
		break;

		case UP:
			snake->nodes[snake->length - 1].position = (SDL_Point){
    			snake->nodes[snake->length - 2].position.x,
    			snake->nodes[snake->length - 2].position.y + 1
    		};
		break;

		case LEFT:
			snake->nodes[snake->length - 1].position = (SDL_Point){
    			snake->nodes[snake->length - 2].position.x + 1,
    			snake->nodes[snake->length - 2].position.y
    		};
		break;

		case DOWN:
			snake->nodes[snake->length - 1].position = (SDL_Point){
    			snake->nodes[snake->length - 2].position.x,
    			snake->nodes[snake->length - 2].position.y - 1
    		};
		break;
	}
}

void snake_render(struct Snake* snake, SDL_Renderer* renderer)
{
	for (int index = 0; index < snake->length; index++)
	{
		SDL_RenderFillRect(renderer, &(SDL_FRect){
			snake->nodes[index].position.x * 25.0f,
			snake->nodes[index].position.y * 25.0f,
			25.0f, 25.0f
		});
	}
}

void snake_destroy(struct Snake* snake)
{
	SDL_free(snake->nodes);
}

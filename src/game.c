#include <SDL3/SDL_init.h>
#include <SDL3/SDL_keycode.h>
#include <SDL3/SDL_timer.h>

#include "include/game.h"
#include "include/snake.h"
#include "include/fruit.h"


void game_init(struct SnakeGame* game)
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_CreateWindowAndRenderer(
		"Snake",
		800, 600,
		0,
		&game->window,
		&game->renderer
	);

	snake_init(&game->snake);
	fruit_init(&game->fruit, game->renderer);

	game->state = RUNNING;
}

void game_run(struct SnakeGame* game)
{
	bool running = true;
	Uint64 last_time = SDL_GetTicks();

	while (running)
	{
	    SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_EVENT_KEY_DOWN)
			{
				enum SnakeDirection* snake_dir = &game->snake.nodes[0].direction;

				switch (event.key.key)
			    {
					case SDLK_ESCAPE: running = false; break;
					case SDLK_Q: running = false; break;

					case SDLK_D:
    					if (*snake_dir != LEFT)
    				    {
      						*snake_dir = RIGHT;
      						last_time = SDL_GetTicks();
      						snake_move(&game->snake);
      				 	}
					break;

					case SDLK_W:
					    if (*snake_dir != DOWN)
    				    {
    						*snake_dir = UP;
    						last_time = SDL_GetTicks();
    						snake_move(&game->snake);
    					}
					break;

					case SDLK_A:
    					if (*snake_dir != RIGHT)
    				    {
    						*snake_dir = LEFT;
    						last_time = SDL_GetTicks();
    						snake_move(&game->snake);
    					}
                    break;

					case SDLK_S:
						if (*snake_dir != UP)
						{
							*snake_dir = DOWN;
							last_time = SDL_GetTicks();
							snake_move(&game->snake);
						}
					break;
				}
			}

			else if (event.type == SDL_EVENT_QUIT) running = false;
		}

		SDL_SetRenderDrawColor(game->renderer, 34, 35, 35, 255);
		SDL_RenderClear(game->renderer);

		if (game->state == RUNNING)
		{
			snake_move(&game->snake);

			SDL_Point snake_head_position = game->snake.nodes[0].position;
			for (int index = 1; index < game->snake.length; ++index)
			{
				if (snake_head_position.x == game->snake.nodes[index].position.x &&
					snake_head_position.y == game->snake.nodes[index].position.y)
				{
					game->state = GAME_OVER;
				}
			}

			if (snake_head_position.x < 0 || snake_head_position.y < 0 ||
				snake_head_position.x > 31 || snake_head_position.y > 23)
			{
				game->state = GAME_OVER;
			}

			if (snake_head_position.x == game->fruit.position.x &&
				snake_head_position.y == game->fruit.position.y)
			{
				fruit_randomize(&game->fruit);
				snake_append_body(&game->snake);
			}

			SDL_SetRenderDrawColor(game->renderer, 240, 246, 240, 255);
			snake_render(&game->snake, game->renderer);
			fruit_render(&game->fruit, game->renderer);
		}
		else if (game->state == GAME_OVER)
		{
			// Do game over related-stuff here
		}

		SDL_RenderPresent(game->renderer);
		SDL_Delay(60);
	}
}

void game_close(struct SnakeGame* game)
{
	snake_destroy(&game->snake);
	fruit_destroy(&game->fruit);
	SDL_DestroyRenderer(game->renderer);
	SDL_DestroyWindow(game->window);

	SDL_Quit();
}

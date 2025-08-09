#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>

#include "include/fruit.h"


void fruit_init(struct Fruit* fruit, SDL_Renderer* renderer)
{
	fruit_randomize(fruit);

	SDL_Surface* fruit_surface = SDL_LoadBMP("./assets/fruit.bmp");
	fruit->texture = SDL_CreateTextureFromSurface(renderer, fruit_surface);
	SDL_DestroySurface(fruit_surface);
}

void fruit_randomize(struct Fruit* fruit)
{
	fruit->position = (SDL_Point){ SDL_rand(32), SDL_rand(24) };
}

void fruit_render(struct Fruit* fruit ,SDL_Renderer* renderer)
{
    SDL_FRect destination_rect = {
		(float)(fruit->position.x) * 25.0f,
		(float)(fruit->position.y) * 25.0f,
		25.0f, 25.0f,
	};

	SDL_RenderTexture(renderer, fruit->texture, nullptr, &destination_rect);
}

void fruit_destroy(struct Fruit* fruit)
{
    SDL_DestroyTexture(fruit->texture);
}

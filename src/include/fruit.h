#ifndef __FRUIT_H__
#define __FRUIT_H__


#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>

struct Fruit
{
	SDL_Point position;
	SDL_Texture* texture;
};

void fruit_init(struct Fruit*, SDL_Renderer*);
void fruit_randomize(struct Fruit*);
void fruit_render(struct Fruit*, SDL_Renderer*);
void fruit_destroy(struct Fruit*);


#endif

#include "include/game.h"


int main()
{
	struct SnakeGame snake_game = {};
	game_init(&snake_game);
	game_run(&snake_game);
	game_close(&snake_game);

	return 0;
}

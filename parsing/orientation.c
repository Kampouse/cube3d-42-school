#include "../cube.h"

void apply_radiant(t_game *game)
{
	const double pi = 3.14159265359 * 2;
	game->player->direction  = game->player->direction *  (pi / 360);

}

void player_direction(t_game *game)
{
	if (game->player->orientation == 'N')
	{
		game->player->direction = 0;
	}
	else if (game->player->orientation == 'E')
	{
		game->player->direction = degToRad(88.3);
	}
	else if (game->player->orientation == 'W')
	{
		game->player->direction = degToRad(266);

	}
	else if (game->player->orientation == 'S')
		game->player->direction = degToRad(176.9);

}

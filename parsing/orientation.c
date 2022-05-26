#include "../Include/cube.h"

void	apply_radiant(t_game *game)
{
	const double pi = 3.14159265359 * 2;
	game->player->direction  = game->player->direction * (pi / 360);
}

void	player_direction(t_game *game)
{
	if (game->player->orientation == 'E')
	{
		game->player->direction = degToRad(360);
		game->ray->dx = 1;
		game->ray->dy = 0;
	}
	else if (game->player->orientation == 'N')
	{
		game->player->direction = degToRad(90);
		game->ray->dx = 0;
		game->ray->dy = -1;
	}
	else if (game->player->orientation == 'W')
	{
		game->player->direction = degToRad(180);
		game->ray->dx = -1;
		game->ray->dy = 0;
	}
	else if (game->player->orientation == 'S')
	{
		game->player->direction = degToRad(270);
		game->ray->dx = 0;
		game->ray->dy = 1;
	}
}

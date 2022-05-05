#include "../Include/cube.h"

void  resize_map(t_game *game)
{
	char	**new_map;
	int		len;
	int		iter;

	iter = game->map_data->start;
	len = 0;
	while (game->map[iter] && !(only_space(game->map[iter])))
	{
		iter++;
		len++;
	}
	game->map_data->last = len;
	new_map = ft_calloc(len + 1,sizeof(new_map));
	iter = game->map_data->start;
	len = 0;
	while (game->map[iter] && !(only_space(game->map[iter])))
	{
		new_map[len] = ft_strdup(game->map[iter]);
		iter++;
		len++;
	}
	freelist(game->map);
	game->map = new_map;
}


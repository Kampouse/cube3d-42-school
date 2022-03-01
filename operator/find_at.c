#include "../cube.h"




int find_at(t_game *map, long x_pos, long y_pos)
{

const	int scale =	map->player->scale; 

	
	 x_pos =  x_pos / scale;
	 y_pos =  y_pos / scale;

	 x_pos = floor(x_pos);
	 y_pos = floor(y_pos);
	printf("%c\n",map->map[y_pos][x_pos]);
return (0);
}

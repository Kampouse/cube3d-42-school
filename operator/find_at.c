#include "../cube.h"


int	isRayFacingDown(float angle)
{
	return (angle > 0 && angle < M_PI);
}

int	isRayFacingUp(float angle)
{
	return (!isRayFacingDown(angle));
}

int	isRayFacingRight(float angle)
{
	return (angle < 0.5 * M_PI || angle > 1.5 * M_PI);
}

int	isRayFacingLeft(float angle)
{
	return (!isRayFacingRight(angle));
}

double normalise_angle(double angle)
{
	angle = remainder(angle,TWO_PI);
	if(angle < 0)
		angle = TWO_PI + angle;
	return(angle);
}

int print_pos(t_game *map, long  x_pos,long y_pos)
{
	printf("%ld %ld\n",(x_pos + 64) /64, (y_pos + 64) /64);
	printf("%s\n",map->map[(y_pos + 64) /64]);
	printf("%c\n",map->map[(y_pos + 64) /64][(x_pos + 64) /64]);
}


int cast_ray(t_game *game)
{
	const float  deg_to_rad =  2 * M_PI / 360;
	game->player->x_pos  *= 64;
	game->player->y_pos  *= 64;
	const float  start_cell_x   = ((float)game->player->x_pos / 64);
	const float  start_cell_y   = ((float)game->player->y_pos / 64);
	const float  sin_theta  = cos((90 - game->player->direction) *  deg_to_rad);
	const float  cos_theta   = cos(game->player->direction * deg_to_rad);
	const float	 delta_dist_x = fabs(1  / cos_theta);
	const float	 delta_dist_y = fabs(1  / sin_theta);
	const float  x_step =  delta_dist_x  * 64;
	const float  y_step =  delta_dist_y  * 64;
	float side_step_x;
	float side_step_y;
	int x_dir;
	int y_dir;
	int walk_x  = start_cell_x;
	int walk_y = start_cell_y;

	printf("%d\n",walk_x);
	printf("%f\n",game->player->direction);
	side_step_x = ( start_cell_x + 1.0 - game->player->x_pos) *  delta_dist_x;
	side_step_y = (start_cell_y  +  1.0 - game->player->y_pos) * delta_dist_y;	
	if (game->player->direction  < 180) 
	{
		y_dir = -1;
		side_step_y = (game->player->y_pos  - start_cell_y) * delta_dist_y;
	}
	else
		 y_dir = 1;
	if (game->player->direction > 90 && game->player->direction < 270) 
	{
		side_step_x = ( start_cell_x  - game->player->x_pos) *  delta_dist_x;
		x_dir = -1;
	}
	else
	{
		printf("hello\n");
		x_dir = 1;
	}
	while(1)	
	{

		if(side_step_x < side_step_y)
		{
			side_step_x += delta_dist_x;
			walk_x += x_dir;
		}
		else
		{
			side_step_y += delta_dist_y;
			walk_y += y_dir;
		}

			printf("%c", game->map[walk_y][walk_x]);
		if(game->map[walk_y][walk_x] == '1')
		{
			printf("found");
			break;
		}





	}

return (0);
}

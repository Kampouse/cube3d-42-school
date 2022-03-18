#include "../cube.h"



int raycaster(t_game *game, t_image image, float angle)
{
	float dy ;
	float dx ;
	float max_value;
	int inc;
	const float delta_x = cos(angle) / 1;
	const float delta_y = sin(angle);

	dx = cos(degToRad(angle)) * delta_x -  sin(degToRad(angle)) * delta_y;
	dy = sin(degToRad(angle)) * delta_x + cos(degToRad(angle)) * delta_y;
	max_value = fmax(fabs(dx), fabs(dy));
	inc = 1;
	dx/= max_value;
	dy/= max_value;
			while(game->map[ (int)(game->player->y_pos + (dy * inc)) >> 5][(int)(game->player->x_pos + (dx * inc)) >> 5] != '1')
				inc+=1;		
	draw_line(&image, game->player->x_pos, game->player->y_pos, game->player->x_pos  + (dx * inc),game->player->y_pos  + (dy * inc));
	//could return the location of where it hit ...
	return(0);
}


int ray_fov(t_game *state,t_image image ,float angle,int inc)
{
	float	 until ;
	float	plus;

	plus = 0;
	until = state->player->direction +  PI / 6;
		while(state->player->direction + plus < until)
	{
			raycaster(state, image,	 state->player->direction + plus );
			raycaster(state, image, state->player->direction - plus );
			plus += PI / 84;
	}
}


#include "../cube.h"



int raycaster(t_game *game ,t_image image,float angle)
{

	float dy ;
	float dx ;
	float max_value;
	int inc;
	const float delta_x = sin(game->player->direction) / 1;
	const float delta_y = cos(game->player->direction);

	dx = cos(degToRad(game->player->direction)) * delta_x -  sin(degToRad(game->player->direction)) * delta_y;
	dy = sin(degToRad(game->player->direction)) * delta_x + cos(degToRad(game->player->direction)) * delta_y;
	max_value = fmax(fabs(dx), fabs(dy));
	inc = 1;
	dx/= max_value;
	dy/= max_value;
			while(game->map[ (int)(game->player->y_pos  + (dy * inc)) >> 5][(int)(game->player->x_pos + (dx * inc)) >> 5] != '1')
				inc++;		
			draw_line(&image, game->player->x_pos, game->player->y_pos, game->player->x_pos  + (dx * inc),game->player->y_pos  + (dy * inc));
	//	printf("%f",yintersect);;
	//long yintersect =    game->player->y_pos +  (10* sin(degToRad(game->player->direction)));;
	//printf("%ld %ld" ,  xintersect, yintersect);






		// finding   vector_y;
	


/*
			//printf("%f",sqrt((32 * 32) + (32 * 32)));

		vector_x = 	(int)round(45 *  cos(degToRad(game->player->direction)));
		vector_y= 	(int)round(45 * sin(degToRad(game->player->direction)));
			
vec_acc_y = vector_x;
vec_acc_x =  vector_y;
				 
			if(vector_x < 0)
				walk_x_unit  = -walk_x_unit ;
			if(vector_y < 0)
				walk_y_unit  = -walk_y_unit ;


		while (1)
	{
		if (vec_acc_x  < vec_acc_y)
		{
			
			vec_acc_x = vec_acc_x + vector_x;
			 walk_location_x += walk_x_unit;
		}
		else
		{
			vec_acc_y = vec_acc_y + vector_y;
			 walk_location_y += walk_y_unit;
		}
		if (game->map[walk_location_y][walk_location_x] == '1')
		{
	//draw_line(&image,game->player->x_pos * 32,game->player->y_pos * 32,walk_location_x * 32, walk_location_y * 32);
			printf("%d %d\n %s \n",walk_location_x,walk_location_y, game->map[walk_location_y]);
					break;

		}
	*/

	}

		//printf("%s \n",game->map[walk_location_y]);
		//printf("%d %d \n",walk_location_y,walk_location_x);
	//	printf("move in x :%f move in y :%f \n",vector_x,vector_y);
	//vector =  tan(game->player->direction) * game->player->x_pos / game->player->y_pos ;
	//printf("%f\n",(vector  * game->player->x_pos));




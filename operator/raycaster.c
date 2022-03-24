#include "../cube.h"


float distance(ax, ay, bx, by, ang)
{
	return cos(ang)*(bx-ax)-sin(ang)*(by-ay);
}

int raycaster2d(t_game *game, t_image image, t_ray ray)
{
	int inc;

	inc = 0;
	ray.delta_y = cos(ray.angle) / 1;
	ray.delta_x = sin(ray.angle);
	ray.dx = cos(degToRad(ray.angle)) * ray.delta_x -  sin(degToRad(ray.angle)) * ray.delta_y;
	ray.dy = sin(degToRad(ray.angle)) * ray.delta_x + cos(degToRad(ray.angle)) * ray.delta_y;
	ray.max_value = fmax(fabs(ray.dx), fabs(ray.dy));
	ray.dx/= ray.max_value;
	ray.dy/= ray.max_value;
	while(game->map[ (int)(game->player->y_pos + (ray.dy * inc)) / game->player->scale][(int)(game->player->x_pos + (ray.dx * inc))  / game->player->scale] != '1')
		inc +=1;		
	draw_line(&image, game->player->x_pos, game->player->y_pos, game->player->x_pos + (ray.dx * inc), game->player->y_pos + (ray.dy * inc));
	return(0);
}

int ray_fov(t_game *state,t_image image ,float angle,int inc)
{
	float	until;
	float	plus;
	t_ray	ray;


	plus = 0;
	until = state->player->direction +  PI / 6;
		while(state->player->direction + plus < until)
	{
		ray.angle = state->player->direction + plus;
			raycaster2d(state, image, ray);
		ray.angle = state->player->direction - plus;
			raycaster2d(state, image, ray );
			plus += PI / 84;
	}
}
int raycaster3d(t_game *game, t_image image, t_ray ray,int scree_strip)
{

	int inc;

	inc = 0;
	ray.delta_y = cos(ray.angle) / 1;
	ray.delta_x = sin(ray.angle);
	ray.dx = cos(degToRad(ray.angle)) * ray.delta_x -  sin(degToRad(ray.angle)) * ray.delta_y;
	ray.dy = sin(degToRad(ray.angle)) * ray.delta_x + cos(degToRad(ray.angle)) * ray.delta_y;
	




	ray.max_value = fmax(fabs(ray.dx), fabs(ray.dy));
	ray.dx/= ray.max_value;
	ray.dy/= ray.max_value;


		float accx = ray.dx;
		float accy = ray.dy;
		accx = 0;
		accy = 0;
	while(game->map[ (int)(game->player->y_pos + accy) / game->player->scale][(int)(game->player->x_pos +  accx)  / game->player->scale] != '1')
	{
		accx += ray.dx;
		accy += ray.dy;
	}
		inc +=1;		

	draw_line(&image, game->player->x_pos, game->player->y_pos, game->player->x_pos + accx, game->player->y_pos +accy);
	//printf("%f %f\n",((game->player->x_pos - accx) /1080) * 1080 ,(game->player->y_pos - accy) / 32 );
	float posx ;
	float posy ;

		posx = accx;	
		posy = accy;	
	posx*=posx;	
	posy*=posy;	

	float dist  = sqrt(posx + posy);

	float distb = fabs(game->player->x_pos - (game->player->x_pos + accx)); 
	float dista = fabs(game->player->y_pos - (game->player->y_pos + accy)); 
 
		float height =  32 /   dist *  277;
		if(height > 1080)
	{
		height =  1080 ;
	}
			

		draw_line(&image,500 + scree_strip,72,500 + scree_strip,height + 300);

		printf("%f \n",game->player->x_pos * height);
	return(0);
}

//printf("%f\n",distance( game->player->x_pos + (ray.dx * inc), game->player->y_pos, game->player->x_pos + (ray.dx * inc), game->player->y_pos + (ray.dy * inc),ray.angle ));

int ray_fov3d(t_game *state,t_image image ,float angle,int inc)
{
	float	until;
	float	plus;
	int	scree_strip;
	t_ray	ray;
	int step = 0;
		plus = 0;
		until = state->player->direction +  PI / 3;
		while(state->player->direction + plus < until)
	{
			ray.angle = state->player->direction + plus;
					raycaster3d(state, image, ray, step);
					step+= 16;
			plus += PI  / 84;
	}
}

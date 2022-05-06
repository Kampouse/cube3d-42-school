#include "../Include/cube.h"


int	isRayFacingUp(float angle)
{
	if(angle < 270 && angle > 90)
		return(0);
	else 
		return(1);
}
int	isRayFacingDown(float angle)
{
	return (!isRayFacingUp(angle));
}

int	isRayFacingRight(float angle)
{
	if(angle >= 270)
		return(0);
	return(1);
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

int cast_ray(t_game *game,t_image *image)
{
	float x_pos = game->player->x_pos;
	float y_pos = game->player->y_pos;
	
	float second_x;
	float second_y;
	float dir;
	float y_dir;
	float len;
	int step_x;
	int step_y;
	unsigned int mapx;
	unsigned int mapy;
	float plane_x = 0;
	float plane_y = 0.66;
	dir = 1;
	//second_x = floor(x_pos - sin(degToRad(60) - 0.01) * 32);
	//second_y = floor(y_pos + cos(degToRad(60) - 0.01) * 32);
	//printf("%f (%f) lol", second_x - x_pos,roundf((second_y  - y_pos) / 32));
	// determiner sur quel iterateur faire la comparaison positif negatif ect kk
	//second_y = (second_y - y_pos);
	//second_x = (second_x - x_pos);
	//printf("(%d)",abs(1 / second_y));
	step_x = 0;
	step_y= 0 ;
	int inc = 1;
	//printf("%f))))\n",second_y );
	while(inc  <  1080)
	{
		inc+= 1;
		double camera_x  = 2 * inc   / (double) 1080  - 1;
		//printf("%f",camera_x);
		double  ray_dirx = 	dir + plane_x * camera_x;
		double  ray_diry = 	0 + plane_y * camera_x;
		double side_dist_x;
		double side_dist_y;
		double  deltax =	 sqrt(1 + (pow(ray_diry,2) / pow(ray_dirx,2)));
		double  deltay =	  sqrt(1 + (pow(ray_dirx,2) / pow(ray_diry,2)));
		int stepx;
		int stepy;
		//printf("%f-\n",ray_dirx);
		//printf("%f-\n",ray_diry);
		mapx = (int)x_pos; 
		mapy = (int)y_pos; 
		if(ray_dirx < 0)
		{
			side_dist_x = ( x_pos - mapx  ) *  deltax;
			step_x = -1;
		}
		else
		{
			step_x = 1;
			side_dist_x = (mapx  + 1 - x_pos) *  deltax;
		}
		if(ray_diry < 0)
		{
			side_dist_y = ( y_pos - mapy) *  deltay;
			step_y = -1;
		}
		else
		{
			step_y = 1;
			side_dist_y = (mapy  + 1 - y_pos) *  deltay;
		}
		while(1)
		{
			if(side_dist_x < side_dist_y)
			{
				side_dist_x += deltax;
				mapx += step_x;
			}
			else
			{
				side_dist_y +=  deltay;	
				mapy += step_y;
			}
			if(game->map[mapy][mapx]  == '1')
			{

				break;
			}
		}
		draw_line(image,x_pos * 32,y_pos * 32,(mapx)  * 32,(mapy)  * 32);
		printf("%d %d\n",mapx,mapy);
	}
//	mapy =	 (int)  ((y_pos + second_y ) / 32)  * step_y;
	//mapx =	 (int)  ((x_pos + second_x ) / 32)  * step_x;
		/*
	while(mapy < mapx)
		{
			draw_line(image,x_pos,y_pos,mapx * 32,mapy * 32);
			mapy++;
		}
	if(mapx < mapy)
		{
		mapx++;
		}

		draw_line(image,x_pos,y_pos,mapx * 32,mapy);
	step_x++;
	step_y++;



		
		printf(" -- %d,%d\n",mapx,mapy);
	}



	if(isRayFacingUp(game->player->direction))	
	{
		 second_y = (y_pos / 32) * (32) + 64;
	}
	if(isRayFacingDown(game->player->direction))
	{
		 second_y = (round((y_pos / 32)) * (32));
	}
	float xa = (32);
	second_x =  x_pos + xa   + (y_pos - second_y) / tan(game->player->direction); 
	second_x =  floor(second_x / 32) ;
	second_y = floor(second_y / 32);
*/
	//printf("%f %f %f",second_x,second_y,xa);
	//printf("y -- :(%d)",(int)(second_y) /32);
	//printf(" x_pos (%d)",(int)second_x /32);
	//// printf("(%c)\n",game->map[(int)game->player->y_pos + (int)(second_y / 32)][(int)x_pos / 64]);
	// printf("(%d\n)",(((int)second_y * 3 ) / 32) * 32);

			// break;
		//
		return (0);
}

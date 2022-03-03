#include "../cube.h"





long normalise_angle(long angle)
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


int find_at(t_game *map, long x_pos, long y_pos,int time)
{
	long x_with_angle;

	int x_intersect;
	int y_intersect;
	int side = 0;
	int x_step;
	int y_step;
	double ray_dir_x = cos(map->player->direction);	
	double ray_dir_y = sin(map->player->direction);	
	long  x_unit = sqrt(1 +  (ray_dir_y * ray_dir_y) / (ray_dir_x * ray_dir_x));
	long  y_unit = sqrt(1 +  (ray_dir_x * ray_dir_x) / (ray_dir_y * ray_dir_y));
	int mapx;
	int mapy;
	int times;
	long side_disty;
	long side_distx;
	int hit = 0;
	time = 0;
	mapx = (int)map->player->x_pos;
	mapy = (int)map->player->y_pos;
	if (ray_dir_x < 0)
	{
		x_step = -1;	
		side_distx = (x_pos - mapx) * x_unit;
	}
	else
	{
		x_step = 1;	
		 side_distx = (mapx  + 1.0 - x_pos) * x_unit;
	}
	if (ray_dir_y < 0)
	{
		y_step = -1;	
		side_disty = (y_pos - mapy) * y_unit;
	}
	else
	{
		y_step = 1;	
		side_disty = (mapy + 1.0  - y_pos) * y_unit;
	}
	while(hit == 0 && time < 25)
	{
		if( side_distx <  side_disty) 
		{
			side_distx +=  x_unit;
			mapx += x_step;
			side = 0	;
		}
		else
		{
			side_disty += y_unit;
			mapy += y_step;
			side = 1;
		}

		time++;
		if(map->map[mapy][mapx] == '1')
		{
			printf( "%c",map->map[mapy][mapx]);
			break;	
		}

			printf( "%c",map->map[mapy][mapx]);
	}




	//y_intersect = floor(y_pos /64) * 64;
// may require something moar;
	//y_intersect += 64;
	//x_intersect  = x_pos + (y_intersect  - x_pos) / tan(map->player->direction);
		//	contact_y =  y_pos / 64 * (64)  - 1 ;
		//contact_x  =  x_pos + (y_pos - contact_y) / tan(90);
	//printf("%c\n --",map->map[contact_y / 64][contact_x / 64]);
	//printf("%ld %ld\n --",contact_y / 64, contact_x / 64);

		return (0);
}

#include "../cube.h"



int print_pos(t_game *map, long  x_pos,long y_pos)
{
	printf("%ld %ld\n",(x_pos + 64) /64, (y_pos + 64) /64);
	printf("%s\n",map->map[(y_pos + 64) /64]);
	printf("%c\n",map->map[(y_pos + 64) /64][(x_pos + 64) /64]);
}


int find_at(t_game *map, long x_pos, long y_pos,int time)
{
	long x_with_angle;

	long contact_y;	
	long contact_x;	
	
		contact_y =  y_pos / 64 * (64)  - 1 ;
		contact_x  =  x_pos + (y_pos - contact_y) / tan(90);
		
	printf("%c\n --",map->map[contact_y / 64][contact_x / 64]);
	printf("%ld %ld\n --",contact_y / 64, contact_x / 64);
		return (0);
}

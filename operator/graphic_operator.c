#include "../cube.h"

uint32_t color_to_rgb(int a ,int r , int g , int b)
   {
	uint32_t color;
	const int ra = r & 0xFF;
	const int ga = g & 0xFF;
	const int ba = b & 0xFF;
	const int aa = a & 0xFF;
	(void)aa;
		color = 0xFF | (ra << 8) | (ga << 16) | ( ba << 24);
      return color;
   }






void draw_line(t_image *image,int x0, int y0, int x1, int y1) 
	{
	  int dx = abs(x1-x0);
	  int dy = abs(y1-y0);
	  int sx;
	  int sy;
	  int err;
	  int e2; 

	if (x0 <  x1)
		sx = 1;
	else 
		sx = -1;
	if (y0 <  y1)
		sy = 1;
	else 
		sy = -1;
	if(dx > dy)
		err = dx / 2;
	else 
		err = -dy / 2;
	  while(1)
	{
		if(x0 < 0)
			x0 = 0;
		if(y0 < 0)
			y0 = 0;


		mlx_putpixel(image->image,x0,y0,color_to_rgb(0,0,0,150));
		if (x0==x1 && y0==y1)
				break;
		e2 = err;
		if (e2 >-dx)
	{
				err -= dy; 
			x0 += sx; 
		}
		if (e2 < dy) 
		{
				err += dx;
				y0 += sy; 
		}
	  }
}





int square_shape(t_image *image,int x_pos, int y_pos,uint32_t color)
{

int inc;
int cin;

inc = 0;
cin = 0;

	while (cin < 32)
	{
		while (inc < 32) 
		{
				mlx_putpixel(image->image, x_pos + inc, y_pos + cin,color);
			inc++;
		}
		inc = 0;
		cin++;
	}
return (0);
}
void draw_map(t_game *state, t_image image, int scale)
{
	int inc;
	int cin;
	int stepx;
	int stepy;
	
	inc = 0;
	cin = 0;
	stepx = 0;
	stepy  = 0;
	while (state->map[cin])
	{	
		while (state->map[cin][inc])
		{
			if (state->map[cin][inc] == '1')
				square_shape(&image, stepx, stepy, color_to_rgb(0, 0,0 ,0));
			else
			{
				square_shape(&image, stepx, stepy, color_to_rgb(0 ,150, 255, 0));
				draw_line(&image,stepx,stepy,stepx + scale,stepy);
				draw_line(&image,stepx,stepy,stepx,stepy + scale);

			}
			inc++;
			stepx+= scale;
		}
		stepx = 0;
		inc = 0;
		stepy += scale;
		cin++;
	}
}

float degToRad(float a)
{
	return a*M_PI/180.0;
}





#include "libft/libft.h"
#include "minilibx/mlx.h"
#include "stdio.h"
#include "solong.h"
#include "stdlib.h"


int close_win(int keycode, screen *state)
{
printf("you have not  pressed %d \n",keycode);
if(keycode == 257)
{
	printf("session destroyed");
	mlx_destroy_window(state->mlx,state->win);
	exit(0);
}

return(0);
}
int display_image(screen *state,int x,int y)
{
void *img; char *image = "./assets/floor.xpm"; int width; int height; img =  mlx_xpm_file_to_image(state->mlx,image,&width,&height); mlx_put_image_to_window(state->mlx,state->win,img,x,y); return (0); }
int main(void)
{
screen state;
int i = 0;

	state.mlx = mlx_init();
	state.win = mlx_new_window(state.mlx,1900,1080,"help"); 

		display_image(&state,650,650);
		while(i < 1900)
		{
	
			display_image(&state,i,600);
			display_image(&state,i,655);
			i += 89;
		
		
		}
		mlx_key_hook(state.win,close_win,&state);
	mlx_loop(state.mlx);
}

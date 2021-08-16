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
int display_image(screen *state)
{
void *img;
char *image = "./Kamp.xpm";
int width;
int height;
img =  mlx_xpm_file_to_image(state->mlx,image,&width,&height);

mlx_put_image_to_window(state->mlx,state->win,img,600,600);
return (0);
}
int main(void)
{
screen state;


	state.mlx = mlx_init();
	state.win = mlx_new_window(state.mlx,1900,1080,"help"); 
		display_image(&state);
		mlx_key_hook(state.win,close_win,&state);
	mlx_loop(state.mlx);
}

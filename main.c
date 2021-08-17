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




int display_image(screen *state,int x,int y,int image)
{
const char images[][20] = {"./assets/player.xpm", "./assets/floor.xpm"};
	void *img;
int width;
int height;
img = mlx_xpm_file_to_image(state->mlx, (char *)images[image], &width, &height);
mlx_put_image_to_window(state->mlx, state->win,img,x,y);
return (0);
}

int main(void)
{
screen state;
int i = 0;
int j = 0;
const int width = 1900;
const int height = 1080;

	state.mlx = mlx_init();
	state.win = mlx_new_window(state.mlx,width,height,"help"); 
while(j < 1080)
{
		while(i < 1900)
		{
			display_image(&state,i,j, i % 2);
			i += 89;
		}
		i = 0;
		j += 55;
}

	mlx_key_hook(state.win,close_win,&state);
	mlx_loop(state.mlx);
}

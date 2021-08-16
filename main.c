#include "libft/libft.h"
#include "minilibx/mlx.h"
#include "stdio.h"
#include "solong.h"



int key_press(int keycode, screen *state)
{
printf("you have not  pressed %d \n",keycode);
if(keycode == 257)
{
	printf("session destroyed");
	exit(0);
}

return(0);
}
int main(void)
{
screen state;

	state.mlx = mlx_init();
	state.win = mlx_new_window(state.mlx,1900,1080,"help"); 
	mlx_key_hook(state.win,key_press,&state);
	mlx_loop(state.mlx);
}

#include "libft/libft.h"
#include "get_next_line.h"
#include "minilibx/mlx.h"
#include "stdio.h"
#include "solong.h"
#include "stdlib.h"

int display_image(screen *state,int x,int y,int image)
{
const char images[][20] = {"./assets/player.xpm", "./assets/floor.xpm"};
	void *img;
int width;
int height;
img = mlx_xpm_file_to_image(state->mlx, (char *)images[image], &width, &height);
if(image == 0)
{
mlx_put_image_to_window(state->mlx, state->win,img,state->player_x,state->player_y);
free(img);
return (0);
}

mlx_put_image_to_window(state->mlx, state->win,img,x,y);
return (0);
}

int move_image(int keycode,void *state)
{
	display_image(state,0,0,0);

	return(0);
}

int display_backgroud(screen *state)
{
int j;
int i;
j = 0;
i = 0;
while(j < 1080)
{
		while(i < 1900)
		{
			display_image(state,i,j,1);
			i += 89;
		}
		i = 0;
		j += 55;
}
return (0);
}

int close_win(int keycode, screen *state)
{
int x;

if(keycode > 0)
{
	state->player_x+= 2;
	x = state->player_x;
	display_backgroud(state);
	display_image(state,x,0,0);

}
		if(keycode == 257)
{
	printf("session destroyed");
	mlx_destroy_window(state->mlx,state->win);
	exit(0);
}

return(0);
}

t_list  mapcreator(fd)
{

char *string;
t_list lst;
get_next_line(fd,&string);
lst = *ft_lstnew(string);

ft_strlen("help");
  
return (lst);
}



int main(void)
{
int  fd;
char *line;
t_list lst;
fd = open("./map.ber",O_RDONLY);
get_next_line(fd,&line);
 lst = *ft_lstnew(line);
printf("%s",line);
//const int width = 500;
//const int height = 500;

//	state.mlx = mlx_init();
//	state.win = mlx_new_window(state.mlx,width,height,"help"); 
//	state.player_x = 0;
//	state.player_y = 0;
//	display_backgroud(&state);
//	display_image(&state,0,0,0);
//	mlx_key_hook(state.win,close_win,&state);
//	mlx_loop_hook(state.mlx,close_win,&state);
//	mlx_loop(state.mlx);
// 1 4 17 moving direction;
}

#include "cube.h"
#include "stdio.h"
#include "stdlib.h"
#include "utils/get_next_line.h"
#include "utils/libft/libft.h"
#include "MLX/include/MLX42/MLX42.h"


int draw_grid(t_image image);
void	free_list(t_dlist *head)
{
	t_dlist	*next;

	if (head != NULL)
	{
		next = head->next;
		free(head->content);
		free(head);
		free_list(next);
	}
}
t_dlist	*verif(t_dlist *map)
{
	int	flag;

	flag = 0;
	if (!map)
	{
		ft_putstr_fd("Error:could not read map\n", 1);
		exit(0);
	}
	flag += assert(verif_len(*map), "Error: len incorrect\n");
	flag += assert(verif_wall(*map), "Error: incorrect wall\n");
	flag += assert(verif_param(*map, 'P'), "Error: wrong number of Player\n");
	flag += assert(verif_param(*map, 'E'), "Error: wrong number of exit\n");
	flag += assert(verif_param(*map, 'C'), "Error: wrong nbr of collectibe\n");
	flag += assert(verif_map_content(*map), "Error: wrong element in the map\n");
	if (flag > 0)
	{
		free_list(map);
		exit(0);
	}
	return (map);
}

void	hook(void *param)
{
	t_mlx *mlx;
	t_game *state;
	state = param;

	const float delta_y = cos(state->player->direction) / 1;
	const float delta_x = sin( state->player->direction);
	const float	dx = cos( state->player->direction) * delta_x -  sin(state->player->direction) * delta_y;
	const float dy = sin(degToRad(state->player->direction)) * delta_x + cos(degToRad(state->player->direction)) * delta_y;
	int mouse_x;
	int mouse_y;
	mlx = state->mlx;
	//////////////////mlx_set_mouse_pos(mlx,500,500);
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{
		exit(0);
	}
if (mlx_is_key_down(mlx, MLX_KEY_A))
	{
	state->player->direction +=	 0.05;
	if(state->player->direction   >= 2 * PI)
		{
			state->player->direction = 0;
		}
		draw_map(state,state->image, 32);
		draw_grid(state->image);
		ray_fov(state, state->image,0);
	}
if (mlx_is_key_down(mlx, MLX_KEY_R))
	{
		state->player->x_pos+=delta_x * 3;
		state->player->y_pos+=delta_y * 3;


	draw_map(state,state->image, 32);
	draw_grid(state->image);
	ray_fov(state, state->image,0);
	}
if (mlx_is_key_down(mlx, MLX_KEY_H))
	{
		state->player->x_pos-=delta_x * 3;
		state->player->y_pos-=delta_y * 3;


	draw_map(state,state->image, 32);
	draw_grid(state->image);
	ray_fov(state, state->image,0);
	}
if (mlx_is_key_down(mlx, MLX_KEY_T))
	{
		state->player->direction-= 0.05;
		if(state->player->direction  <= 0)
			state->player->direction = PI *  2;
	draw_map(state,state->image, 32);
	draw_grid(state->image);
	ray_fov(state, state->image,0);
	}
}


int draw_grid(t_image image)
{

	int inc;
	int cin;
	inc  = 32;
	cin  = 32;
	while(inc < 1000)
	{

		draw_line(&image,inc,1,inc,1000);
		inc+= 32;
	}
	while(cin < 1000)
	{
		draw_line(&image,cin - 1000,cin,1000,cin);
		cin+= 32;
	}





}


int	main(int argc, char *argv[])
{

	(void)argv;
	(void)argc;
	t_game		*state;
	t_image image;
	state = malloc(sizeof(t_game));
	state->player = malloc(sizeof(t_player));
	state->player->scale = 32;
	state->map_data  = init_map();
	state->map = map_init(mapcreator("map.cub"));
	if (parsing(state,0) != 0 || parse_location(state,0,0) != 0)
	{
			printf("an erro as occured \n");
			//freelist(state->map);
			//delete_texture(state->map_data);
			//free(state->map_data);
			//free(state->player);
			//free(state);
		return (0);	
	}
	resize_map(state);
	player_direction(state);
	int time;
	time = 10;
	state->player->x_pos = (state->player->x_pos ) * state->player->scale;
	state->player->y_pos = (state->player->y_pos)  * state->player->scale;

	//cast_ray(state);
	state->mlx = mlx_init(1920, 1080, "MLX42", 0);
	image.image = mlx_new_image(state->mlx,1000,1080);

	//g_img = mlx_new_image(mlx, 128, 128);
	//ft_memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	//mlx_image_to_window(mlx,g_img,100,100);
	//mlx_loop_hook(mlx, &hook, mlx);
	//
	//
	t_mlx_inst *element;
	// element = mlx_image_to_window(state->mlx,image.image,-100,-200);
	state->image = image;
	draw_map(state,image, 32);
	draw_grid(image);
	ray_fov(state, image,0);
	mlx_image_to_window(state->mlx, image.image, 0, 0);
	mlx_loop_hook(state->mlx, &hook, state);
	mlx_loop(state->mlx);
	//mlx_terminate(state->mlx);
	//mlx_terminate(state->mlx);
		//printf("%ld -- \n",state->player->direction);
		//find_at(state,100,300);
		//freelist(state->map);
		//delete_texture(state->map_data);
		//free(state->player);
		//free(state);
	return(0);
		//mlx_new_window(state.mlx,100,100,"helo");
		//mlx_loop(state.mlx);
	//mlx_loop_hook(state.mlx, render_player, &state);
	//mlx_hook(state.win, 2, (1L << 0), render_cycle, &state);
	//mlx_hook(state.win, 17, 0, exit_please, &state);
	//mlx_do_sync(state.mlx);
}

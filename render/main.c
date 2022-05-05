#include "../Include/cube.h"
#include "stdio.h"
#include "stdlib.h"

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

	mlx = state->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		exit(0);
if (mlx_is_key_down(mlx, MLX_KEY_A))
	{
	state->player->direction +=	 0.120;
	if(state->player->direction   >= 2 * PI)
			state->player->direction = 0;
		draw_map(state,state->image, state->player->scale);
		ray_fov(state, state->image,state->player->direction,0);
		//ray_fov3d(state,state->image, state->player->direction,0);
	}
if (mlx_is_key_down(mlx, MLX_KEY_R))
	{
		state->player->x_pos+=delta_x *2;
		state->player->y_pos+=delta_y * 2;
		draw_map(state,state->image,state->player->scale);
		ray_fov(state, state->image,state->player->direction,0);
	}
if (mlx_is_key_down(mlx, MLX_KEY_H))
	{
		state->player->x_pos-=delta_x * 2;
		state->player->y_pos-=delta_y * 2;
		draw_map(state,state->image, state->player->scale);
		ray_fov(state, state->image,state->player->direction,0);
	}
if (mlx_is_key_down(mlx, MLX_KEY_T))
	{
		state->player->direction-= 0.1;
		if(state->player->direction  <= 0)
			state->player->direction = PI *  2;
		ray_fov(state, state->image,state->player->direction,0);
		draw_map(state,state->image, state->player->scale);
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
	state->player->scale = 12;
	state->map_data  = init_map();
	state->map = map_init(mapcreator("assets/map.cub"));
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
	state->mlx = mlx_init(1920, 1080, "MLX42", 0);
	image.image = mlx_new_image(state->mlx,1000,1080);
	//t_mlx_inst *element;
	state->image = image;
	draw_map(state,image, state->player->scale);
	//ray_fov3d(state, image, state->player->direction,0);
	//ray_fov(state, image, state->player->direction,0);
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

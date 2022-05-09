/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by jemartel          #+#    #+#             */
/*   Updated: 2022/05/09 12:13:44 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"
#include "stdio.h"
#include "stdlib.h"

int draw_grid(t_image image);

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

int	main(int argc, char *argv[])
{
	(void)argv;
	(void)argc;	// A.G : Need to add parsing some days
	int			time;
	t_game		*state;
	t_image		image;

	state = malloc(sizeof(t_game));
	state->player = malloc(sizeof(t_player));
	state->player->scale = 12;
	state->map_data  = init_map();
	state->map = map_init(mapcreator("assets/map.cub")); // A.G : ici changer le path avec le argv
	if (parsing(state,0) != 0 || parse_location(state,0,0) != 0)
	{
			ft_putstr_fd("an erro as occured \n", 2);
			//freelist(state->map);
			//delete_texture(state->map_data);
			//free(state->map_data);
			//free(state->player);
			//free(state);
		return (0);	
	}
	resize_map(state);
	player_direction(state);		//math part
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

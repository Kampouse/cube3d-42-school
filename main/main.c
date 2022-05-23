/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by jemartel          #+#    #+#             */
/*   Updated: 2022/05/23 19:13:43 by jemartel         ###   ########.fr       */
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
	flag += assert(verif_map_content(*map), "Error: wrong element in the map\n");
	if (flag > 0)
	{
		//free_list(map);
		exit(0);
	}
	return (map);
}

int	main(int argc, char *argv[])
{
	t_game		*state;
	t_image		image;

	if(argc != 2)
	{
		ft_putstr_fd("Error: wrong number of arguments expected a file \n", 1);
		exit(0);
	}
	else
		if(verify_extention(argv[1],".cub") == 1)
		{
			ft_putstr_fd("Error: wrong file extension expected a .cub\n", 1);
			exit(0);
		}
	state = malloc(sizeof(t_game));
	state->map = NULL;
	state->player = malloc(sizeof(t_player));
	state->ray = malloc(sizeof(t_ray));
	state->player->scale = 12;
	state->map_data  = init_map();
	state->map = map_init(mapcreator(argv[1]));
	if (parsing(state,0) != 0 || parse_location(state,0,0) != 0 || validate_file (state) != 0)
	{
			ft_putstr_fd("an erro as occured \n", 2);
			freelist(state->map);
			delete_texture(state->map_data);
			free(state->player);
			free(state->ray);
			free(state);

		return (0);	
	}
	resize_map(state);
	player_direction(state);
	load_image(state->map_data);
	state->player->x_pos = (state->player->x_pos) * state->player->scale;
	state->player->y_pos = (state->player->y_pos) * state->player->scale;
	state->player->x_map = (state->player->x_pos / state->player->scale) + 1;
	state->player->y_map = (state->player->y_pos / state->player->scale) + 1;
	(void)image;
	state->mlx = mlx_init(800, 600, "MLX42", 0);
	image.image = mlx_new_image(state->mlx, 800, 600);
	state->image = image;
	mlx_image_to_window(state->mlx, image.image, 0, 0);
	initialise_map(state);
	printf("%d\n",	pixel_to_color(state->map_data->est_tex,200,200));
	ray_fov(state);
	mlx_loop_hook(state->mlx, &hook, state);
	mlx_loop(state->mlx);

	return(0);
}

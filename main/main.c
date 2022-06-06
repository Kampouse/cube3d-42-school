/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by jemartel          #+#    #+#             */
/*   Updated: 2022/06/06 03:35:47 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Include/cube.h"
#include "stdio.h"
#include "stdlib.h"

t_game	*game_init(char *argv)
{
	t_game	*state;

	state = malloc(sizeof(t_game));
	state->map = NULL;
	state->player = malloc(sizeof(t_player));
	state->ray = malloc(sizeof(t_ray));
	state->player->scale = 10;
	state->map_data = init_map();
	state->map = map_init(mapcreator(argv));
	return (state);
}

int	parser_validator(t_game *state)
{
	int	error;

	error = 0;
	error += parsing(state, 0);
	if (error > 0)
		printf("FROM  Parsing() line: %d at: %s", __LINE__, __FILE__);
	error +=parse_location(state, 0, 0);
	if (error > 0)
		printf("FROM parse_location() line: %d at:%s", __LINE__, __FILE__);
	error +=validate_file (state);
	if (error > 0)
		printf("FROM validate_file() line: %d at:%s", __LINE__, __FILE__);
	return (error);
}

void	argc_manager(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error: wrong number of arguments expected a file \n", 1);
		exit(0);
	}
	else if (verify_extention(argv[1], ".cub") == 1)
	{
		ft_putstr_fd("Error: wrong file extension expected a .cub\n", 1);
		exit(0);
	}
}

int	delete_this(t_game *state)
{
	ft_putstr_fd("an erro as occured \n", 2);
	freelist(state->map);
	delete_texture(state->map_data);
	free(state->player);
	free(state->ray);
	free(state);
	return (0);
}

void	init_this(t_game *state)
{
	t_image		image;

	resize_map(state);
	player_direction(state);
	state->player->x_pos = ((state->player->x_pos) * state->player->scale) + 1;
	state->player->y_pos = ((state->player->y_pos) * state->player->scale) + 1;
	state->player->x_map = (state->player->x_pos / state->player->scale) + 1;
	state->player->y_map = (state->player->y_pos / state->player->scale) + 1;
	state->last_step = 'x';
	state->mlx = mlx_init(800, 600, "MLX42", 0);
	image.image = mlx_new_image(state->mlx, 800, 600);
	state->image = image;
	load_image(state);
	mlx_image_to_window(state->mlx, image.image, 0, 0);
	initialise_map(state);
	ray_fov(state);
}

int	main(int argc, char *argv[])
{
	t_game		*state;

	argc_manager(argc, argv);
	state = game_init(argv[1]);
	if (parser_validator(state) > 0 )
		return (delete_this(state));
	init_this(state);
	mlx_loop_hook(state->mlx, &hook, state);
	mlx_loop(state->mlx);
	return (0);
}

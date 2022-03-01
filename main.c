/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:37:17 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/28 19:31:05 by jemartel         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

#include "cube.h"
#include "stdio.h"
#include "stdlib.h"
#include "utils/get_next_line.h"
#include "utils/libft/libft.h"
#include "MLX/include/MLX42/MLX42.h"

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
	t_mlx	*mlx;

	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
	{
		mlx_terminate(mlx);
		exit(0);
	}
}
int	main(int argc, char *argv[])
{

	(void)argv;
	(void)argc;
	t_game		*state;
	state = malloc(sizeof(t_game));
	state->player = malloc(sizeof(t_player));
	state->player->scale = 32;
	state->map_data  = init_map();
	state->map = NULL;
	state->map = map_init(mapcreator("map.cub"));
	if (parsing(state,0) != 0 || parse_location(state,0,0) != 0)
	{
			printf("an erro as occured \n");
			freelist(state->map);
			delete_texture(state->map_data);
			//free(state->map_data);
			free(state->player);
			free(state);
		return (0);	
	}
	resize_map(state);
	player_direction(state);
	//t_mlx_image *g_img;
	//state->mlx = mlx_init(1000, 1000, "MLX42", 0);
	//g_img = mlx_new_image(mlx, 128, 128);
	//ft_memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	//mlx_image_to_window(mlx,g_img,100,100);
	//mlx_loop_hook(mlx, &hook, mlx);
	//mlx_loop_hook(state->mlx,&hook,state->mlx);
	//mlx_loop(state->mlx);
	//mlx_terminate(state->mlx);
		printf("%ld -- \n",state->player->direction);
		find_at(state,100,300);
		freelist(state->map);
		delete_texture(state->map_data);
		free(state->player);
		free(state);
	return(0);
		//mlx_new_window(state.mlx,100,100,"helo");
		//mlx_loop(state.mlx);
	//mlx_loop_hook(state.mlx, render_player, &state);
	//mlx_hook(state.win, 2, (1L << 0), render_cycle, &state);
	//mlx_hook(state.win, 17, 0, exit_please, &state);
	//mlx_do_sync(state.mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by jemartel          #+#    #+#             */
/*   Updated: 2022/05/10 16:24:48 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->ceiling_color = NULL;
	map->norh_texture = NULL;
	map->west_texture = NULL;
	map->est_texture = NULL;
	map->south_texture  = NULL;
	map->ceiling_color = NULL;
	map->floor_color = NULL;
	return (map);
}

void	*ft_free(void *content)
{
	if(content != NULL)
	{
		free(content);
		content = NULL;
		return(0);
	}
	else
		return (NULL);
}

/* maybe add a is digit in some way   so you can see if eleme is number or not */
int	*get_color(char *str)
{
	char	**darray;
	int		inc;
	int		*array;

	array = NULL;
	inc = 0;
	if(str)
	{
		darray = ft_split(str, ',');
		if(verif_number(darray))	
		{
			freelist(darray);
			return (NULL);	
		}
		while(darray[inc])
			inc++;
		array = ft_calloc(inc + 1,sizeof(int));
		inc = -1;
		while(darray[++inc])
			array[inc] = ft_atoi(darray[inc]);
		freelist(darray);
	}
	free(str);
	return (array);
}

/* return if the extention of the file is correct */ 
	int verify_extention(char *str) 
{
	const int ext_len = ft_strlen(".cub");	
	const int len = ft_strlen(str);

	if(len < ext_len)
		return (1);
	else if ( ft_strncmp(str + len - ext_len, ".cub",ft_strlen(str)) ==  0)
		return (0);
	return (1);
}

/*
void	main_init(t_screen *state, t_dlist *temp)
{
	map_init( temp);
	state->player = temp;
	//state->mlx = mlx_init();
	//state->win = mlx_new_window(state->mlx, state->screenwidth,
		//	state->screeheight, "./cube42");
	state->move_y = 0;
	state->move_x = 0;
	state->movecount = 0;
	state->image_state = 4;
}

int	exit_please(t_screen *state)
{
	mlx_destroy_window(state->mlx, state->win);
	exit(0);
	return (0);
}


*/

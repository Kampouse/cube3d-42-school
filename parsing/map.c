/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by jemartel          #+#    #+#             */
/*   Updated: 2022/06/06 13:28:23 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"

int	last_seen_at(char *str, char elem)
{
	int	index;

	if (str)
	{
		index = ft_strlen(str);
		while (index >= 0)
		{
			if (str[index] == elem)
				return (index);
			index--;
		}
	}
	return (-1);
}

int	any_before_after(char **map, int current_line)
{
	int			pos;
	int			temp;
	const int	start_at = ft_until_this(map[current_line], "1");

	pos = ft_until_this(map[current_line] + start_at, " ");
	temp = pos;
	if (pos < 0)
		return (0);
	while (pos > 0 && ft_strlen(map[current_line] + temp) > 0)
	{
		if ((map[current_line][temp + 1] != '1') || (
				map[current_line][temp - 1] != '1'))
		{
			if (!(last_seen_at(map[current_line], ' ') > last_seen_at
					(map[current_line], '1')))
				return (assert(1, "broken wall\n"));
		}
		pos = ft_until_this(map[current_line] + temp, "0");
		temp += pos;
	}
	return (0);
}

int	look_in_space(int current_line, t_game *game, int pos)
{
	int	inc;

	inc = ft_until_this(game->map[current_line] + pos, " ");
	if (inc < 0)
		return (0);
	if (inc > 0)
	{
		if ((int)ft_strlen(game->map[current_line - 1]) >= inc)
		{
			if (game->map[current_line - 1][inc] == '1')
			{
				if ((int)ft_strlen(game->map[
							current_line + 1]) >= inc && (game->map
						[current_line + 1][inc] == '1'))
					return (0);
			}
			else
				return (assert(1, "space encounter\n"));
		}
	}
	return (0);
}

int	only_space(char *str)
{
	if (str)
	{
		if (str && ft_strlen(str) == 0)
			return (1);
		if (str && was_in_set(str, " \n\t\v") == 0)
			return (1);
	}
	else
		return (1);
	return (0);
}

int	parser_helper(t_game *game, int temp, int inc)
{
	if (ft_until_this(game->map[temp], "NEWS") != -1)
	{
		game->player->x_pos = ft_until_this(game->map[temp], "NEWS");
		if (ft_until_this(game->map[temp] + ft_ftoi
				(game->player->x_pos) + 1, "NEWS") > 0)
			return (assert(2, "two player one same line\n"));
		game->player->orientation = game->map[temp][ft_ftoi
			(game->player->x_pos)];
		game->player->y_pos = inc;
		return (1);
	}
	return (0);
}

int	validate_file(t_game *game)
{
	int	file;

	file = open(game->map_data->norh_texture, R_OK);
	if (file > 0)
		close(file);
	else
		return (assert(1, "wrong file NORTH\n"));
	file = open(game->map_data->est_texture, R_OK);
	if (file > 0)
		close(file);
	else
		return (assert(1, "wrong file EST \n"));
	file = open(game->map_data->west_texture, R_OK);
	if (file > 0)
		close(file);
	else
		return (assert(1, "wrong file WEST\n"));
	file = open(game->map_data->south_texture, R_OK);
	if (file > 0)
		close(file);
	else
		return (assert(1, "wrong file south_texture\n"));
	return (0);
}

int	parse_location(t_game *game, int found, int inc)
{
	int	temp;

	temp = game->map_data->start;
	while (game->map[temp] && !only_space(game->map[temp]))
	{
		found += parser_helper(game, temp, inc);
		temp++;
		inc++;
	}
	if (found > 1)
		return (1);
	temp = game->map_data->start;
	while (game->map[temp] && !only_space(game->map[temp]))
	{
		if (was_in_set(game->map[temp], "01NEWS ") != 0)
		{
			printf("wrong element in field\n");
			return (1);
		}
		temp++;
	}
	if (found == 0)
		return (1);
	return (0);
}

int	parsing(t_game *game, int temp)
{
	if (loop_directions(game))
		return (1);
	while (game->map[game->map_data->iterator + 1] && only_space(game->map[
				game->map_data->iterator]))
		game->map_data->iterator++;
	temp = game->map_data->iterator;
	game->map_data->start = temp;
	if (ft_all(game->map[temp], '1'))
		return (assert(1, "all  are not one\n"));
	while (game->map[temp])
	{
		if (only_space(game->map[temp]))
			return (ft_all(game->map[temp - 1], '1'));
		if (any_one_above_line(game, temp))
			return (assert(1, "above\n"));
		if (any_before_after(game->map, temp))
			return (assert(1, "before or after\n"));
		if (ft_between(game->map[temp], '1') != 0)
			return (assert(1, "between\n"));
		if (any_one_bellow_line(game->map, temp))
			return (1);
		if (look_in_space(temp++, game, 0))
			return (assert(1, "look in space\n"));
	}
	return (0);
}

int	first_seen(char *str)
{
	int		inc;
	char	*temp;

	inc = 0;
	temp = ft_strchr(str, ' ');
	while (temp[inc] == ' ')
		inc++;
	if (temp[inc] == '1')
		return (0);
	return (1);
}

int	verif_no_space(t_game *game, int pos)
{
	int	iter;
	int	temp;

	iter = pos;
	temp = 0;
	while (!skip_empty_line(game->map[iter]))
		iter++;
	if (ft_all(game->map[iter], '1'))
		return (1);
	if (ft_until_this(game->map[iter], " ") != -1)
	{
		temp = ft_until_this(game->map[iter], " ");
		if (temp > last_seen_at(game->map[iter], '1'))
			return (0);
		if (first_seen(game->map[iter]) || game->map[iter][temp - 1] != '1')
			return (1);
	}
	return (0);
}

int	any_one_above(t_game *map, int current_line, int pos)
{
	while (current_line > map->map_data->iterator)
	{
		current_line--;
		if (map->map[current_line] && pos <= (int)
			ft_strlen(map->map[current_line]))
		{
			if (map->map[current_line][pos] == '1')
				return (0);
			else if (map->map[current_line][pos] == ' ')
				return (1);
			else
				continue ;
		}
		if (pos > (int)ft_strlen(map->map[current_line]))
			return (1);
		else if (map->map[current_line + 1][pos] == '1')
			return (0);
	}
	return (0);
}

int	any_one_above_line(t_game *map, int current_line)
{
	int	inc;

	inc = 0;
	while (map->map[current_line][inc])
	{
		if (map->map[current_line][inc] == '0')
		{
			if (any_one_above(map, current_line, inc))
				return (assert(1,"something is above\n"));
		}
		inc++;
	}
	return (0);
}

int	any_one_bellow_line(char **map, int current_line)
{
	int	inc;

	inc = 0;
	while (map[current_line][inc])
	{
		if (map[current_line][inc] == '0')
		{
			if (any_one_bellow(map, current_line, inc))
				return (assert(1,"Nothing bellow\n"));
		}
		inc++;
	}
	return (0);
}

// this funcion behave correctcly 
int	any_one_bellow(char **map, int current_line, int pos)
{
	while (map[current_line])
	{
		current_line++;
		if (map[current_line] && pos <= (int)ft_strlen(map[current_line]))
		{
			if (map[current_line][pos] == '1')
				return (0);
			else if (map[current_line][pos] == ' ')
				return (1);
			else
				continue ;
		}
		if (pos > (int)ft_strlen(map[current_line]))
			return (1);
		else if (map[current_line - 1][pos] && (map
			[current_line - 1][pos] == '1'))
			return (0);
	}
	return (0);
}

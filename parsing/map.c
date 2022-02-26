#include "../cube.h"


int any_one_above(t_game *map, int current_line,int pos);
void verif_no_space(t_game *game,int pos);
int any_one_above_line(t_game *map,int current_line);
int any_one_bellow(char **map, int current_line, int pos);
int any_one_bellow_line(char **map,int current_line);

int look_in_space(int current_line,t_game *game,int pos);

int was_in_set(char *str,char *set)
{
int inc;
int cin;
int temp;
int was_in_set;
	cin = 0;
was_in_set = 1;
	inc  = 0;
	while (str[inc])
	{
		temp = inc;
		while(set[cin])
		{
			if (set[cin] == str[inc])
			{
				was_in_set = 0;
				cin = 0;
				break ;
			}
			cin++;
		}
		if (was_in_set != 0)
			return (1);
		was_in_set = 1;
		inc++;
	}
return(0);
}

int last_seen_at(char *str, char elem)
{
int index;
if(str)
	{
		index =  ft_strlen(str);
		while(index >= 0)
		{
			if(str[index] == elem)
				return(index);
			index--;
		}
	}
return (-1);
}

int any_before_after(char **map,int current_line)
{
	int pos;
	int temp;	

	const int  start_at = ft_until_this(map[current_line],"1");
	pos = ft_until_this(map[current_line] + start_at, " ");
	temp = pos;
	if(pos < 0)
	return (0);
		while (pos >= 0 && ft_strlen(map[current_line] + temp) > 0)  
		{
			if((map[current_line][temp + 1] != '1') || ( map[current_line][temp - 1] != '1'))
		{
			if(!(last_seen_at( map[current_line],' ') > last_seen_at(map[current_line],'1')))
			printf("wrong\n");
				return (1);
		}
			pos = ft_until_this(map[current_line] + temp, "0");
			temp += pos;
		}
return (0);
}

int look_in_space(int current_line,t_game *game,int pos)
{
	int inc;

	 inc = ft_until_this(game->map[current_line] + pos," ");
	if (inc < 0)
		return (0);
	if (inc > 0)
	{
			if ((int)ft_strlen(game->map[current_line - 1]) >=  inc)
			{
				if (game->map[current_line - 1][inc] == '1')
					{
						if ((int)ft_strlen(game->map[current_line + 1] )>= inc &&  (game->map
								[current_line + 1][inc] == '1'))
						{
							printf("what is thi\n");

								return (0);
						}
					}
				else
					{
					printf("rah\n");
					return (1);
					}
			}
			else
				printf("error at space\n");
	}
return (0);
}
int parsing(t_game *game)
{
	int temp;
	if (loop_directions(game))
	{
		free(game);
		return(0);
	}
	while( game->map[game->map_data->iterator] && ft_all(game->map[game->map_data->iterator],'1'))
		game->map_data->iterator++;
	while (game->map[game->map_data->iterator])
	{
		 if (ft_strlen(game->map[game->map_data->iterator])  != 0 && was_in_set(game->map[game->map_data->iterator], " \t\v\r\n") != 0) 
			break ;
		game->map_data->iterator++;
	}
	temp = game->map_data->iterator;
		verif_no_space(game, temp);
	while(game->map[temp])
	{
		any_one_above_line(game,temp);
		any_before_after(game->map, temp);
		if(ft_between(game->map[temp],'1'))
			printf("not valide");
		any_one_bellow_line(game->map, temp);
		look_in_space(temp,game,0);
		temp++;
	}
	return (0);
}

int first_seen(char *str)
{
	int inc;
	char *temp;
	inc = 0;
	temp = ft_strchr(str,' ');

	while(temp[inc] == ' ')
		inc++;

	if(temp[inc] == '1')
		return(0);
return(1);
}



void verif_no_space(t_game *game, int pos)
{
	int iter;
	int temp;
	iter = pos;
	temp = 0;

	while (!skip_empty_line(game->map[iter]))
		iter++;
	if(ft_all(game->map[iter],'1'))
		printf("hello\n");

	if(ft_until_this(game->map[iter]," ") != -1)	
		{
			temp =  ft_until_this(game->map[iter]," ");
			if(first_seen(game->map[iter]) || game->map[iter][temp - 1] != '1')
				printf("%c \n",game->map[iter][temp - 1]);
		}
	}

int any_one_above(t_game *map,int current_line, int pos)
{
	while(current_line > map->map_data->iterator)
	{
			current_line--;
			if (map->map[current_line] && pos <=  (int)ft_strlen(map->map[current_line]))
			{
					if (map->map[current_line][pos]  == '1')
						return (0);
					else if( map->map[current_line][pos]  == ' ')
					{
						printf("herro");
						return(1);
					}
					else
						continue;
			}
			if(pos > (int)ft_strlen(map->map[current_line]))
				printf("out of bound\n");
			else if(map->map[current_line + 1][pos] == '1')
					return(0);
	}
return (0);
}

int any_one_above_line(t_game *map, int current_line)
{
	int inc;

	inc = 0;
	while (map->map[current_line][inc])
	{
		if (map->map[current_line][inc] == '0')
		{
			if (any_one_above(map, current_line, inc))
			{
				return(1);
			}
		}
		inc++;
	}
return(0);
}

int any_one_bellow_line(char **map,int current_line)
{
	int inc;

	inc = 0;
	while (map[current_line][inc])
	{
		if (map[current_line][inc] == '0')
		{
			if (any_one_bellow(map, current_line, inc))
			{
				return(1);
			}
		}
		inc++;
	}
	return (0);
}
// this funcion behave correctcly 
int any_one_bellow(char **map, int current_line, int pos)
{
	while(map[current_line])
	{
			current_line++;
			if (map[current_line] && pos <=  (int)ft_strlen(map[current_line]))
			{
					if (map[current_line][pos]  == '1')
						return (0);
					else if(map[current_line][pos]  == ' ')
					{
						printf("herror space found");
						return (1);	
					}
					else
						continue;
			}
			if(pos > (int)ft_strlen(map[current_line]))
				printf("out of bound\n");
			else if(map[current_line - 1][pos] &&(map[current_line - 1][pos] == '1'))
					return(0);
	}
return (0);
}
#include "../cube.h"


int any_one_above(char **map, int current_line,int pos);
void verif_no_space(t_game *game,int pos);
int any_one_above_line(char **map,int current_line);
int any_one_bellow(char **map, int current_line, int pos);


int parsing(t_game *game)
{

	if (loop_directions(game))
	{
		free(game);
		return(0);
	}

	verif_no_space(game,game->map_data->iterator + 1);
	any_one_above_line(game->map,game->map_data->iterator + 4);
	any_one_bellow(game->map,game->map_data->iterator + 2,1);
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

	while (game->map[iter])
	{
		if (ft_between(game->map[iter], '1'))
			printf("erro\n");
		if(ft_until_this(game->map[iter]," ") != -1)	
		{
			temp =  ft_until_this(game->map[iter]," ");
			if(first_seen(game->map[iter]) || game->map[iter][temp - 1] != '1')
				printf("%c\n",game->map[iter][temp - 1]);
		}

		iter++;
	}
}


int any_one_above_line(char **map,int current_line)
{
	int inc;

	inc = 0;
	while (map[current_line][inc])
	{
		if (map[current_line][inc] == '0')
		{
			if (any_one_above(map, current_line, inc))
			{
				return(1);
			}
		}
		inc++;
	}
	return (0);
}

int any_one_above(char **map, int current_line, int pos)
{

//should look into if   line is only 1 one wide 
	const   int start  = current_line - 1;
	const	int base_len = ft_strlen(map[current_line]);	

	while (current_line >= start)
	{
		printf("start (%d)  and is at :%d\n",base_len,(int)ft_strlen(map[current_line]));
			if(ft_strlen(map[current_line]) < base_len )
			{
				printf("this line is too short up : ");
				printf("%s\n",map[current_line]);
				return (1);
			}
			current_line--;	
	}
current_line++;
if(map[current_line][pos] == '1')
	return  (0);
else 
	return (1);
return (0);
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



int any_one_bellow(char **map, int current_line, int pos)
{
	const	int base_len = ft_strlen(map[current_line]);	

	while (map[current_line])
	{
		printf("start (%d)  and is at :%d\n",base_len,(int)ft_strlen(map[current_line]));
			if (ft_strlen(map[current_line]) < base_len)
			{
				printf("this line is too short: ");
				printf("%s\n", map[current_line]);
				return (1);
			}
			current_line++;	
	}
current_line--;
if(map[current_line][pos] == '1' || map[current_line][pos] == ' ') 
	return 0;
else
	return(1);
//should look into if   line is only 1 one wide 
return (0);	
}



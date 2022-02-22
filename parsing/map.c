#include "../cube.h"


int any_one_above(char **map, int current_line);
void verif_no_space(t_game *game,int pos);




int parsing(t_game *game)
{

	if (loop_directions(game))
	{
		free(game);
		return(0);
	}

	verif_no_space(game,game->map_data->iterator + 1);
any_one_above(game->map,game->map_data->iterator + 2);
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

int any_one_above(char **map,int current_line)
{

//should look into if   line is only 1 one wide 
	int inc;
	int cin;
	int temp;

	cin = 1;
	const   int start  = current_line - 1;
	
	inc = 0;
	while (current_line >= start)
		{
			if(map[current_line][cin] == '1')			
			{
				printf("%c\n",map[current_line][cin]);
				break;
			}
			printf("%c\n",map[current_line][cin]);
			current_line--;	
		}
	if (ft_strlen(map[start]) < (unsigned int) cin)
	{
		if (map[start][cin] == '0')
			printf("the wall is missing somthing\n");
	}
	else
		printf("line too short\n");
	
return (0);
}

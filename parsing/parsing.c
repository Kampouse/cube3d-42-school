#include "../cube.h"

char *skip_empty_line(char *str)
{
	const char *temp = ft_strtrim(str," \n\t\v");

	if (ft_strlen(temp) == 0)
	{
		free((void *)temp);
		return (0);
	}
	else
		return((char *)temp);
return (NULL);
}

t_map *init_map(void)
{
	t_map *map;
	map = ft_calloc(1,sizeof(*map));
	map->ceiling_color = NULL;
	map->norh_texture = NULL;
	map->west_texture = NULL;
	map->est_texture = NULL;
	map->ceiling_color = NULL;
	map->floor_color = NULL;
	return (map);
}

void *ft_free(void *content)
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
int delete_texture(t_map *map)
{
	if(map)
	{
		map->ceiling_color = ft_free(map->ceiling_color);
		map->south_texture = ft_free(map->south_texture);
		map->norh_texture = ft_free(map->norh_texture);
		map->west_texture = ft_free(map->west_texture);
		map->est_texture = ft_free(map->est_texture);
		map->floor_color = ft_free(map->floor_color);
		free(map);	
	}
return (0);
}

/* should make another function that check that no null  one */
void ft_poll_texture(char *str,t_map *map)
{
char *temp;

temp = NULL;
	if(str)
	{
			if (ft_strncmp(str,"NO",2) == 0)
			 map->norh_texture = ft_strtrim(str + 2," \n\t\v");
			else if (ft_strncmp(str,"SO",2) == 0)
			 map->south_texture = ft_strtrim(str + 2," \n\t\v");
			else if (ft_strncmp(str,"WE",2) == 0)
			 map->west_texture = ft_strtrim(str + 2," \n\t\v");
			else if (ft_strncmp(str,"EA",2) == 0)
			 map->est_texture = ft_strtrim(str + 2," \n\t\v");
			free(str);
	}
}
int verif_number(char **strs)
{
	int inc;
	int cin;

	cin = 0;
	inc = 0;

	while(strs[inc])
	{
		while(strs[inc][cin])
		{
			if(ft_isdigit(strs[inc][cin]))
					cin++;
			else
				return (1);
		}
		cin = 0;	

		inc++;
	}
return (0);
}




/* maybe add a is digit in some way   so you can see if eleme is number or not */
int *get_color(char *str)
{
char **darray;
int inc;
int *array;

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

int valid_range(int *numbers)
{
int is_not_ok;
int inc;

inc = 0;
is_not_ok = 0;

	while (inc < 4)
	{

			if (numbers[inc] < 0  ||  numbers[inc] > 255)
		{
				is_not_ok = 1;
				break ;
		}
		inc++;
	}
	return (is_not_ok);
}


int any_invalid(t_map *map)
{
int is_not_ok;

is_not_ok = 0;
	if(map->west_texture == NULL)
		is_not_ok++;
	if(map->south_texture == NULL)
		is_not_ok++;
	if(map->est_texture == NULL)
		is_not_ok++;
	if(map->norh_texture == NULL)
		is_not_ok++;
	if (!map->floor_color ||(map->floor_color && valid_range(map->floor_color)))
		is_not_ok++;
	if (!map->ceiling_color ||(map->ceiling_color && valid_range(map->ceiling_color)))
		is_not_ok++;
	return (is_not_ok);
}

void ft_poll_color(char *str,t_map *map,int inc)
{
	char *temp;

	temp = NULL;
	if (str)
	{
			if (ft_strncmp(str,"F",1) == 0)
			{
				temp = ft_strtrim(str + 1," \n\t\v");
				if(temp)
					map->floor_color = get_color(temp);
			}
			if (ft_strncmp(str, "C", 1) == 0)
			{
				temp = ft_strtrim(str + 1," \n\t\v");
				if (temp)
				{
					map->ceiling_color = get_color(temp);
					map->iterator = inc;
				}
			}
		free(str);
	}
}
int  loop_directions(t_game *state)
{
	 int inc;
	 int status;

	status = 0;
	inc = 0;
	if (state->map !=NULL)
	{
		while (state->map[inc])
		{
			 ft_poll_texture(skip_empty_line(state->map[inc]), state->map_data);
			 ft_poll_color(skip_empty_line(state->map[inc]), state->map_data,inc);
				inc++;
		}
		if (any_invalid(state->map_data))
		{
			delete_texture(state->map_data);
			freelist(state->map);
			return(printf("an error occured while reading texture or color"));
		}
	}
	else
		status = printf("Error : could not readfile\n");
	state->map_data->iterator++;
return (status);
}


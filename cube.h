/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h	                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:33:18 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/19 16:35:42 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  CUBE_H
# define  CUBE_H
# define LEFT 0
# define RIGHT 2
# define DOWN 1
# define UP 13
# define ESC 53

#include "stdio.h"
#include "stdlib.h"
#include "utils/get_next_line.h"
#include "utils/libft/libft.h"
#include "utils/minilibx/mlx.h"


typedef struct t_dlist
{
	void			*content;
	struct t_dlist	*next;
	struct t_dlist	*prev;
}					t_dlist;	

typedef struct t_map
{
	char	*norh_texture;
	char	*south_texture;
	char	*west_texture;
	char	*est_texture;
	int		*floor_color;
	int		*ceiling_color;
	int		*start_position;
	int		orientation;
} t_map;
typedef struct t_game
{
	t_map	*map_data;
	void	*mlx;
	void	*win;
	char	**map;
	int		image_state;
	int		screenwidth;
	int		screeheight;
}					t_game;	
t_dlist	*ft_lst_lastnode(t_dlist *currlist);
t_dlist	*ft_lst_firstnode(t_dlist *currlist);
t_dlist	*ft_lst_prevnode(t_dlist *currlist);
t_dlist	*ft_lst_nextnode(t_dlist *currlist);
t_dlist	*node_init(void *content);
void	ft_lst_add_frontd(t_dlist **currlist, t_dlist *newnode);
void	ft_lstiterd(t_dlist *currlist, void (*f) (void *));
void	ft_lst_add_backd(t_dlist **currlist, t_dlist *node);
int		ft_all(char *string, char comp);
int		ft_between(char *string, char comp);
int		verif_len(t_dlist stuff);
int		verif_wall(t_dlist stuff);
int		ft_char_count(char *str, int cmp);
int		verif_param(t_dlist map, char param);
int		verif_map_content(t_dlist map);
void	ft_cleart_dlist(t_dlist **currlist, void (*del)(void *));
void	ft_clearnode(t_dlist *currlist, void (*del)(void *));
t_dlist	*tile_row(t_dlist *map, int y);
t_dlist	*tile_all(t_dlist *map);
int		get_next_line(int fd, char **str);
t_dlist	*mapcreator(char *str);
int		ft_lst_lenght(t_dlist *currlist);
char 	**map_init(t_dlist *map);
void	ft_cleart_dlist(t_dlist **currlist, void (*del)(void *));
t_dlist	*verif(t_dlist *map);
t_dlist	*player_node(t_dlist *map);
int		assert(int value, char *str);
int		ft_count_all(char **str, char cmp);
t_dlist	*ft_lstnewl(void *content);
char	freelist(char **list);
int		loop_directions(t_game *state);
void	free_list(t_dlist *head);
t_map *init_map(void);
#endif 

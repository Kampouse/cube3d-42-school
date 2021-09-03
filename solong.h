/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:33:18 by jemartel          #+#    #+#             */
/*   Updated: 2021/09/03 17:34:05 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  SOLONG_H
# define  SOLONG_H
# define LEFT 0
# define RIGHT 2
# define DOWN 1
# define UP 13
# define ESC 53

typedef struct t_dlist
{
	void			*content;
	struct t_dlist	*next;
	struct t_dlist	*prev;
}					t_dlist;	

typedef struct t_screen
{
	void	*mlx;
	void	*win;
	char	**map;
	void	**tiles;
	int		locationx;
	int		locationy;
	int		x_pos;
	int		y_pos;
	int		move_x;
	int		move_y;
	int		movecount;
	int		collected;
	int		image_state;
	int		screenwidth;
	int		screeheight;
	t_dlist	*player;
}					t_screen;	
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
void	render_imageStore(t_screen *state);
void	render_background(t_screen *state, t_dlist *map);
void	player_finder(t_screen *state, int x_axis, int y_axis);
void	ft_cleart_dlist(t_dlist **currlist, void (*del)(void *));
void	ft_clearnode(t_dlist *currlist, void (*del)(void *));
t_dlist	*tile_row(t_dlist *map, int y);
void	image_type(t_screen *state);
t_dlist	*tile_all(t_dlist *map);
int		get_next_line(int fd, char **str);
t_dlist	*mapcreator(int fd);
int		ft_lst_lenght(t_dlist *currlist);
int		render_image(t_screen *state, int x, int y, int image);
int		render_tiles(t_screen *state, int x_axis, int y_axis);
int		render_player(t_screen *state);
void	map_init(t_screen *state, t_dlist *map);
void	map_tiles(t_screen *state);
void	ft_cleart_dlist(t_dlist **currlist, void (*del)(void *));
void	play_vert(t_screen *state, int keycode);
void	play_horz(t_screen *state, int keycode);
void	play_contact(t_screen *state);
int		rend_dec(t_screen *state);
int		render_walk(t_screen *state);
void	main_init(t_screen *state, t_dlist *temp);
t_dlist	*verif(t_dlist *map);
int		type_render(t_screen *state, char type);
t_dlist	*player_node(t_dlist *map);
void	freeray(t_screen *ray);
int		assert(int value, char *str);
#endif 

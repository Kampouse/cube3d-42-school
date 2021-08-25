#ifndef  SOLONG_H
#define  SOLONG_H

typedef struct  dlist 
{
	void *content;
 	struct dlist *prev;
 	struct dlist *next;
	int	 pos_x;
	int	 pos_y;
	char	 type;
}					dlist;	


typedef struct  screen 
{
	void			*mlx;
	void			*win;
	char			**map;
	void			**tiles;
	dlist			*player;
}					screen;	

dlist	*ft_lst_lastnode(dlist *currlist);
dlist	*ft_lst_firstnode(dlist *currlist);
dlist	*ft_lst_prevnode(dlist *currlist);
dlist	*ft_lst_nextnode(dlist *currlist);
dlist	*node_init(void *content);

void	ft_lst_add_frontd(dlist **currlist, dlist *newnode);
void	ft_lstiterd(dlist *currlist, void (*f) (void *));
void	ft_lst_add_backd(dlist **currlist, dlist *node);

int ft_all(char *string,char comp);
int ft_between(char *string, char comp);

int verif_len(dlist stuff);
int verif_wall(dlist stuff);
int ft_char_count(char *str, int cmp);
int verif_param(dlist map,char param);
int verif_map_content(dlist map);
void render_imageStore(screen *state);
int render_player(screen *state, void *player);
void render_background(screen *state, dlist *map);
void ft_cleardlist(dlist **currlist, void (*del)(void *));
void ft_clearnode(dlist *currlist, void (*del)(void *));;
dlist *tile_row(dlist *map,int y);
void image_type(screen *state);
dlist *tile_all(dlist *map);
int render_some(screen *state, int x, int y,int type);
int get_next_line(int fd, char **str);
dlist *mapcreator(int fd);
int ft_lst_lenght(dlist *currlist);
int render_image(screen *state, int x, int y, int image);
void render_tiles(screen *state,int x_axis,int y_axis);
 void map_init(screen *state,dlist *map);
 void map_tiles(screen *state);
#endif 

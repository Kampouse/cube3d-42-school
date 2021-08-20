#ifndef  SOLONG_H
#define  SOLONG_H

typedef struct  screen 
{
	void			*mlx;
	void			*win;
	int				player_x;
	int				player_y;
}					screen;	

typedef struct  dlist 
{
	void *content;
 	struct dlist *prev;
 	struct dlist *next;
	int	 pos_x;
	int	 pos_y;
	char	 type;
}					dlist;	

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

void ft_cleardlist(dlist **currlist, void (*del)(void *));
void ft_clearnode(dlist *currlist, void (*del)(void *));;
dlist *tile_row(dlist *map,int x,int y);
#endif 

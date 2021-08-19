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
int verif_player(dlist map);
#endif 

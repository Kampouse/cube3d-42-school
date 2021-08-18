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
#endif 

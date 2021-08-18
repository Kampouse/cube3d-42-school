#include "stdio.h"
#include "stdlib.h"

typedef struct  dlist 
{
	void *content;
 	struct dlist *prev;
 	struct dlist *next;
}					dlist;	

dlist	*ft_lstnode(void *content)
{
	dlist	 *link;

	link = (dlist *)malloc(sizeof(*link));
	if (!link)
		return (NULL);
	link->content = content;
	link->prev = NULL;
	link->next = NULL;
	return (link);
}

dlist	*ft_lst_lastnode(dlist *currlist)
{
	while (currlist)
	{
		if (!currlist->next)
			return (currlist);
		currlist = currlist->next;
	}
	return (currlist);
}
 
dlist	*ft_lst_firstnode(dlist *currlist)
{
	while (currlist)
	{
		if (!currlist->prev)
			return (currlist);
		currlist = currlist->prev;
	}
	return (currlist);
}
dlist	*ft_lst_prevnode(dlist *currlist)
{

		currlist = currlist->prev;
	return (currlist);
}
dlist	*ft_lst_nextnode(dlist *currlist)
{
		currlist = currlist->next;
	return (currlist);
}

 void	ft_lst_add_frontd(dlist **currlist, dlist *newnode)
{
	if (currlist)
	{
		if (*currlist)
		{
			newnode->next = *currlist;
		}
		*currlist = newnode;
	}
}

void	ft_lstiter(dlist *currlist, void (*f) (void *))
{
	if (!f)
		return ;
	while (currlist)
	{
		 (*f)(currlist->content);
		currlist = currlist->next;
	}
}
void	ft_lst_add_backd(dlist **currlist, dlist *new)
{
	dlist	*last;

	if (currlist)
	{
		if (*currlist)
		{
			last = ft_lst_lastnode(*currlist);
			last->next = new;
			new->prev = last;
		}
		else
			*currlist = new;
	}
}
/**
int main(void)
{
dlist *lst;
lst = NULL;

 ft_lst_add_backd(&lst,ft_lstnode("stuff"));
 ft_lst_add_backd(&lst,ft_lstnode("hello"));
 ft_lst_add_backd(&lst,ft_lstnode("please"));
 ft_lst_add_backd(&lst,ft_lstnode("help me"));
lst = ft_lst_lastnode(lst);
lst = ft_lst_nextnode(lst);
//printf("%s",(char *)lst->content);
}
*/

#include "solong.h"

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



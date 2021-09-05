#include "../solong.h"

t_dlist *ft_lst_lastnode(t_dlist *currlist) {
  while (currlist) {
    if (!currlist->next)
      return (currlist);
    currlist = currlist->next;
  }
  return (currlist);
}

t_dlist *ft_lst_firstnode(t_dlist *currlist) {
  while (currlist) {
    if (!currlist->prev)
      return (currlist);
    currlist = currlist->prev;
  }
  return (currlist);
}

t_dlist *ft_lst_prevnode(t_dlist *currlist) {

  currlist = currlist->prev;
  return (currlist);
}

t_dlist *ft_lst_nextnode(t_dlist *currlist) {
  currlist = currlist->next;
  return (currlist);
}

int ft_lst_lenght(t_dlist *currlist) {
  int len;
  len = 0;
  while (currlist) {
    currlist = currlist->next;
    len++;
  }

  return (len);
}

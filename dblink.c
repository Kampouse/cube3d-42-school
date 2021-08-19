#include "solong.h"
#include "stdio.h"
#include "stdlib.h"

dlist *node_init(void *content) {
  dlist *link;

  link = (dlist *)malloc(sizeof(*link));
  if (!link)
    return (NULL);
  link->content = content;
  link->prev = NULL;
  link->next = NULL;
  return (link);
}

void ft_lst_add_frontd(dlist **currlist, dlist *newnode) {
  if (currlist) {
    if (*currlist) {
      newnode->next = *currlist;
    }
    *currlist = newnode;
  }
}

void ft_lstiterd(dlist *currlist, void (*f)(void *)) {
  if (!f)
    return;
  while (currlist) {
    (*f)(currlist->content);
    currlist = currlist->next;
  }
}

void ft_lst_add_backd(dlist **currlist, dlist *node) {
  dlist *last;

  if (currlist) {
    if (*currlist) {
      last = ft_lst_lastnode(*currlist);
      last->next = node;
      node->prev = last;
    } else
      *currlist = node;
  }
}

void ft_clearnode(dlist *currlist, void (*del)(void *)) {
  if (currlist) {
    //   printf("%s", (char *)currlist->content);
    //(*del)(currlist->content);
    free(currlist);
  }
}

void ft_cleardlist(dlist **currlist, void (*del)(void *)) {
  dlist *iter;

  if (!del || !currlist || !*currlist) {
    return;
  }
  // am not sure if it clear all of the list;
  while (currlist && *currlist) {
    iter = (*currlist)->next;
    *currlist = iter;
    ft_clearnode(*currlist, del);
  }
}

/*
int main(void)
{
dlist *lst;
lst = NULL;

 ft_lst_add_backd(&lst,node_init("stuff"));
 ft_lst_add_backd(&lst,node_init("hello"));
 ft_lst_add_backd(&lst,node_init("please"));
 ft_lst_add_backd(&lst,node_init("help me"));
lst = ft_lst_lastnode(lst);
printf("%s",(char *)lst->content);
}
*/

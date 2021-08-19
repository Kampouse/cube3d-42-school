#include "libft/libft.h"
#include "solong.h"
#include "stdio.h"

int verif_len(dlist map) {
  // len
  dlist *temp;
  int len;
  temp = NULL;
  temp = &map;
  len = ft_strlen((char *)temp->content);
  while (temp->next) {
    if (len != ft_strlen((char *)temp->content))
      printf("cry");
    len = ft_strlen((char *)temp->content);
    temp = ft_lst_nextnode(temp);
  }
  if (len != ft_strlen((char *)temp->content))
    printf("cry");

  return (0);
}

int verif_wall(dlist map) {
  dlist *temp;
  temp = &map;

  if (ft_all((char *)temp->content, '1') != 0)
    printf("what");

  temp = ft_lst_nextnode(temp);
  while (temp->next) {

    if (ft_between((char *)temp->content, '1') != 0)
      printf("c");
    temp = ft_lst_nextnode(temp);
  }

  if (ft_all((char *)temp->content, '1') != 0)
    printf("what");
  return (0);
}

int verif_param(dlist map, char param) {

  dlist *temp;
  int counter;

  counter = 0;
  temp = &map;
  while (temp->next) {
    counter += ft_char_count((char *)temp->content, param);
    temp = ft_lst_nextnode(temp);
  }
  if (counter == 1 && param == 'P') {
    printf("good");
    return (0);
  }
  if (counter >= 1 && param != 'P')
    printf("amazing");

  return (0);
}

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
      return (1);
    len = ft_strlen((char *)temp->content);
    temp = ft_lst_nextnode(temp);
  }
  if (len != ft_strlen((char *)temp->content))
    return (1);
  return (0);
}

int verif_wall(dlist map) {
  dlist *temp;
  temp = &map;

  if (ft_all((char *)temp->content, '1'))
    return (1);

  temp = ft_lst_nextnode(temp);
  while (temp->next) {

    if (ft_between((char *)temp->content, '1'))
      return (1);
    temp = ft_lst_nextnode(temp);
  }

  if (ft_all((char *)temp->content, '1'))
    return (1);
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
  if (counter != 1 && param == 'P')
    return (1);
  if (counter < 1 && param != 'P')
    return (1);
  return (0);
}

int legalchars(char *str) {
  int inc;
  inc = 0;
  const char *comparator = "PE01C";

  while (str[inc]) {
    if (!ft_strchr(comparator, str[inc]))
      return (1);
    inc++;
  }
  return (0);
}

int verif_map_content(dlist map) {
  dlist *temp;
  temp = &map;
  while (temp->next) {
    if (legalchars((char *)temp->content) != 0)
      return (1);
    temp = temp->next;
  }
  if (legalchars((char *)temp->content) != 0)
    return (1);
  return (0);
}

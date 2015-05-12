/*
** list_func.c for list in /home/fouhet_k/Perso/PSU_2014_myftp/src_utils
** 
** Made by kevin fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Thu Mar 12 11:49:41 2015 kevin fouhety
** Last update Sun Apr 12 21:32:39 2015 kevin fouhety
*/

#include <stdio.h>
#include "list_func.h"

fptr		find_cmd(t_list *list, char *cmd)
{
  t_list	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      if (strncmp(cmd, tmp->name, strlen(tmp->name)) == 0)
	return (tmp->cmd);
      tmp = tmp->next;
    }
  return (list->cmd);
}

t_list		*init_list(char *name, fptr cmd)
{
  t_list	*list;

  if ((list = xmalloc(sizeof (t_list))) == NULL)
    return (NULL);
  list->name = init_name(name);
  list->cmd = cmd;
  list->next = NULL;
  return (list);
}

void		add_to_list(t_list *list, char *name, fptr cmd)
{
  t_list	*elem;
  t_list	*tmp;

  tmp = list;
  elem = xmalloc(sizeof (t_list));
  elem->name = init_name(name);
  elem->cmd = cmd;
  elem->next = NULL;
  while (tmp != NULL&& tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = elem;
}

void		destroy_list(t_list *list)
{
  t_list	*tmp;

  while (list != NULL)
    {
      tmp = list->next;
      free(list->name);
      free(list);
      list = tmp;
    }
}

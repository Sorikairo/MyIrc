/*
** get_functions.c for myirc in /home/cruvei_t/PSU_2014_myirc/Sources/server
** 
** Made by Thomas CRUVEILHER
** Login   <cruvei_t@epitech.net>
** 
** Started on  Sun Apr 12 21:02:28 2015 Thomas CRUVEILHER
** Last update Sun Apr 12 23:36:01 2015 Thomas CRUVEILHER
*/

#include "server.h"

char		*get_channel_name(t_channel **channel, int id)
{
  t_channel	*tmp;

  tmp = *channel;
  while (tmp != NULL)
    {
      if (tmp->id == id)
	return (tmp->name);
      tmp = tmp->next;
    }
  return (NULL);
}

int		get_user_id(t_user **list, char *name)
{
  t_user	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (strcmp(tmp->name, name) == 0)
	return (tmp->id);
      tmp = tmp->next;
    }
  return (-1);
}

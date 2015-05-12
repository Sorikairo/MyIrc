/*
** channel.c for myirc in /home/cruvei_t/PSU_2014_myirc/Sources/server
** 
** Made by Thomas CRUVEILHER
** Login   <cruvei_t@epitech.net>
** 
** Started on  Sun Apr 12 12:12:23 2015 Thomas CRUVEILHER
** Last update Sun Apr 12 23:17:38 2015 Thomas CRUVEILHER
*/

#include "server.h"

void		add_channel(t_channel **list, char *name, int id)
{
  t_channel	*tmp;

  tmp = xmalloc(sizeof(t_channel));
  tmp->id = id;
  tmp->name = xmalloc(CHANNEL_NAME + 1);
  strncpy(tmp->name, name, CHANNEL_NAME);
  tmp->name[CHANNEL_NAME] = '\0';
  if (*list != NULL)
    tmp->next = *list;
  else
    tmp->next = NULL;
  *list = tmp;
}

void		list_channel(t_channel **list, int fd)
{
  t_channel	*tmp;

  tmp = *list;
  if (tmp != NULL)
    {
      while (tmp->next != NULL)
	{
	  dprintf(fd, "322 %s\n", tmp->name);
	  tmp = tmp->next;
	}
      dprintf(fd, "%s\n", tmp->name);
    }
}

int		get_channel_id(t_channel **list, char *name)
{
  t_channel	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (strcmp(tmp->name, name) == 0)
	return (tmp->id);
      tmp = tmp->next;
   }
  return (-1);
}

int		get_max_id(t_channel **list)
{
  t_channel	*tmp;
  int		max;

  tmp = *list;
  if (tmp != NULL)
    max = tmp->id;
  else
    max = 0;
  while (tmp != NULL)
    {
      if (tmp->id > max)
	max = tmp->id;
      tmp = tmp->next;
    }
  return (max);
}

void		list_channel_user(t_user **list, int channel_id, int fd)
{
  t_user	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (tmp->channel == channel_id)
	dprintf(fd, " %s", tmp->name);
      tmp = tmp->next;
    }
}

/*
** user.c for myirc in /home/cruvei_t/PSU_2014_myirc/Sources/server
** 
** Made by Thomas CRUVEILHER
** Login   <cruvei_t@epitech.net>
** 
** Started on  Sun Apr 12 12:05:39 2015 Thomas CRUVEILHER
** Last update Sun Apr 12 22:33:50 2015 Thomas CRUVEILHER
*/

#include "server.h"

void		add_user(t_user **list, int id)
{
  t_user	*tmp;

  tmp = xmalloc(sizeof(t_user));
  tmp->id = id;
  tmp->channel = -1;
  tmp->name = xmalloc(USER_NAME + 1);
  strcpy(tmp->name, "Anonymous");
  init_buffer(&(tmp->buffer));
  if (*list != NULL)
    tmp->next = *list;
  else
    tmp->next = NULL;
  *list = tmp;
}

void		change_user_nick(t_user **list, int id, char *name)
{
  t_user	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (tmp->id == id)
	{
	  strncpy(tmp->name, name, USER_NAME);
	  tmp->name[USER_NAME] = '\0';
	  return ;
	}
      tmp = tmp->next;
    }
}

void		set_channel(t_user **list, int id, int channel)
{
  t_user	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (tmp->id == id)
	{
	  tmp->channel = channel;
	  return ;
	}
      tmp = tmp->next;
    }
}

int		get_channel(t_user **list, int id)
{
  t_user	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (tmp->id == id)
	return (tmp->channel);
      tmp = tmp->next;
    }
  return (-1);
}

char		*get_nickname(t_user **list, int id)
{
  t_user	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (tmp->id == id)
	return (tmp->name);
      tmp = tmp->next;
    }
  return (NULL);
}

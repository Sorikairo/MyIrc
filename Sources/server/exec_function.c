/*
** exec_function.c for myirc in /home/cruvei_t/PSU_2014_myirc/Sources/server
** 
** Made by Thomas CRUVEILHER
** Login   <cruvei_t@epitech.net>
** 
** Started on  Sun Apr 12 15:55:21 2015 Thomas CRUVEILHER
** Last update Sun Apr 12 22:46:19 2015 Thomas CRUVEILHER
*/

#include "server.h"

void		send_msg(t_server *server, char *command, int id)
{
  int		id_channel;
  char		*nickname;
  t_user	*tmp;

  tmp = server->user;
  id_channel = get_channel(&(server->user), id);
  if (id_channel != -1)
    {
      nickname = get_nickname(&(server->user), id);
      while (tmp != NULL)
	{
	  if (tmp->channel == id_channel)
	    dprintf(tmp->id, "%s : %s\r\n", nickname, command);
	  tmp = tmp->next;
	}
    }
}

void		init_name_client(t_server *server, char *command, int id)
{
  char		*nickname;

  nickname = get_send_cmd(command, "");
  if (nickname != NULL)
    change_user_nick(&(server->user),id, nickname);
  free(command);
}

void		list_channel_server(t_server *server, char *command, int id)
{
  dprintf(id, "321 Channel %s\n", get_nickname(&(server->user), id));
  list_channel(&(server->channel), id);
  dprintf(id, "323 End of /LIST\r\n");
  free(command);
}

void		join_channel_server(t_server *server, char *command, int id)
{
  char		*channel;

  channel = get_send_cmd(command, "");
  if (channel[0] == '\0')
    dprintf(id, "461 %s Not enough parameters\r\n", command); 
  else
    {
      if (get_channel_id(&(server->channel), channel) ==  -1)
	add_channel(&(server->channel), channel, get_max_id(&(server->channel)) + 1);
      set_channel(&(server->user), id,
		  get_channel_id(&(server->channel), channel));
      dprintf(id, "332 %s\r\n", channel);
    }
  free(command);
  free(channel);
}

void		part_channel_server(t_server *server, char *command, int id)
{
  char		*channel;
  int		channel_id;

  channel = get_send_cmd(command, "");
  if (channel[0] == '\0')
    dprintf(id, "461 %s Not enough parameters\r\n", command);
  else
    {
      channel_id = get_channel_id(&(server->channel), channel);
      if (get_channel(&(server->user), id) != channel_id)
	dprintf(id, "442 %s You're not on that channel\r\n", channel);
      else
	set_channel(&(server->user), id, -1);
    }
  free(command);
  free(channel);
}

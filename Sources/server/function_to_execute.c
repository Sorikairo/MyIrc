/*
** function_to_execute.c for myirc in /home/cruvei_t/PSU_2014_myirc/Sources/server
** 
** Made by Thomas CRUVEILHER
** Login   <cruvei_t@epitech.net>
** 
** Started on  Sun Apr 12 20:35:24 2015 Thomas CRUVEILHER
** Last update Sun Apr 12 23:39:26 2015 Thomas CRUVEILHER
*/

#include "server.h"

void	list_user_channel(t_server *server, char *command, int id)
{
  char	*channel;
  int	channel_id;

  channel = get_send_cmd(command, "");
  if (channel[0] != '\0')
    {
      channel_id = get_channel_id(&(server->channel), channel);
      dprintf(id, "353 %s", channel);
      list_channel_user(&(server->user), channel_id, id);
      dprintf(id, "\n366 %s End of /NAMES list\r\n", channel);
    }
  else
    {
      channel_id = 1;
      while (channel_id <= get_max_id(&(server->channel)))
	{
	  dprintf(id, "353 %s", get_channel_name(&(server->channel), channel_id));
	  list_channel_user(&(server->user), channel_id, id);
	  if (channel_id == get_max_id(&(server->channel)))
	    dprintf(id, "\n366 %s End of /NAMES list\r\n", channel);
	  else
	    dprintf(id, "\n366 %s End of /NAMES list\n", channel);
	  channel_id++;
	}
    }
}

int	count_arguments(char *command)
{
  int	i;
  
  strtok(command, ":");
  i = 1;
  while (strtok(NULL, ":") != NULL)
    i++;
  return (i);
}

void	private_msg(t_server *server, char *command, int id)
{
  char	*epur_command;
  char	*receiver_list;
  char	*receiver;
  char	*message;

  epur_command = get_send_cmd(command, "");
  if (epur_command[0] == '\0' || epur_command[0] == ':')
    dprintf(id, "411 No recipent given (PRIVMSG)\r\n");
  else if (count_arguments(epur_command) == 1)
    dprintf(id, "412 No text to send\r\n");
  else
    {
      message = get_send_cmd(epur_command, "");
      receiver_list = strtok(epur_command, " :");
      receiver = strtok(receiver_list, ",");
      while (receiver != NULL)
	{
	  if (get_user_id(&(server->user), receiver) == -1)
	    dprintf(id, "401 %s No suck nick\r\n", receiver);
	  else
	    dprintf(get_user_id(&(server->user), receiver), "<PM from %s> %s\r\n",
		    get_nickname(&(server->user), id), &message[1]);
	  receiver = strtok(NULL, ",");
	}
    }
}

void	delete_user(t_user **list, int id)
{
  t_user	*tmp;

  tmp = *list;
  while (tmp->next != NULL)
    {
      if (tmp->next->id == id)
	tmp->next = tmp->next->next;
      tmp = tmp->next;
    }
}

void	quit_client(t_server *server, char *command, int id)
{
  FD_CLR(id, &(server->active_read_fd));
  delete_user(&(server->user), id);
  free(command);
}

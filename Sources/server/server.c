/*
** server.c<2> for myirc in /home/cruvei_t/fouhet/PSU_2014_myftp/src_server
** 
** Made by Thomas CRUVEILHER
** Login   <cruvei_t@epitech.net>
** 
** Started on  Sun Apr 12 10:34:58 2015 Thomas CRUVEILHER
** Last update Sun Apr 12 23:07:45 2015 Thomas CRUVEILHER
*/

#include "server.h"

t_buffer		*get_client_buffer(t_server *server, int id)
{
  t_user		*tmp;

  tmp = server->user;
  while (tmp != NULL)
    {
      if (tmp->id == id)
	return (&(tmp->buffer));
      tmp = tmp->next;
    }
  return (NULL);
}

t_list			*create_list_func()
{
  t_list		*ret;

  ret = init_list("msg", &send_msg);
  add_to_list(ret, "NICK", &init_name_client);
  add_to_list(ret, "LIST", &list_channel_server);
  add_to_list(ret, "JOIN", &join_channel_server);
  add_to_list(ret, "PART", &part_channel_server);
  add_to_list(ret, "NAMES", &list_user_channel);
  add_to_list(ret, "PRIVMSG", &private_msg);
  add_to_list(ret, "QUIT", &quit_client);
  return (ret);
}

void			work_with_select(t_server *server)
{
  char			*command;
  int			fd;

  fd = 0;
  if (select(server->max_fd + 1, &(server->read_fd), NULL, NULL, NULL) > 0)
    {
      while (fd <= server->max_fd)
	{
	  if (FD_ISSET(fd, &(server->read_fd)))
	    {
	      if (fd == server->sok)
		add_client_info(server);
	      else
		{
		  if (write_buffer(get_client_buffer(server, fd), fd, 1) == 2)
		    {
		      command = read_buffer(get_client_buffer(server, fd), 1);
		      find_cmd(server->list, command)(server, command, fd);
		    }
		}
	    }
	  fd++;
	}
    }
}

int			main(int ac, char **av)
{
  t_server		server;

  if (ac == 2)
    {
      server.sok = init_socket_client();
      bind_sok(server.sok, av[1]);
      server.peer_addr_size = sizeof(struct sockaddr_in);
      server.channel = NULL;
      server.user = NULL;
      server.max_fd = server.sok;
      server.list = create_list_func();
      FD_ZERO(&(server.active_read_fd));
      FD_SET(server.sok, &(server.active_read_fd)); 
      while (42)
	{
	  server.read_fd = server.active_read_fd;
	  work_with_select(&server);
	}
      close(server.sok);
    }
  return (0);
}

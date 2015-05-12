/*
** main.c for client in /home/fouhet_k/Perso/PSU_2014_myirc/Sources/client
** 
** Made by kevin fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Fri Apr 10 11:32:45 2015 kevin fouhety
** Last update Sun Apr 12 21:33:17 2015 kevin fouhety
*/

#include <errno.h>
#include "client.h"
#include "buffer.h"

t_list			*create_list_func()
{
  t_list		*ret;

  ret = init_list("msg", &send_msg);
  add_to_list(ret,"/server", &init_socket_server);
  add_to_list(ret, "/nick", &init_name_client);
  add_to_list(ret, "/list", &list_channel_server);
  add_to_list(ret, "/join", &join_channel_server);
  add_to_list(ret, "/part", &part_channel_server);
  add_to_list(ret, "/user", &list_user_channel);
  add_to_list(ret, "/msg", &private_msg);
  add_to_list(ret, "/quit", &quit_client);
  return (ret);
}

char			*work_on_fd(int fd_pos, t_buffer *buffer,
				    t_client *client, t_list *list_func)
{
  char			*pars;
  int			nb;

  pars = NULL;
  if (fd_pos == client->sok)
    {
      if ((nb = write_buffer(buffer, fd_pos, 1)) != -1 && nb != 3)
	{
	  pars = read_buffer(buffer, 1);
	  printf("%s\n", pars);
	}
    }
  else if (fd_pos == client->fd_client)
    {
      if ((nb = write_buffer(buffer, fd_pos, 0)) != -1 && nb != 3)
	{
	  pars = read_buffer(buffer, 0);
	  if (client->is_co == 1 ||
	      strncmp("/server", pars, strlen("/server")) == 0)
	    find_cmd(list_func, pars)(pars, client);
	  else
	    write(1, "/server _hose_[:_port_]\n", 24);
	}
    }
  return (pars);
}

void	init_fd(t_client *cl)
{
  FD_ZERO(&(cl->fd));
  FD_SET(0, &(cl->fd));
  if (cl->is_co == 1)
    FD_SET(cl->sok, &(cl->fd));
}

void			work_with_select(t_client *cl, t_buffer *buff1,
					 t_list *list_func, t_buffer *buff2)
{
  t_read		read;

  read.n = 0;
  read.pars = NULL;
  while (((read.pars == NULL || strcmp("/quit", read.pars) != 0))
	 && read.n != -1)
    {
      read.fd_pos = 0;
      init_fd(cl);
      if ((read.n = select(cl->nb_fd + 1,
			   &(cl->fd), NULL, NULL, NULL)) > 0)
	while (read.fd_pos <= cl->nb_fd)
	  {
	    if (FD_ISSET(read.fd_pos, &(cl->fd)))
	      {
		free(read.pars);
		if (read.fd_pos == cl->fd_client)
		  read.pars = work_on_fd(read.fd_pos, buff1, cl, list_func);
		else
		  read.pars = work_on_fd(read.fd_pos, buff2, cl, list_func);
	      }
	    read.fd_pos++;
	  }
    }
}

int			main()
{
  t_list		*list_func;
  t_client		client;
  t_buffer		buff1;
  t_buffer		buff2;
  struct protoent	*protocol;

  protocol = getprotobyname("TCP");
  client.name = init_name("Anonymous");
  client.is_co = 0;
  client.sok = socket(AF_INET, SOCK_STREAM, protocol->p_proto);
  client.nb_fd = 0;
  client.fd_client = 0;
  init_buffer(&buff1);
  init_buffer(&buff2);
  list_func = create_list_func();
  work_with_select(&client, &buff1, list_func, &buff2);
  return (0);
}

/*
** utils.c for myirc in /home/cruvei_t/PSU_2014_myirc/Sources/server
** 
** Made by Thomas CRUVEILHER
** Login   <cruvei_t@epitech.net>
** 
** Started on  Sun Apr 12 12:33:56 2015 Thomas CRUVEILHER
** Last update Sun Apr 12 19:20:10 2015 Thomas CRUVEILHER
*/

#include "server.h"

int			init_socket_client()
{
  struct protoent       *protocol;
  int                   sock;

  protocol = getprotobyname("TCP");
  sock = socket(AF_INET, SOCK_STREAM, protocol->p_proto);
  return (sock);
}

void			bind_sok(int sok, char *port)
{
  struct sockaddr_in	addr;

  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_port = htons(atoi(port));
  bind(sok, (struct sockaddr *)&addr, sizeof(struct sockaddr_in));
  listen(sok, 2048);
}

void			add_client_info(t_server *server)
{
  int			id;

  id = accept(server->sok, (struct sockaddr *)(&(server->peer_addr)),
	      &(server->peer_addr_size));
  if (server->max_fd < id)
    server->max_fd = id;
  FD_SET(id, &(server->active_read_fd));
  add_user(&(server->user), id);
}

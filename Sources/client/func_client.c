/*
** func_client.c for client in /home/fouhet_k/Perso/PSU_2014_myirc/Sources/client
** 
** Made by kevin fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Fri Apr 10 11:57:05 2015 kevin fouhety
** Last update Sun Apr 12 21:16:26 2015 kevin fouhety
*/

#include "client.h"

void	init_socket_server(char *cmd, t_client *client)
{
  char	*adress;
  char	*port;

  adress = pars_addr(cmd);
  port = pars_port(cmd);
  client->addr.sin_family = AF_INET;
  client->addr.sin_addr.s_addr = inet_addr(adress);
  client->addr.sin_port = htons(atoi(port));
  client->fd_connect = connect(client->sok,
			       (struct sockaddr *)&(client->addr),
			       sizeof(client->addr));
  if (client->fd_connect < 0)
    printf("could not connect to serveur %s:%s\n", adress, port);
  else
    {
      client->is_co = 1;
      client->fd_client = client->fd_connect;
      if (client->sok > client->nb_fd)
	client->nb_fd = client->sok;
    }
  free(adress);
  free(port);
}

void	private_msg(char *cmd, t_client *client)
{
  char	*new_cmd;

  new_cmd = get_send_cmd(cmd, "PRIVMSG ");
  dprintf(client->sok, "%s\r\n", new_cmd);
  free(new_cmd);
}

void	accept_file(char *cmd, t_client *client)
{
  char	*new_cmd;

  new_cmd = get_send_cmd(cmd, "ACCF ");
  dprintf(client->sok, "%s\r\n", new_cmd);
  free(new_cmd);
}

void	send_file(char *cmd, t_client *client)
{
  char	*new_cmd;

  new_cmd = get_send_cmd(cmd, "SENDF ");
  dprintf(client->sok, "%s\r\n", new_cmd);
  free(new_cmd);
}

void	send_msg(char *cmd, t_client *client)
{
  dprintf(client->sok, "%s\r\n", cmd);
}

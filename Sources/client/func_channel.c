/*
** func_channel.c for channel in /home/fouhet_k/Perso/PSU_2014_myirc/Sources/client
** 
** Made by kevin fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Fri Apr 10 11:52:53 2015 kevin fouhety
** Last update Fri Apr 10 14:40:10 2015 kevin fouhety
*/

#include "client.h"

void	list_channel_server(char *cmd, t_client *client)
{
  char	*new_cmd;

  new_cmd = get_send_cmd(cmd, "LIST ");
  dprintf(client->sok, "%s\r\n", new_cmd);
  free(new_cmd);
}

void	join_channel_server(char *cmd, t_client *client)
{
  char	*new_cmd;

  new_cmd = get_send_cmd(cmd, "JOIN ");
  dprintf(client->sok, "%s\r\n", new_cmd);
  free(new_cmd);
}

void	part_channel_server(char *cmd, t_client *client)
{
  char	*new_cmd;

  new_cmd = get_send_cmd(cmd, "PART ");
  dprintf(client->sok, "%s\r\n", new_cmd);
  free(new_cmd);
}

void	list_user_channel(char *cmd, t_client *client)
{
  char	*new_cmd;

  new_cmd = get_send_cmd(cmd, "NAMES ");
  dprintf(client->sok, "%s\r\n", new_cmd);
  free(new_cmd);
}

void	init_name_client(char *cmd, t_client *client)
{
  char	*new_cmd;

  new_cmd = get_send_cmd(cmd, "NICK ");
  dprintf(client->sok, "%s\r\n", new_cmd);
  free(new_cmd);
}

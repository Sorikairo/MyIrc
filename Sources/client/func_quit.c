/*
** func_quit.c for quit in /home/fouhet_k/Perso/PSU_2014_myirc/Sources/client
** 
** Made by kevin fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Sun Apr 12 21:16:36 2015 kevin fouhety
** Last update Sun Apr 12 21:16:42 2015 kevin fouhety
*/

#include "client.h"

void	quit_client(char *cmd, t_client *client)
{
  char  *new_cmd;

  new_cmd = get_send_cmd(cmd, "QUIT");
  dprintf(client->sok, "%s\r\n", new_cmd);
  free(new_cmd);
}

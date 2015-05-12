/*
** parsing_addr.c for pars in /home/fouhet_k/Perso/PSU_2014_myirc/Sources/client
** 
** Made by kevin fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Sun Apr 12 21:16:50 2015 kevin fouhety
** Last update Sun Apr 12 21:17:22 2015 kevin fouhety
*/

#include "client.h"

char	*pars_addr(char *cmd)
{
  int	i;
  int	n;
  char	*ret;

  i = 0;
  while (cmd[i] != '\0' && cmd[i] != ' ')
    i++;
  if (cmd[i] == ' ')
    i++;
  n = i;
  while (cmd[i]!= '\0' && cmd[i] != ':')
    i++;
  ret = xmalloc(i - n + 1);
  strncpy(ret, &(cmd[n]), (i - n));
  return (ret);
}

char	*pars_port(char *cmd)
{
  int	i;
  int	n;
  char	*ret;

  i = 0;
  while (cmd[i] != '\0' && cmd[i] != ':')
    i++;
  if (cmd[i] == ':')
    i++;
  n = i;
  while (cmd[i]!= '\0' && cmd[i] != '\n')
    i++;
  ret = xmalloc(i - n + 1);
  strncpy(ret, &(cmd[n]), (i - n));
  return (ret);
}

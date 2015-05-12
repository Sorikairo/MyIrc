/*
** utils.c for utils in /home/fouhet_k/Perso/PSU_2014_myirc
** 
** Made by kevin fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Fri Apr 10 12:12:09 2015 kevin fouhety
** Last update Sun Apr 12 21:31:59 2015 kevin fouhety
*/

#include "utils.h"
#include "stdio.h"

void	*xmalloc(int size)
{
  void	*ret;

  if ((ret = malloc(size)) == NULL)
    {
      write(2, "Error on malloc\n", 16);
      exit(EXIT_FAILURE);
    }
  memset(ret, 0, size);
  return (ret);
}

char	*init_name(char *name)
{
  char	*ret;

  ret = xmalloc(strlen(name) + 1);
  strcpy(ret, name);
  return (ret);
}

char    *get_send_cmd(char *cmd, char *new)
{
  int   i;
  char  *ret;

  i = 0;
  ret = xmalloc(strlen(cmd) + strlen(new) + 1);
  while (cmd[i] == ' ')
    i++;
  while (cmd[i] != ' ' && cmd[i] != '\0')
    i++;
  while (cmd[i] == ' ')
    i++;
  strcpy(ret, new);
  strcat(ret, &(cmd[i]));
  return (ret);
}

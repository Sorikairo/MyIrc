/*
** list_func.h for list in /home/fouhet_k/Perso/PSU_2014_myirc
** 
** Made by kevin fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Wed Apr  8 08:50:48 2015 kevin fouhety
** Last update Sun Apr 12 12:50:30 2015 Thomas CRUVEILHER
*/

#ifndef LIST_FUNC_H_
# define LIST_FUNC_H_

# include <stdlib.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <sys/time.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <netinet/in.h>
# include <netinet/ip.h>
# include "utils.h"

typedef struct s_client
{
  int		is_co;
  int		nb_fd;
  fd_set	fd;
  int		sok;
  int		fd_client;
  int		fd_connect;
  char		*name;
  struct sockaddr_in addr;
}t_client;

typedef void	(*fptr)(char *, t_client *);

typedef struct	s_list
{
  char          *name;
  fptr		cmd;
  struct s_list *next;
}               t_list;

t_list		*init_list(char *name, fptr cmd);
void		add_to_list(t_list *list, char *name, fptr cmd);
fptr		find_cmd(t_list *list, char *name);
void		destroy_list(t_list *list);

#endif

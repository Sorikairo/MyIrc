/*
** client.h for client in /home/fouhet_k/Perso/PSU_2014_myirc
** 
** Made by kevin fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Fri Apr 10 11:49:39 2015 kevin fouhety
** Last update Fri Apr 10 14:15:19 2015 kevin fouhety
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include <stdio.h>
# include "list_func.h"

# define PRINT_ERROR(a) fprintf(stderr, "%s\n", a)

typedef struct s_read
{
  int fd_pos;
  char *pars;
  int n;
}t_read;

void	init_socket_server(char *cmd, t_client *client);

void	list_channel_server(char *cmd, t_client *client);
void	join_channel_server(char *cmd, t_client *client);
void	part_channel_server(char *cmd, t_client *client);
void	list_user_channel(char *cmd, t_client *client);

void	init_name_client(char *cmd, t_client *client);
void	private_msg(char *cmd, t_client *client);

void	accept_file(char *cmd, t_client *client);
void	send_file(char *cmd, t_client *client);
void	send_msg(char *cmd, t_client *client);

void	quit_client(char *cmd, t_client *client);

char	*pars_addr(char *cmd);
char	*pars_port(char *cmd);

#endif

/*
** server.h for myirc in /home/cruvei_t/PSU_2014_myirc/Includes
** 
** Made by Thomas CRUVEILHER
** Login   <cruvei_t@epitech.net>
** 
** Started on  Thu Apr  9 12:54:45 2015 Thomas CRUVEILHER
** Last update Sun Apr 12 23:19:19 2015 Thomas CRUVEILHER
*/

#ifndef SERVER_H_
# define SERVER_H_

# include <stdio.h>
# include <stdlib.h>
# include <sys/select.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netinet/ip.h>
# include <arpa/inet.h>
# include <netdb.h>
# include "buffer.h"
# include "utils.h"
# include "list_server_func.h"

# define USER_NAME 18
# define CHANNEL_NAME 30

typedef struct s_user
{
  int			id;
  char			*name;
  t_buffer		buffer;
  int			channel;
  struct s_user		*next;
} t_user;

typedef struct s_channel
{
  int			id;
  char			*name;
  struct s_channel	*next;
}t_channel;

struct s_server
{
  int			sok;
  int			cfs;
  struct sockaddr_in	peer_addr;
  socklen_t		peer_addr_size;
  int			max_fd;
  fd_set		active_read_fd;
  fd_set		active_write_fd;
  fd_set		read_fd;
  fd_set		write_fd;
  t_list		*list;
  t_channel		*channel;
  t_user		*user;
};

int	init_socket_client();
void	bind_sok(int, char *);
t_list	*create_list_cmd();
void	add_client_info(t_server *);
void	add_user(t_user **, int);
void	add_channel(t_channel **, char *, int);

void	init_name_client(t_server *server, char *cmd, int id);
void	list_channel_server(t_server *server, char *cmd, int id);
void	join_channel_server(t_server *server, char *cmd, int id);
void	part_channel_server(t_server *server, char *cmd, int id);

void	send_msg(t_server *server, char *cmd, int id);
void	list_user_channel(t_server *server, char *cmd, int id);
void	private_msg(t_server *server, char *cmd, int id);
void	send_file(t_server *server, char *cmd, int id);
void	accept_file(t_server *server, char *cmd, int id);
void	quit_client(t_server *server, char *cmd, int id);

void	add_channel(t_channel **, char *, int);
void	list_channel(t_channel **, int);
int	get_channel_id(t_channel **, char *);

void	add_user(t_user **, int);
void	change_user_nick(t_user **, int, char *);
void	set_channel(t_user **, int, int);
int	get_max_id(t_channel **);
int	get_channel(t_user **, int);
char	*get_nickname(t_user **, int);
void	list_channel_user(t_user **, int, int);
int	get_user_id(t_user **, char *);
char	*get_channel_name(t_channel **, int);
#endif

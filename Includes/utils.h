/*
** utils.h for utils in /home/fouhet_k/Perso/PSU_2014_myftp/header
** 
** Made by kevin fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Thu Mar 12 11:49:00 2015 kevin fouhety
** Last update Sat Apr 11 09:34:38 2015 Thomas CRUVEILHER
*/

#ifndef UTILS_H_
# define UTILS_H_

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

void	*xmalloc(int size);
char	*init_name(char *name);
char	*get_send_cmd(char *cmd, char *new);

int dprintf(int fd, const char *format, ...);

#endif

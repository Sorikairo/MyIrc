/*
** buffer.h for myirc in /home/cruvei_t/PSU_2014_myirc/Includes
** 
** Made by Thomas CRUVEILHER
** Login   <cruvei_t@epitech.net>
** 
** Started on  Sat Apr 11 09:34:15 2015 Thomas CRUVEILHER
** Last update Sat Apr 11 16:38:25 2015 Thomas CRUVEILHER
*/

#ifndef BUFFER_H_
# define BUFFER_H_

#define BUFFER_SIZE 4096

typedef struct s_buffer
{
  char	*buffer;
  int	reading;
  int	writing;
  int	size;
}t_buffer;

int	content_rlrf(t_buffer*);
int	content_rn(t_buffer*);

char	*read_buffer(t_buffer *buffer, char delim);
int	write_buffer(t_buffer *buffer, int fd, char deli);
void	init_buffer(t_buffer *buffer);

#endif

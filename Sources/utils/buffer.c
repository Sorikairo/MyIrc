/*
** buffer.c for myirc in /home/cruvei_t/PSU_2014_myirc/Sources/utils
** 
** Made by Thomas CRUVEILHER
** Login   <cruvei_t@epitech.net>
** 
** Started on  Sat Apr 11 09:35:03 2015 Thomas CRUVEILHER
** Last update Sun Apr 12 15:26:32 2015 Thomas CRUVEILHER
*/

#include <stdio.h>
#include <sys/socket.h>
#include "buffer.h"
#include "utils.h"

void	init_buffer(t_buffer *buffer)
{
  buffer->size = BUFFER_SIZE + 1;
  buffer->buffer = malloc(buffer->size);
  buffer->writing = 0;
  buffer->reading = -1;
}

char	*read_buffer(t_buffer *buffer, char delim)
{
  char	*return_buffer;
  int	i;

  i = 0;
  return_buffer = xmalloc((buffer->writing > buffer->reading) ?
			 buffer->writing - buffer->reading + 1:
			 (buffer->size - (buffer->reading - buffer->writing) + 1));
  while ((buffer->reading = buffer->reading + 1) != buffer->writing)
    {
      buffer->reading = buffer->reading % buffer->size;
      return_buffer[i] = buffer->buffer[buffer->reading];
      if ((delim == 0 && return_buffer[i] == '\n')
	  || (delim == 1 && return_buffer[i] == '\n' && return_buffer[i - 1] == '\r'))
	{
	  if (delim == 1)
	    return_buffer[i - 1] = '\0';
	  else
	    return_buffer[i] = '\0';
	  return (return_buffer);
	}
      i++;
    }
  buffer->reading--;
  return_buffer[i] = '\0';
  return (return_buffer);
}

void	increase_buffer_size(t_buffer *buffer)
{
  char	*new_buffer;
  int	i;

  i = 0;
  new_buffer = xmalloc(buffer->size * 2 + 1);
  while ((buffer->reading += 1) != buffer->writing)
    {
      new_buffer[i] = buffer->buffer[buffer->reading];
      i++;
    }
  buffer->size = buffer->size * 2 + 1;
  buffer->reading = 0;
  buffer->writing = i;
  free(buffer->buffer);
  buffer->buffer = new_buffer;
}

int	write_buffer(t_buffer *buf, int fd, char delim)
{
  int	i;
  char	command[513];

  i = read(fd, &command, 512);
  if (i == -1)
    return (-1);
  command[i] = '\0';
  i = 0;
  while (command[i] != '\0')
    {
      buf->writing = buf->writing % buf->size;
      if (buf->writing == buf->reading)
	increase_buffer_size(buf);
      buf->buffer[buf->writing] = command[i];
      i++;
      buf->writing++;
    }
  if (delim == 1 && content_rlrf(buf) == 1)
    return (2);
  if (delim != 1 && content_rn(buf) == 1)
    return (1);
  return (3);
}

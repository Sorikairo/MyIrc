/*
** check_content.c for myirc in /home/cruvei_t/PSU_2014_myirc/Sources/utils
** 
** Made by Thomas CRUVEILHER
** Login   <cruvei_t@epitech.net>
** 
** Started on  Sat Apr 11 14:47:47 2015 Thomas CRUVEILHER
** Last update Sat Apr 11 17:42:40 2015 Thomas CRUVEILHER
*/

#include <stdio.h>
#include "buffer.h"

int	content_rlrf(t_buffer *buffer)
{
  int	i;

  i = (buffer->reading + 1) % buffer->size;
  while (i != buffer->writing)
    {
      i = i % buffer->size;
      if (buffer->buffer[i] == '\r')
	if (buffer->buffer[(i + 1) % buffer->size] == '\n')
	  return (1);
      i++;
    }
  return (0);
}

int	content_rn(t_buffer *buffer)
{
  int	i;

  i = (buffer->reading + 1) % buffer->size;
  while (i != buffer->writing)
    {
      i = i % buffer->size;
      if (buffer->buffer[i] == '\n')
	return (1);
      i++;
    }
  return (0);
}

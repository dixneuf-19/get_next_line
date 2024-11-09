/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:40:47 by mzary             #+#    #+#             */
/*   Updated: 2024/11/09 20:00:06 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	contains_end(t_buffer *p_buffer)
{
	ssize_t	i;

	if (p_buffer->length == 0 || p_buffer->length == -1)
		return (p_buffer->length);
	i = 0;
	if (p_buffer->length < BUFFER_SIZE)
		return (1);
	while (i < BUFFER_SZIE)
	{
		if ((p_buffer->content)[i] == '\n')
		{
			p_buffer->size = i + 1;
			return (1);
		}
		i++;
	}
	return (0);
}

static ssize_t	line_length(t_buffer *p_surplus)
{
	ssize_t		length;
	t_buffer	*p_buffer;

	length = 0;
	p_buffer = p_surplus;
	while (p_buffer)
	{
		length += p_buffer.length;
		p_buffer = p_buffer->next;
	}
	return (length);
}

static void	free_buffers(t_buffer *p_surplus)
{
	t_buffer	*p_buffer;
	t_buffer	*p_nbuffer;

	p_buffer = p_surplus->next;
	while (p_buffer)
	{
		p_nbuffer = p_buffer->next;
		free(p_buffer);
		p_buffer = p_nbuffer;
	}
}

char	*return_line(t_buffer *p_surplus)
{
	t_buffer	*p_buffer;
	ssize_t		length;
	char		*line;
	ssize_t			i;
	int			j;

	length = line_length(p_surplus);
	line = (char *)malloc(sizeof(char) * (length + 1));
	if (!line || !length)
		return (NULL);
	j = 0;
	p_buffer = p_surplus;
	while (p_buffer)
	{
		i = 0;
		while (i < p_buffer->size)
		{
			line[j] = (p_buffer->content)[i];
			i++;
			j++;
		}
		p_buffer = p_buffer->next;
	}
	line[j] = '\0';
	free_buffers(p_surplus);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 02:58:30 by mzary             #+#    #+#             */
/*   Updated: 2024/11/08 05:48:25 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_buffer(t_buffer *p_buffer)
{
	int	i;

	if (p_buffer->size < BUFFER_SIZE)
		return (0);
	i = 0;
	while (i < BUFFER_SIZE)
	{
		if ((p_buffer->buffer)[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

void	free_buffers(t_buffer *p_start)
{
	while (p_start)
	{
		free(p_start);
		p_start = p_start->next;
	}
}

void	link_buffer(t_buffer *p_start, t_buffer *p_buffer)
{
	if (p_start == p_buffer)
		p_buffer->next = NULL;
	else
	{
		while (p_start->next)
		{
			p_start = p_start->next;
		}
		p_start->next = p_buffer;
		p_buffer->next = NULL;
	}
}

static ssize_t	count_len(t_buffer *p_start)
{
	ssize_t	length;
	ssize_t	i;

	length = 0;
	while (p_start->next)
	{
		length += BUFFER_SIZE;
		p_start = p_start->next;
	}
	while (i < p_start->size)
	{
		if ((p_start->buffer)[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	length += i;
	return (length);
}

char	*deduce_line(t_buffer *p_start)
{
	char		*line;
	ssize_t		i;
	ssize_t		j;
	ssize_t		len;
	t_buffer	*p_buffer;

	len = count_len(p_start);
	p_buffer = p_start;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line || len == 0)
		return (free(line), NULL);
	j = 0;
	while (p_buffer)
	{
		i = 0;
		while (i < p_buffer->size && j < len)
		{
			line[j] = (p_buffer->buffer)[i];
			i++;
			j++;
		}
		p_buffer = p_buffer->next;
	}
	return (free_buffers(p_start), line);
}

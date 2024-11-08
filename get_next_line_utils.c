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

int	check_buffer(char buffer[BUFFER_SIZE], ssize_t b_read)
{
	int	i;

	if (b_read < BUFFER_SIZE)
		return (0);
	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buffer[i] == '\n')
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

static ssize_t	count_length(t_buffer *p_start)
{
	ssize_t	length;
	int		i;

	length = 0;
	while (p_start)
	{
		i = 0;
		while ((p_start->buffer)[i] != '\n')
			i++;
		length += i;
		p_start = p_start->next;
	}
	return (length + 1);
}

char	*deduce_line(t_buffer *p_start)
{
	char	*line;

	line = (char *)malloc;
}

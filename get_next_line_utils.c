/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:40:47 by mzary             #+#    #+#             */
/*   Updated: 2024/11/09 21:41:53 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	link_buffer(t_buffer *p_surplus, t_buffer *p_buffer)
{
	if (p_surplus == p_buffer)
		p_surplus->next = NULL;
	else
	{
		while (p_surplus->next)
			p_surplus = p_surplus->next;
		p_surplus->next = p_buffer;
		p_buffer->next = NULL;
	}
}

static ssize_t	line_length(t_buffer *p_surplus)
{
	ssize_t		t_length;
	t_buffer	*p_buffer;
	ssize_t		i;

	t_length = 0;
	p_buffer = p_surplus;
	while (p_buffer)
	{
		i = 0;
		while ((p_buffer->content)[i] != '\n' && i < p_buffer->length)
			i++;
		t_length += i + (i != p_buffer->length);
		p_buffer = p_buffer->next;
	}
	return (t_length);
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

static void	save_surplus(t_buffer *p_surplus)
{
	t_buffer	*p_buffer;
	ssize_t		i;
	ssize_t		r;

	p_buffer = p_surplus;
	while ((p_buffer->next)->length)
		p_buffer = p_buffer->next;
	i = 0;
	while ((p_buffer->content)[i] != '\n' && i < p_buffer->length)
		i++;
	if (i == p_buffer->length)
		p_surplus->length = 0;
	i++;
	while (i < p_buffer->length)
	{
		(p_surplus->content)[r] = (p_buffer->content)[i];
		i++;
		r++;
	}
	p_surplus->length = r;
}

char	*return_line(t_buffer *p_surplus)
{
	t_buffer	*p_buffer;
	ssize_t		length;
	char		*line;
	ssize_t		i;
	int			j;

	length = line_length(p_surplus);
	line = (char *)malloc(sizeof(char) * (length + 1));
	if (!line || !length)
		return (NULL);
	j = 0;
	p_buffer = p_surplus;
	while (p_buffer->length)
	{
		i = 0;
		while (i < p_buffer->length)
		{
			line[j] = (p_buffer->content)[i];
			i++;
			j++;
		}
		p_buffer = p_buffer->next;
	}
	line[j] = '\0';
	return (save_surplus(p_surplus), free_buffers(p_surplus), line);
}

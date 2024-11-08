/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 02:58:25 by mzary             #+#    #+#             */
/*   Updated: 2024/11/08 05:44:09 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_buffer	*p_buffer;
	t_buffer	*p_start;
	int			middle;

	if (fd < 0)
		return (NULL);
	p_start = p_buffer;
	middle = 0;
	while (!middle++ || check_buffer(p_buffer->buffer, b_read))
	{
		p_buffer = (t_buffer *)malloc(sizeof(t_buffer));
		if (!p_buffer)
		{
			if (middle)
				free_buffers(p_start);
			return (NULL);
		}
		p_buffer->size = read(fd, p_buffer->buffer, BUFFER_SIZE);
		if (p_buffer->size == -1)
			return (NULL);
		link_buffer(p_start, p_buffer);
	}
	return (deduce_line(p_start));
}

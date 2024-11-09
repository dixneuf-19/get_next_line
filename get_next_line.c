/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:40:39 by mzary             #+#    #+#             */
/*   Updated: 2024/11/09 21:38:48 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(int fd, t_buffer *p_surplus)
{
	t_buffer	*p_buffer;
	int			first;

	first = 0;
	while (!(first++) || !(p_buffer->length))
	{
		p_buffer = (t_buffer *)malloc(sizeof(t_buffer));
		if (!p_buffer)
			return (NULL);
		p_buffer->length = read(fd, p_buffer->content, BUFFER_SIZE);
		if (p_buffer->length == -1)
			return (NULL);
		link_buffer(p_surplus, p_buffer);
	}
	return (return_line(p_surplus));
}

char    *get_next_line(int fd)
{
    static t_buffer surplus;

	if (fd < 0)
		return (NULL);
	return (get_line(fd, &surplus));
}

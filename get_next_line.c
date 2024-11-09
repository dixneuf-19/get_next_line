/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:40:39 by mzary             #+#    #+#             */
/*   Updated: 2024/11/09 20:00:09 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(int fd, t_buffer *p_surplus)
{
	t_buffer	*p_buffer;

	if (contains_end(p_surplus))
		return (return_line(p_surplus));
}

char    *get_next_line(int fd)
{
    static t_buffer surplus;

	surplus.next = NULL;
	if (fd < 0)
		return (NULL);
	return (get_line(fd, &surplus));
}

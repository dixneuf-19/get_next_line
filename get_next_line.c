/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:40:39 by mzary             #+#    #+#             */
/*   Updated: 2024/11/17 02:56:06 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	check_plus(t_buff *p_plus)
{
	ssize_t	i;

	p_plus->end = 0;
	i = 0;
	while (i < p_plus->length)
	{
		if ((p_plus->content)[i] == '\n')
		{
			p_plus->end = 1;
			break ;
		}
		i++;
	}
}

static char	*get_line(int fd, t_buff *p_plus)
{
	t_buff	*p_buff;

	check_plus(p_plus);
	p_buff = p_plus;
	while (!(p_buff->end))
	{
		p_buff = (t_buff *)malloc(sizeof(t_buff));
		if (!p_buff)
		{
			free_buff(p_plus);
			return (NULL);
		}
		p_buff->length = read(fd, p_buff->content, BUFFER_SIZE);
		if (p_buff->length == -1)
		{
			p_plus->length = 0;
			free(p_buff);
			free_buff(p_plus);
			return (NULL);
		}
		link_check_buff(p_plus, p_buff);
	}
	return (return_line(p_plus));
}

char	*get_next_line(int fd)
{
	static t_buff	plus;

	if (read(fd, NULL, 0) == -1)
	{
		plus.length = 0;
		return (NULL);
	}
	if (BUFFER_SIZE <= 0)
		return (NULL);
	plus.next = NULL;
	return (get_line(fd, &plus));
}

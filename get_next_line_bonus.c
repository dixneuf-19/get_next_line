/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:40:39 by mzary             #+#    #+#             */
/*   Updated: 2024/11/09 21:38:48 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	check_plus(t_buff *p_plus)
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

static void	set_zero(t_buff *p_plus)
{
	ssize_t	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		(p_plus->content)[i] = 0;
		i++;
	}
	p_plus->length = 0;
	p_plus->end = 0;
	p_plus->next = NULL;
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
			set_zero(p_plus);
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
	static t_buff	plus[13000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	plus[fd].next = NULL;
	return (get_line(fd, plus + fd));
}

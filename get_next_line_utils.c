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

void	link_check_buff(t_buff *p_plus, t_buff *p_buff)
{
	ssize_t		i;

	while (p_plus->next)
		p_plus = p_plus->next;
	p_plus->next = p_buff;
	p_buff->next = NULL;
	i = 0;
	while (i < p_buff->length)
	{
		if ((p_buff->content)[i] == '\n')
		{
			p_buff->end = 1;
			break ;
		}
		i++;
	}
	if (i == p_buff->length && i < BUFFER_SIZE)
		p_buff->end = 1;
	else if (i == BUFFER_SIZE)
		p_buff->end = 0;
}

static size_t	line_length(t_buff *p_plus)
{
	size_t		t_length;
	t_buff		*p_buff;
	ssize_t		i;

	t_length = 0;
	p_buff = p_plus;
	while (!(p_buff->end))
	{
		t_length += p_buff->length;
		p_buff = p_buff->next;
	}
	i = 0;
	while (i < p_buff->length && (p_buff->content)[i] != '\n')
		i++;
	t_length += i + (i != p_buff->length);
	return (t_length);
}

void	free_buff(t_buff *p_plus)
{
	t_buff	*p_buff;
	t_buff	*p_nbuff;

	p_buff = p_plus->next;
	while (p_buff)
	{
		p_nbuff = p_buff->next;
		free(p_buff);
		p_buff = p_nbuff;
	}
}

static void	save_plus(t_buff *p_plus, t_buff *p_last, char *line, ssize_t j)
{
	ssize_t		i;

	i = 0;
	while (i < p_last->length)
	{
		line[j] = (p_last->content)[i];
		if (line[j] == '\n')
		{
			i++;
			j++;
			break ;
		}
		i++;
		j++;
	}
	line[j] = '\0';
	j = i;
	while (j < p_last->length)
	{
		(p_plus->content)[j - i] = (p_last->content)[j];
		j++;
	}
	p_plus->length = j - i;
}

char	*return_line(t_buff *p_plus)
{
	t_buff		*p_buff;
	size_t		length;
	char		*line;
	ssize_t		i;
	ssize_t		j;

	length = line_length(p_plus);
	line = (char *)malloc(sizeof(char) * (length + 1));
	if (!line)
		return (free_buff(p_plus), NULL);
	else if (!length)
		return (free(line), free_buff(p_plus), NULL);
	j = 0;
	p_buff = p_plus;
	while (!(p_buff->end))
	{
		i = 0;
		while (i < p_buff->length)
			line[j++] = (p_buff->content)[i++];
		p_buff = p_buff->next;
	}
	return (save_plus(p_plus, p_buff, line, j), free_buff(p_plus), line);
}

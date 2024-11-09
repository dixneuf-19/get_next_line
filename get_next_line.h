/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 02:58:21 by mzary             #+#    #+#             */
/*   Updated: 2024/11/08 21:08:34 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

typedef struct s_buffer
{
	char			buffer[BUFFER_SIZE];
	ssize_t			size;
	struct s_buffer	*next;
}				t_buffer;

char	*get_next_line(int fd);

int		check_buffer(t_buffer *p_buffer);
void	free_buffers(t_buffer *p_start);
void	link_buffer(t_buffer *p_start, t_buffer *p_buffer);
char	*deduce_line(t_buffer *p_start);

#endif

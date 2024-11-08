/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 02:58:21 by mzary             #+#    #+#             */
/*   Updated: 2024/11/08 05:43:32 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE

# define BUFFER_SIZE 42

# endif

typedef struct s_buffer
{
	char			buffer[BUFFER_SIZE];
	ssize_t			size;
	struct s_buffer	*next;
}				t_buffer;

char	*get_next_line(int fd);

#endif

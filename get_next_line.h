/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:40:56 by mzary             #+#    #+#             */
/*   Updated: 2024/11/09 19:32:16 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# endif

typedef struct  s_buffer
{
	char			content[BUFFER_SIZE];
	ssize_t				length;
	struct s_buffer	*next;
}               t_buffer;

char    *get_next_line(int fd);



#endif

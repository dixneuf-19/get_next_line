/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:40:56 by mzary             #+#    #+#             */
/*   Updated: 2024/11/17 23:30:13 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_buff
{
	char			content[BUFFER_SIZE];
	ssize_t			length;
	char			end;
	struct s_buff	*next;
}				t_buff;

char	*get_next_line(int fd);

void	link_check_buff(t_buff *p_plus, t_buff *p_buff);
char	*return_line(t_buff *p_plus);
void	free_buff(t_buff *p_plus);

#endif

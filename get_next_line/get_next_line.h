/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 13:11:03 by vchesnea          #+#    #+#             */
/*   Updated: 2015/12/24 10:59:58 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE	32

typedef struct			s_linebuffer
{
	int					fd;
	size_t				size;
	char				*data;
	struct s_linebuffer	*next;
}						t_linebuffer;

int						get_next_line(const int fd, char **line);

#endif

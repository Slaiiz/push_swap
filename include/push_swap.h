/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 17:13:20 by vchesnea          #+#    #+#             */
/*   Updated: 2016/03/09 17:13:23 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define STACK_INC_FACTOR	 8

# define F_VERBOSE			 1
# define F_COLOR			 2
# define F_GAME				 4

# define O_SA				 1
# define O_SB				 2
# define O_SS				 4
# define O_PA				 4
# define O_PB				 5
# define O_RA				 6
# define O_RB				 7
# define O_RR				 8
# define O_RRA				 9
# define O_RRB				10
# define O_RRR				11

# define A					 1
# define B					 2
# define S					 3
# define R					 S

# define FORWARD			 1
# define REVERSE			-1

typedef struct	s_stack
{
	int	*data;
	int	size;
	int	len;
}				t_stack;

typedef struct	s_couple
{
	char	ops[];
	t_stack	a;
	t_stack	b;
}				t_couple;

#endif

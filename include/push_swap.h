/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 17:13:20 by vchesnea          #+#    #+#             */
/*   Updated: 2016/03/10 16:35:17 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define INC_FACTOR			 8

# define F_VERBOSE			 1
# define F_COLOR			 2
# define F_GAME				 4
# define F_ERRORS			 8

# define O_SA				 1
# define O_SB				 2
# define O_SS				 3
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
# define S					16
# define R					 S

# define FORWARD			 1
# define REVERSE			-1

# define ERR_INVARGS		 1
# define ERR_INITFAIL		 2
# define ERR_SORTFAIL		 3
# define ERR_MALLOC			 4
# define ERR_PUSHFAIL		 5
# define ERR_ROTATEFAIL		 6
# define ERR_REVERSEFAIL	 7
# define ERR_LENFAIL		 8

typedef struct	s_stack
{
	int	len;
	int	size;
	int	*data;
}				t_stack;

typedef struct	s_couple
{
	t_stack	a;
	t_stack	b;
	int		len;
	int		size;
	char	*ops;
	char	*strings[11];
}				t_couple;

int				stack_push(t_stack *s, int n);
int				stack_pop(t_stack *s, int *n);
void			stack_set(t_stack *s, int i, int n);
int				stack_get(t_stack *s, int i);
int				stack_rotate(t_stack *s, int n);

int				__swap(t_couple *c, int o);
int				__push(t_couple *c, int o);
int				__rotate(t_couple *c, int o);
int				__reverse_rotate(t_couple *c, int o);

#endif

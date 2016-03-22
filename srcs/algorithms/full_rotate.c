/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 12:07:50 by vchesnea          #+#    #+#             */
/*   Updated: 2016/03/20 12:07:52 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** I noticed this one algorithm is very efficient with little stacks no more
** than five/six numbers, beyond, complexity grows pretty much exponentially,
** so you'd be better off working with stack_spill().
** Stack B is not used here.
*/

static void	reorder_stack(t_couple *c)
{
	int	i;
	int	s;

	i = stack_find(&c->a, c->a.max, EQUAL);
	if ((s = i && 1) && c->flags & F_VERBOSE)
		ft_printf("[{{red;b}}REORDERING STACK{{eoc;}}]\n");
	if ((i <= c->a.len / 2))
		while (i--)
			RRA;
	else if ((i = c->a.len - i))
		while (i--)
			RA;
	if (s && c->flags & F_VERBOSE)
		ft_printf("[{{red;b}}----- DONE -----{{eoc;}}]\n");
}

int			algorithm_full_rotate(t_couple *c)
{
	int	i;
	int	n;

	while (!stack_is_ordered(&c->a))
	{
		n = c->a.min;
		i = stack_find(&c->a, n, EQUAL);
		while (1)
		{
			if (i > 0 && n > c->a.data[i - 1])
			{
				while (i + 1 != c->a.len && ++i)
					RA;
				SA;
			}
			if ((i = stack_find(&c->a, n, GREATER)) == -1)
				break ;
			reorder_stack(c);
			n = c->a.data[i];
		}
	}
	return (0);
}

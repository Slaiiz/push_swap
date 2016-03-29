/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_spill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 12:07:55 by vchesnea          #+#    #+#             */
/*   Updated: 2016/03/20 12:07:56 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Complexity gets roughly logarithmic with this algorithm, while that sounds
** great, it's not suitable for short stacks, where pushing a to b then the
** inverse makes up a gigantic overhead (more than 70% of operations)
** for very little gain. Even then there's just so much overhead in general
** from this very naive approach.
** --------------------------------------------------------------------------
** Data sampled with a random number generator:
** numbers | operations | increase factor
**      10 |         34 | initial
**      20 |         97 | x2.80
**      30 |        164 | x1.69
**      40 |        272 | x1.65
**      50 |        447 | x1.64
**      60 |        611 | x1.36
**      70 |        753 | x1.23
**      80 |       1015 | x1.57
**      90 |       1160 | x1.14
**     100 |       1468 | x1.26
*/

static int	send_all_to_b(t_couple *c)
{
	int	i;

	while (c->a.len)
	{
		if (((i = stack_find(&c->b, c->a.data[c->a.len - 1], LESS)) != -1)
			|| ((i = stack_find(&c->b, c->b.max, EQUAL)) != -1))
		{
			if (i + 1 < c->b.len / 2 && (i = i + 1))
				while (i--)
					RRB;
			else if ((i = c->b.len - (i + 1)))
				while (i--)
					RB;
		}
		PB;
	}
	i = stack_find(&c->b, c->b.max, EQUAL);
	if (i + 1 < c->b.len / 2 && (i = i + 1))
		while (i--)
			RRB;
	else if ((i = c->b.len - (i + 1)))
		while (i--)
			RB;
	return (0);
}

static int	retrieve_all_from_b(t_couple *c)
{
	while (c->b.len)
	{
		if (PA)
			return (print_error(ERR_RETRIEVEALL, "Undefined"));
	}
	return (0);
}

int			algorithm_stack_spill(t_couple *c)
{
	if (send_all_to_b(c) || retrieve_all_from_b(c))
		return (print_error(ERR_STACKSPILL, "Undefined"));
	return (0);
}

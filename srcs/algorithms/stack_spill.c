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

static void	check_rotation(t_couple *c)
{
	int	i;

	i = stack_find(&c->b, c->b.max, EQUAL);
	if (i + 1 < c->b.len / 2 && (i = i + 1))
		while (i--)
			RRB;
	else if ((i = c->b.len - (i + 1)))
		while (i--)
			RB;
}

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
	check_rotation(c);
	return (0);
}

static int	retrieve_all_from_b(t_couple *c)
{
	while (c->b.len)
	{
		if (PA)
		{
			print_error(ERR_RETRIEVEALL, DET_UNDEFINED);
			return (1);
		}
	}
	return (0);
}

int			algorithm_stack_spill(t_couple *c)
{
	if (send_all_to_b(c) || retrieve_all_from_b(c))
	{
		print_error(ERR_STACKSPILL, DET_UNDEFINED);
		return (1);
	}
	return (0);
}

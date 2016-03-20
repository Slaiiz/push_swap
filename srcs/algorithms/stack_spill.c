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

static int	check_swap(t_couple *c)
{
	if (c->a.len > 1 && (c->a.data[c->a.len - 1] > c->a.data[c->a.len - 2]))
	{
		if (SA)
		{
			print_error(ERR_CHECKSWAPFAIL, DET_UNDEFINED);
			return (1);
		}
	}
	return (0);
}

static int	check_rotation(t_couple *c)
{
	while (c->b.len > 1 && (c->b.data[c->b.len - 1] > c->a.data[c->a.len - 1]))
	{
		if (RB)
		{
			print_error(ERR_CHECKROTATEFAIL, DET_UNDEFINED);
			return (1);
		}
		if (c->b.data[c->b.len - 1] == c->b.max)
			break ;
	}
	return (0);
}

static int	send_all_to_b(t_couple *c)
{
	while (c->a.len)
	{
		if (check_swap(c) || check_rotation(c))
		{
			print_error(ERR_SENDALL, DET_UNDEFINED);
			return (1);
		}
		while (c->b.len > 1 && (c->b.data[c->b.len - 1] != c->b.max)
			&& (c->b.data[0] < c->a.data[c->a.len - 1])
			&& (c->b.data[0] > c->b.data[c->b.len - 1]))
		{
			if (RRB)
			{
				print_error(ERR_SENDALL, DET_UNDEFINED);
				return (1);
			}
		}
		if (PB)
		{
			print_error(ERR_SENDALL, DET_UNDEFINED);
			return (1);
		}
	}
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
	c->b.min = INT_MAX;
	c->b.max = INT_MIN;
	if (send_all_to_b(c) || retrieve_all_from_b(c))
	{
		print_error(ERR_STACKSPILL, DET_UNDEFINED);
		return (1);
	}
	return (0);
}

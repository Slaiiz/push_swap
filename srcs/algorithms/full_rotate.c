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

static int	stack_is_ordered(t_stack *s)
{
	int	i;

	i = s->len;
	while (i-- > 1)
		if (s->data[i] > s->data[i - 1])
			return (0);
	return (1);
}

int			algorithm_full_rotate(t_couple *c)
{
	while (!stack_is_ordered(&c->a))
	{

	}
	return (0);
}

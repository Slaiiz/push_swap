/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:34:59 by vchesnea          #+#    #+#             */
/*   Updated: 2016/03/10 16:35:00 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	register_operation(t_couple *c, int o)
{
	char	*n;

	if (c->size < (c->len + 1))
	{
		if ((n = malloc(sizeof(char) * (c->size + INC_FACTOR))) == NULL)
		{
			print_error(ERR_REGISTER, DET_MALLOC);
			return (1);
		}
		if (c->ops != NULL)
		{
			ft_memcpy(n, c->ops, c->len);
			free(c->ops);
		}
		c->size += INC_FACTOR;
		c->ops = n;
	}
	c->ops[c->len++] = o;
	if (c->flags & F_VERBOSE)
	{
		ft_printf("{{yellow}}Operation: {{eoc}}%s\n", c->strings[o - 1]);
		print_snapshot(c);
	}
	return (0);
}

int			swap(t_couple *c, int o)
{
	int		n;
	t_stack	*s;

	s = o & A ? &c->a : &c->b;
	if (o == S)
	{
		if (swap(c, A | S) || swap(c, B | S)
			|| register_operation(c, O_SS))
		{
			print_error(ERR_SWAPFAIL, DET_UNDEFINED);
			return (1);
		}
		return (0);
	}
	if (s->len < 2)
	{
		print_error(ERR_SWAPFAIL, DET_BADLEN);
		return (1);
	}
	n = s->data[s->len - 1];
	s->data[s->len - 1] = s->data[s->len - 2];
	s->data[s->len - 2] = n;
	if (!(o & S))
		if (register_operation(c, O_SA + o - 1))
		{
			print_error(ERR_SWAPFAIL, ERR_REGISTER);
			return (1);
		}
	return (0);
}

int			push(t_couple *c, int o)
{
	t_stack	*s;
	t_stack *d;
	int		 n;

	s = o & A ? &c->b : &c->a;
	d = o & A ? &c->a : &c->b;
	if (stack_pop(s, &n) || stack_push(d, n)
		|| register_operation(c, O_PA + o - 1))
	{
		print_error(ERR_PUSHFAIL, DET_UNDEFINED);
		return (1);
	}
	return (0);
}

int			rotate(t_couple *c, int o)
{
	t_stack	*s;

	s = o & A ? &c->a : &c->b;
	if (o == R)
	{
		if (rotate(c, A | R) || rotate(c, B | R)
			|| register_operation(c, O_RR))
		{
			print_error(ERR_ROTATEFAIL, DET_UNDEFINED);
			return (1);
		}
		return (0);
	}
	if (stack_rotate(s, FORWARD)
		|| (!(o & R) && register_operation(c, O_RA + o - 1)))
	{
		print_error(ERR_ROTATEFAIL, DET_UNDEFINED);
		return (1);
	}
	return (0);
}

int			reverse_rotate(t_couple *c, int o)
{
	t_stack	*s;

	s = o & A ? &c->a : &c->b;
	if (o == R)
	{
		if (reverse_rotate(c, A | R) || reverse_rotate(c, B | R)
			|| register_operation(c, O_RRR))
		{
			print_error(ERR_REVERSEFAIL, DET_UNDEFINED);
			return (1);
		}
		return (0);
	}
	if (stack_rotate(s, REVERSE)
		|| (!(o & R) && register_operation(c, O_RRA + o - 1)))
	{
		print_error(ERR_REVERSEFAIL, DET_UNDEFINED);
		return (1);
	}
	return (0);
}

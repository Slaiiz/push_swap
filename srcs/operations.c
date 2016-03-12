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
	return (0);
}

int			__swap(t_couple *c, int o)
{
	int		n;
	t_stack	*s;

	if (o & A)
		s = &c->a;
	else if (o & B)
		s = &c->b;
	else if (o == S)
	{
		if (__swap(c, A | S)
			|| __swap(c, B | S)
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
	n = stack_get(s, s->len - 1);
	stack_set(s, s->len - 1, stack_get(s, s->len - 2));
	stack_set(s, s->len - 2, n);
	if (!(o & S))
		if (register_operation(c, O_SA + o - 1))
		{
			print_error(ERR_SWAPFAIL, ERR_REGISTER);
			return (1);
		}
	return (0);
}

int			__push(t_couple *c, int o)
{
	t_stack	*s;
	t_stack *d;
	int		 n;

	if (o & A)
	{
		s = &c->b;
		d = &c->a;
	}
	else if (o & B)
	{
		s = &c->a;
		d = &c->b;
	}
	if (stack_pop(s, &n)
		|| stack_push(d, n)
		|| register_operation(c, O_PA + o - 1))
	{
		print_error(ERR_PUSHFAIL, DET_UNDEFINED);
		return (1);
	}
	return (0);
}

int			__rotate(t_couple *c, int o)
{
	t_stack	*s;

	if (o & A)
		s = &c->a;
	else if (o & B)
		s = &c->b;
	else if (o == R)
	{
		if (__rotate(c, A | R)
			||__rotate(c, B | R)
			|| register_operation(c, O_RR))
		{
			print_error(ERR_ROTATEFAIL, DET_UNDEFINED);
			return (1);
		}
	}
	if (stack_rotate(s, FORWARD)
		|| (!(o & R) && register_operation(c, O_RA + o - 1)))
	{
		print_error(ERR_ROTATEFAIL, DET_UNDEFINED);
		return (1);
	}
	return (0);
}

int			__reverse_rotate(t_couple *c, int o)
{
	t_stack	*s;

	if (o & A)
		s = &c->a;
	else if (o & B)
		s = &c->b;
	else if (o == R)
	{
		if (__reverse_rotate(c, A | R)
			|| __reverse_rotate(c, B | R)
			|| register_operation(c, O_RRR))
		{
			print_error(ERR_REVERSEFAIL, DET_UNDEFINED);
			return (1);
		}
	}
	if (stack_rotate(s, REVERSE)
		|| (!(o & R) && register_operation(c, O_RRA + o - 1)))
	{
		print_error(ERR_REVERSEFAIL, DET_UNDEFINED);
		return (1);
	}
	return (0);
}

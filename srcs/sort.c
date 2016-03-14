#include "push_swap.h"

int	stack_is_ordered(t_stack *s)
{
	int	i;
	int	n;

	i = s->len;
	if (i < 1)
		return (0);
	n = s->data[--i];
	while (i-- > 0)
	{
		if (s->data[i] < n)
			return (0);
		n = s->data[i];
	}
	return (1);
}

int	check_need_for_swap(t_couple *c)
{
	int	b1;
	int	b2;

	if (c->a.data[c->a.len - 1] > c->a.data[c->a.len - 2])
	{
		if (!stack_get(&c->b, c->b.len - 1, &b1)
			&& !stack_get(&c->b, c->b.len - 2, &b2) && (b1 < b2))
		{
			if (SS)
				return (-1);
		}
		else if (SA)
			return (-1);
		return (1);
	}
	else if (!stack_get(&c->b, c->b.len - 1, &b1)
		&& !stack_get(&c->b, c->b.len - 2, &b2) && (b1 < b2))
	{
		if (SB)
			return (-1);
		return (1);
	}
	return (0);
}

int	force_insertion_into_b(t_couple *c)
{
	int	n;

	while (1)
	{
		if (c->b.len && stack_get(&c->b, c->b.len - 1, &n))
			return (1);
		if (!c->b.len || (n <= c->a.data[c->a.len - 1]))
		{
			if (PB)
				return (1);
			break ;
		}
		if (RRB)
			return (1);
	}
	return (0);
}

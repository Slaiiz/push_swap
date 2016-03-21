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

static void reorder_stacks(t_couple *c)
{
	int	a;
	int	b;
	int	i;
	int	d;

	i = stack_find(&c->a, c->a.max, EQUAL);
	a = i + 1 < c->a.len / 2;
	d = stack_find(&c->b, c->b.min, EQUAL);
	b = d + 1 < c->b.len / 2;
	if (a)
	{
		if (b)
		{
			while (i-- && d--)
				RRR;
			while (i-- > )
		}
	}
}

static void	swap_stacks(t_couple *c)
{
	if (c->a.len > 1 && c->a.data[c->a.len - 1] > c->a.data[c->a.len - 2])
	{
		if (c->b.len > 1 && c->b.data[c->b.len - 1] < c->b.data[c->b.len - 2])
			SS;
		else
			SA;
	}
	else if (c->b.len > 1 && c->b.data[c->b.len - 1] < c->b.data[c->b.len - 2])
		SB;
	reorder_stacks(c);
}

int			algorithm_parallel_sort(t_couple *c)
{
	int	n;

	if (stack_is_ordered(&c->a))
		return (0);
	n = c->a.len / 2;
	while (c->a.len > n)
		PB;
	while (!stack_is_ordered(&c->a) || c->b.len)
	{
		reorder_stacks(c);
	}
}

/*
**a  	4 9 1
**b  	0 6 8
**ra
**a  	1 4 9
**b  	0 6 8
**pa
**a  	1 4 9 8
**b  	0 6
**
*/

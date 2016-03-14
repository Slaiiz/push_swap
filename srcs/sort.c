#include "push_swap.h"

int		stack_is_ordered(t_stack *s)
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

void	check_need_for_low_swap(t_couple *c)
{
	int	b1;
	int	b2;

	if (c->a.data[c->a.len - 1] > c->a.data[c->a.len - 2])
	{
		if (!stack_get(&c->b, c->b.len - 1, &b1)
			&& !stack_get(&c->b, c->b.len - 2, &b2) && (b1 > b2))
			SS;
		else
			SA;
	}
	else if (!stack_get(&c->b, c->b.len - 1, &b1)
		&& !stack_get(&c->b, c->b.len - 2, &b2) && (b1 > b2))
		SB;
}

void	check_need_for_high_swap(t_couple *c)
{
	int	b1;
	int	b2;

	if (c->a.data[0] < c->a.data[1])
	{
		if (!stack_get(&c->b, 0, &b1)
			&& !stack_get(&c->b, 1, &b2) && (b1 < b2))
			RR && RR && SS && RRR && RRR;
		else
			RA && RA && SA && RRA && RRA;
	}
	else if (!stack_get(&c->b, 0, &b1)
		&& !stack_get(&c->b, 1, &b2) && (b1 < b2))
		RB && RB && SB && RRB && RRB;
}

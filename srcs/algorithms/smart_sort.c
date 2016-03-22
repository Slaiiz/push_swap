#include "push_swap.h"

static void	bring_to_top(t_couple *c, int n)
{
	int	i;

	i = stack_find(&c->a, n, EQUAL);
	if (i + 1 < c->a.len / 2)
		while (i-- >= 0)
			RRA;
	else
		while (i + 1 < c->a.len)
			RA;
}

int			algorithm_smart_sort(t_couple *c)
{
	int	i;
	int	n;

	n = c->a.min;
	while (c->a.data[0] != c->a.max || !stack_is_ordered)
	{
		i = stack_find(&c->a, n, EQUAL);
		bring_to_top(&c->a, n);
	}
}

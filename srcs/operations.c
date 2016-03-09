#include "push_swap.h"

int	register_operation(t_couple *c, int o)
{
	int	*n;

	if (c->size < (c->len + 1))
	{
		if ((n = malloc(sizeof(int) * (c->size + INC_FACTOR))) == NULL)
			return (0);
		if (in->data != NULL)
		{
			ft_memcpy(n, in->data, in->len);
			free(in->data);
		}
		in->size += INC_FACTOR;
		in->data = n;
	}
	c->data[in->len++] = o;
	return (1);
}

int	__swap(t_couple *c, int o)
{
	int		n;
	t_stack	*s;

	if (o == A)
		s = &c->a;
	else if (o == B)
		s = &c->b;
	if (s.len < 2)
		return (0);
	n = stack_get(&s, c->a.len - 1);
	stack_set(&s, s.len - 1, stack_get(&s, s.len - 2));
	stack_set(&s, s.len - 2, n);
	return (1);
}

int	__push(t_couple *c, int o)
{
	t_stack	*s;
	t_stack *d;

	if (o == A)
	{
		s = &c->b;
		d = &c->a;
	}
	else if (o == B)
	{
		s = &c->a;
		d = &c->b;
	}
	return (stack_push(d, stack_pop(s)));
}

int	__rotate(t_couple *c, int o)
{
	t_stack	*s;

	if (o == O_RA)
		s = &c->a;
	else if (o == O_RB)
		s = &c->b;
}

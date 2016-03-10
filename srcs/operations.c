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

	if (o == O_SA)
		s = &c->a;
	else if (o == O_SB)
		s = &c->b;
	else if (o == S)
	{
		__swap(c, O_SA | S);
		__swap(c, O_SB | S);
		return ;
	}
	if (s.len < 2)
		return (0);
	if (!(O & S))
		if (!register_operation(c, o))
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
	int		 n;

	if (o == O_PA)
	{
		s = &c->b;
		d = &c->a;
	}
	else if (o == O_PB)
	{
		s = &c->a;
		d = &c->b;
	}
	if ((n = stack_pop(s)) == NULL
		|| stack_push(d, n) == NULL
		|| !register_operation(c, o))
		return (0);
	return (1);
}

int	__rotate(t_couple *c, int o)
{
	t_stack	*s;

	if (o == O_PA)
		s = &c->a;
	else if (o == O_PB)
		s = &c->b;
	if (!stack_rotate(s, FORWARD)
		|| !register_operation(c, o))
		return (0);
	return (1);
}

int	__reverse_rotate(t_couple *c, int o)
{
	t_stack	*s;

	if (o == A)
		s = &c->a;
	else if (o == B)
		s = &c->b;
	if (!stack_rotate(s, REVERSE)
		|| !register_operation(c, o))
		return (0);
	return (1);
}

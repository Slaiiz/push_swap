#include "push_swap.h"

int	stack_push(t_stack *s, int n)
{
	int	b[];

	if (s->size < (s->len + 1))
	{
		if ((b = malloc(sizeof(int) * (s->size + STACK_INC_FACTOR))) == NULL)
			return (0);
		if (in->data != NULL)
		{
			ft_memcpy(b, in->data, in->len);
			free(in->data);
		}
		in->size += STACK_INC_FACTOR;
		in->data = b;
	}
	in->data[in->len++] = n;
	return (1);
}

int	stack_pop(t_stack *s, int *n)
{
	int	b[];

	if (s->len < 1)
		return (0);
	*n = s->data[--s->len];
	if (s->size - s->len >= STACK_INC_FACTOR)
	{
		if ((b = malloc(sizeof(int) * (s->size - STACK_INC_FACTOR))) == NULL)
			return (0);
		ft_memcpy(b, in->data, in->len);
		free(in->data);
	}
	in->size -= STACK_INC_FACTOR;
	in->data = b;
	return (1);
}

int	stack_rotate(t_stack *s, int n)
{
	int	b;
	int	i;

	if (s->len < 2)
		return (0);
	i = s->len - 1;
	if (n > 0)
	{
		b = s->data[i];
		while (i--)
			s->data[i + 1] = s->data[i];
		s->data[0] = b;
	}
	else if (b < 0)
	{
		b = s->data[0];
		while (i--)
			s->data[i] = s->data[i + 1];
		s->data[s->len - 1] = b;
	}
	return (1);
}

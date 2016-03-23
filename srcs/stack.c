/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 12:07:31 by vchesnea          #+#    #+#             */
/*   Updated: 2016/03/20 12:07:37 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_push(t_stack *s, int n)
{
	int	*b;

	if (s->size < (s->len + 1))
	{
		if ((b = malloc(sizeof(int) * (s->size + INC_FACTOR))) == NULL)
			return (print_error(ERR_OPERATION, DET_MALLOC));
		if (s->data != NULL)
		{
			ft_memcpy(b, s->data, sizeof(int) * s->len);
			free(s->data);
		}
		s->size += INC_FACTOR;
		s->data = b;
	}
	s->data[s->len++] = n;
	return (0);
}

int	stack_pop(t_stack *s, int *n)
{
	int	*b;

	if (s->len < 1)
		return (print_error(ERR_OPERATION, DET_BADLEN));
	*n = s->data[--s->len];
	if ((s->size - s->len) >= INC_FACTOR)
	{
		if ((b = malloc(sizeof(int) * (s->size - INC_FACTOR))) == NULL)
			return (print_error(ERR_OPERATION, DET_MALLOC));
		ft_memcpy(b, s->data, sizeof(int) * s->len);
		free(s->data);
		s->size -= INC_FACTOR;
		s->data = b;
	}
	return (0);
}

int	stack_rotate(t_stack *s, int n)
{
	int	b;
	int	i;

	if (s->len < 2)
		return (print_error(ERR_OPERATION, DET_BADLEN));
	i = s->len - 1;
	if (n > 0)
	{
		b = s->data[i];
		while (i--)
			s->data[i + 1] = s->data[i];
		s->data[0] = b;
	}
	else if (n < 0)
	{
		b = s->data[0];
		i = 0;
		while (i++ < s->len - 1)
			s->data[i - 1] = s->data[i];
		s->data[s->len - 1] = b;
	}
	return (0);
}

int	stack_find(t_stack *s, int n, int arg)
{
	int	i;
	int	m;
	int	d;

	if (arg == LESS)
		m = INT_MIN;
	else if (arg == GREATER)
		m = INT_MAX;
	i = s->len;
	d = -1;
	while (i--)
	{
		if ((arg == LESS && s->data[i] < n && s->data[i] > m)
			|| (arg == GREATER && s->data[i] > n && s->data[i] < m)
			|| (arg == EQUAL && s->data[i] == n))
		{
			m = s->data[i];
			d = i;
		}
	}
	if (d != -1)
		return (d);
	return (-1);
}

int	stack_is_ordered(t_stack *s)
{
	int	i;

	i = s->len;
	while (i-- > 1)
		if (s->data[i] > s->data[i - 1])
			return (0);
	return (1);
}

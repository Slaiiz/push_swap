/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:35:06 by vchesnea          #+#    #+#             */
/*   Updated: 2016/03/12 16:35:04 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stack_push(t_stack *s, int n)
{
	int	*b;

	if (s->size < (s->len + 1))
	{
		if ((b = malloc(sizeof(int) * (s->size + INC_FACTOR))) == NULL)
		{
			print_error(ERR_OPERATION, DET_MALLOC);
			return (1);
		}
		if (s->data != NULL)
		{
			ft_memcpy(b, s->data, s->len);
			free(s->data);
		}
		s->size += INC_FACTOR;
		s->data = b;
	}
	s->data[s->len++] = n;
	return (0);
}

int		stack_pop(t_stack *s, int *n)
{
	int	*b;

	if (s->len < 1)
	{
		print_error(ERR_OPERATION, DET_BADLEN);
		return (1);
	}
	*n = s->data[--s->len];
	if (s->size - s->len >= INC_FACTOR)
	{
		if ((b = malloc(sizeof(int) * (s->size - INC_FACTOR))) == NULL)
		{
			print_error(ERR_OPERATION, DET_MALLOC);
			return (1);
		}
		ft_memcpy(b, s->data, s->len);
		s->size -= INC_FACTOR;
		free(s->data);
		s->data = b;
	}
	return (0);
}

int		stack_rotate(t_stack *s, int n)
{
	int	b;
	int	i;

	if (s->len < 2)
	{
		print_error(ERR_OPERATION, DET_BADLEN);
		return (1);
	}
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

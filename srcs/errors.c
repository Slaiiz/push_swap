/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 16:34:48 by vchesnea          #+#    #+#             */
/*   Updated: 2016/03/12 16:34:50 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initialize_errors(char **out)
{
	out[0]  = "Invalid/Missing argument(s)";
	out[1]  = "init_stacks() failed";
	out[2]  = "sort_stacks() failed";
	out[3]  = "malloc() failed";
	out[4]  = "push() failed";
	out[5]  = "rotate() failed";
	out[6]  = "reverse_rotate() failed";
	out[7]  = "Stack not large enough for action";
	out[8]  = "swap() failed";
	out[9]  = "Invalid argument syntax";
	out[10] = "No details";
	out[11] = "Could not register operation";
	out[12] = "Operation failed";
	out[13] = "main() failed";
	out[14] = "Illegal flag";
	out[15] = "parse_flags() failed";
	out[16] = "perform_post_checks() failed";
	out[17] = "Same number appearing more than once";
	out[18] = "check_swap() failed";
	out[19] = "check_rotation() failed";
	out[20] = "send_all_to_b() failed";
	out[21] = "retrieve_all_from_b() failed";
}

void		print_error(int id, int arg)
{
	static int	level;
	static char	flags;
	static char	*errors[22];

	if (id == INIT_ERRORS)
	{
		initialize_errors(errors);
		flags = arg;
		return ;
	}
	if (flags & F_ERRORS)
	{
		if (level == 0)
		{
			ft_printf("{{red;b}}WE GOT AN ERROR CAPT'N!!!{{eoc;}}");
			ft_printf("\nStack trace:\n*");
		}
		ft_printf(" [%d] -> {{yellow}}%s{{eoc}} (%s)\n",
			level++, errors[id], errors[arg]);
	}
	else if (level++ == 0)
		ft_printf("#!fd=2^Error\n");
}

int		perform_post_checks(t_couple *c)
{
	int	i;
	int	s;
	int	*hits;

	i = c->a.len;
	if ((hits = malloc(sizeof(int) * (2 * i))) == NULL)
	{
		print_error(ERR_POSTCHECKFAIL, DET_MALLOC);
		return (1);
	}
	ft_bzero(hits, sizeof(int) * (2 * i));
	ft_memcpy(hits, c->a.data, sizeof(int) * i);
	while (i--)
	{
		s = ft_arrayfind(hits, sizeof(int), c->a.len, c->a.data[i]);
		if (s != -1)
		{
			if (hits[s + c->a.len] > 0)
			{
				print_error(ERR_POSTCHECKFAIL, DET_DOUBLE);
				return (1);
			}
			hits[s + c->a.len]++;
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 17:13:20 by vchesnea          #+#    #+#             */
/*   Updated: 2016/03/12 15:44:03 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "get_next_line.h"

# define INC_FACTOR				 8

# define F_VERBOSE				 1
# define F_COLOR				 2
# define F_GAME					 4
# define F_ERRORS				 8
# define F_STATS				16

# define O_SA					 1
# define O_SB					 2
# define O_SS					 3
# define O_PA					 4
# define O_PB					 5
# define O_RA					 6
# define O_RB					 7
# define O_RR					 8
# define O_RRA					 9
# define O_RRB					10
# define O_RRR					11

# define A						 1
# define B						 2
# define S						16
# define R						 S

# define FORWARD				 1
# define REVERSE				-1

# define INIT_ERRORS			 (char*)0
# define ERR_INITFAIL			 "initialize_stacks()"
# define ERR_SORTFAIL			 "sort_stacks()"
# define ERR_PUSHFAIL			 "push()"
# define ERR_ROTATEFAIL			 "rotate()"
# define ERR_REVERSEFAIL		 "reverse_rotate()"
# define ERR_SWAPFAIL			 "swap()"
# define ERR_REGISTER			 "register_operation()"
# define ERR_OPERATION			 "Stack operation"
# define ERR_MAINFAIL			 "main()"
# define ERR_PARSEFAIL			 "parse_flags()"
# define ERR_POSTCHECKFAIL		 "perform_post_checks()"
# define ERR_SENDALL			 "send_all_to_b()"
# define ERR_RETRIEVEALL		 "retrieve_all_from_b()"
# define ERR_STACKSPILL			 "stack_spill()"

# define EQUAL					 0
# define LESS					-1
# define GREATER				-2

# define SA		swap(c, A)
# define SB		swap(c, B)
# define SS		swap(c, S)
# define PA		push(c, A)
# define PB		push(c, B)
# define RA		rotate(c, A)
# define RB		rotate(c, B)
# define RR		rotate(c, R)
# define RRA	reverse_rotate(c, A)
# define RRB	reverse_rotate(c, B)
# define RRR	reverse_rotate(c, R)

typedef struct	s_stack
{
	int			min;
	int			max;
	int			len;
	int			size;
	int			*data;
}				t_stack;

typedef struct	s_couple
{
	t_stack		a;
	t_stack		b;
	int			len;
	int			size;
	char		*ops;
	size_t		flags;
	char		*strings[11];
}				t_couple;

int				print_error(char *error, char *explanation);
void			print_snapshot(t_couple *c);
void			print_operations(t_couple *c);
void			initialize_operations(t_couple *c);
int				perform_post_checks(t_couple *c);

int				stack_push(t_stack *s, int n);
int				stack_pop(t_stack *s, int *n);
int				stack_rotate(t_stack *s, int n);
int				stack_set(t_stack *s, int i, int n);
int				stack_get(t_stack *s, int i, int *n);
int				stack_find(t_stack *s, int n, int arg);
int				stack_is_ordered(t_stack *s);

int				swap(t_couple *c, int o);
int				push(t_couple *c, int o);
int				rotate(t_couple *c, int o);
int				reverse_rotate(t_couple *c, int o);

int				algorithm_stack_spill(t_couple *c);
int				algorithm_full_rotate(t_couple *c);
int				algorithm_stash_sort(t_couple *c);

#endif

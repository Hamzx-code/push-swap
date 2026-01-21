/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:27:24 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/21 19:57:18 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct s_node
{
	int					value;
	struct s_node		*next;
	struct s_node		*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

typedef struct s_flage
{
	double	disorder;
	char	strategy[20];
	int		totsl_ops;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}	t_flage;

t_node	*new_node(int value);
void	init_stack(t_stack *s);
int		push(t_stack *s, int value);
int		pop(t_stack *s);
int		peek(t_stack *s);
int		is_sorted(t_stack *a);

#endif
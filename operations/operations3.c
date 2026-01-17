/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:02:49 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/17 17:36:22 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ra(t_stack *a)
{
	write(1, "ra\n", 3);
	if (a->size > 1)
		a->top = a->top->next;
}

void	rb(t_stack *b)
{
	write(1, "rb\n", 3);
	if (b->size > 1)
		b->top = b->top->next;
}

void	rr(t_stack *a, t_stack *b)
{
	write(1, "rr\n", 3);
	ra(a);
	rb(b);
}

void	rra(t_stack *a)
{
	write(1, "rra\n", 4);
	if (a->size > 1)
		a->top = a->top->prev;
}

void	rrb(t_stack *b)
{
	write(1, "rrb\n", 4);
	if (b->size > 1)
		b->top = b->top->prev;
}

void	rrr(t_stack *a, t_stack *b)
{
	write(1, "rrr\n", 4);
	rrb(b);
	rra(a);
}

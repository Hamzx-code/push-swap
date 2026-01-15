/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:02:49 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/15 21:23:16 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ra(t_stack *a)
{
	if (a->size > 1)
		a->top = a->top->next;
}

void	rb(t_stack *b)
{
	if (b->size > 1)
		b->top = b->top->next;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

void	rra(t_stack *a)
{
	if (a->size > 1)
		a->top = a->top->prev;
}

void	rrb(t_stack *b)
{
	if (b->size > 1)
		b->top = b->top->prev;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}

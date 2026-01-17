/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:46:42 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/17 17:46:57 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

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

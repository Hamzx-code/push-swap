/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:46:42 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/22 02:35:27 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rra(t_stack *a, t_flage *flage)
{
	write(1, "rra\n", 4);
	(flage->rra)++;
	(flage->total_ops)++;
	if (a->size > 1)
		a->top = a->top->prev;
}

void	rrb(t_stack *b, t_flage *flage)
{
	write(1, "rrb\n", 4);
	(flage->rrb)++;
	(flage->total_ops)++;
	if (b->size > 1)
		b->top = b->top->prev;
}

void	rrr(t_stack *a, t_stack *b, t_flage *flage)
{
	write(1, "rrr\n", 4);
	(flage->rrr)++;
	(flage->total_ops)++;
	rrb(b, flage);
	rra(a, flage);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:46:42 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/21 19:56:08 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rra(t_stack *a, t_flage *flage)
{
	write(1, "rra\n", 4);
	(flage->rra)++;
	if (a->size > 1)
		a->top = a->top->prev;
}

void	rrb(t_stack *b, t_flage *flage)
{
	write(1, "rrb\n", 4);
	(flage->rrb)++;
	if (b->size > 1)
		b->top = b->top->prev;
}

void	rrr(t_stack *a, t_stack *b, t_flage *flage)
{
	write(1, "rrr\n", 4);
	(flage->rrr)++;
	rrb(b, flage);
	rra(a, flage);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:02:49 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/22 02:35:17 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ra(t_stack *a, t_flage *flage)
{
	write(1, "ra\n", 3);
	(flage->ra)++;
	(flage->total_ops)++;
	if (a->size > 1)
		a->top = a->top->next;
}

void	rb(t_stack *b, t_flage *flage)
{
	write(1, "rb\n", 3);
	(flage->rb)++;
	(flage->total_ops)++;
	if (b->size > 1)
		b->top = b->top->next;
}

void	rr(t_stack *a, t_stack *b, t_flage *flage)
{
	write(1, "rr\n", 3);
	(flage->rr)++;
	(flage->total_ops)++;
	ra(a, flage);
	rb(b, flage);
}

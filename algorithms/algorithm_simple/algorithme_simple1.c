/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme_simple1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 22:11:00 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/21 00:48:59 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithme_simple.h"

static void	mov_to_b(t_stack *a, t_stack *b)
{
	int	min;
	int	pos_min;

	min = valeur_min(a);
	pos_min = position(min, a);
	if (pos_min <= a->size / 2)
		while ((a->top)->value != min)
			ra(a);
	else
		while ((a->top)->value != min)
			rra(a);
	pb(b, a);
}

void	algorithme_simple(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	while (a->top != NULL)
		mov_to_b(a, b);
	while (b->top != NULL)
		pa(a, b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme_simple1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 22:11:00 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/28 18:12:05 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithme_simple.h"

static void	mov_to_b(t_stack *a, t_stack *b, t_flage *flage)
{
	int	min;
	int	pos_min;

	min = 0;
	pos_min = 0;
	min = valeur_min_pos(a, &pos_min);
	if (pos_min <= a->size / 2)
		while ((a->top)->value != min)
			ra(a, flage);
	else
		while ((a->top)->value != min)
			rra(a, flage);
	pb(b, a, flage);
}

int	algorithme_simple(t_stack *a, t_stack *b, t_flage *flage)
{
	if (is_sorted(a))
		return (0);
	if (a->size == 2)
	{
		sa(a, flage);
		return (1);
	}
	while (a->top != NULL)
		mov_to_b(a, b, flage);
	while (b->top != NULL)
		pa(a, b, flage);
	return (1);
}

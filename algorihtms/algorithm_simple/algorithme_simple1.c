/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme_simple1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 22:11:00 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/16 16:14:20 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithme_simple.h"

static int	use_ra(t_stack *a, t_stack *b, int value)
{
	while ((a->top)->value != value)
	{
		write(1, "ra\n", 3);
		if (ra(a) == 0)
			return (0);
	}
	write(1, "pb\n", 3);
	if (pb(b, a) == 0)
		return (0);
	return (1);
}

static int	use_rra(t_stack *a, t_stack *b, int value)
{
	while ((a->top)->value != value)
	{
		write(1, "rra\n", 3);
        if(rra(a) == 0)
		    return (0);
	}
	write(1, "pb\n", 3);
    if (pb(b, a) == 0)
		return (0);
	return (1);
}

static int	mov_to_b(t_stack *a, t_stack *b, int min, int max)
{
	int cost_min;
    int cost_max;
	int pos_min;
	int pos_max;

	pos_min = position(min, a);
	pos_max = position(max, a);
	cost_min = cost(pos_min, a->size);
    cost_max = cost(pos_max, a->size);
	if (cost_min <= cost_max)
    {
		if (pos_min <= (a->size / 2 + 1))
			use_ra(a, b, min);
		else
			use_rra(a, b, min);
	}
    else
	{
    	if (pos_max <= (a->size / 2 + 1))
			if (use_ra(a, b, max))
				return (0);
		else
			if (use_rra(a, b, max) == 0)
				return (0);
    }
	return (1);
}

// Simple min/max extraction methods
int algorithme_simple(t_stack *a, t_stack *b)
{
    int min;
    int max;

    while (a->top != NULL)
    {
        min = valeur_min(a);
        max = valeur_max(a);
        if (move_to_b(a, b, min, max) == 0)
			return (0);
    }
    while (b->top != NULL)
    {
        write(1, "pa\n", 3);
        if (pa(a, b) == 0)
            return (0);
    }
    return (1);
}
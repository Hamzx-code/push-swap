/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme_medium1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:46:59 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/22 00:08:06 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithme_medium.h"

static void	mov_to_b(t_stack *a, t_stack *b, t_flage *flage)
{
	int		pushed;
	int		max_index;
	int		chunk_size;

	chunk_size = ft_sqrt(a->size);
	pushed = 0;
	max_index = chunk_size;
	while (a->top != NULL)
	{
		if (a->top->value < max_index)
		{
			pb(b, a, flage);
			pushed++;
			if (pushed == max_index)
				max_index += chunk_size;
		}
		else
			ra(a, flage);
	}
}

static void	mov_to_a(t_stack *a, t_stack *b, t_flage *flage)
{
	int	max;

	while (b->top != NULL)
	{
		max = b->size - 1;
		if (position(max, b) <= b->size / 2)
			while ((b->top)->value != max)
				rb(b, flage);
		else
			while ((b->top)->value != max)
				rrb(b, flage);
		pa(a, b, flage);
	}
}

void	real_stack(t_stack *a, int *arr)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = a->top;
	while (i < a->size)
	{
		tmp->value = arr[tmp->value];
		tmp = tmp->next;
		i++;
	}
}

int	algorithme_medium(t_stack *a, t_stack *b, t_flage *flage)
{
	int	*arr;

	if (is_sorted(a))
		return (0);
	arr = index_stack(a);
	mov_to_b(a, b, flage);
	mov_to_a(a, b, flage);
	real_stack(a, arr);
	free(arr);
	return (1);
}

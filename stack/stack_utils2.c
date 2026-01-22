/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:39:20 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/22 02:36:16 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int is_sorted(t_stack *a)
{
	t_node *tmp;

	if (!a || !a->top)
		return (1);
	if (a->top->next == a->top)
		return (1);

	tmp = a->top;
	while (tmp->next != a->top)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	init_flage(t_flage *flage)
{
	int	i;

	flage->disorder = 0.0;
	flage->total_ops = 0;
	flage->sa = 0;
	flage->sb = 0;
	flage->ss = 0;
	flage->pa = 0;
	flage->pb = 0;
	flage->ra = 0;
	flage->rb = 0;
	flage->rr = 0;
	flage->rra = 0;
	flage->rrb = 0;
	flage->rrr = 0;
	i = 0;
	while (i < 20)
	{
		flage->strategy[i] = '\0';
		i++;
	}
}
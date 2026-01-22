/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:39:03 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/22 02:35:08 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	changing_top(t_stack *dest, t_node *node)
{
	t_node	*old_top;
	t_node	*last;

	if (!dest->top)
	{
		dest->top = node;
		dest->top->next = dest->top;
		dest->top->prev = dest->top;
	}
	else
	{
		old_top = dest->top;
		last = dest->top->prev;
		dest->top = node;
		dest->top->next = old_top;
		dest->top->prev = last;
		old_top->prev = dest->top;
		last->next = dest->top;
	}
}

int	pb(t_stack *b, t_stack *a, t_flage *flage)
{
	t_node	*node_to_move;

	write(1, "pb\n", 3);
	(flage->pb)++;
	(flage->total_ops)++;
	if (!a->top)
		return (0);
	node_to_move = a->top;
	if (a->size == 1)
		a->top = NULL;
	else
	{
		a->top = a->top->next;
		a->top->prev = node_to_move->prev;
		node_to_move->prev->next = a->top;
	}
	changing_top(b, node_to_move);
	(b->size)++;
	(a->size)--;
	return (1);
}

int	pa(t_stack *a, t_stack *b, t_flage *flage)
{
	t_node	*node_to_move;

	write(1, "pa\n", 3);
	(flage->pa)++;
	(flage->total_ops)++;
	if (!b->top)
		return (0);
	node_to_move = b->top;
	if (b->size == 1)
		b->top = NULL;
	else
	{
		b->top = b->top->next;
		b->top->prev = node_to_move->prev;
		node_to_move->prev->next = b->top;
	}
	changing_top(a, node_to_move);
	(a->size)++;
	(b->size)--;
	return (1);
}

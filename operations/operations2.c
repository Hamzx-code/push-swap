/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:39:03 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/14 19:02:32 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int	changing_top(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (!a->top)
	{
		a->top = b->top;
		(a->top)->next = a->top;
		(a->top)->prev = a->top;
	}
	else
	{
		tmp = a->top;
		a->top = b->top;
		(a->top)->next = tmp;
		(a->top)->prev = tmp->prev;
		(tmp->prev)->next = a->top;
		tmp->prev = a->top;
	}
}

int	pa(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (!b->top)
		return (0);
	changing_top(a, b);
	if (b->size < 2)
		b->top = NULL;
	else
	{
		tmp = b->top;
		b->top = (b->top->next);
		(b->top)->prev = tmp->prev;
		(tmp->prev)->next = b->top;
		if (b->size == 2)
		{
			(b->top)->next = b->top;
			(b->top)->prev = b->top;
		}
	}
	(a->size)++;
	(b->size)--;
	return (1);
}

int	pb(t_stack *b, t_stack *a)
{
	t_node	*tmp;

	if (!a->top)
		return (0);
	changing_top(b, a);
	if (a->size < 2)
		a->top = NULL;
	else
	{
		tmp = a->top;
		a->top = (a->top->next);
		(a->top)->prev = tmp->prev;
		(tmp->prev)->next = a->top;
		if (a->size == 2)
		{
			(a->top)->next = a->top;
			(a->top)->prev = a->top;
		}
	}
	(b->size)++;
	(a->size)--;
	return (1);
}

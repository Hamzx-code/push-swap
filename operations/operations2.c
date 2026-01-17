/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:39:03 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/17 17:38:30 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

// void	changing_top(t_stack *a, t_stack *b)
// {
// 	t_node	*last_a;

// 	if (!a->top)
// 	{
// 		a->top = b->top;
// 		(a->top)->next = a->top;
// 		(a->top)->prev = a->top;
// 	}
// 	else
// 	{
// 		last_a = (a->top)->prev;  // Sauvegarder le dernier de a
		
// 		// Insérer b->top au sommet de a
// 		b->top->next = a->top;
// 		b->top->prev = last_a;
// 		last_a->next = b->top;
// 		a->top->prev = b->top;
		
// 		a->top = b->top;  // Mettre à jour le top
// 	}
// }

// int	pa(t_stack *a, t_stack *b)
// {
// 	t_node	*tmp;

// 	if (!b->top)
// 		return (0);
// 	changing_top(a, b);
// 	if (b->size < 2)
// 		b->top = NULL;
// 	else
// 	{
// 		tmp = b->top;
// 		b->top = (b->top->next);
// 		(b->top)->prev = tmp->prev;
// 		(tmp->prev)->next = b->top;
// 		if (b->size == 2)
// 		{
// 			(b->top)->next = b->top;
// 			(b->top)->prev = b->top;
// 		}
// 	}
// 	(a->size)++;
// 	(b->size)--;
// 	return (1);
// }

// int	pb(t_stack *b, t_stack *a)
// {
// 	t_node	*tmp;

// 	if (!a->top)
// 		return (0);
// 	changing_top(b, a);
// 	if (a->size < 2)
// 		a->top = NULL;
// 	else
// 	{
// 		tmp = a->top;
// 		a->top = (a->top->next);
// 		(a->top)->prev = tmp->prev;
// 		(tmp->prev)->next = a->top;
// 		if (a->size == 2)
// 		{
// 			(a->top)->next = a->top;
// 			(a->top)->prev = a->top;
// 		}
// 	}
// 	(b->size)++;
// 	(a->size)--;
// 	return (1);
// }

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

int	pb(t_stack *b, t_stack *a)
{
	t_node	*node_to_move;

	write(1, "pb\n", 3);
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

int	pa(t_stack *a, t_stack *b)
{
	t_node	*node_to_move;

	write(1, "pa\n", 3);
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

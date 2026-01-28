/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:33:20 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/27 18:48:13 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	two_element(t_node *first, t_node *second, t_stack *stack_a)
{
	first->next = second;
	first->prev = second;
	second->next = first;
	second->prev = first;
	stack_a->top = second;
}

void	swap_nodes(t_node *first, t_node *second, t_stack *stack_a)
{
	t_node	*last;
	t_node	*third;

	last = first->prev;
	third = second->next;
	second->prev = last;
	second->next = first;
	first->prev = second;
	first->next = third;
	last->next = second;
	third->prev = first;
	stack_a->top = second;
}

int	sa(t_stack *stack_a)
{
	t_node	*first;
	t_node	*second;

	if (!stack_a->top || stack_a->size < 2)
		return (0);
	first = stack_a->top;
	second = first->next;
	if (stack_a->size == 2)
		two_element(first, second, stack_a);
	else
		swap_nodes(first, second, stack_a);
	return (1);
}

int	sb(t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;

	if (!stack_b->top || stack_b->size < 2)
		return (0);
	first = stack_b->top;
	second = first->next;
	if (stack_b->size == 2)
		two_element(first, second, stack_b);
	else
		swap_nodes(first, second, stack_b);
	return (1);
}

int	ss(t_stack *stack_a, t_stack *stack_b)
{
	int	result_a;
	int	result_b;

	result_a = sa(stack_a);
	result_b = sb(stack_b);
	return (result_a && result_b);
}

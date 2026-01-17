/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:33:20 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/17 17:38:08 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int	sa(t_stack *stack_a)
{
	t_node	*ex_top;
	t_node	*last;

	write(1, "sa\n", 3);
	if (!stack_a->top || stack_a->size < 2)
		return (0);
	last = (stack_a->top)->prev;
	ex_top = stack_a->top;
	stack_a->top = (stack_a->top)->next;
	((stack_a->top)->next)->prev = ex_top;
	ex_top->next = (stack_a->top)->next;
	ex_top->prev = (stack_a->top);
	(stack_a->top)->next = ex_top;
	(stack_a->top)->prev = last;
	last->next = stack_a->top;
	return (1);
}

int	sb(t_stack *stack_b)
{
	t_node	*ex_top;
	t_node	*last;

	write(1, "sb\n", 3);
	if (!stack_b->top || stack_b->size < 2)
		return (0);
	last = (stack_b->top)->prev;
	ex_top = stack_b->top;
	stack_b->top = (stack_b->top)->next;
	((stack_b->top)->next)->prev = ex_top;
	ex_top->next = (stack_b->top)->next;
	ex_top->prev = (stack_b->top);
	(stack_b->top)->next = ex_top;
	(stack_b->top)->prev = last;
	last->next = stack_b->top;
	return (1);
}

int	ss(t_stack *stack_a, t_stack *stack_b)
{
	int	result_a;
	int	result_b;

	write(1, "ss\n", 3);
	result_a = sa(stack_a);
	result_b = sb(stack_b);
	return (result_a && result_b);
}

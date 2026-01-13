/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:33:20 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/13 16:42:06 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int	sa(t_node **stack_a)
{
	t_node *tmp;
	
	if (!*stack_a || !(*stack_a)->next)
		return (0);
	tmp = *stack_a;
	*stack_a = tmp->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
	return (1);
}

int	sb(t_node **stack_b)
{
	t_node *tmp;
	
	if (!*stack_b || !(*stack_b)->next)
		return (0);
	tmp = *stack_b;
	*stack_b = tmp->next;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;
	return (1);
}

int	ss(t_node **stack_a, t_node **stack_b)
{
	int	result_a;
	int	result_b;

	result_a = sa(stack_a);
	result_b = sb(stack_b);
	
	return (result_a && result_b);
}

int	pa()

int	main(void)
{
	t_node	*stack;

	push(&stack, 10);
	push(&stack, 20);
	push(&stack, 30);
	printf("before calling sa %d \n", peek(stack));
	sa(&stack);
	printf("after calling sa %d \n", peek(stack));
	printf("pop the peek %d \n",pop(&stack));
	printf("after poping sa %d \n", peek(stack));
	printf("pop the peek %d \n",pop(&stack));
	printf("after poping sa %d \n", peek(stack));
	free(stack);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:33:20 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/14 01:11:45 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/*
sa of first data strcuture 
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
} */

int	sa(t_stack *stack_a)
{
	t_node *ex_top;
	t_node *last;

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
	last->next=stack_a->top;
	return (1);
}

int	sb(t_stack *stack_b)
{
	t_node *ex_top;
	t_node *last;

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
	last->next=stack_b->top;
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

int	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp_a;

	if (!*stack_b)
		return (0);
	tmp_a = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_a)->next = tmp_a;
	return (1);
}

int	paa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*ex_top_a;
	t_node	*ex_top_b;

	if (!stack_b->top)
		return (0);
	if (!stack_a->top)
	{
		ex_top_b =  stack_b->top;
		stack_a->top = stack_b->top;
		(stack_b->top) = (stack_b->top)->next;
		(stack_b->top)->prev = ex_top_b->prev;
		(stack_a->top)->next = stack_a->top;
		(stack_a->top)->prev = stack_a->top;
	}
	else
	{
		ex_top_a = stack_a->top;	
		stack_a->top = stack_b->top;
		(stack_a->top)->next = ex_top;
		(stack_a->top)->prev = ex_top->prev;
		ex_top->prev = stack_a->top;
	}
	return (1);
}

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


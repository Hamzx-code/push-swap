/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:45:53 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/14 18:46:45 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



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

/*int	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp_a;

	if (!*stack_b)
		return (0);
	tmp_a = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_a)->next = tmp_a;
	return (1);
}*/

/*int	main(void)
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
}*/

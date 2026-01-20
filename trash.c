/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:45:53 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/21 00:46:32 by mkacemi          ###   ########.fr       */
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

// static void	mov_to_b(t_stack *a, t_stack *b, int min, int max)
// {
// 	int cost_min;
//     int cost_max;
// 	int pos_min;
// 	int pos_max;

// 	pos_min = position(min, a);
// 	pos_max = position(max, a);
// 	cost_min = cost(pos_min, a->size);
//     cost_max = cost(pos_max, a->size);
// 	if (cost_min <= cost_max)
//     {
// 		if (pos_min <= (a->size / 2 + 1))
// 			use_ra(a, b, min);
// 		else
// 			use_rra(a, b, min);
// 	}
//     else
// 	{
//     	if (pos_max <= (a->size / 2 + 1))
// 			use_ra(a, b, max );
// 		else
// 			use_rra(a, b, max);
//     }
// }


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

/* typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node; */


// min = valeur_min(a);
// if (position(min, a) <= a->size / 2)
// 	while ((a->top)->value != min)
// 		ra(a);
// else
// 	while ((a->top)->value != min)
// 		rra(a);
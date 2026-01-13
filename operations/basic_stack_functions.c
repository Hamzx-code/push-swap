/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:12:58 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/13 16:14:08 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

t_node *new_node(int value)
{
	t_node *n = malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->value = value;
	n->next = NULL;
	return (n);
}
void	push(t_node **stack, int value)
{
	t_node *n = new_node(value);
	if (!n)
		return ;
	n->next = *stack;
	*stack = n;
}

int	pop(t_node **stack)
{
	t_node *tmp;
	int		value;
	
	if (!*stack)
		return (0);
	tmp = *stack;
	value = tmp->value;
	*stack = tmp->next;
	free(tmp);
	return (value);
}

int	peek(t_node *stack)
{
	if (!stack)
		return (0);
	return (stack->value);
}
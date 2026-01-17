/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:07:09 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/16 18:42:07 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithme_simple.h"

int	cost(int index, int size)
{
	if (index <= size / 2)
		return (index - 1);
	else
		return (size - index + 1);
}

int	valeur_min(t_stack *stack)
{
	int		min;
	int		i;
	t_node	*current;

	i = 1;
	current = stack->top;
	min = current->value;
	while (i <= stack->size)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
		i++;
	}
	return (min);
}

int	valeur_max(t_stack	*stack)
{
	int		max;
	int		i;
	t_node	*current;

	i = 1;
	current = stack->top;
	max = current->value;
	while (i <= stack->size)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
		i++;
	}
	return (max);
}

int	position(int value, t_stack *stack)
{
	int		i;
	t_node	*current;

	i = 1;
	current = stack->top;
	while (i <= stack->size)
	{
		if (current->value == value)
			return (i);
		current = current->next;
		i++;
	}
	return (-1);
}

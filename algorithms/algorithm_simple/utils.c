/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:07:09 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/28 18:07:41 by hhamidi          ###   ########.fr       */
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

int	valeur_min_pos(t_stack *stack, int *pos)
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
		{
			min = current->value;
			*pos = i;
		}
		current = current->next;
		i++;
	}
	return (min);
}

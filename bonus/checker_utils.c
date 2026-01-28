/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:40:02 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/28 16:07:41 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	checker_swap(char *operation, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(operation, "sa"))
	{
		if (!sa(a))
			return (0);
		return (1);
	}
	if (!ft_strcmp(operation, "sb"))
	{
		if (!sb(b))
			return (0);
		return (1);
	}
	if (!ft_strcmp(operation, "ss"))
	{
		if (!ss(a, b))
			return (0);
		return (1);
	}
	return (0);
}

int	checker_push(char *operation, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(operation, "pa"))
	{
		if (!pa(a, b))
			return (0);
		return (1);
	}
	if (!ft_strcmp(operation, "pb"))
	{
		if (!pb(b, a))
			return (0);
		return (1);
	}
	return (0);
}

void	checker_rotate(char *operation, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(operation, "ra"))
		ra(a);
	if (!ft_strcmp(operation, "rb"))
		rb(b);
	if (!ft_strcmp(operation, "rr"))
		rr(a, b);
}

void	checker_reverse_rotate(char *operation, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(operation, "rra"))
		rra(a);
	if (!ft_strcmp(operation, "rrb"))
		rrb(b);
	if (!ft_strcmp(operation, "rrr"))
		rrr(a, b);
}

int	apply_operations(char **operations, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (operations[i])
	{
		if (operations[i][0] == 's')
			if (!checker_swap(operations[i], a, b))
				return (0);
		if (operations[i][0] == 'p')
			if (!checker_push(operations[i], a, b))
				return (0);
		if (operations[i][0] == 'r' && ft_strlen(operations[i]) == 2)
			checker_rotate(operations[i], a, b);
		if (operations[i][0] == 'r' && ft_strlen(operations[i]) == 3)
			checker_reverse_rotate(operations[i], a, b);
		i++;
	}
	return (1);
}

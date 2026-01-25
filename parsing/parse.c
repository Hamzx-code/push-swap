/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:51:40 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/25 16:57:31 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdlib.h>

static void	free_buffers(char **tab)
{
	size_t	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	validate_arguments(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!av[i] || !av[i][0])
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	fill_stack(t_stack *stack, int *numbers, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		if (!push(stack, numbers[i]))
			return (empty_stack(stack));
		i--;
	}
	return (1);
}

int	empty_stack(t_stack *stack)
{
	while (stack->size > 0)
		pop(stack);
	return (0);
}

int	parse(int ac, char **av, t_stack *stack, t_data *data)
{
	char	**values;

	if (ac < 2 || !validate_arguments(ac, av))
		return (0);
	values = join_and_split_args(ac, av);
	if (!values)
		return (0);
	init_data(data);
	if (!validate_input(values, data))
	{
		free_buffers(values);
		return (0);
	}
	if (!fill_stack(stack, data->numbers, data->size))
	{
		free_buffers(values);
		free(data->numbers);
		return (0);
	}
	free_buffers(values);
	free(data->numbers);
	if (is_sorted(stack) == 1)
		return (empty_stack(stack));
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:37:57 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/28 17:42:27 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <unistd.h>

static int	free_all(t_stack *a, char **operations, char *massage)
{
	empty_stack(a);
	free_buffers(operations);
	ft_putstr_fd(massage, 1);
	return (0);
}

static int	operations_cmp(char *operation)
{
	if (!ft_strcmp(operation, "sa"))
		return (1);
	if (!ft_strcmp(operation, "sa"))
		return (0);
	if (!ft_strcmp(operation, "sb"))
		return (1);
	if (!ft_strcmp(operation, "ss"))
		return (1);
	if (!ft_strcmp(operation, "pa"))
		return (1);
	if (!ft_strcmp(operation, "pb"))
		return (1);
	if (!ft_strcmp(operation, "ra"))
		return (1);
	if (!ft_strcmp(operation, "rb"))
		return (1);
	if (!ft_strcmp(operation, "rr"))
		return (1);
	if (!ft_strcmp(operation, "rra"))
		return (1);
	if (!ft_strcmp(operation, "rrb"))
		return (1);
	if (!ft_strcmp(operation, "rrr"))
		return (1);
	return (0);
}

static int	parse_operations(char **operations, t_stack *a)
{
	int	i;

	if (!operations)
	{
		if (is_sorted(a) == 1)
			ft_putstr_fd("OK\n", 2);
		else
			ft_putstr_fd("KO\n", 2);
		return (0);
	}
	i = 0;
	while (operations[i])
	{
		if (!operations_cmp(operations[i]))
		{
			ft_putstr_fd("Error\n", 2);
			free_buffers(operations);
			return (0);
		}
		i++;
	}
	return (1);
}

int	checker(int ac, char **av)
{
	char	**operations;
	char	*buffer_operations;
	t_data	data;
	t_stack	a;
	t_stack	b;

	init_stack(&a);
	if (!parse_checker(ac, av, &a, &data))
		return (0);
	buffer_operations = NULL;
	buffer_operations = read_buffer(0, buffer_operations);
	operations = ft_split(buffer_operations, '\n');
	free(buffer_operations);
	if (!parse_operations(operations, &a))
		return (empty_stack(&a));
	init_stack(&b);
	if (!apply_operations(operations, &a, &b))
		return (free_all(&a, operations, "KO\n"));
	if (is_sorted(&a) == 1)
		free_all(&a, operations, "OK\n");
	else
		return (free_all(&a, operations, "KO\n"));
	return (1);
}

int	main(int ac, char **av)
{
	if (!checker(ac, av))
		return (1);
	return (0);
}

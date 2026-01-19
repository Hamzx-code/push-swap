/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:24:33 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/19 20:29:52 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int count_elements(char **tab)
{
	int	count;

	count = 0;
	while (tab[count])
		count++;
	return (count);
}

int	error(int ac, char **values, int **numbers)
{
	int	flag_count;
	int	size_array;

	flag_count = 0;
	if (!check_flag(ac, values, &flag_count))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	size_array = count_elements(values);
	*numbers = malloc((size_array - flag_count) * sizeof(int));
	if (!*numbers)
		return (0);
	if (!check_values(values, flag_count, numbers, size_array))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

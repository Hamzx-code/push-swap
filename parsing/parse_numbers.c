/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:17:19 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/24 12:41:25 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <limits.h>

static int	parse_char(char *value)
{
	int	i;

	i = 0;
	if (value[i] == '-' || value[i] == '+')
		i++;
	if (!value[i])
		return (0);
	while (value[i])
	{
		if (!ft_isdigit(value[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	parse_limits(long number)
{
	if (number < INT_MIN || number > INT_MAX)
		return (0);
	return (1);
}

static int	parse_duplicate(int	*numbers, int size_array)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = size_array;
	while (i < (size - 1))
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	parse_values(char **values, int start, t_data *data)
{
	int		i;
	long	value_long;

	i = start;
	while (values[i])
	{
		if (!parse_char(values[i]))
			return (0);
		value_long = ft_atol(values[i]);
		if (!parse_limits(value_long))
			return (0);
		data->numbers[i - start] = (int)value_long;
		i++;
	}
	if (!parse_duplicate(data->numbers, data->size))
		return (0);
	return (1);
}

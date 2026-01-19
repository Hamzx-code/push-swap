/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:17:19 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/19 20:36:17 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>
#include <limits.h>

static long	ft_atol_overflow(int sign)
{
	if (sign == 1)
		return (LONG_MAX);
	return (LONG_MIN);
}

long	ft_atol(const char *str)
{
	size_t	i;
	int		sign;
	long		result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > (LONG_MAX - (str[i] - '0')) / 10)
			return(ft_atol_overflow(sign));
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_char(char *value)
{
	int	i;

	if (!value[0])
		return (0);
	i = 0;
	if (value[i] == '-' || value[i] == '+')
		i++;
	while (value[i])
	{
		if (!ft_isdigit(value[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_limits(long number)
{
	if (number < INT_MIN || number > INT_MAX)
		return (0);
	return (1);
}

int	check_duplicate(int	*numbers, int size_array)
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

int	check_values(char **values, int start, int **numbers_array, int size_array)
{
	size_t	i;
	long	value_long;

	i = start;
	while (values[i])
	{
		if (!check_char(values[i]))
			return (0);
		value_long = ft_atol(values[i]);
		if (!check_limits(value_long))
			return (0);
		(*numbers_array)[i - start] = (int)value_long;
		i++;
	}
	if (!check_duplicate(*numbers_array, size_array))
		return (0);
	return (1);
}

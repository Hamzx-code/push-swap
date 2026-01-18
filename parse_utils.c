/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:17:19 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/18 13:49:46 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>

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

	i = 0;
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
	if (value < INT_MIN || value_long > INT_MAX)
		return (0);
	return (1);
}

int	check_duplicate(int	*numbers)
{
	size_t	i;
	size_t	j;
	size_t	size; 

	i = 0;
	size = sizeof(numbers) / sizeof(numbers[0]);
	while (numbers[i] < (size - 1))
	{
		j = i + 1;
		while (numbers[j] < size)
		{
			if (numbers[i] == numbers[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_values(char **values, int start, int *numbers_array)
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
		*numbers_array[i - start] = (int)value_long;
		i++;
	}
	if (!check_duplicate(numbers_array))
		return (0);
	return (1);
}

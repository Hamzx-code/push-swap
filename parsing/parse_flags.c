/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:00:36 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/22 20:14:45 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	check_valid_flag(char *flag)
{
	if (!ft_strcmp("--simple", flag))
		return (1);
	else if (!ft_strcmp("--medium", flag))
		return (2);
	else if (!ft_strcmp("--complex", flag))
		return (3);
	else if (!ft_strcmp("--adaptive", flag))
		return (4);
	else if (!ft_strcmp("--bench", flag))
		return (5);
	return (0);
}

static int	check_second_flag(int first_flag_type, char *second_flag, t_data *data)
{
	int	second_flag_type;

	second_flag_type = check_valid_flag(second_flag);
	if (!second_flag_type || second_flag_type == first_flag_type) // valid flag and duplicate flag check
		return (0);
	if (first_flag_type >= 1 && first_flag_type <= 4 && second_flag_type == 5)
	{
		data->bench_mode = 1;
		return (1);
	}
	if (second_flag_type >= 1 && second_flag_type <= 4 && first_flag_type == 5)
	{
		data->flag = second_flag_type;
		return (1);
	}
	return (0);
}

int	parse_flags(int values_count, char **values, int *flag_count, t_data *data)
{
	int	nb_flags;
	int	first_flag_type;

	nb_flags = 0;
	first_flag_type = 0;
	if (values_count >= 1 && values[0][0] == '-' && values[0][1] == '-')
	{
		first_flag_type = check_valid_flag(values[0]);
		if (!first_flag_type)
			return (0);
		if (first_flag_type == 5)
			data->bench_mode = 1;
		else
			data->flag = first_flag_type;
		nb_flags++;
	}	
	if (values_count >= 2 && values[1][0] == '-' && values[1][1] == '-')
	{
		if (!check_second_flag(first_flag_type, values[1], data))
			return (0);
		nb_flags++;
	}
	*flag_count = nb_flags;
	return (1);
}

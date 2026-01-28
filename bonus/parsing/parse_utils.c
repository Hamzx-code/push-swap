/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:12:43 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/28 13:07:32 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	init_data(t_data *data)
{
	data->numbers = NULL;
	data->size = 0;
}

char	**join_and_split_args(int ac, char **av)
{
	char	**values;
	char	*elements;
	char	*old_elements;
	int		i;

	elements = ft_strdup(av[1]);
	if (!elements)
		return (NULL);
	i = 2;
	while (i < ac)
	{
		old_elements = elements;
		elements = ft_strjoin(old_elements, " ");
		free(old_elements);
		old_elements = elements;
		elements = ft_strjoin(old_elements, av[i]);
		free(old_elements);
		i++;
	}
	values = ft_split(elements, ' ');
	free(elements);
	return (values);
}

static int	count_elements(char **tab)
{
	int	count;

	count = 0;
	while (tab[count])
		count++;
	return (count);
}

int	validate_input(char **values, t_data *data)
{
	data->size = count_elements(values);
	data->numbers = malloc(data->size * sizeof(int));
	if (!data->numbers)
		return (0);
	if (!parse_values(values, data))
	{
		free(data->numbers);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

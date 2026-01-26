/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:12:43 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/26 20:33:14 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	count_elements(char **tab)
{
	int	count;

	count = 0;
	while (tab[count])
		count++;
	return (count);
}

int	validate_input(char **values, int *numbers)
{
	int	value_count;

	value_count = count_elements(values);
	numbers = malloc(value_count * sizeof(int));
	if (!numbers)
		return (0);
	if (!parse_values(values, numbers, value_count))
	{
		free(numbers);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

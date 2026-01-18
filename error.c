/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:24:33 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/18 13:49:38 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	error(int ac, char **av, int *numbers)
{
	int	flag_count;

	flag_count = 0;
	if (!check_flag(ac, av, &flag_count))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	*numbers = malloc(((ac - 1) - flag_count) * sizeof(int));
	if (!numbers)
		return (0);
	if (!check_values(values, flag_count, &numbers))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

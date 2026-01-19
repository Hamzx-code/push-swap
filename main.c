/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:51:40 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/19 20:40:36 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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

int	push_swap(int ac, char **av)
{
	int	*numbers;
	char	**values;

	values = parse(ac, av);
	if (!values)
		return (0);
	if (!error(ac, values, &numbers))
	{
		free_buffers(values);
		free(numbers);
		return (0);
	}
	free_buffers(values); // for the test
	free(numbers); // for the test
	return (1);
}
#include <stdio.h>
int	main(int ac, char **av)
{
	printf("return %d\n", push_swap(ac, av));
	return (0);
}

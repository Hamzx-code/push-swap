/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 02:06:22 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/22 00:42:17 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "adaptive.h"

static void	copy_strategy(t_flage *flage, char *strategy)
{
	int	i;

	i = 0;
	while (i < 19 && strategy[i] != '\0')
	{
		flage->strategy[i] = strategy[i];
		i++;
	}
	flage->strategy[i] = '\0';
}

static void	initialize(int *mistakes, int *total_pairs, t_node **i, t_stack *a)
{
	*mistakes = 0;
	*total_pairs = 0;
	*i = a->top;
}

static double	count_disorder(t_stack *a)
{
	t_node	*i;
	t_node	*j;
	int		index[2];
	int		mistakes;
	int		total_pairs;

	initialize(&mistakes, &total_pairs, &i, a);
	index[0] = 0;
	while (index[0] < a->size)
	{
		j = i->next;
		index[1] = index[0] + 1;
		while (index[1] < a->size)
		{
			total_pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
			index[1]++;
		}
		i = i->next;
		index[0]++;
	}
	return ((double)mistakes / (double)total_pairs);
}

int	adaptive(t_stack *a, t_stack *b, t_flage *flage)
{
	double	disorder;

	disorder = count_disorder(a);
	flage->disorder = disorder;
	if (disorder <= 0.2)
	{
		if (algorithme_simple(a, b, flage) == 0)
			return (0);
		copy_strategy(flage, "O(n^2)");
	}
	else if (disorder < 0.5)
	{
		if (algorithme_medium(a, b, flage) == 0)
			return (0);
		copy_strategy(flage, "(O(n √ n))");
	}
	else if (disorder >= 0.5)
	{
		if (algorithme_complexe(a, b, flage) == 0)
			return (0);
		copy_strategy(flage, "(O(n log n))");
	}
	return (1);
}

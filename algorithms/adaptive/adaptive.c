/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 02:06:22 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/21 02:18:18 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "adaptive.h"

double	count_dissorder(t_stack *a)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;

	i = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i < a->size)
	{
		j = i + 1;
		while (j < a->size)
		{
			total_pairs++;
			if (a->top->value > a->top->next->value)
				mistakes++;
		}
	}
	return (mistakes / total_pairs);
}
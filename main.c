/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:52:41 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/23 16:33:22 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void sort_strategy(int flag, t_flage *flage)
{
	if (data->flag == 1)
		flage->strategy = ft_strcpy(flage->strategy, "simple");
	else if (data->flag == 2)
		flage->strategy = ft_strcpy(flage->strategy, "medium");
	else if (data->flag == 3)
		flage->strategy = ft_strcpy(flage->strategy, "complex");
	else if (data->flag == 4)
		flage->strategy = ft_strcpy(flage->strategy, "adaptive");
}

int	push_swap(int ac, char **av)
{
	t_stack	a;
	t_stack b;
	t_data	data;
	t_flage flage;

	init_stack(&a);
	if (!parse(ac, av, &stack, &data))
		return (0);
	init_stack(&b);
	init_flage(&flage);
	sort_strategy(data.flag, &flage);
	if (data->flag == 1)
		algorithme_simple(&a, &b, &flage);
	else if (data->flag == 2)
		algorithme_medium(&a, &b, &flage);
	else if (data->flag == 3)
		algorithme_complexe(&a, &b, &flage);
	else if (data->flag == 4)
		adaptive(&a, &b, &flage);
	if (data->flag == 5)
		display_bench(&flage);
	empty_stack(&a);
	return (1);
}

int main(int ac, char **av)
{
	if (!push_swap(ac, av))
		return (1);
	return (0);
}

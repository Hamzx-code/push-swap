/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:52:41 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/23 17:09:42 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void sort_strategy(t_stack *stack, int flag, t_flage *flage)
{
	double disorder;

	disorder = 0.0;
	if (flag == 1)
		ft_strcpy(flage->strategy, "simple");
	else if (flag == 2)
		ft_strcpy(flage->strategy, "medium");
	else if (flag == 3)
		ft_strcpy(flage->strategy, "complex");
	else if (flag == 4)
		ft_strcpy(flage->strategy, "adaptive");
	disorder = count_disorder(stack);
	flage->disorder = disorder;
}

int	push_swap(int ac, char **av)
{
	t_stack	a;
	t_stack b;
	t_data	data;
	t_flage flage;

	init_stack(&a);
	if (!parse(ac, av, &a, &data))
		return (0);
	init_stack(&b);
	init_flage(&flage);
	sort_strategy(&a, data.flag, &flage);
	if (data.flag == 1)
		algorithme_simple(&a, &b, &flage);
	else if (data.flag == 2)
		algorithme_medium(&a, &b, &flage);
	else if (data.flag == 3)
		algorithme_complexe(&a, &b, &flage);
	else if (data.flag == 4)
		adaptive(&a, &b, &flage);
	if (data.bench_mode == 1)
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

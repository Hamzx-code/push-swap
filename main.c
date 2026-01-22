/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:52:41 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/22 19:47:41 by hhamidi          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parse.h"
#include "stack/stack.h"

int push_swap(int ac, char **av)
{
	t_stack	stack;
	t_data	data;

	init_stack(&stack);
	if (!parse(ac, av, &stack, &data))
		return (0);
}

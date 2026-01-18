/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:51:40 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/18 13:49:44 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	push_swap(int ac, char **av)
{
	int	*numbers;
	char	**values;

	values = parse(ac, av);
	if (!values)
		return (0);
	if (!error(ac, av, &numbers))
		return (0);
	
		
	
}

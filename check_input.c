/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:00:36 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/19 19:40:49 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	check_valid_flag(char *flag)
{
	if (!ft_strcmp("--simple", flag))
		return (1);
	else if (!ft_strcmp("--medium", flag))
		return (2);
	else if (!ft_strcmp("--complex", flag))
		return (3);
	else if (!ft_strcmp("--adaptive", flag))
		return (4);
	else if (!ft_strcmp("--bench", flag))
		return (5);
	return (0);
}

int	check_duplicate_flag(char *first_flag, char *second_flag)
{
	if (!ft_strcmp(first_flag, second_flag))
		return (0);
	return (1);
}

int	check_second_flag(char *first_flag, char *second_flag)
{
	int	first_flag_nb;
	int	second_flag_nb;

	if (!check_duplicate_flag(first_flag, second_flag))
		return (0);
	first_flag_nb = check_valid_flag(first_flag);
	second_flag_nb = check_valid_flag(second_flag);
	if (!second_flag_nb)
		return (0);
	if (first_flag_nb >= 1 && first_flag_nb <= 4 && second_flag_nb == 5)
		return (1);
	if (second_flag_nb >= 1 && second_flag_nb <= 4 && first_flag_nb == 5)
		return (1);
	return (0);
}

int	check_flag(int ac, char **values, int *flag_count)
{
	int	nb_flags;

	nb_flags = 0;
	if (ac >= 2 && values[0][0] == '-' && values[0][1] == '-')
	{
		if (!check_valid_flag(values[0]))
			return (0);
		nb_flags++;
	}	
	if (ac >= 3  && values[1][0] == '-' && values[1][1] == '-')
	{
		if (!check_second_flag(values[0], values[1]))
			return (0);
		nb_flags++;
	}
	*flag_count = nb_flags;
	return (1);
}
//test
//#include <stdio.h>
//int	main(int ac, char **av)
//{
//	int	flag_count = 0;
//	printf("flag = %s: %d\n", av[1], check_flag(ac, av, &flag_count));
//	return (0);
//}

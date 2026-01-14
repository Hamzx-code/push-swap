/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:00:36 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/14 18:32:19 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_check_valid_flag(char *flag)
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

int	ft_check_duplicate_flag(char *first_flag, char *second_flag)
{
	if (!ft_strcmp(first_flag, second_flag))
		return (0);
	return (1);
}

int	ft_check_second_flag(char *first_flag, char *second_flag)
{
	int	first_flag_nb;
	int	second_flag_nb;

	if (!ft_check_duplicate_flag(first_flag, second_flag))
		return (0);
	first_flag_nb = ft_check_valid_flag(first_flag);
	second_flag_nb = ft_check_valid_flag(second_flag);
	if (!second_flag_nb)
		return (0);
	if (first_flag_nb >= 1 && first_flag_nb <= 4 && second_flag_nb == 5)
		return (1);
	if (second_flag_nb >= 1 && second_flag_nb <= 4 && first_flag_nb == 5)
		return (1);
	return (0);
}

int	ft_check_flag(int ac, char **av)
{
	if (ac >= 2 && av[1][0] == '-' && av[1][1] == '-')
	{
		if (!ft_check_valid_flag(av[1]))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
	}
	if (ac >= 3  && av[2][0] == '-' && av[2][1] == '-')
	{
		if (!ft_check_second_flag(av[1], av[2]))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
	}
	return (1);
}
//test
#include <stdio.h>
int	main(int ac, char **av)
{
	printf("flag = %s: %d\n", av[1], ft_check_flag(ac, av));
	return (0);
}

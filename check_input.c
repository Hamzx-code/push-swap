/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:00:36 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/13 21:19:40 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>

size_t  ft_strlen(const char *s)
{
        size_t  len;

        len = 0;
        while (s[len])
                len++;
        return (len);
}

void    ft_putstr_fd(char *s, int fd)
{
        write(fd, s, ft_strlen(s));
}

int     ft_strcmp(const char *s1, const char *s2)
{
        int     i;

        i = 0;
        while (s1[i] && s2[i])
        {
                if (s1[i] != s2[i])
                        return (s1[i] - s2[i]);
                i++;
        }
        return (s1[i] - s2[i]);
}

int	ft_check_flag(char *flag)
{
	if (!ft_strcmp("--simple", flag))
		return (1);
	else if (!ft_strcmp("--medium", flag))
		return (1);
	else if (!ft_strcmp("--complex", flag))
		return (1);
	else if (!ft_strcmp("--adaptive", flag))
		return (1);
	else if (!ft_strcmp("--bench", flag))
		return (1);
	return (0);
}

int	ft_check_input(int ac, char **av)
{
	if (ac > 1 && av[1][0] == '-' && av[1][1] == '-')
	{
		if (!ft_check_flag(av[1]))
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
	}
}
/*#include <stdio.h>
int	main(void)
{
	printf("--simple : %d\n", ft_check_flag("--simple"));
	printf("--medium : %d\n", ft_check_flag("--medium"));
	printf("--complex : %d\n", ft_check_flag("--complex"));
	printf("--adaptive : %d\n", ft_check_flag("--adaptive"));
	printf("--bench : %d\n", ft_check_flag("--bench"));
	printf("0000 : %d\n", ft_check_flag("0000"));
	printf("test : %d\n", ft_check_flag("test"));
	return (0);
}*/

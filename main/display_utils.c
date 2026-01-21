/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 00:53:29 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/22 00:54:26 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr(int nb, int *count)
{
	long int	n;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		(*count)++;
		n *= -1;
	}
	if (n >= 0 && n <= 9)
	{
		ft_putchar(n + '0');
		(*count)++;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, count);
		ft_putnbr(n % 10, count);
	}
}

void	ft_putstr(char *str, int *count)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		(*count)++;
		i++;
	}
}

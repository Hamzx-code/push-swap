/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 00:53:29 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/25 00:41:58 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_putfloat(double nb, int precision, int fd)
{
	long int	entier;
	double		decimale;
	int			i;

	if (nb < 0)
	{
		ft_putchar('-', fd);
		nb = -nb;
	}
	entier = (long int)nb;
	decimale = nb - entier;
	ft_putnbr(entier, fd);
	ft_putchar('.', fd);
	i = 0;
	while (i < precision)
	{
		decimale *= 10;
		ft_putchar((int)decimale + '0', fd);
		decimale -= (int)decimale;
		i++;
	}
}

void	display_sp(t_flage *flage)
{
	ft_putstr("[bench] sa:  ", 2);
	ft_putnbr(flage->sa, 2);
	ft_putstr("  sb:  ", 2);
	ft_putnbr(flage->sb, 2);
	ft_putstr("  ss:  ", 2);
	ft_putnbr(flage->ss, 2);
	ft_putstr("  pa:  ", 2);
	ft_putnbr(flage->pa, 2);
	ft_putstr("  pb:  ", 2);
	ft_putnbr(flage->pb, 2);
}

void	display_r(t_flage *flage)
{
	ft_putstr("[bench] ra:  ", 2);
	ft_putnbr(flage->ra, 2);
	ft_putstr("  rb:  ", 2);
	ft_putnbr(flage->rb, 2);
	ft_putstr("  rr:  ", 2);
	ft_putnbr(flage->rr, 2);
	ft_putstr("  rra:  ", 2);
	ft_putnbr(flage->rra, 2);
	ft_putstr("  rrb:  ", 2);
	ft_putnbr(flage->rrb, 2);
	ft_putstr("  rrr:  ", 2);
	ft_putnbr(flage->rrr, 2);
}

void	display_bench(t_flage *flage)
{
	ft_putstr("[bench] disorder:  ", 2);
	ft_putfloat(flage->disorder, 2, 2);
	write(2, "%\n", 2);
	ft_putstr("[bench] strategy:  ", 2);
	ft_putstr(flage->strategy, 2);
	write(2, "\n", 1);
	ft_putstr("[bench] total_ops:  ", 2);
	ft_putnbr(flage->total_ops, 2);
	write(2, "\n", 1);
	display_sp(flage);
	write(2, "\n", 1);
	display_r(flage);
}

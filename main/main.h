/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:28:47 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/25 00:39:56 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../algorithms/adaptive/adaptive.h"
# include "../algorithms/algorithm_simple/algorithme_simple.h"
# include "../algorithms/algorithme_medium/algorithme_medium.h"
# include "../algorithms/algorithme_complexe/algorithme_complexe.h"
# include "../operations/operations.h"
# include "../stack/stack.h"
# include "../parsing/parse.h"
# include "../libft/libft.h"
# include <stdio.h>

void	display_bench(t_flage *flage);
void	ft_putchar(char c, int fd);
void	ft_putnbr(int nb, int fd);
void	ft_putstr(char *str, int fd);

#endif

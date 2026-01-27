/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:26:08 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/27 16:34:44 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../../libft/libft.h"
# include "../../stack/stack.h"

int		parse_checker(int ac, char **av, int *numbers);
char	**join_and_split_args(int ac, char **av);
int		validate_input(char **values, int *numbers, int numbers_size);
int		parse_values(char **values, int *numbers, int numbers_size);
int		empty_stack(t_stack *stack);

#endif


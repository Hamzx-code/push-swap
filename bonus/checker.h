/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:30:04 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/27 16:36:12 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "parsing/parse.h"
# include "gnl/get_next_line.h"
# include "operations/operations.h"

int checker(int ac, char **av);
int		operations(char **operations, t_stack *a, t_stack *b);
int		swap(char operation, t_stack *a, t_stack *b);
int		push(char operation, t_stack *a, t_stack *b);
int		rotate(char operation, t_stack *a, t_stack *b);
int		reverse_rotate(char operation, t_stack *a, t_stack *b);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:30:04 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/28 16:08:15 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "parsing/parse.h"
# include "operations_bonus/operations.h"

int		checker(int ac, char **av);
int		apply_operations(char **operations, t_stack *a, t_stack *b);
int		checker_swap(char *operation, t_stack *a, t_stack *b);
int		checker_push(char *operation, t_stack *a, t_stack *b);
void	checker_rotate(char *operation, t_stack *a, t_stack *b);
void	checker_reverse_rotate(char *operation, t_stack *a, t_stack *b);
char	*read_buffer(int fd, char *buffer_operations);

#endif

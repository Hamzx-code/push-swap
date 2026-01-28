/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:26:08 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/28 16:07:17 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../../libft/libft.h"
# include "../../stack/stack.h"
# include <limits.h>

typedef struct s_data
{
	int	*numbers;
	int	size;
}	t_data;

int		parse_checker(int ac, char **av, t_stack *stack, t_data *data);
char	**join_and_split_args(int ac, char **av);
int		validate_input(char **values, t_data *data);
int		parse_values(char **values, t_data *data);
int		empty_stack(t_stack *stack);
void	free_buffers(char **tab);
void	init_data(t_data *data);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:26:41 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/24 12:56:38 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../libft/libft.h"
# include "../stack/stack.h"

typedef struct s_data
{
	int	flag;
	int	bench_mode;
	int	*numbers;
	int	size;
}	t_data;

int		parse(int ac, char **av, t_stack *stack, t_data *data);
void	init_data(t_data *data);
char	**join_and_split_args(int ac, char **av);
int		validate_input(char **values, t_data *data);
int		parse_flags(int value_nb, char **values, int *flag_count, t_data *data);
int		parse_values(char **values, int start, t_data *data);
int		empty_stack(t_stack *stack);

#endif

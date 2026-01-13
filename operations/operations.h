/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:43:50 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/13 16:42:42 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

t_node *new_node(int value);
void	push(t_node **stack, int value);
int		pop(t_node **stack);
int		peek(t_node *stack);
int		sa(t_node **stack);
int		sb(t_node **stack);
int		ss(t_node **stack_a, t_node **stack_b);
int		pa(t_node **stack_a, t_node **stack_b);

#endif
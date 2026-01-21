/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:43:50 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/21 19:56:47 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../stack/stack.h"

int		sa(t_stack *stack_a, t_flage *flage);
int		sb(t_stack *stack_b, t_flage *flage);
int		ss(t_stack *stack_a, t_stack *stack_b, t_flage *flage);
int		pa(t_stack *a, t_stack *b, t_flage *flage);
int		pb(t_stack *b, t_stack *a, t_flage *flage);
void	ra(t_stack *a, t_flage *flage);
void	rb(t_stack *b, t_flage *flage);
void	rr(t_stack *a, t_stack *b, t_flage *flage);
void	rra(t_stack *a, t_flage *flage);
void	rrb(t_stack *b, t_flage *flage);
void	rrr(t_stack *a, t_stack *b, t_flage *flage);

#endif
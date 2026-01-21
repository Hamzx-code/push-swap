/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme_simple.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:08:32 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/22 00:05:34 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHME_SIMPLE_H
# define ALGORITHME_SIMPLE_H

# include "../../stack/stack.h"
# include "../../operations/operations.h"

int	cost(int index, int size);
int	valeur_min(t_stack *stack);
int	valeur_max(t_stack	*stack);
int	position(int value, t_stack *stack);
int	algorithme_simple(t_stack *a, t_stack *b, t_flage *flage);

#endif
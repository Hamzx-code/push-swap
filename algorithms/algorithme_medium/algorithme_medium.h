/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme_medium.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 01:24:45 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/20 02:13:33 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHME_MEDIUM_H
# define ALGORITHME_MEDIUM_H

# include "../../stack/stack.h"
# include "../../operations/operations.h"
# include "../algorithm_simple/algorithme_simple.h"
# include <stdlib.h>

int		*index_stack(t_stack *a);
void	sort_small_stack(t_stack *a);
int		ft_sqrt(int nb);
int		algorithme_medium(t_stack *a, t_stack *b);

#endif
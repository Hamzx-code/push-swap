/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 02:07:28 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/22 00:04:01 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADAPTIVE_H
# define ADAPTIVE_H

# include "../../stack/stack.h"
# include "../../operations/operations.h"
# include "../algorithm_simple/algorithme_simple.h"
# include "../algorithme_medium/algorithme_medium.h"
# include "../algorithme_complexe/algorithme_complexe.h"

int	adaptive(t_stack *a, t_stack *b, t_flage *flage);

#endif
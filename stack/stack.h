/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:27:24 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/15 21:53:19 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

/* typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node; */

typedef struct s_node
{
    int value;
    struct s_node *next;
    struct s_node *prev;
} t_node;

typedef struct s_stack
{
    t_node *top;
    int size;
} t_stack;

t_node *new_node(int value);
void	push(t_node **stack, int value);
int		pop(t_node **stack);
int		peek(t_node *stack);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_stack_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:12:58 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/15 21:54:14 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "../stack/stack.h"

void init_stack(t_stack *s)
{
    s->top = NULL;
    s->size = 0;
}

t_node *new_node(int value)
{
    t_node *n;

	n = malloc(sizeof(t_node));
    if (!n)
        return (NULL);
    n->value = value;
    n->next = n;
    n->prev = n;
    return (n);
}
int	push(t_stack *s, int value)
{
	t_node	*n;
	t_node	*last;

	n = new_node(value);
	if (!n)
		return (0);
	if (!s->top)
		s->top = n;
	else
	{
		// recuperer le previous
		last = (s->top)->prev;
		// modifie le next et le prev
		n->next = s->top;
		n->prev = last;
		// modif le premier elemant
		last->next = n;
		// modif le previous de l'ancien top
		(s->top)->prev = n;
		// definir le top
		s->top = n;
	}
	(s->size)++;
}

int	pop(t_stack *s)
{
	t_node *tmp;
	t_node *last;
	int		value;
	
	if (!s->top)
		return (0);
	tmp = s->top;
	value = tmp->value;
	if (s->size == 1)
		s->top = NULL;
	else
	{
		last = tmp->prev;
		s->top = tmp->next;
		last->next = s->top;
		(s->top)->prev = last;
	}
	free(tmp);
	(s->size)--;
	return (value);
}

int	peek(t_stack *stack)
{
	if (!stack->top)
		return (0);
	return ((stack->top)->value);
}

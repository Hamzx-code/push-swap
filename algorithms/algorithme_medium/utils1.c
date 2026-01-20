/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 01:22:56 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/20 02:14:32 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithme_medium.h"

static int *stack_to_array(t_stack *a)
{
    int     *arr;
    t_node  *tmp;
    int     i;

    arr = malloc(sizeof(int) * a->size);
    if (!arr)
        return (NULL);

    tmp = a->top;
    i = 0;
    while (i < a->size)
    {
        arr[i++] = tmp->value;
        tmp = tmp->next;
    }
    return (arr);
}

static void sort_array(int *arr, int size)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < size - 1)
    {
        j = 0;
        while (j < size - i - 1)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }
}

static int get_index(int *arr, int size, int value)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (arr[i] == value)
            return (i);
        i++;
    }
    return (-1); // sécurité
}

int *index_stack(t_stack *a)
{
    int     *arr;
    t_node  *tmp;

    arr = stack_to_array(a);
    if (!arr)
        return (0);
    sort_array(arr, a->size);
    tmp = a->top;
    while (tmp)
    {
        tmp->value = get_index(arr, a->size, tmp->value);
        tmp = tmp->next;
        if (tmp == a->top)
            break;
    }
    return(arr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:28:20 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/21 00:44:47 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "algorithms/algorithme_complexe/algorithme_complexe.h"
// Simple min/max extraction methods

void afficher_stack_debug(t_stack *stack)
{
	int		i;
	t_node	*current;

	if (!stack || !stack->top)
	{
		printf("Stack vide\n");
		return ;
	}
	
	printf("=== Stack (size = %d) ===\n", stack->size);
	i = 1;  // Position commence à 1
	current = stack->top;
	while (i <= stack->size)
	{
		printf("Position %d: value = %d, next = %p, prev = %p\n", 
			i, current->value, (void *)current->next, (void *)current->prev);
		current = current->next;
		i++;
	}
	printf("========================\n");
}

int	main(void)
{
	t_stack a;
	t_stack b;
	
	printf("========================================\n");
	printf("TEST 1 : Stack simple (4 éléments)\n");
	printf("========================================\n");
	init_stack(&a);
	init_stack(&b);
	push(&a, 1);
	push(&a, 5);
	push(&a, 2);
	push(&a, 9);
	printf("\n📊 AVANT ALGO :\n");
	afficher_stack_debug(&a);
	afficher_stack_debug(&b);
	algorithme_simple(&a, &b);
	//algorithme_medium(&a, &b);
	//algorithme_complexe(&a, &b);
	printf("\n✅ APRES ALGO :\n");
	afficher_stack_debug(&a);
	afficher_stack_debug(&b);
	
	printf("\n\n========================================\n");
	printf("TEST 2 : Stack désordonnée (6 éléments)\n");
	printf("========================================\n");
	init_stack(&a);
	init_stack(&b);
	push(&a, 42);
	push(&a, 7);
	push(&a, 99);
	push(&a, 3);
	push(&a, 15);
	push(&a, 8);
	printf("\n📊 AVANT ALGO :\n");
	afficher_stack_debug(&a);
	algorithme_simple(&a, &b);
	//algorithme_medium(&a, &b);
	//algorithme_complexe(&a, &b);
	printf("\n✅ APRES ALGO :\n");
	afficher_stack_debug(&a);
	
	printf("\n\n========================================\n");
	printf("TEST 3 : Stack déjà triée (5 éléments)\n");
	printf("========================================\n");
	init_stack(&a);
	init_stack(&b);
	push(&a, 5);
	push(&a, 4);
	push(&a, 3);
	push(&a, 2);
	push(&a, 1);
	printf("\n📊 AVANT ALGO :\n");
	afficher_stack_debug(&a);
	algorithme_simple(&a, &b);
	//algorithme_medium(&a, &b);
	//algorithme_complexe(&a, &b);
	printf("\n✅ APRES ALGO :\n");
	afficher_stack_debug(&a);
	
	printf("\n\n========================================\n");
	printf("TEST 4 : Stack triée inversée (5 éléments)\n");
	printf("========================================\n");
	init_stack(&a);
	init_stack(&b);
	push(&a, 1);
	push(&a, 2);
	push(&a, 3);
	push(&a, 4);
	push(&a, 5);
	printf("\n📊 AVANT ALGO :\n");
	afficher_stack_debug(&a);
	algorithme_simple(&a, &b);
	//algorithme_medium(&a, &b);
	//algorithme_complexe(&a, &b);
	printf("\n✅ APRES ALGO :\n");
	afficher_stack_debug(&a);
	
	printf("\n\n========================================\n");
	printf("TEST 5 : Petite stack (3 éléments)\n");
	printf("========================================\n");
	init_stack(&a);
	init_stack(&b);
	push(&a, 2);
	push(&a, 1);
	push(&a, 3);
	printf("\n📊 AVANT ALGO :\n");
	afficher_stack_debug(&a);
	algorithme_simple(&a, &b);
	//algorithme_medium(&a, &b);
	//algorithme_complexe(&a, &b);
	printf("\n✅ APRES ALGO :\n");
	afficher_stack_debug(&a);
	
	printf("\n\n========================================\n");
	printf("TEST 6 : Stack avec valeurs négatives\n");
	printf("========================================\n");
	init_stack(&a);
	init_stack(&b);
	push(&a, -5);
	push(&a, 10);
	push(&a, -2);
	push(&a, 0);
	push(&a, 7);
	push(&a, -10);
	printf("\n📊 AVANT ALGO :\n");
	afficher_stack_debug(&a);
	algorithme_simple(&a, &b);
	//algorithme_medium(&a, &b);
	//algorithme_complexe(&a, &b);
	printf("\n✅ APRES ALGO :\n");
	afficher_stack_debug(&a);
	
	printf("\n\n========================================\n");
	printf("TEST 7 : Grande stack (10 éléments)\n");
	printf("========================================\n");

	init_stack(&a);
	init_stack(&b);
	push(&a, 50);
	push(&a, 23);
	push(&a, 89);
	push(&a, 12);
	push(&a, 67);
	push(&a, 34);
	push(&a, 78);
	push(&a, 5);
	push(&a, 91);
	push(&a, 41);
	printf("\n📊 AVANT ALGO :\n");
	afficher_stack_debug(&a);
	algorithme_simple(&a, &b);
	//algorithme_medium(&a, &b);
	//algorithme_complexe(&a, &b);
	printf("\n✅ APRES ALGO :\n");
	afficher_stack_debug(&a);
	
	return (0);
}

// int	main(void)
// {
// 	t_stack a;
// 	int *arr;
// 	init_stack(&a);
// 	push(&a, -5);
// 	push(&a, 10);
// 	push(&a, -2);
// 	push(&a, 0);
// 	push(&a, 7);
// 	push(&a, -10);
// 	printf("\n📊 AVANT INDEXATION :\n");
// 	afficher_stack_debug(&a);
// 	arr = index_stack(&a);
// 	printf("\n✅ APRES INDEXATION :\n");
// 	afficher_stack_debug(&a);
// 	int i = 0;
// 	t_node *tmp;
// 	tmp = a.top;
// 	while (i < a.size)
// 	{
// 		printf("arr[%d] = %d \n",tmp->value,arr[tmp->value] );
// 		tmp = tmp->next;
// 		i++;
// 	}
// }

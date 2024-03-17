/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:57:57 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/03/18 00:07:42 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/ft_push_swap.h"

//PUSH
void	push(t_node **stackA, t_node **stackB)
{
	t_node *aux;

	if (!*stackA)
		return ;
	aux = *stackA;
	*stackA = (*stackA)->next;
	if (*stackA)
		(*stackA)->prev = NULL;
    aux->prev = NULL;
	// if (!stackB)
	// {
	// 	printf("Esto solo debería estar una vez\n");
	// 	stackB = ft_calloc(1, sizeof(t_node *));
	// 	node_add_back(stackB, NULL);
	// }
	if (!*stackB)
	{
		*stackB = aux;
		aux->next = NULL;
	}
	else
	{
		aux->next = *stackB;
		aux->next->prev = aux;
		*stackB = aux;
	}
	*stackB = aux;
}

// static void	push(t_stack_node **dst, t_stack_node **src) //Define a function that pushes a top node, from one stack to another's top node
// {
// 	t_stack_node	*push_node; //Used to store the pointer to the node to be pushed

// 	if (!*src) //The top node of a stack to be pushed
// 		return ;
// 	push_node = *src; //The top node to push is assigned to the `t_stack_node` variable
// 	*src = (*src)->next; //Move the pointer of the stack to the next node, which will become the next `top node` after the node before is "popped off"
// 	if (*src) //Check if the current node exists
// 		(*src)->prev = NULL; //Set the current node as the head of the stack
// 	push_node->prev = NULL; //Detach the node to push from its stack
// 	if (!*dst) //Check if the other stack is empty
// 	{
// 		*dst = push_node; //If it's empty, assign as the first node of that stack, the node we want pushed
// 		push_node->next = NULL; //Ensure it is also set as the last node, e.g. properly null terminate the stack
// 	}
// 	else //If the other stack we want to push to is not empty
// 	{
// 		push_node->next = *dst; //Assign the node to push, to the top of the current top node of the stack
// 		push_node->next->prev = push_node; //Assign to the "second node" `prev` attribute, the pushed node as the current top node
// 		*dst = push_node; //Complete appending the node. The pointer to the top node of the stack is now pointing to our recently pushed node
// 	}
// }

//pa. Cima de StackB a la cima de StackA
void    pa(t_node **b, t_node **a)
{
	push(b, a);
	printf("pa\n");
}

//pb. Cima de StackA a la cima de StackB
void    pb(t_node **a, t_node **b)
{
	push(a, b);
	printf("pb\n");
}
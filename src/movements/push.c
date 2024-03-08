/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:57:57 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/03/08 03:46:02 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/ft_push_swap.h"

//PUSH
void	push(t_node **stackA, t_node **stackB)
{
	t_node *tmp;

	if (!stackA || !*stackA)
		return ;
	
	tmp = *stackA;
	*stackA = (*stackA)->next;
	if (*stackA)
		(*stackA)->prev = NULL;
	
	if (*stackB)
		(*stackB)->prev = tmp;
	tmp->next = *stackB;
	tmp->prev = NULL;
	*stackB = tmp;
}

//pa. Cima de StackB a la cima de StackA
void    pa(t_node **a, t_node **b)
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
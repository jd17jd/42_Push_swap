/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 00:48:00 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/03/17 23:48:11 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/ft_push_swap.h"

int	is_ordered(t_node **stack)
{
    t_node	*aux;

    if (!stack)
        return (1);

    aux = *stack;
    while (aux->next)
    {
        if (aux->content > aux->next->content)
            return (1);
        aux = aux->next;
    }
    return (0);
} //OK

t_node  *find_highest(t_node **stack)
{
    t_node  *res;
    t_node  *actual;

    if (*stack == NULL) {
        return NULL;
    }

    actual = *stack;
    res = actual;
    
    while (actual)
    {
        if (actual->content > res->content)
            res = actual;
        actual = actual->next;
    }
    return(res);
} //OK

void    sort_three_elements(t_node **stack)
{
    t_node  *highest;

    highest = find_highest(stack);
    if (*stack == highest)
        ra(stack);
    else if ((*stack)->next == highest)
        rra(stack);
    if ((*stack)->content > (*stack)->next->content)
        sa(stack);
} //OK


void    sort_five_elements(t_node **stackA, t_node **stackB)
{
    int		i;
    int		size;
    t_node 	*highest;

    i = 0;
    size = node_size(*stackA);
    while (i < size - 3)
    {
        highest = find_highest(stackA);
        if (*stackA == highest)
            ra(stackA);
        else if ((*stackA)->next == highest)
            rra(stackA);
        if ((*stackA)->content > (*stackA)->next->content)
            sa(stackA);
        pb(stackA, stackB);
        printf("prueba\n");
        i++;
    }
    sort_three_elements(stackA);
    pa(stackA, stackB);
    pa(stackA, stackB);
}

void    sort_big_stack(t_node **stackA, t_node **stackB)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;
	int		num;

	i = 0;
	j = 0;
	size = node_size(stackA[0]);
	i = size - 1;
	max_bits = 0;
	while ((i >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		while (j < size)
		{
			num = (*stackA)->position;
			if (((num >> i)&1) == 1)
				ra(stackA);
			else pb(stackA, stackB);
			j++;
		}
		while (stackB[0])
			pa(stackA, stackB);
		i++;
	}
}

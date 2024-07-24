/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:22:13 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/03/18 16:57:03 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

void	node_add_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (!*lst)
		*lst = new;
	else
	{
		last = node_last(*lst);
		last->next = new;
		new->prev = last;
	}
}

void	node_add_front(t_node **lst, t_node *new)
{
	new->next = *lst;
	if (*lst)
		(*lst)->prev = new;
	*lst = new;
	(*lst)->prev = NULL;
}

void	node_clear(t_node **lst)
{
	t_node	*aux;

	while (*lst)
	{
		aux = (*lst)->next;
		free(*lst);
		*lst = aux;
	}
	*lst = NULL;
}

void	node_delete(t_node **lst, t_node *node)
{
	if (!node->prev)
		node->prev->next = node->next;
	else
		*lst = node->next;
	if (node->next)
		node->next->prev = node->prev;
	free(node);
}

void	node_iter(t_node *lst, void (*f)(int))
{
	while (lst && f)
	{
		f(lst->content);
		lst = lst->next;
	}
}

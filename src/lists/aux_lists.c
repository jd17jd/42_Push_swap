/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:22:13 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/02/27 22:40:59 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/ft_push_swap.h"

//ft_lstadd_back
void	node_add_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last = node_last(*lst);
		last->next = new;
		new->prev = last;
	}
}

//ft_lstadd_front
void	node_add_front(t_node **lst, t_node *new)
{
	new->next = *lst;
	if (*lst)
		(*lst)->prev = new;
	*lst = new;
}

//ft_lstclear
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

//ft_lstdelone
void	node_delone(t_node *lst)
{
	if (lst)
		free(lst);
}

//ft_lstiter
void	node_iter(t_node *lst, void (*f)(int))
{
	while (lst && f)
	{
		f(lst->content);
		lst = lst->next;
	}
}

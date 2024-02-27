/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_listS2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:25:09 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/02/27 22:44:25 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/ft_push_swap.h"

//ft_lstlast
t_node	*node_last(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

//ft_lstmap
t_node	*node_map(t_node *lst, int (*f)(int))
{
	t_node	*res;
	t_node	*elto;

	res = NULL;
	while (lst)
	{
		elto = malloc(sizeof(t_node));
		if (!elto)
		{
			node_clear(&res);
			return (NULL);
		}
		elto->content = f(lst->content);
		elto->position = lst->position;
		elto->prev = node_last(res);
		elto->next = NULL;
		node_add_back(&res, elto);
		lst = lst->next;
	}
	return (res);
}

//ft_lstnew
t_node	*node_new(int content, int position)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->position = position;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

//ft_lstsize
int	node_size(t_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

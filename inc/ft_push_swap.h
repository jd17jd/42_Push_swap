/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:59:15 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/03/08 03:45:18 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include <sys/fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include "../lib/inc/libft.h"

/* linked list */
typedef struct s_node // 's_' for struct
{
	int				content;
	int				position;
	
	struct s_node	*prev;
	struct s_node	*next;
	
}	t_node; // 't_' for type


/* ALGORITHM */
int		is_ordered(t_node **stack);
void    sort_3_elements(t_node **stack);


/* AUX */
t_node	**init(int argc, char *argv[]);
void	ver_lista(t_node **start);


/* PARSE */
int 	aux_atoi(const char *str);
void	parse(int argc, char *argv[]);


/* LISTS */
void	node_add_back(t_node **lst, t_node *new);
void	node_add_front(t_node **lst, t_node *new);
void	node_clear(t_node **lst);
void    node_delete(t_node **lst, t_node *node);
void	node_iter(t_node *lst, void (*f)(int));
t_node	*node_last(t_node *lst);
t_node	*node_map(t_node *lst, t_node *(*f)(t_node *), void (*del)(t_node *));
t_node	*node_new(int position, int content);
int		node_size(t_node *lst);


/* MOVEMENTS OK */
void	swap(t_node **stack);
void    sa(t_node **a);
void    sb(t_node **b);
void    ss(t_node **a, t_node **b);

void    rotate(t_node **stack);
void    ra(t_node **a);
void    rb(t_node **b);
void    rr(t_node **a, t_node **b);

void    rev_rotate(t_node **stack);
void    rra(t_node **a);
void    rrb(t_node **b);
void    rrr(t_node **a, t_node **b);

void	push(t_node **stackA, t_node **stackB);
void    pa(t_node **a, t_node **b);
void    pb(t_node **a, t_node **b);

/* PRUEBAS */
void 	pruebas_movements(t_node **stackA, t_node **stackB);
void	pruebas_algorithm(t_node **stackA, t_node **stackB);


#endif
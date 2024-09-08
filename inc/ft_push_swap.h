/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:59:15 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/08 22:32:54 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include <sys/fcntl.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include "../lib/inc/libft.h"

/* linked list */
typedef struct s_node
{
	int				content;
	int				position;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

/* lists */
void	node_add_back(t_node **lst, t_node *new);
void	node_add_front(t_node **lst, t_node *new);
void	node_clear(t_node **lst);
void	node_delete(t_node **lst, t_node *node);
void	node_iter(t_node *lst, void (*f)(int));
t_node	*node_last(t_node *lst);
t_node	*node_map(t_node *lst, t_node *(*f)(t_node *), void (*del)(t_node *));
t_node	*node_new(int position, int content);
int		node_size(t_node *lst);

/* movements */
void	swap(t_node **stack);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	rotate(t_node **stack);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rev_rotate(t_node **stack);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
void	push(t_node **stackA, t_node **stackB);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);

/* parse */
void	init(int *aux, int size, t_node **stackA, t_node **stackB);
int		*aux_strcpy_int(const int *original_array, int size);
int		aux_atoi(const char *str);
int		number_arguments(int argc, char *argv[]);
int		*parse(int argc, char *argv[]);

/* algorithm */
void	sort_three_elements(t_node **stack);
void	move_to_top(t_node **stack_a, t_node *lowest, int size);
void	push_lowest_to_b(t_node **stack_a, t_node **stack_b, int size);
void	sort_five_elements(t_node **stackA, t_node **stackB);
int		calculate_max_bits(int size);
void	sort_by_bit(t_node **stack_a, t_node **stack_b, int bit, int size);
void	move_elements_back_to_a(t_node **stack_a, t_node **stack_b);
void	sort_big_stack(t_node **stackA, t_node **stackB);
t_node	*find_lowest(t_node **stack);
t_node	*find_highest(t_node **stack);
int		get_distance(t_node **stack, t_node *highest);
int		is_ordered(t_node **stack);
void	order_stack(t_node **stackA, t_node **stackB);

/* frees */
void	free_array(char **array);
void	free_stack(t_node **stack);

#endif
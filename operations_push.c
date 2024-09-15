/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosleima <mosleima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:43:48 by mosleima          #+#    #+#             */
/*   Updated: 2024/09/13 18:21:24 by mosleima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **a, t_node **b)
{
	t_node	*temp;

	if (*b == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	temp->next = NULL;
	temp->prev = NULL;
	add_node_at_head(a, temp);
	write(1, "pa\n", 3);
	update_indices(*a);
	update_indices(*b);
}

void	pb(t_node **a, t_node **b)
{
	t_node	*temp;

	if (*a == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	temp->next = NULL;
	temp->prev = NULL;
	add_node_at_head(b, temp);
	write(1, "pb\n", 3);
	update_indices(*a);
	update_indices(*b);
}

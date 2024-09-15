/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosleima <mosleima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:52:31 by mosleima          #+#    #+#             */
/*   Updated: 2024/09/13 18:22:17 by mosleima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	rotate(t_node **s)
{
	t_node	*first;
	t_node	*tail;

	if (*s == NULL || (*s)->next == NULL)
		return ;
	first = *s;
	tail = get_tail(*s);
	*s = first->next;
	(*s)->prev = NULL;
	tail->next = first;
	first->prev = tail;
	first->next = NULL;
}

void	ra(t_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
	update_indices(*a);
}

void	rb(t_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
	update_indices(*b);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	update_indices(*a);
	update_indices(*b);
}

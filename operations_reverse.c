/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosleima <mosleima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:28:27 by mosleima          #+#    #+#             */
/*   Updated: 2024/09/13 18:21:43 by mosleima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	reverse_rotate(t_node **s)
{
	t_node	*first;
	t_node	*tail;

	if (*s == NULL || (*s)->next == NULL)
		return ;
	first = *s;
	tail = get_tail(*s);
	if (tail->prev)
		tail->prev->next = NULL;
	tail->prev = NULL;
	tail->next = first;
	first->prev = tail;
	*s = tail;
}

void	rra(t_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
	update_indices(*a);
}

void	rrb(t_node **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
	update_indices(*b);
}

void	rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
	update_indices(*a);
	update_indices(*b);
}

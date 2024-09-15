/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosleima <mosleima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:44:38 by mosleima          #+#    #+#             */
/*   Updated: 2024/09/13 18:23:33 by mosleima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	swap(t_node **s)
{
	t_node		*first;
	t_node		*second;

	if (*s == NULL || (*s)->next == NULL)
		return ;
	first = *s;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*s = second;
}

void	sa(t_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
	update_indices(*a);
}

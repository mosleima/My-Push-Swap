/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosleima <mosleima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:26:30 by mosleima          #+#    #+#             */
/*   Updated: 2024/09/13 18:12:37 by mosleima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*min_node(t_node *head)
{
	t_node	*min;

	min = head;
	while (head)
	{
		if (min->data > head->data)
			min = head;
		head = head->next;
	}
	return (min);
}

t_node	*max_node(t_node *head)
{
	t_node	*max;

	max = head;
	while (head)
	{
		if (max->data < head->data)
			max = head;
		head = head->next;
	}
	return (max);
}

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	count_nodes(t_node *list)
{
	int	count;

	count = 0;
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}

void	sort_three(t_node **a)
{
	t_node	*highest_node;

	highest_node = max_node(*a);
	if ((*a)->next == highest_node)
		rra(a);
	else if (*a == highest_node)
		ra(a);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

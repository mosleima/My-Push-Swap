/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosleima <mosleima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:24:20 by mosleima          #+#    #+#             */
/*   Updated: 2024/09/25 11:45:24 by mosleima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_cheapest(t_node *a)
{
	t_node	*cheapest;

	if (!a)
		return (NULL);
	cheapest = a;
	while (a)
	{
		if (a->push_cost < cheapest->push_cost)
			cheapest = a;
		a = a->next;
	}
	return (cheapest);
}

static int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	calculate_individual_cost(int index, int len)
{
	if (index >= len / 2)
		return (len - index);
	return (index);
}

void	calculate_push_cost(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;
	int	cost_a;
	int	cost_b;

	len_a = count_nodes(a);
	len_b = count_nodes(b);
	while (a)
	{
		if (!a->target_node)
		{
			a = a->next;
			continue ;
		}
		cost_a = calculate_individual_cost(a->index, len_a);
		cost_b = calculate_individual_cost(a->target_node->index, len_b);
		if (a->index >= len_a / 2 && a->target_node->index >= len_b / 2)
			a->push_cost = max(cost_a, cost_b);
		else if (a->index < len_a / 2 && a->target_node->index < len_b / 2)
			a->push_cost = max(cost_a, cost_b);
		else
			a->push_cost = cost_a + cost_b;
		a = a->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosleima <mosleima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:43:41 by mosleima          #+#    #+#             */
/*   Updated: 2024/09/13 18:00:30 by mosleima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

void	move_to_top(t_node **stack, t_node *node, char stack_name)
{
	int		total_nodes;

	total_nodes = count_nodes(*stack);
	if (!stack || !*stack || !node)
		return ;
	if (node->index > total_nodes / 2)
	{
		while (*stack != node)
		{
			if (stack_name == 'a')
				rra(stack);
			else if (stack_name == 'b')
				rrb(stack);
		}
	}
	else
	{
		while (*stack != node)
		{
			if (stack_name == 'a')
				ra(stack);
			else if (stack_name == 'b')
				rb(stack);
		}
	}
}

static	void	apply_rotations(t_node **a, t_node **b,
				int *cost_a, int *cost_b)
{
	int	count;

	count = ft_min(*cost_a, *cost_b);
	while (count-- > 0)
		rr(a, b);
	if (*cost_a > *cost_b)
		while ((*cost_a)-- > *cost_b)
			ra(a);
	else
		while ((*cost_b)-- > *cost_a)
			rb(b);
}

static	void	apply_rev_rotations(t_node **a, t_node **b,
					int *cost_a, int *cost_b)
{
	int	count;

	count = ft_min(*cost_a, *cost_b);
	while (count-- > 0)
		rrr(a, b);
	if (*cost_a > *cost_b)
		while ((*cost_a)-- > *cost_b)
			rra(a);
	else
		while ((*cost_b)-- > *cost_a)
			rrb(b);
}

void	move_a_b_to_top(t_node **a, t_node **b)
{
	t_node	*cheapest;
	int		len_a;
	int		len_b;
	int		cost_a;
	int		cost_b;

	cheapest = find_cheapest(*a);
	len_a = count_nodes(*a);
	len_b = count_nodes(*b);
	cost_a = calculate_individual_cost(cheapest->index, len_a);
	cost_b = calculate_individual_cost(cheapest->target_node->index, len_b);
	if (cheapest->index < len_a / 2 && cheapest->target_node->index < len_b / 2)
		apply_rotations(a, b, &cost_a, &cost_b);
	else if (cheapest->index >= len_a / 2
		&& cheapest->target_node->index >= len_b / 2)
		apply_rev_rotations(a, b, &cost_a, &cost_b);
	else
	{
		move_to_top(a, cheapest, 'a');
		move_to_top(b, cheapest->target_node, 'b');
	}
}

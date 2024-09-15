/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosleima <mosleima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:59:11 by mosleima          #+#    #+#             */
/*   Updated: 2024/09/15 10:57:55 by mosleima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	perform_push(t_node **a, t_node **b)
{
	move_a_b_to_top(a, b);
	pb(a, b);
	update_indices(*a);
	update_indices(*b);
}

static void	push_all_except_three(t_node **a, t_node **b)
{
	while (count_nodes(*a) > 3 && count_nodes(*b) < 2)
		pb(a, b);
	while (count_nodes(*a) > 3)
	{
		set_target_a(*a, *b);
		calculate_push_cost(*a, *b, 1);
		perform_push(a, b);
	}
}

static void	final_rotation(t_node **a)
{
	t_node	*min;

	min = min_node(*a);
	move_to_top(a, min, 'a');
}

static void	pushbtoa(t_node **a, t_node **b)
{
	int	len_a;

	while (*b)
	{
		set_target_b(*a, *b);
		len_a = count_nodes(*a);
		if ((*b)->target_node->index < len_a / 2)
		{
			while ((*b)->target_node->index != 0)
				ra(a);
		}
		else if ((*b)->target_node->index >= len_a / 2)
		{
			while ((*b)->target_node->index != 0)
				rra(a);
		}
		pa(a, b);
	}
}

void	push_swap(t_node **a, t_node **b)
{
	push_all_except_three(a, b);
	sort_three(a);
	pushbtoa(a, b);
	final_rotation(a);
}
